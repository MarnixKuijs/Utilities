#ifndef POP_COUNT
#if defined(__clang__)
#define POP_COUNT(x)  __builtin_popcount(x)
#elif defined(__GNUC__) || defined(__GNUG__)
#define POP_COUNT(x)  __builtin_popcount(x)
#elif defined(_MSC_VER)
#include <intrin.h>
#define POP_COUNT(x) __popcnt(x)
#else
#pragma warning("Unknown compiler! POP_COUNT doesnt use compiler intrinsics")
#define POP_COUNT(x) [](unsigned value)				\
					{								\
                        int count{0};				\
                        while(value != 0)			\
                        {							\
                            count++;				\
                            value &= (value - 1);   \
                        }                           \
                        return count;               \
					}(x) 
#endif 
#endif