#include <iostream>
using namespace std;
class Person
{
private:
  double height;
  double weight;

public:
  static int const num = 1;

  Person(double h, double w)
  {
    height = h;
    weight = w;
  }
  double getHeight()
  {
    return height;
  }
  double getWeight()
  {
    return weight;
  }
  double calculateBMI()
  {
    return (weight / (height * height));
    calculateBMI(height, weight);
  }
  static double calculateBMI(double height,
                             double weight)
  {
    return (weight / (height * height));
  }
};
int main()
{
  Person x(1.91, 85);
  x.getHeight();
  x.calculateBMI();
  cout << x.calculateBMI(1.77, 54) << endl;
  cout << x.num << endl;
  cout << Person::calculateBMI(1.77, 54) << endl;
  cout << Person::num << endl;

  return 0;
}