#
# OMNeT++/OMNEST Makefile for PhoenixSim
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -LC:\omnetpp-4.5\matlab-link -LC:/Users/Lebiednik/Documents/GT_Grad_School/Information_Security_Practicum/omnetpp-4.5-src-windows/omnetpp-4.5/win32 -lmat -lmx
#

# Name of target to be created (-o option)
TARGET = PhoenixSim$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -Iaddon \
    -Iaddon/HotSpot-5.0 \
    -IchipComponents \
    -Idata \
    -IelectronicComponents \
    -IelectronicComponents/Arbiters \
    -IelectronicComponents/MAC_Layer \
    -IelectronicComponents/PHY_Layer \
    -IelectronicComponents/orion \
    -IelectronicComponents/orion/ORION_1_Params \
    -IelectronicComponents/orion/ORION_2_Params \
    -Iimages \
    -Iimages/components \
    -Iimages/components/old \
    -Iimages/mitucb \
    -Iimages/planes \
    -IioComponents \
    -IioComponents/DRAM_LRL \
    -IioComponents/DRAMsim \
    -IioComponents/DRAMsim/mem_system_def \
    -Iparameters \
    -Iparameters/Hendry-Thesis \
    -Iparameters/custom \
    -Iparameters/default \
    -Iphotonic \
    -Iphotonic/PhotoCAD \
    -Iphotonic/devices \
    -Iphotonic/devices/machzehnder \
    -Iphotonic/devices/multiring \
    -Iphotonic/switches \
    -Iphotonic/switches/machzehnder \
    -Iphotonic/switches/multiring \
    -IprocessingPlane \
    -IprocessingPlane/DRAM_Cfg \
    -IprocessingPlane/addressTranslation \
    -IprocessingPlane/apps \
    -IprocessingPlane/apps/DRAM \
    -IprocessingPlane/apps/MITUCB \
    -IprocessingPlane/apps/SizeDistribution \
    -IprocessingPlane/apps/model \
    -IprocessingPlane/apps/synthetics \
    -IprocessingPlane/apps/test \
    -IprocessingPlane/apps/trace \
    -IprocessingPlane/interfaces \
    -IprocessingPlane/trafficGenerator \
    -Iresults \
    -Iresults/old \
    -Iresults/old/baseline17SEP1031 \
    -Iresults/old/baseline64_19SEP \
    -Iresults/old/baseline64_core_17SEP \
    -Iresults/old/broadcast100 \
    -Iresults/old/test017SEP1122 \
    -Iresults/old/wrong \
    -Iresults/old2 \
    -Iresults/old3 \
    -IsimCore \
    -Istatistics \
    -Istatistics/statGroups \
    -Istatistics/statObjects \
    -Istatistics/statObjects/energy \
    -Itopologies \
    -Itopologies/ButterflyFatTree \
    -Itopologies/CMesh \
    -Itopologies/HybridWEMesh \
    -Itopologies/WirelessMesh \
    -Itopologies/blockingTorus \
    -Itopologies/electronic3DMesh \
    -Itopologies/electronicMesh \
    -Itopologies/electronicMesh_Circuit \
    -Itopologies/electronicRing \
    -Itopologies/electronicTorus \
    -Itopologies/flattenedButterfly \
    -Itopologies/nonblockingSiliconNitride \
    -Itopologies/nonblockingTorus \
    -Itopologies/photonicMesh \
    -Itopologies/photonicTDM \
    -Itopologies/photonicTDM/ETDM \
    -Itopologies/photonicTDM/TDM \
    -Itopologies/squareRoot \
    -Itopologies/switches \
    -Itopologies/switches/crossbar \
    -Itopologies/switches/machzehndercrossbar \
    -Itopologies/torusNX \
    -Itraces \
    -Itraces/HAMMER \
    -Itraces/HAMMER/16 \
    -Itraces/HAMMER/32 \
    -Itraces/MESI \
    -Itraces/MESI/16 \
    -Itraces/MESI/4 \
    -Itraces/MESI/8

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -LC:/omnetpp-4.5/matlab-link -LC:/Users/Lebiednik/Documents/GT_Grad_School/Information_Security_Practicum/omnetpp-4.5-src-windows/omnetpp-4.5/win32  -lmat -lmx
LIBS += -Wl,-rpath,`abspath C:/omnetpp-4.5/matlab-link` -Wl,-rpath,`abspath C:/Users/Lebiednik/Documents/GT_Grad_School/Information_Security_Practicum/omnetpp-4.5-src-windows/omnetpp-4.5/win32`

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/addon/thermalmodel.o \
    $O/chipComponents/InoutConverter.o \
    $O/electronicComponents/electronicIOpad.o \
    $O/electronicComponents/electronic_channel.o \
    $O/electronicComponents/mux.o \
    $O/electronicComponents/RouterArbiter.o \
    $O/electronicComponents/RouterCrossbar.o \
    $O/electronicComponents/RouterInport.o \
    $O/electronicComponents/RouterInport2.o \
    $O/electronicComponents/RouterStat.o \
    $O/electronicComponents/serializer.o \
    $O/electronicComponents/VC_Control.o \
    $O/electronicComponents/VirtualChannelControl.o \
    $O/electronicComponents/Arbiters/Arbiter.o \
    $O/electronicComponents/Arbiters/ArbiterCanRoute.o \
    $O/electronicComponents/Arbiters/Arbiter_3DM.o \
    $O/electronicComponents/Arbiters/Arbiter_BFT.o \
    $O/electronicComponents/Arbiters/Arbiter_BT_4x4.o \
    $O/electronicComponents/Arbiters/Arbiter_BT_EJ.o \
    $O/electronicComponents/Arbiters/Arbiter_BT_GWS.o \
    $O/electronicComponents/Arbiters/Arbiter_BT_INJ.o \
    $O/electronicComponents/Arbiters/Arbiter_CBUF.o \
    $O/electronicComponents/Arbiters/Arbiter_CM.o \
    $O/electronicComponents/Arbiters/Arbiter_Crossbar.o \
    $O/electronicComponents/Arbiters/Arbiter_EHS.o \
    $O/electronicComponents/Arbiters/Arbiter_EM.o \
    $O/electronicComponents/Arbiters/Arbiter_EMB.o \
    $O/electronicComponents/Arbiters/Arbiter_EM_circuit.o \
    $O/electronicComponents/Arbiters/Arbiter_ET.o \
    $O/electronicComponents/Arbiters/Arbiter_FB.o \
    $O/electronicComponents/Arbiters/Arbiter_FT.o \
    $O/electronicComponents/Arbiters/Arbiter_FT_GWC.o \
    $O/electronicComponents/Arbiters/Arbiter_FT_Root.o \
    $O/electronicComponents/Arbiters/Arbiter_GWC.o \
    $O/electronicComponents/Arbiters/Arbiter_MITUCB_MemoryNode.o \
    $O/electronicComponents/Arbiters/Arbiter_MITUCB_MeshNode.o \
    $O/electronicComponents/Arbiters/Arbiter_NBSiN.o \
    $O/electronicComponents/Arbiters/Arbiter_NBT_Gateway.o \
    $O/electronicComponents/Arbiters/Arbiter_NBT_Node.o \
    $O/electronicComponents/Arbiters/Arbiter_NBT_Node_SP.o \
    $O/electronicComponents/Arbiters/Arbiter_OM4x4.o \
    $O/electronicComponents/Arbiters/Arbiter_PC.o \
    $O/electronicComponents/Arbiters/Arbiter_PM_Node.o \
    $O/electronicComponents/Arbiters/Arbiter_PR.o \
    $O/electronicComponents/Arbiters/Arbiter_SR.o \
    $O/electronicComponents/Arbiters/Arbiter_SR16x16.o \
    $O/electronicComponents/Arbiters/Arbiter_SR4x4.o \
    $O/electronicComponents/Arbiters/Arbiter_SR8x8.o \
    $O/electronicComponents/Arbiters/Arbiter_SR_Middle.o \
    $O/electronicComponents/Arbiters/Arbiter_SR_Quad.o \
    $O/electronicComponents/Arbiters/Arbiter_SR_Top.o \
    $O/electronicComponents/Arbiters/Arbiter_TNX_Gateway.o \
    $O/electronicComponents/Arbiters/Arbiter_TNX_Node.o \
    $O/electronicComponents/Arbiters/Arbiter_XB_Gateway.o \
    $O/electronicComponents/Arbiters/Arbiter_XB_Node.o \
    $O/electronicComponents/Arbiters/ElectronicArbiter.o \
    $O/electronicComponents/Arbiters/Photonic4x4Arbiter.o \
    $O/electronicComponents/Arbiters/PhotonicArbiter.o \
    $O/electronicComponents/Arbiters/PhotonicNoUturnArbiter.o \
    $O/electronicComponents/MAC_Layer/MacController.o \
    $O/electronicComponents/MAC_Layer/MACLayer.o \
    $O/electronicComponents/MAC_Layer/MACLayerCentralized.o \
    $O/electronicComponents/MAC_Layer/MACLayerGeneric.o \
    $O/electronicComponents/MAC_Layer/MACLayerStub.o \
    $O/electronicComponents/MAC_Layer/MACprotocol.o \
    $O/electronicComponents/MAC_Layer/MAC_BRS.o \
    $O/electronicComponents/MAC_Layer/MAC_CSMA.o \
    $O/electronicComponents/MAC_Layer/MAC_FDMA.o \
    $O/electronicComponents/MAC_Layer/MAC_TDMA.o \
    $O/electronicComponents/MAC_Layer/MAC_TOKEN.o \
    $O/electronicComponents/PHY_Layer/PhysicalLayer.o \
    $O/electronicComponents/PHY_Layer/PhysicalLayerBRS.o \
    $O/electronicComponents/PHY_Layer/PhysicalLayerGeneric.o \
    $O/electronicComponents/PHY_Layer/PhysicalLayerStub.o \
    $O/electronicComponents/orion/ORION_Arbiter.o \
    $O/electronicComponents/orion/ORION_Array.o \
    $O/electronicComponents/orion/ORION_Array_Info.o \
    $O/electronicComponents/orion/ORION_Array_Internal.o \
    $O/electronicComponents/orion/ORION_Config.o \
    $O/electronicComponents/orion/ORION_Crossbar.o \
    $O/electronicComponents/orion/ORION_Link.o \
    $O/electronicComponents/orion/ORION_Util.o \
    $O/ioComponents/cDramModule.o \
    $O/ioComponents/DRAM_LRL/DRAM_Bank.o \
    $O/ioComponents/DRAM_LRL/MemoryControl.o \
    $O/ioComponents/DRAM_LRL/NIF_MemGW.o \
    $O/ioComponents/DRAM_LRL/OCM_Control.o \
    $O/ioComponents/DRAM_LRL/ProcessorDataStripper.o \
    $O/ioComponents/DRAMsim/Aux_Stat.o \
    $O/ioComponents/DRAMsim/BIU.o \
    $O/ioComponents/DRAMsim/Command.o \
    $O/ioComponents/DRAMsim/DIMM.o \
    $O/ioComponents/DRAMsim/DRAM.o \
    $O/ioComponents/DRAMsim/DRAMaddress.o \
    $O/ioComponents/DRAMsim/DRAM_config.o \
    $O/ioComponents/DRAMsim/DRAM_Sim.o \
    $O/ioComponents/DRAMsim/Global_TQ_info.o \
    $O/ioComponents/DRAMsim/Memory_Controller.o \
    $O/ioComponents/DRAMsim/PendingQueue.o \
    $O/ioComponents/DRAMsim/PowerConfig.o \
    $O/ioComponents/DRAMsim/PrefetchCache.o \
    $O/ioComponents/DRAMsim/RBRR.o \
    $O/ioComponents/DRAMsim/RefreshQueue.o \
    $O/ioComponents/DRAMsim/Transaction.o \
    $O/ioComponents/DRAMsim/TransactionQueue.o \
    $O/ioComponents/DRAMsim/utilities.o \
    $O/photonic/activeelement.o \
    $O/photonic/activemultiringelement.o \
    $O/photonic/activeringelement.o \
    $O/photonic/activetworingelement.o \
    $O/photonic/basicelement.o \
    $O/photonic/detectorelement.o \
    $O/photonic/domainchanger.o \
    $O/photonic/machzehnderelement.o \
    $O/photonic/modulatorelement.o \
    $O/photonic/multiringelement.o \
    $O/photonic/phylayer.o \
    $O/photonic/resonanceprofile.o \
    $O/photonic/ringelement.o \
    $O/photonic/tworingelement.o \
    $O/photonic/devices/activedirectionalcoupler.o \
    $O/photonic/devices/attenuator.o \
    $O/photonic/devices/bend.o \
    $O/photonic/devices/cross.o \
    $O/photonic/devices/detector.o \
    $O/photonic/devices/end.o \
    $O/photonic/devices/facet.o \
    $O/photonic/devices/filter1x2.o \
    $O/photonic/devices/join.o \
    $O/photonic/devices/laser.o \
    $O/photonic/devices/line.o \
    $O/photonic/devices/modulator.o \
    $O/photonic/devices/pse1x2.o \
    $O/photonic/devices/pse1x2nx.o \
    $O/photonic/devices/pse2x2.o \
    $O/photonic/devices/StarCoupler.o \
    $O/photonic/devices/SwitchingFilter.o \
    $O/photonic/devices/machzehnder/mzswitch1x2.o \
    $O/photonic/devices/machzehnder/mzswitch2x2.o \
    $O/photonic/devices/multiring/pse1x2multiring.o \
    $O/photonic/devices/multiring/pse1x2nxmultiring.o \
    $O/photonic/devices/multiring/pse1x2nxr2.o \
    $O/photonic/devices/multiring/pse1x2nxr3.o \
    $O/photonic/devices/multiring/pse1x2r2.o \
    $O/photonic/devices/multiring/pse1x2r3.o \
    $O/photonic/devices/multiring/pse2x2multiring.o \
    $O/photonic/devices/multiring/pse2x2r2.o \
    $O/photonic/devices/multiring/pse2x2r3.o \
    $O/processingPlane/GatewaySignalControl.o \
    $O/processingPlane/Processor.o \
    $O/processingPlane/ProcessorRouterArbiter.o \
    $O/processingPlane/DRAM_Cfg/DRAM_Cfg.o \
    $O/processingPlane/DRAM_Cfg/DRAM_Cfg_AllNodes.o \
    $O/processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery.o \
    $O/processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR16x16.o \
    $O/processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR4x4.o \
    $O/processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR8x8.o \
    $O/processingPlane/addressTranslation/AddressTranslator.o \
    $O/processingPlane/addressTranslation/AddressTranslator_FatTree.o \
    $O/processingPlane/addressTranslation/AddressTranslator_SquareRoot.o \
    $O/processingPlane/addressTranslation/AddressTranslator_Standard.o \
    $O/processingPlane/apps/Application.o \
    $O/processingPlane/apps/AppNull.o \
    $O/processingPlane/apps/DRAM/AppDRAMAll2One.o \
    $O/processingPlane/apps/DRAM/AppDRAMOne2All.o \
    $O/processingPlane/apps/DRAM/AppDRAMOne2One.o \
    $O/processingPlane/apps/DRAM/AppDRAMRandom.o \
    $O/processingPlane/apps/MITUCB/App_MITUCB_All2All.o \
    $O/processingPlane/apps/MITUCB/App_MITUCB_Random.o \
    $O/processingPlane/apps/SizeDistribution/SizeDistribution.o \
    $O/processingPlane/apps/SizeDistribution/SizeDistribution_Constant.o \
    $O/processingPlane/apps/SizeDistribution/SizeDistribution_Control.o \
    $O/processingPlane/apps/SizeDistribution/SizeDistribution_Gamma.o \
    $O/processingPlane/apps/SizeDistribution/SizeDistribution_InvGamma.o \
    $O/processingPlane/apps/SizeDistribution/SizeDistribution_Normal.o \
    $O/processingPlane/apps/model/AppDataFlow.o \
    $O/processingPlane/apps/model/AppFFT.o \
    $O/processingPlane/apps/model/AppFFTstream.o \
    $O/processingPlane/apps/synthetics/AppBcast.o \
    $O/processingPlane/apps/synthetics/AppBitreverse.o \
    $O/processingPlane/apps/synthetics/AppHotspot.o \
    $O/processingPlane/apps/synthetics/AppNeighbor.o \
    $O/processingPlane/apps/synthetics/AppRandom.o \
    $O/processingPlane/apps/synthetics/AppRandom_FiniteQueue.o \
    $O/processingPlane/apps/synthetics/AppTornado.o \
    $O/processingPlane/apps/test/AppAll2All.o \
    $O/processingPlane/apps/test/AppOne2One.o \
    $O/processingPlane/apps/trace/AppTrace_LBL.o \
    $O/processingPlane/apps/trace/App_LL_DepGraph.o \
    $O/processingPlane/interfaces/HybridController.o \
    $O/processingPlane/interfaces/NIF.o \
    $O/processingPlane/interfaces/NIF_Circuit.o \
    $O/processingPlane/interfaces/NIF_Electronic.o \
    $O/processingPlane/interfaces/NIF_ElectronicCC.o \
    $O/processingPlane/interfaces/NIF_Packet_Credit.o \
    $O/processingPlane/interfaces/NIF_Photonic.o \
    $O/processingPlane/interfaces/wNIF.o \
    $O/processingPlane/trafficGenerator/SyntheticGenerator.o \
    $O/processingPlane/trafficGenerator/TGcore.o \
    $O/processingPlane/trafficGenerator/TraceBasedGenerator.o \
    $O/processingPlane/trafficGenerator/TrafficGenerator.o \
    $O/simCore/convert.o \
    $O/simCore/NetworkAddress.o \
    $O/simCore/packetstat.o \
    $O/simCore/sim_includes.o \
    $O/statistics/LogFile.o \
    $O/statistics/StatGroup.o \
    $O/statistics/statistics.o \
    $O/statistics/StatObject.o \
    $O/statistics/statGroups/StatGroup_ListAll.o \
    $O/statistics/statGroups/StatGroup_Sum.o \
    $O/statistics/statObjects/StatObject_Avg.o \
    $O/statistics/statObjects/StatObject_Count.o \
    $O/statistics/statObjects/StatObject_HURST.o \
    $O/statistics/statObjects/StatObject_MMA.o \
    $O/statistics/statObjects/StatObject_StaticTotal.o \
    $O/statistics/statObjects/StatObject_TimeAvg.o \
    $O/statistics/statObjects/StatObject_Total.o \
    $O/statistics/statObjects/energy/StatObject_EnergyEvent.o \
    $O/statistics/statObjects/energy/StatObject_EnergyOn.o \
    $O/statistics/statObjects/energy/StatObject_EnergyStatic.o \
    $O/topologies/photonicTDM/ScheduleItem.o \
    $O/topologies/photonicTDM/ETDM/ETDM_Switch_Controller.o \
    $O/topologies/photonicTDM/ETDM/NIF_PhotonicETDM.o \
    $O/topologies/photonicTDM/TDM/NIF_PhotonicTDM.o \
    $O/topologies/photonicTDM/TDM/TDM_Switch_Controller.o \
    $O/simCore/messages_m.o

