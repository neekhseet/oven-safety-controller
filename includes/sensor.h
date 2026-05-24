#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
public:
  virtual ~Sensor() = default;
  virtual double readTemperature() const = 0;
};

#endif