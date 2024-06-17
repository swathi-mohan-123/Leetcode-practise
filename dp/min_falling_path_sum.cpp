// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

// Example 1:


// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.
// Example 2:


// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is shown.

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
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        // vector<int<vector<int,int>> dp(n, vector<int> n);
        // for(int j=0;j<n;j++)
        //     dp[0][j]=matrix[0][j];

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j-1<0)
                    matrix[i][j]+=min(matrix[i-1][j], matrix[i-1][j+1]);
                else if(j+1>=n)
                    matrix[i][j]+=min(matrix[i-1][j], matrix[i-1][j-1]);
                else 
                    matrix[i][j]+=min(matrix[i-1][j],min(matrix[i-1][j-1], matrix[i-1][j+1]));
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
            ans=min(ans, matrix[n-1][i]);
        
        return ans;
        
        
    }
};