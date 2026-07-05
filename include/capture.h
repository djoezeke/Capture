/**
 * @file capture/capture.h
 */

#if !defined(DJOEZEKE_CAPTURE) || !defined(CAPTURE_VERSION) || (CAPTURE_VERSION < 1)
#define DJOEZEKE_CAPTURE

// clang-format off

//-----------------------------------------------------------------------------
// [SECTION] Utility Macros
//-----------------------------------------------------------------------------

#ifdef CAPTURE_STRINGIFY_IMPL
    #undef CAPTURE_STRINGIFY_IMPL
#endif // CAPTURE_STRINGIFY_IMPL

#define CAPTURE_STRINGIFY_IMPL(x) #x

#ifdef CAPTURE_STRINGIFY
    #undef CAPTURE_STRINGIFY
#endif // CAPTURE_STRINGIFY

#define CAPTURE_STRINGIFY(x) CAPTURE_STRINGIFY_IMPL(x)

#ifdef CAPTURE_CONCAT_IMPL
    #undef CAPTURE_CONCAT_IMPL
#endif // CAPTURE_CONCAT_IMPL

#define CAPTURE_CONCAT_IMPL(a,b) a##b

#ifdef CAPTURE_CONCAT
    #undef CAPTURE_CONCAT
#endif // CAPTURE_CONCAT

#define CAPTURE_CONCAT(a,b) CAPTURE_CONCAT_IMPL(a,b)

//-----------------------------------------------------------------------------
// [SECTION]
//-----------------------------------------------------------------------------

/**
 * @defgroup version version Information
 * @brief Macros for library versioning.
 * @{
 */

/**
 * @def CAPTURE_VERSION_MAJOR
 * @brief Major version number of the library.
 * @note If this were version 1.2.3, this value would be 1.
 * @since This macro is available since 0.1.0 .
 */
#ifndef CAPTURE_VERSION_MAJOR
    #define CAPTURE_VERSION_MAJOR 0
#endif // CAPTURE_VERSION_MAJOR

/**
 * @def CAPTURE_VERSION_MINOR
 * @brief Minor version number of the library.
 * @note If this were version 1.2.3, this value would be 2.
 * @since This macro is available since 0.1.0 .
 */
#ifndef CAPTURE_VERSION_MINOR
    #define CAPTURE_VERSION_MINOR 1
#endif // CAPTURE_VERSION_MINOR

/**
 * @def CAPTURE_VERSION_PATCH
 * @brief Patch version number of the library.
 * @note If this were version 1.2.3, this value would be 3.
 * @since This macro is available since 0.1.0 .
 */
#ifndef CAPTURE_VERSION_PATCH
    #define CAPTURE_VERSION_PATCH 0
#endif // CAPTURE_VERSION_PATCH

/**
 * @def CAPTURE_VERSION_STRING
 * @brief Library version string in the format @c "X.Y.Z",
 * where @c X is the major version number, @c Y is a minor version
 * number, and @c Z is the patch version number.
 */
#ifndef CAPTURE_VERSION_STRING
    #define CAPTURE_VERSION_STRING          \
    CAPTURE_TOSTR(CAPTURE_VERSION_MAJOR) "." \
    CAPTURE_TOSTR(CAPTURE_VERSION_MINOR) "." \
    CAPTURE_TOSTR(CAPTURE_VERSION_PATCH)
#endif // CAPTURE_VERSION_STRING

/**
 * @def CAPTURE_VERSION
 * @brief Library version number.
 */
#ifndef CAPTURE_VERSION
    #define CAPTURE_VERSION (CAPTURE_VERSION_MAJOR * 10000 + CAPTURE_VERSION_MINOR * 100 + CAPTURE_VERSION_PATCH)
#endif // CAPTURE_VERSION

/** @} version */

//-----------------------------------------------------------------------------
// [SECTION] Platform
//-----------------------------------------------------------------------------

/**
 * @defgroup platform Platform Definitions
 * @{
 */

#ifdef CAPTURE_PLATFORM_IS
    #undef CAPTURE_PLATFORM_IS
#endif // CAPTURE_PLATFORM_IS

 /**
 * @brief   Checks if the platform is of given brand.
 * @param   name Platform, like `APPLE`.
 * @retval  true   It is.
 * @retval  false  It isn't.
 */
#define CAPTURE_PLATFORM_IS(name) CAPTURE_PLATFORM_##name

