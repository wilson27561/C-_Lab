#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

typedef list<int> LISTINT;
LISTINT ::iterator it;

int main()
{
    // Q1 :
    // std::cout << "Enter the number of integers to be proccessed followed by the integers" << std::endl;
    // int n = 7;
    // int array[n];
    // int largest = 0;
    // int secondLargest = 0;
    // int temp = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> array[i];
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n - 1; j++)
    //     {
    //         if (array[j] > array[j + 1])
    //         {
    //             temp = array[j + 1];
    //             array[j + 1] = array[j];
    //             array[j] = temp;
    //         };
    //     };
    // };

    // std::cout << "Largest is " <<  array[n-1] << std::endl;
    // std::cout << "Second largest is " <<  array[n-2] << std::endl;

    // system("pause");

    //Q2 :
    //  std::cout << "Enter a positive integer of at most 8: ";
    //  int n;
    //  cin >> n;

    //  std::cout << "Enter a " << n <<"-digit positive integer ";
    //  int oriNum;
    //  cin >> oriNum;

    //  int num;
    //  int rem;
    //  int reverse = 0;
    //  num = oriNum;
    //  while(num!=0){
    //     rem = num % 10;
    //     reverse = reverse*10 + rem;
    //     num = num /10;
    //  }
    //  if(oriNum == reverse){
    //   std::cout << oriNum << "is a palindrome" << std::endl;
    //  }else{
    //  std::cout << oriNum << " is not a palindrome" << std::endl;
    //  }
    // system("pause");

    //Q3 :

    //Q4 :
    // std::cout << "Enter a positive integer : ";
    // int num;
    // cin >> num;
    // std::cout << "Perfect numbers between 1 and " << num << endl;
    // int total;

    // for (int i = 3; i <= num; i++)
    // {
    //     LISTINT primeNumList;
    //     int total = 0;
    //     for (int j = 1; j < i; j++)
    //     {
    //         if (i % j == 0)
    //         {
    //             primeNumList.push_back(j);
    //             total += j;
    //         }
    //     };
    //     if (total == i)
    //     {
    //         std::cout << i << " = ";
    //         for (int var : primeNumList)
    //         {
    //             std::cout << var;
    //             if (var != primeNumList.back())
    //             {
    //                 std::cout << " + ";
    //             }else{
    //                 std::cout << "" << std::endl;
    //             }
    //         }
    //     }
    // }
    // system("pause");

    //Q5 :

    for (int j = 1; j < 10; j++)
    {
        for (int i = 2; i <= 5; i++)
        {
            std::cout << i << " * " << j << " = " << i * j << "\t";
        }
        std::cout << "" << std::endl;
    }
    std::cout << "" << std::endl;
    for (int j = 1; j < 10; j++)
    {
        for (int i = 6; i <= 9; i++)
        {
            std::cout << i << " * " << j << " = " << i * j << "\t";
        }
        std::cout << "" << std::endl;
    }


}