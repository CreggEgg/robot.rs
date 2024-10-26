use io::digital::{DigitalInput, DigitalOutput};
use wpilib_hal::{
    hal_safe_call, HAL_DigitalHandle, HAL_FreeDIOPort, HAL_GetDIO, HAL_GetPort,
    HAL_InitializeDIOPort, HAL_SetDIO, HAL_SetDIODirection,
};

use macros::{wrapped_traits, wrapped_traits_nogen};

pub struct DigitalRoboRIO {
    port: usize,
    handle: HAL_DigitalHandle,
}

pub struct DigitalRoboRIOInput(DigitalRoboRIO);
pub struct DigitalRoboRIOOutput(DigitalRoboRIO);

wrapped_traits_nogen!(DigitalRoboRIOInput, DigitalRoboRIO);
wrapped_traits_nogen!(DigitalRoboRIOOutput, DigitalRoboRIO);

impl DigitalRoboRIO {
<<<<<<< HEAD
  pub fn new(port: usize) -> Self {
    let handle = hal_safe_call!(HAL_InitializeDIOPort(HAL_GetPort(port as i32), 1, "DigitalRoboRIO::new".as_ptr() as *const u8)).unwrap();
=======
    pub fn new(port: usize) -> Self {
        let handle = hal_safe_call!(HAL_InitializeDIOPort(
            HAL_GetPort(port as i32),
            1,
            "DigitalRoboRIO::new".as_ptr() as *const i8
        ))
        .unwrap();
>>>>>>> 21853c4 (added revlib in as a feature and did some refactoring to allow for more shared code)

        Self { port, handle }
    }

    pub fn port(&self) -> usize {
        self.port
    }

    pub fn input(self) -> DigitalRoboRIOInput {
        DigitalRoboRIOInput::new(self)
    }
    pub fn output(self) -> DigitalRoboRIOOutput {
        DigitalRoboRIOOutput::new(self)
    }
}

impl Drop for DigitalRoboRIO {
    fn drop(&mut self) {
        unsafe {
            HAL_FreeDIOPort(self.handle);
        }
    }
}

impl DigitalRoboRIOInput {
    pub fn new(drr: DigitalRoboRIO) -> Self {
        hal_safe_call!(HAL_SetDIODirection(drr.handle, 1)).unwrap();
        Self(drr)
    }
}

impl DigitalInput for DigitalRoboRIOInput {
    fn get(&self) -> bool {
        hal_safe_call!(HAL_GetDIO(self.handle)).unwrap() > 0
    }
}

impl DigitalRoboRIOOutput {
    pub fn new(drr: DigitalRoboRIO) -> Self {
        hal_safe_call!(HAL_SetDIODirection(drr.handle, 0)).unwrap();

        Self(drr)
    }
}

impl DigitalInput for DigitalRoboRIOOutput {
    fn get(&self) -> bool {
        hal_safe_call!(HAL_GetDIO(self.handle)).unwrap() > 0
    }
}

impl DigitalOutput for DigitalRoboRIOOutput {
    fn set(&mut self, value: bool) {
        hal_safe_call!(HAL_SetDIO(self.handle, value as i32)).unwrap()
    }
}

#[cfg(test)]
mod test {
    use io::digital::InvertOutput;

    use super::{DigitalInput, DigitalOutput, DigitalRoboRIO};

    #[test]
    fn test_roborio_digital_out() {
        let mut out = DigitalRoboRIO::new(0).output();
        out.set(true);
        assert_eq!(out.get(), true);
        out.set(false);
        assert_eq!(out.get(), false);
    }

    #[test]
    fn test_inverted() {
        let mut out = InvertOutput(DigitalRoboRIO::new(1).output());
        out.set(false);
        assert_eq!(out.get(), false);
        assert_eq!(out.0.get(), true);
        assert_eq!(out.revert().get(), true);
    }
}
