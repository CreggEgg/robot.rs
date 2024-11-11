use std::{env, path::PathBuf};

use find_deps::Paths;

fn main() {
    let path = std::path::PathBuf::from("include"); // include path
    let paths = find_deps::get_paths();
    // let inc5 = format!(
    //     "-idirafter{}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/c++/12/tr1/",
    //     paths.wpilib_artifacts_path.display()
    // );
    // println!("{}", inc5);

    let mut builder = bindgen::Builder::default()
        .derive_default(true)
        // .derive_ord(true)
        .clang_arg("-Iinclude")
        .header("./include/rev/CANSparkMaxDriver.h")
        .default_enum_style(bindgen::EnumVariation::Rust {
            non_exhaustive: false,
        })
        //.blocklist_type("std::string")
        //.blacklist_type("ctre::phoenix::.*Routines")
        .opaque_type("std::.*")
        //.whitelist_type(SYMBOL_REGEX)
        .allowlist_function("c_.+")
        //.rustified_enum(SYMBOL_REGEX)
        .disable_name_namespacing()
        .ignore_methods()
        .ctypes_prefix("raw")
        .array_pointers_in_arguments(true)
        .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()))
        /*
        .rustfmt_configuration_file(Some(
            PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("rustfmt.toml"),
        ))
        */
        .clang_arg("-xc++")
        .clang_arg("-std=c++14");

    #[cfg(target_os = "windows")]
    {
        //panic!("on linux");
        builder = builder
    .clang_arg(format!(
        "-isystem{}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/c++/12/",
        paths.wpilib_artifacts_path.display())
    )
    .clang_arg(format!(
        "-isystem{}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/c++/12/arm-nilrt-linux-gnueabi/",
        paths.wpilib_artifacts_path.display()
))
    .clang_arg(format!(
        "-isystem{}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/",
        paths.wpilib_artifacts_path.display()
))
    .clang_arg(format!(
        "-isystem{}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/lib/gcc/arm-nilrt-linux-gnueabi/12/include/",
        paths.wpilib_artifacts_path.display()
))
    //}
    // #[cfg(target_os = "windows")]
    // {
    //     //panic!("on windows");
    //     builder = builder
    // .clang_arg(format!(
    //     "-isystem{}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/c++/12/",
    //     paths.wpilib_artifacts_path.display())
    // )
//     .clang_arg(format!(
//         "-isystem{}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/c++/12/arm-nilrt-linux-gnueabi/",
//         paths.wpilib_artifacts_path.display()
// ))
//     .clang_arg(format!(
//         "-isystem{}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/",
//         paths.wpilib_artifacts_path.display()
// ))
//     .clang_arg(format!(
//         "-isystem{}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/lib/gcc/arm-nilrt-linux-gnueabi/12/include/",
//         paths.wpilib_artifacts_path.display()
// ))
    }
    //     .clang_arg(format!(
    //         "-isystem{}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/linux",
    //         paths.wpilib_artifacts_path.display()
    // ))
    //     .clang_arg(format!(
    //         "-isystem{}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/c++/12/tr1/",
    //         paths.wpilib_artifacts_path.display()
    // ))
    // .clang_arg(format!("-idirafter\"{}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/c++/12/\"", paths.wpilib_artifacts_path.display()))
    // .clang_arg(format!("-idirafter\"{}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/c++/12/arm-nilrt-linux-gnueabi/\"",paths.wpilib_artifacts_path.display()))
    // .clang_arg(format!("-idirafter\"{}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/include/\"", paths.wpilib_artifacts_path.display()))
    let bindings = builder.generate().unwrap();
    let out_path = PathBuf::from(std::env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
    println!("cargo:rerun-if-changed=src/main.rs");
    println!("cargo:rerun-if-changed=build.rs");
    println!("cargo:rerun-if-changed=include/*");
    println!(
        "cargo::rustc-link-search={}/roborio/arm-nilrt-linux-gnueabi/sysroot/usr/lib",
        paths.wpilib_artifacts_path.display()
    );

    let path = PathBuf::from("libs");

    println!(
        "cargo:rustc-link-search={}",
        find_deps::get_frc_libs_path()
            .canonicalize()
            .unwrap()
            .to_str()
            .unwrap() // PathBuf::from("libs")
                      //     .canonicalize()
                      //     .unwrap()
                      //     .to_str()
                      //     .unwrap()
    );
    // println!(
    //     "cargo:rustc-link-search={}",
    //     paths.revlib_path.display() // PathBuf::from("libs")
    //                                 //     .canonicalize()
    //                                 //     .unwrap()
    //                                 //     .to_str()
    //                                 //     .unwrap()
    // );
    let wpilib = [
        paths.wpilib_artifacts_path.to_str().unwrap(),
        "maven",
        "edu",
        "wpi",
        "first",
    ];
    let wpi_version = "2024.3.2";
    let ni_version = "2024.2.1";
    let revlib_version = "2024.2.4";

    extract_wpilib_lib("hal", "wpiHal", wpi_version, &paths);
    extract_wpilib_lib("wpinet", "wpinet", wpi_version, &paths);
    extract_wpilib_lib("wpiutil", "wpiutil", wpi_version, &paths);
    extract_wpilib_lib("wpimath", "wpimath", wpi_version, &paths);
    extract_wpilib_lib("ntcore", "ntcore", wpi_version, &paths);

    extract_ni_lib(
        "chipobject",
        "RoboRIO_FRC_ChipObject",
        ".24.0.0",
        ni_version,
        &paths,
    );
    extract_ni_lib(
        "netcomm",
        "FRC_NetworkCommunication",
        ".24.0.0",
        ni_version,
        &paths,
    );
    extract_ni_lib("visa", "visa", ".23.3.0", ni_version, &paths);
    find_deps::extract_lib_to_frc_libs(
        PathBuf::from(
            format!(
                "{}/maven/edu/wpi/first/ni-libraries/runtime/{ni_version}/runtime-{ni_version}-linuxathena.zip",
                paths.wpilib_artifacts_path.display(),
            ), //     wpilib[..],
               //     [
               //         "hal",
               //         "hal-cpp",
               //         "2024.3.2",
               //         "hal-cpp-2024.3.2-linuxathena.zip",
               //     ][..],
               // ]
               // .concat(),
        ),
        &format!("linux/athena/shared/libembcanshim.so"),
    );
    find_deps::extract_lib_to_frc_libs(
        PathBuf::from(
            format!(
                "{}/maven/edu/wpi/first/ni-libraries/runtime/{ni_version}/runtime-{ni_version}-linuxathena.zip",
                paths.wpilib_artifacts_path.display(),
            ), //     wpilib[..],
               //     [
               //         "hal",
               //         "hal-cpp",
               //         "2024.3.2",
               //         "hal-cpp-2024.3.2-linuxathena.zip",
               //     ][..],
               // ]
               // .concat(),
        ),
        &format!("linux/athena/shared/libfpgalvshim.so"),
    );
    find_deps::extract_lib_to_frc_libs(
        PathBuf::from(
            format!(
                "{}/maven/com/revrobotics/frc/REVLib-driver/{revlib_version}/REVLib-driver-{revlib_version}-linuxathena.zip",
                paths.revlib_path.display(),
            ), //     wpilib[..],
               //     [
               //         "hal",
               //         "hal-cpp",
               //         "2024.3.2",
               //         "hal-cpp-2024.3.2-linuxathena.zip",
               //     ][..],
               // ]
               // .concat(),
        ),
        &format!("linux/athena/shared/libREVLibDriver.so"),
    );

    println!("cargo::rustc-link-lib=dylib=wpiHal");
    println!("cargo::rustc-link-lib=dylib=REVLibDriver");
    println!("cargo::rustc-link-lib=dylib=wpiutil");
    println!("cargo::rustc-link-lib=dylib=FRC_NetworkCommunication");
    println!("cargo::rustc-link-lib=dylib=RoboRIO_FRC_ChipObject");
    println!("cargo::rustc-link-lib=dylib=visa");
    println!("cargo::rustc-link-lib=dylib=stdc++");
    println!("cargo::rustc-link-lib=dylib=fpgalvshim");
    println!("cargo::rustc-link-lib=dylib=embcanshim");
}

