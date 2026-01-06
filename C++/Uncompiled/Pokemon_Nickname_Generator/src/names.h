#ifndef POKEMON_NICKNAME_GENERATOR_NAMES_H
#define POKEMON_NICKNAME_GENERATOR_NAMES_H
#include <array>
#include <string>
#include <map>
#include <vector>

// An array of basic Pokemon nicknames
inline std::array<std::string, 29> names = {
    "Sparky",
    "Chester",
    "Frigid",
    "Grabby",
    "Normie",
    "Randy",
    "Mimi",
    "Zerp",
    "Chock",
    "Florp",
    "Zigg",
    "Jeeb",
    "Byte",
    "Wonk",
    "Heavy",
    "Klock",
    "Nebula",
    "Nero",
    "Jort",
    "Ray",
    "Sickle",
    "Cryo",
    "Wibbly",
    "Poke",
    "Rose",
    "Magenta",
    "Polar",
    "Swimble",
    "Ghur"
};

// TODO add names for these pokemon and add all pokemon up to gen 5
inline std::vector<std::string> bulbasaur_names = {
    "Insert Name Here"
};

inline std::vector<std::string> ivysaur_names = {
    "Insert Name Here"
};

inline std::vector<std::string> venusaur_names = {
    "Insert Name Here"
};

inline std::vector<std::string> charmander_names = {
    "Inferno",
    "Cinder",
    "Zerd"
    //...
};

inline std::vector<std::string> charmeleon_names = {
    "Inferno",
    "Red Hot",
    "Insert Name Here"
};

inline std::vector<std::string> charizard_names = {
    "Insert Name Here"
};

inline std::vector<std::string> squirtle_names = {
    "Insert Name Here"
};

inline std::vector<std::string> wartortle_names = {
    "Insert Name Here"
};

inline std::vector<std::string> blastoise_names = {
    "Insert Name Here"
};

inline std::map<std::string, std::vector<std::string>> pokedex = {
    {"Bulbasaur", bulbasaur_names},
    {"Ivysaur", ivysaur_names},
    {"Venusaur", venusaur_names},
    {"Charmander", charmander_names},
    {"Charmeleon", charmeleon_names},
    {"Charizard", charizard_names},
    {"Squirtle", squirtle_names},
    {"Wartortle", wartortle_names},
    {"Blastoise", blastoise_names}
};

#endif //POKEMON_NICKNAME_GENERATOR_NAMES_H