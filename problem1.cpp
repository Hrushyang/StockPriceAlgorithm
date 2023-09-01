#include <stdio.h>
#include <iostream>
#include <vector>
#include "algorithms.h"

using namespace std;

// Returns the maximum element given two int type numbers.
int problem1::maximum(int n1, int n2)
{
    if(n1>n2)
    {
        return n1;
    }
    return n2;
}

// Recurrsion memoization
int problem1::mCompute(int n, int m, vector<int>& stockMemoization)
{
    // base case, if n==0, return 0
    if(n==0)
    {
        return stockMemoization[n] = 0;
    }
    // if value is not yet calculated, calculate based on the recurrsion relation.
    else if(stockMemoization[n] == -1)
    {
        return stockMemoization[n] = maximum(0, mCompute(n-1, m, stockMemoization) + priceList[m][n] - priceList[m][n-1]);    

    }
    // if value is memoized, return the same.
    return stockMemoization[n];
}

// Backtracking the DP table
int problem1::findBuyAndSellDays(vector<vector<int> >& memoization)
{
    // Keep track of the max profit in the DP table and also keep track of the most recent zero profit in the DP table.
    int globalMax = -1;
    // For each stock
    for(int i=0; i < memoization.size(); i++)
    {
        // for each day
        for (int j=0; j < memoization[i].size(); j++)
        {
            // If global max is changed, update the transaction sell date and stockId.
            if(memoization[i][j] > globalMax)
            {
                transactionStockId = i+1;
                globalMax = memoization[i][j];
                transactionSellDate = j+1;
            }
        }
    }
    // Calculate the buy date price, based on the maxProfit & sellDate price.
    int buyDatePrice =  priceList[transactionStockId-1][transactionSellDate-1] - globalMax;
    for (int i=0; i < noOfDays; i++)
    {
        // For the stockId with maxProfit in DP table, check the buyDate price calculated above in the corresponding stockId price list
        if(buyDatePrice == priceList[transactionStockId-1][i])
        {
            // If found update buydate and break because we need only one such transaction.
            transactionBuyDate = i+1;
            break;
        }
    }
    return globalMax;
}

// Memoization 
int problem1::task3A()
{
    transactionStockId = -1;
    transactionBuyDate = -1;
    transactionSellDate = -1;
    int minimumPrice = -1;

    int maxProfit = -1;
    // Declare a 2D mXn DP table.
    vector<vector<int> > memoization(noOfStocks);
    // for each stockId fill the DP table
    for (int stockId = 0; stockId < noOfStocks; ++stockId)
    {
        vector<int> stockMemoization(noOfDays, -1);
        // Call the recurrsion function, with last day.    
        int status = mCompute(noOfDays-1, stockId, stockMemoization);
        // Update the memoization table for each stock.
        memoization[stockId] = stockMemoization;
    }
    // Backtracking to calculate the stockId, transactionBuyDate, transactionSellDate.
    maxProfit = findBuyAndSellDays(memoization);
    return maxProfit;
}

// Problem-1 task3B Dynamic Programming Using Bottom-up
int problem1::task3B()
{
    // Initialize the transaction parameters.
    transactionStockId = -1;
    transactionBuyDate = -1;
    transactionSellDate = -1;
    int maxProfit = -1;

    // Initialize the memoization vector in 2D, as we need to track the price for each stock for all the days.
    // O(mn) space.
    vector<vector<int> > memoization(noOfStocks);
    // For each stock Id
    for (int stockId = 0; stockId < noOfStocks; ++stockId)
    {
        vector<int> stockMemoization(noOfDays, -1);
        // Profit if we sell on day1 is zero.
        stockMemoization[0] = 0;
        // for each day after day 1, fill the DP table w.r.t to the recurrent relation below:
        // M[i] = max(0, M[i-1] + prices[m][n] - prices[m][n-1])
        for(int day = 1; day < noOfDays; day++)
        {
            stockMemoization[day] = maximum(0, stockMemoization[day-1] + priceList[stockId][day] - priceList[stockId][day-1]);
        }
        // update the 2D memoization table for each stock.
        memoization[stockId] = stockMemoization;
    }
    // Backtracking the DP table to extract the transaction parameters.
    maxProfit = problem1::findBuyAndSellDays(memoization);
    return maxProfit;
}

// Problem-1 task 2 Greedy Approach
int problem1::task2()
{
    // Intitialie maxProfit and transaction parameters
    int maxProfit = -1;
    transactionStockId = -1;
    transactionBuyDate = -1;
    transactionSellDate = -1;
    // Initialize minimum price to track the same.
    int minimumPrice = -1;
    // for each stock Id
    for (int stockId = 0; stockId < noOfStocks; ++stockId)
    {
        // start minimum price as starting day price of the current stock.
        minimumPrice = priceList[stockId][0];
        int buy = 1;
        // for each buyDate from day 1
        for (int buyDate = 1; buyDate < noOfDays; ++buyDate)
        {
            // Keep track of the minimum stock price, so that we can track the buy date.
            if(priceList[stockId][buyDate] < minimumPrice)
            {
                buy = buyDate+1;
                minimumPrice = priceList[stockId][buyDate];
            }
            // Calculate the current profit
            int currentProfit = priceList[stockId][buyDate] - minimumPrice;
            
            // Compare current profit and the maxProfit & update transaction sell date and buyDate.
            if(currentProfit > maxProfit)
            {
                maxProfit = currentProfit;
                transactionStockId = stockId+1;
                transactionSellDate = buyDate+1;
                transactionBuyDate = buy;
            } 
        }
    }
    return maxProfit;
}
// Problem-1 task 1 Bruteforce
int problem1::task1()
{
    // Intitialie maxProfit and transaction parameters
    int maxProfit = 0; 
    transactionStockId = -1;
    transactionBuyDate = -1;
    transactionSellDate = -1;

    // for each stock Id
    for (int stockId = 0; stockId < noOfStocks; ++stockId)
    {
        // for each buydate
        for (int buyDate = 0; buyDate < noOfDays; ++buyDate)
        {
            // for each selldate that is after the current buydate
            for (int sellDate = buyDate; sellDate < noOfDays; ++sellDate)
            {
                // Current profit w.r.t buydate and selldate.
                int currentProfit = priceList[stockId][sellDate] - priceList[stockId][buyDate];

                // If current profit is greater than max profit, update maxProfit and store the transaction. 
                if(currentProfit > maxProfit)
                {
                    maxProfit = currentProfit;
                    transactionStockId = stockId + 1;
                    transactionBuyDate = buyDate + 1;
                    transactionSellDate = sellDate + 1;
                }
            }
        }
    }
    return maxProfit;
}

