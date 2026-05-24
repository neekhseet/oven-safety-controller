#include "../includes/controller.h"

void Controller::update() {
  double currTemp = sensor.readTemperature();
  heaterOn = (currTemp < targetTemp);
}