#include <SharpIR.h>
#include <Ewma.h>

Ewma adcFilter1(0.3);

SharpIR topSensor( SharpIR::GP2Y0A21YK0F, A0 );
int topSensorDistance = 0;

SharpIR bottomSensor( SharpIR::GP2Y0A21YK0F, A1);
int bottomSensorDistance = 0;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);  
  
  topSensorDistance = topSensor.getDistance();
  bottomSensorDistance = bottomSensor.getDistance();
  float topSensorDistance = adcFilter1.filter(topSensorDistance);
  float bottomSensorDistance = adcFilter1.filter(bottomSensorDistance);

  if (topSensorDistance > 55) {
    tone(3, 500);
  } else if (bottomSensorDistance > 55) {
    tone(3, 500);
  } else {
    noTone(3);
  }

}
