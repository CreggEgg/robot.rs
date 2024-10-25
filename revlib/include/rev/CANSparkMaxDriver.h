/*
 * Copyright (c) 2018-2024 REV Robotics
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of REV Robotics nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <stdint.h>

#include <cstddef>
#include <vector>

#include "rev/REVLibErrors.h"
#include "rev/REVLibVersion.h"
#include "rev/sim/CANSparkMax.h"

extern "C" {

const uint16_t c_SparkMax_kAPIMajorVersion = REVLibMajorVersion;
const uint8_t c_SparkMax_kAPIMinorVersion = REVLibMinorVersion;
const uint8_t c_SparkMax_kAPIBuildVersion = REVLibBuildVersion;
const uint32_t c_SparkMax_kAPIVersion = REVLibVersion;
const uint32_t kMinFirmwareVersion = 0x18000000;  // v24.0.0

// Other useful constants about firmware
const uint32_t kMinAnalogFirmwareVersion = 0x1040000;
const uint32_t kMinAltEncFirmwareVersion = 0x1050000;
const uint32_t kMinAbsEncFirmwareVersion = 0x1060000;

typedef struct c_SparkMax_Obj* c_SparkMax_handle;

typedef struct {
    uint16_t Major;
    uint8_t Minor;
    uint8_t Build;
    uint32_t Version;
} c_SparkMax_APIVersion;

typedef enum {
    c_SparkMax_kForward = 0,
    c_SparkMax_kReverse = 1,
} c_SparkMax_LimitDirection;

typedef enum {
    c_SparkMax_kNormallyOpen = 0,
    c_SparkMax_kNormallyClosed = 1,
} c_SparkMax_LimitPolarity;

typedef enum {
    c_SparkMax_kNoSensor = 0,
    c_SparkMax_kHallSensor = 1,
    c_SparkMax_kQuadrature = 2,
    c_SparkMax_kSensorless = 3,
    c_SparkMax_kAlternateQuadrature = 4
} c_SparkMax_EncoderType;

typedef enum {
    c_SparkMax_kCoast = 0,
    c_SparkMax_kBrake = 1
} c_SparkMax_IdleMode;

typedef enum {
    c_SparkMax_SparkMax,
    c_SparkMax_SparkFlex,
    c_SparkMax_Unknown = 255
} c_SparkMax_SparkModel;

typedef enum { c_SparkMax_kPWM = 0, c_SparkMax_kCAN = 1 } c_SparkMax_InputMode;

typedef enum {
    c_SparkMax_Fault_kBrownout = 0,
    c_SparkMax_Fault_kOvercurrent = 1,
    c_SparkMax_Fault_kIWDTReset = 2,
    c_SparkMax_Fault_kMotorFault = 3,
    c_SparkMax_Fault_kSensorFault = 4,
    c_SparkMax_Fault_kStall = 5,
    c_SparkMax_Fault_kEEPROMCRC = 6,
    c_SparkMax_Fault_kCANTX = 7,
    c_SparkMax_Fault_kCANRX = 8,
    c_SparkMax_Fault_kHasReset = 9,
    c_SparkMax_Fault_kDRVFault = 10,
    c_SparkMax_Fault_kOtherFault = 11,
    c_SparkMax_Fault_kSoftLimitFwd = 12,
    c_SparkMax_Fault_kSoftLimitRev = 13,
    c_SparkMax_Fault_kHardLimitFwd = 14,
    c_SparkMax_Fault_kHardLimitRev = 15
} c_SparkMax_FaultID;

typedef enum {
    c_SparkMax_kBrushed = 0,
    c_SparkMax_kBrushless = 1
} c_SparkMax_MotorType;

typedef enum {
    c_SparkMax_kParamOK = 0,
    c_SparkMax_kInvalidID = 1,
    c_SparkMax_kMismatchType = 2,
    c_SparkMax_kAccessMode = 3,
    c_SparkMax_kInvalid = 4,
    c_SparkMax_kNotImplementedDeprecated = 5
} c_SparkMax_ParameterStatus;

typedef enum {
    c_SparkMax_kCanID = 0,
    c_SparkMax_kInputMode = 1,
    c_SparkMax_kMotorType = 2,
    c_SparkMax_kCommAdvance = 3,
    c_SparkMax_kSensorType = 4,
    c_SparkMax_kCtrlType = 5,
    c_SparkMax_kIdleMode = 6,
    c_SparkMax_kInputDeadband = 7,
    c_SparkMax_kFeedbackSensorPID0 = 8,
    c_SparkMax_kFeedbackSensorPID1 = 9,
    c_SparkMax_kPolePairs = 10,
    c_SparkMax_kCurrentChop = 11,
    c_SparkMax_kCurrentChopCycles = 12,
    c_SparkMax_kP_0 = 13,
    c_SparkMax_kI_0 = 14,
    c_SparkMax_kD_0 = 15,
    c_SparkMax_kF_0 = 16,
    c_SparkMax_kIZone_0 = 17,
    c_SparkMax_kDFilter_0 = 18,
    c_SparkMax_kOutputMin_0 = 19,
    c_SparkMax_kOutputMax_0 = 20,
    c_SparkMax_kP_1 = 21,
    c_SparkMax_kI_1 = 22,
    c_SparkMax_kD_1 = 23,
    c_SparkMax_kF_1 = 24,
    c_SparkMax_kIZone_1 = 25,
    c_SparkMax_kDFilter_1 = 26,
    c_SparkMax_kOutputMin_1 = 27,
    c_SparkMax_kOutputMax_1 = 28,
    c_SparkMax_kP_2 = 29,
    c_SparkMax_kI_2 = 30,
    c_SparkMax_kD_2 = 31,
    c_SparkMax_kF_2 = 32,
    c_SparkMax_kIZone_2 = 33,
    c_SparkMax_kDFilter_2 = 34,
    c_SparkMax_kOutputMin_2 = 35,
    c_SparkMax_kOutputMax_2 = 36,
    c_SparkMax_kP_3 = 37,
    c_SparkMax_kI_3 = 38,
    c_SparkMax_kD_3 = 39,
    c_SparkMax_kF_3 = 40,
    c_SparkMax_kIZone_3 = 41,
    c_SparkMax_kDFilter_3 = 42,
    c_SparkMax_kOutputMin_3 = 43,
    c_SparkMax_kOutputMax_3 = 44,
    c_SparkMax_kInverted = 45,
    c_SparkMax_kOutputRatio = 46,
    c_SparkMax_kSerialNumberLow = 47,
    c_SparkMax_kSerialNumberMid = 48,
    c_SparkMax_kSerialNumberHigh = 49,
    c_SparkMax_kLimitSwitchFwdPolarity = 50,
    c_SparkMax_kLimitSwitchRevPolarity = 51,
    c_SparkMax_kHardLimitFwdEn = 52,
    c_SparkMax_kHardLimitRevEn = 53,
    c_SparkMax_kSoftLimitFwdEn = 54,
    c_SparkMax_kSoftLimitRevEn = 55,
    c_SparkMax_kRampRate = 56,
    c_SparkMax_kFollowerID = 57,
    c_SparkMax_kFollowerConfig = 58,
    c_SparkMax_kSmartCurrentStallLimit = 59,
    c_SparkMax_kSmartCurrentFreeLimit = 60,
    c_SparkMax_kSmartCurrentConfig = 61,
    c_SparkMax_kSmartCurrentReserved = 62,
    c_SparkMax_kMotorKv = 63,
    c_SparkMax_kMotorR = 64,
    c_SparkMax_kMotorL = 65,
    c_SparkMax_kMotorRsvd1 = 66,
    c_SparkMax_kMotorRsvd2 = 67,
    c_SparkMax_kMotorRsvd3 = 68,
    c_SparkMax_kEncoderCountsPerRev = 69,
    c_SparkMax_kEncoderAverageDepth = 70,
    c_SparkMax_kEncoderSampleDelta = 71,
    c_SparkMax_kEncoderInverted = 72,
    c_SparkMax_kEncoderRsvd1 = 73,
    c_SparkMax_kVoltageCompMode = 74,
    c_SparkMax_kCompensatedNominalVoltage = 75,
    c_SparkMax_kSmartMotionMaxVelocity_0 = 76,
    c_SparkMax_kSmartMotionMaxAccel_0 = 77,
    c_SparkMax_kSmartMotionMinVelOutput_0 = 78,
    c_SparkMax_kSmartMotionAllowedClosedLoopError_0 = 79,
    c_SparkMax_kSmartMotionAccelStrategy_0 = 80,
    c_SparkMax_kSmartMotionMaxVelocity_1 = 81,
    c_SparkMax_kSmartMotionMaxAccel_1 = 82,
    c_SparkMax_kSmartMotionMinVelOutput_1 = 83,
    c_SparkMax_kSmartMotionAllowedClosedLoopError_1 = 84,
    c_SparkMax_kSmartMotionAccelStrategy_1 = 85,
    c_SparkMax_kSmartMotionMaxVelocity_2 = 86,
    c_SparkMax_kSmartMotionMaxAccel_2 = 87,
    c_SparkMax_kSmartMotionMinVelOutput_2 = 88,
    c_SparkMax_kSmartMotionAllowedClosedLoopError_2 = 89,
    c_SparkMax_kSmartMotionAccelStrategy_2 = 90,
    c_SparkMax_kSmartMotionMaxVelocity_3 = 91,
    c_SparkMax_kSmartMotionMaxAccel_3 = 92,
    c_SparkMax_kSmartMotionMinVelOutput_3 = 93,
    c_SparkMax_kSmartMotionAllowedClosedLoopError_3 = 94,
    c_SparkMax_kSmartMotionAccelStrategy_3 = 95,
    c_SparkMax_kIMaxAccum_0 = 96,
    c_SparkMax_kSlot3Placeholder1_0 = 97,
    c_SparkMax_kSlot3Placeholder2_0 = 98,
    c_SparkMax_kSlot3Placeholder3_0 = 99,
    c_SparkMax_kIMaxAccum_1 = 100,
    c_SparkMax_kSlot3Placeholder1_1 = 101,
    c_SparkMax_kSlot3Placeholder2_1 = 102,
    c_SparkMax_kSlot3Placeholder3_1 = 103,
    c_SparkMax_kIMaxAccum_2 = 104,
    c_SparkMax_kSlot3Placeholder1_2 = 105,
    c_SparkMax_kSlot3Placeholder2_2 = 106,
    c_SparkMax_kSlot3Placeholder3_2 = 107,
    c_SparkMax_kIMaxAccum_3 = 108,
    c_SparkMax_kSlot3Placeholder1_3 = 109,
    c_SparkMax_kSlot3Placeholder2_3 = 110,
    c_SparkMax_kSlot3Placeholder3_3 = 111,
    c_SparkMax_kPositionConversionFactor = 112,
    c_SparkMax_kVelocityConversionFactor = 113,
    c_SparkMax_kClosedLoopRampRate = 114,
    c_SparkMax_kSoftLimitFwd = 115,
    c_SparkMax_kSoftLimitRev = 116,
    c_SparkMax_kSoftLimitRsvd0 = 117,
    c_SparkMax_kSoftLimitRsvd1 = 118,
    c_SparkMax_kAnalogRevPerVolt = 119,
    c_SparkMax_kAnalogRotationsPerVoltSec = 120,
    c_SparkMax_kAnalogAverageDepth = 121,
    c_SparkMax_kAnalogSensorMode = 122,
    c_SparkMax_kAnalogInverted = 123,
    c_SparkMax_kAnalogSampleDelta = 124,
    c_SparkMax_kAnalogRsvd0 = 125,
    c_SparkMax_kAnalogRsvd1 = 126,
    c_SparkMax_kDataPortConfig = 127,
    c_SparkMax_kAltEncoderCountsPerRev = 128,
    c_SparkMax_kAltEncoderAverageDepth = 129,
    c_SparkMax_kAltEncoderSampleDelta = 130,
    c_SparkMax_kAltEncoderInverted = 131,
    c_SparkMax_kAltEncodePositionFactor = 132,
    c_SparkMax_kAltEncoderVelocityFactor = 133,
    c_SparkMax_kAltEncoderRsvd0 = 134,
    c_SparkMax_kAltEncoderRsvd1 = 135,
    c_SparkMax_kHallSensorSampleRate = 136,
    c_SparkMax_kHallSensorAverageDepth = 137,
    c_SparkMax_kNumParameters = 138,
    c_SparkMax_kDutyCyclePositionFactor = 139,
    c_SparkMax_kDutyCycleVelocityFactor = 140,
    c_SparkMax_kDutyCycleInverted = 141,
    c_SparkMax_kDutyCycleSensorMode = 142,
    c_SparkMax_kDutyCycleAverageDepth = 143,
    c_SparkMax_kDutyCycleSampleDelta = 144,
    c_SparkMax_kDutyCycleOffsetv1p6p2 = 145,
    c_SparkMax_kDutyCycleRsvd0 = 146,
    c_SparkMax_kDutyCycleRsvd1 = 147,
    c_SparkMax_kDutyCycleRsvd2 = 148,
    c_SparkMax_kPositionPIDWrapEnable = 149,
    c_SparkMax_kPositionPIDMinInput = 150,
    c_SparkMax_kPositionPIDMaxInput = 151,
    c_SparkMax_kDutyCycleZeroCentered = 152,
    c_SparkMax_kDutyCyclePrescaler = 153,
    c_SparkMax_kDutyCycleOffset = 154,
    c_SparkMax_kProductId = 155,
    c_SparkMax_kDeviceMajorVersion = 156,
    c_SparkMax_kDeviceMinorVersion = 157,
    c_SparkMax_NumParameters
} c_SparkMax_ConfigParameter;

typedef enum {
    c_SparkMax_kInt32 = 0,
    c_SparkMax_kUint32 = 1,
    c_SparkMax_kFloat32 = 2,
    c_SparkMax_kBool = 3
} c_SparkMax_ParameterType;

typedef enum {
    c_SparkMax_kStatus0 = 0,
    c_SparkMax_kStatus1 = 1,
    c_SparkMax_kStatus2 = 2,
    c_SparkMax_kStatus3 = 3,
    c_SparkMax_kStatus4 = 4,
    c_SparkMax_kStatus5 = 5,
    c_SparkMax_kStatus6 = 6,
    c_SparkMax_kStatus7 = 7,
} c_SparkMax_PeriodicFrame;

typedef enum {
    c_SparkMax_kDutyCycle = 0,
    c_SparkMax_kVelocity = 1,
    c_SparkMax_kVoltage = 2,
    c_SparkMax_kPosition = 3,
    c_SparkMax_kSmartMotion = 4,
    c_SparkMax_kCurrent = 5,
    c_SparkMax_kSmartVelocity = 6
} c_SparkMax_ControlType;

typedef enum {
    c_SparkMax_kDataPortConfigNone = -1,
    c_SparkMax_kDataPortConfigLimitSwitchesAndAbsoluteEncoder = 0,
    c_SparkMax_kDataPortConfigAltEncoder = 1,
} c_SparkMax_DataPortConfig;

typedef struct {
    float appliedOutput;
    uint16_t faults;
    uint16_t stickyFaults;
    c_SparkMax_MotorType motorType;
    uint8_t isFollower;
    uint8_t isInverted;
    uint8_t lock;
    uint8_t roboRIO;
    uint64_t timestamp;
} c_SparkMax_PeriodicStatus0;

typedef struct {
    float sensorVelocity;
    uint8_t motorTemperature;
    float busVoltage;
    float outputCurrent;
    uint64_t timestamp;
} c_SparkMax_PeriodicStatus1;

typedef struct {
    float sensorPosition;
    uint64_t timestamp;
} c_SparkMax_PeriodicStatus2;

typedef struct {
    float analogVoltage;
    float analogVelocity;
    float analogPosition;
    uint64_t timestamp;
} c_SparkMax_PeriodicStatus3;

typedef struct {
    float altEncoderPosition;
    float altEncoderVelocity;
    uint64_t timestamp;
} c_SparkMax_PeriodicStatus4;

typedef struct {
    float dutyCyclePosition;
    uint8_t dutyCycleAbsoluteValue;
    uint8_t dutyCycleStatus;
    uint64_t timestamp;
} c_SparkMax_PeriodicStatus5;

typedef struct {
    float dutyCycleVelocity;
    uint8_t dutyCycleFrequency;
    uint64_t timestamp;
} c_SparkMax_PeriodicStatus6;

typedef struct {
    float iAccum;
    uint64_t timestamp;
} c_SparkMax_PeriodicStatus7;

typedef struct {
    uint8_t major;
    uint8_t minor;
    uint16_t build;
    uint8_t isDebug;
    uint32_t versionRaw;
} c_SparkMax_FirmwareVersion;

typedef enum {
    c_SparkMax_kStrategyTrapezoidal = 0,
    c_SparkMax_kStrategySCurve = 1
} c_SparkMax_AccelStrategy;

typedef enum {
    c_SparkMax_kAbsolute = 0,
    c_SparkMax_kRelative = 1
} c_SparkMax_AnalogMode;

typedef enum {
    c_SparkMax_kDutyCycleAbsolute = 0,
    c_SparkMax_kDutyCycleRelative = 1
} c_SparkMax_DutyCycleMode;

typedef struct {
    uint16_t DRVStat0;
    uint16_t DRVStat1;
    uint16_t faults;
    uint16_t stickyFaults;
} c_SparkMax_DRVStatus;

// CANSparkMaxLowLevel
c_REVLib_ErrorCode c_SparkMax_RegisterId(int deviceId);
c_SparkMax_handle c_SparkMax_Create(int deviceId, c_SparkMax_MotorType type,
                                    c_SparkMax_SparkModel unconfirmedModel,
                                    c_REVLib_ErrorCode* status);
c_SparkMax_handle c_SparkMax_Create_Inplace(
    int deviceId, c_SparkMax_SparkModel unconfirmedModel,
    c_REVLib_ErrorCode* status);
void c_SparkMax_Destroy(c_SparkMax_handle handle);
bool c_SparkMax_CheckId(int deviceId);
c_REVLib_ErrorCode c_SparkMax_GetFirmwareVersion(
    c_SparkMax_handle handle, c_SparkMax_FirmwareVersion* fwVersion);
c_REVLib_ErrorCode c_SparkMax_GetSerialNumber(c_SparkMax_handle handle,
                                              uint32_t* serialNumber[3]);
c_REVLib_ErrorCode c_SparkMax_GetDeviceId(c_SparkMax_handle handle,
                                          int* deviceId);
c_REVLib_ErrorCode c_SparkMax_SetMotorType(c_SparkMax_handle handle,
                                           c_SparkMax_MotorType type);
c_REVLib_ErrorCode c_SparkMax_GetMotorType(c_SparkMax_handle handle,
                                           c_SparkMax_MotorType* type);
c_REVLib_ErrorCode c_SparkMax_SetPeriodicFramePeriod(
    c_SparkMax_handle handle, c_SparkMax_PeriodicFrame frameId, int periodMs);
void c_SparkMax_SetPeriodicFrameTimeout(c_SparkMax_handle handle,
                                        int timeoutMs);
void c_SparkMax_SetCANMaxRetries(c_SparkMax_handle handle, int numRetries);

void c_SparkMax_SetControlFramePeriod(c_SparkMax_handle handle, int periodMs);
int c_SparkMax_GetControlFramePeriod(c_SparkMax_handle handle);

c_REVLib_ErrorCode c_SparkMax_SetParameterFloat32(
    c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, float value);
c_REVLib_ErrorCode c_SparkMax_SetParameterInt32(
    c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId,
    int32_t value);
c_REVLib_ErrorCode c_SparkMax_SetParameterUint32(
    c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId,
    uint32_t value);
c_REVLib_ErrorCode c_SparkMax_SetParameterBool(
    c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId,
    uint8_t value);
c_REVLib_ErrorCode c_SparkMax_GetParameterFloat32(
    c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId, float* value);
c_REVLib_ErrorCode c_SparkMax_GetParameterInt32(
    c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId,
    int32_t* value);
c_REVLib_ErrorCode c_SparkMax_GetParameterUint32(
    c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId,
    uint32_t* value);
c_REVLib_ErrorCode c_SparkMax_GetParameterBool(
    c_SparkMax_handle handle, c_SparkMax_ConfigParameter paramId,
    uint8_t* value);
// c_SparkMax_ParameterType
// c_SparkMax_GetParameterType(c_SparkMax_ConfigParameter paramId);
c_REVLib_ErrorCode c_SparkMax_GetPeriodicStatus0(
    c_SparkMax_handle handle, c_SparkMax_PeriodicStatus0* rawframe);
c_REVLib_ErrorCode c_SparkMax_GetPeriodicStatus1(
    c_SparkMax_handle handle, c_SparkMax_PeriodicStatus1* rawframe);
c_REVLib_ErrorCode c_SparkMax_GetPeriodicStatus2(
    c_SparkMax_handle handle, c_SparkMax_PeriodicStatus2* rawframe);
c_REVLib_ErrorCode c_SparkMax_GetPeriodicStatus3(
    c_SparkMax_handle handle, c_SparkMax_PeriodicStatus3* rawframe);
c_REVLib_ErrorCode c_SparkMax_GetPeriodicStatus4(
    c_SparkMax_handle handle, c_SparkMax_PeriodicStatus4* rawframe);
c_REVLib_ErrorCode c_SparkMax_GetPeriodicStatus5(
    c_SparkMax_handle handle, c_SparkMax_PeriodicStatus5* rawframe);
c_REVLib_ErrorCode c_SparkMax_GetPeriodicStatus6(
    c_SparkMax_handle handle, c_SparkMax_PeriodicStatus6* rawframe);

c_REVLib_ErrorCode c_SparkMax_SetEncoderPosition(c_SparkMax_handle handle,
                                                 float position);
c_REVLib_ErrorCode c_SparkMax_SetAltEncoderPosition(c_SparkMax_handle handle,
                                                    float position);
c_REVLib_ErrorCode c_SparkMax_RestoreFactoryDefaults(c_SparkMax_handle handle,
                                                     uint8_t persist);
c_REVLib_ErrorCode c_SparkMax_FactoryWipe(c_SparkMax_handle handle,
                                          uint8_t persist);

c_REVLib_ErrorCode c_SparkMax_SetFollow(c_SparkMax_handle handle,
                                        uint32_t followerArbId,
                                        uint32_t followerCfg);
// c_SparkMax_ErrorCode c_SparkMax_FollowerInvert(c_SparkMax_handle handle,
// uint8_t invert);
float c_SparkMax_SafeFloat(float f);

c_REVLib_ErrorCode c_SparkMax_SetpointCommand(c_SparkMax_handle handle,
                                              float value,
                                              c_SparkMax_ControlType ctrl,
                                              int pidSlot, float arbFeedforward,
                                              int arbFFUnits);
c_REVLib_ErrorCode c_SparkMax_GetDRVStatus(c_SparkMax_handle handle,
                                           c_SparkMax_DRVStatus* drvStatus);

// CANSparkMax
c_REVLib_ErrorCode c_SparkMax_SetInverted(c_SparkMax_handle handle,
                                          uint8_t inverted);
c_REVLib_ErrorCode c_SparkMax_GetInverted(c_SparkMax_handle handle,
                                          uint8_t* inverted);
c_REVLib_ErrorCode c_SparkMax_SetSmartCurrentLimit(c_SparkMax_handle handle,
                                                   uint8_t stallLimit,
                                                   uint8_t freeLimit,
                                                   uint32_t limitRPM);
c_REVLib_ErrorCode c_SparkMax_GetSmartCurrentLimit(c_SparkMax_handle handle,
                                                   uint8_t* stallLimit,
                                                   uint8_t* freeLimit,
                                                   uint32_t* limitRPM);
c_REVLib_ErrorCode c_SparkMax_SetSecondaryCurrentLimit(c_SparkMax_handle handle,
                                                       float limit,
                                                       int chopCycles);
c_REVLib_ErrorCode c_SparkMax_GetSecondaryCurrentLimit(c_SparkMax_handle handle,
                                                       float* limit,
                                                       int* chopCycles);
c_REVLib_ErrorCode c_SparkMax_SetIdleMode(c_SparkMax_handle handle,
                                          c_SparkMax_IdleMode idlemode);
c_REVLib_ErrorCode c_SparkMax_GetIdleMode(c_SparkMax_handle handle,
                                          c_SparkMax_IdleMode* idlemode);
c_REVLib_ErrorCode c_SparkMax_GetSparkModel(c_SparkMax_handle handle,
                                            c_SparkMax_SparkModel* model);
c_REVLib_ErrorCode c_SparkMax_EnableVoltageCompensation(
    c_SparkMax_handle handle, float nominalVoltage);
c_REVLib_ErrorCode c_SparkMax_GetVoltageCompensationNominalVoltage(
    c_SparkMax_handle handle, float* nominalVoltage);
c_REVLib_ErrorCode c_SparkMax_DisableVoltageCompensation(
    c_SparkMax_handle handle);
c_REVLib_ErrorCode c_SparkMax_SetOpenLoopRampRate(c_SparkMax_handle handle,
                                                  float rate);
c_REVLib_ErrorCode c_SparkMax_GetOpenLoopRampRate(c_SparkMax_handle handle,
                                                  float* rate);
c_REVLib_ErrorCode c_SparkMax_SetClosedLoopRampRate(c_SparkMax_handle handle,
                                                    float rate);
c_REVLib_ErrorCode c_SparkMax_GetClosedLoopRampRate(c_SparkMax_handle handle,
                                                    float* rate);
c_REVLib_ErrorCode c_SparkMax_IsFollower(c_SparkMax_handle handle,
                                         uint8_t* isFollower);
c_REVLib_ErrorCode c_SparkMax_GetFaults(c_SparkMax_handle handle,
                                        uint16_t* faults);
c_REVLib_ErrorCode c_SparkMax_GetStickyFaults(c_SparkMax_handle handle,
                                              uint16_t* stickyFaults);
c_REVLib_ErrorCode c_SparkMax_GetFault(c_SparkMax_handle handle,
                                       c_SparkMax_FaultID faultId,
                                       uint8_t* fault);
c_REVLib_ErrorCode c_SparkMax_GetStickyFault(c_SparkMax_handle handle,
                                             c_SparkMax_FaultID faultId,
                                             uint8_t* stickyfault);
c_REVLib_ErrorCode c_SparkMax_GetBusVoltage(c_SparkMax_handle handle,
                                            float* busVoltage);
c_REVLib_ErrorCode c_SparkMax_GetAppliedOutput(c_SparkMax_handle handle,
                                               float* appliedOutput);
void c_SparkMax_SetSimAppliedOutput(c_SparkMax_handle handle,
                                    float appliedOutput);
c_REVLib_ErrorCode c_SparkMax_GetOutputCurrent(c_SparkMax_handle handle,
                                               float* outputCurrent);
c_REVLib_ErrorCode c_SparkMax_GetMotorTemperature(c_SparkMax_handle handle,
                                                  float* motorTemperature);
c_REVLib_ErrorCode c_SparkMax_ClearFaults(c_SparkMax_handle handle);
c_REVLib_ErrorCode c_SparkMax_BurnFlash(c_SparkMax_handle handle);
c_REVLib_ErrorCode c_SparkMax_SetCANTimeout(c_SparkMax_handle handle,
                                            int timeoutMs);
c_REVLib_ErrorCode c_SparkMax_EnableSoftLimit(c_SparkMax_handle handle,
                                              c_SparkMax_LimitDirection dir,
                                              uint8_t enable);
c_REVLib_ErrorCode c_SparkMax_IsSoftLimitEnabled(c_SparkMax_handle handle,
                                                 c_SparkMax_LimitDirection dir,
                                                 uint8_t* enabled);
c_REVLib_ErrorCode c_SparkMax_SetSoftLimit(c_SparkMax_handle handle,
                                           c_SparkMax_LimitDirection dir,
                                           float limit);
c_REVLib_ErrorCode c_SparkMax_GetSoftLimit(c_SparkMax_handle handle,
                                           c_SparkMax_LimitDirection dir,
                                           float* limit);
c_REVLib_ErrorCode c_SparkMax_SetSensorType(c_SparkMax_handle handle,
                                            c_SparkMax_EncoderType sensorType);
c_REVLib_ErrorCode c_SparkMax_GetMotorInterface(c_SparkMax_handle handle,
                                                uint8_t* motorInterface);
c_REVLib_ErrorCode c_SparkMax_IDQuery(uint32_t* uniqueIdArray,
                                      size_t uniqueIdArraySize,
                                      size_t* numberOfDevices);
c_REVLib_ErrorCode c_SparkMax_IDAssign(uint32_t uniqueId, uint8_t deviceId);
c_REVLib_ErrorCode c_SparkMax_Identify(c_SparkMax_handle handle);
c_REVLib_ErrorCode c_SparkMax_IdentifyUniqueId(uint32_t uniqueId);

// Digital Input
c_REVLib_ErrorCode c_SparkMax_SetLimitPolarity(
    c_SparkMax_handle handle, c_SparkMax_LimitDirection sw,
    c_SparkMax_LimitPolarity polarity);
c_REVLib_ErrorCode c_SparkMax_GetLimitPolarity(
    c_SparkMax_handle handle, c_SparkMax_LimitDirection sw,
    c_SparkMax_LimitPolarity* polarity);
c_REVLib_ErrorCode c_SparkMax_GetLimitSwitch(c_SparkMax_handle handle,
                                             c_SparkMax_LimitDirection sw,
                                             uint8_t* limit);
c_REVLib_ErrorCode c_SparkMax_EnableLimitSwitch(c_SparkMax_handle handle,
                                                c_SparkMax_LimitDirection sw,
                                                uint8_t enable);
c_REVLib_ErrorCode c_SparkMax_IsLimitEnabled(c_SparkMax_handle handle,
                                             c_SparkMax_LimitDirection sw,
                                             uint8_t* enabled);

// CANAnalog
c_REVLib_ErrorCode c_SparkMax_GetAnalogPosition(c_SparkMax_handle handle,
                                                float* position);
c_REVLib_ErrorCode c_SparkMax_GetAnalogVelocity(c_SparkMax_handle handle,
                                                float* velocity);
c_REVLib_ErrorCode c_SparkMax_GetAnalogVoltage(c_SparkMax_handle,
                                               float* voltage);
void c_SparkMax_SetSimAnalogPosition(c_SparkMax_handle handle, float position);
void c_SparkMax_SetSimAnalogVelocity(c_SparkMax_handle handle, float velocity);
void c_SparkMax_SetSimAnalogVoltage(c_SparkMax_handle, float voltage);
c_REVLib_ErrorCode c_SparkMax_SetAnalogPositionConversionFactor(
    c_SparkMax_handle, float conversion);
c_REVLib_ErrorCode c_SparkMax_SetAnalogVelocityConversionFactor(
    c_SparkMax_handle, float conversion);
c_REVLib_ErrorCode c_SparkMax_GetAnalogPositionConversionFactor(
    c_SparkMax_handle, float* conversion);
c_REVLib_ErrorCode c_SparkMax_GetAnalogVelocityConversionFactor(
    c_SparkMax_handle, float* conversion);
c_REVLib_ErrorCode c_SparkMax_SetAnalogInverted(c_SparkMax_handle,
                                                uint8_t inverted);
c_REVLib_ErrorCode c_SparkMax_GetAnalogInverted(c_SparkMax_handle,
                                                uint8_t* inverted);
c_REVLib_ErrorCode c_SparkMax_SetAnalogAverageDepth(c_SparkMax_handle handle,
                                                    uint32_t depth);
c_REVLib_ErrorCode c_SparkMax_GetAnalogAverageDepth(c_SparkMax_handle handle,
                                                    uint32_t* depth);
c_REVLib_ErrorCode c_SparkMax_SetAnalogMeasurementPeriod(
    c_SparkMax_handle handle, uint32_t samples);
c_REVLib_ErrorCode c_SparkMax_GetAnalogMeasurementPeriod(
    c_SparkMax_handle handle, uint32_t* samples);
c_REVLib_ErrorCode c_SparkMax_SetAnalogMode(c_SparkMax_handle handle,
                                            c_SparkMax_AnalogMode mode);
c_REVLib_ErrorCode c_SparkMax_GetAnalogMode(c_SparkMax_handle handle,
                                            c_SparkMax_AnalogMode* mode);

// CANEncoder
c_REVLib_ErrorCode c_SparkMax_GetEncoderPosition(c_SparkMax_handle handle,
                                                 float* position);
c_REVLib_ErrorCode c_SparkMax_GetEncoderVelocity(c_SparkMax_handle handle,
                                                 float* velocity);
c_REVLib_ErrorCode c_SparkMax_SetPositionConversionFactor(
    c_SparkMax_handle handle, float conversion);
c_REVLib_ErrorCode c_SparkMax_SetVelocityConversionFactor(
    c_SparkMax_handle handle, float conversion);
c_REVLib_ErrorCode c_SparkMax_GetPositionConversionFactor(
    c_SparkMax_handle handle, float* conversion);
c_REVLib_ErrorCode c_SparkMax_GetVelocityConversionFactor(
    c_SparkMax_handle handle, float* conversion);
c_REVLib_ErrorCode c_SparkMax_SetAverageDepth(c_SparkMax_handle handle,
                                              uint32_t depth);
c_REVLib_ErrorCode c_SparkMax_GetAverageDepth(c_SparkMax_handle handle,
                                              uint32_t* depth);
c_REVLib_ErrorCode c_SparkMax_SetMeasurementPeriod(c_SparkMax_handle handle,
                                                   uint32_t samples);
c_REVLib_ErrorCode c_SparkMax_GetMeasurementPeriod(c_SparkMax_handle handle,
                                                   uint32_t* samples);
c_REVLib_ErrorCode c_SparkMax_SetCountsPerRevolution(c_SparkMax_handle handle,
                                                     uint32_t cpr);
c_REVLib_ErrorCode c_SparkMax_GetCountsPerRevolution(c_SparkMax_handle handle,
                                                     uint32_t* cpr);
c_REVLib_ErrorCode c_SparkMax_SetEncoderInverted(c_SparkMax_handle handle,
                                                 uint8_t inverted);
c_REVLib_ErrorCode c_SparkMax_GetEncoderInverted(c_SparkMax_handle handle,
                                                 uint8_t* inverted);

// Alt Encoder
c_REVLib_ErrorCode c_SparkMax_GetAltEncoderPosition(c_SparkMax_handle handle,
                                                    float* position);
c_REVLib_ErrorCode c_SparkMax_GetAltEncoderVelocity(c_SparkMax_handle handle,
                                                    float* velocity);
void c_SparkMax_SetSimAltEncoderVelocity(c_SparkMax_handle handle,
                                         float velocity);
c_REVLib_ErrorCode c_SparkMax_SetAltEncoderPositionFactor(
    c_SparkMax_handle handle, float conversion);
c_REVLib_ErrorCode c_SparkMax_SetAltEncoderVelocityFactor(
    c_SparkMax_handle handle, float conversion);
c_REVLib_ErrorCode c_SparkMax_GetAltEncoderPositionFactor(
    c_SparkMax_handle handle, float* conversion);
c_REVLib_ErrorCode c_SparkMax_GetAltEncoderVelocityFactor(
    c_SparkMax_handle handle, float* conversion);
c_REVLib_ErrorCode c_SparkMax_SetAltEncoderAverageDepth(
    c_SparkMax_handle handle, uint32_t depth);
c_REVLib_ErrorCode c_SparkMax_GetAltEncoderAverageDepth(
    c_SparkMax_handle handle, uint32_t* depth);
c_REVLib_ErrorCode c_SparkMax_SetAltEncoderMeasurementPeriod(
    c_SparkMax_handle handle, uint32_t samples);
c_REVLib_ErrorCode c_SparkMax_GetAltEncoderMeasurementPeriod(
    c_SparkMax_handle handle, uint32_t* samples);
c_REVLib_ErrorCode c_SparkMax_SetAltEncoderCountsPerRevolution(
    c_SparkMax_handle handle, uint32_t cpr);
c_REVLib_ErrorCode c_SparkMax_GetAltEncoderCountsPerRevolution(
    c_SparkMax_handle handle, uint32_t* cpr);
c_REVLib_ErrorCode c_SparkMax_SetAltEncoderInverted(c_SparkMax_handle handle,
                                                    uint8_t inverted);
c_REVLib_ErrorCode c_SparkMax_GetAltEncoderInverted(c_SparkMax_handle handle,
                                                    uint8_t* inverted);

// Duty Cycle
c_REVLib_ErrorCode c_SparkMax_GetDutyCyclePosition(c_SparkMax_handle handle,
                                                   float* position);
c_REVLib_ErrorCode c_SparkMax_GetDutyCycleVelocity(c_SparkMax_handle handle,
                                                   float* velocity);
c_REVLib_ErrorCode c_SparkMax_SetDutyCyclePositionFactor(
    c_SparkMax_handle handle, float conversion);
c_REVLib_ErrorCode c_SparkMax_GetDutyCyclePositionFactor(
    c_SparkMax_handle handle, float* conversion);
c_REVLib_ErrorCode c_SparkMax_SetDutyCycleVelocityFactor(
    c_SparkMax_handle handle, float conversion);
c_REVLib_ErrorCode c_SparkMax_GetDutyCycleVelocityFactor(
    c_SparkMax_handle handle, float* conversion);
c_REVLib_ErrorCode c_SparkMax_SetDutyCycleInverted(c_SparkMax_handle handle,
                                                   uint8_t inverted);
c_REVLib_ErrorCode c_SparkMax_GetDutyCycleInverted(c_SparkMax_handle handle,
                                                   uint8_t* inverted);
c_REVLib_ErrorCode c_SparkMax_SetDutyCycleMode(c_SparkMax_handle handle,
                                               c_SparkMax_DutyCycleMode mode);
c_REVLib_ErrorCode c_SparkMax_GetDutyCycleMode(c_SparkMax_handle handle,
                                               c_SparkMax_DutyCycleMode* mode);
c_REVLib_ErrorCode c_SparkMax_SetDutyCycleAverageDepth(c_SparkMax_handle handle,
                                                       uint32_t depth);
c_REVLib_ErrorCode c_SparkMax_GetDutyCycleAverageDepth(c_SparkMax_handle handle,
                                                       uint32_t* depth);
c_REVLib_ErrorCode c_SparkMax_SetDutyCycleSampleDelta(c_SparkMax_handle handle,
                                                      uint32_t delta);
c_REVLib_ErrorCode c_SparkMax_GetDutyCycleSampleDelta(c_SparkMax_handle handle,
                                                      uint32_t* delta);
c_REVLib_ErrorCode c_SparkMax_SetDutyCycleOffset(c_SparkMax_handle handle,
                                                 float offset);
c_REVLib_ErrorCode c_SparkMax_GetDutyCycleOffset(c_SparkMax_handle handle,
                                                 float* offset);

// Hall Sensor
c_REVLib_ErrorCode c_SparkMax_SetHallSensorSampleRate(c_SparkMax_handle handle,
                                                      float sampleRate);
c_REVLib_ErrorCode c_SparkMax_GetHallSensorSampleRate(c_SparkMax_handle handle,
                                                      float* sampleRate);
c_REVLib_ErrorCode c_SparkMax_SetHallSensorAverageDepth(
    c_SparkMax_handle handle, uint32_t depth);
c_REVLib_ErrorCode c_SparkMax_GetHallSensorAverageDepth(
    c_SparkMax_handle handle, uint32_t* depth);

// The high-level libraries should throw an exception if
// c_SparkMax_AttemptToSetDataPortConfig() returns
// c_REVLibError_SparkMaxDataPortAlreadyConfiguredDifferently
c_REVLib_ErrorCode c_SparkMax_AttemptToSetDataPortConfig(
    c_SparkMax_handle handle, c_SparkMax_DataPortConfig config);
c_REVLib_ErrorCode c_SparkMax_GetDataPortConfig(
    c_SparkMax_handle handle, c_SparkMax_DataPortConfig* config);

// CANPIDController
c_REVLib_ErrorCode c_SparkMax_SetP(c_SparkMax_handle handle, int slotID,
                                   float gain);
c_REVLib_ErrorCode c_SparkMax_SetI(c_SparkMax_handle handle, int slotID,
                                   float gain);
c_REVLib_ErrorCode c_SparkMax_SetD(c_SparkMax_handle handle, int slotID,
                                   float gain);
c_REVLib_ErrorCode c_SparkMax_SetDFilter(c_SparkMax_handle handle, int slotID,
                                         float gain);
c_REVLib_ErrorCode c_SparkMax_SetFF(c_SparkMax_handle handle, int slotID,
                                    float gain);
c_REVLib_ErrorCode c_SparkMax_SetIZone(c_SparkMax_handle handle, int slotID,
                                       float IZone);
c_REVLib_ErrorCode c_SparkMax_SetOutputRange(c_SparkMax_handle handle,
                                             int slotID, float min, float max);
c_REVLib_ErrorCode c_SparkMax_GetP(c_SparkMax_handle handle, int slotID,
                                   float* gain);
c_REVLib_ErrorCode c_SparkMax_GetI(c_SparkMax_handle handle, int slotID,
                                   float* gain);
c_REVLib_ErrorCode c_SparkMax_GetD(c_SparkMax_handle handle, int slotID,
                                   float* gain);
c_REVLib_ErrorCode c_SparkMax_GetDFilter(c_SparkMax_handle handle, int slotID,
                                         float* gain);
c_REVLib_ErrorCode c_SparkMax_GetFF(c_SparkMax_handle handle, int slotID,
                                    float* gain);
c_REVLib_ErrorCode c_SparkMax_GetIZone(c_SparkMax_handle handle, int slotID,
                                       float* IZone);
c_REVLib_ErrorCode c_SparkMax_GetOutputMin(c_SparkMax_handle handle, int slotID,
                                           float* min);
c_REVLib_ErrorCode c_SparkMax_GetOutputMax(c_SparkMax_handle handle, int slotID,
                                           float* max);

c_REVLib_ErrorCode c_SparkMax_SetSmartMotionMaxVelocity(
    c_SparkMax_handle handle, int slotID, float maxVel);
c_REVLib_ErrorCode c_SparkMax_SetSmartMotionMaxAccel(c_SparkMax_handle handle,
                                                     int slotID,
                                                     float maxAccel);
c_REVLib_ErrorCode c_SparkMax_SetSmartMotionMinOutputVelocity(
    c_SparkMax_handle handle, int slotID, float minVel);
c_REVLib_ErrorCode c_SparkMax_SetSmartMotionAccelStrategy(
    c_SparkMax_handle handle, int slotID,
    c_SparkMax_AccelStrategy accelStrategy);
c_REVLib_ErrorCode c_SparkMax_SetSmartMotionAllowedClosedLoopError(
    c_SparkMax_handle handle, int slotID, float allowedError);
c_REVLib_ErrorCode c_SparkMax_GetSmartMotionMaxVelocity(
    c_SparkMax_handle handle, int slotID, float* maxVel);
c_REVLib_ErrorCode c_SparkMax_GetSmartMotionMaxAccel(c_SparkMax_handle handle,
                                                     int slotID,
                                                     float* maxAccel);
c_REVLib_ErrorCode c_SparkMax_GetSmartMotionMinOutputVelocity(
    c_SparkMax_handle handle, int slotID, float* minVel);
c_REVLib_ErrorCode c_SparkMax_GetSmartMotionAccelStrategy(
    c_SparkMax_handle handle, int slotID,
    c_SparkMax_AccelStrategy* accelStrategy);
c_REVLib_ErrorCode c_SparkMax_GetSmartMotionAllowedClosedLoopError(
    c_SparkMax_handle handle, int slotID, float* allowedError);

c_REVLib_ErrorCode c_SparkMax_SetIMaxAccum(c_SparkMax_handle handle, int slotID,
                                           float iMaxAccum);
c_REVLib_ErrorCode c_SparkMax_GetIMaxAccum(c_SparkMax_handle handle, int slotID,
                                           float* iMaxAccum);
c_REVLib_ErrorCode c_SparkMax_SetIAccum(c_SparkMax_handle handle, float iAccum);
c_REVLib_ErrorCode c_SparkMax_GetIAccum(c_SparkMax_handle handle,
                                        float* iAccum);

c_REVLib_ErrorCode c_SparkMax_SetFeedbackDevice(c_SparkMax_handle handle,
                                                uint32_t sensorID);
c_REVLib_ErrorCode c_SparkMax_GetFeedbackDeviceID(c_SparkMax_handle handle,
                                                  uint32_t* id);
c_REVLib_ErrorCode c_SparkMax_SetFeedbackDeviceRange(c_SparkMax_handle handle,
                                                     float min, float max);

// Other helpers
c_SparkMax_APIVersion c_SparkMax_GetAPIVersion(void);
void c_SparkMax_SetLastError(c_SparkMax_handle handle,
                             c_REVLib_ErrorCode error);
c_REVLib_ErrorCode c_SparkMax_GetLastError(c_SparkMax_handle handle);
c_REVLib_ErrorCode c_SparkMax_GenerateError(int deviceID,
                                            c_REVLib_ErrorCode error);

c_REVLib_ErrorCode c_SparkMax_SetSimFreeSpeed(c_SparkMax_handle handle,
                                              float freeSpeed);
c_REVLib_ErrorCode c_SparkMax_SetSimStallTorque(c_SparkMax_handle handle,
                                                float stallTorque);

c_REVLib_ErrorCode c_SparkMax_SetPositionPIDWrapEnable(c_SparkMax_handle handle,
                                                       uint8_t enable);

c_REVLib_ErrorCode c_SparkMax_SetPositionPIDMinInput(c_SparkMax_handle handle,
                                                     float value);

c_REVLib_ErrorCode c_SparkMax_SetPositionPIDMaxInput(c_SparkMax_handle handle,
                                                     float value);

c_REVLib_ErrorCode c_SparkMax_GetPositionPIDWrapEnable(c_SparkMax_handle handle,
                                                       uint8_t* enabled);

c_REVLib_ErrorCode c_SparkMax_GetPositionPIDMinInput(c_SparkMax_handle handle,
                                                     float* value);

c_REVLib_ErrorCode c_SparkMax_GetPositionPIDMaxInput(c_SparkMax_handle handle,
                                                     float* value);

}  // extern "C"
