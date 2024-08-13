# fprime-proves F' project
Valid for F' 3.4.3

## Building and Running the Deployment
Ensure that you have a proper fprime-venv setup!

To deploy onto the RP2040, do the following steps:
> fprime-util generate rpipico && fprime-util build rpipico -j20
- Move the binary from 'build-artifacts/rpipico/BroncoDeployment/bin/BroncoDeployment into the Proves board over USB after it has been intiialized in boot loader mode (Press both Boot loader and Reset button at the same time). This should reinit the board automatically and will run the deployment.

To run GDS over serial:
> fprime-gds -n --dictionary build-artifacts/rpipico/BroncoDeployment/dict/BroncoDeploymentTopologyAppDictionary.xml --comm-adapter uart --uart-baud 115200 --uart-device /dev/ttyACM0 --output-unframed-data -
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
