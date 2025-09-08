/************************************************************
                      Include Libraries
 ***********************************************************/
#define BLYNK_PRINT Serial
#include <TridentTD_LineNotify.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>
#include <BlynkSimpleEsp32.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
#include <EEPROM.h>
#include "UbidotsEsp32Mqtt.h"

///// OLE 0.96 Display //////
// Include the correct display library
#include <Wire.h>               // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"        // legacy: #include "SSD1306.h"
// Initialize the OLED display using Arduino Wire:
SSD1306Wire display(0x3c, SDA, SCL);   // ADDRESS, SDA, SCL  -  SDA and SCL usually populate automatically based on your board's pins_arduino.h

#include "config.h"
#include "helper.h"

#include "DHT.h"
DHT dht(DHTPIN, DHTTYPE);

int modeSelect = 1;
int sensorRoundSet = 1;

int temperatureSet = 32;
int moistureSet = 80;
int lightSet = 20000;

int autoWaterSprayDurationSet = 1;
bool isFirstConnect = 1;
bool sensorRoundStatus = 5;
uint32_t longPressTime = 500;
String timeStamp = "wait";
String todaySchedule = "wait";
String baseTopic = "espcalendar/";

char *Day[] = {" ", "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
char Date[64];
char Time[64];

float temperatureData, humidityData, temperature, humidity;

int soilMoistureData, lightData, tesmod, reading, firstState, lightSetWrite, lastMode,
    timerNumber, CurrentWifiSignal, WifiSignal, firstDisplay, msgCount, timer1Work, timer2Work,
    timer3Work, timer4Work, timer5Work, timer6Work, timer7Work, timer8Work, mqttConnectCount,
    connectCount, CurrentWiFiSignal, CurrentLightValue, MapReadLightValue, lightDataLevel, CurrentSoilValue, MapReadSoilValue, soilMoistureLevelData;

bool waterValveStatus, sprayValveStatus, valve3ValveStatus, valve4ValveStatus , waterAutoTimerWork, sprayAutoTimerWork, waterAutoTimerStatus,
     sprayAutoTimerStatus, sensorStatus, rainDelayWork, lastWaterValveStatus, lastSprayValveStatus, lastValve3Status, lastValve4Status;

bool buttonActive, longPressActive, oldModeButtonState, dataModeButton, dots, lastWater, lastSpray,
     lastAutoWater, lastAutoSpray, lastRainDelay, firstLoop, firstRecieve, mqttUpdate;

bool timer1WaterStatus, timer1SprayStatus, timer2WaterStatus, timer2SprayStatus, timer3WaterStatus,
     timer3SprayStatus, timer4WaterStatus, timer4SprayStatus, timer5WaterStatus, timer5SprayStatus,
     timer6WaterStatus, timer6SprayStatus, timer7WaterStatus, timer7SprayStatus, timer8WaterStatus,
     timer8SprayStatus, timer1On, timer2On, timer3On, timer4On, timer5On, timer6On, timer7On,
     timer8On;

uint32_t startsecondswd, stopsecondswd, nowseconds, buttonTimer, autoMillis, currentMillis,
         newMillis, sensorRoundMillis, mqttMillis, runTime;

String  weatherMain, weatherDescription, weatherCity, displayTime, displayHour, displayMinute,
        lineNotifyMessage, lineSender, lineMessage, lineDataSet, displayDayOfMonth, displayMonth,
        displayYear, outgoing, incoming;

long rssi;
long currentNow = millis();
long lastMeasure = 0;
int counter = 0;

String Temperature;
String Humidity;
String soilMoisture;
String LightSensor;
String PumpStatus;

uint32_t lastReconnectAttempt = 0;

WiFiClient espClient;
PubSubClient client(espClient);

BlynkTimer timer;
WidgetRTC rtc;

WidgetTerminal terminal(Widget_TerminalBug);

WidgetLED waterBlynkLed(Widget_WaterLed);
WidgetLED sprayBlynkLed(Widget_SprayLed);
WidgetLED valve3BlynkLed(Widget_valve3Led);
WidgetLED valve4BlynkLed(Widget_valve4Led);

/****************************************
        Ubidots Define Constants
 ****************************************/
Ubidots ubidots(UBIDOTS_TOKEN);

/****************************************
            Auxiliar Functions
 ****************************************/
void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }

  Serial.println();
}

