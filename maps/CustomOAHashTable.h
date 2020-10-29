#ifndef CUSTOMOAHASHTABLE_H
#define CUSTOMOAHASHTABLE_H

#include <array>
#include <cstdlib>
#include <functional>
#include <memory>
#include <utility>

/** A map from keys of type KeyType to values of type ValueType,
    implemented as a hashtable using open addressing. */
template <typename KeyType, typename ValueType>
class CustomOAHashTable {
private:
	/** The number of buckets in the hashtable. */
	static const int num_buckets = 128;

	/** The type of each bucket: a (key, value) pair. */
	using BucketType = std::pair<KeyType, ValueType>;

	/** The hash function. */
	std::hash<KeyType> hash_function;

public:
	/** Print out the items in the hashtable. */
	void print() {
		std::cout << "Contents:\n";
		for (int i = 0; i < num_buckets; i++) {
			const auto& bucket = buckets_[i];
			if (bucket) {
				std::cout << "- [" << i << "] ";
				std::cout << bucket->first;
				std::cout << " -> " << bucket->second << "\n";
			}
		}
	}

	/** Add or update an entry in the map. */
	void add(const KeyType& key, const ValueType& value) {
		// Hash the key.
		size_t key_hash = hash_function(key) % num_buckets;

		size_t pos = key_hash;
		do {
			if (!buckets_[pos]) {
				// New entry.
				buckets_[pos] = std::make_unique<BucketType>(key, value);
				return;
			}
			if (buckets_[pos]->first == key) {
				// Updating existing entry.
				buckets_[pos]->second = value;
				return;
			}

			// Move on to the next bucket, wrapping around
			// when we get to the last bucket.
			++pos;
			if (pos == num_buckets) {
				pos = 0;
			}
		} while (pos != key_hash);

		// No empty buckets left.
		std::abort();
	}

	/** Return true if there's a mapping for a key. */
	bool is_present(const KeyType& key) {
		std::abort(); // FIXME implement this method
	}

	/** Get the value for a key. */
	const ValueType& get(const KeyType& key) {
		std::abort(); // FIXME implement this method
	}

private:
	/** The array of buckets. */
	std::array<std::unique_ptr<BucketType>, num_buckets> buckets_;
};

#endif
