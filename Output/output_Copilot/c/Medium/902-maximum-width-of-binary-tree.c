/**https://leetcode.com/problems/maximum-width-of-binary-tree/ */
//Given the root of a binary tree, return the maximum width of the given tree.
//The maximum width of a tree is the maximum width among all levels.
//The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
//It is guaranteed that the answer will in the range of a 32-bit signed integer.
// 
//Example 1:
//Input: root = [1,3,2,5,3,null,9]
//Output: 4
//Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
//Example 2:
//Input: root = [1,3,2,5,null,null,9,6,null,7]
//Output: 7
//Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
//Example 3:
//Input: root = [1,3,2,5]
//Output: 2
//Explanation: The maximum width exists in the second level with length 2 (3,2).
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 3000].
//	-100 <= Node.val <= 100
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int widthOfBinaryTree(struct TreeNode* root) {
    int max = 0;
    struct TreeNode *q[3000];
    int qSize = 0;
    int qFront = 0;
    int qRear = 0;
    int qLevel[3000];
    int qLevelSize = 0;
    int qLevelFront = 0;
    int qLevelRear = 0;
    q[qRear++] = root;
    qSize++;
    qLevel[qLevelRear++] = 1;
    qLevelSize++;
    while(qSize > 0) {
        int size = qSize;
        int left = qLevel[qLevelFront];
        int right = qLevel[qLevelRear - 1];
        for(int i = 0; i < size; i++) {
            struct TreeNode *node = q[qFront++];
            qSize--;
            int level = qLevel[qLevelFront++];
            if(node->left) {
                q[qRear++] = node->left;
                qSize++;
                qLevel[qLevelRear++] = 2 * level;
            }
            if(node->right) {
                q[qRear++] = node->right;
                qSize++;
                qLevel[qLevelRear++] = 2 * level + 1;
            }
        }
        max = fmax(max, right - left + 1);
    }
    return max;   
}