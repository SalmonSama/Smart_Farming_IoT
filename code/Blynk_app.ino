/****************************************
             Blynk app
****************************************/
BLYNK_WRITE(Widget_TemperatureSetSlide) {  //temperature set
  temperatureSet = param[0].asInt();

}

BLYNK_WRITE(Widget_MoistureSetSlide) {  //moisture set
  moistureSet = param[0].asInt();

}

BLYNK_WRITE(Widget_LightSetSlide) {  //light set
  lightSet = map(param.asInt(), 0, 4095, 0, 100);
  Blynk.virtualWrite(Widget_LightLabel, lightSet);
  //Blynk.setProperty(Widget_LightSetSlide, "label", lightSet);

}

BLYNK_WRITE(Widget_WaterSprayDurationSetSlide) {  //water time duration set
  autoWaterSprayDurationSet = param[0].asInt();

}

BLYNK_WRITE(Widget_ModeButton) {  //mode button
  forceStopAllTimer();
  closeAllValve();
  resetTerminal();
  if (param.asInt() == 1) {
    modeSelect++;
    if (modeSelect >= 4) modeSelect = 1;
    modeLabel();
  }
}

BLYNK_WRITE(Widget_WaterButton) {  //water manual button
  forceStopAllTimer();
  resetTerminal();
  if (param.asInt() == 1) {
    modeSelect = 1;
    lineSender = "Manual Blynk";

#ifdef LINENOTIFY
    lineNotifyOpenWaterValve();
#endif

    waterValveStatus = 1;
    modeLabel();
  } else {
    modeSelect = 1;
    waterValveStatus = 0;
    lineSender = "Manual Blynk";

#ifdef LINENOTIFY
    lineNotifyCloseWaterValve();
#endif

    modeLabel();
  }
}

BLYNK_WRITE(Widget_SprayButton) {  //spray manual button
  forceStopAllTimer();
  resetTerminal();
  if (param.asInt() == 1) {
    modeSelect = 1;
    lineSender = "Manual Blynk";

#ifdef LINENOTIFY
    lineNotifyOpenSprayValve();
#endif

    sprayValveStatus = 1;
    modeLabel();
  } else {
    modeSelect = 1;
    sprayValveStatus = 0;
    lineSender = "Manual Blynk";

#ifdef LINENOTIFY
    lineNotifyCloseSprayValve();
#endif

    modeLabel();
  }
}

BLYNK_WRITE(Widget_valve3) {
  forceStopAllTimer();
  resetTerminal();
  if (param.asInt() == 1) {
    modeSelect = 1;
    lineSender = "Manual Blynk";

#ifdef LINENOTIFY
    lineNotifyOpenValve3();
#endif

    valve3ValveStatus = 1;
    modeLabel();
  } else {
    modeSelect = 1;
    valve3ValveStatus = 0;
    lineSender = "Manual Blynk";

#ifdef LINENOTIFY
    lineNotifyCloseValve3();
#endif

    modeLabel();
  }
}

BLYNK_WRITE(Widget_valve4) {
  forceStopAllTimer();
  resetTerminal();
  if (param.asInt() == 1) {
    modeSelect = 1;
    lineSender = "Manual Blynk";

#ifdef LINENOTIFY
    lineNotifyOpenValve4();
#endif

    valve4ValveStatus = 1;
    modeLabel();
  } else {
    modeSelect = 1;
    valve4ValveStatus = 0;
    lineSender = "Manual Blynk";

#ifdef LINENOTIFY
    lineNotifyCloseValve4();
#endif

    modeLabel();
  }
}

BLYNK_WRITE(Widget_WaterAutoTimerButton) {  //water work button
  if (param.asInt() == 1) {
    waterAutoTimerWork = 1;
  } else {
    waterAutoTimerWork = 0;
  }
}

BLYNK_WRITE(Widget_SprayAutoTimerButton) {  //spray work button
  if (param.asInt() == 1) {
    sprayAutoTimerWork = 1;
  } else {
    sprayAutoTimerWork = 0;
  }
}

