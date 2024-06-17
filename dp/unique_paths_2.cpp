// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

 
// Example 1:


// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right
// Example 2:


// Input: obstacleGrid = [[0,1],[0,0]]
// Output: 1



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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // return uniquepaths(obstacleGrid.size()-1,obstacleGrid[0].size()-1, obstacleGrid);
       int m=obstacleGrid.size();
       int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j])
                    obstacleGrid[i][j]=-1;
            }
        }
    
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                 if(obstacleGrid[i][j]==-1)
                {
                    dp[i][j]=0;
                    continue;
                }
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





    // int uniquepaths(int i, int j, vector<vector<int>>& obstacleGrid)
    // {
    //     if(i==0 && j==0)
    //         return 1;
    //     if(i<0 || j<0 || obstacleGrid[i][j])
    //         return 0;
        
    //     int left=uniquepaths(i,j-1, obstacleGrid);
    //     int up=uniquepaths(i-1,j,obstacleGrid);
    //     return left+up;
    // }
};