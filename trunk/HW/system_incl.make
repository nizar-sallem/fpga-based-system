#################################################################
# Makefile generated by Xilinx Platform Studio 
# Project:C:\Baseline_9_Working_Folder\K-Fall09-Working_Copy\system.xmp
#
# WARNING : This file will be re-generated every time a command
# to run a make target is invoked. So, any changes made to this  
# file manually, will be lost when make is invoked next. 
#################################################################

XILINX_EDK_DIR = C:/EDK

SYSTEM = system

MHSFILE = system.mhs

MSSFILE = system.mss

FPGA_ARCH = virtex2p

DEVICE = xc2vp100ff1704-6

LANGUAGE = vhdl

SEARCHPATHOPT = 

SUBMODULE_OPT = 

PLATGEN_OPTIONS = -p $(DEVICE) -lang $(LANGUAGE) $(SEARCHPATHOPT) $(SUBMODULE_OPT)

LIBGEN_OPTIONS = -mhs $(MHSFILE) -p $(DEVICE) $(SEARCHPATHOPT)

VPGEN_OPTIONS = -p $(DEVICE) $(SEARCHPATHOPT)

EX1_OS_OUTPUT_DIR = EX1_OS
EX1_OS_OUTPUT = $(EX1_OS_OUTPUT_DIR)/executable.elf

MICROBLAZE_BOOTLOOP = $(XILINX_EDK_DIR)/sw/lib/microblaze/mb_bootloop.elf
PPC405_BOOTLOOP = $(XILINX_EDK_DIR)/sw/lib/ppc405/ppc_bootloop.elf
PPC440_BOOTLOOP = $(XILINX_EDK_DIR)/sw/lib/ppc440/ppc440_bootloop.elf
BOOTLOOP_DIR = bootloops

PPC405_I_BOOTLOOP = $(BOOTLOOP_DIR)/ppc405_i.elf

PPC405_PPCJTAG_CHAIN_BOOTLOOP = $(BOOTLOOP_DIR)/ppc405_ppcjtag_chain.elf

BRAMINIT_ELF_FILES =  $(EX1_OS_OUTPUT) 
BRAMINIT_ELF_FILE_ARGS =   -pe ppc405_i $(EX1_OS_OUTPUT) 

ALL_USER_ELF_FILES = $(EX1_OS_OUTPUT) 

SIM_CMD = vsim

BEHAVIORAL_SIM_SCRIPT = simulation/behavioral/$(SYSTEM).do

STRUCTURAL_SIM_SCRIPT = simulation/structural/$(SYSTEM).do

TIMING_SIM_SCRIPT = simulation/timing/$(SYSTEM).do

DEFAULT_SIM_SCRIPT = $(BEHAVIORAL_SIM_SCRIPT)

MIX_LANG_SIM_OPT = -mixed yes

SIMGEN_OPTIONS = -p $(DEVICE) -lang $(LANGUAGE) $(SEARCHPATHOPT) $(BRAMINIT_ELF_FILE_ARGS) $(MIX_LANG_SIM_OPT)  -s mti -X C:/Baseline_9_Working_Folder/K-test-baseline_userip_uart_CMC_9.1.02 -E C:/Baseline_9_Working_Folder/K-test-baseline_userip_uart_CMC_9.1.02


LIBRARIES =  \
       ppc405_i/lib/libxil.a  \
       ppc405_ppcjtag_chain/lib/libxil.a 
VPEXEC = virtualplatform/vpexec.exe

LIBSCLEAN_TARGETS = ppc405_i_libsclean ppc405_ppcjtag_chain_libsclean 

PROGRAMCLEAN_TARGETS = EX1_OS_programclean 

CORE_STATE_DEVELOPMENT_FILES = 

