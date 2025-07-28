//4. K-th Largest Element in an Array
//Description: Find the k-th largest element using recursive partitioning
//Input:[3,2,1,5,,6,4], k=2
//Output: 5

#include <iostream>
using namespace std;

// BST Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Insert into BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);
    
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Reverse Inorder Traversal to find kth largest
void kthLargestUtil(Node* root, int k, int &count, int &result) {
    if (root == NULL || count >= k)
        return;

    // Traverse right subtree first
    kthLargestUtil(root->right, k, count, result);

    count++;
    if (count == k) {
        result = root->data;
        return;
    }

    // Then traverse left
    kthLargestUtil(root->left, k, count, result);
}

int findKthLargest(int arr[], int n, int k) {
    Node* root = NULL;

    // Build BST
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    int count = 0, result = -1;
    kthLargestUtil(root, k, count, result);
    return result;
}

// Main
int main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Kth largest element is: " << findKthLargest(arr, n, k);
    return 0;
}
