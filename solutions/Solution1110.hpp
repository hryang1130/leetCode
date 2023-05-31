//
// Created by kevin on 2023/5/30.
//

#ifndef LEETCODEGITEE_SOLUTION1110_H
#define LEETCODEGITEE_SOLUTION1110_H

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


// Definition for a binary tree node.
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
    vector<TreeNode*> ans;
    bool vis[1005];
    TreeNode* dfs(TreeNode* root, vector<int>& to_delete){
        if(root==nullptr){
            return nullptr;
        }
        root->left=dfs(root->left,to_delete);
        root->right=dfs(root->right,to_delete);

        if(!vis[root->val]){
            return root;
        }
        if(root->left){ans.push_back(root->left);}
        if(root->right){ans.push_back(root->right);}
        vis[root->val]=false;
        return nullptr;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        memset(vis,false,sizeof(bool)*1005);
        for(auto num:to_delete){
            vis[num]=true;
        }
        TreeNode* tmp=dfs(root,to_delete);
        if(tmp){
            ans.push_back(tmp);
        }
        return ans;

    }
};

#endif //LEETCODEGITEE_SOLUTION1110_H
