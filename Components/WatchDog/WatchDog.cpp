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
    pet_count(0)
{}

Watchdog ::~Watchdog() {}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

void Watchdog ::run_handler(NATIVE_INT_TYPE portNum, NATIVE_UINT_TYPE context) {
    digitalWrite(21, HIGH);
    delay(100);
    digitalWrite(21, LOW);
    this->pet_count = this->pet_count + 1;
    this->tlmWrite_WatchdogPets(pet_count);
}

}  // namespace Components
