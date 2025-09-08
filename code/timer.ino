/****************************************
               Timer mode
****************************************/
void timerCheck() {
  if (modeSelect == 3) {
    if ((timer1On && timer1WaterStatus) || (timer2On && timer2WaterStatus) || (timer3On && timer3WaterStatus) || (timer4On && timer4WaterStatus) || (timer5On && timer5WaterStatus) || (timer6On && timer6WaterStatus) || (timer7On && timer7WaterStatus) || (timer8On && timer8WaterStatus)) {
      waterValveStatus = 1;
      lineSender = "Timer No.";
      lineSender += timerNumber;

#ifdef LINENOTIFY
      lineNotifyOpenWaterValve();
#endif

    }

    if ((timer1On && timer1SprayStatus) || (timer2On && timer2SprayStatus) || (timer3On && timer3SprayStatus) || (timer4On && timer4SprayStatus) || (timer5On && timer5SprayStatus) || (timer6On && timer6SprayStatus) || (timer7On && timer7SprayStatus) || (timer8On && timer8SprayStatus)) {
      sprayValveStatus = 1;
      lineSender = "Timer No.";
      lineSender += timerNumber;

#ifdef LINENOTIFY
      lineNotifyOpenSprayValve();
#endif

    }

    if ((timer1WaterStatus == 0) && (timer2WaterStatus == 0) && (timer3WaterStatus == 0) && (timer4WaterStatus == 0) && (timer5WaterStatus == 0) && (timer6WaterStatus == 0) && (timer7WaterStatus == 0) && (timer8WaterStatus == 0)) {
      waterValveStatus = 0;
      lineSender = "Timer No.";
      lineSender += "x";

#ifdef LINENOTIFY
      lineNotifyCloseWaterValve();
#endif

    }

    if ((timer1SprayStatus == 0) && (timer2SprayStatus == 0) && (timer3SprayStatus == 0) && (timer4SprayStatus == 0) && (timer5SprayStatus == 0) && (timer6SprayStatus == 0) && (timer7SprayStatus == 0) && (timer8SprayStatus == 0))  {
      sprayValveStatus = 0;
      lineSender = "Timer No.";
      lineSender += "x";

#ifdef LINENOTIFY
      lineNotifyCloseSprayValve();
#endif

    }
  }
}


void timer1OpenAll() {
  timer1WaterStatus = 1;
  timer1SprayStatus = 1;
}

void timer1CloseAll() {
  timer1WaterStatus = 0;
  timer1SprayStatus = 0;
}

void timer2OpenAll() {
  timer2WaterStatus = 1;
  timer2SprayStatus = 1;
}

void timer2CloseAll() {
  timer2WaterStatus = 0;
  timer2SprayStatus = 0;
}

void timer3OpenAll() {
  timer3WaterStatus = 1;
  timer3SprayStatus = 1;
}

void timer3CloseAll() {
  timer3WaterStatus = 0;
  timer3SprayStatus = 0;
}

void timer4OpenAll() {
  timer4WaterStatus = 1;
  timer4SprayStatus = 1;
}

void timer4CloseAll() {
  timer4WaterStatus = 0;
  timer4SprayStatus = 0;
}

void timer5OpenAll() {
  timer5WaterStatus = 1;
  timer5SprayStatus = 1;
}

void timer5CloseAll() {
  timer5WaterStatus = 0;
  timer5SprayStatus = 0;
}

void timer6OpenAll() {
  timer6WaterStatus = 1;
  timer6SprayStatus = 1;
}

void timer6CloseAll() {
  timer6WaterStatus = 0;
  timer6SprayStatus = 0;
}

void timer7OpenAll() {
  timer7WaterStatus = 1;
  timer7SprayStatus = 1;
}

void timer7CloseAll() {
  timer7WaterStatus = 0;
  timer7SprayStatus = 0;
}

void timer8OpenAll() {
  timer8WaterStatus = 1;
  timer8SprayStatus = 1;
}

