#include <iostream>

class Point2d
{
  private:
    double m_x = 0.0;
    double m_y = 0.0;

  public:
    Point2d() {}
    Point2d(double x, double y) : m_x{x}, m_y{y} {}
    void print()
    {
      std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
    Point2d first;
    Point2d second(3.0, 4.0);
    first.print();
    second.print();

    return 0;
}
