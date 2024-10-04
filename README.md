# F´ PROVES
[![build](https://github.com/proveskit/fprime-proves/actions/workflows/build.yaml/badge.svg)](https://github.com/proveskit/fprime-proves/actions/workflows/build.yaml)

F´ (F Prime) flight software for the PROVES CubeSat Kit. This version of the PROVES flight software is under development and is not ready to be used with flight hardware. Please see [proveskit/flight_software](https://github.com/proveskit/flight_software/) for our latest flight ready software.

## Building and Running the Deployment: Linux/macOS Guide

Getting started is easy! Please let us know if you run into any issues with the instructions below.

### Check your environment
You must have Python 3.9+ to build this repo. You can check with `python3 --version`

### Setup dependencies

1. Pull the fprime submodule `git submodule update --init --recursive`
1. Create a python venv `python3 -m venv fprime-venv`
1. Activate the venv `. fprime-venv/bin/activate`
1. Install required packages `pip install -r fprime/requirements.txt`
1. Install the arduino-cli
`curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | BINDIR=$VIRTUAL_ENV/bin sh`
1. Install the arduino-cli-wrapper `pip install arduino-cli-cmake-wrapper`
1. Install the RP2040 board
    ```sh
    arduino-cli config init
    arduino-cli config add board_manager.additional_urls https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
    arduino-cli core install rp2040:rp2040
    ```
1. Install additional arduino-cli dependencies:
    ```sh
    arduino-cli lib install Time
    arduino-cli lib install RadioHead
    ```

### Deploy onto the RP2040
1. Build the binary `fprime-util generate rpipico && fprime-util build rpipico -j20`
1. Move the binary from 'build-artifacts/rpipico/BroncoDeployment/bin/BroncoDeployment into the Proves board over USB after it has been intialized in boot loader mode (Press both Boot loader and Reset button at the same time). This should reinit the board automatically and will run the deployment.

Run GDS over serial:
1. `fprime-gds -n --dictionary build-artifacts/rpipico/BroncoDeployment/dict/BroncoDeploymentTopologyAppDictionary.xml --comm-adapter uart --uart-baud 115200 --uart-device /dev/ttyACM0 --output-unframed-data -`
- Be sure to replace '--uart-device /dev/ttyACM0' to the proper port you connect to the board!


## Building and Running the Deployment: Windows Guide

Getting started is easy! Please let us know if you run into any issues with the instructions below.

### Check your environment
You must have Python 3.9+ to build this repo. You can check with `python3 --version`

### Windows Subsystem for Linux (WSL) Install
If you don’t have Windows Subsystem for Linux (WSL) installed on your computer, you install it by opening Windows Powershell and typing `wsl –install`

After installation, search for an application on your PC called ‘Ubuntu’ and open. A terminal will open, and it may be accompanied with an error message.*

*If you have an error message, restart your machine. Upon restarting, open the Ubuntu app, and it should now work properly.

Proceed to enter a username and password. After you set up your profile, you are now able to use WSL.

A good first step with your new environment is to install new versions of packages available. In your WSL terminal, enter the command `sudo apt update && sudo apt upgrade` to install new packages for your WSL environment.

*Note: Your default Python3 installation in WSL may not come with 'venv', a package to create Python virtual environments. Enter `sudo apt install python3-venv` to install.

You are now set to go ahead and clone the repo. Clone the repo to your desired location and continue with the rest of the guide.

### Setup dependencies

1. Pull the fprime submodule `git submodule update --init --recursive`
1. Create a python venv `python3 -m venv fprime-venv`
1. Activate the venv `source fprime-venv/bin/activate`
1. Install required packages `pip install -r fprime/requirements.txt`
1. Install the arduino-cli
`curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | BINDIR=$VIRTUAL_ENV/bin sh`
1. Install the arduino-cli-wrapper `pip install arduino-cli-cmake-wrapper`
1. Install the RP2040 board
    ```sh
    arduino-cli config init
    arduino-cli config add board_manager.additional_urls https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
    arduino-cli core install rp2040:rp2040
    ```
1. Install additional arduino-cli dependencies:
    ```sh
    arduino-cli lib install Time
    arduino-cli lib install RadioHead
    ```
1. Install CMake

### Deploy onto the RP2040
1. Build the binary `fprime-util generate rpipico && fprime-util build rpipico -j20`
1. Move the binary from 'build-artifacts/rpipico/BroncoDeployment/bin/BroncoDeployment into the Proves board over USB after it has been intialized in boot loader mode (Press both Boot loader and Reset button at the same time). This should reinit the board automatically and will run the deployment.

Run GDS over serial:
1. `fprime-gds -n --dictionary build-artifacts/rpipico/BroncoDeployment/dict/BroncoDeploymentTopologyAppDictionary.xml --comm-adapter uart --uart-baud 115200 --uart-device /dev/ttyACM0 --output-unframed-data -`
- Be sure to replace '--uart-device /dev/ttyACM0' to the proper port you connect to the board!




