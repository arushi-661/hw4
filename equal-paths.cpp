#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int pathHelper(Node *node); 

bool equalPaths(Node * root)
{
  return pathHelper(root) != -1; 
}

int pathHelper(Node *node){
  if (node == nullptr){
    return 0; 
  }

  if (node->left == nullptr && node->right == nullptr){
    return 1; // only node is h = 1
  }

  if (node->left == nullptr){
    int rH = pathHelper(node->right);
    if (rH == -1){
      return -1; 
    }
    return 1 + rH; 
  }

  if (node->right == nullptr){
    int lH = pathHelper(node->left);
    if (lH == -1){
      return -1; 
    }
    return 1 + lH; 
  }

  int L = pathHelper(node->left);
  int R = pathHelper(node->right); 
  if (L == -1 || R == -1){
    return -1; 
  }
  if (L != R){
    return -1; 
  }
  return 1 + L; 
}