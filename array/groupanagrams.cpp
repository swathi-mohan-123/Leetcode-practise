// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
//typically using all the original letters exactly once.


// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]
 

#include <vector>
#include <map>
#include <set>
#include<stdio.h>
#include<string>
#include<algorithm>
// #include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        map<string,vector<string>> m;

        for(int i=0;i<strs.size();i++)
        {
            string word=strs[i];
            sort(strs[i].begin(), strs[i].end());
            m[strs[i]].push_back(word);
        }

        for(auto it: m)
        {
            ans.push_back(it.second);
        }
        return ans;
        
    }
};