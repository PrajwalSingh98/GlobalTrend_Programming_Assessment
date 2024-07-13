#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int digit_sum(string x)
{
    int sum=0;
    for(int i=0;i<x.size();i++)
    {
        int d=(int)(x[i]-'0');
        sum+=d;
    }
    return sum;
}
int main()
{
    cout<<"Number whose sum of digits you want to find: ";
    string x;
    cin>>x;
    int f=digit_sum(x);
    cout<<"The sum of digits is: "<<f;
}