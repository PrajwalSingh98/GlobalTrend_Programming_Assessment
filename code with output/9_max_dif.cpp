#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int max_dif(vector<int> vec)
{
    int m1=vec[0];
    int m2=vec[0];
    for(int x:vec)
    {
        m1=min(m1,x);
        m2=max(m2,x);
    }
    return (m2-m1);
}
int main()
{
    cout<<"Length of the array: ";
    int N;
    cin>>N;
    cout<<"Input Array: "<<endl;
    vector<int> vec(N);
    for(int t=0;t<N;t++)
    {
        cin>>vec[t];
    }
    cout<<"Maximum difference any 2 elements is: "<<max_dif(vec);
}