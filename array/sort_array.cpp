// Given an array of integers nums, sort the array in ascending order and return it.

// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space 
//complexity possible.

 

// Example 1:

// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), 
//while the positions of other numbers are changed (for example, 1 and 5).
// Example 2:

// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
// Explanation: Note that the values of nums are not necessairly unique.

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
    vector<int> sortArray(vector<int>& nums) 
    {
        // mergesort(nums, 0, nums.size()-1);
        // return nums;
        priority_queue<int, vector<int>, greater<int>> pq; //MIN HEAP
        for(auto i:nums)
            pq.push(i);
        
        int i=0;
        while(!pq.empty())
        {
            nums[i++]=pq.top();
            pq.pop();
        }

        return nums;



    }

    // void mergesort(vector<int> &nums, int low, int high)
    // {
    //     if(low<high)
    //     {
    //         int mid=low+(high-low)/2;
    //         mergesort(nums, low, mid);
    //         mergesort(nums, mid+1, high);
    //         merge(nums, low, mid, high);
    //     }
    // }

    // void merge(vector<int> &nums, int low, int mid, int high)
    // {
    //     vector<int> res(high-low+1);
    //     int i=low,j=mid+1;
    //     int k=0;
    //     while(i<=mid && j<=high)
    //     {
    //         if(nums[i]<=nums[j])
    //             res[k++]=nums[i++];
    //         else
    //             res[k++]=nums[j++];
    //     }
    //     while(i<=mid)
    //         res[k++]=nums[i++];
    //     while(j<=high)
    //         res[k++]=nums[j++];

    //     for(int a=0;a<res.size();a++)
    //         nums[low+a]=res[a];
    // }

};