//-----------------------------------------------------------------------------
// [SECTION] Platform : Operating System 
//-----------------------------------------------------------------------------

/**
 * @defgroup os Operating System Definitions
 * @{
 */

#ifdef CAPTURE_OS_IS
    #undef CAPTURE_OS_IS
#endif // CAPTURE_OS_IS

/**
 * @brief   Checks if the os is of given brand.
 * @param   name OS, like `MAC`.
 * @retval  true   It is.
 * @retval  false  It isn't.
 */
#define CAPTURE_OS_IS(name) CAPTURE_OS_##name

 /** @} os */

//-----------------------------------------------------------------------------
// [SECTION] Platform : Architecture
//-----------------------------------------------------------------------------

/**
 * @defgroup architecture Architecture Definitions
 * @{
 */

#ifdef CAPTURE_ARCH_IS
    #undef CAPTURE_ARCH_IS
#endif // CAPTURE_ARCH_IS

/**
 * @brief   Checks if the target architecture is of given brand.
 * @param   name Architecture, like `ARM64`.
 * @retval  true   It is.
 * @retval  false  It isn't.
 */
#define CAPTURE_ARCH_IS(name) CAPTURE_ARCH_##name

 /** @} architecture */

/** @} platform */

//-----------------------------------------------------------------------------
// [SECTION] Language C++ Standard
//-----------------------------------------------------------------------------

/**
 * @defgroup language C++ Standard
 * @{
 */

// 199711L - C++98
// 201103L - C++11
// 201402L - C++14
// 201703L - C++17
// 202002L - C++20
// 202302L - C++23

// With the MSVC compilers, the value of __cplusplus is by default always "199611L"(C++98).
// To avoid that, the library instead references _MSVC_LANG which is always set a correct value.
// See https://devblogs.microsoft.com/cppblog/msvc-now-correctly-reports-__cplusplus/ for more details.
#if defined(_MSVC_LANG) && !defined(__clang__)
    #define CAPTURE_CPLUSPLUS _MSVC_LANG
#else
    #define CAPTURE_CPLUSPLUS __cplusplus
#endif

#if !defined(CAPTURE_HAS_CXX_26) && !defined(CAPTURE_HAS_CXX_23) && !defined(CAPTURE_HAS_CXX_20)\
    && !defined(CAPTURE_HAS_CXX_17) && !defined(CAPTURE_HAS_CXX_14) && !defined(CAPTURE_HAS_CXX_11)
    #if (defined(CAPTURE_CPLUSPLUS) && CAPTURE_CPLUSPLUS > 202302L)
        #define CAPTURE_HAS_CXX_26
        #define CAPTURE_HAS_CXX_23
        #define CAPTURE_HAS_CXX_20
        #define CAPTURE_HAS_CXX_17
        #define CAPTURE_HAS_CXX_14
    #elif (defined(CAPTURE_CPLUSPLUS) && CAPTURE_CPLUSPLUS > 202002L)
        #define CAPTURE_HAS_CXX_23
        #define CAPTURE_HAS_CXX_20
        #define CAPTURE_HAS_CXX_17
        #define CAPTURE_HAS_CXX_14
    #elif (defined(CAPTURE_CPLUSPLUS) && CAPTURE_CPLUSPLUS > 201703L)
        #define CAPTURE_HAS_CXX_20
        #define CAPTURE_HAS_CXX_17
        #define CAPTURE_HAS_CXX_14
    #elif (defined(CAPTURE_CPLUSPLUS) && CAPTURE_CPLUSPLUS > 201402L)
        #define CAPTURE_HAS_CXX_17
        #define CAPTURE_HAS_CXX_14
    #elif (defined(CAPTURE_CPLUSPLUS) && CAPTURE_CPLUSPLUS > 201103L)
        #define CAPTURE_HAS_CXX_14
    #endif
    // Always specified because it is the minimal required version
    #define CAPTURE_HAS_CXX_11
#endif

 /** @} language */

//-----------------------------------------------------------------------------
// [SECTION] Language C Standard
//-----------------------------------------------------------------------------

/**
 * @defgroup language C Standard
 * @{
 */

 /** @} language */

//-----------------------------------------------------------------------------
// [SECTION] Compiler
//-----------------------------------------------------------------------------

/**
 * @defgroup compiler Compiler Definitions
 * @{
 */

