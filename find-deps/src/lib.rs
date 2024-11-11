use std::fs;
use std::io::{Read, Write};
use std::path::PathBuf;

use std::env;
pub struct Paths {
    pub wpilib_artifacts_path: PathBuf,
    pub revlib_path: PathBuf,
    pub ctre_path: PathBuf,
    // pub wpilib_libs_path: PathBuf
}
pub fn get_paths() -> Paths {
    let revlib_path = dunce::canonicalize(std::path::PathBuf::from(
        env::var("REVLIB_DIR").expect("Please set the REVLIB_DIR environment variable"),
    )
    )
    .unwrap(); // include path
               // let wpilib_libs_path = std::path::PathBuf::from(
               //     env::var("WPILIB_LIBS_DIR").expect("Please set the WPILIB_LIBS_DIR environment variable"),
               // )
               // .canonicalize()
               // .unwrap(); // include path
    let ctre_path = dunce::canonicalize(std::path::PathBuf::from(
                env::var("CTRE_DIR")
                    .expect("Please set CTRE_DIR environment variable"),
            )
            )
            .unwrap();
    let wpilib_artifacts_path = dunce::canonicalize(std::path::PathBuf::from(
        env::var("WPILIB_ARTIFACTS_DIR")
            .expect("Please set WPILIB_ARTIFACTS_DIR environment variable"),
    )
    )
    .unwrap(); // include path
               // let mut b = autocxx_build::Builder::new("src/main.rs", &[&path])
               //     .extra_clang_args(&["-std=c++20"])
               //     .build()
               //     .unwrap();
               // b.flag_if_supported("-std=c++20") // use "-std:c++17" here if using msvc on windows
               //     .compile("revlib"); // arbitrary library name, pick anything
    dbg!(&wpilib_artifacts_path);
    dbg!(&revlib_path);
    dbg!(&ctre_path);
    Paths {
        revlib_path,
        wpilib_artifacts_path,
        ctre_path
        // wpilib_libs_path
    }
}
pub fn get_frc_libs_path() -> PathBuf {
    let mut target_dir = PathBuf::from(std::env::var("OUT_DIR").unwrap());
    target_dir.push("frc_libs");

    if !fs::exists(&target_dir).unwrap_or(false) {
    //let _ = fs::remove_dir_all(&target_dir);
    fs::create_dir(&target_dir).unwrap();
    }
    target_dir
}

pub fn extract_lib_to_frc_libs(zipped: PathBuf, lib: &str) {
    dbg!(&zipped);
    let mut archive = zip::ZipArchive::new(fs::File::open(zipped).unwrap()).unwrap();

    let mut file = archive
        .by_name(lib)
        .expect(&format!("Did not find {}", lib));

    let mut buf = vec![];
    file.read_to_end(&mut buf)
        .expect("Failed to read the contents of the lib");
    let mut out_path = get_frc_libs_path();
    out_path.push(
        file.enclosed_name().unwrap().file_name().unwrap(), // .to_str()
                                                            // .unwrap(),
    );
    if fs::exists(&out_path).unwrap_or(false) {
        println!("out_path {:?}",out_path);
        return;
    }

    dbg!(&out_path);
    let _ = fs::File::create_new(&out_path).unwrap().write(&buf);
    // .unwrap(),
}
pub fn extract_lib_to_frc_libs_renamed(zipped: PathBuf, lib: &str, new_name: &str) {
    let mut archive = zip::ZipArchive::new(fs::File::open(zipped).unwrap()).unwrap();

    let mut file = archive
        .by_name(lib)
        .expect(&format!("Did not find {}", lib));

    let mut buf = vec![];
    file.read_to_end(&mut buf)
        .expect("Failed to read the contents of the lib");
    let mut out_path = get_frc_libs_path();
    out_path.push(
        new_name, // .to_str()
                 // .unwrap(),
    );
    if fs::exists(&out_path).unwrap_or(false) {
        return;
    }

    dbg!(&out_path);
    let _ = fs::File::create_new(&out_path).unwrap().write(&buf);

    // file.read(buf);
}
