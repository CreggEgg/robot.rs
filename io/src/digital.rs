use macros::{wrapped_traits, wrapped_traits_nogen};

pub trait DigitalInput {
    fn get(&self) -> bool;
}

pub trait DigitalOutput: DigitalInput {
    fn set(&mut self, value: bool);
}

pub struct InvertInput<D: DigitalInput>(pub D);
pub struct InvertOutput<D: DigitalOutput>(pub D);

impl<D: DigitalInput> DigitalInput for InvertInput<D> {
    fn get(&self) -> bool {
        !self.0.get()
    }
}

impl<D: DigitalOutput> DigitalInput for InvertOutput<D> {
    fn get(&self) -> bool {
        !self.0.get()
    }
}

impl<D: DigitalOutput> DigitalOutput for InvertOutput<D> {
    fn set(&mut self, value: bool) {
        self.0.set(!value)
    }
}

wrapped_traits!(DigitalInput, InvertInput);
wrapped_traits!(DigitalOutput, InvertOutput);
