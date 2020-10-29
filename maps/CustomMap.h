#ifndef CUSTOMMAP_H
#define CUSTOMMAP_H

#include <cstdlib>
#include <forward_list>
#include <utility>

/** A map from keys of type KeyType to values of type ValueType. */
template <typename KeyType, typename ValueType>
class CustomMap {
public:
	/** Print out the items in the map. */
	void print() {
		std::cout << "Contents:\n";
		for (const auto& item: items_) {
			std::cout << "- " << item.first;
			std::cout << " -> " << item.second << "\n";
		}
	}

	/** Add or update an entry in the map. */
	void add(const KeyType& key, const ValueType& value) {
		for (auto& item: items_) {
			if (item.first == key) {
				// The key is already in the map.
				// Update the value for it.
				item.second = value;
				return;
			}
		}

		// The key isn't already in the map. Add a new item.
		items_.push_front(std::make_pair(key, value));
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
	/** The list of items, where each item is a (key, value) pair. */
	std::forward_list<std::pair<KeyType, ValueType>> items_;
};

#endif
