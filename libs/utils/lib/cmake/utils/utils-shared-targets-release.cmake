#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "utils::utils" for configuration "Release"
set_property(TARGET utils::utils APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(utils::utils PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/utils.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/utils.dll"
  )

list(APPEND _cmake_import_check_targets utils::utils )
list(APPEND _cmake_import_check_files_for_utils::utils "${_IMPORT_PREFIX}/lib/utils.lib" "${_IMPORT_PREFIX}/bin/utils.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
