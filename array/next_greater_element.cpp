// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// Example 2:

// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
// - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
 

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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        //O(M*N)
        // map<int,int> m;
        // vector<int> ans;
        // for(int i=0;i<nums2.size();i++)
        // {
        //     m[nums2[i]]=i;
        // }
        // for(int i=0;i<nums1.size();i++)
        // {
        //     int gte=-1;
        //     auto it=m.find(nums1[i]);
        //     if(it!=m.end())
        //     {
        //         int ind=it->second;
        //         cout<<ind<<"\n";
        //         for(int j=ind+1;j<nums2.size();j++)
        //         {
        //             if(nums2[j]>nums1[i])
        //             {
        //                 gte=nums2[j];
        //                 break;
        //             }
        //         }
                
        //     }
        //     ans.push_back(gte);
        // }



        //O(M+N)
        map<int,int> m;
        vector<int> ans;
        stack<int> st;

        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums2[i])
            {
                st.pop();
            }
            if(!st.empty() && st.top()>nums2[i])
                m[nums2[i]]=st.top();
            else
                m[nums2[i]]=-1;
             
             st.push(nums2[i]);
        }
        
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};