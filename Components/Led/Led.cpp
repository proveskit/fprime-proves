// ======================================================================
// \title  Led.cpp
// \author nateinaction
// \brief  cpp file for Led component implementation class
// ======================================================================

#include "Components/Led/Led.hpp"
#include "Components/Led/LedPinout.hpp"
#include "FpConfig.hpp"

namespace Components {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

#define NUMPIXELS 1
Led ::Led(const char* const compName) : LedComponentBase(compName),
    state(Fw::On::OFF),
    transitions(0),
    count(0),
    blinking(true),
    pixels(NUMPIXELS, NEO_PWR, NEO_GRB + NEO_KHZ800)
{
}

Led ::~Led() {}

// ----------------------------------------------------------------------
// Handler implementations for user-defined typed input ports
// ----------------------------------------------------------------------

    void Led ::
        run_handler(
            const NATIVE_INT_TYPE portNum,
            NATIVE_UINT_TYPE context)
    {
        // Read back the parameter value
        Fw::ParamValid isValid;
        U32 interval = this->paramGet_BLINK_INTERVAL(isValid);

        // Force interval to be 0 when invalid or not set
        interval = ((Fw::ParamValid::INVALID == isValid) || (Fw::ParamValid::UNINIT == isValid)) ? 0 : interval;

        // Only perform actions when set to blinking
        bool is_blinking = this->blinking;
        if (is_blinking)
        {
            Fw::On new_state = this->state;
            // Check for transitions
            if ((0 == this->count) && (this->state == Fw::On::OFF))
            {
                new_state = Fw::On::ON;
                pixels.begin();
                pixels.setPixelColor(1, pixels.Color(0, 150, 0));
            }
            else if (((interval / 2) == this->count) && (this->state == Fw::On::ON))
            {
                new_state = Fw::On::OFF;
                pixels.clear();
            }

            // A transition has occurred
            if (this->state != new_state)
            {
                this->transitions = this->transitions + 1;

                // Report the number of LED transitions (this->transitions)
                this->tlmWrite_LedTransitions(this->transitions);

                // Port may not be connected, so check before sending output
                if (this->isConnected_gpioSet_OutputPort(0))
                {
                    this->gpioSet_out(0, (Fw::On::ON == new_state) ? Fw::Logic::HIGH : Fw::Logic::LOW);
                }

                this->state = new_state;
                this->tlmWrite_BlinkingState(this->state);
            }

            this->count = ((this->count + 1) >= interval) ? 0 : (this->count + 1);
        }
        else
        {
          if(this->state == Fw::On::ON)
          {
            // Port may not be connected, so check before sending output
            if (this->isConnected_gpioSet_OutputPort(0))
            {
              this->gpioSet_out(0, Fw::Logic::LOW);
            }

            this->state = Fw::On::OFF;
            
            this->tlmWrite_BlinkingState(this->state);
          }
        }
    }

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void Led ::
    BLINKING_ON_OFF_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        Fw::On on_off
    )
  {
    // Create a variable to represent the command response
    auto cmdResp = Fw::CmdResponse::OK;

    // Verify if on_off is a valid argument.
    // Note: isValid is an autogenerate helper function for enums defined in fpp.
    if(!on_off.isValid())
    {
        // Indicates we received an invalid argument.
        this->log_WARNING_LO_InvalidBlinkArgument(on_off);

        // Update command response with a validation error
        cmdResp = Fw::CmdResponse::VALIDATION_ERROR;
    }
    else
    {
        this->count = 0; // Reset count on any successful command
        this->blinking = Fw::On::ON == on_off; // Update blinking state

        // Reports the state we set to blinking.
        this->log_ACTIVITY_HI_SetBlinkingState(on_off);

        // Report the blinking state via a telemetry channel.
        this->tlmWrite_BlinkingState(on_off);
    }

    // Provide command response
    this->cmdResponse_out(opCode,cmdSeq,cmdResp);
  }

  void Led ::parameterUpdated(FwPrmIdType id) {
    // Read back the parameter value
    Fw::ParamValid isValid;
    U32 interval = this->paramGet_BLINK_INTERVAL(isValid);
    // NOTE: isValid is always VALID in parameterUpdated as it was just properly set
    FW_ASSERT(isValid == Fw::ParamValid::VALID, isValid);

    // Check the parameter ID is expected
    if (PARAMID_BLINK_INTERVAL == id) {
        // Emit the blink interval set event
        this->log_ACTIVITY_HI_BlinkIntervalSet(interval);
    }
}

}  // namespace Components
