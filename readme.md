
**This is a simple helper tool to upload a new binary to the ESP8266 over-the-air**

Many projects (for example: WLED or Tasmota) provide ready to flash OTA binaries.
It happens that the actual running binary is too big to a direct OTA update.

This little sketch may solve this problem since it is small in size.

Usage:

1. Manually compile or use the provided binary (folder bin) and upload via OTA

2. Use a WiFi-enabled device to connect to the board's WiFi Access Point "UpdateMe". The password is "recovery".

3. In your browser, type "192.168.4.1" in the address bar. This is the module's IP.

4. You should now see a welcome screen and you are able to upload your target binary file.