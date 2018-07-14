#ifndef EX04_HPP_
#define EX04_HPP_

template <typename T>
bool equal(T const &a, T const &b);
template <typename T>
class Tester {
public:
	bool equal(T const &a, T const &b) const;
};
#endif

