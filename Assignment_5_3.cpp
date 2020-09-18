// Prints out the first four perfect numbers.
#include <iostream>
using namespace ::std;

#include <cmath>
#include <ctime>

// Rendomly generates a huge integer
void random(int hugeInteger[], int size);

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
//hugeInt1 < hugeInt2 return turevv
bool less(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
   //	cout <<"A"<<endl;
   if (hugeInt1Size > hugeInt2Size)
      return 0;
   //	cout <<"B"<<endl;
   if (hugeInt1Size < hugeInt2Size)
      return 1;
   //	cout <<"C"<<endl;
   if (hugeInt1Size == hugeInt2Size)
   {
      for (int i = hugeInt1Size - 1; i >= 0; i--)
      {
         if (hugeInt1[i] > hugeInt2[i])
            return 0;
         if (hugeInt1[i] < hugeInt2[i])
            return 1;
      }
      return 0;
   }

   //	cout <<"D"<<endl;
}

// Returns true if and only if hugeInt1 > hugeInt2
bool greater(int hugeInt1[], int hugeInt2[], int size1, int size2)
{
   bool isGreater = false;
   if (size1 > size2)
   {
      return true;
   };
   if (size1 < size2)
   {
      return false;
   };
   if (size1 == size2)
   {
      int start = size1 - 1;
      for (int i = start; i >= 0; i--)
      {
         if (hugeInt1[i] > hugeInt2[i])
         {
            isGreater = true;
         }
      };
   };
   return isGreater;
};

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
                 int minuendSize, int subtrahendSize, int &differenceSize)
{
   for (int i = 0; i < minuendSize; i++)
   {
      if (i < subtrahendSize)
      {
         if (subtrahend[i] > (minuend[i] + difference[i]))
         {
            difference[i] = (minuend[i] + 10) - subtrahend[i] + difference[i];
            difference[i + 1]--;
         }
         else
         {
            difference[i] = minuend[i] - subtrahend[i] + difference[i];
         }
      }
      else
      {
         if ((minuend[i] + difference[i]) < 0)
         {
            difference[i] = minuend[i] + 10 + difference[i];
            difference[i + 1]--;
         }
         else
         {
            difference[i] = minuend[i] + difference[i];
         }
      }
   }

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

void divideBy10(int hugeInt[], int &hugeIntSize)
{
   for (int i = 1; i < hugeIntSize; i++)
   {
      hugeInt[i - 1] = hugeInt[i];
   }
   hugeIntSize--;
   hugeInt[hugeIntSize] = 0;
}
void sub(int minuend[], int subtrahend[], int &minuendSize, int subtrahendSize)
{
   int temp[80] = {};
   int tempSize = subtrahendSize;

   for (int i = 0; i < 79; i++)
   {
      temp[i] = subtrahend[i];
   }

   //判斷直式減法需要運算幾個位數
   int size;
   if (minuendSize >= tempSize)
   {
      size = minuendSize;
   }
   if (tempSize > minuendSize)
   {
      size = subtrahendSize;
   }

   //開始運算
   for (int i = 0; i <= size - 1; i++)
   {
      if (minuend[i] >= temp[i])
      {
         minuend[i] = minuend[i] - temp[i];
      }
      else
      {
         minuend[i] = (minuend[i] + 10) - temp[i];
         temp[i + 1]++;
      }
   }
   //答案有幾位數
   for (int i = minuendSize - 1; i >= 0; i--)
   {
      if (minuend[i] != 0)
      {
         minuendSize = i + 1;
         break;
      }
   }
}


bool les(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
   //	cout <<"A"<<endl;
   if (hugeInt1Size > hugeInt2Size)
      return 0;
   //	cout <<"B"<<endl;
   if (hugeInt1Size < hugeInt2Size)
      return 1;
   //	cout <<"C"<<endl;
   if (hugeInt1Size == hugeInt2Size)
   {
      for (int i = hugeInt1Size - 1; i >= 0; i--)
      {
         if (hugeInt1[i] > hugeInt2[i])
            return 0;
         if (hugeInt1[i] < hugeInt2[i])
            return 1;
      }
      return 0;
   }
   return 1;
   //	cout <<"D"<<endl;
}

// quotient = dividend / divisor; remainder = dividend % divisor
void division(int dividend[], int divisor[], int quotient[], int remainder[],
              int dividendSize, int divisorSize, int &quotientSize, int &remainderSize)
{
   int buffer[80] = {0};
   int shift[80] = {0};

   if (les(dividend, divisor, dividendSize, divisorSize) == 1)
   {
      cout << "error";
   }

   // shift 除數需除shift才能和被除數位數相等
   int n;
   n = dividendSize - divisorSize;

   for (int i = 0; i < n; i++)
   {
      shift[i] = 0;
   }
   shift[n] = 1;

   // buffer[i] 除數補0到跟被除數一樣位數
    for (int i = 0; i <= divisorSize; i++)
    {
        for (int j = 0; j <= n; j++)
            buffer[i + j] = (divisor[i] * shift[j]) + buffer[i + j];
    }
   
   for (int i = 0; i <= 79; i++)
   {
      buffer[i + 1] += buffer[i] / 10;
      buffer[i] = buffer[i] % 10;
   }

   int bufferSize;
   for (int i = 79; i >= 0; i--)
   {
      if (buffer[i] != 0)
      {
         bufferSize = i + 1;
         break;
      }
   }
   //商數位數結果會等於被除數 - 除數
   quotientSize = dividendSize - divisorSize;

   //除數補0到跟被除數一樣位數，如果被除數小於除數商數直接+1，反之則除於10去做除法運算
   if (les(dividend, buffer, dividendSize, bufferSize))
      divideBy10(buffer, bufferSize);
   else
      quotientSize++;

   //將被除數複製給餘數
   for (int i = 0; i <= dividendSize; i++)
      remainder[i] = dividend[i];
   remainderSize = dividendSize;
  
    for (int k = quotientSize - 1; k >= 0; k--)
    {
        //		cout <<"check ?"<<endl;
        while (les(buffer, remainder, bufferSize, remainderSize))
        {
            //			char dummy; cout << "press any key to continue " << endl; cin >> dummy;
            //			printOperation( buffer, remainder, quotient, 'y', bufferSize, remainderSize, quotientSize );

            sub(remainder, buffer, remainderSize, bufferSize);
            //			cout <<"check 9"<<endl;
            quotient[k]++;
        }
        divideBy10(buffer, bufferSize);
    }

}

// cout << hugeInt1 << op << hugeInt2 << " == " << hugeInt3 << endl << endl;
void printOperation(int hugeInt1[], int hugeInt2[], int hugeInt3[], char op,
                    int hugeInt1Size, int hugeInt2Size, int hugeInt3Size);

// cout << hugeInt1 << string << hugeInt2 << endl << endl;
void print(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size);

const int arraySize = 40;

// function main begins program execution
int main()
{
   srand(static_cast<int>(time(0)));
   unsigned int seed;
   cout << "Enter seed: ";
   cin >> seed;
   cout << endl;
   srand(seed);

   int hugeInt1[arraySize] = {0};
   int hugeInt1Size = 30 + rand() % 10;
   random(hugeInt1, hugeInt1Size);

   int hugeInt2[arraySize] = {0};
   int hugeInt2Size = (hugeInt1Size / 3) + rand() % (hugeInt1Size / 3);
   random(hugeInt2, hugeInt2Size);

   int hugeInt3[arraySize] = {0};
   int hugeInt3Size;
   int hugeInt4[arraySize] = {0};
   int hugeInt4Size;

   // hugeInt3 = hugeInt1 / hugeInt2;  hugeInt4 = hugeInt1 % hugeInt2;
   division(hugeInt1, hugeInt2, hugeInt3, hugeInt4, hugeInt1Size, hugeInt2Size, hugeInt3Size, hugeInt4Size);

   // cout << hugeInt1 << " / " << hugeInt2 << " == " << hugeInt3 << endl << endl;
   printOperation(hugeInt1, hugeInt2, hugeInt3, '/', hugeInt1Size, hugeInt2Size, hugeInt3Size);

   // cout << hugeInt1 << " % " << hugeInt2 << " == " << hugeInt4 << endl << endl;
   printOperation(hugeInt1, hugeInt2, hugeInt4, '%', hugeInt1Size, hugeInt2Size, hugeInt4Size);

   // int hugeInt5[arraySize] = {0};
   // int hugeInt5Size;

   // // hugeInt5 = hugeInt2 * hugeInt3;
   // multiplication(hugeInt2, hugeInt3, hugeInt5, hugeInt2Size, hugeInt3Size, hugeInt5Size);

   // // cout << hugeInt2 << " * " << hugeInt3 << " == " << hugeInt5 << endl << endl;
   // printOperation(hugeInt2, hugeInt3, hugeInt5, '*', hugeInt2Size, hugeInt3Size, hugeInt5Size);

   // int hugeInt6[ arraySize ] = {0};
   // int hugeInt6Size;

   // // hugeInt6 = hugeInt5 + hugeInt4
   // addition( hugeInt5, hugeInt4, hugeInt6, hugeInt5Size, hugeInt4Size, hugeInt6Size );

   // // cout << hugeInt5 << " + " << hugeInt4 << " == " << hugeInt6 << endl << endl;
   // printOperation( hugeInt5, hugeInt4, hugeInt6, '+', hugeInt5Size, hugeInt4Size, hugeInt6Size );

   // // if( hugeInt1 == hugeInt6 ) cout << hugeInt1 << " == " << hugeInt6 << endl << endl;
   // print( hugeInt1, hugeInt6, hugeInt1Size, hugeInt6Size );

   // int hugeInt7[ arraySize ] = {0};
   // int hugeInt7Size;

   // // hugeInt7 = hugeInt1 - hugeInt4
   // subtraction( hugeInt1, hugeInt4, hugeInt7, hugeInt1Size, hugeInt4Size, hugeInt7Size );

   // // cout << hugeInt1 << " - " << hugeInt4 << " == " << hugeInt7 << endl << endl;
   // printOperation( hugeInt1, hugeInt4, hugeInt7, '-', hugeInt1Size, hugeInt4Size, hugeInt7Size );

   // // if( hugeInt7 == hugeInt5 ) cout << hugeInt7 << " == " << hugeInt5 << endl << endl;
   // print( hugeInt7, hugeInt5, hugeInt7Size, hugeInt5Size );

   system("pause");
} // end function main

void random(int hugeInt[], int size)
{
   for (int i = 0; i <= size - 2; i++)
      hugeInt[i] = rand() % 10;
   hugeInt[size - 1] = 1 + rand() % 9;
}

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

void print(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
   if (equal(hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size))
   {
      for (int i = hugeInt1Size - 1; i >= 0; i--)
         cout << hugeInt1[i];

      cout << " == ";

      for (int i = hugeInt2Size - 1; i >= 0; i--)
         cout << hugeInt2[i];
      cout << endl
           << endl;
   }
   else
      cout << "Error!\n\n";
}