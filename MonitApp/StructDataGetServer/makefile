
#-----------------------------------------------------------------------

APP       := MonitApp
TARGET    := StructDataGetServer
CONFIG    := 
STRIP_FLAG:= N
TARS2CPP_FLAG:= 

# INCLUDE   += -I./jce/
# INCLUDE	  += -I/home/tarsjce/MonitApp/tarsCommon/
INCLUDE   += -I/home/trunk-withithoutBussi/MonitApp/tarsCommon/
INCLUDE   += -I/home/MonitApp/StructDataGetServer/Config
INCLUDE   += -I/home/MonitApp/StructDataGetServer/Context
INCLUDE   += -I/home/MonitApp/StructDataGetServer/Shared
INCLUDE   += -I/home/MonitApp/StructDataGetServer/Logic

# CacheServer
INCLUDE   += -I/home/MonitApp/DBServer/

INCLUDE   += -I/home/MonitApp/CacheServer/

## ConfigHolder
INCLUDE   += -I/home/trunk-withithoutBussi/MonitApp/Common/Lab628TarsLib/ConfigHolder/
LIB       += -L/home/trunk-withithoutBussi/MonitApp/Common/Lab628TarsLib/ConfigHolder -lConfigHoldel

LIB       += 
LOCAL_SRC += /home/MonitApp/StructDataGetServer/Logic/
LOCAL_SRC += /home/MonitApp/StructDataGetServer/Config/
LOCAL_SRC += /home/MonitApp/StructDataGetServer/Context/
LOCAL_SRC += /home/MonitApp/StructDataGetServer/Shared/
LOCAL_SRC += /home/MonitApp/StructDataGetServer/Callback/
#-----------------------------------------------------------------------

include /usr/local/tars/cpp/makefile/makefile.tars
include /home/tarsproto/MonitApp/DBServer/DBServer.mk
include /home/tarsproto/MonitApp/CacheServer/CacheServer.mk
#-----------------------------------------------------------------------
