// Maps lab exercise
// Adam Sampson <a.sampson@abertay.ac.uk>

#include <cassert>
#include <iostream>
#include <string>

#include "CustomHashTable.h"
#include "CustomMap.h"
#include "CustomOAHashTable.h"

// Import things we need from the standard library
using std::cout;
using std::string;
using std::to_string;

// Test that a map class works.
// (Templated so we can use it with different map classes below.)
template <typename T>
void test_map(T& map)
{
	cout << "Test adding an item\n";
	assert(!map.is_present("Bob"));
	map.add("Bob", 37);
	assert(map.is_present("Bob"));
	assert(map.get("Bob") == 37);
	//assert(map.get("Andy") == 37);
	map.print();

	cout << "Test adding multiple items\n";
	map.add("Jim", 42);
	map.add("Ken", 64);
	map.add("Andy", 37);
	assert(map.get("Bob") == 37);
	assert(map.get("Jim") == 42);
	assert(map.get("Ken") == 64);
	assert(map.get("Andy") == 37);
	map.print();

	cout << "Test updating an item\n";
	map.add("Bob", 38);
	assert(map.get("Bob") == 38);
	map.add("Bob", 39);
	assert(map.get("Bob") == 39);
	map.print();

	const int count = 100;
	cout << "Test adding and updating " << count << " items\n";

	for (int i = 0; i < count; i++)
	{
		map.add(string("key") + to_string(i), 47);
	}

	for (int i = 0; i < count; i++)
	{
		map.add(string("key") + to_string(i), i);
	}

	for (int i = 0; i < count; i++)
	{
		assert(map.get(string("key") + to_string(i)) == i);
	}
}

int main(int argc, char *argv[])
{
	cout << "-- Testing CustomMap --\n";
	CustomMap<string, int> cm_ages;
	test_map(cm_ages);

	//cout << "-- Testing CustomHashTable --\n";
	//CustomHashTable<string, int> ht_ages;
	//test_map(ht_ages);

	//cout << "-- Testing CustomOAHashTable --\n";
	//CustomOAHashTable<string, int> oa_ages;
	//test_map(oa_ages);

	return 0;
}
