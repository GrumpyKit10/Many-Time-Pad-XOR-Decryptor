///////////////////  
/   Project 2     /  
/ Matthew Wilson  /  
/ mlw0420@unt.edu /  
/    11369458	  /  
/  CSCE 3550.001  /  
/     4-18-22     /  
///////////////////

# Many-Time Pad XOR Decryptor
**CSCE 3550: Foundations of Cybersecurity – Spring 2022**  
**Project 2 – Exploiting Many-Time Pad Vulnerability**

## Project Overview
This program demonstrates how reusing a one-time pad (creating a many-time pad) compromises encryption. By XOR-ing ciphertexts together and leveraging predictable ASCII behavior for spaces and letters, the program recovers large portions of the original plaintexts. Undecipherable characters are shown as `_`.

## Requirements
- Source files and Makefile (provided)
- Linux CSE machines (`cse01`–`cse06`)
- `make` and appropriate compiler/interpreter installed

## Using the Makefile
The executable produced by the Makefile is named `proj2`.

1. `make`  
   *Invokes the Makefile to build `proj2` and any `.o` files.*

2. `./proj2`  
   *Run the program (it will prompt for the ciphertext filename).*

3. `make clean`  
   *Remove `.o` files and the `proj2` executable.*

## Usage
1. Place your ciphertext file (hex, two hex digits per byte) in the same directory.
2. Run `make` then `./proj2` and enter the filename when prompted.
3. The program prints partially/fully recovered plaintexts; unknown characters appear as `_`.

## Notes
- Plaintexts contain only uppercase/lowercase letters and spaces.
- The program aims to decrypt at least 90% of the recoverable characters per set.
- Ensure all ciphertexts encrypted with the same key are present to maximize recovery.

## Author
Matthew Wilson — mlw0420@unt.edu — ID: 11369458
CSCE 3550.001 — April 18, 2022
