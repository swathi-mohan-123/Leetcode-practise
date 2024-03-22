// You have a long flowerbed in which some of the plots are planted, and some are not. However, 
//flowers cannot be planted in adjacent plots.

// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, 
//return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

// Example 1:

// Input: flowerbed = [1,0,0,0,1], n = 1
// Output: true
// Example 2:

// Input: flowerbed = [1,0,0,0,1], n = 2
// Output: false
 
 //LOT OF EDGE CASES TO HANDLE!!!

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
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {

        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i])
                continue;
           if((i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
           {
            // when i=0, the first part of the condition is true. The second part's second part is either true or false.
            //For the last element, the 2nd part of first half is true/false. The second part of the condition is true.
            //For middle elements, both the conditions can evaluate to true or false

            //[0,0,1], [1,1,0,0]
            n--;
            flowerbed[i]=1;
           }

        }
        if(n<=0)
            return true;
        return false;
        
    }
};