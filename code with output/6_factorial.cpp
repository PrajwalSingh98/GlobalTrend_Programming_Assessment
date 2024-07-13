#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long int fact(int x)
{
    if(x==0 || x==1)
    {
        return 0;
    }
    long long int out=1;
    for(int i=2;i<=x;i++)
    {
        out*=i;
    }
    return out;
}
int main()
{
    // can find factorial upto x=19
    cout<<"Number whose factorial you want to find: ";
    int x;
    cin>>x;
    if(x<0)
    {
        cout<<"Error: Negative Number input";
        return 0;
    }
    long long int f=fact(x);
    cout<<"The factorial is: "<<f;
}