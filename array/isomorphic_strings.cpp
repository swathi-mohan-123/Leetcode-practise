// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true
 
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
    bool isIsomorphic(string s, string t) 
    {
        map<char,char> m1,m2;
        if(s.length()!=t.length())
            return false;
         for(int i=0;i<s.length();i++)
         {
            if(m1.find(s[i])==m1.end() && m2.find(t[i])==m2.end())
            {
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
            else
            {
                if((m1[s[i]] && m1[s[i]]!=t[i]) || (m2[t[i]] && m2[t[i]]!=s[i])) //consider a case like 'title' and 'papep'
                    return false;
            }
         }
         return true;
        
    }
};