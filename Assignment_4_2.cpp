// Perform huge integer operations.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <ctime>

// Rendomly generates a positive huge integer
void random(int hugeInt[], int hugeIntSize);

// Returns true if and only if hugeInt1 == hugeInt2
bool equal(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
   if (hugeInt1Size != hugeInt2Size)
   {
      return false;
   }
   bool equal = true;
   int start = hugeInt1Size - 1;
   for (int i = start; i >= 0; i--)
   {
      if (hugeInt1[i] != hugeInt2[i])
      {
         equal = false;
         break;
      }
   }
   return equal;
};

// Returns true if and only if hugeInt1 != hugeInt2
bool notEqual(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
   if (hugeInt1Size != hugeInt2Size)
   {
      return true;
   }
   bool equal = false;
   int start = hugeInt1Size - 1;
   for (int i = start; i >= 0; i--)
   {
      if (hugeInt1[i] != hugeInt2[i])
      {
         equal = true;
         break;
      }
   }
   return equal;
}

// Returns true if and only if hugeInt1 < hugeInt2
bool less(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
   bool isLess = false;
   if (hugeInt2Size > hugeInt1Size)
   {
      return true;
   }
   if (hugeInt1Size > hugeInt1Size)
   {
      return false;
   }
   if (hugeInt1Size == hugeInt2Size)
   {
      int start = hugeInt1Size - 1;
      for (int i = start; i >= 0; i--)
      {
         if (hugeInt2[i] > hugeInt1[i])
         {
            isLess = true;
         }
      };
   }
   return isLess;
}

