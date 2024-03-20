//Given an integer array nums and an integer k, return true if there are two distinct indices 
//i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false
 

#include <vector>
#include <map>
#include <set>
#include<stdio.h>
// #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        map<int,int> m;
        int ans=false;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])!=m.end())
                if(i-m[nums[i]]<=k)
                    return true;
                
                m[nums[i]]=i;
        }
        return false;
    }
};