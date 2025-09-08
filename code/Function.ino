//***********************************************//
//                 FUNCTION                      //
//***********************************************//
void getSensorDataTask(void *p) {
  while (1) {
    getDTHValue();
    SoilPercentValue();
    LdrPercentValue();
    sensorStatus = 1;
    oledUpdate();

    //ตั้งระยะห่างของเวลาที่ต้องการเช็คความชื้นในดิน
    //vTaskDelay(10000 / portTICK_PERIOD_MS);
    vTaskDelay(sensorRoundSet * ONE_MINUTE / portTICK_PERIOD_MS);
  }
}

// *** FUNCTION Get DHT Sensor value ***
void getDTHValue() {
  vTaskDelay(50 / portTICK_PERIOD_MS);

  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  int counterDht = 1;
  while (isnan(humidity) || isnan(temperature) || humidity == 0 || temperature == 0 && counterDht <= 4) {
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    humidity = dht.readHumidity();
    // Read temperature as Celsius (the default)
    temperature = dht.readTemperature();
    counterDht++;
    return;
  }

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }


  //แสดงข้อความใน Serial Monitor
  getTime();
  Serial.print(F(", "));
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  Serial.print(F("% Temperature: "));
  Serial.print(temperature);
  Serial.println(F(" *C "));


  temperatureData = temperature;
  humidityData = humidity;
}

// *** FUNCTION SoilPercentValue ***
int SoilPercentValue() {
  vTaskDelay(10 / portTICK_PERIOD_MS);

  for (int i = 0; i <= 4; i++) {
    //อ่านค่าจากเซ็นเซอร์อนาล๊อก Soil Sensor
    CurrentSoilValue = analogRead(SoilSensorPin);
  }

  MapReadSoilValue = map(CurrentSoilValue, 0, 4095, 100, 0);    //แม๊พค่าให้อยู่ในรูปของเปอร์เซ็นต์
  //แสดงข้อความใน Serial Monitor
  getTime();
  Serial.print(", Soil sensor value: ");
  Serial.println(MapReadSoilValue);
  // return MapReadSoilValue;
  soilMoistureData = CurrentSoilValue;
  soilMoistureLevelData = MapReadSoilValue;
}

// *** FUNCTION LdrPercentValue ***
int LdrPercentValue() {
  vTaskDelay(10 / portTICK_PERIOD_MS);

  for (int i = 0; i <= 4; i++) {
    //อ่านค่าจากเซ็นเซอร์อนาล๊อก LDR
    CurrentLightValue = analogRead(LdrSensorPin);
  }

  //แม๊พค่าให้อยู่ในรูปของเปอร์เซ็นต์
  MapReadLightValue = map(CurrentLightValue, 0, 4095, 100, 0);
  //แสดงข้อความใน Serial Monitor
  getTime();
  Serial.print(", Light sensor value: ");
  Serial.println(MapReadLightValue);
  // return MapReadLightValue;
  lightData = CurrentLightValue;
  lightDataLevel = MapReadLightValue;
}

void getTime() {
  displayYear =   String(year(), DEC);
  displayYear =   displayYear.substring(0, 4);

  int gmMonth = month();
  displayMonth =   String(gmMonth, DEC);
  int monthdigits = displayMonth.length();
  if (monthdigits == 1) displayMonth = "0" + displayMonth;

  int gmDayOfMonth = day();
  displayDayOfMonth =   String(gmDayOfMonth, DEC);
  int daydigits = displayDayOfMonth.length();
  if (daydigits == 1) displayDayOfMonth = "0" + displayDayOfMonth;

  int gmthour = hour();
  if (gmthour == 24) gmthour = 0;
  displayHour =   String(gmthour, DEC);
  int hourdigits = displayHour.length();
  if (hourdigits == 1) displayHour = "0" + displayHour;

  displayMinute = String(minute(), DEC);
  int minutedigits = displayMinute.length();
  if (minutedigits == 1) displayMinute = "0" + displayMinute;

  Serial.print("Date:");
  Serial.print(displayYear);
  Serial.print("/");
  Serial.print(displayMonth);
  Serial.print("/");
  Serial.print(displayDayOfMonth);
  Serial.print(" Time:");
  Serial.print(displayHour);
  Serial.print(":");
  Serial.print(displayMinute);

}

