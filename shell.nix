# shell.nix for libcheck_example
# Set up build dependencies with [Nix](https://nixos.org/)
# Invoke with 'nix-shell', then do build operations in the resulting shell.
{
  nixpkgs ? import <nixpkgs> { },
}:

with nixpkgs;

stdenv.mkDerivation {
  name = "libcheck_example";

  buildInputs = [
    check
    clang
    gnumake
  ];
}
