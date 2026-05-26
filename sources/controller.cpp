#include "../includes/controller.h"

Controller::Controller(const Sensor &s) : sensor(s) {};

void Controller::update() {
  double currTemp = sensor.readTemperature();
  if (currTemp >= maxAllowedTemp) {
    alarmOn = true;
    heaterOn = false;
    return;
  }

  if (!alarmOn)
    heaterOn = (currTemp < targetTemp);
}