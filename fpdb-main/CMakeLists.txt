project(fpdb-main VERSION "${PROJECT_VERSION}" LANGUAGES C CXX)


#-----------------------------------------------------------------------------------------------------------------------
# Targets
#-----------------------------------------------------------------------------------------------------------------------

# fpdb-main-client
add_library(fpdb-main
        src/ExecConfig.cpp include/fpdb/main/ExecConfig.h
        include/fpdb/main/ActorSystemConfig.h
        src/CAFInit.cpp include/fpdb/main/CAFInit.h
        src/Client.cpp include/fpdb/main/Client.h
        src/Server.cpp include/fpdb/main/Server.h)

target_include_directories(fpdb-main PUBLIC include)

target_link_libraries(fpdb-main PUBLIC fpdb-executor)
target_link_libraries(fpdb-main PUBLIC fpdb-util)
target_link_libraries(fpdb-main PUBLIC ssl crypto)


# fpdb-main-client
add_executable(fpdb-main-client
        src/ClientMain.cpp)

target_link_libraries(fpdb-main-client PRIVATE fpdb-main)
# need to add and link libraries on mac
if (${APPLE})
  linkForMacExecutable(fpdb-main-client)
endif()

add_dependencies(fpdb-main-client resources)


# fpdb-main-server
add_executable(fpdb-main-server
        src/ServerMain.cpp)

target_link_libraries(fpdb-main-server PRIVATE fpdb-main)
if (${APPLE})
  linkForMacExecutable(fpdb-main-server)
endif()

add_dependencies(fpdb-main-server resources)


#-----------------------------------------------------------------------------------------------------------------------
# Test
#-----------------------------------------------------------------------------------------------------------------------

add_executable(fpdb-main-test
        test/Globals.h
        test/TestUtil.cpp test/TestUtil.h
        test/MainTest.cpp
        test/SSBTest.cpp
        test/TPCHTest.cpp
        test/TPCHDistTest.cpp)

target_link_libraries(fpdb-main-test PRIVATE fpdb-main)
target_link_libraries(fpdb-main-test PRIVATE doctest::doctest)
# need to add and link libraries on mac
if (${APPLE})
  linkForMacExecutable(fpdb-main-test)
endif()

add_dependencies(fpdb-main-test resources)
