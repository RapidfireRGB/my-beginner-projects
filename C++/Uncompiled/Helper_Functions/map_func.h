#ifndef HELPERFUNCTIONS_MAP_FUNC_H
#define HELPERFUNCTIONS_MAP_FUNC_H
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>

template <typename K, typename V>
// Prints contents of a map preserving the {x, y} notation
void print_map(std::map<K, V> map) {
    if (map.empty()) {
        return;
    }
    for (auto const& [key, value] : map) {
        std::cout << '{' << map[key] << ", " << map[value] << '}';
    }
}

template <typename K, typename V>
// Prints contents of a map separated by linebreaks.
void printbr_map(std::map<K, V> map) {
    if (map.empty()) {
        return;
    }
    for (auto const& [key, value] : map) {
        std::cout << '{' << map[key] << ", " << map[value] << '}' << "\n";
    }
}

template <typename K, typename V>
// Prints contents of a map separated by n number of whitespaces (default n=4)
void printtab_map(std::map<K, V> map, const short n=4) {
    if (map.empty()) {
        return;
    }
    for (auto const& [key, value] : map) {
        std::cout << '{' << map[key] << ", " << map[value] << '}' << std::string(n, ' ');
    }
}

template <typename K, typename V>
// Returns true if a key exists. Else, return false.
bool contains_key(const std::map<K, V> map, const K key) {
    if (map.empty()) {
        return false;
    }
    return map.count(key) > 0;
}

template <typename K, typename V>
// Inserts a key-value pair to a map only if the key does not already exist.
void insert_if_none(std::map<K, V> map, K key, V value) {
    if (!contains_key(map, key)) {
        map.insert({key, value});
    }
}

template <typename K, typename V>
// Inserts a key-value pair if a specified condition is met.
void insert_if(std::map<K, V> map, K key, V value, const bool condition) {
    if (condition == true) {
        map.insert({key, value});
    }
}

template <typename K, typename V>
// Returns a sub map with filtered elements based on a given condition.
std::map<K, V> filter(std::map<K, V> map, const bool condition) {
    std::map<K, V> new_map;
    if (map.empty()) {
        return new_map;
    }
    for (auto const& [key, value] : map && condition == true) {
        new_map.insert({key, value});
    }
    return new_map;
}

template <typename K, typename V>
// Returns a pair vector of map elements.
std::vector<std::pair<K, V>> map_to_pair_vec(std::map<K, V> map) {
    std::vector<std::pair<K, V>> new_vec;
    if (map.empty()) {
        return new_vec;
    }
    for (auto const& [key, value] : map) {
        new_vec.push_back(std::make_pair(key, value));
    }
    return new_vec;
}

template <typename K, typename V>
// Returns a vector of extracted keys.
std::vector<K> extract_keys(std::map<K, V> map) {
    std::vector<K> new_vec;
    if (map.empty()) {
        return new_vec;
    }
    for (auto const& [key, value] : map) {
        new_vec.push_back(key);
    }
    return new_vec;
}

template <typename K, typename V>
// Returns a vector of extracted values.
std::vector<V> extract_values(std::map<K, V> map) {
    std::vector<V> new_vec;
    if (map.empty()) {
        return new_vec;
    }
    for (auto const& [key, value] : map) {
        new_vec.push_back(value);
    }
    return new_vec;
}

// TODO handle non numerical elements here.
template <typename K, typename V>
// Returns lowest value in a map
V min(std::map<K, V> map) {
    if (map.empty()) {
        return 0;
    }

    // Gets the first value
    V minimum = map.begin()->second;

    for (auto const& [key, value] : map) {
        if (value < minimum) {
            minimum = value;
        }
    }
    return minimum;
}

template <typename K, typename V>
// Returns highest value in a map
V max(std::map<K, V> map) {
    if (map.empty()) {
        return 0;
    }
    V maximum = map.begin()->second;
    for (auto const& [key, value] : map) {
        if (value > maximum) {
            maximum = value;
        }
    }
    return maximum;
}

template <typename K, typename V>
// Slices a map between two key bounds and returns a sub map.
std::map<K, V> slice(std::map<K, V> map, K key_1, K key_2) {
    std::map<K, V> new_map;
    if (map.empty()) {
        return new_map;
    }
    // Bounds checking.
    if (!contains(map, key_1) || !contains(map, key_2)) {
        return new_map;
    }
    // Loops between bounds and inserts {key, value} to new map.
    for (auto i = map.lower_bound(key_1); i != map.upper_bound(key_2); ++i) {
        new_map.insert({i->first, i->second});
    }
    return new_map;
}

template <typename K, typename V>
// Updates existing key value pair, or inserts a new one if key is not found.
void update(std::map<K, V> map, K key, V value) {
    if (!contains(map, key)) {
        map.insert(key, value);
    }
    map[key] = value;
}

#endif //HELPERFUNCTIONS_MAP_FUNC_H