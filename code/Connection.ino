/****************************************
          Connection Functions
****************************************/
void connectInternet() {
  Serial.println("Start Connect Internet");

   display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_10);
  display.drawString(64, 24, "Connect Internet...");

  // write the buffer to the display
  display.display();

  connectCount = 0;
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    connectCount++;
    delay(500);
    Serial.print(".");
    if (connectCount > 10) ESP.restart();
  }

  Serial.println(""); Serial.print("WiFi connected IP address: "); Serial.println(WiFi.localIP());


#ifdef BLYNKLOCAL
  connectCount = 0;
  Blynk.config(auth, serverBlynk, portBlynk);
  Blynk.connect();

  while (Blynk.connect() == false) {
    connectCount++;
    delay(500);
    Serial.print(".");
    if (connectCount > 20) ESP.restart();
  }

#endif
}

BLYNK_CONNECTED() {
  if (isFirstConnect == 1) {
    Blynk.syncAll();
    //Blynk.notify("TIMER STARTING!!!!");
    isFirstConnect = 0;
    syncAllBlynk();
    updateBlynk();
  }
}

void reconnectBlynk() {
  if (!Blynk.connected()) {
    if (Blynk.connect()) {
      BLYNK_LOG("Reconnected");
    } else {
      BLYNK_LOG("Not reconnected");
      forceStopAllValve();
    }
  }
}

void blynkConnectTask(void *p) {
  while (1) {
    if (!Blynk.connected()) {
      if (Blynk.connect()) {
        BLYNK_LOG("Reconnected");
      } else {
        BLYNK_LOG("Not reconnected");
        forceStopAllValve();
      }
    }
    vTaskDelay(5000 / portTICK_PERIOD_MS);  //10000
  }
}

void wifiConnectTask(void *p) {
  while (1) {
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("WiFi Disconnected.");
      connectInternet();
    }
    vTaskDelay(10000 / portTICK_PERIOD_MS);
  }
}
