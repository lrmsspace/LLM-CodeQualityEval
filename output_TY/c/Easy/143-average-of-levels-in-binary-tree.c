/**https://leetcode.com/problems/average-of-levels-in-binary-tree/ */
//Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
// 
//Example 1:
//Input: root = [3,9,20,null,null,15,7]
//Output: [3.00000,14.50000,11.00000]
//Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
//Hence return [3, 14.5, 11].
//Example 2:
//Input: root = [3,9,20,15,7]
//Output: [3.00000,14.50000,11.00000]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	-231 <= Node.val <= 231 - 1
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
double* averageOfLevels(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    Queue *queue = createQueue();
    enqueue(queue, root);

    double *result = (double*)malloc(1000 * sizeof(double)); // 假设最多有 1000 层
    int resultSize = 0;

    while (!isEmpty(queue)) {
        int levelSize = 0;
        double levelSum = 0.0;

        Queue *levelQueue = createQueue();
        while (!isEmpty(queue)) {
            struct TreeNode *node = dequeue(queue);
            levelSum += node->val;
            levelSize++;

            if (node->left != NULL) {
                enqueue(levelQueue, node->left);
            }
            if (node->right != NULL) {
                enqueue(levelQueue, node->right);
            }
        }

        double levelAverage = levelSum / levelSize;
        result[resultSize++] = levelAverage;

        // 将下一层的节点重新入队
        while (!isEmpty(levelQueue)) {
            enqueue(queue, dequeue(levelQueue));
        }

        freeQueue(levelQueue);
    }

    freeQueue(queue);
    *returnSize = resultSize;
    return result;
}