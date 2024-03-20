// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.



#include <vector>
#include <map>
#include <set>
#include<stdio.h>
#include<string>
#include<algorithm>
// #include <bits/stdc++.h>
using namespace std;class Solution {


public:
    set<vector<int>> twosum(vector<int> &nums, int start, int end, int target)
    {
        set<vector<int>> temp;
         while(start<end)
            {
                if(nums[start]+nums[end]<target)
                    start++;
                else if(nums[start]+nums[end]>target)
                    end--;
                else 
                {
                    temp.insert({-target, nums[start],nums[end]});
                    start++;
                    end--;
                }
            }
        return temp;
    }
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        set<vector<int>>s;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                break;
            // if(i>0 && nums[i]==nums[i-1])
            //     continue;
            int start=i+1;
            int end=n-1;
            for(auto it: twosum(nums, start, end, -nums[i]))
                s.insert(it);
        }
        for(auto i:s)
            ans.push_back(i);
        return ans;
        
    }
};