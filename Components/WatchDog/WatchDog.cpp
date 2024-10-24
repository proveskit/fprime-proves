// ======================================================================
// \title  Watchdog.cpp
// \author nateinaction
// \brief  cpp file for Watchdog component implementation class
// ======================================================================

#include "Components/Watchdog/Watchdog.hpp"
#include "FpConfig.hpp"

namespace Components {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

Watchdog ::Watchdog(const char* const compName) : WatchdogComponentBase(compName),
    on_state(false),
    cycle_count(0),
    pet_count(0)
{}

Watchdog ::~Watchdog() {}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

void Watchdog ::run_handler(NATIVE_INT_TYPE portNum, NATIVE_UINT_TYPE context) {
    // do we need an RTC implementation first? I guess not... we can use interval between rate group calls but it's not perfect
    // A non-RTC  implmentation will not allow us to check for drift because we only know about each cycle.
    U32 interval = 200;  // 20 seconds

    bool new_state = this->on_state;

    // Check for transitions
    if ((0 == this->cycle_count) && (this->on_state == false))
    {
        new_state = true;
    }
    else if ((this->cycle_count > 1) && (this->on_state == true))
    {
        new_state = false;
    }

    // A transition has occurred
    if (this->on_state != new_state)
    {
        // if (this->isConnected_gpioSet_OutputPort(25)) { // causes crash?
            // this->gpioSet_out(25, (true == new_state) ? Fw::Logic::HIGH : Fw::Logic::LOW);
        // }
        // causes crash
        // this->gpioSet_out(25, (true == new_state) ? Fw::Logic::HIGH : Fw::Logic::LOW);

        this->on_state = new_state;

        if (this->on_state == true) {
            this->pet_count = this->pet_count + 1;
            this->tlmWrite_WatchdogPets(pet_count);
        }
    }

    this->cycle_count = (this->cycle_count >= interval) ? 0 : (this->cycle_count + 1);
}

}  // namespace Components
