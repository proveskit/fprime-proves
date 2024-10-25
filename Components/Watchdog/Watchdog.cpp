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

Watchdog ::Watchdog(const char* const compName) : WatchdogComponentBase(compName) {}

Watchdog ::~Watchdog() {}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

void Watchdog ::run_handler(NATIVE_INT_TYPE portNum, NATIVE_UINT_TYPE context) {
    // TODO (nateinaction): Convet this to use the gpio output port when it works...
    digitalWrite(21, (this->cycle_count % 2) == 0 ? HIGH : LOW);

    this->pet_count += (this->cycle_count % 2) == 0 ? 1 : 0;
    this->tlmWrite_WatchdogPets(pet_count);

    this->cycle_count += 1;
}

}  // namespace Components
