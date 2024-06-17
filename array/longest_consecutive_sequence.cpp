// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
 

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
    int longestConsecutive(vector<int>& nums) 
    {
        set<int> s(nums.begin(), nums.end());
        if(s.size()==0)
            return 0;
        int maxlength=1, length=1;

        for(auto x: s)
        {
            int curr=x;
            int prev=curr-1;
            if(s.find(prev)==s.end()) //prev is not found
            {
                //this means this element could be the beginning of a consecutive sequence
                int next=curr+1;
                length=1;
                while(s.find(next)!=s.end()) //next element exists
                {
                    next++;
                    length++;
                }
                maxlength=max(maxlength,length);
            }
        }
        return maxlength;
    }
};