# - Use CMake's module to help generating relocatable config files
include(CMakePackageConfigHelpers)

# - Versioning
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/EDM4HEPUtilsConfigVersion.cmake
  VERSION ${EDM4HEPUtils_VERSION}
  COMPATIBILITY SameMajorVersion)

# - Install time config and target files
configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/EDM4HEPUtilsConfig.cmake.in
  "${PROJECT_BINARY_DIR}/EDM4HEPUtilsConfig.cmake"
  INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/EDM4HEPUtils"
  PATH_VARS
    CMAKE_INSTALL_BINDIR
    CMAKE_INSTALL_INCLUDEDIR
    CMAKE_INSTALL_LIBDIR
  )

# - install and export
install(FILES
  "${PROJECT_BINARY_DIR}/EDM4HEPUtilsConfigVersion.cmake"
  "${PROJECT_BINARY_DIR}/EDM4HEPUtilsConfig.cmake"
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/EDM4HEPUtils"
  )
install(EXPORT EDM4HEPUtilsTargets
  NAMESPACE EDM4HEPUtils::
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/EDM4HEPUtils"
  )
