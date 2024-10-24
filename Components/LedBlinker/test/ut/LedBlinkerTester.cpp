// ======================================================================
// \title  LedBlinkerTester.cpp
// \author nate
// \brief  cpp file for LedBlinker component test harness implementation class
// ======================================================================

#include "LedBlinkerTester.hpp"

namespace Components {

// ----------------------------------------------------------------------
// Construction and destruction
// ----------------------------------------------------------------------

LedBlinkerTester ::LedBlinkerTester()
    : LedBlinkerGTestBase("LedBlinkerTester", LedBlinkerTester::MAX_HISTORY_SIZE), component("LedBlinker") {
    this->initComponents();
    this->connectPorts();
}

LedBlinkerTester ::~LedBlinkerTester() {}

// ----------------------------------------------------------------------
// Tests
// ----------------------------------------------------------------------

void LedBlinkerTester ::testBlinking() {
    // This test will make use of parameters. So need to load them.
    this->component.loadParameters();

    // Ensure LED stays off when blinking is disabled
    // The Led component defaults to blinking off
    this->invoke_to_run(0, 0);     // invoke the 'run' port to simulate running one cycle
    this->component.doDispatch();  // Trigger execution of async port

    ASSERT_EVENTS_SetBlinkingState_SIZE(0);  // ensure no LedState change events we emitted

    ASSERT_from_neoPixelSet_SIZE(0);  // ensure gpio LED wasn't set

    ASSERT_TLM_LedBlinks_SIZE(0);  // ensure no LedTransitions were recorded
}

// ----------------------------------------------------------------------
// Handlers for typed from ports
// ----------------------------------------------------------------------

void LedBlinkerTester ::from_neoPixelSet_handler(NATIVE_INT_TYPE portNum,
                                                 const Fw::On& on_off,
                                                 U8 red,
                                                 U8 green,
                                                 U8 blue) {
    // TODO
}

}  // namespace Components
