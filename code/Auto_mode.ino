/****************************************
               Auto Mode
****************************************/
void autoCheck() {
  if (sensorStatus == 1) {
    if ((currentMillis - autoMillis) <= (autoWaterSprayDurationSet * ONE_MINUTE)) {
      //auto water check
      if ((waterAutoTimerStatus  == 1) && (soilMoistureData <= moistureSet)) {
        lineSender = "Auto Sensor";
        lineDataSet = " Moisture Set : ";
        lineDataSet += moistureSet;
        lineDataSet += " %H";

#ifdef LINENOTIFY
        lineNotifyOpenWaterValve();
#endif
        waterValveStatus = 1;
      }
      
      //auto spray check
      if ((sprayAutoTimerStatus  == 1) && (temperatureData >= temperatureSet) || (lightDataLevel >= lightSet)) {
        lineSender = "Auto Sensor";
        lineDataSet += " Temperature Set : ";
        lineDataSet += temperatureSet;
        lineDataSet += " C * Light Set : ";
        lineDataSet += lightSet;
        lineDataSet += " %";

#ifdef LINENOTIFY
        lineNotifyOpenSprayValve();
#endif

        sprayValveStatus = 1;
      }

    } else {
      lineSender = "Auto Sensor";
      closeAllValve();
    }

  } else {
    closeAllValve();
  }
}

/****************************************
           Auto timer input
****************************************/
BLYNK_WRITE(Widget_WaterAutoTimerInput) {  //  auto water timer V21

  if ((modeSelect == 2) && (waterAutoTimerWork == 1)) {

    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());

    TimeInputParam t(param);

    Serial.print("Auto Water Timer Checked schedule at: "); Serial.println(Time);
    terminal.print("Auto Water Timer Checked schedule at: "); terminal.println(Time); terminal.flush();

    int dayadjustment = -1;  //  -1
    if (weekday() == 1) dayadjustment =  6;

    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      //Serial.println("Timer 5  ACTIVE today");
      if (t.hasStartTime()) //Serial.println(String("Start: ") + t.getStartHour() + ":" + t.getStartMinute());
        if (t.hasStopTime()) //Serial.println(String("Stop : ") + t.getStopHour() + ":" + t.getStopMinute());
          //Serial.println(String("Time zone: ") + t.getTZ());

          for (int i = 1; i <= 7; i++) {  // Process weekdays (1. Mon, 2. Tue, 3. Wed, ...)
            if (t.isWeekdaySelected(i)) {
              //Serial.println(String("Day ") + i + " is selected");
            }
          }

      nowseconds = ((hour() * 3600) + (minute() * 60) + second());
      startsecondswd = (t.getStartHour() * 3600) + (t.getStartMinute() * 60);
      //Serial.println(startsecondswd);
      if (nowseconds >= startsecondswd) {
        //Serial.print("Timer 5  STARTED at");
        //Serial.println(String(" ") + t.getStartHour() + ":" + t.getStartMinute());
        if (nowseconds <= startsecondswd + 90) {  // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, HIGH); // set LED ON
          waterAutoTimerStatus = 1;
          // code here to switch the relay ON
        }
      }
      else {
        //Serial.println("Timer 5  NOT STARTED today");
      }

      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      //Serial.println(stopsecondswd);

      if (nowseconds >= stopsecondswd) {
        //digitalWrite(waterLed, LOW); // set LED OFF
        waterAutoTimerStatus = 0;
        //Serial.print("Timer 5 STOPPED at");
        //Serial.println(String(" ") + t.getStopHour() + ":" + t.getStopMinute());
        if (nowseconds <= stopsecondswd + 90) { // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, LOW); // set LED OFF
          waterAutoTimerStatus = 0;
          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          //digitalWrite(waterLed, HIGH); // set LED ON    test
          waterAutoTimerStatus = 1;
          //Serial.println("Timer 5 is ON");
        }
      }
    }
    else {
      //Serial.println("Timer 5 INACTIVE today");
      // nothing to do today, check again in 30 SECONDS time
    }
    //Serial.println();
  }
}

BLYNK_WRITE(Widget_SprayAutoTimerInput) {  //  auto water timer V23

  if ((modeSelect == 2) && (sprayAutoTimerWork == 1)) {

    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());

    TimeInputParam t(param);

    Serial.print("Auto Spray Timer Checked schedule at: "); Serial.println(Time);
    terminal.print("Auto Spray Timer Checked schedule at: "); terminal.println(Time); terminal.flush();

    int dayadjustment = -1;  //  -1
    if (weekday() == 1) dayadjustment =  6;

    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      //Serial.println("Timer 5  ACTIVE today");
      if (t.hasStartTime()) //Serial.println(String("Start: ") + t.getStartHour() + ":" + t.getStartMinute());
        if (t.hasStopTime()) //Serial.println(String("Stop : ") + t.getStopHour() + ":" + t.getStopMinute());
          //Serial.println(String("Time zone: ") + t.getTZ());

          for (int i = 1; i <= 7; i++) {  // Process weekdays (1. Mon, 2. Tue, 3. Wed, ...)
            if (t.isWeekdaySelected(i)) {
              //Serial.println(String("Day ") + i + " is selected");
            }
          }

      nowseconds = ((hour() * 3600) + (minute() * 60) + second());
      startsecondswd = (t.getStartHour() * 3600) + (t.getStartMinute() * 60);
      //Serial.println(startsecondswd);
      if (nowseconds >= startsecondswd) {
        //Serial.print("Timer 5  STARTED at");
        //Serial.println(String(" ") + t.getStartHour() + ":" + t.getStartMinute());
        if (nowseconds <= startsecondswd + 90) {  // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, HIGH); // set LED ON
          sprayAutoTimerStatus = 1;
          // code here to switch the relay ON
        }
      }
      else {
        //Serial.println("Timer 5  NOT STARTED today");
      }

      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      //Serial.println(stopsecondswd);

      if (nowseconds >= stopsecondswd) {
        //digitalWrite(waterLed, LOW); // set LED OFF
        sprayAutoTimerStatus = 0;
        //Serial.print("Timer 5 STOPPED at");
        //Serial.println(String(" ") + t.getStopHour() + ":" + t.getStopMinute());
        if (nowseconds <= stopsecondswd + 90) { // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, LOW); // set LED OFF
          sprayAutoTimerStatus = 0;
          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          //digitalWrite(waterLed, HIGH); // set LED ON    test
          sprayAutoTimerStatus = 1;
          //Serial.println("Timer 5 is ON");
        }
      }
    }
    else {
      //Serial.println("Timer 5 INACTIVE today");
      // nothing to do today, check again in 30 SECONDS time
    }
    //Serial.println();
  }
}
