
#-----------------------------------------------------------------------

APP       := MonitApp
TARGET    := CacheServer
CONFIG    := 
STRIP_FLAG:= N
TARS2CPP_FLAG:= 

# INCLUDE   += -I./jce/
INCLUDE   += -I/home/trunk-withithoutBussi/MonitApp/tarsCommon/
INCLUDE   += -I/home/MonitApp/CacheServer/Config
INCLUDE   += -I/home/trunk-withithoutBussi/MonitApp/Common/Lab628TarsLib/ConfigHolder/

# LIB
LIB       += -L/home/trunk-withithoutBussi/MonitApp/Common/Lab628TarsLib/ConfigHolder -lConfigHolder

LOCAL_SRC += $(wildcard ./Config/*.cpp)

#-----------------------------------------------------------------------

include /usr/local/tars/cpp/makefile/makefile.tars

#-----------------------------------------------------------------------
