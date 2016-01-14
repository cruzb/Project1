#include "Router.h"
#include <string>
#include <iostream>
#include <cassert>

void testChange();
void testSwap();
void testLength();


int main(){
	testChange();

	testSwap();
	
	testLength();
}

void testChange(){
	cout << "TESTING CHANGE" << endl;
	Router router;

	vector<string> words;
	words.push_back("this"); words.push_back("thas"); //1 letter changed
	words.push_back("this"); words.push_back("thas "); //different length
	words.push_back("this"); words.push_back("that"); //2 letters changed
	words.push_back("this"); words.push_back("this"); //no letters changed

	cout << words[0] << " and " << words[1] << endl;
	assert(router.canChange(words[0], words[1]));
	cout << words[2] << " and " << words[3] << endl;
	assert(!router.canChange(words[2], words[3]));
	cout << words[4] << " and " << words[5] << endl;
	assert(!router.canChange(words[4], words[5]));
	cout << words[6] << " and " << words[7] << endl;
	assert(!router.canChange(words[6], words[7]));

	cout << "TESTING CHNAGE COMPLETE" << endl << endl;
}

void testSwap(){
	cout << "TESTING SWAP" << endl;
	Router router;

	vector<string> words;
	words.push_back("this"); words.push_back("thsi"); //1 pair swapped
	words.push_back("this"); words.push_back("thsi "); //different length
	words.push_back("this"); words.push_back("htsi"); //2 pairs swapped
	words.push_back("this"); words.push_back("tsih"); //1 pair swapped not adjacent
	words.push_back("this"); words.push_back("ihts"); //1 pair swapped not adjacent, other direction
	words.push_back("this"); words.push_back("this"); // no pairs swapped


	cout << words[0] << " and " << words[1] << endl;
	assert(router.canSwap(words[0], words[1]));
	cout << words[2] << " and " << words[3] << endl;
	assert(!router.canSwap(words[2], words[3]));
	cout << words[4] << " and " << words[5] << endl;
	assert(!router.canSwap(words[4], words[5]));
	cout << words[6] << " and " << words[7] << endl;
	assert(!router.canSwap(words[6], words[7]));
	cout << words[8] << " and " << words[9] << endl;
	assert(!router.canSwap(words[8], words[9]));
	cout << words[10] << " and " << words[11] << endl;
	assert(!router.canSwap(words[10], words[11]));

	cout << "TESTING SWAP COMPLETE" << endl << endl;
}

void testLength(){
	cout << "TESTING LENGTH" << endl;
	Router router;

	vector<string> words;
	words.push_back("this"); words.push_back("thisi"); //1 added
	words.push_back("this"); words.push_back("thi"); //1 removed
	words.push_back("this"); words.push_back("ttisi"); //1 added, 1 changed
	words.push_back("this"); words.push_back("thisis"); //2 added
	words.push_back("this"); words.push_back("th"); //2 removed
	words.push_back("this"); words.push_back("this"); //no change


	cout << words[0] << " and " << words[1] << endl;
	assert(router.canLength(words[0], words[1]));
	cout << words[2] << " and " << words[3] << endl;
	assert(router.canLength(words[2], words[3]));
	cout << words[4] << " and " << words[5] << endl;
	assert(!router.canLength(words[4], words[5]));
	cout << words[6] << " and " << words[7] << endl;
	assert(!router.canLength(words[6], words[7]));
	cout << words[8] << " and " << words[9] << endl;
	assert(!router.canLength(words[8], words[9]));
	cout << words[10] << " and " << words[11] << endl;
	assert(!router.canLength(words[10], words[11]));

	cout << "TESTING LENGTH COMPLETE" << endl << endl;

}