// ======================================================================
// \title  LedBlinkerTester.hpp
// \author nate
// \brief  hpp file for LedBlinker component test harness implementation class
// ======================================================================

#ifndef Components_LedBlinkerTester_HPP
#define Components_LedBlinkerTester_HPP

#include "Components/LedBlinker/LedBlinker.hpp"
#include "Components/LedBlinker/LedBlinkerGTestBase.hpp"

namespace Components {

class LedBlinkerTester : public LedBlinkerGTestBase {
  public:
    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    // Maximum size of histories storing events, telemetry, and port outputs
    static const NATIVE_INT_TYPE MAX_HISTORY_SIZE = 10;

    // Instance ID supplied to the component instance under test
    static const NATIVE_INT_TYPE TEST_INSTANCE_ID = 0;

    // Queue depth supplied to the component instance under test
    static const NATIVE_INT_TYPE TEST_INSTANCE_QUEUE_DEPTH = 10;

  public:
    // ----------------------------------------------------------------------
    // Construction and destruction
    // ----------------------------------------------------------------------

    //! Construct object LedBlinkerTester
    LedBlinkerTester();

    //! Destroy object LedBlinkerTester
    ~LedBlinkerTester();

  public:
    // ----------------------------------------------------------------------
    // Tests
    // ----------------------------------------------------------------------

    //! To do
    void testBlinking();

  private:
    // ----------------------------------------------------------------------
    // Handlers for typed from ports
    // ----------------------------------------------------------------------

    //! Handler implementation for neoPixelSet
    void from_neoPixelSet_handler(NATIVE_INT_TYPE portNum,  //!< The port number
                                  const Fw::On& on_off,
                                  U8 red,
                                  U8 green,
                                  U8 blue);

  private:
    // ----------------------------------------------------------------------
    // Helper functions
    // ----------------------------------------------------------------------

    //! Connect ports
    void connectPorts();

    //! Initialize components
    void initComponents();

  private:
    // ----------------------------------------------------------------------
    // Member variables
    // ----------------------------------------------------------------------

    //! The component under test
    LedBlinker component;
};

}  // namespace Components

#endif
