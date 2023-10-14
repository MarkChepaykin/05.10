#include <iostream>
#include <string>

class Fraction {
private:
  int numerator;
  int denominator;

  static const std::string ZERO_DIVISION_ERROR;

public:
  Fraction() : numerator(0), denominator(1) {}

  Fraction(int nmrtr, int dnmntr) : numerator(nmrtr), denominator(dnmntr) {
    if (denominator == 0) {
      std::cout << ZERO_DIVISION_ERROR;
      denominator = 1;
    }
  }

  void edit() {
    std::cout << "Enter numerator: ";
    std::cin >> numerator;
    std::cout << "Enter denominator: ";
    std::cin >> denominator;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore();
      std::cout << "Invalid input. Setting to default values.\n";
      numerator = 0;
      denominator = 1;
    } else if (denominator == 0) {
      std::cout << ZERO_DIVISION_ERROR;
      denominator = 1;
    }
  }

  void print() const {
    std::cout << "Fraction: " << numerator << "/" << denominator << "\n";
  }

  Fraction add(const Fraction &other) const {
    return Fraction(numerator * other.denominator +
                        other.numerator * denominator,
                    denominator * other.denominator);
  }

  Fraction subtract(const Fraction &other) const {
    return Fraction(numerator * other.denominator -
                        other.numerator * denominator,
                    denominator * other.denominator);
  }

  Fraction multiply(const Fraction &other) const {
    return Fraction(numerator * other.numerator,
                    denominator * other.denominator);
  }

  Fraction divide(const Fraction &other) const {
    if (other.numerator == 0) {
      std::cout << ZERO_DIVISION_ERROR;
      return Fraction();
    }
    return Fraction(numerator * other.denominator,
                    denominator * other.numerator);
  }
};

const std::string Fraction::ZERO_DIVISION_ERROR =
    "\nDividing by zero is like cutting the cake into 0 pieces, which doesn't "
    "make any sense at all.\n";

int main() {
  Fraction x, y, result;
  int choice;

  while (true) {
    std::cout << "\nSet first fraction:\n";
    x.edit();
    x.print();

    std::cout << "\nSet second fraction:\n";
    y.edit();
    y.print();

    std::cout << "\nFraction operations:\n1) Add\n2) Subtract\n3) Multiply\n4) "
                 "Divide\n0) Exit\nChoose operation: ";
    std::cin >> choice;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore();
      std::cout << "Invalid choice. Try again.\n";
      continue;
    }

    switch (choice) {
    case 1:
      result = x.add(y);
      result.print();
      break;
    case 2:
      result = x.subtract(y);
      result.print();
      break;
    case 3:
      result = x.multiply(y);
      result.print();
      break;
    case 4:
      result = x.divide(y);
      result.print();
      break;
    case 0:
      return 0;
    default:
      std::cout << "Wrong input\n";
      break;
    }
  }
}

// A new commit with a collaborator