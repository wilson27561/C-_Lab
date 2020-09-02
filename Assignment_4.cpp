#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <math.h>
using namespace std;

typedef list<int> LISTINT;
LISTINT ::iterator it;

int getDigits(int num){
  int digits = 0;
  while (num !=0)
  {
     num = num / 10;
     ++digits;
  }
   return digits;
}

LISTINT getNumList(int num){
   LISTINT numberList;
   int rem;
     while (num != 0)
   {
       rem = num%10;
       numberList.push_front(rem);
       num = num/10;
   }
    return numberList;
}

int getTotalNum(LISTINT numberList,int digits){
     int total = 0;

    for(int number : numberList)
   {
      int multiplicationNum = pow(number,digits);
      total += multiplicationNum;
   }
  
  std::cout << "/* message */" << std::endl;

   return total;
}

int main()
{
   //Q1: 
   // std::cout << "Enter an integer between and including 10 and 10000000: ";
   // int num;
   // cin >> num;
   // std::cout << "Armstrong numbers between and including 10 and " << num << std::endl;


   // LISTINT amstrongList;

   // for (int i = 10; i <= num; i++)
   // {
   //      LISTINT numberList = getNumList(i);
   //      int digits = getDigits(i);
   //      int total = getTotalNum(numberList,digits);

   //      if(i == total){
   //         std::cout << i << std::endl;
   //      }
   // }
 // system("pause");
}