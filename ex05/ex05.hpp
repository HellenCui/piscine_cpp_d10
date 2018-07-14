#ifndef EX05_HPP_
#define EX05_HPP_
#include <iostream>
#include <stdexcept>

template <typename T>
class array {
public:
	array() :
		_array(nullptr), _size(0)
	{
	}
	array(size_t n) :
		_array(new T[n]), _size(n)
	{
		for (size_t i = 0; i < n; i++)
			this->_array[i] = T();
	}

	array(array<T> const &other) :
		_array(new T[other._size]), _size(other._size)
	{
		for (size_t i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}
	~array()
	{
		delete[] this->_array;
	}
	array<T> &operator=(array<T> const &other)
	{
		delete[] this->_array;
		this->_array = new T[other._size];
		this->_size = other._size;
		for (size_t i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
		return (*this);
	}

	T &operator[](size_t idx)
	{
		if (idx >= this->_size) {
			T *_new = new T[idx + 1];
			for (size_t i = 0; i < this->_size; i++)
				_new[i] = this->_array[i];
			delete[] this->_array;
			for (size_t i = this->_size; i < idx; i++)
				_new[i] = T();
			this->_array = _new;
			this->_size = idx + 1;
		}
		return (this->_array[idx]);
	}
	T const &operator[](size_t idx) const
	{
		if (idx >= this->_size)
			throw std::out_of_range("Index out of range.");
		return (this->_array[idx]);
	}
	size_t size() const
	{
		return (this->_size);
	}
	void dump() const
	{
		std::cout << '[' << std::boolalpha;
		for (size_t i = 0; i < this->_size; i++) {
			std::cout << this->_array[i];
			if (i != this->_size - 1)
				std::cout << ", ";
		}
		std::cout << ']' << std::endl;
	}
	template <typename U>
	array<U> convertTo(U (*func)(T const&))
	{
		array<U> res(this->_size);
		for (size_t i = 0; i < this->_size; i++)
			res[i] = func(this->_array[i]);
		return res;
	}
private:
	T *_array;
	size_t _size;
};
#endif

