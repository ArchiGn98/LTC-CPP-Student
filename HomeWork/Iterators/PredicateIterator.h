#pragma once
#include <functional>

template<class Iter>
class PredicateIterator
{
	using value_type = typename std::iterator_traits<Iter>::value_type;

	Iter current;
	Iter start;
	Iter stop;
	std::function<bool(value_type val)> predicate;

	void stepOverIfNotPredicate()
	{
		if (current != stop)
		{
			if (!predicate(*current))
			{
				operator++();
			}
		}
	}

public:
	PredicateIterator(Iter start, Iter stop, std::function<bool(value_type val)> predicate)
		: current{ start },
		start{ start },
		stop{ stop },
		predicate{ predicate }
	{
	}

	PredicateIterator(Iter start, Iter stop)
		: current{ start },
		start{ start },
		stop{ stop }
	{
		predicate = [](value_type val) { return true; };
	}

	value_type operator*() const
	{
		return *current;
	}

	PredicateIterator& operator++()
	{
		++current;
		stepOverIfNotPredicate();
		return *this;
	}

	bool operator !=(const PredicateIterator& other) const
	{
		return current != other.current;
	}

	PredicateIterator begin()
	{
		stepOverIfNotPredicate();
		return *this;
	}

	PredicateIterator end()
	{
		return PredicateIterator(stop, stop);
	}
};