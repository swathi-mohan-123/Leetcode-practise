

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


// Example 1:


// Input: root = [1,2,2,3,4,4,3]
// Output: true
// Example 2:


// Input: root = [1,2,2,null,3,null,3]
// Output: false
 



#include <vector>
#include <map>
#include <set>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<queue>
// #include <bits/stdc++.h>
using namespace std;


//   Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


class Solution {
public:

    // bool isIdentical(TreeNode *p, TreeNode *q)
    // {
    //     if(!p && !q)
    //         return true;
    //     if(!p || !q)
    //         return false;
    //     if(p->val != q->val)
    //         return false;
    //     return isIdentical(p->left, q->right) && isIdentical(p->right, q->left);
    // }
    // bool isSymmetric(TreeNode* root) 
    // {
    //     if(!root)
    //         return true;
    //     TreeNode *p=root->left;
    //     TreeNode *q=root->right;
    //     return isIdentical(p,q);
        
       
    // }
    bool isPalindrome(vector<int> v)
    {
        
        if(v.size()%2)
            return false;
        int i,j;

        for(i=0,j=v.size()-1;i<v.size()/2;i++, j--)
        {
            if(v[i]!=v[j])
                return false;
        }
        
        return true;
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> v;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left)
                {
                    q.push(node->left);
                    v.push_back(node->left->val);
                }
                else
                    v.push_back(-10);
                if(node->right)
                {
                    q.push(node->right);
                    v.push_back(node->right->val);
                }
                else
                    v.push_back(-10);  
            }
             
           bool flag=isPalindrome(v);
                if(!flag)
                    return false;
           
        }
        return true;
    }
};