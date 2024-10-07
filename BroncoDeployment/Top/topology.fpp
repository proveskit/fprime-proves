module BroncoDeployment {

  # ----------------------------------------------------------------------
  # Symbolic constants for port numbers
  # ----------------------------------------------------------------------

    enum Ports_RateGroups {
      rateGroup1
    }

    enum Ports_StaticMemory {
      framer
      deframer
      deframing
    }

  topology BroncoDeployment {

    # ----------------------------------------------------------------------
    # Instances used in the topology
    # ----------------------------------------------------------------------

    instance helloWorld
    instance cmdDisp
    instance commDriver
    instance deframer
    instance eventLogger
    instance fatalAdapter
    instance fatalHandler
    instance framer
    instance rateDriver
    instance rateGroup1
    instance rateGroupDriver
    instance systemResources
    instance textLogger
    instance timeHandler
    instance tlmSend

    #hub instances
    instance hub
    instance hubDeframer
    instance hubFramer
    instance hubComDriver
    instance bufferManager

    #custom instances
    instance broncoOreMessageHandler 

    # ----------------------------------------------------------------------
    # Pattern graph specifiers
    # ----------------------------------------------------------------------

    command connections instance cmdDisp

    event connections instance eventLogger

    telemetry connections instance tlmSend

    text event connections instance textLogger

    time connections instance timeHandler

    # ----------------------------------------------------------------------
    # Direct graph specifiers
    # ----------------------------------------------------------------------

    connections RateGroups {
      # Block driver
      rateDriver.CycleOut -> rateGroupDriver.CycleIn

      # Rate group 1
      rateGroupDriver.CycleOut[Ports_RateGroups.rateGroup1] -> rateGroup1.CycleIn
      rateGroup1.RateGroupMemberOut[0] -> commDriver.schedIn
      rateGroup1.RateGroupMemberOut[1] -> tlmSend.Run
      rateGroup1.RateGroupMemberOut[2] -> systemResources.run
    }

    connections FaultProtection {
      eventLogger.FatalAnnounce -> fatalHandler.FatalReceive
    }

    connections Downlink {

      tlmSend.PktSend -> framer.comIn
      eventLogger.PktSend -> framer.comIn

      framer.framedAllocate -> bufferManager.bufferGetCallee
      framer.framedOut -> commDriver.$send

      commDriver.deallocate -> bufferManager.bufferSendIn

    }
    
    connections Uplink {

      commDriver.allocate -> bufferManager.bufferGetCallee
      commDriver.$recv -> deframer.framedIn
      deframer.framedDeallocate -> bufferManager.bufferSendIn

      deframer.comOut -> cmdDisp.seqCmdBuff
      cmdDisp.seqCmdStatus -> deframer.cmdResponseIn

      deframer.bufferAllocate -> bufferManager.bufferGetCallee
      deframer.bufferDeallocate -> bufferManager.bufferSendIn
      
    }

    connections BroncoDeployment {
      # Add here connections to user-defined components
      broncoOreMessageHandler.send_message -> hub.portIn[0]
      hub.portOut[0] -> broncoOreMessageHandler.recv_message 
    }
    
    connections HubConnections {

      hub.dataOut -> hubFramer.bufferIn
      hub.dataOutAllocate -> bufferManager.bufferGetCallee
      hubFramer.bufferDeallocate -> bufferManager.bufferSendIn
      hubFramer.framedAllocate -> bufferManager.bufferGetCallee
      hubFramer.framedOut -> hubComDriver.comDataIn
      hubComDriver.deallocate -> bufferManager.bufferSendIn

      hubComDriver.allocate -> bufferManager.bufferGetCallee
      hubComDriver.comDataOut -> hubDeframer.framedIn
      hubDeframer.framedDeallocate -> bufferManager.bufferSendIn
      hubDeframer.bufferAllocate -> bufferManager.bufferGetCallee
      hubDeframer.bufferOut -> hub.dataIn
      hub.dataInDeallocate -> bufferManager.bufferSendIn
    }
  }

}
