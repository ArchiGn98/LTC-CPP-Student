#include "pch.h"
#include <vector>
class MyRange
{
private:
	int current;
	int stop;
	int step;
public:
	explicit MyRange(int start, int stop, int step = 1) :
		current(start), stop(stop), step(step) {}
	int operator*() const { return current; }
	MyRange& operator++() {
		if (current + step < stop)
			current += step;
		else
			current = stop;
		return *this;
	}
	bool operator !=(const MyRange& op) const
	{
		return current != op.current;
	}
	
	MyRange begin() 
	{
		return *this;
	}
	MyRange end()
	{
		return MyRange(stop,stop);
	}
};

TEST(Module4, OwnedIterator)
{
	MyRange range{ 1,10,2 };
	std::vector<int> actual;
	std::vector<int> expected{ 1,3,5,7,9 };
	for (auto c : range)
	{
		actual.push_back(c);
	}
	ASSERT_EQ(expected, actual);
}