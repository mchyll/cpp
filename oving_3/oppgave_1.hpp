const double pi = 3.141592;

class Circle {
  public:
    Circle(double radius_);                          // Konstruktør må ha nøyaktig samme navn som klassen (stor C i Circle)
    int get_area() const;
    double get_circumference() const;
  private: double radius;                            // private skal etterfølges av :
};                                                   // Semikolon etter klassedeklarasjon

// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) : radius(radius_) {}  // Ikke public foran funksjonsdefinisjonen
                                                     // Datamedlemmet heter radius, funksjonsargumentet heter radius_

int Circle::get_area() const {                       // La til const for å stemme overens med klassedeklarasjonen
  return pi * radius * radius;
}

double Circle::get_circumference() const {           // La til returtype double for å stemme overens med klassedeklarasjonen
  double circumference = 2.0 * pi * radius;          // La til double for å definere variabelen circumference
  return circumference;
}
