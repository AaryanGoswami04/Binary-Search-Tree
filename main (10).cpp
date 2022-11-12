#include <iostream>
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
     //find key
    int pre=-1;
    int succ=-1;
   BinaryTreeNode<int>* temp=root;
    while(temp->data!= key){
        
       if(temp->data > key){
        succ=temp->data;
        temp=temp->left;
       }
       
       else{
        pre=temp->data;
        temp=temp->right;
       }
    }
    //pred
   BinaryTreeNode<int>* LeftTree=temp->left;
    while(LeftTree != NULL){
        pre=LeftTree->data;
        LeftTree=LeftTree->right;
    }
    //succ
 BinaryTreeNode<int>* RightTree=temp->right;
    while(RightTree != NULL){
        succ=RightTree->data;
        RightTree=RightTree->left;
    }
    return {pre,succ};
int main() {
  std::cout << "Hello World!\n";
}