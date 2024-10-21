// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// THIS FILE WAS AUTO-GENERATED BY ./wpilibc/generate_hids.py. DO NOT MODIFY

#pragma once

#include "frc/GenericHID.h"

namespace frc {

/**
 * Handle input from PS5 controllers connected to the Driver Station.
 *
 * This class handles PS5 input that comes from the Driver Station. Each
 * time a value is requested the most recent value is returned. There is a
 * single class instance for each controller and the mapping of ports to
 * hardware buttons depends on the code in the Driver Station.
 *
 * Only first party controllers from Sony are guaranteed to have the
 * correct mapping, and only through the official NI DS. Sim is not guaranteed
 * to have the same mapping, as well as any 3rd party controllers.
 */
class PS5Controller : public GenericHID {
 public:
  /**
   * Construct an instance of a controller.
   *
   * The controller index is the USB port on the Driver Station.
   *
   * @param port The port on the Driver Station that the controller is plugged
   *             into (0-5).
   */
  explicit PS5Controller(int port);

  ~PS5Controller() override = default;

  PS5Controller(PS5Controller&&) = default;
  PS5Controller& operator=(PS5Controller&&) = default;

  /**
   * Get the X axis value of left side of the controller.
   *
   * @return the axis value.
   */
  double GetLeftX() const;

  /**
   * Get the Y axis value of left side of the controller.
   *
   * @return the axis value.
   */
  double GetLeftY() const;

  /**
   * Get the X axis value of right side of the controller.
   *
   * @return the axis value.
   */
  double GetRightX() const;

  /**
   * Get the Y axis value of right side of the controller.
   *
   * @return the axis value.
   */
  double GetRightY() const;

  /**
   * Get the left trigger 2 axis value of the controller. Note that this axis
   * is bound to the range of [0, 1] as opposed to the usual [-1, 1].
   *
   * @return the axis value.
   */
  double GetL2Axis() const;

  /**
   * Get the right trigger 2 axis value of the controller. Note that this axis
   * is bound to the range of [0, 1] as opposed to the usual [-1, 1].
   *
   * @return the axis value.
   */
  double GetR2Axis() const;

  /**
   * Read the value of the square button on the controller.
   *
   * @return The state of the button.
   */
  bool GetSquareButton() const;

  /**
   * Whether the square button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetSquareButtonPressed();

  /**
   * Whether the square button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetSquareButtonReleased();

  /**
   * Constructs an event instance around the square button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the square button's
   * digital signal attached to the given loop.
   */
  BooleanEvent Square(EventLoop* loop) const;

  /**
   * Read the value of the cross button on the controller.
   *
   * @return The state of the button.
   */
  bool GetCrossButton() const;

  /**
   * Whether the cross button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetCrossButtonPressed();

  /**
   * Whether the cross button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetCrossButtonReleased();

  /**
   * Constructs an event instance around the cross button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the cross button's
   * digital signal attached to the given loop.
   */
  BooleanEvent Cross(EventLoop* loop) const;

  /**
   * Read the value of the circle button on the controller.
   *
   * @return The state of the button.
   */
  bool GetCircleButton() const;

  /**
   * Whether the circle button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetCircleButtonPressed();

  /**
   * Whether the circle button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetCircleButtonReleased();

  /**
   * Constructs an event instance around the circle button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the circle button's
   * digital signal attached to the given loop.
   */
  BooleanEvent Circle(EventLoop* loop) const;

  /**
   * Read the value of the triangle button on the controller.
   *
   * @return The state of the button.
   */
  bool GetTriangleButton() const;

  /**
   * Whether the triangle button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetTriangleButtonPressed();

  /**
   * Whether the triangle button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetTriangleButtonReleased();

  /**
   * Constructs an event instance around the triangle button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the triangle button's
   * digital signal attached to the given loop.
   */
  BooleanEvent Triangle(EventLoop* loop) const;

  /**
   * Read the value of the left trigger 1 button on the controller.
   *
   * @return The state of the button.
   */
  bool GetL1Button() const;

  /**
   * Whether the left trigger 1 button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetL1ButtonPressed();

  /**
   * Whether the left trigger 1 button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetL1ButtonReleased();

  /**
   * Constructs an event instance around the left trigger 1 button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the left trigger 1 button's
   * digital signal attached to the given loop.
   */
  BooleanEvent L1(EventLoop* loop) const;

  /**
   * Read the value of the right trigger 1 button on the controller.
   *
   * @return The state of the button.
   */
  bool GetR1Button() const;

  /**
   * Whether the right trigger 1 button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetR1ButtonPressed();

  /**
   * Whether the right trigger 1 button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetR1ButtonReleased();

  /**
   * Constructs an event instance around the right trigger 1 button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the right trigger 1 button's
   * digital signal attached to the given loop.
   */
  BooleanEvent R1(EventLoop* loop) const;

  /**
   * Read the value of the left trigger 2 button on the controller.
   *
   * @return The state of the button.
   */
  bool GetL2Button() const;

  /**
   * Whether the left trigger 2 button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetL2ButtonPressed();

  /**
   * Whether the left trigger 2 button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetL2ButtonReleased();

  /**
   * Constructs an event instance around the left trigger 2 button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the left trigger 2 button's
   * digital signal attached to the given loop.
   */
  BooleanEvent L2(EventLoop* loop) const;

  /**
   * Read the value of the right trigger 2 button on the controller.
   *
   * @return The state of the button.
   */
  bool GetR2Button() const;

