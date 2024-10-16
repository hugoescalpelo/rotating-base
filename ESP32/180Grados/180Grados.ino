#include <Servo.h>

Servo miServo;               // Creamos un objeto Servo
const int servoPin = 3;      // Pin al que está conectado el servomotor

void setup() {
  miServo.attach(servoPin);  // Conectamos el servomotor al pin 9
}

void loop() {
  // Girar suavemente de 0 a 180 grados
  for (int angulo = 0; angulo <= 180; angulo++) {
    miServo.write(angulo);    // Establecemos el ángulo del servomotor
    delay(30);                // Esperamos para un movimiento suave (ajustar si se desea más lento/rápido)
  }

  // Girar suavemente de 180 a 0 grados
  for (int angulo = 180; angulo >= 0; angulo--) {
    miServo.write(angulo);    // Establecemos el ángulo del servomotor
    delay(30);                // Esperamos para un movimiento suave (ajustar si se desea más lento/rápido)
  }
} 