// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

// A palindrome is a string that reads the same forwards and backwards.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted \
without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
 

// Example 1:

// Input: s = "aabca"
// Output: 3
// Explanation: The 3 palindromic subsequences of length 3 are:
// - "aba" (subsequence of "aabca")
// - "aaa" (subsequence of "aabca")
// - "aca" (subsequence of "aabca")
// Example 2:

// Input: s = "adc"
// Output: 0
// Explanation: There are no palindromic subsequences of length 3 in "adc".
// Example 3:

// Input: s = "bbcbaba"
// Output: 4
// Explanation: The 4 palindromic subsequences of length 3 are:
// - "bbb" (subsequence of "bbcbaba")
// - "bcb" (subsequence of "bbcbaba")
// - "bab" (subsequence of "bbcbaba")
// - "aba" (subsequence of "bbcbaba")
 


#include <vector>
#include <map>
#include <set>
#include<stdio.h>
#include<string>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

// #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
       unordered_map<char, vector<int>> m;
       int ans=0;
       for(int i=0;i<s.length();i++)
           m[s[i]].push_back(i);

        for(auto it: m)
        {
            unordered_set<char> se;
            int len=it.second.size();
            int first=it.second[0];
            int last=it.second[len-1];
            for(int i=first+1;i<last;i++)
            {
                se.insert(s[i]);
            }

            ans+=se.size();
        }
        return ans;
    }
};