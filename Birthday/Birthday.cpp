#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "Birthday.h"
#include <time.h>

using namespace std;

Birthday::Birthday(const Birthday& a) {}
int birthdayGen(const int n);

int randMonth() {
	int month = rand() % 12 + 1;
	return month;
}

int randDay(int month){
	int day;
		switch(month) {
			case 4: case 6: case 9: case 11: day = rand() % 30 + 1; break;	//30 Days for April, June, September, and November
			case 2: day = rand() % 29 + 1; break;	//29 Days for February
			default: day = rand() % 31 + 1; break;	//31 Days for the other months
		}
		return day;
}

int testBirthday(const int n) {
	int repeated = 0;
	srand(time(NULL));
	
	for(int i = 0; i < 10; i++) {
		if(birthdayGen(n) > 0) {
			repeated++;
		}
	}

	return repeated;
}

int birthdayGen(const int n) {
	int repeated = 0;

	// vector of five Birthday pointers
	vector<Birthday *> group(n);

	// allocate Birthday objects
	for(int i = 0; i < n; i++) {
		int month = randMonth();
		group[i] = new Birthday(month, randDay(month));
	}

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(*group[i] == *group[j]) { 
				repeated += 1;
			}
		}
	}

	return repeated;
}

int main() {

	for(int i = 5; i <= 100; i += 5) {
		cout << "For 10 trials, n = " << i << ", " << testBirthday(i) << " trials had at least one repeated birthday.\n";
	}

	char c;
	cin >> c;
	return EXIT_SUCCESS;
}