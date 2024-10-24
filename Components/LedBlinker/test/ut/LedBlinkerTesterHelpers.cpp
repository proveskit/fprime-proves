// ======================================================================
// \title  LedBlinkerTesterHelpers.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for LedBlinker component test harness helper functions
// ======================================================================

#include "LedBlinkerTester.hpp"

namespace Components {

// ----------------------------------------------------------------------
// Helper functions
// ----------------------------------------------------------------------

void LedBlinkerTester ::connectPorts() {
    // Connect special input ports

    this->connect_to_cmdIn(0, this->component.get_cmdIn_InputPort(0));

    // Connect special output ports

    this->component.set_cmdRegOut_OutputPort(0, this->get_from_cmdRegOut(0));

    this->component.set_cmdResponseOut_OutputPort(0, this->get_from_cmdResponseOut(0));

    this->component.set_logOut_OutputPort(0, this->get_from_logOut(0));

    this->component.set_logTextOut_OutputPort(0, this->get_from_logTextOut(0));

    this->component.set_prmGetOut_OutputPort(0, this->get_from_prmGetOut(0));

    this->component.set_prmSetOut_OutputPort(0, this->get_from_prmSetOut(0));

    this->component.set_timeCaller_OutputPort(0, this->get_from_timeCaller(0));

    this->component.set_tlmOut_OutputPort(0, this->get_from_tlmOut(0));

    // Connect typed input ports

    this->connect_to_run(0, this->component.get_run_InputPort(0));

    // Connect typed output ports

    this->component.set_neoPixelSet_OutputPort(0, this->get_from_neoPixelSet(0));
}

void LedBlinkerTester ::initComponents() {
    this->init();
    this->component.init(LedBlinkerTester::TEST_INSTANCE_QUEUE_DEPTH, LedBlinkerTester::TEST_INSTANCE_ID);
}

}  // namespace Components
