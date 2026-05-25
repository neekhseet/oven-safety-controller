#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "sensor.h"
class Controller {
  double targetTemp{0};
  const Sensor &sensor;
  bool heaterOn = false;
  bool alarmOn = false;

public:
  Controller(const Sensor &s);

  void setTargetTemperature(double temp) { targetTemp = temp; };
  double getTargetTemperature() { return targetTemp; }

  void update();
  bool isHeaterOn() const { return heaterOn; };
  bool isAlarmOn() const { return alarmOn; }
};

#endif