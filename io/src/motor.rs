use macros::wrapped_traits;
pub trait MotorController {
    fn set_voltage(&mut self, voltage: f64);
    fn get_set_voltage(&self) -> f64;
}

pub struct InvertMotor<M: MotorController>(pub M);

impl<M: MotorController> MotorController for InvertMotor<M> {
    fn set_voltage(&mut self, voltage: f64) {
        self.0.set_voltage(voltage * -1.0);
    }

    fn get_set_voltage(&self) -> f64 {
        self.0.get_set_voltage() * -1.0
    }
}

pub struct ClampedMotor<M: MotorController>(pub M, pub f64, pub f64);

impl<M: MotorController> MotorController for ClampedMotor<M> {
    fn set_voltage(&mut self, voltage: f64) {
        self.0.set_voltage(voltage.max(self.1).min(self.2))
    }

    fn get_set_voltage(&self) -> f64 {
        self.0.get_set_voltage()
    }
}

wrapped_traits!(MotorController, InvertMotor);
wrapped_traits!(MotorController, ClampedMotor);