void writeEeprom() {
  int modeSelectTmp = EEPROM.read(MODE_SELECT_ADDRESS);
  int sensorRoundSetTmp = EEPROM.read(SENSOR_ROUND_DURATION_SET_ADDRESS);
  int temperatureSetTmp = EEPROM.read(TEMPERATURE_SET_ADDRESS);
  int moistureSetTmp = EEPROM.read(MOISTURE_SET_ADDRESS);
  int lightSetTmp = EEPROM.read(LIGHT_SET_ADDRESS);
  int timer1WorkTmp = EEPROM.read(TIMER1_ADDRESS);
  int timer2WorkTmp = EEPROM.read(TIMER2_ADDRESS);
  int timer3WorkTmp = EEPROM.read(TIMER3_ADDRESS);
  int timer4WorkTmp = EEPROM.read(TIMER4_ADDRESS);
  int timer5WorkTmp = EEPROM.read(TIMER5_ADDRESS);
  int timer6WorkTmp = EEPROM.read(TIMER6_ADDRESS);
  int timer7WorkTmp = EEPROM.read(TIMER7_ADDRESS);
  int timer8WorkTmp = EEPROM.read(TIMER8_ADDRESS);
  int autoWaterSprayDurationSetTmp = EEPROM.read(AUTO_WATER_SPRAY_DURATION_SET_ADDRESS);
  bool waterAutoTimerWorkTmp = EEPROM.read(WATER_AUTO_TIMER_ADDRESS);
  bool sprayAutoTimerWorkTmp = EEPROM.read(SPRAY_AUTO_TIMER_ADDRESS);

  if (modeSelect != modeSelectTmp) {
    EEPROM.write(MODE_SELECT_ADDRESS, modeSelect);
    Serial.print("write eeprom mode select : "); Serial.println(modeSelect);
  }

  if (sensorRoundSet != sensorRoundSetTmp) {
    EEPROM.write(SENSOR_ROUND_DURATION_SET_ADDRESS, sensorRoundSet);
    Serial.print("eeprom write sensor round set : "); Serial.println(sensorRoundSet);
  }

  if (temperatureSet != temperatureSetTmp) {
    EEPROM.write(TEMPERATURE_SET_ADDRESS, temperatureSet);
    Serial.print("eeprom write temerature set : "); Serial.println(temperatureSet);
  }

  if (moistureSet != moistureSetTmp) {
    EEPROM.write(MOISTURE_SET_ADDRESS, moistureSet);
    Serial.print("eeprom write moisture set : "); Serial.println(moistureSet);
  }

  lightSetWrite = lightSet / 1000;
  if (lightSetWrite != lightSetTmp) {
    if (lightSetWrite <= 0) lightSetWrite = 0;
    if (lightSetWrite >= 99) lightSetWrite = 99;
    EEPROM.write(LIGHT_SET_ADDRESS, lightSetWrite);
    Serial.print("eeprom write light set : "); Serial.println(lightSetWrite);
  }

  if (autoWaterSprayDurationSet != autoWaterSprayDurationSetTmp) {
    EEPROM.write(AUTO_WATER_SPRAY_DURATION_SET_ADDRESS, autoWaterSprayDurationSet);
    Serial.print("eeprom write water time set : "); Serial.println(autoWaterSprayDurationSet);
  }

  if (waterAutoTimerWork != waterAutoTimerWorkTmp) {
    EEPROM.write(WATER_AUTO_TIMER_ADDRESS, waterAutoTimerWork);
    Serial.print("eeprom write auto water timerwork : "); Serial.println(waterAutoTimerWork);
  }

  if (sprayAutoTimerWork != sprayAutoTimerWorkTmp) {
    EEPROM.write(SPRAY_AUTO_TIMER_ADDRESS, sprayAutoTimerWork);
    Serial.print("eeprom write auto spray timer work : "); Serial.println(sprayAutoTimerWork);
  }

  if (timer1Work != timer1WorkTmp) {
    EEPROM.write(TIMER1_ADDRESS, timer1Work);
    Serial.print("eeprom write Timer 1 Work : "); Serial.println(timer1Work);
  }

  if (timer2Work != timer2WorkTmp) {
    EEPROM.write(TIMER2_ADDRESS, timer2Work);
    Serial.print("eeprom write Timer 2 Work : "); Serial.println(timer2Work);
  }

  if (timer3Work != timer3WorkTmp) {
    EEPROM.write(TIMER3_ADDRESS, timer3Work);
    Serial.print("eeprom write Timer 3 Work : "); Serial.println(timer3Work);
  }

  if (timer4Work != timer4WorkTmp) {
    EEPROM.write(TIMER4_ADDRESS, timer4Work);
    Serial.print("eeprom write Timer 4 Work : "); Serial.println(timer4Work);
  }

  if (timer5Work != timer5WorkTmp) {
    EEPROM.write(TIMER5_ADDRESS, timer5Work);
    Serial.print("eeprom write Timer 5 Work : "); Serial.println(timer5Work);
  }

  if (timer6Work != timer6WorkTmp) {
    EEPROM.write(TIMER6_ADDRESS, timer6Work);
    Serial.print("eeprom write Timer 6 Work : "); Serial.println(timer6Work);
  }

  if (timer7Work != timer7WorkTmp) {
    EEPROM.write(TIMER7_ADDRESS, timer7Work);
    Serial.print("eeprom write Timer 7 Work : "); Serial.println(timer7Work);
  }

  if (timer8Work != timer8WorkTmp) {
    EEPROM.write(TIMER8_ADDRESS, timer8Work);
    Serial.print("eeprom write Timer 8 Work : "); Serial.println(timer8Work);
  }

  EEPROM.commit();
}


