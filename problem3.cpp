// C++ implementation of the approach
#include <stdio.h>
#include <iostream>
#include <vector>
#include <limits>
#include "algorithms.h"

using namespace std;

// Returns the maximum element given two int type numbers.
int problem3::maximum(int n1, int n2)
{
    if(n1>n2)
    {
        return n1;
    }
    return n2;
}

// Backtracking the DP table
void problem3::findBuyAndSellDays(vector<int>& memoization)
{
    outputKtransactions.clear();
    // start from the right end of the DP table i.e., day = totalNumberOfDays-1
    int day = noOfDays-1;
    while(true)
    {
        // If Currday == 0 => we have reached the start of the table i.e., we already got the output.
        if(day<=0)
        {
            // Get out of the while loop
            break;
        }
        // Current = previous days DP value => no transaction happened in that interval.
        if(memoization[day] == memoization[day-1])
        {
            day = day-1;
        }
        // Current != previous days DP value => A transaction has happened in that interval.
        else
        {
            // Need to find the transaction across stock Ids -> for loop on stocks
            for (int stockId = 0; stockId < noOfStocks; stockId++)
            {
                // As we are sure that transaction has happened,
                // As the stock is selled on this day, calculate the Combination for which the current profit is obtained based on the cooldown period,
                // M[day] = m[j-c-1] + p[s][day] - p[s][j]
                // CuurProfit = profit w.r.t cooldown + (price on the currDay - price on (profit w.r.t cooldown) day)
                for(int j = day-1; j>=0; j--)
                {
                    // if cooldown period exists with respect to the jth day.
                    if (j-coolDown-1 >= 0)
                    {
                        if(memoization[day] == memoization[j-coolDown-1] + priceList[stockId][day] - priceList[stockId][j])
                        {
                            // Update the transaction to the final output transactions list.
                            outputKtransactions.push_back({stockId+1, j+1, day+1});
                            // Update the day to the day@which the transaction was bought, because overlapping is not allowed in our problem statement.
                            day=j-coolDown-1;
                            break;
                        }
                    }
                    // if not, there is no value i.e., j-c-1 <0 => dp value at that location is considered zero.
                    else
                    {
                        if(memoization[day] == priceList[stockId][day] - priceList[stockId][j])
                        {
                            // Update the transaction to the final output transactions list.
                            outputKtransactions.push_back({stockId+1, j+1, day+1});
                            // Update the day to the day@which the transaction was bought, because overlapping is not allowed in our problem statement.
                            day=j-coolDown-1;
                            break;
                        }
                    }                    
                }
            }
        }
    }
}

// Algorith-8 Dynamic Programming Using Bottom-up with O(m*n^2)
int problem3::task8()
{
    // Declaring the memoization table with space of k+1 X n
    vector<int> memoization(noOfDays, -1);
    memoization[0] = 0;

    for(int day = 1; day < noOfDays; day++)
    {
        // STEP1: If stock is not selled on current day => cyrrent profit will be the previous days profit.
        int maxVal = memoization[day-1];

        // STEP2: If transaction is going to be happend on this day => rest should happen between [0, j-c-1], cause we cannot do transactions in coolDown period.
        // Calculate the profit for day in the above interval considering it's (j-c-1)th transaction profit + current days transaction ; for each stock      
        for(int stockId = 0; stockId < noOfStocks; stockId++)
        {
            for(int j = day-1; j>=0; j--)
            {
                // if day before the cooldown exits consider its profit along with the corresponding transactions profit.
                if(j-coolDown-1 >= 0)
                    maxVal = maximum(maxVal, memoization[j-coolDown-1]+priceList[stockId][day] - priceList[stockId][j]);
                // else just consider the transactions profit.
                else    
                    maxVal = maximum(maxVal, priceList[stockId][day] - priceList[stockId][j]);
            }
        }
        // Store the maximun of STEP1 & STEP2
        memoization[day] = maxVal;
    }

    // Backtracking the DP table to get atmost K transactions.
    findBuyAndSellDays(memoization);
    return memoization[noOfDays-1];
}

// Algorith-9B Dynamic Programming Using Bottom-up with O(m*n)
int problem3::task9B()
{
    // Declaring the memoization table with space of k+1 X n
    vector<int> memoization(noOfDays, -1);
    memoization[0] = 0;
    vector<int> maxDiff(noOfStocks,0);
    for(int i=0; i<noOfStocks; i++) 
        maxDiff[i] = -priceList[i][0];
    
    for(int day = 1; day < noOfDays; day++)
    {
        // STEP1: If stock is not selled on current day => cyrrent profit will be the previous days profit.
        int maxVal = memoization[day-1];
        // STEP2: If transaction is going to be happend on this day => next should happen on [0, day-c-1].
        // Populate the maxDiff for each stock reducing the runtime complexity to O(m*n) and calculate the maxProfit based on the maxDiff vector. 
        for(int stockId = 0; stockId < noOfStocks; stockId++)
        {
            maxVal = maximum(maxVal, maxDiff[stockId] + priceList[stockId][day] );
            // Update maxDiff vector based on the coolDown check i.e., if dp table doesnot contain that day consider dp table value = 0 and update as below.
            if(day-coolDown-1 >= 0)
            {
                maxDiff[stockId] = maximum(maxDiff[stockId], memoization[day-coolDown-1]-priceList[stockId][day]);
            }
            else
            {    
                maxDiff[stockId] = maximum(maxDiff[stockId], -priceList[stockId][day]);
            }
        }
        // Store the maximum of STEP1 & STEP2
        memoization[day] = maxVal;
    }

    // Backtracking the DP table to get atmost K transactions.
    findBuyAndSellDays(memoization);
    return memoization[noOfDays-1];
}


