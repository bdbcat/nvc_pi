##---------------------------------------------------------------------------
## Author:      Pavel Kalian Dave Register
## Copyright:
## License:     wxWidgets License
##---------------------------------------------------------------------------

# define minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2)

PROJECT(nvc_pi)

SET(PACKAGE_NAME nvc_pi)
SET(VERBOSE_NAME NVCChartPlugin)
SET(TITLE_NAME NVCChartPlugin)
SET(CPACK_PACKAGE_CONTACT "Dave Register")

SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "4")

#SET(CMAKE_BUILD_TYPE Debug)

INCLUDE("cmake/PluginConfigure.cmake")

SET(SRC_NVC
            src/nvc_pi.h
            src/nvc_pi.cpp
            src/chart.cpp
            src/chart.h
            src/ellipse.c
     )
ADD_LIBRARY(${PACKAGE_NAME} SHARED ${SRC_NVC})

IF(WIN32)
  SET(OPENCPN_IMPORT_LIB "C:/Projects/opencpn/build/${CMAKE_CFG_INTDIR}/opencpn.lib")
  TARGET_LINK_LIBRARIES( ${PACKAGE_NAME} ${OPENCPN_IMPORT_LIB} )
ENDIF(WIN32)


INCLUDE("cmake/PluginInstall.cmake")
INCLUDE("cmake/PluginLocalization.cmake")
INCLUDE("cmake/PluginPackage.cmake")
