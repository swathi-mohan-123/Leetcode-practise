

// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10


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
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m=triangle.size();
        for(int i=1;i<m;i++)
        {
            int n=triangle[i].size();
            for(int j=0;j<n;j++)
            {
                if(j<n-1 && j==0)
                    triangle[i][j]+=triangle[i-1][j];
                else if(j>=n-1 && j>0)
                    triangle[i][j]+=triangle[i-1][j-1];
                else
                    triangle[i][j]+=min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
    int mini=INT_MAX;
    for(int i=0;i<m;i++)
        mini=min(mini, triangle[m-1][i]);
    return mini;
    }
    
};