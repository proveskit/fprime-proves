// ======================================================================
// \title  MicroChessDriver.hpp
// \author alandlt
// \brief  hpp file for MicroChessDriver component implementation class
// ======================================================================

#ifndef Drv_MicroChessDriver_HPP
#define Drv_MicroChessDriver_HPP

#include "Components/Drv/MicroChessDriver/MicroChessDriverComponentAc.hpp"

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

  };

}

#endif
