//
// Created by Aleksander Olsvik on 19.09.2023.
//

const double pi = 3.141592;

class Circle {
public:
    // Stor bokstav på konstruktør
    Circle(double radius_);
    int get_area() const;
    double get_circumference() const;

private:
    // riktig syntaks for deklarering av private attributter
    double radius;
};

// ==> Implementasjon av klassen Circle

// Ikke public, bare initialisering av den allerede deklarerte konstruktøren
Circle::Circle(double radius_) : radius(radius_) {}

// get_area() er deklarert som 'const', og må følge dette
int Circle::get_area() const {
    return pi * radius * radius;
}

// må ha rett datatype for deklarering
// circumference kan regnes ut, og trenger ikke å deklareres/initialiseres
double Circle::get_circumference() const {
    return 2.0 * pi * radius;
}