# Message files
MSGFILES = \
    simCore/messages.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)echo >.tmp$$$$ $(OBJS) $(EXTRA_OBJS) && $(AR) .tmplib$$$$ @.tmp$$$$ && $(CXX) -o $O/$(TARGET) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) .tmplib$$$$ $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS) $(LDFLAGS) && rm .tmp$$$$ && rm .tmplib$$$$

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f PhoenixSim PhoenixSim.exe libPhoenixSim.so libPhoenixSim.a libPhoenixSim.dll libPhoenixSim.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f addon/*_m.cc addon/*_m.h
	$(Q)-rm -f addon/HotSpot-5.0/*_m.cc addon/HotSpot-5.0/*_m.h
	$(Q)-rm -f chipComponents/*_m.cc chipComponents/*_m.h
	$(Q)-rm -f data/*_m.cc data/*_m.h
	$(Q)-rm -f electronicComponents/*_m.cc electronicComponents/*_m.h
	$(Q)-rm -f electronicComponents/Arbiters/*_m.cc electronicComponents/Arbiters/*_m.h
	$(Q)-rm -f electronicComponents/MAC_Layer/*_m.cc electronicComponents/MAC_Layer/*_m.h
	$(Q)-rm -f electronicComponents/PHY_Layer/*_m.cc electronicComponents/PHY_Layer/*_m.h
	$(Q)-rm -f electronicComponents/orion/*_m.cc electronicComponents/orion/*_m.h
	$(Q)-rm -f electronicComponents/orion/ORION_1_Params/*_m.cc electronicComponents/orion/ORION_1_Params/*_m.h
	$(Q)-rm -f electronicComponents/orion/ORION_2_Params/*_m.cc electronicComponents/orion/ORION_2_Params/*_m.h
	$(Q)-rm -f images/*_m.cc images/*_m.h
	$(Q)-rm -f images/components/*_m.cc images/components/*_m.h
	$(Q)-rm -f images/components/old/*_m.cc images/components/old/*_m.h
	$(Q)-rm -f images/mitucb/*_m.cc images/mitucb/*_m.h
	$(Q)-rm -f images/planes/*_m.cc images/planes/*_m.h
	$(Q)-rm -f ioComponents/*_m.cc ioComponents/*_m.h
	$(Q)-rm -f ioComponents/DRAM_LRL/*_m.cc ioComponents/DRAM_LRL/*_m.h
	$(Q)-rm -f ioComponents/DRAMsim/*_m.cc ioComponents/DRAMsim/*_m.h
	$(Q)-rm -f ioComponents/DRAMsim/mem_system_def/*_m.cc ioComponents/DRAMsim/mem_system_def/*_m.h
	$(Q)-rm -f parameters/*_m.cc parameters/*_m.h
	$(Q)-rm -f parameters/Hendry-Thesis/*_m.cc parameters/Hendry-Thesis/*_m.h
	$(Q)-rm -f parameters/custom/*_m.cc parameters/custom/*_m.h
	$(Q)-rm -f parameters/default/*_m.cc parameters/default/*_m.h
	$(Q)-rm -f photonic/*_m.cc photonic/*_m.h
	$(Q)-rm -f photonic/PhotoCAD/*_m.cc photonic/PhotoCAD/*_m.h
	$(Q)-rm -f photonic/devices/*_m.cc photonic/devices/*_m.h
	$(Q)-rm -f photonic/devices/machzehnder/*_m.cc photonic/devices/machzehnder/*_m.h
	$(Q)-rm -f photonic/devices/multiring/*_m.cc photonic/devices/multiring/*_m.h
	$(Q)-rm -f photonic/switches/*_m.cc photonic/switches/*_m.h
	$(Q)-rm -f photonic/switches/machzehnder/*_m.cc photonic/switches/machzehnder/*_m.h
	$(Q)-rm -f photonic/switches/multiring/*_m.cc photonic/switches/multiring/*_m.h
	$(Q)-rm -f processingPlane/*_m.cc processingPlane/*_m.h
	$(Q)-rm -f processingPlane/DRAM_Cfg/*_m.cc processingPlane/DRAM_Cfg/*_m.h
	$(Q)-rm -f processingPlane/addressTranslation/*_m.cc processingPlane/addressTranslation/*_m.h
	$(Q)-rm -f processingPlane/apps/*_m.cc processingPlane/apps/*_m.h
	$(Q)-rm -f processingPlane/apps/DRAM/*_m.cc processingPlane/apps/DRAM/*_m.h
	$(Q)-rm -f processingPlane/apps/MITUCB/*_m.cc processingPlane/apps/MITUCB/*_m.h
	$(Q)-rm -f processingPlane/apps/SizeDistribution/*_m.cc processingPlane/apps/SizeDistribution/*_m.h
	$(Q)-rm -f processingPlane/apps/model/*_m.cc processingPlane/apps/model/*_m.h
	$(Q)-rm -f processingPlane/apps/synthetics/*_m.cc processingPlane/apps/synthetics/*_m.h
	$(Q)-rm -f processingPlane/apps/test/*_m.cc processingPlane/apps/test/*_m.h
	$(Q)-rm -f processingPlane/apps/trace/*_m.cc processingPlane/apps/trace/*_m.h
	$(Q)-rm -f processingPlane/interfaces/*_m.cc processingPlane/interfaces/*_m.h
	$(Q)-rm -f processingPlane/trafficGenerator/*_m.cc processingPlane/trafficGenerator/*_m.h
	$(Q)-rm -f results/*_m.cc results/*_m.h
	$(Q)-rm -f results/old/*_m.cc results/old/*_m.h
	$(Q)-rm -f results/old/baseline17SEP1031/*_m.cc results/old/baseline17SEP1031/*_m.h
	$(Q)-rm -f results/old/baseline64_19SEP/*_m.cc results/old/baseline64_19SEP/*_m.h
	$(Q)-rm -f results/old/baseline64_core_17SEP/*_m.cc results/old/baseline64_core_17SEP/*_m.h
	$(Q)-rm -f results/old/broadcast100/*_m.cc results/old/broadcast100/*_m.h
	$(Q)-rm -f results/old/test017SEP1122/*_m.cc results/old/test017SEP1122/*_m.h
	$(Q)-rm -f results/old/wrong/*_m.cc results/old/wrong/*_m.h
	$(Q)-rm -f results/old2/*_m.cc results/old2/*_m.h
	$(Q)-rm -f results/old3/*_m.cc results/old3/*_m.h
	$(Q)-rm -f simCore/*_m.cc simCore/*_m.h
	$(Q)-rm -f statistics/*_m.cc statistics/*_m.h
	$(Q)-rm -f statistics/statGroups/*_m.cc statistics/statGroups/*_m.h
	$(Q)-rm -f statistics/statObjects/*_m.cc statistics/statObjects/*_m.h
	$(Q)-rm -f statistics/statObjects/energy/*_m.cc statistics/statObjects/energy/*_m.h
	$(Q)-rm -f topologies/*_m.cc topologies/*_m.h
	$(Q)-rm -f topologies/ButterflyFatTree/*_m.cc topologies/ButterflyFatTree/*_m.h
	$(Q)-rm -f topologies/CMesh/*_m.cc topologies/CMesh/*_m.h
	$(Q)-rm -f topologies/HybridWEMesh/*_m.cc topologies/HybridWEMesh/*_m.h
	$(Q)-rm -f topologies/WirelessMesh/*_m.cc topologies/WirelessMesh/*_m.h
	$(Q)-rm -f topologies/blockingTorus/*_m.cc topologies/blockingTorus/*_m.h
	$(Q)-rm -f topologies/electronic3DMesh/*_m.cc topologies/electronic3DMesh/*_m.h
	$(Q)-rm -f topologies/electronicMesh/*_m.cc topologies/electronicMesh/*_m.h
	$(Q)-rm -f topologies/electronicMesh_Circuit/*_m.cc topologies/electronicMesh_Circuit/*_m.h
	$(Q)-rm -f topologies/electronicRing/*_m.cc topologies/electronicRing/*_m.h
	$(Q)-rm -f topologies/electronicTorus/*_m.cc topologies/electronicTorus/*_m.h
	$(Q)-rm -f topologies/flattenedButterfly/*_m.cc topologies/flattenedButterfly/*_m.h
	$(Q)-rm -f topologies/nonblockingSiliconNitride/*_m.cc topologies/nonblockingSiliconNitride/*_m.h
	$(Q)-rm -f topologies/nonblockingTorus/*_m.cc topologies/nonblockingTorus/*_m.h
	$(Q)-rm -f topologies/photonicMesh/*_m.cc topologies/photonicMesh/*_m.h
	$(Q)-rm -f topologies/photonicTDM/*_m.cc topologies/photonicTDM/*_m.h
	$(Q)-rm -f topologies/photonicTDM/ETDM/*_m.cc topologies/photonicTDM/ETDM/*_m.h
	$(Q)-rm -f topologies/photonicTDM/TDM/*_m.cc topologies/photonicTDM/TDM/*_m.h
	$(Q)-rm -f topologies/squareRoot/*_m.cc topologies/squareRoot/*_m.h
	$(Q)-rm -f topologies/switches/*_m.cc topologies/switches/*_m.h
	$(Q)-rm -f topologies/switches/crossbar/*_m.cc topologies/switches/crossbar/*_m.h
	$(Q)-rm -f topologies/switches/machzehndercrossbar/*_m.cc topologies/switches/machzehndercrossbar/*_m.h
	$(Q)-rm -f topologies/torusNX/*_m.cc topologies/torusNX/*_m.h
	$(Q)-rm -f traces/*_m.cc traces/*_m.h
	$(Q)-rm -f traces/HAMMER/*_m.cc traces/HAMMER/*_m.h
	$(Q)-rm -f traces/HAMMER/16/*_m.cc traces/HAMMER/16/*_m.h
	$(Q)-rm -f traces/HAMMER/32/*_m.cc traces/HAMMER/32/*_m.h
	$(Q)-rm -f traces/MESI/*_m.cc traces/MESI/*_m.h
	$(Q)-rm -f traces/MESI/16/*_m.cc traces/MESI/16/*_m.h
	$(Q)-rm -f traces/MESI/4/*_m.cc traces/MESI/4/*_m.h
	$(Q)-rm -f traces/MESI/8/*_m.cc traces/MESI/8/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc addon/*.cc addon/HotSpot-5.0/*.cc chipComponents/*.cc data/*.cc electronicComponents/*.cc electronicComponents/Arbiters/*.cc electronicComponents/MAC_Layer/*.cc electronicComponents/PHY_Layer/*.cc electronicComponents/orion/*.cc electronicComponents/orion/ORION_1_Params/*.cc electronicComponents/orion/ORION_2_Params/*.cc images/*.cc images/components/*.cc images/components/old/*.cc images/mitucb/*.cc images/planes/*.cc ioComponents/*.cc ioComponents/DRAM_LRL/*.cc ioComponents/DRAMsim/*.cc ioComponents/DRAMsim/mem_system_def/*.cc parameters/*.cc parameters/Hendry-Thesis/*.cc parameters/custom/*.cc parameters/default/*.cc photonic/*.cc photonic/PhotoCAD/*.cc photonic/devices/*.cc photonic/devices/machzehnder/*.cc photonic/devices/multiring/*.cc photonic/switches/*.cc photonic/switches/machzehnder/*.cc photonic/switches/multiring/*.cc processingPlane/*.cc processingPlane/DRAM_Cfg/*.cc processingPlane/addressTranslation/*.cc processingPlane/apps/*.cc processingPlane/apps/DRAM/*.cc processingPlane/apps/MITUCB/*.cc processingPlane/apps/SizeDistribution/*.cc processingPlane/apps/model/*.cc processingPlane/apps/synthetics/*.cc processingPlane/apps/test/*.cc processingPlane/apps/trace/*.cc processingPlane/interfaces/*.cc processingPlane/trafficGenerator/*.cc results/*.cc results/old/*.cc results/old/baseline17SEP1031/*.cc results/old/baseline64_19SEP/*.cc results/old/baseline64_core_17SEP/*.cc results/old/broadcast100/*.cc results/old/test017SEP1122/*.cc results/old/wrong/*.cc results/old2/*.cc results/old3/*.cc simCore/*.cc statistics/*.cc statistics/statGroups/*.cc statistics/statObjects/*.cc statistics/statObjects/energy/*.cc topologies/*.cc topologies/ButterflyFatTree/*.cc topologies/CMesh/*.cc topologies/HybridWEMesh/*.cc topologies/WirelessMesh/*.cc topologies/blockingTorus/*.cc topologies/electronic3DMesh/*.cc topologies/electronicMesh/*.cc topologies/electronicMesh_Circuit/*.cc topologies/electronicRing/*.cc topologies/electronicTorus/*.cc topologies/flattenedButterfly/*.cc topologies/nonblockingSiliconNitride/*.cc topologies/nonblockingTorus/*.cc topologies/photonicMesh/*.cc topologies/photonicTDM/*.cc topologies/photonicTDM/ETDM/*.cc topologies/photonicTDM/TDM/*.cc topologies/squareRoot/*.cc topologies/switches/*.cc topologies/switches/crossbar/*.cc topologies/switches/machzehndercrossbar/*.cc topologies/torusNX/*.cc traces/*.cc traces/HAMMER/*.cc traces/HAMMER/16/*.cc traces/HAMMER/32/*.cc traces/MESI/*.cc traces/MESI/16/*.cc traces/MESI/4/*.cc traces/MESI/8/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/addon/thermalmodel.o: addon/thermalmodel.cc \
	addon/thermalmodel.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/chipComponents/InoutConverter.o: chipComponents/InoutConverter.cc \
	chipComponents/InoutConverter.h
$O/electronicComponents/RouterArbiter.o: electronicComponents/RouterArbiter.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_3DM.h \
	electronicComponents/Arbiters/Arbiter_BFT.h \
	electronicComponents/Arbiters/Arbiter_BT_4x4.h \
	electronicComponents/Arbiters/Arbiter_BT_EJ.h \
	electronicComponents/Arbiters/Arbiter_BT_GWS.h \
	electronicComponents/Arbiters/Arbiter_BT_INJ.h \
	electronicComponents/Arbiters/Arbiter_CBUF.h \
	electronicComponents/Arbiters/Arbiter_CM.h \
	electronicComponents/Arbiters/Arbiter_Crossbar.h \
	electronicComponents/Arbiters/Arbiter_EHS.h \
	electronicComponents/Arbiters/Arbiter_EM.h \
	electronicComponents/Arbiters/Arbiter_EMB.h \
	electronicComponents/Arbiters/Arbiter_EM_circuit.h \
	electronicComponents/Arbiters/Arbiter_ET.h \
	electronicComponents/Arbiters/Arbiter_FB.h \
	electronicComponents/Arbiters/Arbiter_FT.h \
	electronicComponents/Arbiters/Arbiter_FT_GWC.h \
	electronicComponents/Arbiters/Arbiter_FT_Root.h \
	electronicComponents/Arbiters/Arbiter_GWC.h \
	electronicComponents/Arbiters/Arbiter_MITUCB_MemoryNode.h \
	electronicComponents/Arbiters/Arbiter_MITUCB_MeshNode.h \
	electronicComponents/Arbiters/Arbiter_NBSiN.h \
	electronicComponents/Arbiters/Arbiter_NBT_Gateway.h \
	electronicComponents/Arbiters/Arbiter_NBT_Node.h \
	electronicComponents/Arbiters/Arbiter_PC.h \
	electronicComponents/Arbiters/Arbiter_PM_Node.h \
	electronicComponents/Arbiters/Arbiter_PR.h \
	electronicComponents/Arbiters/Arbiter_SR.h \
	electronicComponents/Arbiters/Arbiter_SR_Middle.h \
	electronicComponents/Arbiters/Arbiter_SR_Quad.h \
	electronicComponents/Arbiters/Arbiter_SR_Top.h \
	electronicComponents/Arbiters/Arbiter_TNX_Gateway.h \
	electronicComponents/Arbiters/Arbiter_TNX_Node.h \
	electronicComponents/Arbiters/Arbiter_XB_Gateway.h \
	electronicComponents/Arbiters/Arbiter_XB_Node.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/Photonic4x4Arbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/RouterArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/addressTranslation/AddressTranslator_FatTree.h \
	processingPlane/addressTranslation/AddressTranslator_SquareRoot.h \
	processingPlane/addressTranslation/AddressTranslator_Standard.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/RouterCrossbar.o: electronicComponents/RouterCrossbar.cc \
	electronicComponents/RouterCrossbar.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/RouterInport.o: electronicComponents/RouterInport.cc \
	electronicComponents/RouterInport.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/RouterInport2.o: electronicComponents/RouterInport2.cc \
	electronicComponents/RouterInport2.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/RouterStat.o: electronicComponents/RouterStat.cc \
	electronicComponents/RouterStat.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Crossbar.h \
	electronicComponents/orion/ORION_Link.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/VC_Control.o: electronicComponents/VC_Control.cc \
	electronicComponents/VC_Control.h \
	simCore/messages_m.h
$O/electronicComponents/VirtualChannelControl.o: electronicComponents/VirtualChannelControl.cc \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	simCore/messages_m.h
$O/electronicComponents/electronicIOpad.o: electronicComponents/electronicIOpad.cc \
	electronicComponents/electronicIOpad.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/electronic_channel.o: electronicComponents/electronic_channel.cc \
	electronicComponents/RouterStat.h \
	electronicComponents/electronic_channel.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Crossbar.h \
	electronicComponents/orion/ORION_Link.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/mux.o: electronicComponents/mux.cc \
	electronicComponents/mux.h \
	simCore/messages_m.h \
	simCore/packetstat.h
$O/electronicComponents/serializer.o: electronicComponents/serializer.cc \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/serializer.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter.o: electronicComponents/Arbiters/Arbiter.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/ArbiterCanRoute.o: electronicComponents/Arbiters/ArbiterCanRoute.cc \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h
$O/electronicComponents/Arbiters/Arbiter_3DM.o: electronicComponents/Arbiters/Arbiter_3DM.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_3DM.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_BFT.o: electronicComponents/Arbiters/Arbiter_BFT.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_BFT.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_BT_4x4.o: electronicComponents/Arbiters/Arbiter_BT_4x4.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_BT_4x4.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_BT_EJ.o: electronicComponents/Arbiters/Arbiter_BT_EJ.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_BT_EJ.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_BT_GWS.o: electronicComponents/Arbiters/Arbiter_BT_GWS.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_BT_GWS.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_BT_INJ.o: electronicComponents/Arbiters/Arbiter_BT_INJ.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_BT_INJ.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_CBUF.o: electronicComponents/Arbiters/Arbiter_CBUF.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_CBUF.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_CM.o: electronicComponents/Arbiters/Arbiter_CM.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_CM.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_Crossbar.o: electronicComponents/Arbiters/Arbiter_Crossbar.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_Crossbar.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_EHS.o: electronicComponents/Arbiters/Arbiter_EHS.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_EHS.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_EM.o: electronicComponents/Arbiters/Arbiter_EM.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_EM.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_EMB.o: electronicComponents/Arbiters/Arbiter_EMB.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_EMB.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_EM_circuit.o: electronicComponents/Arbiters/Arbiter_EM_circuit.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_EM_circuit.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_ET.o: electronicComponents/Arbiters/Arbiter_ET.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_ET.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_FB.o: electronicComponents/Arbiters/Arbiter_FB.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_FB.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_FT.o: electronicComponents/Arbiters/Arbiter_FT.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_FT.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_FT_GWC.o: electronicComponents/Arbiters/Arbiter_FT_GWC.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_FT_GWC.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_FT_Root.o: electronicComponents/Arbiters/Arbiter_FT_Root.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_FT_Root.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_GWC.o: electronicComponents/Arbiters/Arbiter_GWC.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_GWC.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_MITUCB_MemoryNode.o: electronicComponents/Arbiters/Arbiter_MITUCB_MemoryNode.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_MITUCB_MemoryNode.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_MITUCB_MeshNode.o: electronicComponents/Arbiters/Arbiter_MITUCB_MeshNode.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_MITUCB_MeshNode.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_NBSiN.o: electronicComponents/Arbiters/Arbiter_NBSiN.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_NBSiN.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_NBT_Gateway.o: electronicComponents/Arbiters/Arbiter_NBT_Gateway.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_NBT_Gateway.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_NBT_Node.o: electronicComponents/Arbiters/Arbiter_NBT_Node.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_NBT_Node.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_NBT_Node_SP.o: electronicComponents/Arbiters/Arbiter_NBT_Node_SP.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_NBT_Node.h \
	electronicComponents/Arbiters/Arbiter_NBT_Node_SP.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_OM4x4.o: electronicComponents/Arbiters/Arbiter_OM4x4.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_OM4x4.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_PC.o: electronicComponents/Arbiters/Arbiter_PC.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_PC.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_PM_Node.o: electronicComponents/Arbiters/Arbiter_PM_Node.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_PM_Node.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_PR.o: electronicComponents/Arbiters/Arbiter_PR.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_PR.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_SR.o: electronicComponents/Arbiters/Arbiter_SR.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_SR.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/Photonic4x4Arbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_SR16x16.o: electronicComponents/Arbiters/Arbiter_SR16x16.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_SR16x16.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/Photonic4x4Arbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_SR4x4.o: electronicComponents/Arbiters/Arbiter_SR4x4.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_SR4x4.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/Photonic4x4Arbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_SR8x8.o: electronicComponents/Arbiters/Arbiter_SR8x8.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_SR8x8.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/Photonic4x4Arbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_SR_Middle.o: electronicComponents/Arbiters/Arbiter_SR_Middle.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_SR.h \
	electronicComponents/Arbiters/Arbiter_SR_Middle.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/Photonic4x4Arbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_SR_Quad.o: electronicComponents/Arbiters/Arbiter_SR_Quad.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_SR.h \
	electronicComponents/Arbiters/Arbiter_SR_Quad.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/Photonic4x4Arbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_SR_Top.o: electronicComponents/Arbiters/Arbiter_SR_Top.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_SR.h \
	electronicComponents/Arbiters/Arbiter_SR_Top.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/Photonic4x4Arbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_TNX_Gateway.o: electronicComponents/Arbiters/Arbiter_TNX_Gateway.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_TNX_Gateway.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_TNX_Node.o: electronicComponents/Arbiters/Arbiter_TNX_Node.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_TNX_Node.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/Photonic4x4Arbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/Arbiter_XB_Gateway.o: electronicComponents/Arbiters/Arbiter_XB_Gateway.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_XB_Gateway.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Arbiter_XB_Node.o: electronicComponents/Arbiters/Arbiter_XB_Node.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/Arbiter_XB_Node.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/ElectronicArbiter.o: electronicComponents/Arbiters/ElectronicArbiter.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/Photonic4x4Arbiter.o: electronicComponents/Arbiters/Photonic4x4Arbiter.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/Photonic4x4Arbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/Arbiters/PhotonicArbiter.o: electronicComponents/Arbiters/PhotonicArbiter.cc \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/Arbiters/PhotonicNoUturnArbiter.o: electronicComponents/Arbiters/PhotonicNoUturnArbiter.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/Arbiters/ElectronicArbiter.h \
	electronicComponents/Arbiters/PhotonicArbiter.h \
	electronicComponents/Arbiters/PhotonicNoUturnArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/MAC_Layer/MACLayer.o: electronicComponents/MAC_Layer/MACLayer.cc \
	electronicComponents/MAC_Layer/MACLayer.h \
	electronicComponents/MAC_Layer/MAC_CSMA.h \
	electronicComponents/MAC_Layer/MAC_FDMA.h \
	electronicComponents/MAC_Layer/MAC_TDMA.h \
	electronicComponents/MAC_Layer/MACprotocol.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/MAC_Layer/MACLayerCentralized.o: electronicComponents/MAC_Layer/MACLayerCentralized.cc \
	electronicComponents/MAC_Layer/MACLayer.h \
	electronicComponents/MAC_Layer/MACLayerCentralized.h \
	electronicComponents/MAC_Layer/MACprotocol.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/MAC_Layer/MACLayerGeneric.o: electronicComponents/MAC_Layer/MACLayerGeneric.cc \
	electronicComponents/MAC_Layer/MACLayer.h \
	electronicComponents/MAC_Layer/MACLayerGeneric.h \
	electronicComponents/MAC_Layer/MAC_CSMA.h \
	electronicComponents/MAC_Layer/MAC_FDMA.h \
	electronicComponents/MAC_Layer/MAC_TDMA.h \
	electronicComponents/MAC_Layer/MACprotocol.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/MAC_Layer/MACLayerStub.o: electronicComponents/MAC_Layer/MACLayerStub.cc \
	electronicComponents/MAC_Layer/MACLayer.h \
	electronicComponents/MAC_Layer/MACLayerStub.h \
	electronicComponents/MAC_Layer/MACprotocol.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/MAC_Layer/MAC_BRS.o: electronicComponents/MAC_Layer/MAC_BRS.cc \
	electronicComponents/MAC_Layer/MACLayer.h \
	electronicComponents/MAC_Layer/MAC_BRS.h \
	electronicComponents/MAC_Layer/MACprotocol.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/MAC_Layer/MAC_CSMA.o: electronicComponents/MAC_Layer/MAC_CSMA.cc \
	electronicComponents/MAC_Layer/MAC_CSMA.h \
	electronicComponents/MAC_Layer/MACprotocol.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/MAC_Layer/MAC_FDMA.o: electronicComponents/MAC_Layer/MAC_FDMA.cc \
	electronicComponents/MAC_Layer/MAC_FDMA.h \
	electronicComponents/MAC_Layer/MACprotocol.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/MAC_Layer/MAC_TDMA.o: electronicComponents/MAC_Layer/MAC_TDMA.cc \
	electronicComponents/MAC_Layer/MAC_TDMA.h \
	electronicComponents/MAC_Layer/MACprotocol.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/MAC_Layer/MAC_TOKEN.o: electronicComponents/MAC_Layer/MAC_TOKEN.cc
$O/electronicComponents/MAC_Layer/MACprotocol.o: electronicComponents/MAC_Layer/MACprotocol.cc \
	electronicComponents/MAC_Layer/MACprotocol.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/MAC_Layer/MacController.o: electronicComponents/MAC_Layer/MacController.cc \
	electronicComponents/MAC_Layer/MacController.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/PHY_Layer/PhysicalLayer.o: electronicComponents/PHY_Layer/PhysicalLayer.cc \
	electronicComponents/PHY_Layer/PhysicalLayer.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/PHY_Layer/PhysicalLayerBRS.o: electronicComponents/PHY_Layer/PhysicalLayerBRS.cc \
	electronicComponents/PHY_Layer/PhysicalLayer.h \
	electronicComponents/PHY_Layer/PhysicalLayerBRS.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/PHY_Layer/PhysicalLayerGeneric.o: electronicComponents/PHY_Layer/PhysicalLayerGeneric.cc \
	electronicComponents/PHY_Layer/PhysicalLayer.h \
	electronicComponents/PHY_Layer/PhysicalLayerGeneric.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/PHY_Layer/PhysicalLayerStub.o: electronicComponents/PHY_Layer/PhysicalLayerStub.cc \
	electronicComponents/PHY_Layer/PhysicalLayer.h \
	electronicComponents/PHY_Layer/PhysicalLayerStub.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/orion/ORION_Arbiter.o: electronicComponents/orion/ORION_Arbiter.cc \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/electronicComponents/orion/ORION_Array.o: electronicComponents/orion/ORION_Array.cc \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/orion/ORION_Array_Info.o: electronicComponents/orion/ORION_Array_Info.cc \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Config.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/orion/ORION_Array_Internal.o: electronicComponents/orion/ORION_Array_Internal.cc \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/orion/ORION_Config.o: electronicComponents/orion/ORION_Config.cc \
	electronicComponents/orion/ORION_Config.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/orion/ORION_Crossbar.o: electronicComponents/orion/ORION_Crossbar.cc \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Crossbar.h \
	electronicComponents/orion/ORION_Util.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/orion/ORION_Link.o: electronicComponents/orion/ORION_Link.cc \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Link.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/electronicComponents/orion/ORION_Util.o: electronicComponents/orion/ORION_Util.cc \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/ioComponents/cDramModule.o: ioComponents/cDramModule.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	ioComponents/DRAMsim/Aux_Stat.h \
	ioComponents/DRAMsim/BIU.h \
	ioComponents/DRAMsim/BIU_slot.h \
	ioComponents/DRAMsim/Bank.h \
	ioComponents/DRAMsim/Bus.h \
	ioComponents/DRAMsim/BusEvent.h \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/DIMM.h \
	ioComponents/DRAMsim/DRAM.h \
	ioComponents/DRAMsim/DRAM_Sim.h \
	ioComponents/DRAMsim/DRAM_config.h \
	ioComponents/DRAMsim/DRAMaddress.h \
	ioComponents/DRAMsim/Global_TQ_info.h \
	ioComponents/DRAMsim/Memory_Controller.h \
	ioComponents/DRAMsim/PendingInfo.h \
	ioComponents/DRAMsim/PendingQueue.h \
	ioComponents/DRAMsim/PowerConfig.h \
	ioComponents/DRAMsim/PowerCounter.h \
	ioComponents/DRAMsim/PowerMeasure.h \
	ioComponents/DRAMsim/RBRR.h \
	ioComponents/DRAMsim/Rank.h \
	ioComponents/DRAMsim/RefreshQueue.h \
	ioComponents/DRAMsim/Transaction.h \
	ioComponents/DRAMsim/TransactionQueue.h \
	ioComponents/DRAMsim/UpdateInterface.h \
	ioComponents/DRAMsim/constants.h \
	ioComponents/cDramModule.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/addressTranslation/AddressTranslator_FatTree.h \
	processingPlane/addressTranslation/AddressTranslator_SquareRoot.h \
	processingPlane/addressTranslation/AddressTranslator_Standard.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/ioComponents/DRAM_LRL/DRAM_Bank.o: ioComponents/DRAM_LRL/DRAM_Bank.cc \
	electronicComponents/orion/ORION_Config.h \
	ioComponents/DRAM_LRL/DRAM_Bank.h \
	photonic/phylayer.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/ioComponents/DRAM_LRL/MemoryControl.o: ioComponents/DRAM_LRL/MemoryControl.cc \
	ioComponents/DRAM_LRL/MemoryControl.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/ioComponents/DRAM_LRL/NIF_MemGW.o: ioComponents/DRAM_LRL/NIF_MemGW.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	ioComponents/DRAM_LRL/NIF_MemGW.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/interfaces/NIF.h \
	processingPlane/interfaces/NIF_Circuit.h \
	processingPlane/interfaces/NIF_Packet_Credit.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/ioComponents/DRAM_LRL/OCM_Control.o: ioComponents/DRAM_LRL/OCM_Control.cc \
	electronicComponents/orion/ORION_Config.h \
	ioComponents/DRAM_LRL/OCM_Control.h \
	photonic/phylayer.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/ioComponents/DRAM_LRL/ProcessorDataStripper.o: ioComponents/DRAM_LRL/ProcessorDataStripper.cc \
	electronicComponents/orion/ORION_Config.h \
	ioComponents/DRAM_LRL/ProcessorDataStripper.h \
	photonic/phylayer.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/ioComponents/DRAMsim/Aux_Stat.o: ioComponents/DRAMsim/Aux_Stat.cc \
	ioComponents/DRAMsim/Aux_Stat.h \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/DRAM_config.h \
	ioComponents/DRAMsim/Global_TQ_info.h \
	ioComponents/DRAMsim/UpdateInterface.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/BIU.o: ioComponents/DRAMsim/BIU.cc \
	ioComponents/DRAMsim/Aux_Stat.h \
	ioComponents/DRAMsim/BIU.h \
	ioComponents/DRAMsim/BIU_slot.h \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/DRAM_config.h \
	ioComponents/DRAMsim/DRAMaddress.h \
	ioComponents/DRAMsim/Global_TQ_info.h \
	ioComponents/DRAMsim/UpdateInterface.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/Command.o: ioComponents/DRAMsim/Command.cc \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/DIMM.o: ioComponents/DRAMsim/DIMM.cc \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/DIMM.h \
	ioComponents/DRAMsim/DRAM_config.h \
	ioComponents/DRAMsim/Global_TQ_info.h \
	ioComponents/DRAMsim/UpdateInterface.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/DRAM.o: ioComponents/DRAMsim/DRAM.cc \
	ioComponents/DRAMsim/Aux_Stat.h \
	ioComponents/DRAMsim/BIU.h \
	ioComponents/DRAMsim/BIU_slot.h \
	ioComponents/DRAMsim/Bank.h \
	ioComponents/DRAMsim/Bus.h \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/DIMM.h \
	ioComponents/DRAMsim/DRAM.h \
	ioComponents/DRAMsim/DRAM_config.h \
	ioComponents/DRAMsim/DRAMaddress.h \
	ioComponents/DRAMsim/Global_TQ_info.h \
	ioComponents/DRAMsim/Memory_Controller.h \
	ioComponents/DRAMsim/PendingInfo.h \
	ioComponents/DRAMsim/PendingQueue.h \
	ioComponents/DRAMsim/PowerConfig.h \
	ioComponents/DRAMsim/PowerCounter.h \
	ioComponents/DRAMsim/PowerMeasure.h \
	ioComponents/DRAMsim/RBRR.h \
	ioComponents/DRAMsim/Rank.h \
	ioComponents/DRAMsim/RefreshQueue.h \
	ioComponents/DRAMsim/Transaction.h \
	ioComponents/DRAMsim/TransactionQueue.h \
	ioComponents/DRAMsim/UpdateInterface.h \
	ioComponents/DRAMsim/constants.h \
	ioComponents/DRAMsim/utilities.h
$O/ioComponents/DRAMsim/DRAM_Sim.o: ioComponents/DRAMsim/DRAM_Sim.cc \
	ioComponents/DRAMsim/Aux_Stat.h \
	ioComponents/DRAMsim/BIU.h \
	ioComponents/DRAMsim/BIU_slot.h \
	ioComponents/DRAMsim/Bank.h \
	ioComponents/DRAMsim/Bus.h \
	ioComponents/DRAMsim/BusEvent.h \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/DIMM.h \
	ioComponents/DRAMsim/DRAM.h \
	ioComponents/DRAMsim/DRAM_Sim.h \
	ioComponents/DRAMsim/DRAM_config.h \
	ioComponents/DRAMsim/DRAMaddress.h \
	ioComponents/DRAMsim/Global_TQ_info.h \
	ioComponents/DRAMsim/Memory_Controller.h \
	ioComponents/DRAMsim/PendingInfo.h \
	ioComponents/DRAMsim/PendingQueue.h \
	ioComponents/DRAMsim/PowerConfig.h \
	ioComponents/DRAMsim/PowerCounter.h \
	ioComponents/DRAMsim/PowerMeasure.h \
	ioComponents/DRAMsim/RBRR.h \
	ioComponents/DRAMsim/Rank.h \
	ioComponents/DRAMsim/RefreshQueue.h \
	ioComponents/DRAMsim/Transaction.h \
	ioComponents/DRAMsim/TransactionQueue.h \
	ioComponents/DRAMsim/UpdateInterface.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/DRAM_config.o: ioComponents/DRAMsim/DRAM_config.cc \
	ioComponents/DRAMsim/Aux_Stat.h \
	ioComponents/DRAMsim/BIU.h \
	ioComponents/DRAMsim/BIU_slot.h \
	ioComponents/DRAMsim/Bank.h \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/DRAM_config.h \
	ioComponents/DRAMsim/DRAMaddress.h \
	ioComponents/DRAMsim/Global_TQ_info.h \
	ioComponents/DRAMsim/Transaction.h \
	ioComponents/DRAMsim/TransactionQueue.h \
	ioComponents/DRAMsim/UpdateInterface.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/DRAMaddress.o: ioComponents/DRAMsim/DRAMaddress.cc \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/DRAM_config.h \
	ioComponents/DRAMsim/DRAMaddress.h \
	ioComponents/DRAMsim/Global_TQ_info.h \
	ioComponents/DRAMsim/UpdateInterface.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/Global_TQ_info.o: ioComponents/DRAMsim/Global_TQ_info.cc \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/Global_TQ_info.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/Memory_Controller.o: ioComponents/DRAMsim/Memory_Controller.cc \
	ioComponents/DRAMsim/Aux_Stat.h \
	ioComponents/DRAMsim/BIU.h \
	ioComponents/DRAMsim/BIU_slot.h \
	ioComponents/DRAMsim/Bank.h \
	ioComponents/DRAMsim/Bus.h \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/DIMM.h \
	ioComponents/DRAMsim/DRAM.h \
	ioComponents/DRAMsim/DRAM_config.h \
	ioComponents/DRAMsim/DRAMaddress.h \
	ioComponents/DRAMsim/Global_TQ_info.h \
	ioComponents/DRAMsim/Memory_Controller.h \
	ioComponents/DRAMsim/PendingInfo.h \
	ioComponents/DRAMsim/PendingQueue.h \
	ioComponents/DRAMsim/PowerConfig.h \
	ioComponents/DRAMsim/PowerCounter.h \
	ioComponents/DRAMsim/PowerMeasure.h \
	ioComponents/DRAMsim/RBRR.h \
	ioComponents/DRAMsim/Rank.h \
	ioComponents/DRAMsim/RefreshQueue.h \
	ioComponents/DRAMsim/Transaction.h \
	ioComponents/DRAMsim/TransactionQueue.h \
	ioComponents/DRAMsim/UpdateInterface.h \
	ioComponents/DRAMsim/constants.h \
	ioComponents/DRAMsim/utilities.h
$O/ioComponents/DRAMsim/PendingQueue.o: ioComponents/DRAMsim/PendingQueue.cc \
	ioComponents/DRAMsim/PendingInfo.h \
	ioComponents/DRAMsim/PendingQueue.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/PowerConfig.o: ioComponents/DRAMsim/PowerConfig.cc \
	ioComponents/DRAMsim/Aux_Stat.h \
	ioComponents/DRAMsim/BIU.h \
	ioComponents/DRAMsim/BIU_slot.h \
	ioComponents/DRAMsim/Bank.h \
	ioComponents/DRAMsim/Bus.h \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/DIMM.h \
	ioComponents/DRAMsim/DRAM_config.h \
	ioComponents/DRAMsim/DRAMaddress.h \
	ioComponents/DRAMsim/Global_TQ_info.h \
	ioComponents/DRAMsim/Memory_Controller.h \
	ioComponents/DRAMsim/PendingInfo.h \
	ioComponents/DRAMsim/PendingQueue.h \
	ioComponents/DRAMsim/PowerConfig.h \
	ioComponents/DRAMsim/PowerCounter.h \
	ioComponents/DRAMsim/PowerMeasure.h \
	ioComponents/DRAMsim/RBRR.h \
	ioComponents/DRAMsim/Rank.h \
	ioComponents/DRAMsim/RefreshQueue.h \
	ioComponents/DRAMsim/Transaction.h \
	ioComponents/DRAMsim/TransactionQueue.h \
	ioComponents/DRAMsim/UpdateInterface.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/PrefetchCache.o: ioComponents/DRAMsim/PrefetchCache.cc \
	ioComponents/DRAMsim/PrefetchCache.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/RBRR.o: ioComponents/DRAMsim/RBRR.cc \
	ioComponents/DRAMsim/RBRR.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/RefreshQueue.o: ioComponents/DRAMsim/RefreshQueue.cc \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/RefreshQueue.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/Transaction.o: ioComponents/DRAMsim/Transaction.cc \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/DRAM_config.h \
	ioComponents/DRAMsim/DRAMaddress.h \
	ioComponents/DRAMsim/Global_TQ_info.h \
	ioComponents/DRAMsim/Transaction.h \
	ioComponents/DRAMsim/UpdateInterface.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/TransactionQueue.o: ioComponents/DRAMsim/TransactionQueue.cc \
	ioComponents/DRAMsim/Aux_Stat.h \
	ioComponents/DRAMsim/BIU.h \
	ioComponents/DRAMsim/BIU_slot.h \
	ioComponents/DRAMsim/Bank.h \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/DRAM_config.h \
	ioComponents/DRAMsim/DRAMaddress.h \
	ioComponents/DRAMsim/Global_TQ_info.h \
	ioComponents/DRAMsim/Transaction.h \
	ioComponents/DRAMsim/TransactionQueue.h \
	ioComponents/DRAMsim/UpdateInterface.h \
	ioComponents/DRAMsim/constants.h
$O/ioComponents/DRAMsim/utilities.o: ioComponents/DRAMsim/utilities.cc \
	ioComponents/DRAMsim/Command.h \
	ioComponents/DRAMsim/constants.h \
	ioComponents/DRAMsim/utilities.h
$O/photonic/activeelement.o: photonic/activeelement.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/basicelement.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/activemultiringelement.o: photonic/activemultiringelement.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activemultiringelement.h \
	photonic/basicelement.h \
	photonic/multiringelement.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/activeringelement.o: photonic/activeringelement.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activeringelement.h \
	photonic/basicelement.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/activetworingelement.o: photonic/activetworingelement.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activetworingelement.h \
	photonic/basicelement.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	photonic/tworingelement.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/basicelement.o: photonic/basicelement.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/basicelement.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/detectorelement.o: photonic/detectorelement.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/basicelement.h \
	photonic/detectorelement.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/domainchanger.o: photonic/domainchanger.cc \
	photonic/domainchanger.h \
	simCore/messages_m.h
$O/photonic/machzehnderelement.o: photonic/machzehnderelement.cc \
	photonic/machzehnderelement.h
$O/photonic/modulatorelement.o: photonic/modulatorelement.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/basicelement.h \
	photonic/modulatorelement.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/multiringelement.o: photonic/multiringelement.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/basicelement.h \
	photonic/multiringelement.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/phylayer.o: photonic/phylayer.cc \
	photonic/phylayer.h
$O/photonic/resonanceprofile.o: photonic/resonanceprofile.cc \
	photonic/resonanceprofile.h
$O/photonic/ringelement.o: photonic/ringelement.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/basicelement.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/tworingelement.o: photonic/tworingelement.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/basicelement.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	photonic/tworingelement.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/StarCoupler.o: photonic/devices/StarCoupler.cc \
	photonic/devices/StarCoupler.h
$O/photonic/devices/SwitchingFilter.o: photonic/devices/SwitchingFilter.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activeringelement.h \
	photonic/basicelement.h \
	photonic/devices/SwitchingFilter.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/activedirectionalcoupler.o: photonic/devices/activedirectionalcoupler.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/basicelement.h \
	photonic/devices/activedirectionalcoupler.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/attenuator.o: photonic/devices/attenuator.cc \
	photonic/devices/attenuator.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/photonic/devices/bend.o: photonic/devices/bend.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/basicelement.h \
	photonic/devices/bend.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/cross.o: photonic/devices/cross.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/basicelement.h \
	photonic/devices/cross.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/detector.o: photonic/devices/detector.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/basicelement.h \
	photonic/detectorelement.h \
	photonic/devices/detector.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	simCore/convert.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/end.o: photonic/devices/end.cc \
	photonic/devices/end.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/photonic/devices/facet.o: photonic/devices/facet.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/basicelement.h \
	photonic/devices/facet.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/filter1x2.o: photonic/devices/filter1x2.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/basicelement.h \
	photonic/devices/filter1x2.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/join.o: photonic/devices/join.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/basicelement.h \
	photonic/devices/join.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/laser.o: photonic/devices/laser.cc \
	photonic/devices/laser.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/photonic/devices/line.o: photonic/devices/line.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/basicelement.h \
	photonic/devices/line.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/modulator.o: photonic/devices/modulator.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/basicelement.h \
	photonic/devices/modulator.h \
	photonic/modulatorelement.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	simCore/convert.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/pse1x2.o: photonic/devices/pse1x2.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activeringelement.h \
	photonic/basicelement.h \
	photonic/devices/pse1x2.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/pse1x2nx.o: photonic/devices/pse1x2nx.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activeringelement.h \
	photonic/basicelement.h \
	photonic/devices/pse1x2nx.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/pse2x2.o: photonic/devices/pse2x2.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activeringelement.h \
	photonic/basicelement.h \
	photonic/devices/pse2x2.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/machzehnder/mzswitch1x2.o: photonic/devices/machzehnder/mzswitch1x2.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/basicelement.h \
	photonic/devices/machzehnder/mzswitch1x2.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/machzehnder/mzswitch2x2.o: photonic/devices/machzehnder/mzswitch2x2.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/basicelement.h \
	photonic/devices/machzehnder/mzswitch2x2.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/multiring/pse1x2multiring.o: photonic/devices/multiring/pse1x2multiring.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activemultiringelement.h \
	photonic/basicelement.h \
	photonic/devices/multiring/pse1x2multiring.h \
	photonic/multiringelement.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/multiring/pse1x2nxmultiring.o: photonic/devices/multiring/pse1x2nxmultiring.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activemultiringelement.h \
	photonic/basicelement.h \
	photonic/devices/multiring/pse1x2nxmultiring.h \
	photonic/multiringelement.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/multiring/pse1x2nxr2.o: photonic/devices/multiring/pse1x2nxr2.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activetworingelement.h \
	photonic/basicelement.h \
	photonic/devices/multiring/pse1x2nxr2.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	photonic/tworingelement.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/multiring/pse1x2nxr3.o: photonic/devices/multiring/pse1x2nxr3.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activemultiringelement.h \
	photonic/basicelement.h \
	photonic/devices/multiring/pse1x2nxr3.h \
	photonic/multiringelement.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/multiring/pse1x2r2.o: photonic/devices/multiring/pse1x2r2.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activetworingelement.h \
	photonic/basicelement.h \
	photonic/devices/multiring/pse1x2r2.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	photonic/tworingelement.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/multiring/pse1x2r3.o: photonic/devices/multiring/pse1x2r3.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activemultiringelement.h \
	photonic/basicelement.h \
	photonic/devices/multiring/pse1x2r3.h \
	photonic/multiringelement.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/multiring/pse2x2multiring.o: photonic/devices/multiring/pse2x2multiring.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activemultiringelement.h \
	photonic/basicelement.h \
	photonic/devices/multiring/pse2x2multiring.h \
	photonic/multiringelement.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/multiring/pse2x2r2.o: photonic/devices/multiring/pse2x2r2.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activetworingelement.h \
	photonic/basicelement.h \
	photonic/devices/multiring/pse2x2r2.h \
	photonic/phylayer.h \
	photonic/ringelement.h \
	photonic/tworingelement.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/photonic/devices/multiring/pse2x2r3.o: photonic/devices/multiring/pse2x2r3.cc \
	addon/thermalmodel.h \
	electronicComponents/orion/ORION_Config.h \
	photonic/activeelement.h \
	photonic/activemultiringelement.h \
	photonic/basicelement.h \
	photonic/devices/multiring/pse2x2r3.h \
	photonic/multiringelement.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/GatewaySignalControl.o: processingPlane/GatewaySignalControl.cc \
	processingPlane/GatewaySignalControl.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/processingPlane/Processor.o: processingPlane/Processor.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg_AllNodes.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR16x16.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR4x4.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR8x8.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/addressTranslation/AddressTranslator_FatTree.h \
	processingPlane/addressTranslation/AddressTranslator_SquareRoot.h \
	processingPlane/addressTranslation/AddressTranslator_Standard.h \
	processingPlane/apps/AppNull.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/DRAM/AppDRAMAll2One.h \
	processingPlane/apps/DRAM/AppDRAMOne2All.h \
	processingPlane/apps/DRAM/AppDRAMOne2One.h \
	processingPlane/apps/DRAM/AppDRAMRandom.h \
	processingPlane/apps/MITUCB/App_MITUCB_All2All.h \
	processingPlane/apps/MITUCB/App_MITUCB_Random.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/SizeDistribution/SizeDistribution_Constant.h \
	processingPlane/apps/SizeDistribution/SizeDistribution_Control.h \
	processingPlane/apps/SizeDistribution/SizeDistribution_Gamma.h \
	processingPlane/apps/SizeDistribution/SizeDistribution_InvGamma.h \
	processingPlane/apps/SizeDistribution/SizeDistribution_Normal.h \
	processingPlane/apps/model/AppDataFlow.h \
	processingPlane/apps/model/AppFFT.h \
	processingPlane/apps/model/AppFFTstream.h \
	processingPlane/apps/synthetics/AppBcast.h \
	processingPlane/apps/synthetics/AppBitreverse.h \
	processingPlane/apps/synthetics/AppHotspot.h \
	processingPlane/apps/synthetics/AppNeighbor.h \
	processingPlane/apps/synthetics/AppRandom.h \
	processingPlane/apps/synthetics/AppRandom_FiniteQueue.h \
	processingPlane/apps/synthetics/AppTornado.h \
	processingPlane/apps/test/AppAll2All.h \
	processingPlane/apps/test/AppOne2One.h \
	processingPlane/apps/trace/AppTrace_LBL.h \
	processingPlane/apps/trace/App_LL_DepGraph.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/ProcessorRouterArbiter.o: processingPlane/ProcessorRouterArbiter.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/RouterArbiter.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/ProcessorRouterArbiter.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/DRAM_Cfg/DRAM_Cfg.o: processingPlane/DRAM_Cfg/DRAM_Cfg.cc \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h
$O/processingPlane/DRAM_Cfg/DRAM_Cfg_AllNodes.o: processingPlane/DRAM_Cfg/DRAM_Cfg_AllNodes.cc \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg_AllNodes.h
$O/processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery.o: processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery.cc \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery.h
$O/processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR16x16.o: processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR16x16.cc \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR16x16.h
$O/processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR4x4.o: processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR4x4.cc \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR4x4.h
$O/processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR8x8.o: processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR8x8.cc \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg_Periphery_SR8x8.h
$O/processingPlane/addressTranslation/AddressTranslator.o: processingPlane/addressTranslation/AddressTranslator.cc \
	processingPlane/addressTranslation/AddressTranslator.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h
$O/processingPlane/addressTranslation/AddressTranslator_FatTree.o: processingPlane/addressTranslation/AddressTranslator_FatTree.cc \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/addressTranslation/AddressTranslator_FatTree.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h
$O/processingPlane/addressTranslation/AddressTranslator_SquareRoot.o: processingPlane/addressTranslation/AddressTranslator_SquareRoot.cc \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/addressTranslation/AddressTranslator_SquareRoot.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h
$O/processingPlane/addressTranslation/AddressTranslator_Standard.o: processingPlane/addressTranslation/AddressTranslator_Standard.cc \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/addressTranslation/AddressTranslator_Standard.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h
$O/processingPlane/apps/AppNull.o: processingPlane/apps/AppNull.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/AppNull.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/Application.o: processingPlane/apps/Application.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/DRAM/AppDRAMAll2One.o: processingPlane/apps/DRAM/AppDRAMAll2One.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/DRAM/AppDRAMAll2One.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/DRAM/AppDRAMOne2All.o: processingPlane/apps/DRAM/AppDRAMOne2All.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/DRAM/AppDRAMOne2All.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/DRAM/AppDRAMOne2One.o: processingPlane/apps/DRAM/AppDRAMOne2One.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/DRAM/AppDRAMOne2One.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/DRAM/AppDRAMRandom.o: processingPlane/apps/DRAM/AppDRAMRandom.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/DRAM/AppDRAMRandom.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/MITUCB/App_MITUCB_All2All.o: processingPlane/apps/MITUCB/App_MITUCB_All2All.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/MITUCB/App_MITUCB_All2All.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/MITUCB/App_MITUCB_Random.o: processingPlane/apps/MITUCB/App_MITUCB_Random.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/MITUCB/App_MITUCB_Random.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/SizeDistribution/SizeDistribution.o: processingPlane/apps/SizeDistribution/SizeDistribution.cc \
	processingPlane/apps/SizeDistribution/SizeDistribution.h
$O/processingPlane/apps/SizeDistribution/SizeDistribution_Constant.o: processingPlane/apps/SizeDistribution/SizeDistribution_Constant.cc \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/SizeDistribution/SizeDistribution_Constant.h
$O/processingPlane/apps/SizeDistribution/SizeDistribution_Control.o: processingPlane/apps/SizeDistribution/SizeDistribution_Control.cc \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/SizeDistribution/SizeDistribution_Control.h
$O/processingPlane/apps/SizeDistribution/SizeDistribution_Gamma.o: processingPlane/apps/SizeDistribution/SizeDistribution_Gamma.cc \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/SizeDistribution/SizeDistribution_Gamma.h
$O/processingPlane/apps/SizeDistribution/SizeDistribution_InvGamma.o: processingPlane/apps/SizeDistribution/SizeDistribution_InvGamma.cc \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/SizeDistribution/SizeDistribution_Gamma.h \
	processingPlane/apps/SizeDistribution/SizeDistribution_InvGamma.h
$O/processingPlane/apps/SizeDistribution/SizeDistribution_Normal.o: processingPlane/apps/SizeDistribution/SizeDistribution_Normal.cc \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/SizeDistribution/SizeDistribution_Normal.h
$O/processingPlane/apps/model/AppDataFlow.o: processingPlane/apps/model/AppDataFlow.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/model/AppDataFlow.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/model/AppFFT.o: processingPlane/apps/model/AppFFT.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/model/AppFFT.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/model/AppFFTstream.o: processingPlane/apps/model/AppFFTstream.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/model/AppFFTstream.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/synthetics/AppBcast.o: processingPlane/apps/synthetics/AppBcast.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/synthetics/AppBcast.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/synthetics/AppBitreverse.o: processingPlane/apps/synthetics/AppBitreverse.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/synthetics/AppBitreverse.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/synthetics/AppHotspot.o: processingPlane/apps/synthetics/AppHotspot.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/synthetics/AppHotspot.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/synthetics/AppNeighbor.o: processingPlane/apps/synthetics/AppNeighbor.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/synthetics/AppNeighbor.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/synthetics/AppRandom.o: processingPlane/apps/synthetics/AppRandom.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/synthetics/AppRandom.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/synthetics/AppRandom_FiniteQueue.o: processingPlane/apps/synthetics/AppRandom_FiniteQueue.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/synthetics/AppRandom_FiniteQueue.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/synthetics/AppTornado.o: processingPlane/apps/synthetics/AppTornado.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/synthetics/AppTornado.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/test/AppAll2All.o: processingPlane/apps/test/AppAll2All.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/test/AppAll2All.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/test/AppOne2One.o: processingPlane/apps/test/AppOne2One.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/test/AppOne2One.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/trace/AppTrace_LBL.o: processingPlane/apps/trace/AppTrace_LBL.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/trace/AppTrace_LBL.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/apps/trace/App_LL_DepGraph.o: processingPlane/apps/trace/App_LL_DepGraph.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/apps/trace/App_LL_DepGraph.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/interfaces/HybridController.o: processingPlane/interfaces/HybridController.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/interfaces/HybridController.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/interfaces/NIF.o: processingPlane/interfaces/NIF.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/interfaces/NIF.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/interfaces/NIF_Circuit.o: processingPlane/interfaces/NIF_Circuit.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/interfaces/NIF.h \
	processingPlane/interfaces/NIF_Circuit.h \
	processingPlane/interfaces/NIF_Packet_Credit.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/interfaces/NIF_Electronic.o: processingPlane/interfaces/NIF_Electronic.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/interfaces/NIF.h \
	processingPlane/interfaces/NIF_Electronic.h \
	processingPlane/interfaces/NIF_Packet_Credit.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/interfaces/NIF_ElectronicCC.o: processingPlane/interfaces/NIF_ElectronicCC.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/interfaces/NIF.h \
	processingPlane/interfaces/NIF_Circuit.h \
	processingPlane/interfaces/NIF_ElectronicCC.h \
	processingPlane/interfaces/NIF_Packet_Credit.h \
	processingPlane/interfaces/NIF_Photonic.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/interfaces/NIF_Packet_Credit.o: processingPlane/interfaces/NIF_Packet_Credit.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/interfaces/NIF.h \
	processingPlane/interfaces/NIF_Packet_Credit.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/interfaces/NIF_Photonic.o: processingPlane/interfaces/NIF_Photonic.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/interfaces/NIF.h \
	processingPlane/interfaces/NIF_Circuit.h \
	processingPlane/interfaces/NIF_Packet_Credit.h \
	processingPlane/interfaces/NIF_Photonic.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/interfaces/wNIF.o: processingPlane/interfaces/wNIF.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/interfaces/wNIF.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/packetstat.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/trafficGenerator/SyntheticGenerator.o: processingPlane/trafficGenerator/SyntheticGenerator.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/trafficGenerator/SyntheticGenerator.h \
	processingPlane/trafficGenerator/TGcore.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/trafficGenerator/TGcore.o: processingPlane/trafficGenerator/TGcore.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/trafficGenerator/TGcore.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/trafficGenerator/TraceBasedGenerator.o: processingPlane/trafficGenerator/TraceBasedGenerator.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/trafficGenerator/TGcore.h \
	processingPlane/trafficGenerator/TraceBasedGenerator.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/processingPlane/trafficGenerator/TrafficGenerator.o: processingPlane/trafficGenerator/TrafficGenerator.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	processingPlane/trafficGenerator/SyntheticGenerator.h \
	processingPlane/trafficGenerator/TGcore.h \
	processingPlane/trafficGenerator/TraceBasedGenerator.h \
	processingPlane/trafficGenerator/TrafficGenerator.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h
$O/simCore/NetworkAddress.o: simCore/NetworkAddress.cc \
	simCore/NetworkAddress.h \
	simCore/messages_m.h
$O/simCore/convert.o: simCore/convert.cc \
	simCore/convert.h \
	simCore/messages_m.h
$O/simCore/messages_m.o: simCore/messages_m.cc \
	simCore/messages_m.h
$O/simCore/packetstat.o: simCore/packetstat.cc \
	simCore/packetstat.h
$O/simCore/sim_includes.o: simCore/sim_includes.cc \
	simCore/debug.h \
	simCore/sim_includes.h \
	statistics/StatObject.h
$O/statistics/LogFile.o: statistics/LogFile.cc \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h
$O/statistics/StatGroup.o: statistics/StatGroup.cc \
	statistics/StatGroup.h \
	statistics/StatObject.h
$O/statistics/StatObject.o: statistics/StatObject.cc \
	statistics/StatObject.h
$O/statistics/statistics.o: statistics/statistics.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statGroups/StatGroup_ListAll.h \
	statistics/statGroups/StatGroup_Sum.h \
	statistics/statObjects/StatObject_Avg.h \
	statistics/statObjects/StatObject_Count.h \
	statistics/statObjects/StatObject_HURST.h \
	statistics/statObjects/StatObject_MMA.h \
	statistics/statObjects/StatObject_StaticTotal.h \
	statistics/statObjects/StatObject_TimeAvg.h \
	statistics/statObjects/StatObject_Total.h \
	statistics/statObjects/energy/StatObject_EnergyEvent.h \
	statistics/statObjects/energy/StatObject_EnergyOn.h \
	statistics/statObjects/energy/StatObject_EnergyStatic.h \
	statistics/statistics.h
$O/statistics/statGroups/StatGroup_ListAll.o: statistics/statGroups/StatGroup_ListAll.cc \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statGroups/StatGroup_ListAll.h
$O/statistics/statGroups/StatGroup_Sum.o: statistics/statGroups/StatGroup_Sum.cc \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statGroups/StatGroup_Sum.h
$O/statistics/statObjects/StatObject_Avg.o: statistics/statObjects/StatObject_Avg.cc \
	statistics/StatObject.h \
	statistics/statObjects/StatObject_Avg.h
$O/statistics/statObjects/StatObject_Count.o: statistics/statObjects/StatObject_Count.cc \
	statistics/StatObject.h \
	statistics/statObjects/StatObject_Count.h
$O/statistics/statObjects/StatObject_HURST.o: statistics/statObjects/StatObject_HURST.cc \
	statistics/StatObject.h \
	statistics/statObjects/StatObject_HURST.h
$O/statistics/statObjects/StatObject_MMA.o: statistics/statObjects/StatObject_MMA.cc \
	statistics/StatObject.h \
	statistics/statObjects/StatObject_MMA.h
$O/statistics/statObjects/StatObject_StaticTotal.o: statistics/statObjects/StatObject_StaticTotal.cc \
	statistics/StatObject.h \
	statistics/statObjects/StatObject_StaticTotal.h
$O/statistics/statObjects/StatObject_TimeAvg.o: statistics/statObjects/StatObject_TimeAvg.cc \
	statistics/StatObject.h \
	statistics/statObjects/StatObject_TimeAvg.h
$O/statistics/statObjects/StatObject_Total.o: statistics/statObjects/StatObject_Total.cc \
	statistics/StatObject.h \
	statistics/statObjects/StatObject_Total.h
$O/statistics/statObjects/energy/StatObject_EnergyEvent.o: statistics/statObjects/energy/StatObject_EnergyEvent.cc \
	statistics/StatObject.h \
	statistics/statObjects/energy/StatObject_EnergyEvent.h
$O/statistics/statObjects/energy/StatObject_EnergyOn.o: statistics/statObjects/energy/StatObject_EnergyOn.cc \
	statistics/StatObject.h \
	statistics/statObjects/energy/StatObject_EnergyOn.h
$O/statistics/statObjects/energy/StatObject_EnergyStatic.o: statistics/statObjects/energy/StatObject_EnergyStatic.cc \
	statistics/StatObject.h \
	statistics/statObjects/energy/StatObject_EnergyStatic.h
$O/topologies/photonicTDM/ScheduleItem.o: topologies/photonicTDM/ScheduleItem.cc \
	simCore/messages_m.h \
	topologies/photonicTDM/ScheduleItem.h
$O/topologies/photonicTDM/ETDM/ETDM_Switch_Controller.o: topologies/photonicTDM/ETDM/ETDM_Switch_Controller.cc \
	electronicComponents/orion/ORION_Config.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h \
	topologies/photonicTDM/ETDM/ETDM_Switch_Controller.h
$O/topologies/photonicTDM/ETDM/NIF_PhotonicETDM.o: topologies/photonicTDM/ETDM/NIF_PhotonicETDM.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/interfaces/NIF.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h \
	topologies/photonicTDM/ETDM/NIF_PhotonicETDM.h \
	topologies/photonicTDM/ScheduleItem.h
$O/topologies/photonicTDM/TDM/NIF_PhotonicTDM.o: topologies/photonicTDM/TDM/NIF_PhotonicTDM.cc \
	addon/thermalmodel.h \
	electronicComponents/Arbiters/Arbiter.h \
	electronicComponents/Arbiters/ArbiterCanRoute.h \
	electronicComponents/VC_Control.h \
	electronicComponents/VirtualChannelControl.h \
	electronicComponents/orion/ORION_Arbiter.h \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	processingPlane/DRAM_Cfg/DRAM_Cfg.h \
	processingPlane/Processor.h \
	processingPlane/addressTranslation/AddressTranslator.h \
	processingPlane/apps/Application.h \
	processingPlane/apps/SizeDistribution/SizeDistribution.h \
	processingPlane/interfaces/NIF.h \
	simCore/NetworkAddress.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h \
	topologies/photonicTDM/ScheduleItem.h \
	topologies/photonicTDM/TDM/NIF_PhotonicTDM.h
$O/topologies/photonicTDM/TDM/TDM_Switch_Controller.o: topologies/photonicTDM/TDM/TDM_Switch_Controller.cc \
	electronicComponents/orion/ORION_Array.h \
	electronicComponents/orion/ORION_Array_Info.h \
	electronicComponents/orion/ORION_Array_Internal.h \
	electronicComponents/orion/ORION_Config.h \
	electronicComponents/orion/ORION_Link.h \
	electronicComponents/orion/ORION_Util.h \
	photonic/phylayer.h \
	simCore/messages_m.h \
	simCore/sim_includes.h \
	statistics/LogFile.h \
	statistics/StatGroup.h \
	statistics/StatObject.h \
	statistics/statistics.h \
	topologies/photonicTDM/TDM/TDM_Switch_Controller.h

