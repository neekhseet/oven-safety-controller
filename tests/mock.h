#ifndef MOCK_SENSOR_H
#define MOCK_SENSOR_H

#include "../includes/sensor.h"
#include <gmock/gmock.h>

class MockSensor : public Sensor {
public:
  MOCK_METHOD(double, readTemperature, (), (const, override));
};

#endif