void timer8CloseAll() {
  timer8WaterStatus = 0;
  timer8SprayStatus = 0;
}

BLYNK_WRITE(Widget_TimerButton_1) {  //timer 1 button  0=off 1= w+s 2=w 3=s
  if (param.asInt() == 1) {
    timer1Work++;
    if (timer1Work >= 4) {
      timer1Work = 0;
      timer1CloseAll();
    }
    activeToday();
    timer1Label();
  }
}

BLYNK_WRITE(Widget_TimerButton_2) {  //timer 2 button  0=off 1= w+s 2=w 3=s
  if (param.asInt() == 1) {
    timer2Work++;
    if (timer2Work >= 4) {
      timer2Work = 0;
      timer2CloseAll();
    }
    activeToday();
    timer2Label();
  }
}

BLYNK_WRITE(Widget_TimerButton_3) {  //timer 3 button  0=off 1= w+s 2=w 3=s
  if (param.asInt() == 1) {
    timer3Work++;
    if (timer3Work >= 4) {
      timer3Work = 0;
      timer3CloseAll();
    }
    activeToday();
    timer3Label();
  }
}

BLYNK_WRITE(Widget_TimerButton_4) {  //timer 4 button  0=off 1= w+s 2=w 3=s
  if (param.asInt() == 1) {
    timer4Work++;
    if (timer4Work >= 4) {
      timer4Work = 0;
      timer4CloseAll();
    }
    activeToday();
    timer4Label();
  }
}

BLYNK_WRITE(Widget_TimerButton_5) {  //timer 5 button  0=off 1= w+s 2=w 3=s
  if (param.asInt() == 1) {
    timer5Work++;
    if (timer5Work >= 4) {
      timer5Work = 0;
      timer5CloseAll();
    }
    activeToday();
    timer5Label();
  }
}

BLYNK_WRITE(Widget_TimerButton_6) {  //timer 6 button  0=off 1= w+s 2=w 3=s
  if (param.asInt() == 1) {
    timer6Work++;
    if (timer6Work >= 4) {
      timer6Work = 0;
      timer6CloseAll();
    }
    activeToday();
    timer6Label();
  }
}

BLYNK_WRITE(Widget_TimerButton_7) {  //timer 7 button  0=off 1= w+s 2=w 3=s
  if (param.asInt() == 1) {
    timer7Work++;
    if (timer7Work >= 4) {
      timer7Work = 0;
      timer7CloseAll();
    }
    activeToday();
    timer7Label();
  }
}

BLYNK_WRITE(Widget_TimerButton_8) {  //timer 8 button  0=off 1= w+s 2=w 3=s
  if (param.asInt() == 1) {
    timer8Work++;
    if (timer8Work >= 4) {
      timer8Work = 0;
      timer8CloseAll();
    }
    activeToday();
    timer8Label();
  }
}

//******************************************************************************************//
//*************************************TIMER MODULE*****************************************//

