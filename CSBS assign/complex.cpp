#include <iostream>

using namespace std;

class Complex
{
  int real, img;
public:
    Complex ();
  void input ();
  Complex operator+ (Complex ob);
  Complex operator- (Complex ob);
  Complex operator* (Complex ob);
  void operator==(Complex ob);
  void display ();
};

Complex::Complex ()
{
  real = 0;
  img = 0;
}

void Complex::input ()
{
  cout << "Enter the real and imaginary part" << endl;
  cin >> real >> img;
}

void Complex::display ()
{
  cout << "The complex number is:" << endl;
  cout << real << "+" << img << "i" << endl;
}

Complex Complex::operator+ (Complex ob)
{
  Complex res;
  res.real = real + ob.real;
  res.img = img + ob.img;
  return res;
}

Complex Complex::operator- (Complex ob)
{
  Complex
    res;
  res.real = real - ob.real;
  res.img = img - ob.img;
  return res;
}

Complex Complex::operator* (Complex ob)
{
  Complex
    res;
  res.real = (real * ob.real) - (img * ob.img);
  res.img = (real * ob.real) + (img * ob.img);
  return res;
}


void Complex::operator== (Complex ob)
{
  if (this->real == ob.real)
    {
      if (this->img == ob.img)
	{
	  cout << "Complex Nos. are equal" << endl;
	}
    }
  else
    cout << "Complex Nos. are not equal" << endl;
}

int main ()
{
  Complex a, b;
  a.input ();
  b.input ();
  a.display ();
  b.display ();
  a == b;
  Complex c = a + b;
  cout<<"After adding:";
  c.display ();
  Complex d=a-b;
   cout<<"After subtracting:";
  d.display();
  Complex e=a*b;
   cout<<"After multiplying:";
  e.display();
}
