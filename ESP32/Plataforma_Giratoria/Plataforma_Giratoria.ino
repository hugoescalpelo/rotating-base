#include <ESP32Servo.h>

Servo miServo;               // Creamos un objeto Servo
const int servoPin = 18;      // Pin al que está conectado el servomotor

void setup() {
  miServo.attach(servoPin);  // Conectamos el servomotor al pin 9
}

void loop() {
  // Girar suavemente en un sentido de forma continua
  miServo.write(85);        // Establecemos el ángulo para el giro continuo
  delay(50);                 // Esperamos para un movimiento suave (ajustar si se desea más lento/rápido)
}
