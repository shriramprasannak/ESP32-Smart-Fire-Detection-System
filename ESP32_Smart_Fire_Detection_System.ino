#include <DHTesp.h>
#include <ESP32Servo.h>


#define DHT_PIN 15
#define SMOKE_PIN 34
#define FLAME_DO 27
#define FLAME_AO 35


#define BUZZER_PIN 23
#define GREEN_LED 25
#define YELLOW_LED 26
#define RED_LED 33
#define SERVO_PIN 18
#define RELAY_PIN 19

DHTesp dhtSensor;
Servo emergencyServo;

void setup() {
  Serial.begin(115200);

  
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);

  
  pinMode(SMOKE_PIN, INPUT);
  pinMode(FLAME_DO, INPUT);
  pinMode(FLAME_AO, INPUT);

  
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  
  emergencyServo.attach(SERVO_PIN);
  emergencyServo.write(0);

  digitalWrite(RELAY_PIN, LOW);

  Serial.println("====================================");
  Serial.println("SMART FIRE DETECTION SYSTEM");
  Serial.println("ESP32 EMERGENCY RESPONSE SYSTEM");
  Serial.println("====================================");
}

void loop() {

  TempAndHumidity data = dhtSensor.getTempAndHumidity();

  float temperature = data.temperature;

  int smokeRaw = analogRead(SMOKE_PIN);
  int smokeLevel = map(smokeRaw, 0, 4095, 0, 100);

  int flameDigital = digitalRead(FLAME_DO);
  int flameAnalog = analogRead(FLAME_AO);

  bool flameDetected = (flameDigital == LOW);

  Serial.println("------------------------------------");

  Serial.print("Temperature : ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Smoke Level : ");
  Serial.print(smokeLevel);
  Serial.println("%");

  Serial.print("Flame Analog : ");
  Serial.println(flameAnalog);

  Serial.print("Flame : ");

  if (flameDetected) {
    Serial.println("DETECTED");
  } else {
    Serial.println("NOT DETECTED");
  }

  
  if ((temperature >= 60 && smokeLevel >= 70) || flameDetected) {

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    digitalWrite(RELAY_PIN, HIGH);

    tone(BUZZER_PIN, 1500);

    emergencyServo.write(90);

    Serial.println("System Status : FIRE EMERGENCY");
    Serial.println("Emergency Response : ACTIVE");
    Serial.println("Relay : ON");
    Serial.println("Emergency Servo : ACTIVATED");
  }

  
  else if (temperature >= 45 || smokeLevel >= 50) {

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    digitalWrite(RELAY_PIN, LOW);

    tone(BUZZER_PIN, 800);

    emergencyServo.write(0);

    Serial.println("System Status : WARNING");
    Serial.println("Emergency Response : STANDBY");
  }

  
  else {

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);

    digitalWrite(RELAY_PIN, LOW);

    noTone(BUZZER_PIN);

    emergencyServo.write(0);

    Serial.println("System Status : SAFE");
    Serial.println("Emergency Response : OFF");
  }

  delay(1000);
}