void readConfig() {

  firstState = EEPROM.read(FIRST_ADDRESS);

  if (firstState == 5) {
    modeSelect = EEPROM.read(MODE_SELECT_ADDRESS);
    sensorRoundSet = EEPROM.read(SENSOR_ROUND_DURATION_SET_ADDRESS);
    temperatureSet = EEPROM.read(TEMPERATURE_SET_ADDRESS);
    moistureSet = EEPROM.read(MOISTURE_SET_ADDRESS);
    lightSetWrite = EEPROM.read(LIGHT_SET_ADDRESS) ;
    autoWaterSprayDurationSet = EEPROM.read(AUTO_WATER_SPRAY_DURATION_SET_ADDRESS);
    waterAutoTimerWork = EEPROM.read(WATER_AUTO_TIMER_ADDRESS);
    sprayAutoTimerWork = EEPROM.read(SPRAY_AUTO_TIMER_ADDRESS);
    timer1Work = EEPROM.read(TIMER1_ADDRESS);
    timer2Work = EEPROM.read(TIMER2_ADDRESS);
    timer3Work = EEPROM.read(TIMER3_ADDRESS);
    timer4Work = EEPROM.read(TIMER4_ADDRESS);
    timer5Work = EEPROM.read(TIMER5_ADDRESS);
    timer6Work = EEPROM.read(TIMER6_ADDRESS);
    timer7Work = EEPROM.read(TIMER7_ADDRESS);
    timer8Work = EEPROM.read(TIMER8_ADDRESS);
    Serial.println("restore config");
  } else {
    EEPROM.write(FIRST_ADDRESS, 5);
    EEPROM.write(MODE_SELECT_ADDRESS, 1);
    EEPROM.write(SENSOR_ROUND_DURATION_SET_ADDRESS, 5);
    EEPROM.write(TEMPERATURE_SET_ADDRESS, 32);
    EEPROM.write(MOISTURE_SET_ADDRESS, 50);
    EEPROM.write(LIGHT_SET_ADDRESS, 20);
    EEPROM.write(AUTO_WATER_SPRAY_DURATION_SET_ADDRESS, 1);
    EEPROM.write(WATER_AUTO_TIMER_ADDRESS, 1);
    EEPROM.write(AUTO_WATER_SPRAY_DURATION_SET_ADDRESS, 1);
    EEPROM.write(TIMER1_ADDRESS, 0);
    EEPROM.write(TIMER2_ADDRESS, 0);
    EEPROM.write(TIMER3_ADDRESS, 0);
    EEPROM.write(TIMER4_ADDRESS, 0);
    EEPROM.write(TIMER5_ADDRESS, 0);
    EEPROM.write(TIMER6_ADDRESS, 0);
    EEPROM.write(TIMER7_ADDRESS, 0);
    EEPROM.write(TIMER8_ADDRESS, 0);
    EEPROM.commit();
    Serial.println("write config first");
  }
}