fn extract_wpilib_lib(name: &str, libname: &str, wpi_version: &str, paths: &Paths) {
    find_deps::extract_lib_to_frc_libs(
        PathBuf::from(
            format!(
                "{}/maven/edu/wpi/first/{name}/{name}-cpp/{wpi_version}/{name}-cpp-{wpi_version}-linuxathena.zip",
                paths.wpilib_artifacts_path.display(),
            ), //     wpilib[..],
               //     [
               //         "hal",
               //         "hal-cpp",
               //         "2024.3.2",
               //         "hal-cpp-2024.3.2-linuxathena.zip",
               //     ][..],
               // ]
               // .concat(),
        ),
        &format!("linux/athena/shared/lib{libname}.so"),
    );
}
fn extract_ni_lib(name: &str, libname: &str, ending: &str, ni_version: &str, paths: &Paths) {
    find_deps::extract_lib_to_frc_libs_renamed(
        PathBuf::from(
            format!(
                "{}/maven/edu/wpi/first/ni-libraries/{name}/{ni_version}/{name}-{ni_version}-linuxathena.zip",
                paths.wpilib_artifacts_path.display(),
            ), //     wpilib[..],
               //     [
               //         "hal",
               //         "hal-cpp",
               //         "2024.3.2",
               //         "hal-cpp-2024.3.2-linuxathena.zip",
               //     ][..],
               // ]
               // .concat(),
        ),
        &format!("linux/athena/shared/lib{libname}.so{ending}"),
        &format!("lib{libname}.so")
    );
}
