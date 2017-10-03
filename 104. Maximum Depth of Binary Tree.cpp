#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

//#define INT_MAX 0x7fffffff
//#define INT_MIN 0x80000000


using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

int maxDepth(TreeNode* root) {
 	 int left_subtree_maxDepth = 0;
 	 int right_subtree_maxDepth = 0;
 	 int subtree_maxDepth = 0;
 	 if(root == NULL) {
 	 	return 0;
 	 }
     if(root -> left == NULL && root -> right == NULL) {
     	return 1;
     }
     if(root -> left != NULL) {
     	left_subtree_maxDepth = maxDepth(root->left);
     }
     if(root -> right != NULL) {
     	right_subtree_maxDepth = maxDepth(root->right);
     }
     subtree_maxDepth = left_subtree_maxDepth > right_subtree_maxDepth ? left_subtree_maxDepth:right_subtree_maxDepth;
     return subtree_maxDepth + 1;
}

int minDepth(TreeNode* root) {
    int left_subtree_minDepth = INT_MAX;
    int right_subtree_minDepth = INT_MAX;
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    if(root->left != NULL) {
      left_subtree_minDepth = minDepth(root->left);
    }
    if(root->right != NULL) {
      right_subtree_minDepth = minDepth(root->right);
    }
    return left_subtree_minDepth > right_subtree_minDepth? right_subtree_minDepth + 1 : left_subtree_minDepth + 1; 
}

bool isBalanced(TreeNode* root) {
	int left_subtree_Depth = 0;
	int right_subtree_Depth = 0;
	if(root == NULL) {
		return true;
	}
	if(root->left != NULL) {
		left_subtree_Depth = maxDepth(root->left);
	}
  if(root->right != NULL) {
    right_subtree_Depth = maxDepth(root->right);
  }
  if (abs(left_subtree_Depth - right_subtree_Depth) > 1) return false;
  if(!(isBalanced(root->left) && isBalanced(root->right))) return false;//miss at the first time
  return true;
}

int main() {
 	TreeNode* root = new TreeNode(1);
 	TreeNode* tn1 = new TreeNode(2);
 	TreeNode* tn2 = new TreeNode(3);
 	TreeNode* tn3 = new TreeNode(4);
 	TreeNode* tn4 = new TreeNode(5);
 	TreeNode* tn5 = new TreeNode(6);
 	TreeNode* tn6 = new TreeNode(7);
 	root->left = tn1;
// 	root->right = tn2;
// 	tn2->left = tn3;
// 	tn2->right = tn4;
// 	tn3->left = tn5;
// 	tn4->right = tn6;
 	cout << "The maxDepth is " << maxDepth(root) << endl;
  cout << "The minDepth is " << minDepth(root) << endl;
 	cout << "isBalanced " << isBalanced(root) << endl;
 }