
/*

 Description:
 
 val[] - value of items
 wt[] - weight of items
 W - capacity of knapsack
 
 Taking value (val[]) and weight (wt[]) of items, and placing them in a napsack of a certain
 capacity (W) to get the maximum total value in the knapsack. Find a maximum value subset that
 can be placed into the knapsack such that the total weight of these items is not higher than
 the total weight capacity of the knapsack.
 
 
 Example:
 
 int val[] = {60, 100, 120};
 int wt[] = {10, 20, 30};
 int W = 50;
 
 The subset that will achieve the maximum weight of 50 (without going over this number) and
 achieving the highest value would be two items with the weight of 20 and 30, and the value
 of 100 and 120 respectively. Therefore, the maximum value that can be stored in the knapsack
 is 220 (100 + 120).
 
 The code to solve such a problem is written below.
 
*/


#include <iostream>
using namespace std;

int max(int a, int b) {return (a > b) ? a : b;}

int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n+5][W+5]; // DP table
    
    for (i=0; i <= n; i++)
    {
        for (w=0; w <= W; w++)
        {
            if (i==0 || w==0)
            {
                K[i][w] = 0;
            }
            else if (wt[i-1] <= w)
            {
                K[i][w] = max(val[i-1] + K[i-1][w - wt[i-1]], K[i-1][w]);
            }
            else
            {
                K[i][w] = K[i-1][w];
            }
        }
    }
    return K[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    
    printf("0-1 DP knapsack: \n");
    int value = knapsack(W, wt, val, n);
    printf("maximum value: %d\n", value);
    
    return 0;
}
