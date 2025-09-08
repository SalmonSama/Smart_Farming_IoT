/****************************************
             Line notify
****************************************/
#ifdef LINENOTIFY

void lineNotifyOpenAllValve() {  // for open all valve
  if ((lastWaterValveStatus == 0) || (lastSprayValveStatus == 0) || (lastValve3Status == 0) || (lastValve4Status == 0)) {  //if last Spray or water close
    lineMessage = "Open All Valve";
    lineNotify();
    lastWaterValveStatus = 1;  //change last water valve to open
    lastSprayValveStatus = 1;  //change last Spray valve to copen
    lastValve3Status = 1;
    lastValve4Status = 1;
  }
}

void lineNotifyCloseAllValve() {  // for close all valve
  if ((lastWaterValveStatus == 1) || (lastSprayValveStatus == 1) || (lastValve3Status == 1) || (lastValve4Status == 1)) {   //if last Spray or water open
    lineMessage = "Close All Valve";
    lineNotify();
    lastWaterValveStatus = 0;  //change last water valve to close
    lastSprayValveStatus = 0;  //change last Spray valve to close
    lastValve3Status = 0;
    lastValve4Status = 0;
  }
}

void lineNotifyOpenWaterValve() {  // for open water valve
  if (lastWaterValveStatus == 0) {  //if last water valve close
    lineMessage = "Open Water Valve";
    lineNotify();
    lastWaterValveStatus = 1;  //change last water valve to open
  }
}

void lineNotifyCloseWaterValve() {  // for close water valve
  if (lastWaterValveStatus == 1) {  //if last water valve open
    lineMessage = "Close Water Valve";
    lineNotify();
    lastWaterValveStatus = 0;  //change last water valve to close
  }
}

void lineNotifyOpenSprayValve() {  // for open Spray valve
  if (lastSprayValveStatus == 0) {  //if last Spray valve close
    lineMessage = "Open  Spray Valve";
    lineNotify();
    lastSprayValveStatus = 1;  //change last Spray valve to open
  }
}

void lineNotifyCloseSprayValve() {  // for close Spray valve
  if (lastSprayValveStatus == 1) {  //if last Spray valve open
    lineMessage = "Close Spray Valve";
    lineNotify();
    lastSprayValveStatus = 0;  //change last Spray valve to close
  }
}

void lineNotifyOpenValve3() {  // for open Valve 3
  if (lastValve3Status == 0) {  //if last Spray valve close
    lineMessage = "Open Valve 3";
    lineNotify();
    lastValve3Status = 1;  //change last Spray valve to open
  }
}

void lineNotifyCloseValve3() {  // for Close Valve 3
  if (lastValve3Status == 1) {  //if last Spray valve open
    lineMessage = "Close Valve 3";
    lineNotify();
    lastValve3Status = 0;  //change last Spray valve to close
  }
}

void lineNotifyOpenValve4() {  // for open Valve 4
  if (lastValve4Status == 0) {  //if last Spray valve close
    lineMessage = "Open Valve 4";
    lineNotify();
    lastValve4Status = 1;  //change last Spray valve to open
  }
}

void lineNotifyCloseValve4() {  // for Close Valve 4
  if (lastValve4Status == 1) {  //if last valve 4 open
    lineMessage = "Close Valve 4";
    lineNotify();
    lastValve4Status = 0;  //change last valve 4 to close
  }
}

void lineNotify() {
  lineNotifyMessage = "";
  lineNotifyMessage += lineMessage;
  lineNotifyMessage += " by ";
  lineNotifyMessage += lineSender;
  lineNotifyMessage += lineDataSet;
  lineNotifyMessage += " :-)";
  lineDataSet = "";
  LINE.notify(lineNotifyMessage);
}

void lineNotifySensor() {
  lineNotifyMessage = "";
  lineNotifyMessage += "Recieve data from Sensor, Temp : ";
  lineNotifyMessage += temperatureData;
  lineNotifyMessage += " C * Moisture : ";
  lineNotifyMessage += soilMoistureData;
  lineNotifyMessage += " % * Light : ";
  lineNotifyMessage += lightData;
  lineNotifyMessage += " Lux ";
  lineNotifyMessage += " :-)";
  LINE.notify(lineNotifyMessage);
}
#endif
