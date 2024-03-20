// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal 
// substring
//  consisting of non-space characters only.

 

// Example 1:

// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.
// Example 2:

// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.
// Example 3:

// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.
 

//IMPORTANT TO HANDLE EDGE CASES LIKE "a" AND "a     ". Always check if i>=0
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
    int lengthOfLastWord(string s) 
    {
        int i=s.length()-1;
 
        int count=0;
        
        while(i>=0 && s[i]==' ')
        {
            i--;
        }
        
        while(i>=0 && s[i]!=' ')
        {
            count++;
            i--;
        }
        
    return count;

        
    }
};