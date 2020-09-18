// Perform huge integer division.
#include <iostream>
using namespace std;
#include <vector>
#include <ctime>

void random(vector<int> &hugeInt); // Rendomly generates a huge integer

// Returns true if and only if hugeInt1 == hugeInt2
bool equal(vector<int> hugeInt1, vector<int> hugeInt2)
{
   if (hugeInt1.size() != hugeInt2.size())
   {
      return 0;
   }
   else
   {
      for (int i = (hugeInt1.size() - 1); i >= 0; i++)
      {
         if (hugeInt1[i] != hugeInt2[i])
         {
            return 0;
         }
      }
   }

   return 1;
};
// Returns true if and only if hugeInt2 > hugeInt1
bool les(vector<int> hugeInt1, vector<int> hugeInt2)
{
   if (hugeInt2.size() < hugeInt1.size())
   {
      return 0;
   }
   else if (hugeInt2.size() > hugeInt1.size())
   {
      return 1;
   }
   else
   {
      for (int i = (hugeInt1.size() - 1); i >= 0; i++)
      {
         if (hugeInt1[i] == hugeInt2[i])
         {
            continue;
         }
         if (hugeInt1[i] > hugeInt2[i])
         {
            return 0;
         }
         else
         {
            return 1;
         }
      }
   }
   return 1;
}

// Returns true if and only if hugeInt1 > hugeInt2
bool greater(vector<int> hugeInt1, vector<int> hugeInt2)
{
   if (hugeInt1.size() < hugeInt2.size())
   {
      return 0;
   }
   else if (hugeInt1.size() > hugeInt2.size())
   {
      return 1;
   }
   else
   {
      for (int i = (hugeInt1.size() - 1); i >= 0; i++)
      {
         if (hugeInt1[i] == hugeInt2[i])
         {
            continue;
         }
         if (hugeInt2[i] > hugeInt1[i])
         {
            return 0;
         }
         else
         {
            return 1;
         }
      }
   }
   return 1;
};

vector<int> divideBy10(vector<int> divisor)
{
   divisor.erase(divisor.begin());

   return divisor;
};

vector<int> sub(vector<int> minuend, vector<int> subtrahend){
   
   vector<int> temp; 
   
   temp.assign(subtrahend.begin(),subtrahend.end()); 

    std::cout << "minuend : " << std::endl;
      for (int i = 0; i < minuend.size(); i++)
      {
         std::cout << minuend[i];
      }
      std::cout << "" << std::endl;

      std::cout << "subtrahend : " << std::endl;
      for (int i = 0; i < subtrahend.size(); i++)
      {
         std::cout << subtrahend[i];
      }
      std::cout << "" << std::endl;


   int size;
   if(minuend.size() >= temp.size()){
      size = minuend.size();
   }
   if(temp.size() > minuend.size()){
      size = subtrahend.size();
   }


   for (int i = 0; i < minuend.size(); i++)
   {
      if(minuend[i] >= temp[i]){

      }else
      {
        
      }
      



   }
   


   

    return minuend;
}

// Returns the sum of addend and adder, i.e., addend + adder
vector<int> addition(vector<int> addend, vector<int> adder);

// Returns the difference between minuend and subtrahend, i.e., minuend - subtrahend
vector<int> subtraction(vector<int> minuend, vector<int> subtrahend);

// Returns the product of multiplicand and multiplier, i.e., multiplicand * multiplier
vector<int> multiplication(vector<int> multiplicand, vector<int> multiplier);

// Returns the quotient of dividend divided by divisor, i.e., dividend / divisor
vector<int> compQuotient(vector<int> dividend, vector<int> divisor)
{
   vector<int> number1 = {0, 2, 1};
   vector<int> number2 = {0, 2};

   //除數
   vector<int> buffer;
   
   vector<int> number3 = sub(number1,number2);
      std::cout << "sub : " << std::endl;
      for (int i = 0; i < number3.size(); i++)
      {
         std::cout << number3[i];
      }
      std::cout << "" << std::endl;


   //    //被除數
   //    vector<int> remainder;
   //    //商數
   //    vector<int> quotient;
   //    if (les(dividend, divisor))
   //    {
   //       std::cout << "error" << std::endl;
   //    }

   //    std::cout << "dividend : " << std::endl;
   //    for (int i = 0; i < dividend.size(); i++)
   //    {
   //       std::cout << dividend[i];
   //    }
   //    std::cout << "" << std::endl;

   //    // buffer 除數 補0到跟被除數一樣位數
   //    int bufferSize = dividend.size() - divisor.size();
   //    buffer.assign(divisor.begin(), divisor.end());

   //    for (int i = 0; i < bufferSize; i++)
   //    {
   //      buffer.insert(buffer.begin(), 0);
   //    }

   //    //除數補0到跟被除數一樣位數，如果被除數小於除數商數直接+1，反之則除於10去做除法運算
   //   if(les(dividend,buffer)){
   //       buffer = divideBy10(buffer);
   //   }else
   //   {
   //      quotient.push_back(1);
   //   };

   //   //將被除數複製給餘數
   //   remainder.assign(dividend.begin(), dividend.end());

   //   //除法相減

   //  std::cout << "buffer : " << std::endl;
   // for (int i = 0; i < buffer.size(); i++)
   // {
   //    std::cout << buffer[i];
   // }
   // std::cout << "" << std::endl;

   return buffer;
}

