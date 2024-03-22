// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

// Example 1:



// Input: text = "nlaebolko"
// Output: 1
// Example 2:



// Input: text = "loonbalxballpoon"
// Output: 2
// Example 3:

// Input: text = "leetcode"
// Output: 0
  

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
    int maxNumberOfBalloons(string text) 
    {
        vector<int> freq(5,0);
        for(int i=0;i<text.length();i++)
        {
           if(text[i]=='b')
                freq[0]++;
            else if(text[i]=='a')
                freq[1]++;
            else if(text[i]=='l')
                freq[2]++;
            else if(text[i]=='o')
                freq[3]++;
            else if(text[i]=='n')
                freq[4]++;
        }
        int minele=INT_MAX;

        for(int i=0;i<5;i++)
        {
            if(i==2 || i==3)
            {
                if(freq[i]<2)
                    return 0;
                minele=min(minele, freq[i]/2);
            }
            else
            {
                if(freq[i]<1)
                    return 0;
                minele=min(minele, freq[i]);
            }
        }
        return minele;
        
    }
};