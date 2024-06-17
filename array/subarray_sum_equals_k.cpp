// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2


#include <vector>
#include <map>
#include <set>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<unordered_map>
// #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        
        for(int i=1;i<nums.size();i++)
            nums[i]+=nums[i-1];

        map<int,int> m;            
        int count=0;


        for(int i=0;i<nums.size();i++)
        {
            
            if(m.find(nums[i]-k)!=m.end())
                count+=m[nums[i]-k];
            if(nums[i]-k==0)
                count++;
            
            m[nums[i]]++;
                
        }  
        return count;      
        
    }
};