#ifndef RADIX_TREE_INCLUDED
#define RADIX_TREE_INCLUDED
#include <string>
#include <iostream>
#include <map>

using namespace std;

template <typename ValueType>
class RadixTree {
public:
	RadixTree();
	~RadixTree();
	void insert(std::string key, const ValueType& value);
	ValueType* search(std::string key) const;

private:
	map<string, ValueType> myMap;
};

template<typename ValueType>
inline RadixTree<ValueType>::RadixTree()
{

}

template<typename ValueType>
inline RadixTree<ValueType>::~RadixTree()
{

}

template<typename ValueType>
inline void RadixTree<ValueType>::insert(std::string key, const ValueType& value)
{
	ValueType valToInsert = value;
	if (myMap.find(key) == myMap.end()) {
		myMap.insert(pair<string, ValueType>(key, valToInsert));
		cerr << "inserting a new AttVal Pair" << endl;
	}
	else {
		myMap.find(key)->second = value;
		cerr << "updating an already existing AttVal Pair" << endl;
	}

}

template<typename ValueType>
inline typename ValueType* RadixTree<ValueType>::search(std::string key) const
{
	typename map<string, ValueType>::const_iterator it = myMap.find(key);
	if (it != myMap.end()) {
		ValueType* ptr = const_cast<ValueType*>(&it->second);
		cerr << "this will print if the key exists in the map " << it->first << endl;
		return ptr;
	}
	else {
		cerr << "KEY DOES NOT EXIST IN THE MAP" << endl;
		return nullptr;
	}
}

#endif