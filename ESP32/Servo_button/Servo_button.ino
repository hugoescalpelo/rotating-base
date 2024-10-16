#include <ESP32Servo.h>  // Cambia a ESP32Servo

// Definición de pines
const int buttonPin = 23;   // Pin del botón
const int servoPin = 21;    // Pin del servo

// Estado del botón y servo
int buttonState = HIGH;        // Estado actual del botón
int lastButtonState = HIGH;    // Estado anterior del botón
int servoSpeedState = 0;       // Estado del servo (0: apagado, 1: lento, 2: rápido)

unsigned long lastDebounceTime = 0;  // Tiempo del último cambio de estado del botón
unsigned long debounceDelay = 50;    // Retardo para evitar rebotes

Servo servoMotor;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Configurar el pin del botón con pull-up interno
  servoMotor.attach(servoPin);       // Adjuntar el servo al pin 21
  servoMotor.writeMicroseconds(1500); // Detener el servo inicialmente (1500 es el valor neutral)
  Serial.begin(115200);              // Iniciar la comunicación serial
}

void loop() {
  int reading = digitalRead(buttonPin);

  // Verificar si ha habido un cambio en el estado del botón y hacer debounce
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Si el estado ha cambiado después del debounce
    if (reading != buttonState) {
      buttonState = reading;

      // Solo actuar cuando el botón ha sido presionado (cambio a LOW)
      if (buttonState == LOW) {
        servoSpeedState++;
        if (servoSpeedState > 2) {
          servoSpeedState = 0;  // Volver al estado apagado después de la velocidad rápida
        }

        // Controlar el servo según el estado
        switch (servoSpeedState) {
          case 0:
            servoMotor.writeMicroseconds(1500); // Detener el servo
            Serial.println("Servo apagado");
            break;
          case 1:
            servoMotor.writeMicroseconds(1300); // Gira lentamente
            Serial.println("Servo girando lentamente");
            break;
          case 2:
            servoMotor.writeMicroseconds(1100); // Gira más rápido
            Serial.println("Servo girando rápido");
            break;
        }
      }
    }
  }

  lastButtonState = reading;
}
