
#include <bits/stdc++.h>
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
    bool isSymmetric(TreeNode* root) {
        return checksymmetry(root->left,root->right);
    }
    bool checksymmetry(TreeNode* Left, TreeNode* Right){
        if(Left==NULL && Right==NULL){
            return true;
        }
        else if(Left==NULL || Right==NULL){
            return false;
        }
        return Left->val==Right->val && checksymmetry(Left->left,Right->right) &&checksymmetry(Left->right,Right->left);

    }


};