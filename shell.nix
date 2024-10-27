# https://nix.dev/tutorials/declarative-and-reproducible-developer-environments
with import <nixpkgs> { };

mkShell {

  # Package names can be found via https://search.nixos.org/packages
  nativeBuildInputs = [
    direnv
    clang
    # stdenv.cc.libc
  ];

  NIX_ENFORCE_PURITY = true;

  # REVLIB_DIR = "";
  WPILIB_DIR = "CHANGE ME!!!!!!";

  LIBCLANG_PATH="${llvmPackages.libclang.lib}/lib";

  shellHook = ''
  '';
}
