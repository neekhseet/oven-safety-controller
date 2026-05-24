#include "../includes/controller.h"

Controller::Controller(const Sensor &s) : sensor(s) {};

void Controller::update() {
  double currTemp = sensor.readTemperature();
  heaterOn = (currTemp < targetTemp);
}