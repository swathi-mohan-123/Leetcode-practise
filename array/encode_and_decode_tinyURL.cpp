// Note: This is a companion problem to the System Design problem: Design TinyURL.
// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it \
returns a short URL such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

// There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be \
encoded to a tiny URL and the tiny URL can be decoded to the original URL.

// Implement the Solution class:

// Solution() Initializes the object of the system.
// String encode(String longUrl) Returns a tiny URL for the given longUrl.
// String decode(String shortUrl) Returns the original long URL for the given shortUrl. It is guaranteed that the given shortUrl \
was encoded by the same object.
 


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
    map<string,string> encodemap;
    map<string,string> decodemap;
    string base = "http://tinyurl.com/";
   
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) 
    {
        if(encodemap.find(longUrl)==encodemap.end()) //if url doesnt exist, add it to map
        {
            encodemap.insert({longUrl, base+to_string(encodemap.size()+1)});
            decodemap.insert({base+to_string(encodemap.size()), longUrl});
        }
        return encodemap[longUrl];
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        return decodemap[shortUrl];
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));