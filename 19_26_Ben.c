#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int countNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeafNodes(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

void displayMenu()
{
    printf("\nBinary Search Tree Menu:\n");
    printf("1. Insert an element\n");
    printf("2. Search for an element\n");
    printf("3. Count total nodes\n");
    printf("4. Count leaf nodes\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    struct Node *root = NULL;
    int choice, data;

    while (1)
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Enter the element to search for: ");
            scanf("%d", &data);
            struct Node *result = search(root, data);
            if (result)
            {
                printf("%d found in the BST.\n", data);
            }
            else
            {
                printf("%d not found in the BST.\n", data);
            }
            break;
        case 3:
            printf("Total number of nodes: %d\n", countNodes(root));
            break;
        case 4:
            printf("Number of leaf nodes: %d\n", countLeafNodes(root));
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}