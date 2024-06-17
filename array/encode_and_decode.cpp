// Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

// Machine 1 (sender) has the function:

// string encode(vector<string> strs) {
//   // ... your code
//   return encoded_string;
// }
// Machine 2 (receiver) has the function:
// vector<string> decode(string s) {
//   //... your code
//   return strs;
// }
// So Machine 1 does:

// string encoded_string = encode(strs);
// and Machine 2 does:

// vector<string> strs2 = decode(encoded_string);
// strs2 in Machine 2 should be the same as strs in Machine 1.

// Implement the encode and decode methods.

// You are not allowed to solve the problem using any serialize methods (such as eval).

 

// Example 1:

// Input: dummy_input = ["Hello","World"]
// Output: ["Hello","World"]
// Explanation:
// Machine 1:
// Codec encoder = new Codec();
// String msg = encoder.encode(strs);
// Machine 1 ---msg---> Machine 2

// Machine 2:
// Codec decoder = new Codec();
// String[] strs = decoder.decode(msg);
// Example 2:

// Input: dummy_input = [""]
// Output: [""]

#include <vector>
#include <map>
#include <set>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<unordered_map>
// #include <bits/stdc++.h>
using namespace std;


class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) 
    {
        string res="";
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            res+=to_string(s.size())+'#'+s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) 
    {
        vector<string> ans;
        int i=0, lastindex=-1;
        while(i<s.length())
        {
            if(s[i]=='#')
            {
                
                string val=s.substr(lastindex+1, i);
                int strlength=stoi(val);
                ans.push_back(s.substr(i+1, strlength));
                lastindex=i+strlength;
                i=lastindex;
            }
            i++;
        }
        return ans;        
    }
};

