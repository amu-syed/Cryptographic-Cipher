# Cryptographic Data Masking Utility

## Overview
This repository contains a C-based cybersecurity tool designed to encrypt and decrypt strings using a bitwise XOR cipher. It demonstrates fundamental low-level memory manipulation, pointer usage, and secure input handling to prevent buffer overflow vulnerabilities.

## Features
## Bitwise Encryption:
Utilizes XOR operations ('^') to securely mask and unmask plaintext data.
## Memory Management:
Implements C pointers to modify data structures directly in memory without redundant copying.
## Memory-Safe Input:
 Uses 'fgets' instead of vulnerable input functions to strictly enforce buffer limits and prevent overflows.
* **Input Validation:** Features stream-clearing loops to sanitize invalid data entries and prevent runtime crashes.