#ifdef CAPTURE_COMPILER_IS
    #undef CAPTURE_COMPILER_IS
#endif // CAPTURE_COMPILER_IS

 /**
 * @brief   Checks if the compiler is of given brand.
 * @param   name  Compiler brand, like `MSVC`.
 * @retval  true   It is.
 * @retval  false  It isn't.
 */
#define CAPTURE_COMPILER_IS(name) CAPTURE_COMPILER_##name

#ifdef CAPTURE_COMPILER_SINCE
    #undef CAPTURE_COMPILER_SINCE
#endif // CAPTURE_COMPILER_SINCE

/**
 * @brief   Checks if the compiler is of given brand and is newer than or equal
 *          to the passed version.
 * @param   name     Compiler brand, like `MSVC`.
 * @param   x      Major version.
 * @param   y      Minor version.
 * @param   z      Patchlevel.
 * @retval  true   name >= x.y.z.
 * @retval  false  otherwise.
 */
#define CAPTURE_COMPILER_SINCE(name, x, y, z)                                 \
  (CAPTURE_COMPILER_IS(name) && ((CAPTURE_COMPILER_VERSION_MAJOR > (x)) ||     \
                                ((CAPTURE_COMPILER_VERSION_MAJOR == (x)) &&   \
                                 ((CAPTURE_COMPILER_VERSION_MINOR > (y)) ||   \
                                  ((CAPTURE_COMPILER_VERSION_MINOR == (y)) && \
                                   (CAPTURE_COMPILER_VERSION_PATCH >= (z)))))))

#ifdef CAPTURE_COMPILER_BEFORE
    #undef CAPTURE_COMPILER_BEFORE
#endif // CAPTURE_COMPILER_BEFORE

/**
 * @brief   Checks if  the compiler  is of  given brand and  is older  than the
 *          passed version.
 * @param   name     Compiler brand, like `MSVC`.
 * @param   x      Major version.
 * @param   y      Minor version.
 * @param   z      Patchlevel.
 * @retval  true   name < x.y.z.
 * @retval  false  otherwise.
 */
#define CAPTURE_COMPILER_BEFORE(name, x, y, z)                                \
  (CAPTURE_COMPILER_IS(name) && ((CAPTURE_COMPILER_VERSION_MAJOR < (x)) ||     \
                                ((CAPTURE_COMPILER_VERSION_MAJOR == (x)) &&   \
                                 ((CAPTURE_COMPILER_VERSION_MINOR < (y)) ||   \
                                  ((CAPTURE_COMPILER_VERSION_MINOR == (y)) && \
                                   (CAPTURE_COMPILER_VERSION_PATCH < (z)))))))


//-----------------------------------------------------------------------------
// [SECTION] Compiler Vendor
//-----------------------------------------------------------------------------

/**
 * @defgroup compiler Compiler Vendor
 * @{
 */

#ifdef CAPTURE_COMPILER_VERSION_MAJOR
    #undef CAPTURE_COMPILER_VERSION_MAJOR
#endif // CAPTURE_COMPILER_VERSION_MAJOR

#ifdef CAPTURE_COMPILER_VERSION_MINOR
    #undef CAPTURE_COMPILER_VERSION_MINOR
#endif // CAPTURE_COMPILER_VERSION_MINOR

#ifdef CAPTURE_COMPILER_VERSION_PATCH
    #undef CAPTURE_COMPILER_VERSION_PATCH
#endif // CAPTURE_COMPILER_VERSION_PATCH

#ifdef CAPTURE_COMPILER_IS_GCC
    #undef CAPTURE_COMPILER_IS_GCC
#endif // CAPTURE_COMPILER_IS_GCC

/// Compiler is gcc
#if !defined(__GNUC__)
    #define CAPTURE_COMPILER_GCC 0
#else
    #define CAPTURE_COMPILER_IS_GCC 1
    #define CAPTURE_COMPILER_VERSION_MAJOR __GNUC__
    #define CAPTURE_COMPILER_VERSION_MINOR __GNUC_MINOR__
    #define CAPTURE_COMPILER_VERSION_PATCH __GNUC_PATCHLEVEL__
#endif

#ifdef CAPTURE_COMPILER_CLANG
    #undef CAPTURE_COMPILER_CLANG
#endif // CAPTURE_COMPILER_CLANG

