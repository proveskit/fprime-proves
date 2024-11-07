// ======================================================================
// \title  LedBlinker.hpp
// \author nateinaction
// \brief  hpp file for LedBlinker component implementation class
// ======================================================================

#ifndef Components_LedBlinker_HPP
#define Components_LedBlinker_HPP

#include "Components/LedBlinker/LedBlinkerComponentAc.hpp"

namespace Components {

class LedBlinker : public LedBlinkerComponentBase {
  public:
    // ----------------------------------------------------------------------
    // Component construction and destruction
    // ----------------------------------------------------------------------

    //! Construct LedBlinker object
    LedBlinker(const char* const compName  //!< The component name
    );

    //! Destroy LedBlinker object
    ~LedBlinker();

  private:
    // ----------------------------------------------------------------------
    // Handler implementations for user-defined typed input ports
    // ----------------------------------------------------------------------

    //! Handler implementation for run
    //!
    //! Port receiving calls from the rate group
    void run_handler(NATIVE_INT_TYPE portNum,  //!< The port number
                     NATIVE_UINT_TYPE context  //!< The call order
                     ) override;

    // ----------------------------------------------------------------------
    // Handler implementations for commands
    // ----------------------------------------------------------------------

    //! Implementation for BLINKING_ON_OFF command handler
    //! Command to turn on or off the blinking LED
    void BLINKING_ON_OFF_cmdHandler(FwOpcodeType opCode,   //!< The opcode
                                    U32 cmdSeq,            //!< The command sequence number
                                    Fw::On blinking_state  //!< Color to blink
                                    ) override;

    //! Emit parameter updated EVR
    //!
    void parameterUpdated(FwPrmIdType id /*!< The parameter ID*/
    );

    //! Validate and set the color parameter on update
    //!
    void parameterValidateColor(
    );

    //! Validate and set the interval parameter on update
    //!
    void parameterValidateInterval(
    );

    //! Choose the color to blink
    //!
    Drv::NeoPixelColor colorParamOrDefault(
    );

    //! Choose the interval to blink
    //!
    U32 intervalParamOrDefault(
    );

    //! The LED blinker behavior
    //!
    void blink(
    );

    // Private member variables
    Fw::On blinkingState;  //!< Whether the LED is blinking or not
    U64 blinkCount;  //! The number of on/off transitions that have occurred from FSW boot up
    U32 cycleCount;  //! Keeps track of how many ticks the LED has been on for
};

}  // namespace Components

#endif
