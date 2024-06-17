// There is a rectangular brick wall in front of you with n rows of bricks. The ith row has some number of bricks each of\
the same height (i.e., one unit) but they can be of different widths. The total width of each row is the same.

// Draw a vertical line from the top to the bottom and cross the least bricks. If your line goes through the edge of a brick, \
then the brick is not considered as crossed. You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.

// Given the 2D array wall that contains the information about the wall, return the minimum number of crossed bricks after \
drawing such a vertical line.

 

// Example 1:


// Input: wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
// Output: 2
// Example 2:

// Input: wall = [[1],[1],[1]]
// Output: 3

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
    int leastBricks(vector<vector<int>>& wall) 
    {
        
        map<int,int> m;
        int maxsum=INT_MIN;
        for(int i=0;i<wall.size();i++)
        {
            int sum=0;
            for(int j=0;j<wall[i].size();j++)
            {
                sum+=wall[i][j];
                wall[i][j]=sum;    
            } 
       }


       for(int i=0;i<wall.size();i++)
            for(int j=0;j<wall[i].size()-1;j++) 
                    m[wall[i][j]]++;
    
        
        if(m.empty())
            return wall.size();

        for(auto it: m)
            maxsum=max(maxsum, it.second);
        
        return wall.size()-maxsum;

        
    }
};