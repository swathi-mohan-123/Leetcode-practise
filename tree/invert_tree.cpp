// Given the root of a binary tree, invert the tree, and return its root.


// Example 1:


// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]
// Example 2:


// Input: root = [2,1,3]
// Output: [2,3,1]
// Example 3:

// Input: root = []
// Output: []
 




struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

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
    TreeNode* invertTree(TreeNode* root) 
    {
        // queue<TreeNode *>q;
        // if(! root)
        //     return NULL;
        // TreeNode *newroot=root;
        // q.push(root);
        // while(!q.empty())
        // {

        //         TreeNode *node=q.front();
        //         q.pop();
        //         swap(node->left, node->right);
        //         if(node->left)
        //             q.push(node->left);
        //         if(node->right)
        //             q.push(node->right);
            
            
        // }
        // return root;

        if(!root)
            return NULL;
        swap(root->left, root->right);
        root->left= invertTree(root->left);
        root->right= invertTree(root->right);

        return root;

    }
};