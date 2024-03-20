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
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int start=0;
        int end=numbers.size()-1;
        while(start<end)
        {
            if(numbers[start]+numbers[end]<target)
                start++;
            else if(numbers[start]+numbers[end]>target)
                end--;
            else return {start+1,end+1};
        }
        return {-1,-1};
    }
};