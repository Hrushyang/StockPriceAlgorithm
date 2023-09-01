// C++ implementation of the approach
#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits>
#include "algorithms.h"

using namespace std;

// Returns the maximum element given two int type numbers.
int problem2::maximum(int n1, int n2)
{
    if(n1>n2)
    {
        return n1;
    }
    return n2;
}

// Backtracking the DP table
void problem2::findBuyAndSellDays( vector<vector<int> >& memoization)
{
    outputKtransactions.clear();
    // start from the bottom right corner of the DP table i.e., t = totalTransactionsAllowed && day = totalNumberOfDays
    int t = noOfTransactions, day = noOfDays-1;
    while(true)
    {
        // If any of transactions and days ==0 => we have reached the start of the table i.e., we already got the output.
        if(t==0 || day==0)
        {
            // Get out of the while loop
            break;
        }
        // Current = previous days DP value => no transaction happened in that interval.
        if(memoization[t][day] == memoization[t][day-1])
        {
            day = day-1;
        }
        // Current != previous days DP value => A transaction has happened in that interval.
        else
        {
            bool flag = false; 

            // Need to find the transaction across stock Ids -> for loop on stocks
            for (int stockId = 0; stockId < noOfStocks; stockId++)
            {
                // As the stock is selled on this day, calculate the difference with each stock to find where is this difference 
                // reproduced in the previous transaction across all stocks till currentday-1
                int maxDiff = memoization[t][day] - priceList[stockId][day];
                for(int j = day-1; j>=0; j--)
                {
                    // If we found a match
                    if(memoization[t-1][j] - priceList[stockId][j] == maxDiff)
                    {
                        // Update the transaction to the final output transactions list.
                        outputKtransactions.push_back({stockId+1, j+1, day+1});
                        // Decrease the transaction variable by 1, as one transaction is found.
                        t = t-1;
                        // Update the day to the day@which the transaction was bought, because overlapping is not allowed in our problem statement.
                        day=j;
                        // Update the flag to true.
                        flag = true;
                        break;
                    }
                }
                // Break the stocks loop,as we found our match and there is no need to check for all the others.
                if(flag)
                    break;
            }
        }
    }
}

// Recurrsion logic for O(m*n*k) time complexity using memoization.
int problem2::mCompute(int n, int k, vector<vector<int> >& maxDiff, vector<vector<int> >& memoization)
{
    // Base case if n==0, return 0 i.e., no profit on transaction on day 0
    // Base case if k==0, return 0 i.e., no profit if #of transactions=0
    if(n==0 || k==0)
    {
        return memoization[k][n] = 0;
    }
    // If the value in memoization table is not filled
    if(memoization[k][n] == -1)
    {
        // Consider stock is on hold on current day i.e., not selling => maxProfit will be the value at previous day.
        int maxVal = mCompute(n-1, k, maxDiff, memoization);
        // If its sold on the current day => Calculate the profit considering the (k-1)th transaction profit + profit if its sold on that day.
        for(int stockId = 0; stockId < noOfStocks; stockId++)
        {
            // Store the max differece in a 2D vector, so as to reduce the time complexity to m*n*k from n*n^2*k
            maxDiff[k][stockId] = maximum(maxDiff[k][stockId], mCompute(n, k-1, maxDiff, memoization) - priceList[stockId][n]);
            // update max value for each stock with the updated maxDiff.
            maxVal = maximum(maxVal, priceList[stockId][n] + maxDiff[k][stockId]);
        }
        // Store the maximum value obtained in the DP table.
        memoization[k][n] = maxVal;
        return maxVal;
    }
    // If value is already filled => just return the value.
    return memoization[k][n];
}