/****************************************
           Setup Functions
****************************************/
void setup() {
  pinMode(waterValve, OUTPUT); digitalWrite(waterValve, LOW);
  pinMode(sprayValve, OUTPUT); digitalWrite(sprayValve, LOW);
  pinMode(valve3, OUTPUT); digitalWrite(valve3, LOW);
  pinMode(valve4, OUTPUT); digitalWrite(valve4, LOW);

  pinMode(LED_BUILTIN, OUTPUT);


  // Initialising the UI will init the display too.
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

#ifdef LINENOTIFY
  Serial.println(LINE.getVersion());
  LINE.setToken(LINE_TOKEN);
#endif

  Serial.begin(115200);
  while (!Serial);
  Serial.println("");

  EEPROM.begin(EEPROM_SIZE);
  forceStopAllValve();
  readConfig();
  connectInternet();

#ifdef NODEREDDASH
  client.setServer(mqtt_server, 1883);    // MQTT Broker setup
#endif

#ifdef UBIDOTSDASH
  ubidots.setCallback(callback);
  ubidots.setup();
  ubidots.reconnect();
  // timer_Ubi = millis();
#endif

  dht.begin();
  rtc.begin();

  timer.setInterval(10000L, activeToday);
  timer.setInterval(10000L, writeEeprom);
  timer.setInterval(10000L, updateBlynk);

  //FreeRTOS
  // xTaskCreate(&TaskBlink, "TaskBlink", 1024, NULL, 9, NULL);
  xTaskCreate(&getSensorDataTask, "getSensorData", 3000, NULL, 10, NULL);
  xTaskCreate(&blynkConnectTask, "blynkConnect", 3000, NULL, 10, NULL);
  xTaskCreate(&wifiConnectTask, "wifiConnect", 3000, NULL, 10, NULL);

#ifdef UBIDOTSDASH
  xTaskCreate(&updateUbidots, "updateUbidots", 3000, NULL, 10, NULL);
#endif

#ifdef NODEREDDASH
  xTaskCreate(&TaskSendDatatoNodeRed, "SendDatatoNodeRed", 3000, NULL, 10, NULL);
#endif
}

