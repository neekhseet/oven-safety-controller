#include "../includes/controller.h"
#include "mock.h"
#include <gtest/gtest.h>
using ::testing::Return;

TEST(ControllerTests, CanBeCreated) { Controller controller; }

TEST(ControllerTests, SetAndGetTargetTemperature) {
  Controller controller;
  controller.setTargetTemperature(10);
  EXPECT_EQ(controller.getTargetTemperature(), 10);
}

TEST(ControllerTest, HeaterDisableIfTempMoreTarget) {
  MockSensor sensor;
  EXPECT_CALL(sensor, readTemperature()).WillOnce(Return(150.9));

  Controller controller(sensor);
  controller.setTargetTemperature(100.0);
  controller.update();
  EXPECT_FALSE(controller.isHeaterOn());
}