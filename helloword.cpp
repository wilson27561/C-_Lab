#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <stdio.h>

int main()

{

        int x, y, x1[31] = {}, y1[31] = {}, n[31] = {};

        int max = 0, plus = 0, i = 0, j = 0;

        scanf("%d", &x);

        for (i = x - 1; i >= 0; i--)

                scanf("%d", &x1[i]);

        scanf("%d", &y);

        for (j = y - 1; j >= 0; j--)

                scanf("%d", &y1[j]);

        max = (x > y ? x : y);

        for (int i = 0; i < 3; i++)
        {
               std::cout  << x1[i];
        }

        for (int m = 0; m <= max; m++)

        {
                n[m] = x1[m] + y1[m] + plus;

                if (n[m] >= 10)

                {

                        n[m] = n[m] % 10;

                        plus = 1;
                }

                else

                        plus = 0;
        }
        if (n[max] == 0)

        {

                for (i = max - 1; i >= 0; i--)

                        printf("%d", n[i]);
        }

        else

        {

                for (i = max; i >= 0; i--)

                        printf("%d", n[i]);
        }

        return 0;
}