#include <iostream>
#include <cmath>
constexpr double pi = 3.14;

struct threedimensional {
	double surface_area;
	double volume;

	// Child classes will use their respective formulas here for constructor inputs.
	threedimensional(double sa, double v) : surface_area(sa), volume(v) {
	}

	virtual ~threedimensional() = default;

	[[nodiscard]] double surf() const {
        return surface_area;
    }

    [[nodiscard]] double vol() const {
        return volume;
    }

	virtual void dimensions() const {
		std::cout << "Surface Area: " << surface_area << "\n";
		std::cout << "Volume: " << volume << "\n";
	}

};

struct sphere final : threedimensional {
    double radius;
    double diameter;
	double circumference;

	// Default sphere with a radius of 1.
	sphere() : threedimensional(12.57, 4.19){
		radius = 1;
		diameter = 2;
		circumference = 6.28;
	}

	// Only need to define a radius to construct a sphere.
    explicit sphere(const double r) : threedimensional(
		(4 * pi) * (r * r),
		(4 * pi)/3 * (r * r * r)) {

		radius = r;

		if (r <= 0) {
			std::cerr << "Radius cannot be negative. Radius will default to 1; Diameter will default to 2.\n";
			radius = 1;
			surface_area = 12.57;
			volume = 4.19;
		}

		diameter = radius * 2;
		circumference = pi * diameter;
	}

	~sphere() override = default;

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

	//void formulae() {
	// Print relevant formulas for this shape
	//}

};

struct cube final : threedimensional {
	double sidelength;
	double face;

	// Default cube with a side length of 1.
	cube() : threedimensional(6, 1){
		sidelength = 1;
		face = 1;
	}

	explicit cube(const double length) : threedimensional(
		6 * (length * length),
		(length * length * length)) {

		sidelength = length;

		if (length <= 0) {
			std::cerr << "Sidelength cannot be negative. Sidelength will default to 1.\n";
			sidelength = 1;
			surface_area = 6;
			volume = 1;
		}
		face = sidelength * sidelength;
	}

	~cube() override = default;

	// Prints info of a cube. Type void.
	void dimensions() const override {
		std::cout << "Surface Area: " << surface_area << "\n";
		std::cout << "Volume: " << volume << "\n";
		std::cout << "Length of a Side: " << sidelength << "\n";
		std::cout << "Surface Area of a Face: " << face << "\n";
	}
};

struct cylinder final : threedimensional {
	double radius;
	double diameter;
	double height;
	double circumference;
	double base_area;
	double wrap_area;

	// Default Cylinder with a radius of 1 and a height of 1.
	cylinder() : threedimensional(12.57, 3.14){
		radius = 1;
		diameter = 2;
		height = 1;
		circumference = 6.28;
		base_area = 3.14;
		wrap_area = 6.28;
	}

	// Need to define radius and height to define a cylinder.
	cylinder(const double r, const double h) : threedimensional(
		2 * (pi * (r * r)) + h * (2 * pi * r),
		pi * (r * r) * h) {

		radius = r;
		height = h;
		bool has_valid_dimensions = true;
		if (r <= 0) {
			std::cerr << "Radius cannot be negative. Radius will default to 1; Diameter will default to 2.\n";
			radius = 1;
			has_valid_dimensions = false;
		}

		if (h <= 0) {
			std::cerr << "Height cannot be negative. Height will default to 1.\n";
			height = 1;
			has_valid_dimensions = false;
		}

		// If invalid values are given for r or h, recalculate surface area and volume.
		if (!has_valid_dimensions) {
			surface_area = 2 * (pi * (radius*radius)) + height * (2 * pi * radius);
			volume = pi * (radius * radius) * height;
		}

		diameter = radius * 2;
		circumference = pi * diameter;
		base_area = pi * (radius * radius);
		wrap_area = circumference * height;
	}

	~cylinder() override = default;

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

struct cone final : threedimensional {
	double radius;
	double diameter;
	double height;
	double slant_height;
	double base_circumference;
	double base_area;

	// Default cone with a radius of 1 and height of 1.
	cone() : threedimensional(7.58, 1.05) {
		radius = 1;
		diameter = 2;
		height = 1;
		slant_height = sqrt((height * height) + (radius * radius));
		base_circumference = 6.28;
		base_area = 3.14;
	}

	// Need to define a radius and height to define a cone.
	cone(const double r, const double h) : threedimensional(
		pi * r * (r + sqrt((h*h) + (r*r))) + pi * (r * r),
		(pi * (r * r) * h)/3) {

		radius = r;
		height = h;
		bool has_valid_dimensions = true;

		if (r <= 0) {
			std::cerr << "Radius cannot be negative. Radius will default to 1; Diameter will default to 2.\n";
			radius = 1;
			has_valid_dimensions = false;
		}

		if (h <= 0) {
			std::cerr << "Height cannot be negative. Height will default to 1.\n";
			height = 1;
			has_valid_dimensions = false;
		}

		slant_height = sqrt((height * height) + (radius * radius));

		// If invalid values are given for r or h, recalculate surface area and volume.
		if (!has_valid_dimensions) {
			surface_area = pi * radius * (radius + slant_height) + pi * (radius * radius);
			volume = (pi * (radius * radius) * height) / 3;
		}
		diameter = radius * 2;
		base_circumference = pi * diameter;
		base_area = pi * (radius * radius);
	}

	~cone() override = default;

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

struct rectangularprism final : threedimensional {
	double length;
	double width;
	double height;

	// Default rect prism has l=1; w=2; h=3
	rectangularprism() : threedimensional(22, 6){
		length = 1;
		width = 2;
		height = 3;
	}

	rectangularprism(const double l, const double w, const double h) : threedimensional(
		2 * ((l * w) + (l * h) + (w * h)),
		l * w * h) {

		length = l;
		width = w;
		height = h;
		bool has_valid_dimensions = true;

		if (l <= 0) {
			std::cerr << "Length cannot be negative. Length will default to 1.\n";
			length = 1;
			has_valid_dimensions = false;
		}
		if (w <= 0) {
			std::cerr << "Width cannot be negative. Width will default to 2.\n";
			width = 2;
			has_valid_dimensions = false;
		}
		if (h <= 0) {
			std::cerr << "Height cannot be negative. Height will default to 3.\n";
			height = 3;
			has_valid_dimensions = false;
		}
		if (!has_valid_dimensions) {
			surface_area = 2 * ((length * width) + (length * height) + (width * height));
			volume = length * width * height;
		}
	}

	~rectangularprism() override = default;

	void dimensions() const override {
		std::cout << "Surface Area: " << surface_area << "\n";
		std::cout << "Volume: " << volume << "\n";
		std::cout << "Length: " << length << "\n";
		std::cout << "Width: " << width << "\n";
		std::cout << "Height: " << height << "\n";
	}
};

struct triangularprism : threedimensional {


};

struct pyramid : threedimensional {


};