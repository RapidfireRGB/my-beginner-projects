#include <iostream>
const double pi = 3.14;
// Work in Progress.
struct 3dshape {
	double surface_area;
	double volume;

	[[nodiscard]] double surf() {
        return surface_area;
    }

    [[nodiscard]] double vol() {
        return volume;
    }

	void properties() const {
		std::cout << "Surface Area: " << surface_area << "\n";
		std::cout << "Volume: " << volume << "\n";
	}

};

struct sphere : 3dshape {
    double radius;
    double diameter;

	// Default constructor will define radius as 1 and diameter as 2.
	sphere() {
		radius = 1;
		diameter = 2;
	}

	// Only need to define a radius to construct a sphere.
	sphere(double r) : r(radius) {
		diameter = r*2;
		if (r <= 0) {
			diameter = 0;
		}
	}

	~sphere() = default;

	volume = (4 * pi)/3 * (radius * radius * radius);
	surface_area = (4 * pi) * (radius * radius);

	[[nodiscard]] double r() {
        return radius;
    }

    [[nodiscard]] double d() {
		if (radius == 0) {
			return 0;
		}
        return diameter;
    }

	// Prints info of a sphere. Type void.
	void properties() {
		std::cout << "Surface Area: " << surface_area << "\n";
		std::cout << "Volume: " << volume << "\n";
		std::cout << "Radius: " << radius << "\n";
		std::cout << "Diameter: " << diameter << "\n";

	}

};

struct cube : 3dshape {
	double sidelength;
	double face;

	cube() {
		sidelength = 1;
	}

	cube(double length) : length(sidelength) {
	}

	~cube() = default;

	face = sidelength * sidelength;
	surface_area = face * 6;
	volume = (sidelength * sidelength * sidelength);

	// Prints info of a cube. Type void.
	void properties() const override {
		std::cout << "Surface Area: " << surface_area << "\n";
		std::cout << "Volume: " << volume << "\n";
		std::cout << "Length of a Side: " << sidelength << "\n";
		std::cout << "Surface Area of a Face: " << face << "\n";
	}
};

struct cylinder : 3dshape {
	double radius;
	double diameter;
	double height;
	double base_circumference;
	double base_area;
	double wrap_area;


	cylinder() {
		radius = 1;
		diameter = 2;
		height = 1;
	}

	// Need to define radius and height to define a cylinder.
	cylinder(double r, double h) : r(radius), h(height) {
		diameter = 2*r;
		if (r <= 0) {
			std::cerr << "Radius cannot be negative. Diameter will default to 0.";
			diameter = 0;
		}
		if (h <= 0) {
			std::cerr << "Height cannot be negative. Height will default to 1.";
			h = 1;
		}
	}

	~cylinder() = default;

	void properties() const override {
		std::cout << "Surface Area: " << surface_area << "\n";
		std::cout << "Volume: " << volume << "\n";
		std::cout << "Radius: " << radius << "\n";
		std::cout << "Diameter: " << diameter << "\n";
		std::cout << "Circumference of a Base: " << base_circumference << "\n";
		std::cout << "Surface Area of a Base: " << base_area << "\n";
		std::cout << "Surface Area of Cross Section: " << wrap_area << "\n";

	}







};
