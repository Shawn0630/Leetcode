#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

typedef struct {
	char *key;
	int data;
} Node;

typedef struct {
	Node *tree_nodes; 
	unsigned char *is_free;
	int size;
} BStree_struct;
typedef BStree_struct* BStree;

// Input: ’node’: a node
// Effect: node.key is printed and then the node.data is printed
void printNode(Node node) {
	printf("Node.key = %s Node.data = %d\n", node.key, node.data);
}

char *key_dup(char *key) {
	char *dst;
	strcpy(dst, key);
	return dst;
}

BStree bstree_ini(int size) {
	BStree bst = new BStree_struct();
	bst->size = size;
	bst->tree_nodes = (Node*) malloc((bst->size + 1));
	bst->is_free = (unsigned char*) malloc((bst->size + 1));
	for(int i = 1; i <= bst->size; i++) {
		bst->is_free[i] = '1';
	}
	return bst;
}

void bstree_insert(BStree bst, char *key, int data) {
	int index = 1;
	Node node;
	node.key = key;
	node.data = data;

	while(bst->is_free[index] == '0') {
		printf("Comparing %s and %s the result is %d\n", key, bst->tree_nodes[index].key, strcmp(key, bst->tree_nodes[index].key));
		if(strcmp(bst->tree_nodes[index].key, key) == 0) return;
		else if(strcmp(key, bst->tree_nodes[index].key) < 0) {
			index = 2 * index;
		} else {
			index = 2 * index + 1;
		}
		if(index > bst->size) exit(1);
	}
	bst->tree_nodes[index] = node;
	bst->is_free[index] = '0';
	printf("Insert node.key = %s, node.data = %d into %d\n", node.key, node.data, index);
}

int left_child(int index) {
	return 2 * index;
}

int right_child(int index) {
	return 2 * index + 1;
}

int parent(int index) {
	return index / 2;
}

void bstree_dfs_traversal(BStree bst, int index) {
//	if(left_child(index) <= bst->size && 
//		right_child(index) <= bst->size && 
//		bst->is_free[left_child(index)] == '1'  && 
//		bst->is_free[right_child(index)] == '1') {
//		printf("The index is %d ", index);
//		printNode(bst->tree_nodes[index]);
//		return;
//	}
	if(left_child(index) <= bst->size && bst->is_free[left_child(index)] == '0') {
		bstree_dfs_traversal(bst, left_child(index));
	}
	printf("The index is %d ", index);
	printNode(bst->tree_nodes[index]);
	if(right_child(index) <= bst->size && bst->is_free[right_child(index)] == '0') {
		bstree_dfs_traversal(bst, right_child(index));
	}
	return;
}

void bstree_traversal(BStree bst) {
	bstree_dfs_traversal(bst, 1);
}

int main() {
//	char str1[] = "Hello World";
//	char *str2 = key_dup(str1);
//	str1[1] = 'a';
//	printf("The str1 is %s\n", str1);
//	printf("The duplication of str1 is %s\n", str2);
	BStree bst;
	bst = bstree_ini(1000);
	bstree_insert(bst, "Once", 1);
	bstree_insert(bst, "Upon", 22);
	bstree_insert(bst, "a", 3);
	bstree_insert(bst, "Time", 4);
	bstree_insert(bst, "is", 5);
	bstree_insert(bst, "filmed", 6);
	bstree_insert(bst, "in", 7);
	bstree_insert(bst, "Vancouver", 8);
	bstree_insert(bst, "!", 99);
	bstree_traversal(bst);
	system("pause");
}