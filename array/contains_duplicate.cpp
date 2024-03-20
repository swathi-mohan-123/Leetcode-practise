

#include <vector>
#include <map>
#include <set>
#include<stdio.h>
// #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // bool containsDuplicate(vector<int>& nums) 
    // {
    //    //SC O(N) and TC O(N)
    //     unordered_set<int> s(nums.begin(), nums.end());
       
    //     if(nums.size()!=s.size())
    //         return true;
    //     return false;

    // }

    bool containsDuplicate(vector<int>& nums) 
    {
       map<int,int> m;
       for(int i=0;i<nums.size();i++)
       {
        if(m.find(nums[i])!=m.end())
        {
                return true;
        }
        else
        {
            m[nums[i]]++;
        }
       }
       return false;

    }

};