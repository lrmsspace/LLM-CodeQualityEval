/**https://leetcode.com/problems/binary-tree-right-side-view/ */
//Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
// 
//Example 1:
//Input: root = [1,2,3,null,5,null,4]
//Output: [1,3,4]
//Explanation:
//Example 2:
//Input: root = [1,2,3,4,null,null,null,5]
//Output: [1,3,4,5]
//Explanation:
//Example 3:
//Input: root = [1,null,3]
//Output: [1,3]
//Example 4:
//Input: root = []
//Output: []
// 
//Constraints:
//	The number of nodes in the tree is in the range [0, 100].
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int *ans = (int *)malloc(sizeof(int) * 101);
    int level[101] = {0};
    int q[101] = {0};
    int front = 0, rear = 0;

    q[rear++] = root;
    level[root->val] = 1;

    while (front < rear) {
        struct TreeNode *node = q[front++];
        ans[level[node->val] - 1] = node->val;

        if (node->left) {
            q[rear++] = node->left;
            level[node->left->val] = level[node->val] + 1;
        }
        if (node->right) {
            q[rear++] = node->right;
            level[node->right->val] = level[node->val] + 1;
        }
    }

    *returnSize = rear;
    return ans;
}