BLYNK_WRITE(Widget_TimerInput_1) {  //  timer 1

  if (modeSelect == 3) {

    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());

    TimeInputParam t(param);

    Serial.print("Timer 1 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 1 Checked schedule at: "); terminal.println(Time); terminal.flush();

    int dayadjustment = -1;  //  -1
    if (weekday() == 1) dayadjustment =  6;

    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      //Serial.println("Timer 1  ACTIVE today");
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
        //Serial.print("Timer 1  STARTED at");
        //Serial.println(String(" ") + t.getStartHour() + ":" + t.getStartMinute());
        if (nowseconds <= startsecondswd + 90) {  // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, HIGH); // set LED ON
          //Serial.println("Timer 1 on 1");
          timer1On = 1;
          timerNumber = 1;

          //timer1 on
          if (timer1Work == 1) {
            timer1OpenAll();
          } else if (timer1Work == 2) {
            timer1WaterStatus = 1;
            timer1SprayStatus = 0;
          } else if (timer1Work == 3) {
            timer1SprayStatus = 1;
            timer1WaterStatus = 0;
          }

          // code here to switch the relay ON
        }
      }
      else {
        //Serial.println("Timer 1  NOT STARTED today");
      }

      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      //Serial.println(stopsecondswd);

      if (nowseconds >= stopsecondswd) {
        //digitalWrite(waterLed, LOW); // set LED OFF
        //Serial.println("Timer 1 off 1");
        timer1CloseAll();
        timer1On = 0;

        //Serial.print("Timer 1 STOPPED at");
        //Serial.println(String(" ") + t.getStopHour() + ":" + t.getStopMinute());
        if (nowseconds <= stopsecondswd + 90) { // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, LOW); // set LED OFF
          //Serial.println("Timer 1 off 2");
          timer1CloseAll();
          timer1On = 0;

          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          //digitalWrite(waterLed, HIGH); // set LED ON    test
          //Serial.println("Timer 1 on 2");
          timer1On = 1;
          timerNumber = 1;

          //timer1 on
          if (timer1Work == 1) {
            timer1OpenAll();
          } else if (timer1Work == 2) {
            timer1WaterStatus = 1;
            timer1SprayStatus = 0;
          } else if (timer1Work == 3) {
            timer1SprayStatus = 1;
            timer1WaterStatus = 0;
          }

          //Serial.println("Timer 1 is ON");
        }
      }
    }
    else {
      //Serial.println("Timer 1 INACTIVE today");
      // nothing to do today, check again in 30 SECONDS time
    }
    //Serial.println();
  }
}

BLYNK_WRITE(Widget_TimerInput_2) {  //  timer 2

  if (modeSelect == 3) {

    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());

    TimeInputParam t(param);

    Serial.print("Timer 2 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 2 Checked schedule at: "); terminal.println(Time); terminal.flush();

    int dayadjustment = -1;  //  -1
    if (weekday() == 1) dayadjustment =  6;

    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      //Serial.println("Timer 2  ACTIVE today");
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
        //Serial.print("Timer 2  STARTED at");
        //Serial.println(String(" ") + t.getStartHour() + ":" + t.getStartMinute());
        if (nowseconds <= startsecondswd + 90) {  // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, HIGH); // set LED ON
          //Serial.println("Timer 2 on 1");
          timer2On = 1;
          timerNumber = 2;

          //timer2 on
          if (timer2Work == 1) {
            timer2OpenAll();
          } else if (timer2Work == 2) {
            timer2WaterStatus = 1;
            timer2SprayStatus = 0;
          } else if (timer2Work == 3) {
            timer2SprayStatus = 1;
            timer2WaterStatus = 0;
          }

          // code here to switch the relay ON
        }
      }
      else {
        //Serial.println("Timer 2  NOT STARTED today");
      }

      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      //Serial.println(stopsecondswd);

      if (nowseconds >= stopsecondswd) {
        //digitalWrite(waterLed, LOW); // set LED OFF
        //Serial.println("Timer 2 off 1");
        timer2CloseAll();

        //Serial.print("Timer 2 STOPPED at");
        //Serial.println(String(" ") + t.getStopHour() + ":" + t.getStopMinute());
        if (nowseconds <= stopsecondswd + 90) { // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, LOW); // set LED OFF
          //Serial.println("Timer 2 off 2");
          timer2CloseAll();

          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          //digitalWrite(waterLed, HIGH); // set LED ON
          //Serial.println("Timer 2 on 2");
          timer2On = 1;
          timerNumber = 2;

          //timer2 on
          if (timer2Work == 1) {
            timer2OpenAll();
          } else if (timer2Work == 2) {
            timer2WaterStatus = 1;
            timer2SprayStatus = 0;
          } else if (timer2Work == 3) {
            timer2SprayStatus = 1;
            timer2WaterStatus = 0;
          }

          // code here to switch the relay ON

        }
      }
    }
    else {
      //Serial.println("Timer 2 INACTIVE today");
      // nothing to do today, check again in 30 SECONDS time
    }
    //Serial.println();
  }
}

