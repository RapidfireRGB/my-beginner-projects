#include <cstdio>
#include <iostream>
#include <cmath>

//Defines WoW's Level Curve as an array. Index 0 is unused since the Player level is between 1 and 59.
//Also fetches total xp needed to level up at a given level (xp_to_level).
int get_xp(int current_level) {
    static const int XP_Table[60] = {
        0,  // Unused index 0
        400,
        900,
        1400,
        2100,
        2800,
        3600,
        4500,
        5400,
        6500,
        7600,
        8800,
        10100,
        11400,
        12900,
        14400,
        16000,
        17700,
        19400,
        21300,
        23200,
        25200,
        27300,
        29400,
        31700,
        34000,
        36400,
        38900,
        41400,
        44300,
        47400,
        50800,
        54500,
        58600,
        62800,
        67100,
        71600,
        76100,
        80800,
        85700,
        90700,
        95800,
        101000,
        106300,
        111800,
        117500,
        123200,
        129100,
        135100,
        141200,
        147500,
        153900,
        160400,
        167100,
        173900,
        180800,
        187900,
        195000,
        202300,
        209800
    };
    if (current_level < 1 || current_level > 59) {
        std::cout << "Invalid Player Level!" << std::endl;
        return -1;
    }
    return XP_Table[current_level];
}

//Simple subtract Function to calculate how much XP to get from current level to the next.
int get_xp_to_level(int current_level, int current_xp) {
    int max_xp = get_xp(current_level);
    int xp_to_level = max_xp - current_xp;
    return xp_to_level;
}

//Division Function to calculate how many On-Level Mobs the Player must kill to level up.
int get_mob_xp(int current_level, int current_xp) {
    int mob_xp = 5 * (current_level - 1) + 50;
    int mobs_to_level = std::ceil(get_xp_to_level(current_level, current_xp) / mob_xp);
    return mobs_to_level;
}

//Main Function accepts Player Level and XP, then prints the output of the two functions above.
int main() {

    int current_level;
    int current_xp;

    std::cout << "Type your Current Level: \n";
    std::cin >> current_level;
    std::cout << "Type your Current XP: \n";
    std::cin >> current_xp;

    printf("Level: %d\nXP to Next Level: %d\nMobs You Must Slay: %d\nWith Rested XP: %d\n",
            current_level, get_xp_to_level(current_level, current_xp),
            get_mob_xp(current_level, current_xp), get_mob_xp(current_level, current_xp)/2);

    return 0;
}