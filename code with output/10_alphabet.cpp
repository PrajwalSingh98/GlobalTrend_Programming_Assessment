#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool check(char& c)
{
    if((c>='a'&&c<='z')||(c>='A' && c<='Z'))
        return true;
    return false;

}
int main()
{
    cout<<"Input String: ";
    string s;
    cin>>s;
    for(char c:s)
    {
        if(!check(c))
        {
            cout<<"Not all alphabet string";
            return 0;
        }
    }
    cout<<"All alphabet string";
}