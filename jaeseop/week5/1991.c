#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	char data;
	struct TreeNode* left, * right;
}TreeNode;

//       A
//   B      C
// D      E   F
//              G
TreeNode n1 = { 'G', NULL, NULL };
TreeNode n2 = { 'F', NULL, &n1 };
TreeNode n3 =  { 'E', NULL, NULL };
TreeNode n4 = { 'D', NULL, NULL};
TreeNode n5 = { 'C', &n3, &n2 };
TreeNode n6 = { 'B', & n4, NULL };
TreeNode n7 = { 'A', & n6, & n5 };
TreeNode* root = &n7; // root 초기값을 n1노드로 설정

// 전위 순회
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

// 중위 순회
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

// 후위 순회
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
}

int main(void) {
	printf("전위 순회한 결과: ");
	preorder(root);
	printf("\n중위 순회한 결과: ");
	inorder(root);
	printf("\n후위 순회한 결과: ");
	postorder(root);

	return 0;
}