// Algorithm 6A, top down recurrsion with O(m*n*k)
int problem2::task6A()
{
    // Declaring the DP table(with k+1 x n) and the maxDiff table(k+1 x m).
    vector<vector<int> > memoization(noOfTransactions + 1, vector<int> (noOfDays,-1));
    vector<vector<int> > maxDiff(noOfTransactions + 1, vector<int> (noOfStocks,0));
    // Intitial maxDiff will be the negative of starting day price for each stock.
    for (int j=0; j< noOfTransactions+1;j++)
        for(int i=0; i < noOfStocks; i++)
            maxDiff[j][i] = -priceList[i][0];
    
    memoization[0][0] = 0;
    // Recurrsion Algorithm that calls the bottom right corner i.e., k,n-1 the value of the DP table, which in turn fills the rest of the values in recurrsion defined in the function.
    int maxProfit = mCompute(noOfDays-1, noOfTransactions, maxDiff, memoization);
    
    // Backtracking the DP table to get atmost K transactions.
    findBuyAndSellDays(memoization);

    return memoization[noOfTransactions][noOfDays - 1];
}
// Algorith-5 Dynamic Programming Using Bottom-up with O(m*n^2*k)
int problem2::task5()
{
    // Declaring the memoization table with space of k+1 X n
    vector<vector<int> > memoization(noOfTransactions + 1, vector<int> (noOfDays, 0));
    
    // For each transaction & for each day
    for (int t = 1; t < noOfTransactions+1; t++)
    {
        for(int day = 1; day < noOfDays; day++)
        {
            // STEP1: If stock is not selled on current day => cyrrent profit will be the previous days profit.
            int maxVal = memoization[t][day-1];

            // STEP2: If transaction is going to be happend on this day => rest k-1 should happen between [0, day-1].
            // Calculate the profit for day in the above interval considering it's (k-1)th transaction profit + current days transaction ; for each stock      
            for(int stockId = 0; stockId < noOfStocks; stockId++)
            {
                for(int j = day-1; j>=0; j--)
                {
                    maxVal = maximum(maxVal, memoization[t-1][j]+priceList[stockId][day] - priceList[stockId][j]);
                }
            }
            // Store the maximun of STEP1 & STEP2
            memoization[t][day] = maxVal;
        }
    }

    // Backtracking the DP table to get atmost K transactions.
    findBuyAndSellDays(memoization);
    return memoization[noOfTransactions][noOfDays-1];
}

// Algorith-6B Dynamic Programming Using Bottom-up with O(m*n*k) Time Complexity.
int problem2::task6B()
{
    // Declaring the memoization table with space of k+1 X n
    vector<vector<int> > memoization(noOfTransactions + 1, vector<int> (noOfDays, 0));

    for (int t = 1; t < noOfTransactions+1; t++)
    {
        // Creating a maxDiff array which will be populated for each stock for n days & need to be tracked for each transaction. So, its getting redeclared.
        vector<int> maxDiff(noOfStocks,0);
        for(int i=0; i < noOfStocks; i++)
            maxDiff[i] = -priceList[i][0];
        
        for(int day = 1; day < noOfDays; day++)
        {
            // STEP1: If stock is not selled on current day => [Current maxProfit] will be the previous day's profit.
            int maxVal = memoization[t][day-1];
            // STEP2: If transaction is going to be happend on this day => rest k-1 should happen between [0, day-1].
            // Calculate the profit for day in the above interval considering it's (k-1)th transaction profit + current days transaction ; for each stock

            // Here we are storing the repeated calculations done in TASK5. Here we are storing the maxDiff value till current day for each stock.
            // As the no of days progress, storing this maximum difference across each stock will reduce the time complexity.
            for(int stockId=0; stockId < noOfStocks; stockId++)
            {
                maxVal = maximum(maxVal, priceList[stockId][day]+maxDiff[stockId]);
                maxDiff[stockId] = maximum(maxDiff[stockId], memoization[t-1][day] - priceList[stockId][day]);
           }

           // Store max(STEP1, STEP2).
            memoization[t][day] = maxVal;
        }
    }

    // Backtracking the DP table to get atmost K transactions.
    findBuyAndSellDays(memoization);
    
    return memoization[noOfTransactions][noOfDays-1];
}

int problem2::bruteForceRecurrsion(int n, int k, vector<vector<int> >& memoization)
{
    // Base case if n==0, return 0 i.e., no profit on transaction on day 0
    // Base case if k==0, return 0 i.e., no profit if #of transactions=0
    if(n==0 || k==0)
    {
        return memoization[k][n] = 0;
    }
    // Consider stock is on hold on current day i.e., not selling => maxProfit will be the value at previous day.
    int maxVal = bruteForceRecurrsion(n-1, k, memoization);
    // STEP2: If transaction is going to be happend on this day => rest k-1 should happen between [0, day-1].
    // Calculate the profit for day in the above interval considering it's (k-1)th transaction profit + current days transaction ; for each stock      
    for(int stockId = 0; stockId < noOfStocks; stockId++)
    {
        for(int j = n-1; j>=0; j--)
        {
            maxVal = maximum(maxVal, bruteForceRecurrsion(j, k-1, memoization) + priceList[stockId][n] - priceList[stockId][j]);
        }
    }
    // Store the maximum value obtained in the DP table.
    memoization[k][n] = maxVal;
    return memoization[k][n];
}

int problem2::task4()
{
    // Declaring the memoization table with space of k+1 X n
    vector<vector<int> > memoization(noOfTransactions + 1, vector<int> (noOfDays, 0));
    
    int maxProfit = bruteForceRecurrsion(noOfDays-1, noOfTransactions, memoization);

    // Backtracking the DP table to get atmost K transactions.
    findBuyAndSellDays(memoization);
    return maxProfit;
}