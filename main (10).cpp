#include <iostream>
//Kth largest element = (K-N+1)th smallest element
int solve(TreeNode* root,int &i, int k){
    //base case
    if(!root)
        return -1;
    //Left subtree
    int left = solve(root->left, i, k);

    if(left != -1) //Kth smallest element has been found already so return it to parent
       return left;
    
    //Reached root
    i++;
    if(i==k)
       return root->val;
    
    //Right subtree
    return solve(root->right, i, k);
}
    int kthSmallest(TreeNode* root, int k) {
    int i=0;
    int ans = solve(root, i, k);
    return ans;
    }
