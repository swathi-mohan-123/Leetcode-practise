// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.


// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
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
        // option1: sort and return nums[n/2]
        //option 2: hashing
        //option 3: Boyer-Moore Majority Vote Algorithm
    int majorityElement(vector<int>& nums) 
    {
        int n=nums.size();
        int count=0, element;
        for(int i=0;i<n;i++)
        {
            if(count==0)
                element=nums[i];
             
            if(nums[i]==element)
                count++;
            else    
                count--;   
        }
    // [7,7,5,7,5,1,    5,7,     5,5,7,7,     5,5,5,5]
        int verify=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==element)
                verify++;
        }
        if(verify>n/2)
            return element;
        return -1;
    }
};