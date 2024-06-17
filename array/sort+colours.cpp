
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 


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
    void sortColors(vector<int>& nums) 
    {
        int l=0, r=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                swap(nums[i], nums[l]);
                l++;
            }
            else if(nums[i]==2)
            {
                swap(nums[i], nums[r]);
                r--;
                i--;
            }
            
            if(i==r)
                break;
        }
        
    }
};