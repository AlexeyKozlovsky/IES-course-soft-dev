
#ifndef THREADPOOLING_EXPORT_H
#define THREADPOOLING_EXPORT_H

#ifdef THREADPOOLING_STATIC_DEFINE
#  define THREADPOOLING_EXPORT
#  define THREADPOOLING_NO_EXPORT
#else
#  ifndef THREADPOOLING_EXPORT
#    ifdef threadpooling_EXPORTS
        /* We are building this library */
#      define THREADPOOLING_EXPORT 
#    else
        /* We are using this library */
#      define THREADPOOLING_EXPORT 
#    endif
#  endif

#  ifndef THREADPOOLING_NO_EXPORT
#    define THREADPOOLING_NO_EXPORT 
#  endif
#endif

#ifndef THREADPOOLING_DEPRECATED
#  define THREADPOOLING_DEPRECATED __declspec(deprecated)
#endif

#ifndef THREADPOOLING_DEPRECATED_EXPORT
#  define THREADPOOLING_DEPRECATED_EXPORT THREADPOOLING_EXPORT THREADPOOLING_DEPRECATED
#endif

#ifndef THREADPOOLING_DEPRECATED_NO_EXPORT
#  define THREADPOOLING_DEPRECATED_NO_EXPORT THREADPOOLING_NO_EXPORT THREADPOOLING_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef THREADPOOLING_NO_DEPRECATED
#    define THREADPOOLING_NO_DEPRECATED
#  endif
#endif

#endif /* THREADPOOLING_EXPORT_H */
