#include<iostream>
#include<vector>
#include<string>
#include"Polynom.h"
#include<sstream>
#include<iterator>

using namespace std;

Polynom::Polynom()
{
  //initializing an empty vector
  vector<int> P;
}

Polynom::Polynom(const vector<int>& coeff)
{
  //creating a polynomial with coefficients in the vector parameter
  this->P = coeff;
}

Polynom Polynom::operator+(const Polynom& RHS) const
{
  // Grab sizes of Polynom coefficient vectors.
  unsigned int l_size = this->P.size();
  unsigned int r_size = RHS.P.size();
  vector<int> vec;

  // Fill the smaller vector with leading 0s
  // until it is the same size as the larger.
  if (l_size > r_size)
  {
    Polynom temp(RHS.P);
    while (r_size < l_size)
    {
      temp.P.insert(temp.P.begin(), 0);
      r_size = temp.P.size();
    }
    vec = temp.P;
  }
  else if (r_size > l_size)
  {
    Polynom temp(this->P);
    while (l_size < r_size)
    {
      temp.P.insert(temp.P.begin(), 0);
      l_size = temp.P.size();
    }
    vec = temp.P;
  }
  else
  {
    vec = RHS.P;
  }

  // Initialize a Polynom object with largest sized vector.
  Polynom poly(vec);
  int size = poly.P.size();
  int l, r;
  // Add coefficients of the two vectors and store in Polynom object.
  for (int i=0; i<size; ++i)
  {
    if (this->getCoeff(size-i-1, l))
    {
      poly.setCoeff(size-i-1, l);
      if (RHS.getCoeff(size-i-1, r))
      {
        poly.setCoeff(size-i-1, l+r);
      }
    }
    else if (RHS.getCoeff(size-i-1, r))
    {
      poly.setCoeff(size-i-1, r);
      if (this->getCoeff(size-i-1, l))
      {
        poly.setCoeff(size-i-1, r+l);
      }
    }
    else
    {
      poly.setCoeff(size-i-1, 0);
    }
  }

  return poly;
}

Polynom Polynom::operator-(const Polynom& RHS) const
{
  // Grab sizes of Polynom coefficient vectors.
  unsigned int l_size = this->P.size();
  unsigned int r_size = RHS.P.size();
  vector<int> vec;

  // Fill the smaller vector with leading 0s
  // until it is the same size as the larger.
  if (l_size > r_size)
  {
    Polynom temp(RHS.P);
    while (r_size < l_size)
    {
      temp.P.insert(temp.P.begin(), 0);
      r_size = temp.P.size();
    }
    vec = temp.P;
  }
  else if (r_size > l_size)
  {
    Polynom temp(this->P);
    while (l_size < r_size)
    {
      temp.P.insert(temp.P.begin(), 0);
      l_size = temp.P.size();
    }
    vec = temp.P;
  }
  else
  {
    vec = RHS.P;
  }

  // Initialize a Polynom object with largest sized vector.
  Polynom poly(vec);
  int size = poly.P.size();
  int l, r;
  // Add coefficients of the two vectors and store in Polynom object.
  for (int i=0; i<size; ++i)
  {
    if (this->getCoeff(size-i-1, l))
    {
      poly.setCoeff(size-i-1, l);
      if (RHS.getCoeff(size-i-1, r))
      {
        poly.setCoeff(size-i-1, l-r);
      }
    }
    else if (RHS.getCoeff(size-i-1, r))
    {
      poly.setCoeff(size-i-1, -r);
      if (this->getCoeff(size-i-1, l))
      {
        poly.setCoeff(size-i-1, l-r);
      }
    }
    else
    {
      poly.setCoeff(size-i-1, 0);
    }
  }
  return poly;
}

double Polynom::operator()(double x) const
{
  double result = 0.0;
  //checking the condition that our vector is nonempty
  if(!this->P.empty())
  {
    //evaluating each element of the polynomial at the value
    for (long unsigned int i = 0; i <= this->P.size()-1; i++)
    {
      result = result*x + this->P[i];
    }
  }
  return result;
}

bool Polynom::getCoeff(int k, int& c) const
{
  int n = P.size()-1;
  //checking if the degree k is inside the bounds
  if(k >= 0 && k <= n)
  {
    //assigning c to the coefficient of x^k
    c = P[n-k];
    return true;
  }
  return false;
}

bool Polynom::setCoeff(int k, int c)
{
  int n = P.size()-1;
  //checking if the degree k is inside the bounds
  if(k >= 0 && k <= n)
  {
    //changes the coefficient of x^k to c to then return true
    P[n-k] = c;
    return true;
  }
  return false;
}

ostream& Polynom::printTerm(char sign, int pwr, int coeff, ostream& sout)
{
  return sout << sign << coeff << "x^" << pwr;
}

ostream& Polynom::insert(ostream& sout)
{
  char sign = ' ';
  string output;
  //if the vector is nonempty, then we can properly write out our polynomial
  if(!this->P.empty())
  {
    //looping to write out each individual term in our polynomial
    for(unsigned int i = 0; i < this->P.size(); i++)
    {
      //checks if the value is negative, then will print the term with a '-' in front
      if(this->P[i] < 0)
      {
        sign = '-';
        int pwr = this->P.size() - i - 1;
        int coeff = abs(this->P[i]);
        printTerm(sign, pwr, coeff, sout);
      }
      else
      {
        //if it is the first term, there will be no + in front of it
        if(this->P[i] > 0 && i == 0)
        {
        }
        else
        {
          sign = '+';
        }
        int pwr = this->P.size() - i - 1;
        int coeff = abs(this->P[i]);
        printTerm(sign, pwr, coeff, sout);
      }
    }
  }

  return sout;
}

istream& Polynom::extract(istream& sin)
{
  vector<int> nums;
  string user_input = "";
  getline(sin, user_input);

  istringstream iss(user_input);
  vector<string> str_nums{istream_iterator<string>{iss}, istream_iterator<string>{}};

  unsigned int length = str_nums.size();
  this->P.resize(str_nums.size());
  nums.resize(length);

  //reassigning the values of the vector str_nums to integer values in nums
  for(int i = 0; i < length; i++)
  {
    nums[i] = stoi(str_nums[length - i - 1]);
  }
  //setting the coefficients of the polynomial
  for(unsigned int i = 0; i < length; i++)
  {
    setCoeff(i, nums[i]);
  }

  return sin;
}

ostream& operator<<(ostream& Out, Polynom& RHS)
{
  RHS.insert(Out);

  return Out;
}

istream& operator>>(istream& In, Polynom& RHS)
{
  RHS.extract(In);

  return In;
}
