#[allow(warnings)]
mod rev;
use io::motor::MotorController;
use rev::*;

macro_rules! safe_call {
  ($function:ident($($arg:expr),* $(,)?)) => {{
    use crate::RevError;
        let error = unsafe { $function($($arg,)*) };

        if error != _c_REVLib_ErrorCode::c_REVLibError_None {
            Err(RevError::from(error))
        } else {
            Ok(())
        }
  }};
  ($function:ident($($arg:expr),* $(,)?) -> $ret:ident) => {{
    use crate::RevError;

        let mut tmp: $ret = $ret::default();
        let error = unsafe { $function($($arg,)* &mut tmp) };

        if error != _c_REVLib_ErrorCode::c_REVLibError_None {
            Err(RevError::from(error))
        } else {
            Ok(tmp)
        }

  }};

}
#[derive(Debug, Clone, Copy)]
pub enum DutyCycleMode {
    Absolute,
    Relative
}
impl Into<c_SparkMax_DutyCycleMode> for DutyCycleMode {
    fn into(self) -> c_SparkMax_DutyCycleMode {
        match self {
            DutyCycleMode::Absolute => c_SparkMax_DutyCycleMode::c_SparkMax_kDutyCycleAbsolute,
            DutyCycleMode::Relative => c_SparkMax_DutyCycleMode::c_SparkMax_kDutyCycleRelative,
        }
    }
}
#[derive(Debug, Clone, Copy)]
pub enum DataPortConfig {
    DataPortConfigNone,
    DataPortConfigLimitSwitchesAndAbsoluteEncoder,
    DataPortConfigAltEncoder,
}
impl Into<c_SparkMax_DataPortConfig> for DataPortConfig {
    fn into(self) -> c_SparkMax_DataPortConfig {
        match self {
            DataPortConfig::DataPortConfigNone => c_SparkMax_DataPortConfig::c_SparkMax_kDataPortConfigNone,
            DataPortConfig::DataPortConfigLimitSwitchesAndAbsoluteEncoder => c_SparkMax_DataPortConfig::c_SparkMax_kDataPortConfigLimitSwitchesAndAbsoluteEncoder,
            DataPortConfig::DataPortConfigAltEncoder => c_SparkMax_DataPortConfig::c_SparkMax_kDataPortConfigAltEncoder,
        }
    }
}
#[derive(Debug)]
pub enum RevError {
    None,
    General,
    CANTimeout,
    NotImplemented,
    HAL,
    CantFindFirmware,
    FirmwareTooOld,
    FirmwareTooNew,
    ParamInvalidID,
    ParamMismatchType,
    ParamAccessMode,
    ParamInvalid,
    ParamNotImplementedDeprecated,
    FollowConfigMismatch,
    Invalid,
    SetpointOutOfRange,
    Unknown,
    CANDisconnected,
    DuplicateCANId,
    InvalidCANId,
    SparkMaxDataPortAlreadyConfiguredDifferently,
    SparkFlexBrushedWithoutDock,
    NumCodes,
}
impl From<rev::_c_REVLib_ErrorCode> for RevError {
    fn from(value: rev::_c_REVLib_ErrorCode) -> Self {
        match value {
            rev::_c_REVLib_ErrorCode::c_REVLibError_None => RevError::None,
            rev::_c_REVLib_ErrorCode::c_REVLibError_General => RevError::General,
            rev::_c_REVLib_ErrorCode::c_REVLibError_CANTimeout => RevError::CANTimeout,
            rev::_c_REVLib_ErrorCode::c_REVLibError_NotImplemented => RevError::NotImplemented,
            rev::_c_REVLib_ErrorCode::c_REVLibError_HAL => RevError::HAL,
            rev::_c_REVLib_ErrorCode::c_REVLibError_CantFindFirmware => RevError::CantFindFirmware,
            rev::_c_REVLib_ErrorCode::c_REVLibError_FirmwareTooOld => RevError::FirmwareTooOld,
            rev::_c_REVLib_ErrorCode::c_REVLibError_FirmwareTooNew => RevError::FirmwareTooNew,
            rev::_c_REVLib_ErrorCode::c_REVLibError_ParamInvalidID => RevError::ParamInvalidID,
            rev::_c_REVLib_ErrorCode::c_REVLibError_ParamMismatchType => RevError::ParamMismatchType,
            rev::_c_REVLib_ErrorCode::c_REVLibError_ParamAccessMode => RevError::ParamAccessMode,
            rev::_c_REVLib_ErrorCode::c_REVLibError_ParamInvalid => RevError::ParamInvalid,
            rev::_c_REVLib_ErrorCode::c_REVLibError_ParamNotImplementedDeprecated => RevError::ParamNotImplementedDeprecated,
            rev::_c_REVLib_ErrorCode::c_REVLibError_FollowConfigMismatch => RevError::FollowConfigMismatch,
            rev::_c_REVLib_ErrorCode::c_REVLibError_Invalid => RevError::Invalid,
            rev::_c_REVLib_ErrorCode::c_REVLibError_SetpointOutOfRange => RevError::SetpointOutOfRange,
            rev::_c_REVLib_ErrorCode::c_REVLibError_Unknown => RevError::Unknown,
            rev::_c_REVLib_ErrorCode::c_REVLibError_CANDisconnected => RevError::CANDisconnected,
            rev::_c_REVLib_ErrorCode::c_REVLibError_DuplicateCANId => RevError::DuplicateCANId,
            rev::_c_REVLib_ErrorCode::c_REVLibError_InvalidCANId => RevError::InvalidCANId,
            rev::_c_REVLib_ErrorCode::c_REVLibError_SparkMaxDataPortAlreadyConfiguredDifferently => {
                RevError::SparkMaxDataPortAlreadyConfiguredDifferently
            }
            rev::_c_REVLib_ErrorCode::c_REVLibError_SparkFlexBrushedWithoutDock => RevError::SparkFlexBrushedWithoutDock,
            rev::_c_REVLib_ErrorCode::c_REVLibError_NumCodes => RevError::NumCodes,
        }
    }
}

