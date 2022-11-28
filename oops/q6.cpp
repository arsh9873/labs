#include<iostream>
class Complex
{
  int real;
  int img;
public:
    Complex (int r = 0, int i = 0)
  {
    real = r;
    img = i;
  }
  Complex operator+= (Complex c)
  {
    real += c.real;
    img += c.img;
    return *this;
  }
  Complex operator-= (Complex c)
  {
    real -= c.real;
    img -= c.img;
    return *this;
  }
  Complex operator*= (Complex c)
  {
    int r = real;
    real = real * c.real - img * c.img;
    img = r * c.img + img * c.real;
    return *this;
  }
  Complex operator/= (Complex c)
  {
    int r = real;
    real = (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img);
    img = (img * c.real - r * c.img) / (c.real * c.real + c.img * c.img);
    return *this;
  }
  friend std::ostream & operator<< (std::ostream & out, Complex & c);
};

std::ostream & operator<< (std::ostream & out, Complex & c)
{
  out << c.real << " + " << c.img << "i";
  return out;
}

int
main ()
{
  Complex c1 (2, 3), c2 (3, 4);
  c1 += c2;
  std::cout << "\n" << "adding = " << c1 << "\n";
  c1 -= c2;
  std::cout << "\n" << "subtracing = " << c1 << "\n";
  c1 *= c2;
  std::cout << "\n" << "multiplying = " << c1 << "\n";
  c1 /= c2;
  std::cout << "\n" << "dividing = " << c1 << "\n";
}
