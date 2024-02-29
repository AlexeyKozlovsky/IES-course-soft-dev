#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "modbuswrappers::modbuswrappers" for configuration "Release"
set_property(TARGET modbuswrappers::modbuswrappers APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(modbuswrappers::modbuswrappers PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/modbuswrappers.lib"
  )

list(APPEND _cmake_import_check_targets modbuswrappers::modbuswrappers )
list(APPEND _cmake_import_check_files_for_modbuswrappers::modbuswrappers "${_IMPORT_PREFIX}/lib/modbuswrappers.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
