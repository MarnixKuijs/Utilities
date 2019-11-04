#pragma once
#include <cstring>
#include <type_traits>

namespace cof
{
	inline namespace fill
	{
		//C++20 function fill 
		template <class To, class From>
		inline To bit_cast(const From& src) noexcept
		{
			static_assert(sizeof(To) == sizeof(From));
			static_assert(std::is_trivially_copyable_v<From>);
			static_assert(std::is_trivial_v<To>);

			To dst{};
			std::memcpy(&dst, &src, sizeof(To));
			return dst;
		}
	}
}