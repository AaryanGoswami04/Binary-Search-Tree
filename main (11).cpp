#include <iostream>
bool search(Node* root, int x) {
    //base case
    if(root==NULL)
       return false;
     if(root->data == x)
        return true;
    if(root->data > x)
    return search(root->left, x);
    else
      return search(root->right, x);
}
int main() {
  std::cout << "Hello World!\n";
}