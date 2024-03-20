// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
//typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
 

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
    //SORTING -> TC O(NlogN)
    // bool isAnagram(string s, string t) 
    // {
    //     sort(s.begin(), s.end());
    //     sort(t.begin(), t.end());
    //     if(s==t)
    //         return true;
    //     return false; 
    // }


    //HASHING -> TC: O(N) SC: O(N)
     bool isAnagram(string s, string t) 
    {
       unordered_map<char,int> m;
       for(int i=0;i<s.length();i++)
       {
            m[s[i]]++;
       }
       for(int i=0;i<t.length();i++)
       {
           m[t[i]]--;
       }
       for(auto it: m)
       {
            if(it.second!=0)
                return false;
       }
       return true;
    }
};

   