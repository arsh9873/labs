#include <iostream>
class demo
{
  int x, y;
public:
    demo ()
  {
    x = 0;
    y = 0;
  }
  demo (int a, int b)
  {
    x = a;
    y = b;
  }
  friend demo operator + (demo & d1, demo & d2)
  {
    demo d3;
    d3.x = d1.x + d2.x;
    d3.y = d1.y + d2.y;
    return d3;
  }
  void display ()
  {
    std::cout << "X=" << x << "\n";
    std::cout << "Y=" << y << "\n";
  }
};

int main ()
{
  demo d1 (4, 5);
  demo d2 (1, 2);
  demo d3;
  d3 = operator + (d1, d2);
  std::cout << "Object C1\n";
  d1.display ();
  std::cout << "Object C2\n";
  d2.display ();
  std::cout << "Object C3\n";
  d3.display ();
  return 0;
}
