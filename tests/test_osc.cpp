#include "../includes/controller.h"
#include <gtest/gtest.h>

TEST(ControllerTests, CanBeCreated) { Controller controller; }

TEST(ControllerTests, SetAndGetTargetTemperature) {
  Controller controller;
  controller.setTargetTemperature(10);
  EXPECT_EQ(controller.getTargetTemperature(), 10);
}