void updateBlynk() {
  Blynk.virtualWrite(V1, temperatureData);
  Blynk.virtualWrite(V2, humidityData);
  Blynk.virtualWrite(V3, soilMoistureData);
  Blynk.virtualWrite(V6, soilMoistureLevelData);
  Blynk.virtualWrite(V4, lightData);
  Blynk.virtualWrite(V5, lightDataLevel);
  Blynk.virtualWrite(Widget_WifiSignal, WifiPercentSignal());
  Blynk.virtualWrite(Widget_WifiRawValue, WiFi.RSSI());
}

void syncAllBlynk() {
  modeSelect = EEPROM.read(MODE_SELECT_ADDRESS);
  sensorRoundSet = EEPROM.read(SENSOR_ROUND_DURATION_SET_ADDRESS);
  temperatureSet = EEPROM.read(TEMPERATURE_SET_ADDRESS);
  moistureSet = EEPROM.read(MOISTURE_SET_ADDRESS);
  lightSetWrite = EEPROM.read(LIGHT_SET_ADDRESS);
  lightSet = lightSetWrite * 1000;
  autoWaterSprayDurationSet = EEPROM.read(AUTO_WATER_SPRAY_DURATION_SET_ADDRESS);
  waterAutoTimerWork = EEPROM.read(WATER_AUTO_TIMER_ADDRESS);
  sprayAutoTimerWork = EEPROM.read(SPRAY_AUTO_TIMER_ADDRESS);
  rainDelayWork = EEPROM.read(RAIN_DELAY_ADDRESS);
  timer1Work = EEPROM.read(TIMER1_ADDRESS);
  timer2Work = EEPROM.read(TIMER2_ADDRESS);
  timer3Work = EEPROM.read(TIMER3_ADDRESS);
  timer4Work = EEPROM.read(TIMER4_ADDRESS);
  timer5Work = EEPROM.read(TIMER5_ADDRESS);
  timer6Work = EEPROM.read(TIMER6_ADDRESS);
  timer7Work = EEPROM.read(TIMER7_ADDRESS);
  timer8Work = EEPROM.read(TIMER8_ADDRESS);

  modeLabel();
  timer1Label();
  timer2Label();
  timer3Label();
  timer4Label();
  timer5Label();
  timer6Label();
  timer7Label();
  timer8Label();

  Blynk.virtualWrite(Widget_WaterAutoTimerButton, waterAutoTimerWork);
  Blynk.virtualWrite(Widget_SprayAutoTimerButton, sprayAutoTimerWork);
  Blynk.virtualWrite(Widget_SensorRoundSetSlide, sensorRoundSet);
  Blynk.virtualWrite(Widget_MoistureSetSlide, moistureSet);
  Blynk.virtualWrite(Widget_WaterSprayDurationSetSlide, autoWaterSprayDurationSet);
  Blynk.virtualWrite(Widget_TemperatureSetSlide, temperatureSet);
  Blynk.virtualWrite(Widget_LightSetSlide, lightSetWrite);
  Blynk.virtualWrite(Widget_LightLabel, lightSet);
}

void resetTerminal() {
  terminal.println(); terminal.println(); terminal.println(); terminal.println(); terminal.println();
  terminal.println(); terminal.println(); terminal.println(); terminal.println(); terminal.println();
  terminal.println(); terminal.println(); terminal.println(); terminal.println(); terminal.println();
  terminal.println(); terminal.println(); terminal.println(); terminal.println(); terminal.println();
  terminal.println(); terminal.println(); terminal.println(); terminal.println(); terminal.println();
  terminal.println(); terminal.println(); terminal.println(); terminal.println(); terminal.println();
  terminal.println(); terminal.println(); terminal.println(); terminal.println(); terminal.println();
  terminal.println(); terminal.println(); terminal.println(); terminal.println(); terminal.println();
  terminal.flush();
}

void modeLabel() {
  if (modeSelect == 1) {
    Blynk.setProperty(Widget_ModeButton, "onLabel", "MANUAL");
    Blynk.setProperty(Widget_ModeButton, "offLabel", "MANUAL");
  } else if (modeSelect == 2) {
    Blynk.setProperty(Widget_ModeButton, "onLabel", "AUTO");
    Blynk.setProperty(Widget_ModeButton, "offLabel", "AUTO");
  } else if (modeSelect == 3) {
    Blynk.setProperty(Widget_ModeButton, "onLabel", "TIMER");
    Blynk.setProperty(Widget_ModeButton, "offLabel", "TIMER");
  }

  Blynk.virtualWrite(Widget_WaterButton, waterValveStatus);
  Blynk.virtualWrite(Widget_SprayButton, sprayValveStatus);

}

