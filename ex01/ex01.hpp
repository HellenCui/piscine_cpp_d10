#ifndef EX01_HPP_
#define EX01_HPP_
#include <cstring>

template <typename T>
int compare(T const &a, T const &b)
{
	if (a == b)
		return 0;
	return a < b ? -1 : 1;
}

int compare(const char *a, const char *b)
{
	int res = std::strcmp(a, b);
	if (res > 0)
		return 1;
	else if (res < 0)
		return -1;
	else
		return 0;
}
#endif

