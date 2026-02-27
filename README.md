#Smart Farm IoT

โครงงานระบบฟาร์มอัจฉริยะ (Smart Farm IoT) สำหรับประยุกต์ใช้ในการเกษตรแม่นยำสูง เพื่อตรวจวัดสภาพแวดล้อมและควบคุมการทำงานของอุปกรณ์ในฟาร์ม โดยใช้บอร์ดไมโครคอนโทรลเลอร์ ESP32 เป็นตัวประมวลผลหลัก ระบบสามารถควบคุมได้ทั้งแบบอัตโนมัติ (Auto) และแบบทำมือ (Manual) พร้อมทั้งแสดงผลข้อมูลผ่านหน้าจอ OLED แอปพลิเคชัน Blynk และแพลตฟอร์ม Ubidots

## ✨ คุณสมบัติของระบบ (Features)
* ตรวจวัดอุณหภูมิและความชื้นสัมพัทธ์ในอากาศด้วยโมดูล DHT22
* ตรวจวัดความชื้นในดินด้วยเซนเซอร์ Capacitive Soil Moisture Sensor v1.2
* ตรวจวัดความเข้มของแสงด้วย LDR Photoresistor Module
* ควบคุมการทำงานของปั๊มน้ำและโซลินอยด์วาล์ว โดยสามารถแบ่งโซนการรดน้ำได้
* มี Selector switch สำหรับเลือกโหมดการทำงานระหว่าง Auto และ Manual
* แสดงผลค่าต่างๆ และควบคุมอุปกรณ์แบบ Real-time ผ่านแอปพลิเคชัน Blynk (ระบบ Local Server)
* บันทึกข้อมูลและแสดงผลกราฟ Dashboard ผ่านทางแพลตฟอร์ม Ubidots
* แสดงสถานะการทำงานของระบบด้วยหลอดไฟ Pilot Lamp LED

## 🛠️ อุปกรณ์ฮาร์ดแวร์ (Hardware Components)
* บอร์ดไมโครคอนโทรลเลอร์ ESP32-WROOM-32U (DevKitC V4)
* 0.96" OLED Display Module
* DHT22 / AM2302 Module
* Capacitive Soil Moisture Sensor v1.2
* LDR Photoresistor Sensor Module
* 5V Relay module 4 Channel
* 12V Solenoid valve
* Selector switch และ Pilot Lamp LED

## 💻 การตั้งค่าซอฟต์แวร์ (Software Configuration)
ก่อนทำการอัปโหลดโค้ดลงบอร์ด ESP32 กรุณาเปิดไฟล์ `config.h` เพื่อตั้งค่าการเชื่อมต่อเครือข่ายและแพลตฟอร์ม IoT ดังนี้:

* **การเลือกใช้งานแพลตฟอร์ม:** สามารถเลือกเปิดใช้งานแอปพลิเคชันโดยการนำเครื่องหมาย comment ออก เช่น `#define BLYNKLOCAL` สำหรับใช้งาน Blynk หรือ `#define UBIDOTSDASH` สำหรับใช้งาน Ubidots
* **การเปิดแจ้งเตือน:** สามารถเปิดใช้งาน `#define LINENOTIFY` สำหรับการแจ้งเตือนผ่านแอปพลิเคชัน LINE
* **การเชื่อมต่อ Wi-Fi:** ตั้งค่าเครือข่ายอินเทอร์เน็ตที่ตัวแปร `ssid` และ `pass`
* **การตั้งค่า Ubidots:** ระบุ `UBIDOTS_TOKEN` ของคุณ และกำหนด `DEVICE_LABEL` เป็น `"myiotfarm"` พร้อมตรวจสอบ `VARIABLE_LABEL` ต่างๆ ที่ใช้รับข้อมูล
* **การตั้งค่า Blynk (Local Server):** ระบุ IP ของ Server เป็น `"43.229.135.169"` พอร์ต `8080` และใส่รหัส `auth` Token ที่ได้รับจากอีเมล
* **การตั้งค่า LINE Notify:** นำ Token ที่ได้รับจาก LINE แจ้งเตือนมาใส่ใน `LINE_TOKEN`

## 🚀 วิธีการติดตั้งและอัปโหลดโค้ด (Installation & Upload)
1. ติดตั้งโปรแกรม Arduino IDE และเพิ่ม Board Manager ลิงก์สำหรับ ESP32
2. ค้นหาและติดตั้งบอร์ด `esp32` ใน Boards Manager
3. เปิดไฟล์โปรเจกต์ `.ino` ด้วย Arduino IDE
4. แก้ไขตั้งค่าในไฟล์ `config.h` ให้เรียบร้อย
5. เลือกบอร์ดไปที่เมนู **Tools > Board: Node32s**
6. เลือกพอร์ตการเชื่อมต่อที่เมนู **Tools > Port** ให้ตรงกับบอร์ด ESP32
7. กดปุ่ม **Upload** เพื่อทำการคอมไพล์และแฟลชโค้ดลงบอร์ด
8. เปิด Serial Monitor และปรับ Baud rate เป็น `115200` เพื่อดูสถานะการทำงานของบอร์ดและการเชื่อมต่อเครือข่าย
