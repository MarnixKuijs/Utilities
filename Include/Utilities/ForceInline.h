#ifndef FORCE_INLINE
#if defined(__clang__)
#define FORCE_INLINE __attribute__((always_inline))
#elif defined(__GNUC__) || defined(__GNUG__)
#define FORCE_INLINE __attribute__((always_inline))
#elif defined(_MSC_VER)
#define FORCE_INLINE __forceinline
#else
#pragma warning("Unknown compiler! FORCE_INLINE defaulted to inline")
#define FORCE_INLINE inline
#endif