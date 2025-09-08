/************************************************************************************************
                                    Select Option
*************************************************************************************************/
//**********************************************************************************************//
#define BLYNKLOCAL  //define if use blynk local server (option)
// #define LINENOTIFY  //define if use linenotify (option)
//#define NODEREDDASH  //define if use NODE-RED DASHBOARD (option)
#define UBIDOTSDASH  //define if use UBIDOTS DASHBOARD (option)

//**********************************************************************************************//

const char* ssid = "True1-WiFi";
const char* pass = "truetrue";

//const char* ssid = "2PHH7C3 6365";
//const char* pass = "b9(57J09";

#ifdef NODEREDDASH
const char* mqtt_server = "157.245.58.249";
const char* ZoneName = "test_m/esp32";
#endif

const char *UBIDOTS_TOKEN = "BBFF-5sXQqGkld0JkX1Sh67XFvMMsHv9dlm";  // Put here your Ubidots TOKEN
const char *DEVICE_LABEL = "myiotfarm";                             // Put here your Device label to which data  will be published
const char *VARIABLE_LABEL = "Humidity";                            // Put here your Variable label to which data  will be published
const char *VARIABLE_LABEL2 = "soil-moise";
const char *VARIABLE_LABEL3 = "light";
const char *VARIABLE_LABEL4 = "temperature";

#ifdef  BLYNKLOCAL
#define serverBlynk "43.229.135.169" // honey.blynk
#define portBlynk 8080
const char* auth =  "6tGk8LgMEnrgAmAVQyisAI73TO8Tutr8";  //blynk local
#endif

#ifdef LINENOTIFY
#define LINE_TOKEN  "RhA4Ops3MM5Lbp1S4LXgbUbbBeeMll9GWacLJXBey4Q"  //line token
#endif
