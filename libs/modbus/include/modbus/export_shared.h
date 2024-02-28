
#ifndef MODBUS_EXPORT_H
#define MODBUS_EXPORT_H

#ifdef MODBUS_STATIC_DEFINE
#  define MODBUS_EXPORT
#  define MODBUS_NO_EXPORT
#else
#  ifndef MODBUS_EXPORT
#    ifdef modbus_EXPORTS
        /* We are building this library */
#      define MODBUS_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define MODBUS_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef MODBUS_NO_EXPORT
#    define MODBUS_NO_EXPORT 
#  endif
#endif

#ifndef MODBUS_DEPRECATED
#  define MODBUS_DEPRECATED __declspec(deprecated)
#endif

#ifndef MODBUS_DEPRECATED_EXPORT
#  define MODBUS_DEPRECATED_EXPORT MODBUS_EXPORT MODBUS_DEPRECATED
#endif

#ifndef MODBUS_DEPRECATED_NO_EXPORT
#  define MODBUS_DEPRECATED_NO_EXPORT MODBUS_NO_EXPORT MODBUS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MODBUS_NO_DEPRECATED
#    define MODBUS_NO_DEPRECATED
#  endif
#endif

#endif /* MODBUS_EXPORT_H */
