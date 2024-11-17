// ======================================================================
// \title  MicroChessDriver.hpp
// \author alandlt
// \brief  hpp file for MicroChessDriver component implementation class
// ======================================================================

#ifndef Drv_MicroChessDriver_HPP
#define Drv_MicroChessDriver_HPP

#include "Components/Drv/MicroChessDriver/MicroChessDriverComponentAc.hpp"
#include "lib/MicroChess/MicroChess.h"
#include "lib/MicroChess/board.h"
#include "lib/MicroChess/game.h"

namespace Drv {

  class MicroChessDriver :
    public MicroChessDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct MicroChessDriver object
      MicroChessDriver(
          const char* const compName //!< The component name
      );

      //! Destroy MicroChessDriver object
      ~MicroChessDriver();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for BoardState
      void BoardState_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          const Drv::BoardStatePortStrings::StringSize20& state
      ) override;

      //! Handler implementation for MoveRequest
      void MoveRequest_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          U32 startPosition, //!< changed to unsigned 32 bit int
          U32 endPosition
      ) override;

      PRIVATE:
      //MicroChess microChess; <planned to use setup() but runs main loop automatically
      board_t board;
      game_t game;
      
  };

}

#endif

