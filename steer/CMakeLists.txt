# CMakeList file for library libAnalysisTreeQASteer
# F. Linz,     18 July 2023

include(AnalysisTree)

set(SOURCES
  Config.cpp
  Run.cpp
  TaskFactory.cpp
)

string(REPLACE ".cpp" ".hpp" HEADERS "${SOURCES}")

add_definitions(-DWITH_EXECUTION)

include_directories(${CMAKE_SOURCE_DIR}/src ${AnalysisTree_BINARY_DIR}/include)

add_library(AnalysisTreeQASteer SHARED ${SOURCES})
ROOT_GENERATE_DICTIONARY(G__AnalysisTreeQASteer ${HEADERS} MODULE AnalysisTreeQASteer AnalysisTreeQASteerLinkDef.h)

target_link_libraries(AnalysisTreeQASteer 
	PUBLIC
	AnalysisTreeQA
	AnalysisTreeBase
	AnalysisTreeInfra
	yaml-cpp
)
target_include_directories(AnalysisTreeQASteer
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>	
)

install( TARGETS AnalysisTreeQASteer EXPORT AnalysisTreeQASteerTargets
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION lib
	INCLUDES DESTINATION include
)

install(
	FILES
	${HEADERS}
	DESTINATION
	include/AnalysisTreeQASteer
	COMPONENT
	Devel
)

set(PCM_FILE_NAME libAnalysisTreeQASteer)

install(
	FILES
	"${CMAKE_CURRENT_BINARY_DIR}/${PCM_FILE_NAME}_rdict.pcm"
	DESTINATION
	lib
	OPTIONAL
)

install(
	FILES
	"${CMAKE_CURRENT_BINARY_DIR}/${PCM_FILE_NAME}.rootmap"
	DESTINATION
	lib
	OPTIONAL
)
