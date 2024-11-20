// ======================================================================
// \title  ChessDriver.cpp
// \author alandlt
// \brief  cpp file for ChessDriver component implementation class
// ======================================================================

#include "Components/Drv/ChessDriver/ChessDriver.hpp"
#include "FpConfig.hpp"
using namespace chess;
namespace Drv {

  // ----------------------------------------------------------------------
  // Component construction and destruction
  // ----------------------------------------------------------------------

  ChessDriver ::
    ChessDriver(const char* const compName) :
      ChessDriverComponentBase(compName)
  {
      
  }

  ChessDriver ::
    ~ChessDriver()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  Square::underlying convert (Drv::Location pos) {
      switch (pos) {
        case Drv::Location::SQ_A1: return Square::underlying::SQ_A1;
        case Drv::Location::SQ_B1: return Square::underlying::SQ_B1;
        case Drv::Location::SQ_C1: return Square::underlying::SQ_C1;
        case Drv::Location::SQ_D1: return Square::underlying::SQ_D1;
        case Drv::Location::SQ_E1: return Square::underlying::SQ_E1;
        case Drv::Location::SQ_F1: return Square::underlying::SQ_F1;
        case Drv::Location::SQ_G1: return Square::underlying::SQ_G1;
        case Drv::Location::SQ_H1: return Square::underlying::SQ_H1;
        case Drv::Location::SQ_A2: return Square::underlying::SQ_A2;
        case Drv::Location::SQ_B2: return Square::underlying::SQ_B2;
        case Drv::Location::SQ_C2: return Square::underlying::SQ_C2;
        case Drv::Location::SQ_D2: return Square::underlying::SQ_D2;
        case Drv::Location::SQ_E2: return Square::underlying::SQ_E2;
        case Drv::Location::SQ_F2: return Square::underlying::SQ_F2;
        case Drv::Location::SQ_G2: return Square::underlying::SQ_G2;
        case Drv::Location::SQ_H2: return Square::underlying::SQ_H2;
        case Drv::Location::SQ_A3: return Square::underlying::SQ_A3;
        case Drv::Location::SQ_B3: return Square::underlying::SQ_B3;
        case Drv::Location::SQ_C3: return Square::underlying::SQ_C3;
        case Drv::Location::SQ_D3: return Square::underlying::SQ_D3;
        case Drv::Location::SQ_E3: return Square::underlying::SQ_E3;
        case Drv::Location::SQ_F3: return Square::underlying::SQ_F3;
        case Drv::Location::SQ_G3: return Square::underlying::SQ_G3;
        case Drv::Location::SQ_H3: return Square::underlying::SQ_H3;
        case Drv::Location::SQ_A4: return Square::underlying::SQ_A4;
        case Drv::Location::SQ_B4: return Square::underlying::SQ_B4;
        case Drv::Location::SQ_C4: return Square::underlying::SQ_C4;
        case Drv::Location::SQ_D4: return Square::underlying::SQ_D4;
        case Drv::Location::SQ_E4: return Square::underlying::SQ_E4;
        case Drv::Location::SQ_F4: return Square::underlying::SQ_F4;
        case Drv::Location::SQ_G4: return Square::underlying::SQ_G4;
        case Drv::Location::SQ_H4: return Square::underlying::SQ_H4;
        case Drv::Location::SQ_A5: return Square::underlying::SQ_A5;
        case Drv::Location::SQ_B5: return Square::underlying::SQ_B5;
        case Drv::Location::SQ_C5: return Square::underlying::SQ_C5;
        case Drv::Location::SQ_D5: return Square::underlying::SQ_D5;
        case Drv::Location::SQ_E5: return Square::underlying::SQ_E5;
        case Drv::Location::SQ_F5: return Square::underlying::SQ_F5;
        case Drv::Location::SQ_G5: return Square::underlying::SQ_G5;
        case Drv::Location::SQ_H5: return Square::underlying::SQ_H5;
        case Drv::Location::SQ_A6: return Square::underlying::SQ_A6;
        case Drv::Location::SQ_B6: return Square::underlying::SQ_B6;
        case Drv::Location::SQ_C6: return Square::underlying::SQ_C6;
        case Drv::Location::SQ_D6: return Square::underlying::SQ_D6;
        case Drv::Location::SQ_E6: return Square::underlying::SQ_E6;
        case Drv::Location::SQ_F6: return Square::underlying::SQ_F6;
        case Drv::Location::SQ_G6: return Square::underlying::SQ_G6;
        case Drv::Location::SQ_H6: return Square::underlying::SQ_H6;
        case Drv::Location::SQ_A7: return Square::underlying::SQ_A7;
        case Drv::Location::SQ_B7: return Square::underlying::SQ_B7;
        case Drv::Location::SQ_C7: return Square::underlying::SQ_C7;
        case Drv::Location::SQ_D7: return Square::underlying::SQ_D7;
        case Drv::Location::SQ_E7: return Square::underlying::SQ_E7;
        case Drv::Location::SQ_F7: return Square::underlying::SQ_F7;
        case Drv::Location::SQ_G7: return Square::underlying::SQ_G7;
        case Drv::Location::SQ_H7: return Square::underlying::SQ_H7;
        case Drv::Location::SQ_A8: return Square::underlying::SQ_A8;
        case Drv::Location::SQ_B8: return Square::underlying::SQ_B8;
        case Drv::Location::SQ_C8: return Square::underlying::SQ_C8;
        case Drv::Location::SQ_D8: return Square::underlying::SQ_D8;
        case Drv::Location::SQ_E8: return Square::underlying::SQ_E8;
        case Drv::Location::SQ_F8: return Square::underlying::SQ_F8;
        case Drv::Location::SQ_G8: return Square::underlying::SQ_G8;
        case Drv::Location::SQ_H8: return Square::underlying::SQ_H8;
        case Drv::Location::NO_SQ: return Square::underlying::NO_SQ;
        default: return Square::underlying::NO_SQ;
      }
      return Square::underlying::NO_SQ;
  }

  Drv::displayBoardPortStrings::StringSize80 ChessDriver ::
    displayBoard_handler(NATIVE_INT_TYPE portNum)
  {
    return board.getFen(bool movec = true);
  }
  
  void ChessDriver ::
    movePiece_handler(
        NATIVE_INT_TYPE portNum,
        const Drv::Location& startPos,
        const Drv::Location& endPos
    )
  {
    Square::underlying start = convert(startPos);
    Square::underlying end = convert(endPos);
    Move m = Move::make<Move::NORMAL>(start, end);
    board.makeMove(m);
  }

}
