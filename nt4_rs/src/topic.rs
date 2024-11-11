use std::ffi::CString;

use wpilib_hal::{
    NT_GetTopic, NT_GetTopicExists, NT_GetTopicPersistent, NT_GetTopicRetained, NT_GetTopicType,
    NT_GetTopicTypeString, NT_SetTopicPersistent, NT_SetTopicRetained, NT_Topic, WPI_String,
};

use crate::{instance::NetworkTableInstance, types::Type};

struct Topic {
    handle: NT_Topic,
}

impl Topic {
    pub fn new(instance: &NetworkTableInstance, name: &str) -> Self {
        let cname = CString::new(name).unwrap();
        let str = WPI_String {
            str_: cname.as_ptr(),
            len: name.len(),
        }; //CString::new(name).unwrap();
        Self {
            handle: unsafe {
                NT_GetTopic(instance.handle, &str) //, cstr.as_bytes().len() as u64)
            },
        }
    }

    pub fn get_type(&self) -> Type {
        unsafe { NT_GetTopicType(self.handle) }.into()
    }

    pub fn get_type_str(&self) -> String {
        let mut str = WPI_String::default();
        unsafe { NT_GetTopicTypeString(self.handle, &mut str) };
        std::str::from_utf8(unsafe { std::slice::from_raw_parts(str.str_ as *const u8, str.len) })
            .unwrap()
            .to_owned()
    }

    pub fn set_persistent(&mut self, persistent: bool) {
        unsafe { NT_SetTopicPersistent(self.handle, persistent as i32) }
    }

    pub fn is_persistent(&self) -> bool {
        unsafe { NT_GetTopicPersistent(self.handle) != 0 }
    }

    pub fn set_retained(&mut self, retained: bool) {
        unsafe { NT_SetTopicRetained(self.handle, retained as i32) }
    }

    pub fn is_retained(&self) -> bool {
        unsafe { NT_GetTopicRetained(self.handle) != 0 }
    }

    pub fn exists(&self) -> bool {
        unsafe { NT_GetTopicExists(self.handle) != 0 }
    }

    // TODO: Properties, Pub, Sub
}