pub struct SparkMax;

impl RevMotorControllerModel for SparkMax {
    fn raw() -> rev::c_SparkMax_SparkModel {
        rev::c_SparkMax_SparkModel::c_SparkMax_SparkMax
    }
}

pub struct SparkFlex;

impl RevMotorControllerModel for SparkFlex {
    fn raw() -> rev::c_SparkMax_SparkModel {
        rev::c_SparkMax_SparkModel::c_SparkMax_SparkFlex
    }
}

// pub enum MotorControllerType {
//     SparkMax,
//     SparkFlex,
// }
// impl MotorControllerType {
//     fn get_raw(&self) -> rev::c_SparkMax_SparkModel;
// }


pub trait RevMotorControllerModel {
    fn raw() -> rev::c_SparkMax_SparkModel;
}

pub enum MotorType {
    Brushless,
    Brushed,
}

impl MotorType {
    fn raw(&self) -> rev::c_SparkMax_MotorType {
        match self {
            MotorType::Brushless => rev::c_SparkMax_MotorType::c_SparkMax_kBrushless,
            MotorType::Brushed => rev::c_SparkMax_MotorType::c_SparkMax_kBrushed,
        }
    }
}

pub struct RevMotorController<Controller>
where
    Controller: RevMotorControllerModel,
{
    handle: rev::c_SparkMax_handle,
    id: i32,
    _controller: Controller,
}

// pub struct MotorController<Controller>
// where
//     Controller: MotorControllerType,
// {
//     handle: rev::c_SparkMax_handle,
//     id: i32,
//     _controller: Controller,
// }
impl<Controller: RevMotorControllerModel> RevMotorController<Controller> {
    pub fn new(controller: Controller, id: i32, motor_type: MotorType) -> Result<Self, RevError> {
        safe_call!(c_SparkMax_RegisterId(id))?;
        let mut error = rev::_c_REVLib_ErrorCode::c_REVLibError_None;
        let mc = Self {
            id,
            handle: unsafe {
                rev::c_SparkMax_Create(id, motor_type.raw(), Controller::raw(), &mut error)
            },
            _controller: controller,
        };
        if error != rev::_c_REVLib_ErrorCode::c_REVLibError_None {
            Err(RevError::from(error))
        } else {
            Ok(mc)
        }
    }

    pub fn get_encoder_position(&self) -> Result<f32, RevError> {
        safe_call!(c_SparkMax_GetEncoderPosition(self.handle) -> f32)
    }
    pub fn get_encoder_velocity(&self) -> Result<f32, RevError> {
        safe_call!(c_SparkMax_GetEncoderVelocity(self.handle) -> f32)
    }
    pub fn get_alt_encoder_position(&self) -> Result<f32, RevError> {
        safe_call!(c_SparkMax_GetAltEncoderPosition(self.handle) -> f32)
    }
    pub fn get_alt_encoder_velocity(&self) -> Result<f32, RevError> {
        safe_call!(c_SparkMax_GetAltEncoderVelocity(self.handle) -> f32)
    }
    pub fn get_duty_cycle_encoder_position(&self) -> Result<f32, RevError> {
        safe_call!(c_SparkMax_GetDutyCyclePosition(self.handle) -> f32)
    }
    pub fn get_duty_cycle_encoder_velocity(&self) -> Result<f32, RevError> {
        safe_call!(c_SparkMax_GetDutyCycleVelocity(self.handle) -> f32)
    }
    pub fn set_duty_cycle_mode(&mut self, duty_cycle_mode: DutyCycleMode) -> Result<(), RevError> {
        safe_call!(c_SparkMax_SetDutyCycleMode(self.handle, duty_cycle_mode.into()))
    }
    pub fn set_data_port_config(&mut self, config: DataPortConfig) -> Result<(), RevError> {
        safe_call!(c_SparkMax_AttemptToSetDataPortConfig(self.handle, config.into()))
    }
}

impl<Controller: RevMotorControllerModel> MotorController for RevMotorController<Controller> {
    fn set_voltage(&mut self, voltage: f64) {
        safe_call!(c_SparkMax_SetpointCommand(
            self.handle,
            voltage as f32,
            rev::c_SparkMax_ControlType::c_SparkMax_kVoltage,
            0.into(),
            0.,
            0.into(),
        ))
        .expect(&format!(
            "Failed to set voltage of motor controller {}",
            self.id
        )) //TODO: Proper error handling here (im thinking reporting this error to driver station
           //log)
    }

    fn get_set_voltage(&self) -> f64 {
        safe_call!(c_SparkMax_GetAppliedOutput(
            self.handle,
        ) -> f32)
        .expect(&format!(
            "Failed to set voltage of motor controller {}",
            self.id
        )) as f64 //TODO: Proper error handling here (im thinking reporting this error to driver station
                  //log)
    }
}
impl<Controller: RevMotorControllerModel> RevMotorController<Controller> {
    pub fn restory_factory_defaults(&mut self, persist: bool) -> Result<(), RevError> {
        safe_call!(c_SparkMax_RestoreFactoryDefaults(
            self.handle,
            persist.into()
        ))
    }
    pub fn follow(&mut self, other: Self, inverted: bool) -> Result<(), RevError> {
        safe_call!(c_SparkMax_SetFollow(
            self.handle,
            other.id.try_into().unwrap(),
            inverted.into()
        ))
    }
}
