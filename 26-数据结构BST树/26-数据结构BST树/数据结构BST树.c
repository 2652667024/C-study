#include<stdio.h>
#include<stdlib.h>
typedef struct BSTtree {
	int data;
	struct BSTtree* left;
	struct BSTtree* right;

}BSTtree;

void insert(BSTtree** T, int data) {
	if (*T == NULL) {
		BSTtree* node = (BSTtree*)malloc(sizeof(BSTtree));
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		*T = node;
	}
	else {
		if ((*T)->data > data) {
			insert((&(*T)->left), data);

		}
		else {
			insert((&(*T)->right), data);
		
		}
	}
}
void midtree(BSTtree* T) {
	if (T == NULL) {
		return;
	}
	else
	{
		midtree(T->left);
		printf("%d ", T->data);
		midtree(T->right);
	}

}


int main()
{
	BSTtree* T = NULL;
	int data;
	for (int i = 0;i<10;i++)
	{
		printf("ÇëÊäÈëÊý×Ö:");
		scanf("%d", &data);
		insert(&T, data);
	}
	printf("\n");
	midtree(T);
	printf("\n");

	return 0;
}