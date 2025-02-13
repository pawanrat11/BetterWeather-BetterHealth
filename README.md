<p align="center">
    <img src="img/coverGIT.png" />
</p>

# :partly_sunny: BetterWeather-BetterHealth
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;เนื่องจากในปัจจุบันประเทศไทยมีสภาพอากาศที่ร้อน นอกจากนี้ยังประสบปัญหาเรื่องของมลพิษทางอากาศ ซึ่งทั้งสองปัญหานี้สามารถส่งผลต่อสุขภาพ
การใช้ชีวิตและความเป็นอยู่ของประชากร เช่น อากาศที่ร้อนจัดอาจจะทำให้เกิด Heat stroke หรือการได้รับมลพิษทางอากาศในปริมาณที่สูง อาจส่งผลกระทบต่อระบบทางเดินหายใจได้ เป็นต้น
ดังนั้นเราจึงได้จัดทำอุปกรณ์ตรวจวัดอุณหภูมิ ความชื้น และปริมาณฝุ่นในอากาศ จาก *Sensor, Arduino และ nodeMCU8266 และใช้ภาษา C และ C++* ในการเขียนโปรแกรม
เพื่ออุปกรณ์นี้จะได้ช่วยในการตัดสินใจในการวางแผนการใช้ชีวิต หรือการทำกิจกรรมต่าง ๆ ในสภาพอากาศที่เหมาะสม และปลอดภัยต่อสุขภาพ
<br><br><br>
# :wrench: Hardware

ESP8266 (NodeMCU) | Arduino Uno R3 | สาย USB Arduino | DHT11 | 20X4 LCD 
:-: | :-: | :-: | :-: | :-:
<a href=""><img src="img/hw1.jpeg" width="200px"></a>  | <a href=""><img src="img/hw2.png" width="200px"></a> | <a href=""><img src="img/hw3.jpg" width="200px"></a> | <a href=""><img src="img/hw4.jpg" width="200px"></a> | <a href=""><img src="img/hw5.jpg" width="200px"></a>

 GP2Y1014AU0F Dust Sensor | รางถ่าน 9V | Breadboard | สายไฟจัมเปอร์
:-: | :-: | :-: | :-:
<a href=""><img src="img/hw6.jpg" width="200px"></a>  | <a href=""><img src="img/hw7.png" width="200px"></a> | <a href=""><img src="img/hw8.jpg" width="200px"></a> | <a href=""><img src="img/hw9.jpg" width="200px"></a> 

 Power Bank | ถ่าน 9V 
:-: | :-: 
<a href=""><img src="img/hw10.jpg" width="200px"></a>  | <a href=""><img src="img/hw11.jpeg" width="200px"></a>


# :electric_plug: Connection

<p align="center">
    <img src="img/connect.png" />
</p>



# :file_folder: Software
| Arduino | Fritzing |
|:---:|:---:|
|<img src="img/a.png" width="200px" height="120px">|<img src="img/f.png" width="110px" height="120px">|

# :pager: Interface
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ในส่วนของการใช้งาน จะแสดงผลค่าของอุณหภูมิ ความชื้น และค่าของฝุ่นผ่านทาง LCD และจะทำการ Notify ผ่าน LINE
 ### ตัวอย่าง การแสดงผลผ่าน LCD 
<p align="center">
    <img src="img/inter2.png" width="600px" height="400px"/>
</p>

 ### ตัวอย่าง การแสดงผลผ่านแอพลิเคชั่น LINE
<p align="center">
    <img src="img/inter1.png" width="500px" height="400px"/>
</p>

# :computer: Video

:arrow_forward: [BetterWeather-BetterHealth](https://youtu.be/FbBQsLTD08Q) :arrow_backward:

# 👥 Team Member
|<img src="img/pong.jpg" width="190px" height="190px">|<img src="img/mild.jpg" width="190px" height="190px">|<img src="img/nam.jpg" width="190px" height="190px">|<img src="https://avatars0.githubusercontent.com/u/41178248?s=400&u=afc69eb8e89db6013815d8d6ccb8cacdbd972261&v=4" width="190px" height="190px">|
|:---:|:---:|:---:|:---:|
|[ChanyaPong](https://github.com/ChanyaPong)|[Thanaporn80](https://github.com/Thanaporn80)|[NETCHANOK61](https://github.com/NETCHANOK61)|[pawanrat11](https://github.com/pawanrat11)|
|<p>Chanya Chansri</p>:wolf:|<p>Thanaporn Panngam</p>:rabbit:|<p>Netchanok Petchurai</p>:koala:|<p>Pawanrat Mongkolkittham</p>:bear: |
 |      61070038      |      61070080      |      61070106      |      61070119      |



# 👨‍🏫 Instructor

|<a href=""><img src="img/aj_1.jpg" width="150px"></a>  |<a href=""><img src="img/aj_2.jpg" width="150px"></a>  |
| :-: | :-: |
|รศ. ดร. กิติ์สุชาต พสุภา|รศ. ดร. ปานวิทย์ ธุวะนุติ|



# 🔗 Reference
___
- [gp2y1010au](https://www.sparkfun.com/datasheets/Sensors/gp2y1010au_e.pdf)
- [Air Quality](http://www.howmuchsnow.com/arduino/airquality/)
- [Serial Communication](https://mybtechprojects.tech/serial-communication-between-nodemcu-and-arduino/)
- [Notify-BOT](https://www.ioxhop.com/article/47/esp8266-esp8285-%E0%B8%81%E0%B8%B1%E0%B8%9A%E0%B8%81%E0%B8%B2%E0%B8%A3%E0%B8%AA%E0%B9%88%E0%B8%87%E0%B8%81%E0%B8%B2%E0%B8%A3%E0%B9%81%E0%B8%88%E0%B9%89%E0%B8%87%E0%B9%80%E0%B8%95%E0%B8%B7%E0%B8%AD%E0%B8%99%E0%B9%80%E0%B8%82%E0%B9%89%E0%B8%B2-line)

<img scr="img/it.jpg">
<p align="center">
    
รายงานนี้เป็นส่วนหนึ่งของวิชา Computer Programming (06016315)

คณะเทคโนโลยีสารสนเทศ สถาบันเทคโนโลยีพระจอมเกล้าเจ้าคุณทหารลาดกระบัง

</p>


___
