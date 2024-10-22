// ======================================================================
// \title  Watchdog.hpp
// \author nate
// \brief  hpp file for Watchdog component implementation class
// ======================================================================

#ifndef Components_Watchdog_HPP
#define Components_Watchdog_HPP

#include "Components/Watchdog/WatchdogComponentAc.hpp"

namespace Components {

class Watchdog : public WatchdogComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct Watchdog object
    Watchdog(const char* const compName  //!< The component name
    );

    //! Destroy Watchdog object
    ~Watchdog();

  PRIVATE:
    // ----------------------------------------------------------------------
    // Handler implementations for user-defined typed input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for run
    //!
    //! Port receiving calls from the rate group
    void run_handler(NATIVE_INT_TYPE portNum,  //!< The port number
                     NATIVE_UINT_TYPE context  //!< The call order
                     ) override;
  
  PRIVATE:
    bool on_state = false;
    U64 pet_count = 0;
    U32 cycle_count = 0;
};

}  // namespace Components

#endif
