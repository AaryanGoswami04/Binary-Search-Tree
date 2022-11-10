#include <iostream>
#include <queue>
using namespace std;
//Worst case time complexity of insertion: O(N)
class Node{
public:
     int data;
      Node* left;
      Node* right;
      Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
      }
};
Node* InsertIntoBST(Node*root, int d){
  //base case
  if(!root){
    root=new Node(d);
    return root;
  }
  if(d> root->data)
    root->right = InsertIntoBST(root->right,d);
  else
     root->left = InsertIntoBST(root->left,d);
  return root;
}

void inorder(Node*root){
  if(root==NULL)
    return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void TakeInput(Node* &root){
  int data;
  cin>>data;

  while(data!=-1){
    root = InsertIntoBST(root, data);
    cin>>data;
  }
}
int main() {
  Node* root=NULL;
  cout<<"Enter data into BST"<<endl;
  TakeInput(root);
  cout<<"printing BST:"<<endl;
  inorder(root);
}
