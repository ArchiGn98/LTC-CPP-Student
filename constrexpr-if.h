#pragma once
#include <type_traits>
#include <vector>

template<typename T>
class Addable
{
	T val;
public:
	Addable(T v) : val(v) {}
	template<typename U>
	T Add(U x) const
	{
		if constexpr (std::is_same_v<T, std::vector<U>>)
		{
			auto copy(val);
			for (auto& n : copy)
			{
				n += x;
			}
			return copy;
		}
		else
		{
			return val + x;
		}
	}
};