  /**
   * Whether the right trigger 2 button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetR2ButtonPressed();

  /**
   * Whether the right trigger 2 button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetR2ButtonReleased();

  /**
   * Constructs an event instance around the right trigger 2 button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the right trigger 2 button's
   * digital signal attached to the given loop.
   */
  BooleanEvent R2(EventLoop* loop) const;

  /**
   * Read the value of the create button on the controller.
   *
   * @return The state of the button.
   */
  bool GetCreateButton() const;

  /**
   * Whether the create button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetCreateButtonPressed();

  /**
   * Whether the create button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetCreateButtonReleased();

  /**
   * Constructs an event instance around the create button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the create button's
   * digital signal attached to the given loop.
   */
  BooleanEvent Create(EventLoop* loop) const;

  /**
   * Read the value of the options button on the controller.
   *
   * @return The state of the button.
   */
  bool GetOptionsButton() const;

  /**
   * Whether the options button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetOptionsButtonPressed();

  /**
   * Whether the options button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetOptionsButtonReleased();

  /**
   * Constructs an event instance around the options button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the options button's
   * digital signal attached to the given loop.
   */
  BooleanEvent Options(EventLoop* loop) const;

  /**
   * Read the value of the L3 (left stick) button on the controller.
   *
   * @return The state of the button.
   */
  bool GetL3Button() const;

  /**
   * Whether the L3 (left stick) button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetL3ButtonPressed();

  /**
   * Whether the L3 (left stick) button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetL3ButtonReleased();

  /**
   * Constructs an event instance around the L3 (left stick) button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the L3 (left stick) button's
   * digital signal attached to the given loop.
   */
  BooleanEvent L3(EventLoop* loop) const;

  /**
   * Read the value of the R3 (right stick) button on the controller.
   *
   * @return The state of the button.
   */
  bool GetR3Button() const;

  /**
   * Whether the R3 (right stick) button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetR3ButtonPressed();

  /**
   * Whether the R3 (right stick) button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetR3ButtonReleased();

  /**
   * Constructs an event instance around the R3 (right stick) button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the R3 (right stick) button's
   * digital signal attached to the given loop.
   */
  BooleanEvent R3(EventLoop* loop) const;

  /**
   * Read the value of the PlayStation button on the controller.
   *
   * @return The state of the button.
   */
  bool GetPSButton() const;

  /**
   * Whether the PlayStation button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetPSButtonPressed();

  /**
   * Whether the PlayStation button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetPSButtonReleased();

  /**
   * Constructs an event instance around the PlayStation button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the PlayStation button's
   * digital signal attached to the given loop.
   */
  BooleanEvent PS(EventLoop* loop) const;

  /**
   * Read the value of the touchpad button on the controller.
   *
   * @return The state of the button.
   */
  bool GetTouchpadButton() const;

  /**
   * Whether the touchpad button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetTouchpadButtonPressed();

  /**
   * Whether the touchpad button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetTouchpadButtonReleased();

  /**
   * Constructs an event instance around the touchpad button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the touchpad button's
   * digital signal attached to the given loop.
   */
  BooleanEvent Touchpad(EventLoop* loop) const;

  /**
   * Read the value of the touchpad button on the controller.
   *
   * @return The state of the button.
   */
  [[deprecated("Use GetTouchpadButton instead")]]
  bool GetTouchpad() const;
  /**
   * Whether the touchpad was pressed since the last check.
   *
   * @return Whether the touchpad was pressed since the last check.
   */
  [[deprecated("Use GetTouchpadButtonPressed instead")]]
  bool GetTouchpadPressed();

  /**
   * Whether the touchpad was released since the last check.
   *
   * @return Whether the touchpad was released since the last check.
   */
  [[deprecated("Use GetTouchpadButtonReleased instead")]]
  bool GetTouchpadReleased();

  /** Represents a digital button on an PS5Controller. */
  struct Button {
    /// Square button.
    static constexpr int kSquare = 1;
    /// Cross button.
    static constexpr int kCross = 2;
    /// Circle button.
    static constexpr int kCircle = 3;
    /// Triangle button.
    static constexpr int kTriangle = 4;
    /// Left trigger 1 button.
    static constexpr int kL1 = 5;
    /// Right trigger 1 button.
    static constexpr int kR1 = 6;
    /// Left trigger 2 button.
    static constexpr int kL2 = 7;
    /// Right trigger 2 button.
    static constexpr int kR2 = 8;
    /// Create button.
    static constexpr int kCreate = 9;
    /// Options button.
    static constexpr int kOptions = 10;
    /// L3 (left stick) button.
    static constexpr int kL3 = 11;
    /// R3 (right stick) button.
    static constexpr int kR3 = 12;
    /// PlayStation button.
    static constexpr int kPS = 13;
    /// Touchpad button.
    static constexpr int kTouchpad = 14;
  };

  /** Represents an axis on an PS5Controller. */
  struct Axis {
    /// Left X axis.
    static constexpr int kLeftX = 0;
    /// Left Y axis.
    static constexpr int kLeftY = 1;
    /// Right X axis.
    static constexpr int kRightX = 2;
    /// Right Y axis.
    static constexpr int kRightY = 5;
    /// Left trigger 2.
    static constexpr int kL2 = 3;
    /// Right trigger 2.
    static constexpr int kR2 = 4;
  };
};

}  // namespace frc
