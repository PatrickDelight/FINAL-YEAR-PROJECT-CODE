#include <dht.h>

dht DHT;

#define DHT11_PIN 7
#define LIGHT_SENSOR_PIN A3
#define VOLTAGE_SENSOR_PIN A1
#define CURRENT_SENSOR_PIN A0

float adc_voltage = 0.0;
float in_voltage = 0.0;

// solar radiation
float SR = 0.0;

float R1 = 30000.0;
float R2 = 7500.0;

float ref_voltage = 5.0;
int adc_value = 0;

// Variables for current measurement
double Vout = 0;
double Current = 0;

// Scale factor for 20A ACS712
const double scale_factor = 0.1;

const double resConvert = 1024;
double resADC = ref_voltage / resConvert;
double zeroPoint = ref_voltage / 2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Light intensity measurement
  int light = analogRead(LIGHT_SENSOR_PIN);
  
  // Temperature and humidity measurement
  float chk = DHT.read11(DHT11_PIN);
  float temperature = DHT.temperature;
  float humidity = DHT.humidity;

  // Voltage measurement
  adc_value = analogRead(VOLTAGE_SENSOR_PIN);
  adc_voltage = (adc_value * ref_voltage) / 1024.0;
  in_voltage = adc_voltage / (R2 / (R1 + R2));

  // Current measurement
  Vout = 0;
  for (int i = 0; i < 1000; i++) {
    Vout = (Vout + (resADC * analogRead(CURRENT_SENSOR_PIN)));
    delay(1);
  }
  Vout = Vout / 1000;
  Current = (Vout - zeroPoint) / scale_factor;
  Current = Current * 0.1;
  // solar radiation data based on regression model
  // SR = 0.63458(Light)+40.57888
  SR = (0.63458*light)+40.57888;

  // Print all measurements
  //Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.print(",");
  Serial.print(humidity);
  Serial.print(",");
  Serial.print(SR,3);
  Serial.print(",");
  Serial.print(in_voltage*Current, 3);
  //Serial.print(" V, Current = ");
 // Serial.print(Current, 2);
  Serial.print("\n");

  delay(10000);
}

