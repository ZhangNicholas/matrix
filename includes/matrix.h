#pragma once
#include <unordered_map>
#include <tuple>

/**
*	Helper struct to index matrix elements
*/

struct Key
{
	size_t _first, _last;
	Key(size_t first_, size_t last_) : _first(first_), _last(last_) {}

	bool operator==(const Key& p) const
	{
		return _first == p._first && _last == p._last;
	}
};

/**
* Hashes Key struct using [Cantor pairing function]
* (https://en.wikipedia.org/?title=Cantor_pairing_function&redirect=no).
*/

template <typename Key>
class PairingFunction
{
public:
	size_t operator()(const Key& p) const
	{
		return ((p._first + p._last) * (p._first + p._last + 1))/2 + p._last;
	}
};


/**
* Hashmap emulating endless 2-d matrix using hashed Key
*/

template <typename T, T default_value>
class PseudoMatrix
{
private:
	std::unordered_map<Key, T, PairingFunction<Key>> _map;
	class Cell
	{
	public:
		Cell(PseudoMatrix* matrix_, size_t i, size_t j) : _matrix(matrix_), i(i), j(j) {}

		Cell& operator=(T value)
		{
			if (value != default_value)
				_matrix->_map[Key(i, j)] = value;
			else
				_matrix->_map.erase(Key(i, j));
			return *this;
		}

		operator auto()
		{
			auto search = _matrix->_map.find(Key(i, j));
			if (search != _matrix->_map.end())
				return (*search).second;
			else
				return default_value;
		}

	private:
		PseudoMatrix* _matrix;
		size_t i, j;
	};

	class Proxy
	{
	public:
		Proxy(PseudoMatrix* matrix_, size_t i) : _matrix(matrix_), i(i) {}

		Cell operator[](size_t j)
		{
			return Cell(_matrix, i, j);
		}

	private:
		PseudoMatrix* _matrix;
		size_t i;
	};

	class iterator
	{
	public:
		iterator(typename std::unordered_map<Key, T, PairingFunction<Key>>::const_iterator it) : it(it) {}

		iterator operator++()
		{
			++it;
			return *this;
		}

		bool operator!=(const iterator& other) const { return it != other.it; }

		const std::tuple<size_t, size_t, T> operator*() const
		{
			return std::make_tuple((*it).first._first, (*it).first._last, (*it).second);
		}

	private:
		typename std::unordered_map<Key, T, PairingFunction<Key>>::const_iterator it;
	};

public:
	Proxy operator[](size_t i)
	{
		return Proxy(this, i);
	}

	size_t size()
	{
		return _map.size();
	}

	iterator begin() const { return iterator(_map.cbegin()); }
	iterator end() const { return iterator(_map.cend()); }
};