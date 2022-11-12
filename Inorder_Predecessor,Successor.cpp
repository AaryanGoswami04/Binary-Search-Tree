#include <iostream>
pair<int,int> predecessorSuccessor(Node* root, int key)
{
     //Time complexity:O(N), Space complexity:O(1)
    int pre=-1;   //stores predecessor
    int succ=-1;  //stores successor
    Node* temp=root;
    while(temp->data!= key){ //Find key
        
       if(temp->data > key){
        succ = temp->data;
        temp = temp->left;
       }
       
       else{
        pre = temp->data;
        temp = temp->right;
       }
    }
     
    //Predecessor is the max of left subtree 
     Node* LeftTree = temp->left;
    while(LeftTree != NULL){
        pre = LeftTree->data;
        LeftTree = LeftTree->right;
    }
     
    //successor is the min of right subtree
    Node* RightTree = temp->right;
    while(RightTree != NULL){
        succ = RightTree->data;
        RightTree = RightTree->left;
    }
    return {pre,succ};
}
