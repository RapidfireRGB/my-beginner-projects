#include <iostream>
#include <random>
//#include <vector>
#include "src/names.h"

// rng function takes vector to get its size, so that the index position is within bounds.
int randomize(const std::vector<std::string> &target) {
    // Random number generation block
    std::random_device rd;
    std::seed_seq seed{rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 gen(seed);
    // Sets range from 0 to size of names vector. Minus 1 for index position.
    std::uniform_int_distribution<int> dist(0, target.size()-1);

    // Prints the random name by fetching array index
    const int n = dist(gen);
    return n;
}

int main() {
    std::string input;
    std::cout << "Which Pokemon do you want to generate a nickname for?\n";
    std::cin >> input;

    // Fetches a random index position to print a random name.
    // mons[input] is a map to a vector depending on the pokemon species (user input)
    const int index = randomize(pokedex[input]);

    std::cout << pokedex[input][index];
    return 0;
}