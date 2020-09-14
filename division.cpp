// Perform huge integer division.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Rendomly generates a huge integer
void random(int hugeInteger[], int size);

bool equal(int hugeInteger1[], int hugeInteger1Size);

// quotient = dividend / divisor; remainder = dividend % divisor
void division(int dividend[], int divisor[], int quotient[], int remainder[],
              int dividendSize, int divisorSize, int &quotientSize, int &remainderSize);

// Returns true if and only if hugeInt1 < hugeInt2
bool less(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size);
void divideBy10(int hugeInt[], int &hugeIntSize); // hugeInt /= 10, i.e., shift right by one position

// minuend -= subtrahend
void subtraction(int minuend[], int subtrahend[], int &minuendSize, int subtrahendSize);

// cout << hugeInt1 << op << hugeInt2 << " == " << hugeInt3 << endl << endl;
void printOperation(int hugeInt1[], int hugeInt2[], int hugeInt3[], char op,
                    int hugeInt1Size, int hugeInt2Size, int hugeInt3Size);

const int arraySize = 40;

// function main begins program execution
int main()
{
    unsigned int seed;
    cout << "Enter seed: ";
    cin >> seed;
    cout << endl;
    srand(seed);

    int dividend[arraySize] = {};
    int dividendSize = 30 + rand() % 10;
    random(dividend, dividendSize);

    int divisor[arraySize] = {};
    int divisorSize = (dividendSize / 3) + rand() % (dividendSize / 3);
    random(divisor, divisorSize);

    int quotient[arraySize] = {};
    int quotientSize;

    int remainder[arraySize] = {};
    int remainderSize;

    int huge1[3] = {0, 2, 1};
    int hugeSize1 = 3;
    int huge2[2] = {0, 3};
    int hugeSize2 = 2;

    //  division(huge1, huge2, quotient, remainder, hugeSize1, hugeSize2, quotientSize, remainderSize);
    //  printOperation(huge1, huge2, quotient, '/', hugeSize1, hugeSize2, quotientSize);
    //  printOperation(huge1, huge2, remainder, '%', hugeSize1, hugeSize2, remainderSize);

    // quotient = dividend / divisor;  remainder = dividend % divisor;
    division(dividend, divisor, quotient, remainder, dividendSize, divisorSize, quotientSize, remainderSize);

    // cout << dividend << " / " << divisor << " == " << quotient << endl << endl;
    printOperation(dividend, divisor, quotient, '/', dividendSize, divisorSize, quotientSize);

    // cout << dividend << " % " << divisor << " == " << remainder << endl << endl;
    printOperation(dividend, divisor, remainder, '%', dividendSize, divisorSize, remainderSize);

    system("pause");
} // end function main

void random(int hugeInteger[], int size)
{
    for (int i = 0; i <= size - 2; i++)
        hugeInteger[i] = rand() % 10;
    hugeInteger[size - 1] = 1 + rand() % 9;
}

