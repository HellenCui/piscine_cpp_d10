#include <string>
#include "ex04.hpp"

template <typename T>
bool equal(T const &a, T const &b)
{
	return a == b;
}
template <typename T>
bool Tester<T>::equal(T const &a, T const &b) const
{
	return a == b;
}
template bool equal<int>(int const &a, int const &b);
template bool equal<float>(float const &a, float const &b);
template bool equal<double>(double const &a, double const &b);
template bool equal<std::string>(std::string const &a, std::string const &b);
template class Tester<int>;
template class Tester<float>;
template class Tester<double>;
template class Tester<std::string>;
