#include "../includes/controller.h"
#include <gtest/gtest.h>

TEST(ControllerTests, CanBeCreated) { Controller controller; }

TEST(ControllerTests, SetAndGetTargetTemperature) {
  Controller controller;
  controller.setTargetTemperature(10);
  EXPECT_EQ(controller.getTargetTemperature(), 10);
}

TEST(ControllerTest, HeaterDisableIfTempMoreTarget) {
  MockSensor sensor;
  EXPECT_CALL(sensor, readTemperature()).willOnce(Return(150.9));

  Controller controller(sensor);
  controller.setTargetTemperature(100.0);
  controller.update();
  EXPECT_FALSE(controller.isHeaterOn());
}