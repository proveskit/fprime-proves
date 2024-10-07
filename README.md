# F´ PROVES
[![build](https://github.com/proveskit/fprime-proves/actions/workflows/build.yaml/badge.svg)](https://github.com/proveskit/fprime-proves/actions/workflows/build.yaml)

F´ (F Prime) flight software for the PROVES CubeSat Kit. This version of the PROVES flight software is under development and is not ready to be used with flight hardware. Please see [proveskit/flight_software](https://github.com/proveskit/flight_software/) for our latest flight ready software.

**Note**: This guide features setup for both Linux/macOS and Windows (through the use of WSL). There will be a section specific to only Windows users, as well as a common section where steps will apply to both groups (Linux/macOS and Windows). If you are a Linux/macOS user, you can go straight to the [Common Section](#common-section-linuxmacos-and-windows).

## Windows Specific Section
### Windows Subsystem for Linux (WSL) Install
If you don’t have Windows Subsystem for Linux (WSL) installed on your computer, install it by opening Windows Powershell and typing 
```sh
wsl –install
```

After installation, search for an application on your PC called ‘Ubuntu’ and open. A terminal will open, and it may be accompanied with an error message.*

*If you have an error message, restart your machine. Upon restarting, open the Ubuntu app, and it should now work properly.

Proceed to enter a username and password. After you set up your profile, you are now able to use WSL.

A good first step with your new environment is to install new versions of packages available. In your WSL terminal, the folowing command will install new packages for your WSL environment. 
```sh
sudo apt update && sudo apt upgrade
```

Note: Your default Python3 installation in WSL may not come with 'venv', a package to create Python virtual environments. To install, enter 
```sh
sudo apt install python3-venv
```

For some of us on WSL, the default download of CMake using apt resulted in build errors, but the latest version was able to allow for succesful builds. We recommend downloading the latest version of CMake.
   ```sh
   wget -qO- https://github.com/Kitware/CMake/releases/download/v3.30.4/cmake-3.30.4-linux-x86_64.tar.gz | tar xzv && sudo mv cmake-3.30.4-linux-x86_64/bin/* /usr/local/bin && rm -r cmake-3.30.4-linux-x86_64
   ```
## Common Section (Linux/macOS and Windows)
### Building and Running the Deployment:

Getting started is easy! Please let us know if you run into any issues with the instructions below.

### Check your environment
You must have Python 3.9+ and Git to build this repo. You can check with:
```sh
python3 --version
```
```sh
git --version
```
> **Note**: If you do not have these downloaded to your device, please download [Git](https://git-scm.com/downloads) and [Python](https://www.python.org/downloads/).

### Cloning this repository
1. Open your terminal or command prompt
   
3. Navigate to the location you want to clone the repository to using:
   ```sh
   cd example/path/to/the/repo/location/
   ```
   > **Note**: 'example/path/to/the/repo/location' is a placeholder for the path to the location you wish to put the repo
   
4. To clone the repository, use the following in your terminal or command prompt:
   ```sh
   git clone https://github.com/proveskit/fprime-proves.git
   ```
5. Once the repository is finished downloading, navigate into the fprime-proves directory:
   ```sh
   cd fprime-proves/
   ```

### Setup dependencies

1. Pull the fprime submodule 
    ```sh
    git submodule update --init --recursive
    ```
1. Create a python venv 
   ```sh
   python3 -m venv fprime-venv
   ```
1. Activate the venv 
    ```sh
    source fprime-venv/bin/activate
    ```
1. Install required packages 
   ```sh
   pip install -r fprime/requirements.txt
   ```
2. Install the arduino-cli
   ```sh
   curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | BINDIR=$VIRTUAL_ENV/bin sh
   ```
1. 
   Install the arduino-cli-wrapper 
   ```sh
   pip install arduino-cli-cmake-wrapper
   ```
2. Install the RP2040 board
    ```sh
    arduino-cli config init
    ```
    ```sh
    arduino-cli config add board_manager.additional_urls https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
    ```
    ```sh
    arduino-cli core install rp2040:rp2040@3.9.5
    ```
3. Install additional arduino-cli dependencies:
    ```sh
    arduino-cli lib install Time
    ```
    ```sh
    arduino-cli lib install RadioHead
    ```

### Deploy onto the RP2040
1. Build the binary
   ```sh
   fprime-util generate rpipico && fprime-util build rpipico -j20
   ```
2. Move the binary from 'build-artifacts/rpipico/BroncoDeployment/bin/BroncoDeployment' into the Proves board over USB after it has been intialized in boot loader mode (Press both Boot loader and Reset button at the same time). This should reinit the board automatically and will run the deployment.

3. Run GDS over serial:
   ```sh
   fprime-gds -n --dictionary build-artifacts/rpipico/BroncoDeployment/dict/BroncoDeploymentTopologyAppDictionary.xml --comm-adapter uart --uart-baud 115200 --uart-device /dev/ttyACM0 --output-unframed-data -
   ```
    > **Note:** Be sure to replace '--uart-device /dev/ttyACM0' to the proper port you connect to the board!
