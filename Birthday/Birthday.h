#pragma once

#ifndef BIRTHDAY_H
#define	BIRTHDAY_H

#include<iostream>
#include<vector>

using std::ostream;
using std::vector;

class Birthday
{
public:
	Birthday(int month=1, int day=1) : m(month), d(day) {}

	Birthday(const Birthday& a);

	// accessors
    int getMonth() const { return m; }
    int getDay() const { return d; }

    // mutators
    void setMonth(int month) { m = month; }
    void setDay(int day) { d = day; }

private:
	int m, d;
};

std::ostream& operator<<(std::ostream& out, const Birthday& b) {
	out << b.getMonth() << "/" << b.getDay();
	return out;
}

bool operator==(const Birthday& a, const Birthday& b) {
	return a.getMonth() == b.getMonth() && a.getDay() == b.getDay();
}
#endif