/// Compiler is clang
#if !defined(__clang__)
    #define CAPTURE_COMPILER_CLANG 0
#elif CAPTURE_COMPILER_IS(GCC)
    #define CAPTURE_COMPILER_CLANG 0
#else
    #define CAPTURE_COMPILER_CLANG 1
    #define CAPTURE_COMPILER_VERSION_MAJOR __clang_major__
    #define CAPTURE_COMPILER_VERSION_MINOR __clang_minor__
    #define CAPTURE_COMPILER_VERSION_PATCH __clang_patchlevel__
#endif

#ifdef CAPTURE_COMPILER_MSVC
    #undef CAPTURE_COMPILER_MSVC
#endif // CAPTURE_COMPILER_MSVC

/// Compiler is msvc
#if !defined(_MSC_VER)
    #define CAPTURE_COMPILER_MSVC 0
#elif CAPTURE_COMPILER_IS(CLANG)
    #define CAPTURE_COMPILER_MSVC 0
#elif _MSC_VER >= 1400
    #define CAPTURE_COMPILER_MSVC 1
    /* _MSC_FULL_VER = XXYYZZZZZ */
    #define CAPTURE_COMPILER_VERSION_MAJOR (_MSC_FULL_VER / 10000000)
    #define CAPTURE_COMPILER_VERSION_MINOR (_MSC_FULL_VER % 10000000 / 100000)
    #define CAPTURE_COMPILER_VERSION_PATCH (_MSC_FULL_VER % 100000)
#elif defined(_MSC_FULL_VER)
    #define CAPTURE_COMPILER_MSVC 1
    /* _MSC_FULL_VER = XXYYZZZZ */
    #define CAPTURE_COMPILER_VERSION_MAJOR (_MSC_FULL_VER / 1000000)
    #define CAPTURE_COMPILER_VERSION_MINOR (_MSC_FULL_VER % 1000000 / 10000)
    #define CAPTURE_COMPILER_VERSION_PATCH (_MSC_FULL_VER % 10000)
#else
    #define CAPTURE_COMPILER_MSVC 1
    /* _MSC_VER = XXYY */
    #define CAPTURE_COMPILER_VERSION_MAJOR (_MSC_VER / 100)
    #define CAPTURE_COMPILER_VERSION_MINOR (_MSC_VER % 100)
    #define CAPTURE_COMPILER_VERSION_PATCH 0
#endif

 /** @} compiler */

//-----------------------------------------------------------------------------
// [SECTION] Compiler Warnings
//-----------------------------------------------------------------------------

/**
 * @defgroup compiler Compiler Warnings
 * @{
 */

#if CAPTURE_COMPILER_IS(GCC)
    #define CAPTURE_PRAGMA_TO_STR(x) _Pragma(#x)
    #define CAPTURE_GCC_SUPPRESS_WARNING_PUSH _Pragma("GCC diagnostic push")
    #define CAPTURE_GCC_SUPPRESS_WARNING_POP _Pragma("GCC diagnostic pop")
    #define CAPTURE_GCC_SUPPRESS_WARNING(w) CAPTURE_PRAGMA_TO_STR(GCC diagnostic ignored w)
    #define CAPTURE_GCC_SUPPRESS_WARNING_WITH_PUSH(w) \
        CAPTURE_GCC_SUPPRESS_WARNING_PUSH CAPTURE_GCC_SUPPRESS_WARNING(w)
#else // CAPTURE_GCC
    #define CAPTURE_GCC_SUPPRESS_WARNING_PUSH
    #define CAPTURE_GCC_SUPPRESS_WARNING(w)
    #define CAPTURE_GCC_SUPPRESS_WARNING_POP
    #define CAPTURE_GCC_SUPPRESS_WARNING_WITH_PUSH(w)
#endif // CAPTURE_GCC

#if CAPTURE_COMPILER_IS(MSVC)
    #define CAPTURE_MSVC_SUPPRESS_WARNING_PUSH __pragma(warning(push))
    #define CAPTURE_MSVC_SUPPRESS_WARNING(w) __pragma(warning(disable : w))
    #define CAPTURE_MSVC_SUPPRESS_WARNING_POP __pragma(warning(pop))
    #define CAPTURE_MSVC_SUPPRESS_WARNING_WITH_PUSH(w) \
        CAPTURE_MSVC_SUPPRESS_WARNING_PUSH CAPTURE_MSVC_SUPPRESS_WARNING(w)
