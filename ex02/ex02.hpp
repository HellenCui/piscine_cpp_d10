#ifndef EX02_HPP_
#define EX02_HPP_
#include <climits>
#include <iostream>
#include <stdexcept>

template <typename T>
T min(T a, T b)
{
	std::cout << "template min" << std::endl;
	return a <= b ? a : b;
}
int min(int a, int b)
{
	std::cout << "non-template min" << std::endl;
	return a <= b ? a : b;
}
template <typename T>
T templateMin(T const *array, size_t size)
{
	if (!array)
		throw std::runtime_error("Null pointer.");
	if (size == 0)
		throw std::logic_error("Array must not be empty.");
	T res = array[0];
	for (size_t i = 1; i < size; i++)
		res = min<T>(array[i], res);
	return res;
}

int nonTemplateMin(int const *array, size_t size)
{
	if (!array)
		throw std::runtime_error("Null pointer.");
	if (size == 0)
		throw std::logic_error("Array must not be empty.");
	int res = array[0];
	for (size_t i = 1; i < size; i++)
		res = min(array[i], res);
	return res;
}
#endif

