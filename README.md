# F´ PROVES
[![build](https://github.com/proveskit/fprime-proves/actions/workflows/build.yaml/badge.svg)](https://github.com/proveskit/fprime-proves/actions/workflows/build.yaml)

F´ (F Prime) flight software for the PROVES CubeSat Kit. This version of the PROVES flight software is under development and is not ready to be used with flight hardware. Please see [proveskit/flight_software](https://github.com/proveskit/flight_software/) for our latest flight ready software.

## Building and Running the Deployment

Getting started is easy! Please let us know if you run into any issues with the instructions below.

### Check your environment
You must have Python 3.9+ to build this repo. You can check with:
```sh
python3 --version
```

### Setup dependencies

1. Pull the fprime submodule
   ```sh
   git submodule update --init --recursive
   ```
2. Create a python venv
   ```sh
   python3 -m venv fprime-venv
   ```
3. Activate the venv
   ```sh
   . fprime-venv/bin/activate
   ```
4. Install required packages
   ```sh
   pip install -r fprime/requirements.txt
   ```
5. Install the arduino-cli
    ```sh
    curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | BINDIR=$VIRTUAL_ENV/bin sh
    ```
6. Install the arduino-cli-wrapper
   ```sh
   pip install arduino-cli-cmake-wrapper
   ```
7. Install the RP2040 board
    ```sh
    arduino-cli config init
    ```
    ```sh
    arduino-cli config add board_manager.additional_urls https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
    ```
    ```sh
    arduino-cli core install rp2040:rp2040@3.9.5
    ```
8. Install additional arduino-cli dependencies:
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