#else // CAPTURE_MSVC
    #define CAPTURE_MSVC_SUPPRESS_WARNING_PUSH
    #define CAPTURE_MSVC_SUPPRESS_WARNING(w)
    #define CAPTURE_MSVC_SUPPRESS_WARNING_POP
    #define CAPTURE_MSVC_SUPPRESS_WARNING_WITH_PUSH(w)
#endif // CAPTURE_MSVC

#if CAPTURE_COMPILER_IS(CLANG)
    #define CAPTURE_PRAGMA_TO_STR(x) _Pragma(#x)
    #define CAPTURE_CLANG_SUPPRESS_WARNING_PUSH _Pragma("clang diagnostic push")
    #define CAPTURE_CLANG_SUPPRESS_WARNING_POP _Pragma("clang diagnostic pop")
    #define CAPTURE_CLANG_SUPPRESS_WARNING(w) CAPTURE_PRAGMA_TO_STR(clang diagnostic ignored w)
    #define CAPTURE_CLANG_SUPPRESS_WARNING_WITH_PUSH(w) \
        CAPTURE_CLANG_SUPPRESS_WARNING_PUSH CAPTURE_CLANG_SUPPRESS_WARNING(w)
#else // CAPTURE_CLANG
    #define CAPTURE_CLANG_SUPPRESS_WARNING_PUSH
    #define CAPTURE_CLANG_SUPPRESS_WARNING(w)
    #define CAPTURE_CLANG_SUPPRESS_WARNING_POP
    #define CAPTURE_CLANG_SUPPRESS_WARNING_WITH_PUSH(w)
#endif // CAPTURE_CLANG

#if CAPTURE_COMPILER_IS(GCC)
    #define CAPTURE_DIABLE_WARNINGS                  \
        CAPTURE_GCC_SUPPRESS_WARNING_PUSH            \
        CAPTURE_GCC_SUPPRESS_WARNING("-Weverything")
    
    #define CAPTURE_ENABLE_WARNINGS                  \
        CAPTURE_GCC_SUPPRESS_WARNING_POP
#endif // CAPTURE_COMPILER_IS_GCC

#if CAPTURE_COMPILER_IS(MSVC)
    #define CAPTURE_DIABLE_WARNINGS                  \
        CAPTURE_MSVC_SUPPRESS_WARNING_PUSH           \
        CAPTURE_MSVC_SUPPRESS_WARNING()
    
    #define CAPTURE_ENABLE_WARNINGS                  \
        CAPTURE_MSVC_SUPPRESS_WARNING_POP
#endif // CAPTURE_COMPILER_IS_MSVC

#if CAPTURE_COMPILER_IS(CLANG)
    #define CAPTURE_DIABLE_WARNINGS                  \
        CAPTURE_CLANG_SUPPRESS_WARNING_PUSH          \
        CAPTURE_CLANG_SUPPRESS_WARNING("-Weverything")
    
    #define CAPTURE_ENABLE_WARNINGS                  \
        CAPTURE_CLANG_SUPPRESS_WARNING_POP
#endif // CAPTURE_COMPILER_IS_CLANG

 /** @} compiler */

//-----------------------------------------------------------------------------
// [SECTION] Compiler Macros
//-----------------------------------------------------------------------------

/**
 * @defgroup compiler Compiler Macros
 * @{
 */

#ifdef CAPTURE_HAS_BUILTIN
    #undef CAPTURE_HAS_BUILTIN
#endif // CAPTURE_HAS_BUILTIN

/** compiler builtin check */
#ifdef __has_builtin
    #define CAPTURE_HAS_BUILTIN(x) __has_builtin(x)
#else
	#define CAPTURE_HAS_BUILTIN(x) 0
#endif

#ifdef CAPTURE_HAS_ATTRIBUTE
    #undef CAPTURE_HAS_ATTRIBUTE
#endif // CAPTURE_HAS_ATTRIBUTE

/** compiler attribute check */
#ifdef __has_attribute
    #define CAPTURE_HAS_ATTRIBUTE(x) __has_attribute(x)
#else
    #define CAPTURE_HAS_ATTRIBUTE(x) 0
#endif

#ifdef CAPTURE_HAS_WARNING
    #undef CAPTURE_HAS_WARNING
