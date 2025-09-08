/****************************************
                Helper
****************************************/
#define ONE_MINUTE 60000 // 1 minute

#define DHTPIN 4 // Digital pin connected to the DHT sensor

// Uncomment whatever type you're using!
#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321

// #Define sensor Pin
#define SoilSensorPin 34
#define LdrSensorPin 35

// #Define relay pins
#define waterValve 15   //Water Zone 1
#define sprayValve 25   //Water Zone 2
#define valve3 32       //optional
#define valve4 33       //optional

//define eeprom
#define EEPROM_SIZE 512
#define FIRST_ADDRESS 0
#define MODE_SELECT_ADDRESS 8
#define TEMPERATURE_SET_ADDRESS 16
#define MOISTURE_SET_ADDRESS 24
#define LIGHT_SET_ADDRESS 32
#define AUTO_WATER_SPRAY_DURATION_SET_ADDRESS 40
#define WATER_AUTO_TIMER_ADDRESS 48
#define SPRAY_AUTO_TIMER_ADDRESS 56
#define RAIN_DELAY_ADDRESS 64
#define TIMER1_ADDRESS 72
#define TIMER2_ADDRESS 80
#define TIMER3_ADDRESS 88
#define TIMER4_ADDRESS 96
#define TIMER5_ADDRESS 108
#define TIMER6_ADDRESS 112
#define TIMER7_ADDRESS 120
#define TIMER8_ADDRESS 128
#define SENSOR_ROUND_DURATION_SET_ADDRESS 136

//#Define blynk widget
#define Widget_Temperatuer V1
#define Widget_Humidity V2
#define Widget_SoilMoisture V3
#define Widget_SoilMoistureLevel V6
#define Widget_Light V4
#define Widget_LightLevel V5

#define Widget_WifiSignal V9
#define Widget_WifiRawValue V10
#define Widget_SensorLabel V11
#define Widget_SprayLed V13
#define Widget_WaterLed V14

#define Widget_ModeButton V15
#define Widget_SprayButton V16
#define Widget_WaterButton V17

#define Widget_valve3 V70
#define Widget_valve4 V71
#define Widget_valve3Led V72
#define Widget_valve4Led V73

#define Widget_WaterAutoTimerInput V21
#define Widget_WaterAutoTimerButton V22
#define Widget_SprayAutoTimerInput V23
#define Widget_SprayAutoTimerButton V24

#define Widget_WaterSprayDurationSetSlide V25
#define Widget_LightSetSlide V27
#define Widget_LightLabel V28
#define Widget_TemperatureSetSlide V29
#define Widget_MoistureSetSlide V30
#define Widget_SensorRoundSetSlide V31

#define Widget_TimerInput_1 V41
#define Widget_TimerInput_2 V42
#define Widget_TimerInput_3 V43
#define Widget_TimerInput_4 V44
#define Widget_TimerInput_5 V45
#define Widget_TimerInput_6 V46
#define Widget_TimerInput_7 V47
#define Widget_TimerInput_8 V48

#define Widget_TimerButton_1 V51
#define Widget_TimerButton_2 V52
#define Widget_TimerButton_3 V53
#define Widget_TimerButton_4 V54
#define Widget_TimerButton_5 V55
#define Widget_TimerButton_6 V56
#define Widget_TimerButton_7 V57
#define Widget_TimerButton_8 V58

#define Widget_TerminalBug V61
