/*
   NTP Clock Program -- 网络时钟
   Network Time Protocol (NTP)
   ESP8266 连接到NET WORK ，获取NTP

  library:
   https://github.com/PaulStoffregen/Time
   https://github.com/JChristensen/Timezone

   by: yfrobot
   http://www.yfrobot.com
*/

#include <ESP8266WiFi.h>
#include <Time.h>
#include <Timezone.h>
#include "NTP.h"


// Set your WiFi login credentials
#define WIFI_SSID "YFROBOT"       // 使用时请修改为当前你的 wifi ssid
#define WIFI_PASS "yfrobot2016"   // 使用时请修改为当前你的 wifi 密码

#define ledPin 14                          // 定义ledPin连接到GPIO14

// This clock is in the Mountain Time Zone
// Change this for your timezone
// 北京时间时区
#define STD_TIMEZONE_OFFSET +8    // Standard Time offset (-7 is mountain time)

// ***************************************************************
// TimeZone and Daylight Savings Time Rules
// ***************************************************************

// Define daylight savings time rules for the China
TimeChangeRule mySTD = {"", First,  Sun, Jan, 0, STD_TIMEZONE_OFFSET * 60};
Timezone myTZ(mySTD, mySTD);

WiFiClient client;

// This function is called once a second
void updateDisplay(void) {

  TimeChangeRule *tcr;        // Pointer to the time change rule

  // Read the current UTC time from the NTP provider
  time_t utc = now();

  // Convert to local time taking DST into consideration
  time_t localTime = myTZ.toLocal(utc, &tcr);

  // Map time to pixel positions
  int weekdays=   weekday(localTime);
  int days    =   day(localTime);
  int months  =   month(localTime);
  int years   =   year(localTime);
  int seconds =   second(localTime);
  int minutes =   minute(localTime);
  int hours   =   hour(localTime) ;   //12 hour format use : hourFormat12(localTime)  isPM()/isAM()
  Serial.println("");
  Serial.print("Current local time:");
  Serial.print(days);
  Serial.print("/");
  Serial.print(months);
  Serial.print("/");
  Serial.print(years);
  Serial.print(" - ");
  Serial.print(hours);
  Serial.print(":");
  Serial.print(minutes);
  Serial.print(":");
  Serial.print(seconds);
  Serial.print(" - ");
  Serial.print(dayStr(weekdays));
  Serial.println("");
}

void setup() {

  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  delay(10);

  // We start by connecting to a WiFi network
  initNTP(WIFI_SSID, WIFI_PASS);
}

// Previous seconds value
time_t previousSecond = 0;

void loop() {
  //  Update the display only if time has changed
  if (timeStatus() != timeNotSet) {
    if (second() != previousSecond) {
      previousSecond = second();
      // Update the display
      updateDisplay();
    }
  }
  delay(1000);
}

