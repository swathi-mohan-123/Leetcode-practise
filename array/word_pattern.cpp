// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false

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
    bool wordPattern(string pattern, string s) 
    {
        vector<string> v;
        int k=0;
        //IMPORTANR
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                v.push_back(s.substr(k, i-k));
                k=i+1;
            }   
        }
        if (k < s.length()) 
            v.push_back(s.substr(k));

        
        //Logic same as isomorphic strings
        if(v.size()!=pattern.length())
            return false;

        map<char, string> m1;
        map<string, char> m2;

        for(int i=0;i<pattern.length();i++)
        {
            if(m1.find(pattern[i])==m1.end() && m2.find(v[i])==m2.end())
            {
                m1[pattern[i]]=v[i];
                m2[v[i]]=pattern[i];
            }
            else
            {
                if((m1.count(pattern[i]) && m1[pattern[i]] != v[i]) || (m2.count(v[i]) && m2[v[i]] !=pattern[i]))
                { 
                    return false;
                }
            }
        }
        return true;
        
    }
};