BLYNK_WRITE(Widget_TimerInput_3) {  //  timer 3

  if (modeSelect == 3) {

    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());

    TimeInputParam t(param);

    Serial.print("Timer 3 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 3 Checked schedule at: "); terminal.println(Time); terminal.flush();

    int dayadjustment = -1;  //  -1
    if (weekday() == 1) dayadjustment =  6;

    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      //Serial.println("Timer 3  ACTIVE today");
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
        //Serial.print("Timer 3  STARTED at");
        //Serial.println(String(" ") + t.getStartHour() + ":" + t.getStartMinute());
        if (nowseconds <= startsecondswd + 90) {  // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, HIGH); // set LED ON
          //Serial.println("Timer 3 on 1");
          timer3On = 1;
          timerNumber = 3;

          //timer3 on
          if (timer3Work == 1) {
            timer3OpenAll();
          } else if (timer3Work == 2) {
            timer3WaterStatus = 1;
            timer3SprayStatus = 0;
          } else if (timer3Work == 3) {
            timer3SprayStatus = 1;
            timer3WaterStatus = 0;
          }

          // code here to switch the relay ON
        }
      }
      else {
        //Serial.println("Timer 3  NOT STARTED today");
      }

      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      //Serial.println(stopsecondswd);

      if (nowseconds >= stopsecondswd) {
        //digitalWrite(waterLed, LOW); // set LED OFF
        //Serial.println("Timer 3 off 1");
        timer3CloseAll();
        timer3On = 0;

        //Serial.print("Timer 3 STOPPED at");
        //Serial.println(String(" ") + t.getStopHour() + ":" + t.getStopMinute());
        if (nowseconds <= stopsecondswd + 90) { // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, LOW); // set LED OFF
          //Serial.println("Timer 3 off 2");
          timer3CloseAll();
          timer3On = 0;

          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          //digitalWrite(waterLed, HIGH); // set LED ON
          //Serial.println("Timer 3 on 2");
          timer3On = 1;
          timerNumber = 3;

          //timer3 on
          if (timer3Work == 1) {
            timer3OpenAll();
          } else if (timer3Work == 2) {
            timer3WaterStatus = 1;
            timer3SprayStatus = 0;
          } else if (timer3Work == 3) {
            timer3SprayStatus = 1;
            timer3WaterStatus = 0;
          }

          // code here to switch the relay ON

        }
      }
    }
    else {
      //Serial.println("Timer 3 INACTIVE today");
      // nothing to do today, check again in 30 SECONDS time
    }
    //Serial.println();
  }
}

