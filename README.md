# fprime-proves F' project
[![build](https://github.com/proveskit/fprime-proves/actions/workflows/build.yaml/badge.svg)](https://github.com/proveskit/fprime-proves/actions/workflows/build.yaml)

Valid for F' 3.4.3

## Building and Running the Deployment

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
1. Move the binary from 'build-artifacts/rpipico/BroncoDeployment/bin/BroncoDeployment into the Proves board over USB after it has been intiialized in boot loader mode (Press both Boot loader and Reset button at the same time). This should reinit the board automatically and will run the deployment.

Run GDS over serial:
1. `fprime-gds -n --dictionary build-artifacts/rpipico/BroncoDeployment/dict/BroncoDeploymentTopologyAppDictionary.xml --comm-adapter uart --uart-baud 115200 --uart-device /dev/ttyACM0 --output-unframed-data -`
- Be sure to replace '--uart-device /dev/ttyACM0' to the proper port you connect to the board!


## Development Notes:
- Do NOT use the devel branch! The os layer has been updated and does not sit correctly with the fprime-arduino
- Do the following BEFORE you make a deployment:
- Insert fprime-arduino into your project
- Reference it in your settings.ini
```
library_locations: ./fprime-arduino
default_toolchains: rpipico
deployment_cookiecutter: https://github.com/fprime-community/fprime-arduino-deployment-cookiecutter.git
```
Follow Arduino CLI Installation
> pip install arduino-cli-cmake-wrapper

> arduino-cli core install rp2040:rp2040

"BroncoDeployment" is currently the only deployment able to run on the Proves RP2040.






F´ (F Prime) is a component-driven framework that enables rapid development and deployment of spaceflight and other embedded software applications.
**Please Visit the F´ Website:** https://fprime.jpl.nasa.gov.
