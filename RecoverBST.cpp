#include <iostream>
//You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
class Solution {
    //Time complexity:O(N), Space complexity:O(N)
private:
    TreeNode *first;
    TreeNode *prev;
    TreeNode *middle;
    TreeNode *last;
public:
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);

        if(root->val < prev->val){
            //If this is first violation
            //mark these nodes first and middle
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else   //if this is second violation, mark last as root
                last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);

        inorder(root);

        if(first && last)
            swap(first->val, last->val);
        else
            swap(first->val, middle->val);
    }
};
//https://www.youtube.com/watch?v=ZWGW7FminDM&t=819s
