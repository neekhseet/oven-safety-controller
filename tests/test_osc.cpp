#include "../includes/controller.h"
#include "mock.h"
#include <gtest/gtest.h>
using ::testing::Return;

TEST(ControllerTests, CanBeCreated) {
  MockSensor sensor;
  Controller controller(sensor);
}

TEST(ControllerTests, SetAndGetTargetTemperature) {
  MockSensor sensor;
  Controller controller(sensor);
  controller.setTargetTemperature(10);
  EXPECT_EQ(controller.getTargetTemperature(), 10);
}

TEST(ControllerTests, HeaterDisableIfTempMoreTarget) {
  MockSensor sensor;
  EXPECT_CALL(sensor, readTemperature()).WillOnce(Return(150.9));

  Controller controller(sensor);
  controller.setTargetTemperature(100.0);
  controller.update();
  EXPECT_FALSE(controller.isHeaterOn());
}

TEST(ControllerTests, AlarmOnTargetTemp) {
  MockSensor sensor;
  EXPECT_CALL(sensor, readTemperature()).WillOnce(Return(150.9));

  Controller controller(sensor);
  controller.setTargetTemperature(100.0);
  controller.update();

  EXPECT_TRUE(controller.isAlarmOn());
}

TEST(ControllerTests, HeaterCantWorkWhileAlarmEnabled) {
  MockSensor sensor;
  EXPECT_CALL(sensor, readTemperature()).WillOnce(Return(150.9));

  Controller controller(sensor);
  controller.setTargetTemperature(100.0);
  controller.update();

  EXPECT_TRUE(controller.isAlarmOn());
  EXPECT_CALL(sensor, readTemperature()).WillOnce(Return(90.9));
  controller.update();
  EXPECT_FALSE(controller.isHeaterOn());
}

TEST(ControllerTests, HeaterTurnsOnAfterAlarmReset) {
  MockSensor sensor;
  EXPECT_CALL(sensor, readTemperature()).WillOnce(Return(150.9));

  Controller controller(sensor);
  controller.setTargetTemperature(100.0);
  controller.update();

  EXPECT_TRUE(controller.isAlarmOn());
  EXPECT_FALSE(controller.isHeaterOn());

  controller.resetAlarm();
  EXPECT_CALL(sensor, readTemperature()).WillOnce(Return(90.9));

  controller.update();

  EXPECT_FALSE(controller.isAlarmOn());
  EXPECT_TRUE(controller.isHeaterOn());
}

TEST(ControllerTest, HeaterOnAndOffInLiveWithouAlarm) {
  MockSensor sensor;

  EXPECT_CALL(sensor, readTemperature()).WillOnce(Return(80.0));
  Controller controller(sensor);
  controller.setTargetTemperature(100.0);
  controller.update();
  EXPECT_TRUE(controller.isHeaterOn());

  EXPECT_CALL(sensor, readTemperature()).WillOnce(Return(100.0));
  controller.update();
  EXPECT_FALSE(controller.isHeaterOn());

  EXPECT_CALL(sensor, readTemperature()).WillOnce(Return(90.0));
  controller.update();
  EXPECT_TRUE(controller.isHeaterOn());
}