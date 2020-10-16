/*
 * @title Minimal HTTP updater project sketch
 * @version 1.0
 * @author Christian Schwinne
 */
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>

char apSSID[] = "UpdateMe";
char apPass[] = "recovery";

const char PAGE_index[] PROGMEM = R"=====(
<!DOCTYPE html>
<html><head><title>Flash this ESP8266!</title></head><body>
<h2>Welcome!</h2>
You are successfully connected to your ESP8266.<br>
Please click the button to proceed and upload a new binary firmware!<br><br>
<b>Be sure to double check the firmware (.bin) is suitable!<br>
I am not to be held liable if you accidentally flash a wrong file or something goes wrong during the update!<br>
You are solely responsible for using this tool!</b><br><br>
<form><input type="button" value="Select firmware..." onclick="window.location.href='/update'" />
</form><br>
(c) 2020 Christian Schwinne and Johann Obermeier<br>
<i>Licensed under the MIT license</i> <br>
<i>Uses libraries:</i> <br>
<i>ESP8266 Arduino Core 2.3.0</i> <br>
</body></html>
)=====";

ESP8266WebServer server(80);
ESP8266HTTPUpdateServer httpUpdater;

void setup() {
  WiFi.softAP(apSSID, apPass);
  server.onNotFound([](){
    server.send(200, "text/html", PAGE_index);
  });
  httpUpdater.setup(&server);
  server.begin();
}

void loop() {
  server.handleClient();
}
