#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Meow";
const char* password = "PoopyPants123";
const char* serverUrl = "http:/192.168.1.1/api/data/"; // Sesuaikan dengan alamat server dan endpoint yang benar

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  // Baca data dari sensor (misalnya suhu dari LM35)
  float temperature = 25.5; // Ganti dengan pembacaan aktual dari sensor
  
  // Kirim data ke server
  if(WiFi.status()== WL_CONNECTED){
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");

    // Buat payload JSON
    String payload = "{\"temperature\":" + String(temperature) "}";

    int httpResponseCode = http.POST(payload);
    
    if(httpResponseCode>0){
      Serial.print("HTTP Response code: http.getstring");
      Serial.println(httpResponseCode);
    }else{
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
  
  delay(5000); // Kirim data setiap 5 detik
}