BLYNK_WRITE(Widget_TimerInput_4) {  //  timer 4

  if (modeSelect == 3) {

    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());

    TimeInputParam t(param);

    Serial.print("Timer 4 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 4 Checked schedule at: "); terminal.println(Time); terminal.flush();

    int dayadjustment = -1;  //  -1
    if (weekday() == 1) dayadjustment =  6;

    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      //Serial.println("Timer 4  ACTIVE today");
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
        //Serial.print("Timer 4  STARTED at");
        //Serial.println(String(" ") + t.getStartHour() + ":" + t.getStartMinute());
        if (nowseconds <= startsecondswd + 90) {  // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, HIGH); // set LED ON
          //Serial.println("Timer 4 on 1");
          timer4On = 1;
          timerNumber = 4;

          //timer4 on
          if (timer4Work == 1) {
            timer4OpenAll();
          } else if (timer4Work == 2) {
            timer4WaterStatus = 1;
            timer4SprayStatus = 0;
          } else if (timer4Work == 3) {
            timer4SprayStatus = 1;
            timer4WaterStatus = 0;
          }

          // code here to switch the relay ON
        }
      }
      else {
        //Serial.println("Timer 4  NOT STARTED today");
      }

      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      //Serial.println(stopsecondswd);

      if (nowseconds >= stopsecondswd) {
        //digitalWrite(waterLed, LOW); // set LED OFF
        //Serial.println("Timer 4 off 1");
        timer4CloseAll();
        timer4On = 0;

        //Serial.print("Timer 4 STOPPED at");
        //Serial.println(String(" ") + t.getStopHour() + ":" + t.getStopMinute());
        if (nowseconds <= stopsecondswd + 90) { // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, LOW); // set LED OFF
          //Serial.println("Timer 4 off 2");
          timer4CloseAll();
          timer4On = 0;

          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          //digitalWrite(waterLed, HIGH); // set LED ON    test
          //Serial.println("Timer 4 on 2");
          timer4On = 1;
          timerNumber = 4;

          //timer4 on
          if (timer4Work == 1) {
            timer4OpenAll();
          } else if (timer4Work == 2) {
            timer4WaterStatus = 1;
            timer4SprayStatus = 0;
          } else if (timer4Work == 3) {
            timer4SprayStatus = 1;
            timer4WaterStatus = 0;
          }

          //Serial.println("Timer 4 is ON");
        }
      }
    }
    else {
      //Serial.println("Timer 4 INACTIVE today");
      // nothing to do today, check again in 30 SECONDS time
    }
    //Serial.println();
  }
}

BLYNK_WRITE(Widget_TimerInput_5) {  //  timer 5

  if (modeSelect == 3) {

    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());

    TimeInputParam t(param);

    Serial.print("Timer 5 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 5 Checked schedule at: "); terminal.println(Time); terminal.flush();

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
          //Serial.println("Timer 5 on 1");
          timer5On = 1;
          timerNumber = 5;

          //timer5 on
          if (timer5Work == 1) {
            timer5OpenAll();
          } else if (timer5Work == 2) {
            timer5WaterStatus = 1;
            timer5SprayStatus = 0;
          } else if (timer5Work == 3) {
            timer5SprayStatus = 1;
            timer5WaterStatus = 0;
          }

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
        //Serial.println("Timer 5 off 1");
        timer5CloseAll();
        timer5On = 0;

        //Serial.print("Timer 5 STOPPED at");
        //Serial.println(String(" ") + t.getStopHour() + ":" + t.getStopMinute());
        if (nowseconds <= stopsecondswd + 90) { // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, LOW); // set LED OFF
          //Serial.println("Timer 5 off 2");
          timer5CloseAll();
          timer5On = 0;

          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          //digitalWrite(waterLed, HIGH); // set LED ON    test
          //Serial.println("Timer 5 on 2");
          timer5On = 1;
          timerNumber = 5;

          //timer5 on
          if (timer5Work == 1) {
            timer5OpenAll();
          } else if (timer5Work == 2) {
            timer5WaterStatus = 1;
            timer5SprayStatus = 0;
          } else if (timer5Work == 3) {
            timer5SprayStatus = 1;
            timer5WaterStatus = 0;
          }

          //Serial.println("Timer 5 is ON");
        }
      }
    }
    else {
      //Serial.println("Timer 5 INACTIVE today");
      // nothing to do today, check again in 30 SECONDS time
    }
    //Serial.println();
    //Serial.println();
  }
}