// Recurrsion logic for O(m*n*k) time complexity using memoization.
int problem3::mCompute(int n, vector<int>& maxDiff, vector<int>& memoization)
{
    // Base case if n==0, return 0 i.e., no profit on transaction on day 0
    if(n==0)
    {
        return memoization[n] = 0;
    }
    // If the value in memoization table is not filled
    if(memoization[n] == -1)
    {
        // Consider stock is on hold on current day i.e., not selling => maxProfit will be the value at previous day.
        int maxVal = mCompute(n-1, maxDiff, memoization);
        // STEP2: If transaction is going to be happend on this day => next should happen on [0, day-c-1].
        // Populate the maxDiff for each stock reducing the runtime complexity to O(m*n) and calculate the maxProfit based on the maxDiff vector. 
        for(int stockId = 0; stockId < noOfStocks; stockId++)
        {
            maxVal = maximum(maxVal, maxDiff[stockId] + priceList[stockId][n]);
            if(n - coolDown -1 >= 0)
            {
                maxDiff[stockId] = maximum(maxDiff[stockId], mCompute(n-coolDown-1, maxDiff, memoization) - priceList[stockId][n]);
            }
            else
            {
                maxDiff[stockId] = maximum(maxDiff[stockId], -priceList[stockId][n]);
            }
        }
        // Store the maximum value obtained in the DP table.
        memoization[n] = maxVal;
        return maxVal;
    }
    // If value is already filled => just return the value.
    return memoization[n];
}

// Algorithm 6A, top down recurrsion with O(m*n*k)
int problem3::task9A()
{
    // Declaring the DP table(n-1) and the maxDiff table(m).
    vector<int> memoization(noOfDays,-1);
    vector<int> maxDiff(noOfStocks,0);
    // Intitial maxDiff will be the negative of starting day price for each stock.
    for(int i=0; i < noOfStocks; i++)
        maxDiff[i] = -priceList[i][0];
    
    // Recurrsion Algorithm that calls the bottom right corner i.e., k,n-1 the value of the DP table, which in turn fills the rest of the values in recurrsion defined in the function.
    int maxProfit = mCompute(noOfDays-1, maxDiff, memoization);
    
    // Backtracking the DP table to get atmost K transactions.
    findBuyAndSellDays(memoization);

    return memoization[noOfDays - 1];
}

// Recurrsion logic for O(m*n*k) time complexity using memoization.
int problem3::mComputeBruteForce(int n, vector<int>& memoization)
{
    // Base case if n==0, return 0 i.e., no profit on transaction on day 0
    if(n==0)
    {
        return memoization[n] = 0;
    }
    // Consider stock is on hold on current day i.e., not selling => maxProfit will be the value at previous day.
    int maxVal = mComputeBruteForce(n-1, memoization);
    // STEP2: If transaction is going to be happend on this day => next should happen on [0, day-c-1].
    // Just don't use the stored recurrsion value i.e., store the value in the DP table over and over again.
    for(int stockId = 0; stockId < noOfStocks; stockId++)
    {
        for(int j = n-1; j>=0; j--)
        {
            // if day before the cooldown exits consider its profit along with the corresponding transactions profit.
            if(j-coolDown-1 >= 0)
                // HERE WE ARE COMPUTING THE TRANSACTION PROFIT AGAIN INSTEAD OF STORING IT AND USING IT.
                maxVal = maximum(maxVal, mComputeBruteForce(j-coolDown-1, memoization) + priceList[stockId][n] - priceList[stockId][j]);
            // else just consider the transactions profit.
            else    
                maxVal = maximum(maxVal, priceList[stockId][n] - priceList[stockId][j]);
        }
    }
    // Store the maximum value obtained in the DP table.
    memoization[n] = maxVal;
    return memoization[n];
}

int problem3::task7()
{
   // Declaring the memoization table(n-1).
    vector<int> memoization(noOfDays,-1);

    // Bruteforce Recurrsion Algorithm that calls the bottom right corner i.e., n-1 the value of the table, which in turn fills the rest of the values in recurrsion defined in the function.
    // Each recursion calls 2 recurrsions, which happens n times
    // It forms a binary tree, with total number of recursive calls as m*2^n
    int maxProfit = mComputeBruteForce(noOfDays-1, memoization);
    
    // Backtracking the DP table to get atmost K transactions.
    findBuyAndSellDays(memoization);

    return memoization[noOfDays - 1]; 
}