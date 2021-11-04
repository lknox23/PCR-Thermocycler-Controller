//for PID, use PWM to have it be on some percent of the time
//#include <cmath>
#include <OneWire.h> 
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2 

int ssrPin = 7;
int fanPin = 9;

double goal = 70; //degrees F

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ssrPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  sensors.begin(); 
}

void loop() {
  sensors.requestTemperatures();
  double temp = sensors.getTempFByIndex(0);

  if(temp<goal) {
    digitalWrite(ssrPin, HIGH);
    digitalWrite(fanPin, LOW);
  } else {
    digitalWrite(ssrPin, LOW);
    digitalWrite(fanPin, HIGH);
  }

  //Serial.print("temperature is ");
  Serial.print(goal);
  Serial.print(";");
  Serial.print(temp);
  Serial.print("\n");
}
