#include <iostream>

 bool solve(TreeNode* root, long long  min, long long max){
        //base case
        if(!root)
           return 1;

         if(root->val > min && root->val < max){
             bool left = solve(root->left, min, root->val);
             bool right = solve(root->right, root->val, max);
             if(left && right)
               return 1;
         }
         return 0;
    }
    bool isValidBST(TreeNode* root) {
        long long lowest = 1LL*INT_MIN-1; //To cover the edge case, when root=INT_MIN or INT_MAX
        long long highest = 1LL*INT_MAX+1;
        return solve(root, lowest, highest);
    }
};