/****************************************
           Loop Functions
****************************************/
void loop() {
  currentMillis = millis();
  checkValve();
  checkFunction();

  if (Blynk.connected()) {
    Blynk.run();
  }

#ifdef NODEREDDASH
  if (!client.connected()) {
    Serial.println("=== MQTT NOT CONNECTED ===");
    // Reconnect every 10 seconds
    uint32_t t = millis();
    if (t - lastReconnectAttempt > 10000L) {
      lastReconnectAttempt = t;
      if (mqttConnect()) {
        lastReconnectAttempt = 0;
      }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
    return;
  }

  if (!client.loop())client.connect("ESP32Client");
  client.loop();
#endif

#ifdef UBIDOTSDASH
  // put your main code here, to run repeatedly:
  if (!ubidots.connected()) {
    ubidots.reconnect();
  }
  ubidots.loop();
#endif

  timer.run();
  checkDebug();
}

/****************************************
           Check Functions
****************************************/

void checkDebug() {
  newMillis = millis();
  if ((newMillis - currentMillis) < 10 ) Serial.println(newMillis - currentMillis);
  //Serial.println(newMillis - currentMillis);
}

void checkFunction() {
  if (modeSelect == 2) {
    autoCheck();
  } else if (modeSelect == 3) {
    timerCheck();
  }

  if (((currentMillis - sensorRoundMillis) >= ((sensorRoundSet * ONE_MINUTE) + 30000)) && (sensorRoundStatus == 0)) {
    sensorRoundStatus = 5;
  }

  if (firstLoop == 0) {
    getTime();
    resetTerminal();
    firstLoop = 1;
  }
}

void checkValve() {
  //Zone 1 valve check
  if (waterValveStatus == 1) {
    digitalWrite(waterValve, HIGH);
    waterBlynkLed.on();
  } else {
    digitalWrite(waterValve, LOW);
    waterBlynkLed.off();
  }

  //Zone 2 valve check
  if (sprayValveStatus == 1) {
    digitalWrite(sprayValve, HIGH);
    sprayBlynkLed.on();
  } else {
    digitalWrite(sprayValve, LOW);
    sprayBlynkLed.off();
  }

  //Valve3 valve check
  if (valve3ValveStatus == 1) {
    digitalWrite(valve3, HIGH);
    valve3BlynkLed.on();
  } else {
    digitalWrite(valve3, LOW);
    valve3BlynkLed.off();
  }

  //Valve4 valve check
  if (valve4ValveStatus == 1) {
    digitalWrite(valve4, HIGH);
    valve4BlynkLed.on();
  } else {
    digitalWrite(valve4, LOW);
    valve4BlynkLed.off();
  }

}

void closeAllValve() {  //for close all valve
  if ((waterValveStatus  == 1) || (sprayValveStatus == 1) || (valve3ValveStatus == 1) || (valve4ValveStatus == 1)) {
    waterValveStatus = 0;
    sprayValveStatus = 0;
    valve3ValveStatus = 0;
    valve4ValveStatus = 0;

#ifdef LINENOTIFY
    lineNotifyCloseAllValve();
#endif

  }
}

void openAllValve() {  //for open all valve
  if ((waterValveStatus  == 0) || (sprayValveStatus == 0) || (valve3ValveStatus == 0) || (valve4ValveStatus == 0)) {
    waterValveStatus = 1;
    sprayValveStatus = 1;
    valve3ValveStatus = 1;
    valve4ValveStatus = 1;

#ifdef LINENOTIFY
    lineNotifyOpenAllValve();
#endif

  }
}

void activeToday() {
  if (year() != 1970) {
    if (modeSelect == 3) {

      if ((timer1Work == 1) || (timer1Work == 2) || (timer1Work == 3)) {
        Blynk.syncVirtual(Widget_TimerInput_1);
      } else if (timer1Work == 0) {
        timer1CloseAll();
        timer1On = 0;
      }

      if ((timer2Work == 1) || (timer2Work == 2) || (timer2Work == 3)) {
        Blynk.syncVirtual(Widget_TimerInput_2);
      } else if (timer2Work == 0) {
        timer2CloseAll();
        timer2On = 0;
      }

      if ((timer3Work == 1) || (timer3Work == 2) || (timer3Work == 3)) {
        Blynk.syncVirtual(Widget_TimerInput_3);
      } else if (timer3Work == 0) {
        timer3CloseAll();
        timer3On = 0;
      }

      if ((timer4Work == 1) || (timer4Work == 2) || (timer4Work == 3)) {
        Blynk.syncVirtual(Widget_TimerInput_4);
      } else if (timer4Work == 0) {
        timer4CloseAll();
        timer4On = 0;
      }

      if ((timer5Work == 1) || (timer5Work == 2) || (timer5Work == 3)) {
        Blynk.syncVirtual(Widget_TimerInput_5);
      } else if (timer5Work == 0) {
        timer5CloseAll();
        timer5On = 0;
      }

      if ((timer6Work == 1) || (timer6Work == 2) || (timer6Work == 3)) {
        Blynk.syncVirtual(Widget_TimerInput_6);
      } else if (timer6Work == 0) {
        timer6CloseAll();
        timer6On = 0;
      }

      if ((timer7Work == 1) || (timer7Work == 2) || (timer7Work == 3)) {
        Blynk.syncVirtual(Widget_TimerInput_7);
      } else if (timer7Work == 0) {
        timer7CloseAll();
        timer7On = 0;
      }

      if ((timer8Work == 1) || (timer8Work == 2) || (timer8Work == 3)) {
        Blynk.syncVirtual(Widget_TimerInput_8);
      } else if (timer8Work == 0) {
        timer8CloseAll();
        timer8On = 0;
      }

    } else if (modeSelect == 2) {

      if (waterAutoTimerWork == 1) Blynk.syncVirtual(Widget_WaterAutoTimerInput);
      if (sprayAutoTimerWork == 1) Blynk.syncVirtual(Widget_SprayAutoTimerInput);
    }
  }
}
