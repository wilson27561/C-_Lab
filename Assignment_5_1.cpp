
#include <iostream>
using namespace std;

int pow(int n, int m)
{
   const int arraysize = m;
   int ans = 1;
   int array[arraysize];

   for (int i = 0; i < arraysize; i++)
   {
      array[i] = n;
   }
   for (int i = 0; i < arraysize; i++)
   {
      ans = ans * array[i];
   }
   return ans;
}

int gcd(int x, int y)
{
   // std::cout << x << std::endl;
   if (x % y == 0)
   {
      return y;
   }
   else
   {
      return gcd(y, x % y);
   }
}

int main()
{
   pow(3, 4);
   gcd(9,3);
   return 0;
}