cmake_minimum_required(VERSION 3.5)
project(CHeaders)

set (HEADER_FILES Debug.h GameElements.h GameFonts.h GameMath.h)
file(INSTALL ${HEADER_FILES} DESTINATION $ENV{DEVPATH}\\headers)
