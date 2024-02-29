#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "modbuswrappers::modbuswrappers" for configuration "Debug"
set_property(TARGET modbuswrappers::modbuswrappers APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(modbuswrappers::modbuswrappers PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/modbuswrappersd.lib"
  )

list(APPEND _cmake_import_check_targets modbuswrappers::modbuswrappers )
list(APPEND _cmake_import_check_files_for_modbuswrappers::modbuswrappers "${_IMPORT_PREFIX}/lib/modbuswrappersd.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
