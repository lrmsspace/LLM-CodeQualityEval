/**https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/ */
//Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
// 
//Example 1:
//Input: root = [3,9,20,null,null,15,7]
//Output: [[3],[20,9],[15,7]]
//Example 2:
//Input: root = [1]
//Output: [[1]]
//Example 3:
//Input: root = []
//Output: []
// 
//Constraints:
//	The number of nodes in the tree is in the range [0, 2000].
//	-100 <= Node.val <= 100
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    int** res = (int**)malloc(sizeof(int*) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    int size = 0;
    struct TreeNode* queue[1000];
    int head = 0, tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        int len = tail - head;
        int* tmp = (int*)malloc(sizeof(int) * len);
        for (int i = 0; i < len; i++) {
            tmp[i] = queue[head]->val;
            if (queue[head]->left) {
                queue[tail++] = queue[head]->left;
            }
            if (queue[head]->right){
                queue[tail++] = queue[head]->right;
            }
        }
    }
    for (int i = 0; i < tail; i++) {
        res[size] = tmp;
        (*returnColumnSizes)[size++] = len;
    }
    *returnSize = size;
    return res;
}