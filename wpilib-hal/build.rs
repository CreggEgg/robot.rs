use std::path::PathBuf;
fn main() {
    let path = PathBuf::from("libs");
    dbg!(path);
    println!(
        "cargo:rustc-link-search={}",
        PathBuf::from("libs")
            .canonicalize()
            .unwrap()
            .to_str()
            .unwrap()
    );
    println!("cargo:rustc-link-lib=dylib=wpinet");
    println!("cargo:rustc-link-lib=dylib=wpimath");
    println!("cargo:rustc-link-lib=dylib=wpiHal");
    println!("cargo:rustc-link-lib=dylib=wpiutil");
    println!("cargo:rustc-link-lib=dylib=ntcore");
    println!("cargo:rustc-link-lib=dylib=visa");
    println!("cargo:rustc-link-lib=dylib=RoboRIO_FRC_ChipObject");
    println!("cargo:rustc-link-lib=dylib=FRC_NetworkCommunication");
    println!("cargo:rustc-link-lib=dylib=embcanshim");
    println!("cargo:rustc-link-lib=dylib=fpgalvshim");
}
