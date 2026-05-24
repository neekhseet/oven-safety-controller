#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
  double targetTemp{0};

public:
  Controller() = default;

  void setTargetTemperature(double temp) { targetTemp = temp; };
  double getTargetTemperature() { return targetTemp; }
};

#endif