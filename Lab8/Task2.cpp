//not complete task


#include <iostream>
struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int value){
        data=value;
        left=right=NULL;
        
    }
}
  

Node*insert(Node*root,int data){
    if(root==NULL){
        return new Node(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->right){
        root->right=insert(root->right,data);
    }
    return root;
}
Node*search(Node*root,int data){
    if(root=NULL || root->data=data){
        return root;
    }
    if(data<root->data){
        return search(root->left,data);
        
    }
    return search(root>right,data);
}
void inorder(Node*root){
  inorder(root->left);
 cout<<root->data<<" ";
 inorder(root->rigt);
}

void postorder(Node*root){
  postorder(root->left);
   postorder(root->rigt);
   cout<<root->data<<" ";

}
int main() {
  Node*rootNode=new Node(10);
  Node*song1=new Node(12);
  Node*song2=new Node(13);
  Node*song3=new Node(15);
  Node*song4=new Node(8);
  insert(rootNode,song1);
  insert(rootNode,song2);
  insert(rootNode,song3);
  insert(rootNode,song4);
  inorder(root);
  
    return 0;
}
