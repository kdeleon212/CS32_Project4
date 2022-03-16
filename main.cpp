#include "PersonProfile.h"
#include "RadixTree.h"
#include <string>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	PersonProfile AF = PersonProfile("Abdullah Fowler", "AbFow2483@charter.net");
	PersonProfile::AttValPair Pair1 = PersonProfile::AttValPair("hobby", "painting");
	PersonProfile::AttValPair Pair2 = PersonProfile::AttValPair("hobby", "slacklining");
	PersonProfile::AttValPair Pair3 = PersonProfile::AttValPair("hobby", "painting");
	AF.AddAttValPair(Pair1);
	AF.AddAttValPair(Pair2);
	AF.AddAttValPair(Pair3);
	cout << AF.GetNumAttValPairs() << endl;

	RadixTree<set<string>*> Test;
	set<string> stringset1;
	set<string>* string1 = &stringset1;

	(*string1).insert("games");
	Test.insert("hobby", string1);
	(*(*(Test.search("hobby")))).insert("BLAHBING");

	for (set<string>::iterator it = stringset1.begin(); it != stringset1.end(); it++) {
		cout << "attribute: " << *it << endl;
	}

	//if (*(Test.search("hobby")) == string1) {
	//	cout << "this is true" << endl;
	//}
}