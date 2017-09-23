//Aisha Balogun Mohammed
//COSC 2030
//Homework 1 Part 3
//Help received from Damir Pulatov


#include "collection.h"

// TODO: reference any additional headers you need in STDAFX.H
// and not in this file

int main()
{
	Collection<int> testColl;
	testColl.print();
	for(int j = 0; j< 8; j++)
	{
		testColl.insert(j);
	}
	testColl.print();
	testColl.notContained(7);
	testColl.insert(10);
	testColl.notContained(7);
	testColl.remove(1);
	testColl.removeRandom();
	testColl.print();
	testColl.isEmpty();
	testColl.makeEmpty();
	testColl.isEmpty();
	testColl.insert(2);
	testColl.print();
	return 0;
}
