#pragma once
#include <array>
#include <type_traits>

namespace cof
{
	template <typename Member, typename T>
	inline auto ArrayCast(T const& value) noexcept
	{
		static_assert(sizeof(T) % sizeof(Member) == 0);

		return cof::bit_cast<std::array<Member, sizeof(T) / sizeof(Member)>>(value);
	}

	template <typename T, typename Member>
	inline auto ReverseArrayCast(std::array<Member, sizeof(T) / sizeof(Member)> const& arr) noexcept
	{
		static_assert(sizeof(T) % sizeof(Member) == 0);

		return cof::bit_cast<T>(arr);
	}
}