#endif // CAPTURE_HAS_WARNING

/** compiler attribute check */
#ifdef __has_warning
    #define CAPTURE_HAS_WARNING(x) __has_warning(x)
#else
    #define CAPTURE_HAS_WARNING(x) 0
#endif

#ifdef CAPTURE_HAS_FEATURE
    #undef CAPTURE_HAS_FEATURE
#endif // CAPTURE_HAS_FEATURE

/** compiler feature check */
#ifdef __has_feature
    #define CAPTURE_HAS_FEATURE(x) __has_feature(x)
#else
    #define CAPTURE_HAS_FEATURE(x) 0
#endif

#ifdef CAPTURE_HAS_EXTENSION
    #undef CAPTURE_HAS_EXTENSION
#endif // CAPTURE_HAS_EXTENSION

/** compiler extension check */
#ifdef __has_extension
    #define CAPTURE_HAS_EXTENSION(x) __has_extension(x)
#else
    #define CAPTURE_HAS_EXTENSION(x) 0
#endif

#ifdef CAPTURE_HAS_INCLUDE
    #undef CAPTURE_HAS_INCLUDE
#endif // CAPTURE_HAS_INCLUDE

/** compiler include check */
#ifdef __has_include
    #define CAPTURE_HAS_INCLUDE(x) __has_include(x)
#else
    #define CAPTURE_HAS_INCLUDE(x) 0
#endif

#ifdef CAPTURE_HAS_CPP_ATTRIBUTE
    #undef CAPTURE_HAS_CPP_ATTRIBUTE
#endif // CAPTURE_HAS_CPP_ATTRIBUTE

/** compiler cpp attribute check */
#ifdef __has_cpp_attribute
    #define CAPTURE_HAS_CPP_ATTRIBUTE(x) __has_cpp_attribute(x)
#else
    #define CAPTURE_HAS_CPP_ATTRIBUTE(x) 0
#endif

#ifdef CAPTURE_HAS_DECLSPEC_ATTRIBUTE
    #undef CAPTURE_HAS_DECLSPEC_ATTRIBUTE
#endif // CAPTURE_HAS_DECLSPEC_ATTRIBUTE

/** compiler cpp attribute check */
#ifdef __has_declspec_attribute
    #define CAPTURE_HAS_DECLSPEC_ATTRIBUTE(x) __has_declspec_attribute(x)
#else
    #define CAPTURE_HAS_DECLSPEC_ATTRIBUTE(x) 0
#endif

//-----------------------------------------------------------------------------
// [SECTION] Compiler Attributes
//-----------------------------------------------------------------------------

/**
 * @defgroup compiler Compiler Attributes
 * @{
 */

/** inline for compiler */
#ifndef CAPTURE_INLINE
  	#if defined(__cplusplus) || CAPTURE_STDC >= 199901L
    	#define CAPTURE_INLINE inline
  	#elif CAPTURE_HAS_ATTRIBUTE(always_inline) || CAPTURE_COMPILER_SINCE(GCC, 4, 0, 0)
    	#define CAPTURE_INLINE __inline__ __attribute__((always_inline))
  	#else
    	#define CAPTURE_INLINE
  	#endif
#endif

/** noinline for compiler */
#ifndef CAPTURE_NOINLINE
  	#if CAPTURE_COMPILER_SINCE(MSVC, 14, 0, 0)
    	#define CAPTURE_NOINLINE __declspec(noinline)
  	#elif CAPTURE_HAS_ATTRIBUTE(noinline) || (CAPTURE_COMPILER_SINCE(GCC, 4, 0, 0))
    	#define CAPTURE_NOINLINE __attribute__((noinline))
  	#else
    	#define CAPTURE_NOINLINE
  	#endif
#endif

/** align for compiler */
#ifndef CAPTURE_ALIGN
  	#if CAPTURE_COMPILER_SINCE(MSVC, 13, 0, 0)
    	#define CAPTURE_ALIGN(x) __declspec(align(x))
  	#elif CAPTURE_HAS_ATTRIBUTE(aligned) || defined(__GNUC__)
    	#define CAPTURE_ALIGN(x) __attribute__((aligned(x)))
  	#elif defined(CAPTURE_HAS_CXX_11)
    	#define CAPTURE_ALIGN(x) alignas(x)
  	#else
    	#define CAPTURE_ALIGN(x)
  	#endif
