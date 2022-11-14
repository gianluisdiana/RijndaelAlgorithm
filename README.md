# Rijndael Algorithm
* Author: Gian Luis Bolivar Diana
* Email: _gianluisbolivar1@gmail.com_

AES algorithm implementation using C++ (coded for the Computer Science Students Congress VIII).

## How to use
First, clone the repository and execute the following command to create the necesary directories:
```BASH
make setup
```

This program _encrypt_ or _decrypt_ a key using the Rijndael algorithm and a private key. Use `--help` for an explanation on how to use the code:
```BASH
./bin/exec.out [--hex] <--encrypt | --decrypt> <key>
                  │               │              └─> The key to encrypt / decrypt
                  │               └─> The mode selected
                  └─> If we want to display the hex code. Optional.
```

## References
* [AES algorithm](https://en.wikipedia.org/wiki/Advanced_Encryption_Standard)