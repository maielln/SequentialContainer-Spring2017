 /*  GHP #6 code

    Read in 15 double values (because they are prices) and store them
    in a sequential container.
    Program must display
    a) The trading range (lowest and highest)
    b) A sequence that shows how much the price rose or fell each day.

    Written by Nicole Maiello

    April 18, 2017
    Language: c++ (Written in Code::Blocks, g++ target)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main(void)
{
    vector<double> val;
    double result[14];
    int i;
    double *p1;
    double *p2;
    double *p3;

    double price;

    cout<<"Welcome to the investment company of Pickum & Loozem!"<<endl<<"This program is our stock tracker. You will be asked to input our stock prices over a 15-day period."<<endl;

    for(i = 0; i < 15; i++){
        cout<<"Enter the stock price for day "<<i+1<<" to be stored: (only enter numbers!)"<<endl;
        cin>>price;
        val.push_back(price);
    }
    p1 = max_element(&val.front(), &val.back()); //gets pointer to max element
    p2 = min_element(&val.front(), &val.back()); //gets pointer to min element

    cout<<"The stock range for this period is: $"<<*p1<<" to $"<<*p2<<endl;

    std::adjacent_difference(val.begin(), val.end(), val.begin()); //calculates the difference between adjacent values in the array and puts them back in the array

    for(i = 0; i < 15; i++){
        if(i != 0){
            if (val[i] > 0)
                cout<<"The price rose from day "<<i<<" to day "<<i+1<<" by $"<<val[i]<<endl;
            else if (val[i] < 0)
                cout<<"The price fell from day "<<i<<" to day "<<i+1<<" by $"<<(-1 * val[i])<<endl;
            else
                cout<<"The price stayed the same from day "<<i<<" to day "<<i+1<<endl;
        }
    }
    return 0;
}
