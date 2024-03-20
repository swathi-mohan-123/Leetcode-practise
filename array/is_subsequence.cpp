// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the 
//characters without disturbing the relative positions of the remaining characters. 
//(i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 

// Example 1:

// Input: s = "abc", t = "ahbgdc"
// Output: true
// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false


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
    bool isSubsequence(string subsequence, string original) 
    {

        //i for original, j for subsequence
        int i=0,j=0;
        for(; i<original.length();)
        {
            if(subsequence[j]==original[i])
            {
                i++; j++;
            }
            else
            {
                i++;
            }
        }
        if(j==subsequence.length())
            return true;
        return false;

    }
};