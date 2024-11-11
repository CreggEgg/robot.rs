use std::ffi::CString;

use wpilib_hal::{
    NT_CreateInstance, NT_DestroyInstance, NT_GetDefaultInstance, NT_Inst, NT_StartServer,
    NT_StopServer, WPI_String,
};

use crate::entry::Entry;

#[derive(Debug, Clone)]
pub struct ServerConfig<'a> {
    pub persist_filename: &'a str,
    pub listen_address: &'a str,
    pub port3: usize,
    pub port4: usize,
}

impl<'a> Default for ServerConfig<'a> {
    fn default() -> Self {
        Self {
            persist_filename: "networktables.json",
            listen_address: "",
            port3: 1735,
            port4: 5810,
        }
    }
}

pub struct NetworkTableInstance {
    pub(crate) handle: NT_Inst,
}

impl NetworkTableInstance {
    pub fn new() -> Self {
        Self {
            handle: unsafe { NT_CreateInstance() },
        }
    }

    pub fn start_server<'a>(&mut self, config: ServerConfig<'a>) {
        let cstr_persist = CString::new(config.persist_filename).unwrap();
        let cstr_listen = CString::new(config.listen_address).unwrap();

        let wpi_str_persist = WPI_String {
            str_: cstr_persist.as_ptr(),
            len: config.persist_filename.len(),
        };
        let wpi_str_listen = WPI_String {
            str_: cstr_listen.as_ptr(),
            len: config.listen_address.len(),
        };

        unsafe { NT_StartServer(self.handle, &wpi_str_persist, &wpi_str_listen, 1735, 5810) }
    }

    pub fn stop_server(&mut self) {
        unsafe { NT_StopServer(self.handle) }
    }

    // TODO: Client

    pub fn entry(&self, name: &str) -> Entry {
        Entry::new(&self, name)
    }
}

impl Default for NetworkTableInstance {
    fn default() -> Self {
        Self {
            handle: unsafe { NT_GetDefaultInstance() },
        }
    }
}

impl Drop for NetworkTableInstance {
    fn drop(&mut self) {
        let handle = self.handle;
        if handle != unsafe { NT_GetDefaultInstance() } {
            unsafe { NT_DestroyInstance(handle) };
        }
    }
}
