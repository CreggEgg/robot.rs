// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// THIS FILE WAS AUTO-GENERATED BY ./wpilibc/generate_hids.py. DO NOT MODIFY

#pragma once

#include "frc/GenericHID.h"

namespace frc {

/**
 * Handle input from Xbox controllers connected to the Driver Station.
 *
 * This class handles Xbox input that comes from the Driver Station. Each
 * time a value is requested the most recent value is returned. There is a
 * single class instance for each controller and the mapping of ports to
 * hardware buttons depends on the code in the Driver Station.
 *
 * Only first party controllers from Microsoft are guaranteed to have the
 * correct mapping, and only through the official NI DS. Sim is not guaranteed
 * to have the same mapping, as well as any 3rd party controllers.
 */
class XboxController : public GenericHID {
 public:
  /**
   * Construct an instance of a controller.
   *
   * The controller index is the USB port on the Driver Station.
   *
   * @param port The port on the Driver Station that the controller is plugged
   *             into (0-5).
   */
  explicit XboxController(int port);

  ~XboxController() override = default;

  XboxController(XboxController&&) = default;
  XboxController& operator=(XboxController&&) = default;

  /**
   * Get the X axis value of left side of the controller.
   *
   * @return the axis value.
   */
  double GetLeftX() const;

  /**
   * Get the X axis value of right side of the controller.
   *
   * @return the axis value.
   */
  double GetRightX() const;

  /**
   * Get the Y axis value of left side of the controller.
   *
   * @return the axis value.
   */
  double GetLeftY() const;

  /**
   * Get the Y axis value of right side of the controller.
   *
   * @return the axis value.
   */
  double GetRightY() const;

  /**
   * Get the left trigger axis value of the controller. Note that this axis
   * is bound to the range of [0, 1] as opposed to the usual [-1, 1].
   *
   * @return the axis value.
   */
  double GetLeftTriggerAxis() const;

  /**
   * Constructs an event instance around the axis value of the left trigger.
   * The returned trigger will be true when the axis value is greater than
   * {@code threshold}.
   * @param threshold the minimum axis value for the returned event to be true.
   * This value should be in the range [0, 1] where 0 is the unpressed state of
   * the axis.
   * @param loop the event loop instance to attach the event to.
   * @return an event instance that is true when the left trigger's axis
   * exceeds the provided threshold, attached to the given event loop
   */
  BooleanEvent LeftTrigger(double threshold, EventLoop* loop) const;

  /**
   * Constructs an event instance around the axis value of the left trigger.
   * The returned trigger will be true when the axis value is greater than 0.5.
   * @param loop the event loop instance to attach the event to.
   * @return an event instance that is true when the left trigger's axis
   * exceeds 0.5, attached to the given event loop
   */
  BooleanEvent LeftTrigger(EventLoop* loop) const;

  /**
   * Get the right trigger axis value of the controller. Note that this axis
   * is bound to the range of [0, 1] as opposed to the usual [-1, 1].
   *
   * @return the axis value.
   */
  double GetRightTriggerAxis() const;

  /**
   * Constructs an event instance around the axis value of the right trigger.
   * The returned trigger will be true when the axis value is greater than
   * {@code threshold}.
   * @param threshold the minimum axis value for the returned event to be true.
   * This value should be in the range [0, 1] where 0 is the unpressed state of
   * the axis.
   * @param loop the event loop instance to attach the event to.
   * @return an event instance that is true when the right trigger's axis
   * exceeds the provided threshold, attached to the given event loop
   */
  BooleanEvent RightTrigger(double threshold, EventLoop* loop) const;

  /**
   * Constructs an event instance around the axis value of the right trigger.
   * The returned trigger will be true when the axis value is greater than 0.5.
   * @param loop the event loop instance to attach the event to.
   * @return an event instance that is true when the right trigger's axis
   * exceeds 0.5, attached to the given event loop
   */
  BooleanEvent RightTrigger(EventLoop* loop) const;

  /**
   * Read the value of the A button on the controller.
   *
   * @return The state of the button.
   */
  bool GetAButton() const;

  /**
   * Whether the A button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetAButtonPressed();

  /**
   * Whether the A button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetAButtonReleased();

  /**
   * Constructs an event instance around the A button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the A button's
   * digital signal attached to the given loop.
   */
  BooleanEvent A(EventLoop* loop) const;

  /**
   * Read the value of the B button on the controller.
   *
   * @return The state of the button.
   */
  bool GetBButton() const;

  /**
   * Whether the B button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetBButtonPressed();

  /**
   * Whether the B button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetBButtonReleased();

  /**
   * Constructs an event instance around the B button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the B button's
   * digital signal attached to the given loop.
   */
  BooleanEvent B(EventLoop* loop) const;

  /**
   * Read the value of the X button on the controller.
   *
   * @return The state of the button.
   */
  bool GetXButton() const;

  /**
   * Whether the X button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetXButtonPressed();

  /**
   * Whether the X button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetXButtonReleased();

  /**
   * Constructs an event instance around the X button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the X button's
   * digital signal attached to the given loop.
   */
  BooleanEvent X(EventLoop* loop) const;

  /**
   * Read the value of the Y button on the controller.
   *
   * @return The state of the button.
   */
  bool GetYButton() const;

  /**
   * Whether the Y button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetYButtonPressed();

  /**
   * Whether the Y button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetYButtonReleased();

  /**
   * Constructs an event instance around the Y button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the Y button's
   * digital signal attached to the given loop.
   */
  BooleanEvent Y(EventLoop* loop) const;

