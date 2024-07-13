#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    while(a>0 && b>0)
    {
        if(a<b)
        {
            swap(a,b);
        }
        if(a%b==0)
        {
            return b;
        }
        int x=a-b;
        a=b;
        b=x;
    }
    if(b==0)
    {
        return a;
    }
    return b;
}
int main()
{
    cout<<"The two numbers whose GCD you want: ";
    int a,b;
    cin>>a;
    cin>>b;
    cout<<"GCD of "<<a<<" and "<<b<<" is: "<<gcd(a,b);
}