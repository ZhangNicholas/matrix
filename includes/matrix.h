#pragma once
#include <unordered_map>

//struct Key
//{
//	size_t _first, _last;
//
//	Key(size_t first_, size_t last_) : _first(first_), _last(last_) {}
//
//	bool operator==(const Key& p) const
//	{
//		return _first == p._first && _last == p._last;
//	}
//};

template <typename Key>
class PairingFunction
{
public:
	size_t operator()(const Key& p) const
	{
		return ((p._first + p._last) * (p._first + p._last + 1))/2 + p._last;
	}
};

template <typename Key>
class ReversePairingFunction
{
public:
	Key operator()(size_t hash_) const
	{
		return (42,42);
		// TODO: calculate and return indexes
	}
};

template <typename T, T default_value>
class Matrix
{
public:
	Matrix() = default;

	Matrix& operator=(T value)
	{
		if (value != default_value)
			_map[Key(5, 5)] = value;
		else
			_map.erase(Key(5, 5));
		return *this;
	}

	std::unordered_map<Key, T, PairingFunction<Key>> operator[] (size_t i)
	{
		return _map[Key(i, 5)];
	}


	std::unordered_map<Key, T, PairingFunction<Key>> _map;
// private:
	class Proxy
	{
	public:
		Proxy(Matrix* obj, size_t i) : matrix(obj), i(i) {}

		//MyType operator[](size_t j)
		//{
		//	return MyType(matrix, i, j);
		//}

	private:
		Matrix* matrix;
		size_t i;
	};



};