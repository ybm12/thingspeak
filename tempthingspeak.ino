#include <WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "Gearbox Members";   // Your Network SSID
const char* password = "Members@Gearbox";       // Your Network Password

int val;
int pin = 36; // LM35 Pin Connected at A0 Pin

WiFiClient client;

unsigned long myChannelNumber = 2312303; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "6X5NK7AF3GV90T34"; //Your Write API Key

void setup()
{
  Serial.begin(115200);
  delay(2);
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}

void loop()
{
  val = analogRead(pin)*0.322265; // Read Analog values and Store in val variable
  Serial.print("Temperature: ");
  Serial.print(val);                 // Print on Serial Monitor
  Serial.println("*C");
  delay(1000);
  ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
  delay(100);
}

