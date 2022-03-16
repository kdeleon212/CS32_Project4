#include "PersonProfile.h"
#include "RadixTree.h"
#include <string>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

PersonProfile::~PersonProfile()
{
	for (vector<AttValPair>::iterator attval = vectorPairs.begin(); attval != vectorPairs.begin(); ) {
		set<string>* Values = *AttValPairs.search(attval->attribute);
		delete Values;
	}
}

string PersonProfile::GetName() const {
	return m_name;
}

string PersonProfile::GetEmail() const {
	return m_email;
}

void PersonProfile::AddAttValPair(const AttValPair& attval)
{
	set<string>** values = AttValPairs.search(attval.attribute);

	if (values != nullptr) {
		set<string> insertable = (**values);
		if (values != nullptr) { //if the attribute already exists
			if (insertable.insert(attval.value).second) {
				cout << "WE GOT TO HERE" << endl;
			}
		}
	}
	else {

	}
	
}

//void PersonProfile::AddAttValPair(const AttValPair& attval) {
//	set<string>** values = AttValPairs.search(attval.attribute);
//	if (values != nullptr) { //if the attribute already exists
//		cout << (*values) << endl;
//		set<string> somename = *const_cast<set<string>*>(*values);
//
//		for (set<string>::iterator it = somename.begin(); it != somename.end(); ++it) {
//			cout << "TEST: " << *it << endl;
//		}
//		cout << "if the attribuuuuuuut exists" << endl;
//		if ((*values)->insert(attval.value).second) { //and doesn't already exist with the given value increment the number of AttValPairs and add the attribute value pairs to the vector
//			cout << "WE GOT TO HERE" << endl;
//			AttValPairs.insert(attval.attribute, *values);
//			numAttValPairs++;
//			vectorPairs.push_back(attval);
//		}
//	}
//	else { //if the attribute does not exist create a set of strings to map it to
//		cout << "this will print out first " << endl;
//		set<string> values2;
//		cout << &values2 << endl;
//		cout << attval.attribute << endl;
//		values2.insert(attval.value);
//
//		for (set<string>::iterator it = values2.begin(); it != values2.end(); ++it) {
//			cout << "TESTING: " << *it << endl;
//		}
//		AttValPairs.insert(attval.attribute, &values2);
//		set<string> ITERATE_THIS = **(AttValPairs.search(attval.attribute));
//		for (set<string>::iterator it = ITERATE_THIS.begin(); it != ITERATE_THIS.end(); it++) {
//			cout << "TESTING: " << *it << endl;
//		}
//		numAttValPairs++;
//		vectorPairs.push_back(attval);
//	}
//	return;
//}

int PersonProfile::GetNumAttValPairs() const {
	return numAttValPairs;
}

bool PersonProfile::GetAttVal(int attribute_num, AttValPair& attval) const {
	if (attribute_num < 0 || attribute_num > GetNumAttValPairs()) {
		return false;
	}
	attval = vectorPairs[attribute_num];
	return true;
}