// Given an integer array nums and an integer k, return the k most frequent elements. 
//You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

#include <vector>
#include <map>
#include <set>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_map>
#include <queue>
// #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int, int> &b)
    {
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> ans;
        map<int,int> m;
        vector<pair<int,int>> v;

        for(int i=0;i<nums.size();i++)
            m[nums[i]]++; //O(N)
        
        for(auto it: m)
            v.push_back(it);
        
        sort(v.begin(), v.end(), cmp);
        for(int i=0;i<k;i++)
            ans.push_back(v[i].first); //O(KlogN)
            
        return ans;
    }
};