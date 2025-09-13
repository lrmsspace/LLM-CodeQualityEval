/*
 You are given the root of a binary tree and an integer k.
 Return an integer denoting the size of the kth largest perfect binary subtree, or -1 if it doesn't exist.
 A perfect binary tree is a tree where all leaves are on the same level, and every parent has two children.
 Example 1:
 Input: root = [5,3,6,5,2,5,7,1,8,null,null,6,8], k = 2
 Output: 3
 Explanation:
 The roots of the perfect binary subtrees are highlighted in black. Their sizes, in non-increasing order are [3, 3, 1, 1, 1, 1, 1, 1].
 The 2nd largest size is 3.
 Example 2:
 Input: root = [1,2,3,4,5,6,7], k = 1
 Output: 7
 Explanation:
 The sizes of the perfect binary subtrees in non-increasing order are [7, 3, 3, 1, 1, 1, 1]. The size of the largest perfect binary subtree is 7.
 Example 3:
 Input: root = [1,2,3,null,4], k = 3
 Output: -1
 Explanation:
 The sizes of the perfect binary subtrees in non-increasing order are [1, 1]. There are fewer than 3 perfect binary subtrees.
 Constraints:
 The number of nodes in the tree is in the range [1, 2000].
 1 <= Node.val <= 2000
 1 <= k <= 1024
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to check if a binary tree is perfect
bool isPerfect(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    
    int leftHeight = 0;
    int rightHeight = 0;
    
    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;
    
    while (left != NULL) {
        leftHeight++;
        left = left->left;
    }
    
    while (right != NULL) {
        rightHeight++;
        right = right->right;
    }
    
    return leftHeight == rightHeight;
}

// Function to perform depth-first search and find the kth largest perfect binary subtree size
int kthLargestPerfectSubtree(struct TreeNode* root, int k) {
    // Create a max-heap to store the sizes of perfect binary subtrees
    int* heap = (int*)malloc(sizeof(int) * k);
    int heapSize = 0;
    
    // Perform depth-first search
    dfs(root, heap, &heapSize, k);
    
    // If there are fewer than k perfect binary subtrees, return -1
    if (heapSize < k) {
        return -1;
    }
    
    // Return the kth largest perfect binary subtree size
    return heap[k - 1];
}

// Helper function for depth-first search
void dfs(struct TreeNode* root, int* heap, int* heapSize, int k) {
    if (root == NULL) {
        return;
    }
    
    // Check if the current node is a perfect binary subtree
    if (isPerfect(root)) {
        // If the heap is not full, add the size to the heap
        if (*heapSize < k) {
            heap[*heapSize] = root->val;
            (*heapSize)++;
            
            // Heapify the heap
            int index = *heapSize - 1;
            while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
                int temp = heap[(index - 1) / 2];
                heap[(index - 1) / 2] = heap[index];
                heap[index] = temp;
                index = (index - 1) / 2;
            }
        }
        // If the heap is full, check if the current size is larger than the smallest size in the heap
        else if (root->val > heap[0]) {
            heap[0] = root->val;
            
            // Heapify the heap
            int index = 0;
            while (true) {
                int leftChildIndex = 2 * index + 1;
                int rightChildIndex = 2 * index + 2;
                int largestIndex = index;
                
                if (leftChildIndex < *heapSize && heap[leftChildIndex] > heap[largestIndex]) {
                    largestIndex = leftChildIndex;
                }
                
                if (rightChildIndex < *heapSize && heap[rightChildIndex] > heap[largestIndex]) {
                    largestIndex = rightChildIndex;
                }
                
                if (largestIndex != index) {
                    int temp = heap[index];
                    heap[index] = heap[largestIndex];
                    heap[largestIndex] = temp;
                    index = largestIndex;
                } else {
                    break;
                }
            }
        }
    }
    
    // Recursively perform depth-first search on the left and right subtrees
    dfs(root->left, heap, heapSize, k);
    dfs(root->right, heap, heapSize, k);
}