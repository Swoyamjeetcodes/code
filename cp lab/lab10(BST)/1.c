//wap to create bst of n node data elements using linked list and perform the following operations 
// i.preorder ii.post order iii.inorder iv.search an element 
#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Insert a node
struct node *insert(struct node *node, int key) 
{
  if (node == NULL) return newNode(key);
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}
// Inorder Traversal
void inorder(struct node *root) 
{
  if (root != NULL) 
  {
    inorder(root->left);
    printf("%d -> ", root->key);
    inorder(root->right);
  }
}
void preorder(struct node* root)  
{  
    if (root == NULL)  
    {
        return;  
    }
    printf(" %d ", root->key);  
    preorder(root->left);  
    preorder(root->right);  
}  
void postorder(struct node* root)  
{  
    if (root == NULL)  
    {
        return;  
    } 
    postorder(root->left);  
    postorder(root->right);  
    printf(" %d ", root->key);  
}  
void search (Node* root, int key) 
{
    if (root == NULL || root->key == key)
    {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}