void timer1Label() {
  if (timer1Work == 0) {
    Blynk.setProperty(Widget_TimerButton_1, "onLabel", "OFF");
    Blynk.setProperty(Widget_TimerButton_1, "offLabel", "OFF");
    Blynk.setProperty(Widget_TimerInput_1, "label", "TIMER 1 (OFF)");
  } else if (timer1Work == 1) {
    Blynk.setProperty(Widget_TimerButton_1, "onLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerButton_1, "offLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerInput_1, "label", "TIMER 1 (WATER & SPRAY)");

  } else if (timer1Work == 2) {
    Blynk.setProperty(Widget_TimerButton_1, "onLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerButton_1, "offLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerInput_1, "label", "TIMER 1 (WATER ONLY)");

  } else if (timer1Work == 3) {
    Blynk.setProperty(Widget_TimerButton_1, "onLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerButton_1, "offLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerInput_1, "label", "TIMER 1 (SPRAY ONLY)");
  }
}

void timer2Label() {
  if (timer2Work == 0) {
    Blynk.setProperty(Widget_TimerButton_2, "onLabel", "OFF");
    Blynk.setProperty(Widget_TimerButton_2, "offLabel", "OFF");
    Blynk.setProperty(Widget_TimerInput_2, "label", "TIMER 2 (OFF)");
  } else if (timer2Work == 1) {
    Blynk.setProperty(Widget_TimerButton_2, "onLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerButton_2, "offLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerInput_2, "label", "TIMER 2 (WATER & SPRAY)");

  } else if (timer2Work == 2) {
    Blynk.setProperty(Widget_TimerButton_2, "onLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerButton_2, "offLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerInput_2, "label", "TIMER 2 (WATER ONLY)");

  } else if (timer2Work == 3) {
    Blynk.setProperty(Widget_TimerButton_2, "onLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerButton_2, "offLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerInput_2, "label", "TIMER 2 (SPRAY ONLY)");
  }
}

void timer3Label() {
  if (timer3Work == 0) {
    Blynk.setProperty(Widget_TimerButton_3, "onLabel", "OFF");
    Blynk.setProperty(Widget_TimerButton_3, "offLabel", "OFF");
    Blynk.setProperty(Widget_TimerInput_3, "label", "TIMER 3 (OFF)");
  } else if (timer3Work == 1) {
    Blynk.setProperty(Widget_TimerButton_3, "onLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerButton_3, "offLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerInput_3, "label", "TIMER 3 (WATER & SPRAY)");

  } else if (timer3Work == 2) {
    Blynk.setProperty(Widget_TimerButton_3, "onLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerButton_3, "offLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerInput_3, "label", "TIMER 3 (WATER ONLY)");

  } else if (timer3Work == 3) {
    Blynk.setProperty(Widget_TimerButton_3, "onLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerButton_3, "offLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerInput_3, "label", "TIMER 3 (SPRAY ONLY)");
  }
}

void timer4Label() {
  if (timer4Work == 0) {
    Blynk.setProperty(Widget_TimerButton_4, "onLabel", "OFF");
    Blynk.setProperty(Widget_TimerButton_4, "offLabel", "OFF");
    Blynk.setProperty(Widget_TimerInput_4, "label", "TIMER 4 (OFF)");
  } else if (timer4Work == 1) {
    Blynk.setProperty(Widget_TimerButton_4, "onLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerButton_4, "offLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerInput_4, "label", "TIMER 4 (WATER & SPRAY)");

  } else if (timer4Work == 2) {
    Blynk.setProperty(Widget_TimerButton_4, "onLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerButton_4, "offLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerInput_4, "label", "TIMER 4 (WATER ONLY)");

  } else if (timer4Work == 3) {
    Blynk.setProperty(Widget_TimerButton_4, "onLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerButton_4, "offLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerInput_4, "label", "TIMER 4 (SPRAY ONLY)");
  }
}

