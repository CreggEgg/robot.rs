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
    println!("cargo:rustc-link-lib=wpiHal");
    println!("cargo:rustc-link-lib=wpiutil");
    println!("cargo:rustc-link-lib=ntcore");
}
