#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "utils::utils" for configuration "Debug"
set_property(TARGET utils::utils APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(utils::utils PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/utilsd.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/utilsd.dll"
  )

list(APPEND _cmake_import_check_targets utils::utils )
list(APPEND _cmake_import_check_files_for_utils::utils "${_IMPORT_PREFIX}/lib/utilsd.lib" "${_IMPORT_PREFIX}/bin/utilsd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
