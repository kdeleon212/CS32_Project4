//#pragma once
//#ifndef RADIX_TREE_SET_INCLUDED
//#define RADIX_TREE_SET_INCLUDED
//#include <string>
//#include <iostream>
//#include <map>
//#include <set>
//
//using namespace std;
//
//class RadixTreeSet {
//public:
//	RadixTreeSet();
//	~RadixTreeSet();
//	void insert(std::string key, const set<string>& value);
//	set<string>* search(std::string key) const;
//
//private:
//	map<string, set<string>> myMap;
//};
//
//inline RadixTreeSet::RadixTreeSet()
//{
//
//}
//
//inline RadixTreeSet::~RadixTreeSet()
//{
//
//}
//
//inline void RadixTreeSet::insert(std::string key, const set<string>& value)
//{
//	set<string> valToInsert = value;
//	if (myMap.find(key) == myMap.end()) {
//		myMap.insert(pair<string, set<string>>(key, valToInsert));
//		cerr << "inserting a new AttVal Pair" << endl;
//	}
//	else {
//		myMap.find(key)->second = value;
//		cerr << "updating an already existing AttVal Pair" << endl;
//	}
//
//}
//
//inline set<string>* RadixTreeSet::search(std::string key) const
//{
//	map<string, set<string>>::const_iterator it = myMap.find(key);
//	if (it != myMap.end()) {
//		//ValueType* ptr = (ValueType*)&*(it->second);
//		set<string>* ptr = const_cast<set<string>*>(&it->second);
//		cerr << "this will print if the key exists in the map " << it->first << endl;
//		return ptr;
//	}
//	else {
//		cerr << "KEY DOES NOT EXIST IN THE MAP" << endl;
//		return nullptr;
//	}
//}
//
//#endif