BLYNK_WRITE(Widget_TimerInput_6) {  //  timer 6

  if (modeSelect == 3) {

    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());

    TimeInputParam t(param);

    Serial.print("Timer 6 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 6 Checked schedule at: "); terminal.println(Time); terminal.flush();

    int dayadjustment = -1;  //  -1
    if (weekday() == 1) dayadjustment =  6;

    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      //Serial.println("Timer 6  ACTIVE today");
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
        //Serial.print("Timer 6  STARTED at");
        //Serial.println(String(" ") + t.getStartHour() + ":" + t.getStartMinute());
        if (nowseconds <= startsecondswd + 90) {  // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, HIGH); // set LED ON
          //Serial.println("Timer 6 on 1");
          timer6On = 1;
          timerNumber = 6;

          //timer6 on
          if (timer6Work == 1) {
            timer6OpenAll();
          } else if (timer6Work == 2) {
            timer6WaterStatus = 1;
            timer6SprayStatus = 0;
          } else if (timer6Work == 3) {
            timer6SprayStatus = 1;
            timer6WaterStatus = 0;
          }

          // code here to switch the relay ON
        }
      }
      else {
        //Serial.println("Timer 6  NOT STARTED today");
      }

      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      //Serial.println(stopsecondswd);

      if (nowseconds >= stopsecondswd) {
        //digitalWrite(waterLed, LOW); // set LED OFF
        //Serial.println("Timer 6 off 1");
        timer6CloseAll();
        timer6On = 0;

        //Serial.print("Timer 6 STOPPED at");
        //Serial.println(String(" ") + t.getStopHour() + ":" + t.getStopMinute());
        if (nowseconds <= stopsecondswd + 90) { // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, LOW); // set LED OFF
          //Serial.println("Timer 6 off 2");
          timer6CloseAll();
          timer6On = 0;

          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          //digitalWrite(waterLed, HIGH); // set LED ON    test
          //Serial.println("Timer 6 on 2");
          timer6On = 1;
          timerNumber = 6;

          //timer6 on
          if (timer6Work == 1) {
            timer6OpenAll();
          } else if (timer6Work == 2) {
            timer6WaterStatus = 1;
            timer6SprayStatus = 0;
          } else if (timer6Work == 3) {
            timer6SprayStatus = 1;
            timer6WaterStatus = 0;
          }

          //Serial.println("Timer 6 is ON");
        }
      }
    }
    else {
      //Serial.println("Timer 6 INACTIVE today");
      // nothing to do today, check again in 30 SECONDS time
    }
    //Serial.println();
    //Serial.println();
  }
}

BLYNK_WRITE(Widget_TimerInput_7) {  //  timer 7

  if (modeSelect == 3) {

    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());

    TimeInputParam t(param);

    Serial.print("Timer 7 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 7 Checked schedule at: "); terminal.println(Time); terminal.flush();

    int dayadjustment = -1;  //  -1
    if (weekday() == 1) dayadjustment =  6;

    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      //Serial.println("Timer 7  ACTIVE today");
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
        //Serial.print("Timer 7  STARTED at");
        //Serial.println(String(" ") + t.getStartHour() + ":" + t.getStartMinute());
        if (nowseconds <= startsecondswd + 90) {  // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, HIGH); // set LED ON
          //Serial.println("Timer 7 on 1");
          timer7On = 1;
          timerNumber = 7;

          //timer7 on
          if (timer7Work == 1) {
            timer7OpenAll();
          } else if (timer7Work == 2) {
            timer7WaterStatus = 1;
            timer7SprayStatus = 0;
          } else if (timer7Work == 3) {
            timer7SprayStatus = 1;
            timer7WaterStatus = 0;
          }

          // code here to switch the relay ON
        }
      }
      else {
        //Serial.println("Timer 7  NOT STARTED today");
      }

      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      //Serial.println(stopsecondswd);

      if (nowseconds >= stopsecondswd) {
        //digitalWrite(waterLed, LOW); // set LED OFF
        //Serial.println("Timer 7 off 1");
        timer7CloseAll();
        timer7On = 0;

        //Serial.print("Timer 7 STOPPED at");
        //Serial.println(String(" ") + t.getStopHour() + ":" + t.getStopMinute());
        if (nowseconds <= stopsecondswd + 90) { // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, LOW); // set LED OFF
          //Serial.println("Timer 7 off 2");
          timer7CloseAll();
          timer7On = 0;

          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          //digitalWrite(waterLed, HIGH); // set LED ON    test
          //Serial.println("Timer 7 on 2");
          timer7On = 1;
          timerNumber = 7;

          //timer7 on
          if (timer7Work == 1) {
            timer7OpenAll();
          } else if (timer7Work == 2) {
            timer7WaterStatus = 1;
            timer7SprayStatus = 0;
          } else if (timer7Work == 3) {
            timer7SprayStatus = 1;
            timer7WaterStatus = 0;
          }

          //Serial.println("Timer 7 is ON");
        }
      }
    }
    else {
      //Serial.println("Timer 7 INACTIVE today");
      // nothing to do today, check again in 30 SECONDS time
    }
    //Serial.println();
  }
}

