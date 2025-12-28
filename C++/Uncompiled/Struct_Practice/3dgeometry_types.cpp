#include <iostream>
#include <cmath>
const double pi = 3.14;

struct 3dshape {
	double surface_area;
	double volume;

	[[nodiscard]] double surf() {
        return surface_area;
    }

    [[nodiscard]] double vol() {
        return volume;
    }

	void dimensions() const {
		std::cout << "Surface Area: " << surface_area << "\n";
		std::cout << "Volume: " << volume << "\n";
	}

};

struct sphere : 3dshape {
    double radius;
    double diameter;
	double circumference;

	// Default sphere with a radius of 1.
	sphere() {
		radius = 1;
		diameter = 2;
		circumference = 6.28;
	}

	// Only need to define a radius to construct a sphere.
	sphere(double r) : radius(r) {
		if (r <= 0) {
			std::cerr << "Radius cannot be negative. Radius will default to 1; Diameter will default to 2.\n";
			radius = 1;

		}
		diameter = r * 2;
		circumference = pi * diameter;
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
	void dimensions() const override{
		std::cout << "Surface Area: " << surface_area << "\n";
		std::cout << "Volume: " << volume << "\n";
		std::cout << "Radius: " << radius << "\n";
		std::cout << "Diameter: " << diameter << "\n";
		std::cout << "Circumference: " << circumference << "\n";
	}

};

struct cube : 3dshape {
	double sidelength;
	double face;

	// Default cube with a side length of 1.
	cube() {
		sidelength = 1;
	}

	cube(double length) : sidelength(length) {
	}

	~cube() = default;

	face = sidelength * sidelength;
	surface_area = face * 6;
	volume = (sidelength * sidelength * sidelength);

	// Prints info of a cube. Type void.
	void dimensions() const override {
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
	double circumference;
	double base_area;
	double wrap_area;

	// Default Cylinder with a radius of 1 and a height of 1.
	cylinder() {
		radius = 1;
		diameter = 2;
		height = 1;
		circumference = 6.28;
		base_area = 3.14;
		wrap_area = 6.28
	}

	// Need to define radius and height to define a cylinder.
	cylinder(double r, double h) : radius(r), height(h) {
		if (r <= 0) {
			std::cerr << "Radius cannot be negative. Radius will default to 1; Diameter will default to 2.\n";
			radius = 1;

		}
		if (h <= 0) {
			std::cerr << "Height cannot be negative. Height will default to 1.\n";
			h = 1;
		}
		diameter = 2 * r;
		circumference = pi * diameter;
		base_area = pi * (radius * radius);
		wrap_area = circumference * height;
	}

	~cylinder() = default;

	surface_area = (base_area * 2) + wrap_area;
	volume = base_area * height;

	void dimensions() const override {
		std::cout << "Surface Area: " << surface_area << "\n";
		std::cout << "Volume: " << volume << "\n";
		std::cout << "Radius: " << radius << "\n";
		std::cout << "Diameter: " << diameter << "\n";
		std::cout << "Circumference: " << circumference << "\n";
		std::cout << "Surface Area of a Base: " << base_area << "\n";
		std::cout << "Surface Area of Cross Section: " << wrap_area << "\n";

	}

};

struct cone : 3dshape {
	double radius;
	double diameter;
	double height;
	double slant_height;
	double base_circumference;
	double base_area;

	// Default cone with a radius of 1 and height of 1.
	cone() {
		radius = 1;
		diameter = 2;
		height = 1;
		base_circumference = 6.28;
		base_area = 3.14;
	}

	// Need to define a radius and height to define a cone.
	cone(double r, double h) : radius(r), height(h) {
		if (r <= 0) {
			std::cerr << "Radius cannot be negative. Radius will default to 1; Diameter will default to 2.\n";
			radius = 1;

		}
		if (h <= 0) {
			std::cerr "Height cannot be negative. Height will default to 1.\n";
			height = 1;
		}
		diameter = r * 2;
		base_circumference = pi * diameter;
		base_area = pi * (radius * radius);
	}

	~cone() = default;

	slant_height = std::sqrt((height * height) + (radius * radius));
	surface_area = pi * radius * (radius + slant_height);
	volume = (pi * (radius * radius) * height) / 3;

	void dimensions() const override {
		std::cout << "Surface Area: " << surface_area << "\n";
		std::cout << "Volume: " << volume << "\n";
		std::cout << "Radius: " << radius << "\n";
		std::cout << "Diameter: " << diameter << "\n";
		std::cout << "Height: " << height << "\n";
		std::cout << "Height of Slant: " << slant_height << "\n";
		std::cout << "Circumference of Base: " << base_circumference << "\n";
		std::cout << "Surface Area of Base: " << base_area << "\n";
	}

};

struct rectangularprism : 3dshape {
	double length;
	double width;
	double height;

	// Default rect prism has l=1; w=2; h=3
	rectangularprism() {
		length = 1;
		width = 2;
		height = 3;
	}

	rectangularprism(double l, double w, double h) : length(l), width(w), height(h) {
		if (l <= 0) {
			std::cerr << "Length cannot be negative. Length will default to 1.\n";
			length = 1;
		}
		if (w <= 0) {
			std::cerr << "Width cannot be negative. Width will default to 2.\n";
			width = 2;
		}
		if (h <= 0) {
			std::cerr << "Height cannot be negative. Height will default to 3.\n";
			height = 3;
		}
	}

	~rectangularprism() = default;

	surface_area = 2 * ((length * width) + (length * height) + (width * height));
	volume = length * width * height;

	void dimensions() const override {
		std::cout << "Surface Area: " << surface_area << "\n";
		std::cout << "Volume: " << volume << "\n";
		std::cout << "Length: " << length << "\n";
		std::cout << "Width: " << width << "\n";
		std::cout << "Height: " << height << "\n";

	}
};

struct triangularprism : 3dshape {


};

struct pyramid : 3dshape {


};