// Returns true if and only if hugeInt1 > hugeInt2
bool greater(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{

   bool isGreater = false;
   if (hugeInt1Size > hugeInt2Size)
   {
      return true;
   };
   if (hugeInt1Size < hugeInt2Size)
   {
      return false;
   };
   if (hugeInt1Size == hugeInt2Size)
   {
      int start = hugeInt1Size - 1;
      for (int i = start; i >= 0; i--)
      {
         if (hugeInt1[i] > hugeInt2[i])
         {
            isGreater = true;
         }
      };
   };
   return isGreater;
}

// Returns true if and only if hugeInt1 <= hugeInt2
bool lessEqual(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
   if (equal(hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size))
   {
      return true;
   }
   if (less(hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size))
   {
      return true;
   }
   return false;
}

// Returns true if and only if hugeInt1 >= hugeInt2
bool greaterEqual(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
   if (equal(hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size))
   {
      return true;
   }
   if (greater(hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size))
   {
      return true;
   }
   return false;
}

// sum = addend + adder
void addition(int addend[], int adder[], int sum[], int addendSize, int adderSize, int &sumSize)
{

   sumSize = addendSize > adderSize ? addendSize : adderSize;
   int plus = 0;
   for (int i = 0; i < sumSize; i++)
   {
      sum[i] = addend[i] + adder[i] + sum[i];

      if (sum[i] >= 10)
      {
         sum[i] = sum[i] - 10;
         sum[i + 1]++;
      }
   }
   if (sum[sumSize] != 0)
   {
      sumSize++;
   }
};

// difference = minuend - subtrahend
void subtraction(int minuend[], int subtrahend[], int difference[],
                 int &minuendSize, int subtrahendSize, int &differenceSize)
{
   // differenceSize = minuendSize > subtrahendSize ? minuendSize : subtrahendSize;
   // int min = 0;
   // for (int i = 0; i < differenceSize; i++)
   // {
   //    if (i >= subtrahendSize)
   //    {
   //       if (minuend[i] - min < 0)
   //       {
   //          difference[i] = minuend[i] - min + 10;
   //          min = 1;
   //       }
   //       else
   //       {
   //          difference[i] = minuend[i] - min;
   //          min = 0;
   //       }
   //    }
   //    else if (subtrahend[i] > (minuend[i] - min))
   //    {
   //       difference[i] = minuend[i] + 10 - subtrahend[i] - min;
   //       min = 1;
   //    }
   //    else
   //    {
   //       difference[i] = minuend[i] - subtrahend[i] - min;
   //       min = 0;
   //    }
   // }
   // for (int i = 0; i < 60; i++)
   // {
   //    std::cout << difference[i];
   // }
   // std::cout << "  " << std::endl;
   differenceSize = minuendSize > subtrahendSize ? minuendSize : subtrahendSize;
   int min = 0;
   for (int i = 0; i < differenceSize; i++)
   {
      if (i < subtrahendSize)
      {
         if (subtrahend[i] > (minuend[i] - min))
         {
            difference[i] = minuend[i] - min + 10 - subtrahend[i];
            min = 1;
         }
         else
         {
            difference[i] = minuend[i] - min - subtrahend[i];
            min = 0;
         }
      }
      else
      {
         if (minuend[i] - min < 0)
         {
            difference[i] = minuend[i] - min + 10;
            min = 1;
         }
         else
         {
            difference[i] = minuend[i] - min;
            min = 0;
         }
      };
   }
   // for (int i = 0; i < 2; i++)
   // {
   //    std::cout << difference[i] << std::endl;
   // }

   int digits = 0;
   for (int i = (minuendSize + subtrahendSize - 1); i >= 0; i--)
   {
      if (difference[i] == 0)
      {
         ++digits;
         continue;
      }
      else
      {
         break;
      }
   }
   differenceSize = minuendSize + subtrahendSize - digits;
}

// product = multiplicand * multiplier
void multiplication(int multiplicand[], int multiplier[], int product[],
                    int multiplicandSize, int multiplierSize, int &productSize)
{
   for (int i = 0; i < multiplierSize; i++)
   {
      for (int j = 0; j < multiplicandSize; j++)
      {
         product[i + j] += multiplier[i] * multiplicand[j];
      }
   }

   for (int i = 0; i < (multiplierSize + multiplicandSize); i++)
   {
      if (product[i] >= 10)
      {
         product[i + 1] += product[i] / 10;
         product[i] %= 10;
      }
   }

   int minus = 0;
   for (int i = (multiplierSize + multiplicandSize - 1); i >= 0; i--)
   {
      if (product[i] == 0)
      {
         ++minus;
         continue;
      }
      else
      {
         break;
      }
   }
   productSize = multiplierSize + multiplicandSize - minus;
}

// cout << hugeInt1 << op << hugeInt2 << " == " << hugeInt3 << endl << endl;
void printOperation(int hugeInt1[], int hugeInt2[], int hugeInt3[], char op,
                    int hugeInt1Size, int hugeInt2Size, int hugeInt3Size);

// cout << hugeInt1 << string << hugeInt2 << endl << endl;
void print(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size, char string[]);

// function main begins program execution
int main()
{
   srand(static_cast<int>(time(0)));
   unsigned int seed;
   cout << "Enter seed: ";
   cin >> seed;
   cout << endl;
   // srand(seed);

   const int arraySize = 80;
   int hugeInt1[arraySize] = {0};
   int hugeInt1Size = 30 + rand() % 10;
   random(hugeInt1, hugeInt1Size);

   int hugeInt2[arraySize] = {0};
   int hugeInt2Size = (hugeInt1Size / 2) + rand() % (hugeInt1Size / 2);
   random(hugeInt2, hugeInt2Size);

   // equal :
   // if (hugeInt1 == hugeInt1)
   //    cout << hugeInt1 << " == " << hugeInt1 << endl
   //         << endl;
   // if (equal(hugeInt1, hugeInt1, hugeInt1Size, hugeInt1Size))
   // {
   //     char symbol[] = "==";
   //    print(hugeInt1, hugeInt1, hugeInt1Size, hugeInt1Size, symbol);
   // };

   // if (hugeInt1 == hugeInt1)
   //    cout << hugeInt1 << " == " << hugeInt2 << endl
   //         << endl;
   // if (equal(hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size))
   // {
   //    char symbol[] = "==";
   //    print(hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size, symbol);
   // };
   // if ( hugeInt2 == hugeInt1 ) cout << hugeInt2 << " == " << hugeInt1 << endl << endl;
   // if ( equal( hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size ) ){
   //   char symbol[] = "==";
   //   print( hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size, symbol );
   // }

   //notEqual :
   // if (hugeInt1 != hugeInt1)
   //    cout << hugeInt1 << " != " << hugeInt1 << endl
   //         << endl;
   // if (notEqual(hugeInt1, hugeInt1, hugeInt1Size, hugeInt1Size))
   // {
   //    char symbol[] = "!=";
   //    print(hugeInt1, hugeInt1, hugeInt1Size, hugeInt1Size, symbol);
   // }

   // if (hugeInt1 != hugeInt2)
   //    cout << hugeInt1 << " != " << hugeInt2 << endl
   //         << endl;
   // if (notEqual(hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size))
   // {
   //    char symbol[] = "!=";
   //    print(hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size, symbol);
   // }

   // if (hugeInt2 != hugeInt1)
   //    cout << hugeInt2 << " != " << hugeInt1 << endl
   //         << endl;
   // if (notEqual(hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size))
   // {
   //    char symbol[] = "!=";
   //    print(hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size, symbol);
   // }

   // if (hugeInt1 < hugeInt1)
   //    cout << hugeInt1 << " < " << hugeInt1 << endl
   //         << endl;
   // if (less(hugeInt1, hugeInt1, hugeInt1Size, hugeInt1Size))
   // {
   //    char symbol[] = "<";
   //    print(hugeInt1, hugeInt1, hugeInt1Size, hugeInt1Size, symbol);
   // }

   // if ( hugeInt1 < hugeInt2 ) cout << hugeInt1 << " < " << hugeInt2 << endl << endl;
   // if ( less( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size ) ){
   //    char symbol[] = "<";
   //    print( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size, symbol );
   // }

   // if ( hugeInt2 < hugeInt1 ) cout << hugeInt2 << " < " << hugeInt1 << endl << endl;
   // if ( less( hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size ) ){
   //     char symbol[] = "<";
   //    print( hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size, symbol);
   // }

   // if ( hugeInt1 > hugeInt1 ) cout << hugeInt1 << " > " << hugeInt1 << endl << endl;
   // if ( greater( hugeInt1, hugeInt1, hugeInt1Size, hugeInt1Size ) ){
   //      char symbol[] = ">";
   //    print( hugeInt1, hugeInt1, hugeInt1Size, hugeInt1Size, symbol );
   // }

   // if ( hugeInt1 > hugeInt2 ) cout << hugeInt1 << " > " << hugeInt2 << endl << endl;
   // if ( greater( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size ) ){
   //       char symbol[] = ">";
   //     print( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size, symbol );
   // };

   // // // if ( hugeInt2 > hugeInt1 ) cout << hugeInt2 << " > " << hugeInt1 << endl << endl;
   // if ( greater( hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size ) ){
   //     char symbol[] = ">";
   //     print( hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size, symbol );
   // };

   // // if ( hugeInt1 <= hugeInt1 ) cout << hugeInt1 << " <= " << hugeInt1 << endl << endl;
   // if ( lessEqual( hugeInt1, hugeInt1, hugeInt1Size, hugeInt1Size ) ){
   //     char symbol[] = "<=";
   //     print( hugeInt1, hugeInt1, hugeInt1Size, hugeInt1Size, symbol );
   // }

   // // if ( hugeInt1 <= hugeInt2 ) cout << hugeInt1 << " <= " << hugeInt2 << endl << endl;
   // if ( lessEqual( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size ) ){
   //     char symbol[] = "<=";
   //    print( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size, symbol );
   // };

   // // if ( hugeInt2 <= hugeInt1 ) cout << hugeInt2 << " <= " << hugeInt1 << endl << endl;
   // if ( lessEqual( hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size ) ){
   //     char symbol[] = "<=";
   //    print( hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size, symbol );
   // }

   // if ( hugeInt1 >= hugeInt1 ) cout << hugeInt1 << " >= " << hugeInt1 << endl << endl;
   // if (greaterEqual(hugeInt1, hugeInt1, hugeInt1Size, hugeInt1Size))
   // {
   //    char symbol[] = ">=";
   //    print(hugeInt1, hugeInt1, hugeInt1Size, hugeInt1Size, symbol);
   // }

   // // if ( hugeInt1 >= hugeInt2 ) cout << hugeInt1 << " >= " << hugeInt2 << endl << endl;
   // if (greaterEqual(hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size))
   // {
   //    char symbol[] = ">=";
   //    print(hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size, symbol);
   // };

   // // if ( hugeInt2 >= hugeInt1 ) cout << hugeInt2 << " >= " << hugeInt1 << endl << endl;
   // if ( greaterEqual( hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size ) ){
   //     char symbol[] = ">=";
   //      print( hugeInt2, hugeInt1, hugeInt2Size, hugeInt1Size, symbol );
   // }

   int hugeInt3[arraySize] = {0};
   int hugeInt3Size;

   // hugeInt3 = hugeInt1 * hugeInt2;
   multiplication(hugeInt1, hugeInt2, hugeInt3, hugeInt1Size, hugeInt2Size, hugeInt3Size);
   // cout << hugeInt1 << " * " << hugeInt2 << " == " << hugeInt3 << endl << endl;
   // printOperation(hugeInt1, hugeInt2, hugeInt3, '*', hugeInt1Size, hugeInt2Size, hugeInt3Size);

   // hugeInt3 = hugeInt1 + hugeInt2
   addition(hugeInt1, hugeInt2, hugeInt3, hugeInt1Size, hugeInt2Size, hugeInt3Size);
   // cout << hugeInt1 << " + " << hugeInt2 << " == " << hugeInt3 << endl
   //      << endl;
   // printOperation( hugeInt1, hugeInt2, hugeInt3, '+', hugeInt1Size, hugeInt2Size, hugeInt3Size );

   int hugeInt4[arraySize] = {0};
   int hugeInt4Size;

   int huge1[13] = {8,5,1,7,7,5,1,5,0,1,0,1,8};
   int huge2[13] = {6,4,4,9,6,8,8,6,2,9,4,8,3};
   int n = 13;
   int m = 13;
   int k = 13;
   //8101051577158
   //3849268869446

   subtraction(huge1, huge2, hugeInt4, n, m, k);
   printOperation(huge1, huge2, hugeInt4, '-', n, m, k);

   // hugeInt4 = hugeInt3 - hugeInt1
   subtraction(hugeInt3, hugeInt1, hugeInt4, hugeInt3Size, hugeInt1Size, hugeInt4Size);

   // cout << hugeInt3 << " - " << hugeInt2 << " == " << hugeInt4 << endl << endl;
   printOperation(hugeInt3, hugeInt1, hugeInt4, '-', hugeInt3Size, hugeInt1Size, hugeInt4Size);

   // // if( hugeInt2 == hugeInt4 ) cout << hugeInt2 << " == " << hugeInt4 << endl << endl;
   // if( equal( hugeInt2, hugeInt4, hugeInt2Size, hugeInt4Size ) )
   //    print( hugeInt2, hugeInt4, hugeInt2Size, hugeInt4Size, "==" );
   // else
   //    cout << "Error!\n\n";

   system("pause");
} // end function main

// Rendomly generates a positive huge integer
void random(int hugeInt[], int hugeIntSize)
{
   for (int i = 0; i < hugeIntSize - 1; i++)
      hugeInt[i] = rand() % 10;
   hugeInt[hugeIntSize - 1] = 1 + rand() % 9;
}

// cout << hugeInt1 << op << hugeInt2 << " == " << hugeInt3 << endl << endl;
void printOperation(int hugeInt1[], int hugeInt2[], int hugeInt3[], char op,
                    int hugeInt1Size, int hugeInt2Size, int hugeInt3Size)
{
   for (int i = hugeInt1Size - 1; i >= 0; i--)
      cout << hugeInt1[i];

   cout << " " << op << " ";
   for (int i = hugeInt2Size - 1; i >= 0; i--)
      cout << hugeInt2[i];

   cout << " == ";
   for (int i = hugeInt3Size - 1; i >= 0; i--)
      cout << hugeInt3[i];
   cout << endl
        << endl;
}

// cout << hugeInt1 << string << hugeInt2 << endl << endl;
void print(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size, char string[])
{
   for (int i = hugeInt1Size - 1; i >= 0; i--)
      cout << hugeInt1[i];

   cout << " " << string << " ";

   for (int i = hugeInt2Size - 1; i >= 0; i--)
      cout << hugeInt2[i];
   cout << endl
        << endl;
}