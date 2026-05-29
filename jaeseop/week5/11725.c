#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef struct TreeNode {
	int data;
	struct TreeNode* next;
}TreeNode;

TreeNode* tree[MAX_SIZE];
int parent[MAX_SIZE];
int visited[MAX_SIZE];

void addEdge(int from, int to) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));

	newNode->data = to;
	newNode->next = tree[from];
	tree[from] = newNode;
}

void findParent(int current) {
	visited[current] = 1;

	TreeNode* temp = tree[current];

	while (temp != NULL) {
		int next = temp->data;

		if (visited[next] == 0) {
			parent[next] = current;
			findParent(next);
		}

		temp = temp->next;
	}
}

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		addEdge(a, b);
		addEdge(b, a);
	}

	findParent(1);

	for (int i = 2; i <= N; i++) {
		printf("%d\n", parent[i]);
	}

	return 0;
}