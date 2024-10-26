use crate::actuators::pwm::{PWMSpeedController, PWM};
use io::motor::MotorController;
use macros::{wrapped_traits, wrapped_traits_nogen};
use wpilib_hal::{hal_safe_call, HAL_GetVinVoltage};

macro_rules! pwm_motor_impl {
    ($name:ident) => {
        pub struct $name(PWMSpeedController);

        impl $name {
            pub fn new(port: usize) -> Self {
                Self(PWM::new(port).speed_controller())
            }

            pub fn bus_voltage() -> f64 {
                hal_safe_call!(HAL_GetVinVoltage()).unwrap()
            }
        }

        impl MotorController for $name {
            fn set_voltage(&mut self, voltage: f64) {
                self.0.set_speed((voltage / Self::bus_voltage()));
            }

            fn get_set_voltage(&self) -> f64 {
                self.0.get_speed() * Self::bus_voltage()
            }
        }

        wrapped_traits_nogen!($name, PWMSpeedController);
    };
}

pwm_motor_impl!(PWMSparkMax);
pwm_motor_impl!(PWMTalonSRX);
pwm_motor_impl!(PWMTalonFX);

#[cfg(test)]
mod test {
    use approx::assert_relative_eq;
    use io::motor::{ClampedMotor, InvertMotor};

    use super::{MotorController, PWMSparkMax};

    #[test]
    fn test_pwm_motor_controller() {
        let mut pwm = PWMSparkMax::new(0);
        assert_relative_eq!(pwm.get_set_voltage(), 0.0);
        pwm.set_voltage(12.0);
        assert_relative_eq!(pwm.get_set_voltage(), 12.0);
        pwm.set_voltage(-4.0);
        assert_relative_eq!(pwm.get_set_voltage(), -4.0);
    }

    #[test]
    fn test_inverted_motor() {
        let mut inverted = InvertMotor(PWMSparkMax::new(1));
        inverted.set_voltage(12.0);
        assert_relative_eq!(inverted.get_set_voltage(), 12.0);
        assert_relative_eq!(inverted.0.get_set_voltage(), -12.0);
    }

    #[test]
    fn test_clamped_motor() {
        let mut clamped = ClampedMotor(PWMSparkMax::new(2), -5.0, 6.0);
        clamped.set_voltage(3.3);
        assert_relative_eq!(clamped.get_set_voltage(), 3.3);
        clamped.set_voltage(10.0);
        assert_relative_eq!(clamped.get_set_voltage(), 6.0);
        clamped.set_voltage(-6.0);
        assert_relative_eq!(clamped.get_set_voltage(), -5.0);
    }
}
