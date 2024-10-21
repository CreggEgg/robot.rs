bindgen --default-enum-style rust --with-derive-default ./include/HALWrapper.h -- -I ./include > src/bindings.rs
