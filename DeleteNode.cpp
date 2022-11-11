#include <iostream>
int MinVal(TreeNode* root){  //finds the min value in the tree
     TreeNode* temp=root;
    while(temp->left)
        temp = temp->left;
    return temp->val;
 }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case
        if(!root)
            return NULL;

        if(root->val == key){
             //0 child
             if(!root->left && !root->right){
                 delete root;
                 return NULL;
             }
            //1 child
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            //2 children
            if(root->left && root->right){   // Find the min value in the right subtree and replace the root's value by it. Then delete the node which contained min(OR find the max value in the right subtree))
                int min = MinVal(root->right);
                root->val = min;
                root->right = deleteNode(root->right, min);
                return root;
            }
        }

        else if(root->val > key)  //visit the left subtree
           root->left = deleteNode(root->left, key);
        
        else  //visit the right subtree
            root->right = deleteNode(root->right, key);
        
         return root;
    }
};
