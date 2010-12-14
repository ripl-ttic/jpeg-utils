add_definitions(-Wall)

set(IPP_SRC)

if(IPP_FOUND AND USE_IPP)
    file(GLOB IPP_SRC ipp/*.c ipp/*.h)
    link_directories("${IPP_PATH}")
endif()

if(${CMAKE_INSTALL_RPATH})
    set(CMAKE_INSTALL_RPATH ${IPP_PATH}:${CMAKE_INSTALL_RPATH})
else(${CMAKE_INSTALL_RPATH})
    set(CMAKE_INSTALL_RPATH ${IPP_PATH})
endif(${CMAKE_INSTALL_RPATH})

# Create a shared library 
add_library(jpeg-utils SHARED 
    jpeg-utils.c 
    jpeg-utils-ijg.c
    ${IPP_SRC})

# set the library API version.  Increment this every time the public API
# changes.
set_target_properties(jpeg-utils PROPERTIES SOVERSION 1)

if(IPP_FOUND AND USE_IPP)
#target_link_libraries(jpeg-utils ${IPP_LIBS})
#target_link_libraries(jpeg-utils -lippj -lippi -lipps -lippcore)
#message("link dir: ${IPP_PATH}/../sharedlib")
#target_link_libraries(jpeg-utils -lguide -lippcoreem64t -lippjem64t -lippiem64t -lippsem64t -lpthread -lippccem64t -lippcvem64t -liomp5 -lpthread)
target_link_libraries(jpeg-utils -lippjem64t -lippiem64t -lippsem64t -lippcoreem64t -lguide -lippcoreem64t -lippiem64t -lippjem64t -lippccem64t -lippcvem64t -lpthread -lippsem64t)
#                       IPP_LIBS:=-lguide -lippcoreem64t -lippiem64t -lippjem64t -lippccem64t -lippcvem64t -lpthread -lippsem64t
endif()

#message("linking against ${IPP_LIBS}")

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