void forceStopAllTimer() {
  timer1CloseAll();
  timer2CloseAll();
  timer3CloseAll();
  timer4CloseAll();
  timer5CloseAll();
  timer6CloseAll();
  timer7CloseAll();
  timer8CloseAll();

  Blynk.syncVirtual(Widget_TimerInput_1, 0);
  Blynk.syncVirtual(Widget_TimerInput_2, 0);
  Blynk.syncVirtual(Widget_TimerInput_3, 0);
  Blynk.syncVirtual(Widget_TimerInput_4, 0);
  Blynk.syncVirtual(Widget_TimerInput_5, 0);
  Blynk.syncVirtual(Widget_TimerInput_6, 0);
  Blynk.syncVirtual(Widget_TimerInput_7, 0);
  Blynk.syncVirtual(Widget_TimerInput_8, 0);
}

void forceStopAllValve() {
  waterValveStatus = 0;
  sprayValveStatus = 0;
  valve3ValveStatus = 0;
  valve4ValveStatus = 0;
}

void updateUbidots(void *p) {
  while (1) {
    float value = humidity;
    float value2 = soilMoistureLevelData;
    float value3 = lightDataLevel;
    float value4 = temperature;
    ubidots.add(VARIABLE_LABEL, value);
    ubidots.add(VARIABLE_LABEL2, value2); // Insert your variable Labels and the value to be sent
    ubidots.add(VARIABLE_LABEL3, value3);
    ubidots.add(VARIABLE_LABEL4, value4);
    ubidots.publish(DEVICE_LABEL);
    Serial.println("Ubidots Updated");
    vTaskDelay(sensorRoundSet * ONE_MINUTE / portTICK_PERIOD_MS);
  }
}

#ifdef NODEREDDASH
void TaskSendDatatoNodeRed(void *p) {
  while (1) {
    long rssi = WiFi.RSSI();

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(WiFi.RSSI());

    counter = counter + 1;
    if (counter == 10000) {
      counter = 0;
      ESP.restart();
    }

    Temperature = String(temperature);
    Humidity = String(humidity);
    soilMoisture = String(soilMoistureLevelData);
    LightSensor = String(lightDataLevel);
    PumpStatus = "Error";
    String MQPumpStatus, MQSprayState;

    String dataSend = "{\"Id\":\"TEST ZONE\",\"Iteration\":" + String(counter) +
                      ",\"RSSI\":" + String(rssi) +
                      ",\"T\":" + String(Temperature) +
                      ",\"H\":" + String(Humidity) +
                      ",\"M\":" + String(soilMoisture) +
                      ",\"L\":" + String(LightSensor) +
                      ",\"P\":" + '"' + String(PumpStatus) + '"' + "}";

    vTaskDelay(ONE_MINUTE / portTICK_PERIOD_MS);

    client.publish(ZoneName, String(dataSend).c_str());
    Serial.print(dataSend);
  }
}

boolean mqttConnect() {
  Serial.print("Connecting to ");
  Serial.print(mqtt_server);

  // Connect to MQTT Broker without username and password
  boolean status = client.connect("ESPClientN");

  // Or, if you want to authenticate MQTT:
  // boolean status = client.connect("GsmClientN", mqttUsername, mqttPassword);

  if (status == false) {
    Serial.println(" fail");
    ESP.restart();
    return false;
  }
  Serial.println(" success");
  return client.connected();
}
#endif

void TaskBlink(void *p) {
  while (1) {
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay(500);
    digitalWrite(LED_BUILTIN, LOW);
    vTaskDelay(500);
  }
}

// *** FUNCTION WifiPercentSignal ***
int WifiPercentSignal() {
  //หาค่าสัญญาณ RSSI ของ WIFI แล้ว MAP ให้อยู่ในรูปของเปอร์เซ็นต์
  CurrentWiFiSignal = WiFi.RSSI();
  WifiSignal = map(CurrentWiFiSignal, -90, -30, 0, 100);
  return WifiSignal;
}

void oledUpdate() {
  // clear the display
  display.clear();

  // create more fonts at http://oleddisplay.squix.ch/
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_10);
  display.drawString(64, 0, "SWCM IoT Smart Box");
  display.drawString(64, 12, "Temperature = " + String(temperature) + " *C");
  display.drawString(64, 24, "Humidity = " + String(humidity) + " %");
  display.drawString(64, 36, "SoilMoisture = " + String(soilMoistureLevelData) + " %");
  display.drawString(64, 48, "LightSensor = " + String(lightDataLevel) + " %");

  // write the buffer to the display
  display.display();
}
