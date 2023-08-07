# CMakeList file for binary AnalysisTreeQA
# F. Linz,     18 July 2023

include(AnalysisTree)

set(SOURCES
  Application.cpp
  ProgramOptions.cpp
  )

string(REGEX REPLACE ".cpp" ".hpp" HEADERS "${SOURCES}")
list(APPEND SOURCES "main.cpp")

include_directories(${PROJECT_INCLUDE_DIRECTORIES} ${CMAKE_CURRENT_SOURCE_DIR} ${AnalysisTree_BINARY_DIR}/include ${CMAKE_SOURCE_DIR}/steer)
link_directories(${PROJECT_LINK_DIRECTORIES} ${Boost_LIBRARY_DIRS})
message(STATUS "AnalysisTree_BINARY DIR = ${AnalysisTree_BINARY_DIR}")
message(STATUS "Boost library location : ${Boost_LIBRARY_DIRS}")

add_executable(RunAnalysisTreeQA ${SOURCES} ${HEADERS})
add_dependencies(RunAnalysisTreeQA AnalysisTreeQASteer)

target_link_libraries(RunAnalysisTreeQA
  PUBLIC
    AnalysisTreeQASteer
    AnalysisTreeQA
    AnalysisTreeBase
    AnalysisTreeInfra
    ${Boost_LIBRARY_DIRS}/libboost_program_options.so
  )

install(TARGETS RunAnalysisTreeQA RUNTIME DESTINATION bin)
