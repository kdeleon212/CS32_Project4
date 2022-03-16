#ifndef PERSON_PROFILE_INCLUDED
#define PERSON_PROFILE_INCLUDED
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include "RadixTree.h"

using namespace std;

class PersonProfile {
public:
	struct AttValPair {
		AttValPair(string att, string val)
			: attribute(att), value(val)
		{}

		AttValPair()
		{}

		std::string attribute;
		std::string value;

		bool operator==(const AttValPair& rhs) const {
			return (attribute == rhs.attribute && value == rhs.value);
		}

		bool operator!=(const AttValPair& rhs) const {
			return !(*this == rhs);
		}
	};

	PersonProfile(std::string name, std::string email) : m_name(name), m_email(email), numAttValPairs(0) {}
	~PersonProfile();
	string GetName() const;
	string GetEmail() const;
	int GetNumAttValPairs() const;
	void AddAttValPair(const AttValPair& attval);
	bool GetAttVal(int attribute_num, AttValPair& attval) const;

private:

	string m_name;
	string m_email;
	RadixTree<set<string>*> AttValPairs;
	int numAttValPairs;
	vector<AttValPair> vectorPairs;

};
#endif