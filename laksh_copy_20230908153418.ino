#define BLYNK_TEMPLATE_ID "TMPL3ulK3ITau"
#define BLYNK_TEMPLATE_NAME "DHT sensor"
#define BLYNK_AUTH_TOKEN "1FfdYtdZzmrXPPsgHkjGAQ2LYhItQ2SF"
#include <DHT.h>
#include <BlynkSimpleEsp8266.h>
 
#define DHTPIN 4 // DATA PIN IS CONNECTED TO D2 PIN
#define DHTTYPE DHT11 // NAME THE SENSOR AS AN OBJECT 


char auth[]="1FfdYtdZzmrXPPsgHkjGAQ2LYhItQ2SF";
char ssid[]="POCO X4 Pro 5G";
char pass[]="hihihihi";

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test Successful!");
  Blynk.begin(auth,ssid, pass);
  Serial.println("Blynk Connected Successfully");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float humid = dht.readHumidity();
  float temp = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(humid) || isnan(temp) || isnan(f))
  {
    Serial.println("Something is not working as intended.");
    return; 
  }
  Serial.println("Humidity: ");
  Serial.print(humid);
  Serial.print("%");
  Serial.println("Temperature");
  Serial.print(temp);
  Serial.print("degrees celsius.");
  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, humid);
  delay(1000);
}
