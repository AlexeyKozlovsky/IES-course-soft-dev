#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "modbus::modbus" for configuration "Debug"
set_property(TARGET modbus::modbus APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(modbus::modbus PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/modbusd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/modbusd.dll"
  )

list(APPEND _cmake_import_check_targets modbus::modbus )
list(APPEND _cmake_import_check_files_for_modbus::modbus "${_IMPORT_PREFIX}/lib/modbusd.lib" "${_IMPORT_PREFIX}/bin/modbusd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
