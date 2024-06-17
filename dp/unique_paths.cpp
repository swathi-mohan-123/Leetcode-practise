

// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

// Example 1:


// Input: m = 3, n = 7
// Output: 28
// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down
 


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
    // int uniquePaths(int m, int n) 
    // {
    //     return uniquep(m-1,n-1);
    // }

    // int uniquep(int i, int j)
    // {
    //     if(i==0 && j==0)
    //         return 1;
    //     if(i<0 || j<0)
    //         return 0;
        
    //     int up= uniquep(i-1,j);
    //     int left=uniquep(i,j-1);
    //     return up+left;
    // }


    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        //int dp[m][n];
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=1;
                    continue;
                }
                int up=0,left=0;
                if(i>0)
                    up=dp[i-1][j];
                if(j>0)
                    left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
    }
};