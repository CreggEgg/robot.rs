use find_deps::Paths;
use std::path::PathBuf;
fn main() {
    let paths = find_deps::get_paths();
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

    let wpi_version = "2024.3.2";
    let ni_version = "2024.2.1";

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
    println!("cargo:rustc-link-lib=wpinet");
    println!("cargo:rustc-link-lib=wpimath");
    println!("cargo:rustc-link-lib=wpiHal");
    println!("cargo:rustc-link-lib=wpiutil");
    println!("cargo:rustc-link-lib=ntcore");
    println!("cargo:rustc-link-lib=visa");
    println!("cargo:rustc-link-lib=RoboRIO_FRC_ChipObject");
    println!("cargo:rustc-link-lib=FRC_NetworkCommunication");
    println!("cargo:rustc-link-lib=embcanshim");
    println!("cargo:rustc-link-lib=fpgalvshim");
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