WRAPPER_NGC_FILES = implementation/clock_reset_block_wrapper.ngc \
implementation/ppc405_i_wrapper.ngc \
implementation/plb_bus_wrapper.ngc \
implementation/plb_ddr_controller_i_wrapper.ngc \
implementation/plb_bram_if_cntlr_i_wrapper.ngc \
implementation/bram_wrapper.ngc \
implementation/plb2opb_bridge_i_wrapper.ngc \
implementation/opb_bus_wrapper.ngc \
implementation/ap1000_interrupt_interface_i_wrapper.ngc \
implementation/opb_intc_i_wrapper.ngc \
implementation/rs232_1_wrapper.ngc \
implementation/opbslave_ext_bridge_i_wrapper.ngc \
implementation/plb_psb_bridge_i_wrapper.ngc \
implementation/dcr_bus_wrapper.ngc \
implementation/ppc405_ppcjtag_chain_wrapper.ngc \
implementation/jtagppc_0_wrapper.ngc \
implementation/plb_emc_0_wrapper.ngc \
implementation/opb_gpio_0_wrapper.ngc \
implementation/opb_timer_0_wrapper.ngc \
implementation/hwrtos_0_wrapper.ngc

POSTSYN_NETLIST = implementation/$(SYSTEM).ngc

SYSTEM_BIT = implementation/$(SYSTEM).bit

DOWNLOAD_BIT = implementation/download.bit

SYSTEM_ACE = implementation/$(SYSTEM).ace

UCF_FILE = data/system.ucf

BMM_FILE = implementation/$(SYSTEM).bmm

BITGEN_UT_FILE = etc/bitgen.ut

XFLOW_OPT_FILE = etc/fast_runtime.opt
XFLOW_DEPENDENCY = __xps/xpsxflow.opt $(XFLOW_OPT_FILE)

XPLORER_DEPENDENCY = __xps/xplorer.opt
XPLORER_OPTIONS = -p $(DEVICE) -uc $(SYSTEM).ucf -bm $(SYSTEM).bmm -max_runs 7

FPGA_IMP_DEPENDENCY = $(BMM_FILE) $(POSTSYN_NETLIST) $(UCF_FILE) $(BITGEN_UT_FILE) $(XFLOW_DEPENDENCY)

#################################################################
# SOFTWARE APPLICATION EX1_OS
#################################################################

EX1_OS_SOURCES = C:/Micrium/SOFTWARE/EvalBoards/Amirix/AP1000/GNU/EX1_OS/app.c 

EX1_OS_HEADERS = 

EX1_OS_CC = powerpc-eabi-gcc
EX1_OS_CC_SIZE = powerpc-eabi-size
EX1_OS_CC_OPT = -O0
EX1_OS_CFLAGS = 
EX1_OS_CC_SEARCH = # -B
EX1_OS_LIBPATH = -L./ppc405_i/lib/ # -L
EX1_OS_INCLUDES = -I./ppc405_i/include/ # -I
EX1_OS_LFLAGS = # -l
EX1_OS_LINKER_SCRIPT = 
EX1_OS_LINKER_SCRIPT_FLAG = #-Wl,-T -Wl,$(EX1_OS_LINKER_SCRIPT) 
EX1_OS_CC_DEBUG_FLAG =  -g 
EX1_OS_CC_PROFILE_FLAG = # -pg
EX1_OS_CC_GLOBPTR_FLAG= # -msdata=eabi
EX1_OS_CC_INFERRED_FLAGS= 
EX1_OS_CC_START_ADDR_FLAG=  # -Wl,-defsym -Wl,_START_ADDR=
EX1_OS_CC_STACK_SIZE_FLAG=  # -Wl,-defsym -Wl,_STACK_SIZE=
EX1_OS_CC_HEAP_SIZE_FLAG=  # -Wl,-defsym -Wl,_HEAP_SIZE=
EX1_OS_OTHER_CC_FLAGS= $(EX1_OS_CC_GLOBPTR_FLAG)  \
                  $(EX1_OS_CC_START_ADDR_FLAG) $(EX1_OS_CC_STACK_SIZE_FLAG) $(EX1_OS_CC_HEAP_SIZE_FLAG)  \
                  $(EX1_OS_CC_INFERRED_FLAGS)  \
                  $(EX1_OS_LINKER_SCRIPT_FLAG) $(EX1_OS_CC_DEBUG_FLAG) $(EX1_OS_CC_PROFILE_FLAG) 
