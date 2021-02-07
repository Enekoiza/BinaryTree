//In order to not get error implementing the scanf we will add this line which will avoid these type of warnings
#define _CRT_SECURE_NO_WARNINGS
//The scanf is implemented in this library
#include <stdio.h>
//The malloc is implemented in this library
#include <stdlib.h>

//This is going to be the main structure with two branches right and left
typedef struct _BinaryTreeNode
{
	int value;
	struct _BinaryTreeNode* left; 
	struct _BinaryTreeNode* right; 
} BinaryTreeNode;

//This BinaryTree will work with these values using the first value as the root
int values[14] = {55,33,42,67,12,9,53,85,91,18,4,26,71};

//Declaration of a function that we will use to free the memory allocated
//from the very end until the beginning so we don't generate any memory leek
void release(struct _BinaryTreeNode* p);


int main()
{	
    //Two structures will be created
    //root will be used as a reference "the top of the tree"
    //current will be moved through the tree until we find the location where we need to put the new node
	struct _BinaryTreeNode *root, *current;

    //Since it is a pointer it needs to point to something so it will be pointing to NULL until the value is asigned
	root = NULL;
    for (int j = 0 ; j < 14; j++)
	{
        //The root will only be defined once
		if (root == NULL)
		{
            //root will be memory allocated with the size of the structure, the branches are also pointer so we need to point them to NULL.
			root = malloc(sizeof(struct _BinaryTreeNode));
			root->value = values[j];
			root->left = NULL;
			root ->right = NULL;
			continue;
		}
		//Pointing current to the top of the tree being able to move in the two directions if necessary
		current = root;

        //This infinite loop will finish when we reach the bottom of the tree
		while (1)
			if (values[j] > current->value)
			{
				if (current->right == NULL)
				{
					current->right = malloc(sizeof(struct _BinaryTreeNode));
					current->right->value = values[j];
					current->right->left = NULL;
					current->right->right = NULL;
					break;
				}
				else
				{
					current = current->right;
					continue;
				}
			}
		else
		{
				if (current->left == NULL)
				{
					current->left = malloc(sizeof(struct _BinaryTreeNode));
					current->left->value = values[j];
					current->left->left = NULL;
					current->left->right = NULL;
					break;
				}
				else
				{
					current = current->left;
					continue;
				}
		}
		
	}
    //To search the value we again need to put the current pointer pointing to the top of the tree which is the root
	current = root;
	int SearchID = 0;
	printf("Please type the number you are looking for inside the tree:\n");
	scanf("%d", &SearchID);
	
	
	while (1)
	{
		if (SearchID == current->value)
		{
			printf("The number you typed has been found\n");
			break;
		}
		else if (SearchID > current->value)
		{
			current = current->right;
			printf("The pointer in the tree moved to the right\n");
		}
		else
		{
			current = current->left;
			printf("The pointer in the tree moved to the left\n");
			
		}
	}

    //The last step before finishing the program is to free the memory location
    //used to create the nodes.
	release(root);
	return 0;
}

//This will go until both branches are NULL and will free that memory
//It goes in a recursion way.
void release(struct _BinaryTreeNode* p)
{
	if (p->left != NULL)
		release(p->left);
	if (p->right != NULL)
		release(p->right);
	free(p);

}