// ======================================================================
// \title  ChessDriver.hpp
// \author alandlt
// \brief  hpp file for ChessDriver component implementation class
// ======================================================================

#ifndef Drv_ChessDriver_HPP
#define Drv_ChessDriver_HPP

#include "Components/Drv/ChessDriver/ChessDriverComponentAc.hpp"
#include "lib/chess-library/include/chess.hpp"
using namespace chess;

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
          const Drv::Location& startPos,
          const Drv::Location& endPos
      ) override;

      Square::underlying convert (Drv.Location pos);

      PRIVATE:
      Board board = Board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

  };

}

#endif
