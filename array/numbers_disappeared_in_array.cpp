// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] 
// that do not appear in nums.

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]
// Example 2:

// Input: nums = [1,1]
// Output: [2]

#include <vector>
#include <map>
#include <set>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_map>
// #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int num, chair, i=0;
        vector<int> ans;

        //BETTER TIME COMPLEXITY
        // vector<int> ideal(nums.size(),-1);
        // for(int i=0;i<nums.size();i++)
        //     ideal[nums[i]-1]++;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(ideal[i]==-1)
        //         ans.push_back(i+1);
        // }
        


        //BETTER SPACE COMPLEXITY
        for(int i=0;i<nums.size();i++)
        {
            num=nums[i];
            chair=num-1;
            if(nums[chair]!=num)
            {
                swap(nums[chair], nums[i]);
                i--;
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
                ans.push_back(i+1);
        }
        return ans;
        
    }
};