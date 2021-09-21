set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

file( GLOB SRC_FILES *.cxx )
foreach( SRC_PATH ${SRC_FILES} )
    # I used a simple string replace, to cut off .cpp.
    get_filename_component(EXECUTABLE_NAME ${SRC_PATH} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SRC_PATH})
    # set_property(TARGET ${testname} PROPERTY POSITION_INDEPENDENT_CODE TRUE)
    target_link_libraries(${EXECUTABLE_NAME} qupid ROOT::Core ROOT::Gpad ROOT::Hist ROOT::Tree)
endforeach( SRC_PATH ${SRC_FILES} )
message(STATUS "Target Executable TEST: ${SRC_FILES}")
