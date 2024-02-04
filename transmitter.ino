#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define LED_PIN 14
#define PERIOD 2  //14

String a,htmlcode;

//IPAddress local_IP(192,168,4,2);

#ifndef APSSID
#define APSSID "router1"
#define APPSK  "12345678"
#endif

/* Set these to your desired credentials. */
const char *ssid = APSSID;
const char *password = APPSK;

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
   connected to this access point to see it.
*/

void handleRoot() {
  server.send(200, "text/html", htmlcode);
}

//const char *string = "https://buy.stripe.com/test_dR6bLT5Ckaz2fWoeVZ \n";
const char *string = R"(
<!DOCTYPE html>
<html>
<head>
    <style>
img{
  width: 320px;
  height: 240px;
}

header{
  font-family: 'Dancing Script', cursive;
  text-align: center;
  border: 3px solid #2E2E2E;
  padding: 5px;
  width: 400px;
  margin: 0px auto;
  box-shadow: 0px 0px 15px #434F5B;
}
header h1{
  color: #212A3F;
  font-size: 45px;
}
header p{
  color: #434F5B;
}
#topnav{
  font-family: 'Dancing Script', cursive;
  background-color: #434F5B;
  font-size: 30px;
  text-transform: lowercase;
  width: 415px;
  margin: 0 auto;
}
#topnav ul{
  padding: 20px 15px;
  margin: 0px;
  text-align: center;
}
#topnav ul li{
  list-style-type: none;
  display: inline;
}
#topnav ul li a{
  color: #F2F2F2;
  text-decoration: none;
  margin: 0px 5px;
  padding: 5px;
}
#topnav ul li a:hover{
  border-bottom: 3px solid #F2F2F2;
  transition: 50ms linear 0s;
  -moz-transition: 50ms linear 0s;
  -webkit-transition: 50ms linear 0s;
}
body{
  background-color: #F2F2F2;
}
#content{
  font-family: 'Lora', serif;
}
#content h1, h2, h3, h4, h5, h6{
  color: #212A3F;
  text-align: center;
  font-family: 'Dancing Script', cursive;
}
#content p{
  color: #2E2E2E;
  text-align: left;
  width: 415px;
  margin: 0px auto;
}
#content img{
  display: block;
  margin-left: auto;
  margin-right: auto;
}
#content ul{
  text-align: center;
  margin: 0px;
  padding: 0px;
}
#pic1{
  padding-bottom: 5px;
}
#pic2{
  padding-bottom: 5px;
}
#pic3{
  padding-bottom: 5px;
}
footer{
  border-top: 10px solid #434F5B;
  width: 415px;
  margin: 0px auto;
}
footer p{
  float: right;
  padding-top: 5px;
  padding-right: 0px;
  padding-bottom: 5px;
  padding-left: 0px;
  margin: 0px;
  font-family: 'Lora', serif;
}
.footernav{
  padding-top: 5px;
  padding-left: 0px;
  float: left;
}
.footernav ul{
  margin: 0px;
  padding: 0px;
}
.footernav ul li{
  list-style-type: none;
  display: inline;
}
.footernav ul li a:link, .footernav ul li a:visited{
  color: #212A3F;
  text-decoration: none;
  text-transform: lowercase;
  font-family: 'Dancing Script', cursive;
}
.footernav ul li a:hover{
  color: #8F8F8F;
}


    </style>
</head>

<header>
  <h1>Cat Fancy Event</h1>
  <p>The fanciest cat event.</p>
</header>
<br>
<nav id="topnav">
  <ul>
    <li><a href="#">Home</a></li>
    <li><a href="#">About</a></li>
    <li><a href="#">Locations</a></li>
    <li><a href="#">RSVP</a></li>
  </ul>
</nav>

<div id="content">
  <h1>Cat Fancy Event 2014</h1>
  <p>The 115th annual Cat Fancy Event is being held in New York City on December 21st. This is the fanciest cat event of the year, starring over 300 different cats. This event was made to show America how great cats really are. There will be treats at the walk in, and for the cat owners there will be a buffet in the lounge. We thank you for coming to our event site, and hope to see you on December 21st. Thank you.</p>
  <br>
  <img src="https://2.bp.blogspot.com/-e1gP9Sj4HmM/UYBIKLVcP_I/AAAAAAAAA0g/9Hy86hAvnUs/s320/funny-cat-download-hd-backgrounds+%25281%2529.jpg" alt="Cat being fancy" />
  <h2>Featured Cats</h2>
  <ul>
    <li>George C.</li>
    <li>Sam F.</li>
    <li>Doug T.</li>
    <li>Sally Z.</li>
  </ul>
  <br>
  <div id="pic1"><img src="http://media.thedenverchannel.com/photo/2012/09/01/Generic-Cat-19700452_69436_ver1.0_320_240.jpg" alt="George" /></div>
  <div id="pic2"><img src="https://3.bp.blogspot.com/-WHW5J1uTTCY/UERgSSUImII/AAAAAAAAAMk/JrIBdXHajj0/s320/Cat+Pictures+8.jpg" alt="Sam" /></div>
  <div id="pic3"><img src="http://www.weetzies.com/wp-content/uploads/2010/10/birman-cat.jpg" alt="Doug" /></div>
  <div id="pic4"><img src="http://kittentoys.org/wp-content/uploads/toys-for-cats.jpg" alt="Sally" /></div>
  <br>
  <p>These cats will be the showrunners this year. George has a long history in cat events, and is looking forward to this year's Cat Fancy Event. Sam is a world-class runner, and will be showing his new techniques. Doug likes to lay around, and will practice his abilities. Sally was invited because her mom made a fit about not coming.</p>
</div>
<br>
<footer>
<nav class="footernav">
  <ul>
    <li><a href="#">Home</a></li>
    <li><a href="#">About</a></li>
    <li><a href="#">Locations</a></li>
    <li><a href="#">RSVP</a></li>
  </ul>
</nav>
  <p>&copy; - Copyright 2014</p>
</footer>
</html>)";

int string_length;

void send_byte(char my_byte);
void pagedis();
void serialreading();

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(12, INPUT_PULLUP);
  Serial.begin(9600);
  string_length = strlen(string);
  //string_length = string.length();
  //Serial.println(string_length);
}

void loop() {
  //Serial.println(string_length);
  if(digitalRead(12) == LOW)
  {
   for(int i = 0; i < string_length; i++)
   {
    send_byte(string[i]);
   }
   //delay(100);
  }
   serialreading();
   server.handleClient();
}

void serialreading()
{
  while(Serial.available()) {
    a= Serial.readString();// read the incoming data as string
      if(a.length() > 3)
      {
        htmlcode = a;
        Serial.println(htmlcode);
        pagedis();
      }

  }
}

void pagedis()
{
   Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
//  WiFi.softAPConfig(local_IP);
  WiFi.softAP(ssid, password);
 
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void send_byte(char my_byte){
  digitalWrite(LED_PIN, LOW);
  delay(PERIOD);

  uint8_t bin;

  for(int i = 0; i < 8; i++){
    int led_state = bitRead(my_byte, i);
    digitalWrite(LED_PIN, led_state != 0);
    //Serial.println(led_state);
    delay(PERIOD);
  }

  digitalWrite(LED_PIN, HIGH);
  delay(PERIOD);
}
