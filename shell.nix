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

  # REVLIB_DIR = "/home/churst/Downloads/revlib/";
  # WPILIB_DIR = "/home/churst/Downloads//";

  LIBCLANG_PATH="${llvmPackages.libclang.lib}/lib";

  shellHook = ''
  '';
}
