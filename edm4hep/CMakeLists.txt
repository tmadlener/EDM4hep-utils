add_library(kinematics INTERFACE)
target_include_directories(kinematics
  INTERFACE $<BUILD_INTERFACE:${${PROJECT_NAME}_SOURCE_DIR}>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_link_libraries(kinematics PUBLIC INTERFACE ROOT::Core)
target_compile_features(kinematics INTERFACE cxx_std_17)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/edm4hep/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/edm4hep
  PATTERN "CMakeLists.txt" EXCLUDE)

install(TARGETS kinematics
  EXPORT EDM4HEPUtilsTargets
  )
