#include <iostream>
#include <random>
#include "src/names.h"

// rng function takes vector to get its size, so that the index position is within bounds.
int randomize(const std::vector<std::string> &target) {
    // Random number generation block
    std::random_device rd;
    std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 gen(seed);
    // Sets range from 0 to size of names vector. Minus 1 for index position.
    std::uniform_int_distribution<int> dist(0, target.size()-1);

    // Fetches a random index position
    const int n = dist(gen);
    return n;
}

int main() {
    std::string mon_name;
    std::cout << "Which Pokemon do you want to generate a nickname for?\n";
    std::cin >> mon_name;

    const int index = randomize(pokedex[mon_name]);

    // Prints the random name by fetching vector from string name, then index position of that vector.
    std::cout << pokedex[mon_name][index];
    return 0;
}