  /**
   * Read the value of the left bumper button on the controller.
   *
   * @return The state of the button.
   */
  bool GetLeftBumperButton() const;

  /**
   * Whether the left bumper button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetLeftBumperButtonPressed();

  /**
   * Whether the left bumper button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetLeftBumperButtonReleased();

  /**
   * Constructs an event instance around the left bumper button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the left bumper button's
   * digital signal attached to the given loop.
   */
  BooleanEvent LeftBumper(EventLoop* loop) const;

  /**
   * Read the value of the right bumper button on the controller.
   *
   * @return The state of the button.
   */
  bool GetRightBumperButton() const;

  /**
   * Whether the right bumper button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetRightBumperButtonPressed();

  /**
   * Whether the right bumper button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetRightBumperButtonReleased();

  /**
   * Constructs an event instance around the right bumper button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the right bumper button's
   * digital signal attached to the given loop.
   */
  BooleanEvent RightBumper(EventLoop* loop) const;

  /**
   * Read the value of the back button on the controller.
   *
   * @return The state of the button.
   */
  bool GetBackButton() const;

  /**
   * Whether the back button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetBackButtonPressed();

  /**
   * Whether the back button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetBackButtonReleased();

  /**
   * Constructs an event instance around the back button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the back button's
   * digital signal attached to the given loop.
   */
  BooleanEvent Back(EventLoop* loop) const;

  /**
   * Read the value of the start button on the controller.
   *
   * @return The state of the button.
   */
  bool GetStartButton() const;

  /**
   * Whether the start button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetStartButtonPressed();

  /**
   * Whether the start button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetStartButtonReleased();

  /**
   * Constructs an event instance around the start button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the start button's
   * digital signal attached to the given loop.
   */
  BooleanEvent Start(EventLoop* loop) const;

  /**
   * Read the value of the left stick button on the controller.
   *
   * @return The state of the button.
   */
  bool GetLeftStickButton() const;

  /**
   * Whether the left stick button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetLeftStickButtonPressed();

  /**
   * Whether the left stick button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetLeftStickButtonReleased();

  /**
   * Constructs an event instance around the left stick button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the left stick button's
   * digital signal attached to the given loop.
   */
  BooleanEvent LeftStick(EventLoop* loop) const;

  /**
   * Read the value of the right stick button on the controller.
   *
   * @return The state of the button.
   */
  bool GetRightStickButton() const;

  /**
   * Whether the right stick button was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check.
   */
  bool GetRightStickButtonPressed();

  /**
   * Whether the right stick button was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  bool GetRightStickButtonReleased();

  /**
   * Constructs an event instance around the right stick button's
   * digital signal.
   *
   * @param loop the event loop instance to attach the event to.
   * @return an event instance representing the right stick button's
   * digital signal attached to the given loop.
   */
  BooleanEvent RightStick(EventLoop* loop) const;

  /**
   * Read the value of the left bumper (LB) button on the controller.
   *
   * @return the state of the button
   */
  [[deprecated("Use GetLeftBumperButton instead")]]
  bool GetLeftBumper() const;

  /**
   * Read the value of the right bumper (RB) button on the controller.
   *
   * @return the state of the button
   */
  [[deprecated("Use GetRightBumperButton instead")]]
  bool GetRightBumper() const;

  /**
   * Whether the left bumper (LB) was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check
   */
  [[deprecated("Use GetLeftBumperButtonPressed instead")]]
  bool GetLeftBumperPressed();

  /**
   * Whether the right bumper (RB) was pressed since the last check.
   *
   * @return Whether the button was pressed since the last check
   */
  [[deprecated("Use GetRightBumperButtonPressed instead")]]
  bool GetRightBumperPressed();

  /**
   * Whether the left bumper (LB) was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  [[deprecated("Use GetLeftBumperButtonReleased instead")]]
  bool GetLeftBumperReleased();

  /**
   * Whether the right bumper (RB) was released since the last check.
   *
   * @return Whether the button was released since the last check.
   */
  [[deprecated("Use GetRightBumperButtonReleased instead")]]
  bool GetRightBumperReleased();

  /** Represents a digital button on an XboxController. */
  struct Button {
    /// A button.
    static constexpr int kA = 1;
    /// B button.
    static constexpr int kB = 2;
    /// X button.
    static constexpr int kX = 3;
    /// Y button.
    static constexpr int kY = 4;
    /// Left bumper button.
    static constexpr int kLeftBumper = 5;
    /// Right bumper button.
    static constexpr int kRightBumper = 6;
    /// Back button.
    static constexpr int kBack = 7;
    /// Start button.
    static constexpr int kStart = 8;
    /// Left stick button.
    static constexpr int kLeftStick = 9;
    /// Right stick button.
    static constexpr int kRightStick = 10;
  };

  /** Represents an axis on an XboxController. */
  struct Axis {
    /// Left X axis.
    static constexpr int kLeftX = 0;
    /// Right X axis.
    static constexpr int kRightX = 4;
    /// Left Y axis.
    static constexpr int kLeftY = 1;
    /// Right Y axis.
    static constexpr int kRightY = 5;
    /// Left trigger.
    static constexpr int kLeftTrigger = 2;
    /// Right trigger.
    static constexpr int kRightTrigger = 3;
  };
};

}  // namespace frc