#endif

/** deprecate warning */
#if defined(CAPTURE_HAS_CXX_14)
    #define CAPTURE_DEPRECATED(msg) [[deprecated(msg)]]
#else
    #define CAPTURE_DEPRECATED(msg)
#endif

#ifndef CAPTURE_NODISCARD
    #define CAPTURE_NODISCARD [[nodiscard]]
#endif

// switch usage of [[likely]] C++ attribute which has been available since C++20.
#if defined(CAPTURE_HAS_CXX_20) && CAPTURE_HAS_CPP_ATTRIBUTE(likely) >= 201803L
    #define CAPTURE_LIKELY(expr) (!!(expr)) [[likely]]
#elif CAPTURE_HAS_BUILTIN(__builtin_expect)
    #define CAPTURE_LIKELY(expr) (__builtin_expect(!!(expr), 1))
#else
    #define CAPTURE_LIKELY(expr) (!!(expr))
#endif

// switch usage of [[unlikely]] C++ attribute which has been available since C++20.
#if defined(CAPTURE_HAS_CXX_20) && CAPTURE_HAS_CPP_ATTRIBUTE(unlikely) >= 201803L
    #define CAPTURE_UNLIKELY(expr) (!!(expr)) [[unlikely]]
#elif CAPTURE_HAS_BUILTIN(__builtin_expect)
    #define CAPTURE_UNLIKELY(expr) (__builtin_expect(!!(expr), 0))
#else
    #define CAPTURE_UNLIKELY(expr) (!!(expr))
#endif

// switch usage of constexpr keyword depending on active C++ standard.
#if defined(CAPTURE_HAS_CXX_17)
    #define CAPTURE_CONSTEXPR constexpr
#else
    #define CAPTURE_CONSTEXPR
#endif

// switch usage of char8_t which has been available since C++20.
#if defined(CAPTURE_HAS_CXX_20) && defined(__cpp_char8_t) && __cpp_char8_t >= 201811L
    #define CAPTURE_HAS_CHAR8_T (1)
#else
    #define CAPTURE_HAS_CHAR8_T (0)
#endif

 /** @} compiler */

 /** @} compiler */

//-----------------------------------------------------------------------------
// [SECTION] API Import/Export
//-----------------------------------------------------------------------------

/**
 * @defgroup export Export Definitions
 * @{
 */

#if CAPTURE_PLATFORM_WINDOWS
    #define CAPTURE_API_EXPORT __declspec(dllexport)
    #define CAPTURE_API_IMPORT __declspec(dllimport)
    #define CAPTURE_NO_EXPORT
#else
    #define CAPTURE_API_EXPORT __attribute__((visibility("default")))
    #define CAPTURE_API_IMPORT __attribute__((visibility("default")))
    #define CAPTURE_NO_EXPORT __attribute__((visibility("hidden")))
#endif  // CAPTURE_PLATFORM_WINDOWS

/**
 * @def CAPTURE_API
 * @brief Macro for public API symbol export/import.
 * @details Use this macro to annotate all public API functions for correct
 * symbol visibility on all platforms.
 */

#if defined(CAPTURE_BUILD_STATIC)
    #define CAPTURE_API
#elif defined(CAPTURE_BUILD_SHARED) || defined(CAPTURE_EXPORTS)
    /* We are building this library */
    #define CAPTURE_API CAPTURE_API_EXPORT
#elif defined(CAPTURE_LOAD_SHARED) || defined(CAPTURE_IMPORTS)
    /* We are using this library */
    #define CAPTURE_API CAPTURE_API_IMPORT
#else  // CAPTURE_BUILD_STATIC
    #define CAPTURE_API
#endif  // CAPTURE_BUILD_STATIC

/** @} export */

//-----------------------------------------------------------------------------
// [SECTION] General Macros
//-----------------------------------------------------------------------------

/** 
 * @brief One.
 *
 *  This is only semantic sugar for the number `1`.
 *  @note You can instead use `1` or `true` .
 *
 */
#define CAPTURE_TRUE 1

/** 
 * @brief Zero.
 *
 *  This is only semantic sugar for the number `0`.
 *  @note You can instead use `0` or `false` .
 *
 */
#define CAPTURE_FALSE 0

// clang-format on

#endif // DJOEZEKE_CAPTURE) || CAPTURE_VERSION) || (CAPTURE_VERSION
