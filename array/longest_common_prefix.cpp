// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

#include <vector>
#include <map>
#include <set>
#include<stdio.h>
#include<string>
#include<algorithm>
// #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string ans="";
        sort(strs.begin(), strs.end());
        int n=strs.size();
        int len=min(strs[0].length(), strs[n-1].length());
        for(int i=0;i<len;i++)
        {
            if(strs[0][i]!=strs[n-1][i])
                break;
            else
                ans+=strs[0][i];
        }
        return ans;
        
    }
};