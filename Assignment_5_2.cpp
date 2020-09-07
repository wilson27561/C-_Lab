// Prints out the first four perfect numbers.
#include <iostream>
using namespace::std;

#include <cmath>
#include <ctime>

// Rendomly generates a huge integer
void random( int hugeInteger[], int size );

// Returns true if and only if hugeInt1 == hugeInt2
bool equal( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size );

// Returns true if and only if hugeInt1 > hugeInt2
bool greater( int hugeInt1[], int hugeInt2[], int size1, int size2 );

// sum = addend + adder
void addition( int addend[], int adder[], int sum[], int addendSize, int adderSize, int &sumSize );

// difference = minuend - subtrahend
void subtraction( int minuend[], int subtrahend[], int difference[],
			         int minuendSize, int subtrahendSize, int &differenceSize );

// product = multiplicand * multiplier
void multiplication( int multiplicand[], int multiplier[], int product[],
			            int multiplicandSize, int multiplierSize, int &productSize );

// quotient = dividend / divisor; remainder = dividend % divisor
void division( int dividend[], int divisor[], int quotient[], int remainder[],
			      int dividendSize, int divisorSize, int &quotientSize, int &remainderSize );

// cout << hugeInt1 << op << hugeInt2 << " == " << hugeInt3 << endl << endl;
void printOperation( int hugeInt1[], int hugeInt2[], int hugeInt3[], char op,
                     int hugeInt1Size, int hugeInt2Size, int hugeInt3Size );

// cout << hugeInt1 << string << hugeInt2 << endl << endl;
void print( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size );

const int arraySize = 40;

// function main begins program execution
int main()
{
//   srand( static_cast< int >( time(0) ) );
   unsigned int seed;
   cout << "Enter seed: ";
   cin >> seed;
   cout << endl;
   srand( seed );

   int hugeInt1[ arraySize ] = {0};
   int hugeInt1Size = 30 + rand() % 10;
   random( hugeInt1, hugeInt1Size );

   int hugeInt2[ arraySize ] = {0};
   int hugeInt2Size = ( hugeInt1Size / 3 ) + rand() % ( hugeInt1Size / 3 );
   random( hugeInt2, hugeInt2Size );

   int hugeInt3[ arraySize ] = {0};
   int hugeInt3Size;
   int hugeInt4[ arraySize ] = {0};
   int hugeInt4Size;

   // hugeInt3 = hugeInt1 / hugeInt2;  hugeInt4 = hugeInt1 % hugeInt2;
   division( hugeInt1, hugeInt2, hugeInt3, hugeInt4, hugeInt1Size, hugeInt2Size, hugeInt3Size, hugeInt4Size );

   // cout << hugeInt1 << " / " << hugeInt2 << " == " << hugeInt3 << endl << endl;
   printOperation( hugeInt1, hugeInt2, hugeInt3, '/', hugeInt1Size, hugeInt2Size, hugeInt3Size );

   // cout << hugeInt1 << " % " << hugeInt2 << " == " << hugeInt4 << endl << endl;
   printOperation( hugeInt1, hugeInt2, hugeInt4, '%', hugeInt1Size, hugeInt2Size, hugeInt4Size );

   int hugeInt5[ arraySize ] = {0};
   int hugeInt5Size;

   // hugeInt5 = hugeInt2 * hugeInt3;
   multiplication( hugeInt2, hugeInt3, hugeInt5, hugeInt2Size, hugeInt3Size, hugeInt5Size );

   // cout << hugeInt2 << " * " << hugeInt3 << " == " << hugeInt5 << endl << endl;
   printOperation( hugeInt2, hugeInt3, hugeInt5, '*', hugeInt2Size, hugeInt3Size, hugeInt5Size );

   int hugeInt6[ arraySize ] = {0};
   int hugeInt6Size;

   // hugeInt6 = hugeInt5 + hugeInt4
   addition( hugeInt5, hugeInt4, hugeInt6, hugeInt5Size, hugeInt4Size, hugeInt6Size );

   // cout << hugeInt5 << " + " << hugeInt4 << " == " << hugeInt6 << endl << endl;
   printOperation( hugeInt5, hugeInt4, hugeInt6, '+', hugeInt5Size, hugeInt4Size, hugeInt6Size );

   // if( hugeInt1 == hugeInt6 ) cout << hugeInt1 << " == " << hugeInt6 << endl << endl;
   print( hugeInt1, hugeInt6, hugeInt1Size, hugeInt6Size );

   int hugeInt7[ arraySize ] = {0};
   int hugeInt7Size;

   // hugeInt7 = hugeInt1 - hugeInt4
   subtraction( hugeInt1, hugeInt4, hugeInt7, hugeInt1Size, hugeInt4Size, hugeInt7Size );

   // cout << hugeInt1 << " - " << hugeInt4 << " == " << hugeInt7 << endl << endl;
   printOperation( hugeInt1, hugeInt4, hugeInt7, '-', hugeInt1Size, hugeInt4Size, hugeInt7Size );

   // if( hugeInt7 == hugeInt5 ) cout << hugeInt7 << " == " << hugeInt5 << endl << endl;
   print( hugeInt7, hugeInt5, hugeInt7Size, hugeInt5Size );

   system( "pause" );
} // end function main

void random( int hugeInt[], int size )
{
   for( int i = 0; i <= size - 2; i++ )
      hugeInt[i] = rand() % 10;
   hugeInt[ size - 1 ] = 1 + rand() % 9;
}

void printOperation( int hugeInt1[], int hugeInt2[], int hugeInt3[], char op,
                     int hugeInt1Size, int hugeInt2Size, int hugeInt3Size )
{
   for( int i = hugeInt1Size - 1; i >= 0; i-- )
      cout << hugeInt1[i];

   cout << " " << op << " ";
   for( int i = hugeInt2Size - 1; i >= 0; i-- )
      cout << hugeInt2[i];

   cout << " == ";
   for( int i = hugeInt3Size - 1; i >= 0; i-- )
      cout << hugeInt3[i];
   cout << endl << endl;
}

void print( int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size )
{
   if( equal( hugeInt1, hugeInt2, hugeInt1Size, hugeInt2Size ) )
   {
      for( int i = hugeInt1Size - 1; i >= 0; i-- )
         cout << hugeInt1[i];

      cout << " == ";

      for( int i = hugeInt2Size - 1; i >= 0; i-- )
         cout << hugeInt2[i];
      cout << endl << endl;
   }
   else
      cout << "Error!\n\n";
}