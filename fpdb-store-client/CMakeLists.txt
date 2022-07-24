
#-----------------------------------------------------------------------------------------------------------------------
# Library
#-----------------------------------------------------------------------------------------------------------------------

add_library(fpdb_store_client_objlib OBJECT
        src/Module.cpp include/fpdb/store/client/Module.hpp)

set_target_properties(fpdb_store_client_objlib PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties(fpdb_store_client_objlib PROPERTIES OUTPUT_NAME fpdb_store_client)

target_include_directories(fpdb_store_client_objlib PUBLIC include)

add_library(fpdb_store_client_static STATIC $<TARGET_OBJECTS:fpdb_store_client_objlib>)
set_target_properties(fpdb_store_client_static PROPERTIES OUTPUT_NAME $<TARGET_PROPERTY:fpdb_store_client_objlib,OUTPUT_NAME>)
target_include_directories(fpdb_store_client_static PUBLIC $<TARGET_PROPERTY:fpdb_store_client_objlib,INCLUDE_DIRECTORIES>)

add_library(fpdb_store_client_shared SHARED $<TARGET_OBJECTS:fpdb_store_client_objlib>)
set_target_properties(fpdb_store_client_shared PROPERTIES OUTPUT_NAME $<TARGET_PROPERTY:fpdb_store_client_objlib,OUTPUT_NAME>)
target_include_directories(fpdb_store_client_shared PUBLIC $<TARGET_PROPERTY:fpdb_store_client_objlib,INCLUDE_DIRECTORIES>)


#-----------------------------------------------------------------------------------------------------------------------
# Tests
#-----------------------------------------------------------------------------------------------------------------------

add_executable(fpdb_store_client_test
        test/Module.cpp test/Module.hpp)

target_link_libraries(fpdb_store_client_test fpdb_store_client_shared)
# need to add and link libraries on mac
if (${APPLE})
    linkForMacExecutable(fpdb_store_client_test)
endif()
