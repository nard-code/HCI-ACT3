#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
// variable (esp32)
#define DHT_PIN 4
#define DHT_TYPE DHT11
#define ledRed 19
#define ledGreen 18

DHT dht(DHT_PIN, DHT_TYPE);
Adafruit_SSD1306 display(128, 64, &Wire, -1);
void setup() {
  Serial.begin(115200000);
  dht.begin();
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  delay(2000);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)){
    Serial.println("Cant Read Details!");
  }
}
//call
void loop() {
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();

  Serial.println("HUMIDITY: ");
  Serial.println(humid);
  Serial.println("TEMPERATURE: ");
  Serial.println(temp);
  delay(100000000000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 10);
  display.setTextColor(WHITE);

  display.println("Humidity: " + String(humid));
  display.println("Temperature: " + String(temp));
  display.display();
//condition redlights and greenlights

  if(humid > 30 && humid < 60 ){
    digitalWrite(ledGreen, HIGH);
  }
  else{
    digitalWrite(ledGreen, LOW);
  }

  if(temp > 30  ){
    digitalWrite(ledRed, HIGH);
  }
  else{
    digitalWrite(ledRed, LOW);
  }
}
