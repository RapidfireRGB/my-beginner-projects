#include <array>
#include <utility>
// Work in Progress.
struct grid {
    int grid_size;
    //std::array<int, grid_size> x_axis;
    //std::array<int, grid_size> y_axis;
    int x_coordinate = 0;
    int y_coordinate = 0;
    pair<int, int> coordinates = (x_coordinate, y_coordinate);
    //auto tilespace;

    grid(const int size) : grid_size(size) {
        if (size <= 0) {
            size = 1;
        }
    }

    ~grid() = default;

    
};
