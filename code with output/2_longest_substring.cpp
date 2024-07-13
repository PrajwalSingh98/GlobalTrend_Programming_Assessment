#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
using namespace std;
int longest_substring(string s)
{
    int n=s.size();
    unordered_map<char,int> mp;
    int left=0,right=0;
    int ans=0;
    while(right<n)
    {
        while(mp[s[right]]==1)
        {
            mp[s[left]]--;
            left++;
        }
        ans=max(ans,right-left+1);
        mp[s[right]]++;
        right++;
    }
    return ans;

}
int main()
{
    string input;
    cout<<"Input String: ";
    cin>>input;
    int result=longest_substring(input);
    cout<<"The Length of the longest substring without repitition: "<<result;
}