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
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    struct TreeNode* queue[2001];
    int head = 0, tail = 0;
    queue[tail++] = root;
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2001);
    int** ret = (int**)malloc(sizeof(int*) * 2001);
    int zigzag = 1;
    while (head < tail) {
        (*returnColumnSizes)[*returnSize] = tail - head;
        ret[(*returnSize)++] = (int*)malloc(sizeof(int) * (tail - head));
        for (int i = head; i < tail; ++i) {
            ret[*returnSize - 1][zigzag ? (tail - i - 1) : (i - head)] = queue[i]->val;
            if (queue[i]->left)  queue[tail++] = queue[i]->left;
            if (queue[i]->right) queue[tail++] = queue[i]->right;
        }
        head = tail;
        zigzag ^= 1;
    }
    return ret;
}