void divideBy10(int hugeInt[], int &hugeIntSize)
{
    for (int i = 1; i < hugeIntSize; i++)
        hugeInt[i - 1] = hugeInt[i];

    hugeIntSize--;
    hugeInt[hugeIntSize] = 0;
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
void subtraction(int minuend[], int subtrahend[], int &minuendSize, int subtrahendSize)
{
    int temp[80] = {};
    int tempSize = subtrahendSize;

    for (int i = 0; i <= 79; i++)
        temp[i] = subtrahend[i];

    //	cout <<"E"<<endl;
    int size;
    if (minuendSize >= tempSize)
        size = minuendSize;
    if (tempSize > minuendSize)
        size = subtrahendSize;

    for (int i = 0; i <= size - 1; i++)
    {
        if (minuend[i] >= temp[i])
            minuend[i] = minuend[i] - temp[i];

        else
        {
            minuend[i] = (minuend[i] + 10) - temp[i];
            temp[i + 1]++;
        }
    }

    //新增
    for (int i = minuendSize - 1; i >= 0; i--)
    {
        if (minuend[i] != 0)
        {
            minuendSize = i + 1;
            break;
        }
    }
}

void division(int dividend[], int divisor[], int quotient[], int remainder[],
              int dividendSize, int divisorSize, int &quotientSize, int &remainderSize)
{
    int buffer[80] = {0};
    int shift[80] = {0};
    //	cout <<"check 1"<<endl;

    //----------------------------------------------------------------------------------------確認被除數大於除數
    if (less(dividend, divisor, dividendSize, divisorSize) == 1)
        cout << "error";
    //	cout <<"check 2"<<endl;

    int n;
    n = dividendSize - divisorSize;
    //	cout <<"check 3"<<endl;
    //----------------------------------------------------------------------------------------除數最大倍數 ex: 被除數-100 除數-3 -> 100
    for (int i = 0; i < n; i++)
        shift[i] = 0;
    shift[n] = 1;

    //	cout <<"check 4"<<endl;
    //修改
    for (int i = 0; i <= divisorSize; i++)
    {
        for (int j = 0; j <= n; j++)
            buffer[i + j] = (divisor[i] * shift[j]) + buffer[i + j];
    }
    std::cout << "buffer  ---  1" << std::endl;
    for (int i = 0; i <= 30; i++)
    {
        std::cout << buffer[i];
    }
    std::cout << "" << std::endl;

    //	cout <<"check 5"<<endl;

    for (int i = 0; i <= 79; i++)
    {
        buffer[i + 1] += buffer[i] / 10;
        buffer[i] = buffer[i] % 10;
    }
    std::cout << "buffer  ---  2" << std::endl;
    for (int i = 0; i <= 30; i++)
    {
        std::cout << buffer[i];
    }
    std::cout << "" << std::endl;

    int bufferSize;
    for (int i = 79; i >= 0; i--)
    {
        if (buffer[i] != 0)
        {
            bufferSize = i + 1;
            break;
        }
    }
    std::cout << "buffer  ---  3" << std::endl;
    for (int i = 0; i <= 30; i++)
    {
        std::cout << buffer[i];
    }
    std::cout << "" << std::endl;

    quotientSize = dividendSize - divisorSize;


    //	cout <<"check 6"<<endl;

    //	for(int i =0; i <=79; i++)
    //		buffer[i] = pass[i];
    //----------------------------------------------------------------------------------------除數補0到跟被除數一樣位數，如果被除數小於除數商數直接+1，反之則除於10去做除法運算
    //修改
    if (less(dividend, buffer, dividendSize, bufferSize))
        divideBy10(buffer, bufferSize);
    else
        quotientSize++;

    //	cout <<"check 7"<<endl;
    //----------------------------------------------------------------------------------------將被除數複製給餘數
    for (int i = 0; i <= dividendSize; i++)
        remainder[i] = dividend[i];
    remainderSize = dividendSize;

    //	cout <<"check 8"<<endl;

    //	cout << "bufferSize = " << bufferSize << endl;
    //	cout << "remainderSize = " << remainderSize << endl;
    //	cout << "quotientSize = " << quotientSize << endl;

    //	printOperation( buffer, remainder, quotient, 'z', bufferSize, remainderSize, quotientSize );

    //----------------------------------------------------------------------------------------進行除數相減過程

    //修改
    for (int k = quotientSize - 1; k >= 0; k--)
    {
        //		cout <<"check ?"<<endl;
        while (less(buffer, remainder, bufferSize, remainderSize))
        {
            //			char dummy; cout << "press any key to continue " << endl; cin >> dummy;
            //			printOperation( buffer, remainder, quotient, 'y', bufferSize, remainderSize, quotientSize );

            subtraction(remainder, buffer, remainderSize, bufferSize);
            //			cout <<"check 9"<<endl;
            quotient[k]++;
        }
        divideBy10(buffer, bufferSize);
    }
}
