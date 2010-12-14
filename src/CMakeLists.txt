add_definitions(-Wall)

set(IPP_SRC)

if(IPP_FOUND AND USE_IPP)
    file(GLOB IPP_SRC ipp/*.c ipp/*.h)
endif()

# Create a shared library 
add_library(jpeg-utils SHARED 
    jpeg-utils.c 
    jpeg-utils-ijg.c
    ${IPP_SRC})

# set the library API version.  Increment this every time the public API
# changes.
set_target_properties(jpeg-utils PROPERTIES SOVERSION 1)

# make the header public
# install it to include/hello
pods_install_headers(jpeg-utils.h DESTINATION jpeg-utils)

# make the library public
pods_install_libraries(jpeg-utils)

# create a pkg-config file for the library, to make it for other software to
# use it.
pods_install_pkg_config_file(jpeg-utils
    CFLAGS
    LIBS -ljpeg-utils -ljpeg
    VERSION 0.0.1)
