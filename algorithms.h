// C++ implementation of the approach
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
#ifndef ALGORITHMS_H
#define ALGORITHMS_H
// Class problem1, contains all required input parameters and helper functions.
class problem1
{
    private:
        int noOfStocks; // # of stocks
        int noOfDays;   // # of days
        vector<vector<int> > priceList; // Corresponding prices of each stock for each day.
        int mCompute(int n, int m, vector<int>& stockMemoization); // Private function to calculate DP table by recurrsion.
        int findBuyAndSellDays(vector<vector<int> >& memoization); // Private function to do backtracking on DP table to update the public (transactionstockId, transactionBuyDate, transactionSellDate)
        int maximum(int n1, int n2); // Function that returns max of two integers.
    public:
        // Output transaction parameters.
        int transactionStockId;
        int transactionBuyDate;
        int transactionSellDate;
        // Constructor to take inputs defined from STDIN.
        problem1(int m, int n, vector<vector<int> >& prices)
        {
            noOfStocks = m;
            noOfDays = n;
            priceList = prices;
        }
        int task1(); // BruteForce Algorithm
        int task2(); // Greedy Algorithm
        int task3A();// Top Down Recurrsion Algorithm
        int task3B();// Bottom Up Memoization Algorithm
};

class problem2
{
    private:
        int noOfStocks; // # of stocks
        int noOfDays;   // # of days
        int noOfTransactions; // how many transactions are required.
        vector<vector<int> > priceList; // Corresponding prices of each stock for each day.
        int mCompute(int n, int k, vector<vector<int> >& maxDiff, vector<vector<int> >& memoization); // Private function to calculate DP table by recurrsion with m*n*k algorithm.
        void findBuyAndSellDays(vector<vector<int> >& memoization); // Private function to do backtracking on DP table to update the public (transactionstockId, transactionBuyDate, transactionSellDate)
        int bruteForceRecurrsion(int n, int k, vector<vector<int> >& memoization); // bruteForce implementation for m*n^(2k)
        int maximum(int n1, int n2); // Function that returns max of two integers.
    public:
        // Output transaction parameters.
        vector<vector<int> > outputKtransactions;
        // Constructor to take inputs defined from STDIN.
        problem2(int m, int n, int k, vector<vector<int> >& prices)
        {
            noOfStocks = m;
            noOfDays = n;
            noOfTransactions = k;
            priceList = prices;
        }
        int task4(); // BruteForce Algorithm
        int task5(); // DP with m*n^2*k
        int task6A();// Top Down Recurrsion Algorithm with m*n*k
        int task6B();// Bottom Up Memoization Algorithm with m*n*k
};

class problem3
{
    private:
        int noOfStocks; // # of stocks
        int noOfDays;   // # of days
        int coolDown; // CoolDown period after each transaction.
        vector<vector<int> > priceList; // Corresponding prices of each stock for each day.
        int mCompute(int n, vector<int>& maxDiff, vector<int>& memoization); // Private function to calculate DP table by recurrsion with m*n*k algorithm.
        int mComputeBruteForce(int n, vector<int>& memoization); // Private function for bruteforce approach
        void findBuyAndSellDays(vector<int>& memoization); // Private function to do backtracking on DP table to update the public (transactionstockId, transactionBuyDate, transactionSellDate)
        int maximum(int n1, int n2); // Function that returns max of two integers.
    public:
        // Output transaction parameters.
        vector<vector<int> > outputKtransactions;
        // Constructor to take inputs defined from STDIN.
        problem3(int m, int n, int c, vector<vector<int> >& prices)
        {
            noOfStocks = m;
            noOfDays = n;
            coolDown = c;
            priceList = prices;
        }
        int task7(); // BruteForce Algorithm O(m*2^n)
        int task8(); // DP with O(m*n^2)
        int task9A(); // DP recurrsion memoization O(m*n)
        int task9B(); // DP with O(m*n)
};

#endif  // ALGORITHMS_H