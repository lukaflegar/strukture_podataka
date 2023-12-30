#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}


void replace(Node* root) {
    if (root == NULL) {
        return;
    }

    replace(root->left);
    replace(root->right);

    
    int leftSum = (root->left != NULL) ? root->left->data : 0;
    int rightSum = (root->right != NULL) ? root->right->data : 0;
    root->data += leftSum + rightSum;
}


void inorderToFile(Node* root, FILE* file) {
    if (root != NULL) {
        inorderToFile(root->left, file);
        fprintf(file, "%d ", root->data);
        inorderToFile(root->right, file);
    }
}

int main() {
    
    Node* root = NULL;

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int randomNum = rand() % 81 + 10; 
        root = insert(root, randomNum);
    }

    FILE* beforeReplaceFile = fopen("before_replace.txt", "w");
    if (beforeReplaceFile == NULL) {
        fprintf(stderr, "Nemoguæe otvoriti datoteku before_replace.txt\n");
        return 1;
    }

    inorderToFile(root, beforeReplaceFile);

    fclose(beforeReplaceFile);

    replace(root);

    FILE* afterReplaceFile = fopen("after_replace.txt", "w");
    if (afterReplaceFile == NULL) {
        fprintf(stderr, "Nemoguæe otvoriti datoteku after_replace.txt\n");
        return 1;
    }

    inorderToFile(root, afterReplaceFile);

    fclose(afterReplaceFile);

    return 0;
}
