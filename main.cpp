#include <stdio.h>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "algorithms.h"
// #include "problem1.cpp"
// #include "problem2.cpp"
// #include "problem3.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    std::string taskName;
    if(argc==1)
        cout<<"No Extra Command Line Argument Passed Other Than Program Name"<<endl;
    else if(argc == 2)
    {
        taskName = argv[1]; // Name of the task to run.
    }
    else
    {
        cout<<"Number of Arguments Passed > 1., Only 1 of {1,2,3a,3b,4,5,6a,6b,7,8,9a,9b} these are valid."<<endl;
    }

    if(taskName == "1")
    {
        int m,n;
        std::cin>>m>>n;
        vector<vector<int> > prices(m, vector<int> (n,-1));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin>>prices[i][j];
            }
        }    
        problem1 run(m,n,prices);
        clock_t start, end;
        start = clock();
        int maxProfit = run.task1();
        end = clock();
        double time_taken_task1 = double(end - start) / double(CLOCKS_PER_SEC);
        cout<<run.transactionStockId<<" "<<run.transactionBuyDate<<" "<<run.transactionSellDate<<endl;
        //cout << "Task1: Time Taken = "<< fixed<<time_taken_task1<<setprecision(7)<<endl;
    }
    else if(taskName == "2")
    {
        int m,n;
        std::cin>>m>>n;
        vector<vector<int> > prices(m, vector<int> (n,-1));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin>>prices[i][j];
            }
        }    
        problem1 run(m,n,prices);
        clock_t start, end;
        start = clock();
        int maxProfit = run.task2();
        end = clock();
        double time_taken_task1 = double(end - start) / double(CLOCKS_PER_SEC);
        cout<<run.transactionStockId<<" "<<run.transactionBuyDate<<" "<<run.transactionSellDate<<endl;
        //cout << "Task2: Time Taken = "<< fixed<<time_taken_task1<<setprecision(7)<<endl;
    }
    else if(taskName == "3a")
    {
        int m,n;
        std::cin>>m>>n;
        vector<vector<int> > prices(m, vector<int> (n,-1));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin>>prices[i][j];
            }
        }    
        problem1 run(m,n,prices);
        clock_t start, end;
        start = clock();
        int maxProfit = run.task3A();
        end = clock();
        double time_taken_task1 = double(end - start) / double(CLOCKS_PER_SEC);
        cout<<run.transactionStockId<<" "<<run.transactionBuyDate<<" "<<run.transactionSellDate<<endl;
        //cout << "Task3A: Time Taken = "<< fixed<<time_taken_task1<<setprecision(7)<<endl;
    }
    else if(taskName == "3b")
    {
        int m,n;
        std::cin>>m>>n;
        vector<vector<int> > prices(m, vector<int> (n,-1));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin>>prices[i][j];
            }
        }    
        problem1 run(m,n,prices);
        clock_t start, end;
        start = clock();
        int maxProfit = run.task3B();
        end = clock();
        double time_taken_task1 = double(end - start) / double(CLOCKS_PER_SEC);
        cout<<run.transactionStockId<<" "<<run.transactionBuyDate<<" "<<run.transactionSellDate<<endl;
        //cout << "Task2: Time Taken = "<< fixed<<time_taken_task1<<setprecision(7)<<endl;
    }
    else if(taskName == "4")
    {
        int m,n,k;
        std::cin>>k;
        cin>>m>>n;
        vector<vector<int> > prices(m, vector<int> (n,-1));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin>>prices[i][j];
            }
        }    
        problem2 run(m,n,k,prices);
        clock_t start, end;
        start = clock();
        int maxProfit = run.task4();
        end = clock();
        double time_taken_task1 = double(end - start) / double(CLOCKS_PER_SEC);
        for(int i = run.outputKtransactions.size()-1; i >=0 ; i--)
        {
            cout<<run.outputKtransactions[i][0]<<" "<<run.outputKtransactions[i][1]<<" "<<run.outputKtransactions[i][2]<<endl;
        }
        //cout << "Task4: Time Taken = "<< fixed<<time_taken_task1<<setprecision(7)<<" max Profit="<<maxProfit<<endl;
    }
    else if(taskName == "5")
    {
        int m,n,k;
        std::cin>>k;
        cin>>m>>n;
        vector<vector<int> > prices(m, vector<int> (n,-1));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin>>prices[i][j];
            }
        }    
        problem2 run(m,n,k,prices);
        clock_t start, end;
        start = clock();
        int maxProfit = run.task5();
        end = clock();
        double time_taken_task1 = double(end - start) / double(CLOCKS_PER_SEC);
        for(int i = run.outputKtransactions.size()-1; i >=0 ; i--)
        {
            cout<<run.outputKtransactions[i][0]<<" "<<run.outputKtransactions[i][1]<<" "<<run.outputKtransactions[i][2]<<endl;
        }
        //cout << "Task5: Time Taken = "<< fixed<<time_taken_task1<<setprecision(7)<<" max Profit="<<maxProfit<<endl;
    }
    else if(taskName == "6a")
    {
        int m,n,k;
        std::cin>>k;
        cin>>m>>n;
        vector<vector<int> > prices(m, vector<int> (n,-1));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin>>prices[i][j];
            }
        }    
        problem2 run(m,n,k,prices);
        clock_t start, end;
        start = clock();
        int maxProfit = run.task6A();
        end = clock();
        double time_taken_task1 = double(end - start) / double(CLOCKS_PER_SEC);
        for(int i = run.outputKtransactions.size()-1; i >=0 ; i--)
        {
            cout<<run.outputKtransactions[i][0]<<" "<<run.outputKtransactions[i][1]<<" "<<run.outputKtransactions[i][2]<<endl;
        }
        //cout << "Task6A: Time Taken = "<< fixed<<time_taken_task1<<setprecision(7)<<" max Profit="<<maxProfit<<endl;
    }
    else if(taskName == "6b")
    {
        int m,n,k;
        std::cin>>k;
        cin>>m>>n;
        vector<vector<int> > prices(m, vector<int> (n,-1));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin>>prices[i][j];
            }
        }    
        problem2 run(m,n,k,prices);
        clock_t start, end;
        start = clock();
        int maxProfit = run.task6B();
        end = clock();
        double time_taken_task1 = double(end - start) / double(CLOCKS_PER_SEC);
        for(int i = run.outputKtransactions.size()-1; i >=0 ; i--)
        {
            cout<<run.outputKtransactions[i][0]<<" "<<run.outputKtransactions[i][1]<<" "<<run.outputKtransactions[i][2]<<endl;
        }
        //cout << "Task6B: Time Taken = "<< fixed<<time_taken_task1<<setprecision(7)<<" max Profit="<<maxProfit<<endl;
    }
    else if(taskName == "7")
    {
        int m, n,c;
        std::cin>>c;
        cin>>m>>n;
        vector<vector<int> > prices(m, vector<int> (n,-1));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin>>prices[i][j];
            }
        }    
        problem3 run(m,n,c,prices);
        clock_t start, end;
        start = clock();
        int maxProfit = run.task7();
        end = clock();
        double time_taken_task1 = double(end - start) / double(CLOCKS_PER_SEC);
        for(int i = run.outputKtransactions.size()-1; i >=0 ; i--)
        {
            cout<<run.outputKtransactions[i][0]<<" "<<run.outputKtransactions[i][1]<<" "<<run.outputKtransactions[i][2]<<endl;
        }
        //cout << "Task7: Time Taken = "<< fixed<<time_taken_task1<<setprecision(7)<<" max Profit="<<maxProfit<<endl;
    }
    else if(taskName == "8")
    {
        int m, n,c;
        std::cin>>c;
        cin>>m>>n;
        vector<vector<int> > prices(m, vector<int> (n,-1));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin>>prices[i][j];
            }
        }    
        problem3 run(m,n,c,prices);
        clock_t start, end;
        start = clock();
        int maxProfit = run.task8();
        end = clock();
        double time_taken_task1 = double(end - start) / double(CLOCKS_PER_SEC);
        for(int i = run.outputKtransactions.size()-1; i >=0 ; i--)
        {
            cout<<run.outputKtransactions[i][0]<<" "<<run.outputKtransactions[i][1]<<" "<<run.outputKtransactions[i][2]<<endl;
        }
        //cout << "Task8: Time Taken = "<< fixed<<time_taken_task1<<setprecision(7)<<" max Profit="<<maxProfit<<endl;
    }
    else if(taskName == "9a")
    {
        int m, n,c;
        std::cin>>c;
        cin>>m>>n;
        vector<vector<int> > prices(m, vector<int> (n,-1));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin>>prices[i][j];
            }
        }    
        problem3 run(m,n,c,prices);
        clock_t start, end;
        start = clock();
        int maxProfit = run.task9A();
        end = clock();
        double time_taken_task1 = double(end - start) / double(CLOCKS_PER_SEC);
        for(int i = run.outputKtransactions.size()-1; i >=0 ; i--)
        {
            cout<<run.outputKtransactions[i][0]<<" "<<run.outputKtransactions[i][1]<<" "<<run.outputKtransactions[i][2]<<endl;
        }
        //cout << "Task9a: Time Taken = "<< fixed<<time_taken_task1<<setprecision(7)<<" max Profit="<<maxProfit<<endl;
    }
    else if(taskName == "9b")
    {
        int m, n,c;
        std::cin>>c;
        cin>>m>>n;
        vector<vector<int> > prices(m, vector<int> (n,-1));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                cin>>prices[i][j];
            }
        }    
        problem3 run(m,n,c,prices);
        clock_t start, end;
        start = clock();
        int maxProfit = run.task9B();
        end = clock();
        double time_taken_task1 = double(end - start) / double(CLOCKS_PER_SEC);
        for(int i = run.outputKtransactions.size()-1; i >=0 ; i--)
        {
            cout<<run.outputKtransactions[i][0]<<" "<<run.outputKtransactions[i][1]<<" "<<run.outputKtransactions[i][2]<<endl;
        }
        //  cout << "Task9b: Time Taken = "<< fixed<<time_taken_task1<<setprecision(7)<<" max Profit="<<maxProfit<<endl;
    }
    else
    {
        cout<<"Invalid Argument., Only 1 of {1,2,3a,3b,4,5,6a,6b,7,8,9a,9b} these are valid."<<endl;
    }
    
    return 0;

}