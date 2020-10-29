#ifndef CUSTOMHASHTABLE_H
#define CUSTOMHASHTABLE_H

#include <array>
#include <cstdlib>
#include <forward_list>
#include <functional>
#include <utility>

/** A map from keys of type KeyType to values of type ValueType,
    implemented as a hashtable. */
template <typename KeyType, typename ValueType>
class CustomHashTable
{
private:
	/** The number of buckets in the hashtable. */
	static const int num_buckets = 128;

	/** The type of each bucket: a list of (key, value) pairs. */
	using BucketType = std::forward_list<std::pair<KeyType, ValueType>>;

	/** The hash function. */
	std::hash<KeyType> hash_function;

public:
	/** Print out the items in the hashtable. */
	void print()
	{
		std::cout << "Contents:\n";

		for (int i = 0; i < num_buckets; i++)
		{
			for (const auto& item: buckets_[i])
			{
				std::cout << "- [" << i << "] ";
				std::cout << item.first;
				std::cout << " -> " << item.second << "\n";
			}
		}
	}

	/** Add or update an entry in the map. */
	void add(const KeyType& key, const ValueType& value)
	{
		// Work out which bucket this should be in.
		size_t bucket = hash_function(key) % num_buckets;

		// What is happening here?
		// Why is buckets_ being subscripted with the has value inside a for loop?
		// Because we need to potentially loop over ALL the entries at that hash number.
		for (auto& item: buckets_[bucket])
		{
			if (item.first == key)
			{
				// Update existing entry.
				item.second = value;
				return;
			}
		}

		// Add a new entry.
		buckets_[bucket].push_front(make_pair(key, value));
	}

	/** Return true if there's a mapping for a key. */
	bool is_present(const KeyType& key)
	{
		// Work out which bucket this should be in.
		size_t bucket = hash_function(key) % num_buckets;

		for (const auto& item : buckets_[bucket])
		{
			if (item.first == key)
			{
				return true;
			}
		}

		// If we get this far we didn't find the key.
		return false;

		//std::abort(); // FIXME implement this method
	}

	/** Get the value for a key. */
	const ValueType& get(const KeyType& key)
	{
		// Work out which bucket this should be in.
		size_t bucket = hash_function(key) % num_buckets;

		for (const auto& item : buckets_[bucket])
		{
			if (item.first == key)
			{
				return item.second;
			}
		}

		throw std::runtime_error("No key found.");
	}

private:
	/** The array of buckets. */
	std::array<BucketType, num_buckets> buckets_;
};

#endif
