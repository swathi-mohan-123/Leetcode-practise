// Given an integer array nums, handle multiple queries of the following type:

// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

// Example 1:

// Input
// ["NumArray", "sumRange", "sumRange", "sumRange"]
// [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
// Output
// [null, 1, -1, -3]

// Explanation
// NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
// numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
// numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
// numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

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

class NumArray {
public:
    //TC: O(N), SC: O(1)
    // vector<int> nums;
    // NumArray(vector<int>& nums) 
    // {
    //     this->nums=nums;
    // }
    
    // int sumRange(int left, int right) 
    // {
    //     int sum=0;
    //     for(int i=left;i<=right;i++)
    //         sum+=nums[i];
        
    //     return sum;
    // }


    //TC: O(1), SC: O(N)
    vector<int> prefixsum;
    NumArray(vector<int>& nums) 
    {
        prefixsum.resize(nums.size());
        prefixsum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            prefixsum[i]=nums[i]+prefixsum[i-1];

    }
    
    int sumRange(int left, int right) 
    {

        if(!left)
            return prefixsum[right];
        return prefixsum[right]-prefixsum[left-1];
    }


};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */