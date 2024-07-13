#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

void rotate(vector<int>& vec,int k)
{
    int n=vec.size();
    k=k%n;
    reverse(vec.begin(),vec.begin()+k);
    reverse(vec.begin()+k+1,vec.end());
    reverse(vec.begin(),vec.end());
}

int main()
{
    cout<<"Length of the array:";
    int N;
    cin>>N;
    cout<<"Input of the array:"<<endl;
    vector<int> vec(N);
    for(int t=0;t<N;t++)
    {
        cin>>vec[t];
    }
    cout<<"Number steps to rotate by: ";
    int k;
    cin>>k;
    rotate(vec,k);
    cout<<"Rotated array: ";
    for(int x:vec)
    {
        cout<<x<<" ";
    }
}