// Returns the remainder of dividend divided by divisor, i.e., dividend % divisor
vector<int> compRemainder(vector<int> dividend, vector<int> divisor);

// cout << hugeInt1 << op << hugeInt2 << " == " << hugeInt3 << endl << endl;
void printOperation(vector<int> hugeInt1, vector<int> hugeInt2, vector<int> hugeInt3, char op);

// cout << hugeInt1 << " == " << hugeInt2 << endl << endl;
void print(vector<int> hugeInt1, vector<int> hugeInt2);

int main()
{
   //   srand( static_cast< int >( time(0) ) );

   unsigned int seed;
   cout << "Enter seed: ";
   cin >> seed;
   cout << endl;
   srand(seed);

   int hugeInt1Size = 30 + rand() % 10;
   vector<int> hugeInt1(hugeInt1Size);
   random(hugeInt1);

   int hugeInt2Size = (hugeInt1Size / 3) + rand() % (hugeInt1Size / 3);
   vector<int> hugeInt2(hugeInt2Size);
   random(hugeInt2);

   vector<int> hugeInt3 = compQuotient(hugeInt1, hugeInt2); // hugeInt3 = hugeInt1 / hugeInt2

   // cout << hugeInt1 << " / " << hugeInt2 << " == " << hugeInt3 << endl << endl;
   printOperation(hugeInt1, hugeInt2, hugeInt3, '/');

   // vector< int > hugeInt4 = compRemainder( hugeInt1, hugeInt2 ); // hugeInt4 = hugeInt1 % hugeInt2

   // // cout << hugeInt1 << " % " << hugeInt2 << " == " << hugeInt4 << endl << endl;
   // printOperation( hugeInt1, hugeInt2, hugeInt4, '%' );

   // vector< int > hugeInt5 = multiplication( hugeInt2, hugeInt3 ); // hugeInt5 = hugeInt2 * hugeInt3;

   // // cout << hugeInt2 << " * " << hugeInt3 << " == " << hugeInt5 << endl << endl;
   // printOperation( hugeInt2, hugeInt3, hugeInt5, '*' );

   // vector< int > hugeInt6 = addition( hugeInt5, hugeInt4 ); // hugeInt6 = hugeInt5 + hugeInt4

   // // cout << hugeInt5 << " + " << hugeInt4 << " == " << hugeInt6 << endl << endl;
   // printOperation( hugeInt5, hugeInt4, hugeInt6, '+' );

   // // if( hugeInt1 == hugeInt6 ) cout << hugeInt1 << " == " << hugeInt6 << endl << endl;
   // print( hugeInt1, hugeInt6 );

   // vector< int > hugeInt7 = subtraction( hugeInt1, hugeInt4 ); // hugeInt7 = hugeInt1 - hugeInt4

   // // cout << hugeInt1 << " - " << hugeInt4 << " == " << hugeInt7 << endl << endl;
   // printOperation( hugeInt1, hugeInt4, hugeInt7, '-' );

   // // if( hugeInt7 == hugeInt5 ) cout << hugeInt7 << " == " << hugeInt5 << endl << endl;
   // print( hugeInt7, hugeInt5 );

   // system("pause");
}

void random(vector<int> &hugeInt)
{
   for (unsigned int i = 0; i < hugeInt.size() - 1; i++)
      hugeInt[i] = rand() % 10;
   hugeInt[hugeInt.size() - 1] = 1 + rand() % 9;
}

vector<int> addition(vector<int> addend, vector<int> adder)
{
   int addendSize = addend.size();
   int adderSize = adder.size();
   int sumSize = (addendSize >= adderSize) ? addendSize + 1 : adderSize + 1;

   vector<int> sum(sumSize);

   for (int i = 0; i < addendSize; i++)
      sum[i] = addend[i];

   for (int i = 0; i < adderSize; i++)
      sum[i] += adder[i];

   for (int i = 0; i < sumSize - 1; i++)
      if (sum[i] > 9)
      {
         sum[i] -= 10;
         sum[i + 1]++;
      }

   if (sum[sumSize - 1] == 0)
      sum.resize(sumSize - 1);

   return sum;
}

void printOperation(vector<int> hugeInt1, vector<int> hugeInt2, vector<int> hugeInt3, char op)
{
   for (int i = hugeInt1.size() - 1; i >= 0; i--)
      cout << hugeInt1[i];

   cout << " " << op << " ";
   for (int i = hugeInt2.size() - 1; i >= 0; i--)
      cout << hugeInt2[i];

   cout << " == ";
   for (int i = hugeInt3.size() - 1; i >= 0; i--)
      cout << hugeInt3[i];
   cout << endl
        << endl;
}

void print(vector<int> hugeInt1, vector<int> hugeInt2)
{
   if (equal(hugeInt1, hugeInt2))
   {
      for (int i = hugeInt1.size() - 1; i >= 0; i--)
         cout << hugeInt1[i];

      cout << " == ";

      for (int i = hugeInt2.size() - 1; i >= 0; i--)
         cout << hugeInt2[i];
      cout << endl
           << endl;
   }
   else
      cout << "Error!\n\n";
}