void timer5Label() {
  if (timer5Work == 0) {
    Blynk.setProperty(Widget_TimerButton_5, "onLabel", "OFF");
    Blynk.setProperty(Widget_TimerButton_5, "offLabel", "OFF");
    Blynk.setProperty(Widget_TimerInput_5, "label", "TIMER 5 (OFF)");
  } else if (timer5Work == 1) {
    Blynk.setProperty(Widget_TimerButton_5, "onLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerButton_5, "offLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerInput_5, "label", "TIMER 5 (WATER & SPRAY)");

  } else if (timer5Work == 2) {
    Blynk.setProperty(Widget_TimerButton_5, "onLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerButton_5, "offLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerInput_5, "label", "TIMER 5 (WATER ONLY)");

  } else if (timer5Work == 3) {
    Blynk.setProperty(Widget_TimerButton_5, "onLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerButton_5, "offLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerInput_5, "label", "TIMER 5 (SPRAY ONLY)");
  }
}

void timer6Label() {
  if (timer6Work == 0) {
    Blynk.setProperty(Widget_TimerButton_6, "onLabel", "OFF");
    Blynk.setProperty(Widget_TimerButton_6, "offLabel", "OFF");
    Blynk.setProperty(Widget_TimerInput_6, "label", "TIMER 6 (OFF)");
  } else if (timer6Work == 1) {
    Blynk.setProperty(Widget_TimerButton_6, "onLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerButton_6, "offLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerInput_6, "label", "TIMER 6 (WATER & SPRAY)");

  } else if (timer6Work == 2) {
    Blynk.setProperty(Widget_TimerButton_6, "onLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerButton_6, "offLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerInput_6, "label", "TIMER 6 (WATER ONLY)");

  } else if (timer6Work == 3) {
    Blynk.setProperty(Widget_TimerButton_6, "onLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerButton_6, "offLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerInput_6, "label", "TIMER 6 (SPRAY ONLY)");
  }
}

void timer7Label() {
  if (timer7Work == 0) {
    Blynk.setProperty(Widget_TimerButton_7, "onLabel", "OFF");
    Blynk.setProperty(Widget_TimerButton_7, "offLabel", "OFF");
    Blynk.setProperty(Widget_TimerInput_7, "label", "TIMER 7 (OFF)");
  } else if (timer7Work == 1) {
    Blynk.setProperty(Widget_TimerButton_7, "onLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerButton_7, "offLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerInput_7, "label", "TIMER 7 (WATER & SPRAY)");

  } else if (timer7Work == 2) {
    Blynk.setProperty(Widget_TimerButton_7, "onLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerButton_7, "offLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerInput_7, "label", "TIMER 7 (WATER ONLY)");

  } else if (timer7Work == 3) {
    Blynk.setProperty(Widget_TimerButton_7, "onLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerButton_7, "offLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerInput_7, "label", "TIMER 7 (SPRAY ONLY)");
  }
}

void timer8Label() {
  if (timer8Work == 0) {
    Blynk.setProperty(Widget_TimerButton_8, "onLabel", "OFF");
    Blynk.setProperty(Widget_TimerButton_8, "offLabel", "OFF");
    Blynk.setProperty(Widget_TimerInput_8, "label", "TIMER 8 (OFF)");
  } else if (timer8Work == 1) {
    Blynk.setProperty(Widget_TimerButton_8, "onLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerButton_8, "offLabel", "WATER&SPRAY");
    Blynk.setProperty(Widget_TimerInput_8, "label", "TIMER 8 (WATER & SPRAY)");

  } else if (timer8Work == 2) {
    Blynk.setProperty(Widget_TimerButton_8, "onLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerButton_8, "offLabel", "WATER ONLY");
    Blynk.setProperty(Widget_TimerInput_8, "label", "TIMER 8 (WATER ONLY)");

  } else if (timer8Work == 3) {
    Blynk.setProperty(Widget_TimerButton_8, "onLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerButton_8, "offLabel", "SPRAY ONLY");
    Blynk.setProperty(Widget_TimerInput_8, "label", "TIMER 8 (SPRAY ONLY)");
  }
}
