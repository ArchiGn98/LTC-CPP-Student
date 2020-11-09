#include "pch.h"

namespace exchange_rate
{
	constexpr double eur_to_usd = 1.16;
	constexpr double uah_to_usd = 0.035;
}

long double operator ""uah(unsigned long long uah)
{
	return uah * exchange_rate::uah_to_usd;
}

long double operator ""eur(unsigned long long eur)
{
	return eur * exchange_rate::eur_to_usd;
}

TEST(HW1, UahToUsd)
{
	ASSERT_EQ(10uah, 10 * 0.035);
}

TEST(HW1, EurToUsd)
{
	ASSERT_EQ(10eur, 10 * 1.16);
}