#include <iostream>
#include "Polynom.h"

using namespace std;

int main()
{
  vector<int>V1 = {3,2,1,16};
  int val;

  Polynom poly1(V1);
  Polynom poly2;

  cout << "Polynomial 1 is: " << endl;
  cout << poly1 << endl;

  cout << "Enter the coefficients for polynomial 2: " << endl;
  cin >> poly2;
  cout << endl;

  Polynom res1;
  Polynom res2;
  Polynom res3;
  res1 = poly1 + poly2;
  res2 = poly1 - poly2;
  res3 = poly2 - poly1;

  cout << "Polynomial 1 is : " << poly1 << endl;
  cout << endl;

  cout << "Polynomial 2 is : " << poly2 << endl;
  cout << endl;

  cout << "Polynomial 1 + Polynomial 2 is : " << res1 << endl;
  cout << endl;

  cout << "Polynomial 1 - Polynomial 2 is : " << res2 << endl;
  cout << endl;

  cout << "Polynomial 2 - Polynomial 1 is : " << res3 << endl;
  cout << endl;

  cout << "Enter a number for the polynomials to be evaluated at: ";
  cin >> val;
  cout << endl;

  cout << poly1 << " evaluated at x = " << val << " is equal to: " << poly1(val) << endl;
  cout << endl;

  cout << poly2 << " evaluated at x = " << val << " is equal to: " << poly2(val) << endl;
  cout << endl;

  return 0;
}
