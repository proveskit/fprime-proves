// ======================================================================
// \title  ChessDriver.hpp
// \author alandlt
// \brief  hpp file for ChessDriver component implementation class
// ======================================================================

#ifndef Drv_ChessDriver_HPP
#define Drv_ChessDriver_HPP

#include "Components/Drv/ChessDriver/ChessDriverComponentAc.hpp"
#include "lib/chess/main.cpp"
#include "lib/chess/game.h"
#include "lib/chess/board.h"

namespace Drv {

  class ChessDriver :
    public ChessDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct ChessDriver object
      ChessDriver(
          const char* const compName //!< The component name
      );

      //! Destroy ChessDriver object
      ~ChessDriver();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for movePiece
      void movePiece_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          U32 startPos,
          U32 endPos
      ) override;
      
  };

}

#endif
