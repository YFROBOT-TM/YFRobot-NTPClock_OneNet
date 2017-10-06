##ESP8266 Weather Station
该项目基于[Arduino core for ESP8266 WiFi chip](https://github.com/esp8266/Arduino)项目，ESP8266 wifi 通过获取网络NTP(OneNet NTP服务)，串口输出打印！

NTP，Network Time Protocol，网络时间协议；它是用来使网络中的各个计算机时间同步的一种协议。它的用途是把计算机的时钟同步到世界协调时UTC，其精度在局域网内可达0.1ms，在互联网上绝大多数的地方其精度可以达到1-50ms。

[arduino IDE 配置](http://file.yfrobot.com/file/wifi/nodemcu/arduino/arduinoIDEForTheESP8266.html)

串口打印：

![](https://github.com/finalvalue/YFRobot-NTPClock_OneNet/blob/master/image/NTP%20time.png?raw=true)

世界时区分布图：![](https://github.com/finalvalue/YFRobot-NTPClock_OneNet/blob/master/image/time-zone-offset.png?raw=true)

###Using library
* [Time Library](https://github.com/PaulStoffregen/Time)
* [Timezone library](https://github.com/JChristensen/Timezone)

Created by [YFROBOT](www.yfrobot.com)