BLYNK_WRITE(Widget_TimerInput_8) {  //  timer 8

  if (modeSelect == 3) {

    sprintf(Date, "%02d/%02d/%04d",  day(), month(), year());
    sprintf(Time, "%02d:%02d:%02d", hour(), minute(), second());

    TimeInputParam t(param);

    Serial.print("Timer 8 Checked schedule at: "); Serial.println(Time);
    terminal.print("Timer 8 Checked schedule at: "); terminal.println(Time); terminal.flush();

    int dayadjustment = -1;  //  -1
    if (weekday() == 1) dayadjustment =  6;

    if (t.isWeekdaySelected(weekday() + dayadjustment)) {
      //Serial.println("Timer 8  ACTIVE today");
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
        //Serial.print("Timer 8  STARTED at");
        //Serial.println(String(" ") + t.getStartHour() + ":" + t.getStartMinute());
        if (nowseconds <= startsecondswd + 90) {  // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, HIGH); // set LED ON
          //Serial.println("Timer 8 on 1");
          timer8On = 1;
          timerNumber = 8;

          //timer8 on
          if (timer8Work == 1) {
            timer8OpenAll();
          } else if (timer8Work == 2) {
            timer8WaterStatus = 1;
            timer8SprayStatus = 0;
          } else if (timer8Work == 3) {
            timer8SprayStatus = 1;
            timer8WaterStatus = 0;
          }

          // code here to switch the relay ON
        }
      }
      else {
        //Serial.println("Timer 8  NOT STARTED today");
      }

      stopsecondswd = (t.getStopHour() * 3600) + (t.getStopMinute() * 60);
      //Serial.println(stopsecondswd);

      if (nowseconds >= stopsecondswd) {
        //digitalWrite(waterLed, LOW); // set LED OFF
        //Serial.println("Timer 8 off 1");
        timer8CloseAll();
        timer8On = 0;
        timerNumber = 8;

        //Serial.print("Timer 8 STOPPED at");
        //Serial.println(String(" ") + t.getStopHour() + ":" + t.getStopMinute());
        if (nowseconds <= stopsecondswd + 90) { // 90s on 60s timer ensures 1 trigger command is sent
          //digitalWrite(waterLed, LOW); // set LED OFF
          //Serial.println("Timer 8 off 2");
          timer8CloseAll();
          timer8On = 0;
          timerNumber = 8;

          // code here to switch the relay OFF
        }
      }
      else {
        if (nowseconds >= startsecondswd) {
          //digitalWrite(waterLed, HIGH); // set LED ON    test
          //Serial.println("Timer 8 on 2");
          timer8On = 1;
          timerNumber = 8;

          //timer8 on
          if (timer8Work == 1) {
            timer8OpenAll();
          } else if (timer8Work == 2) {
            timer8WaterStatus = 1;
            timer8SprayStatus = 0;
          } else if (timer8Work == 3) {
            timer8SprayStatus = 1;
            timer8WaterStatus = 0;
          }

          //Serial.println("Timer 8 is ON");
        }
      }
    }
    else {
      //Serial.println("Timer 8 INACTIVE today");
      // nothing to do today, check again in 30 SECONDS time
    }
    //Serial.println();
  }
}
