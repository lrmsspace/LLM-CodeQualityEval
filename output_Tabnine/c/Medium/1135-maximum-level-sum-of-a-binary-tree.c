/**https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/ */
//Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
//Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
// 
//Example 1:
//Input: root = [1,7,0,7,-8,null,null]
//Output: 2
//Explanation: 
//Level 1 sum = 1.
//Level 2 sum = 7 + 0 = 7.
//Level 3 sum = 7 + -8 = -1.
//So we return the level with the maximum sum which is level 2.
//Example 2:
//Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
//Output: 2
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 104].
//	-105 <= Node.val <= 105
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxLevelSum(struct TreeNode* root) {
    if (!root) return 0;
    
    int maxSum = INT_MIN, maxLevel = 0;
    struct TreeNode* queue[10000];
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        int levelSum = 0, levelSize = rear - front;
        for (int i = 0; i < levelSize; ++i) {
            struct TreeNode* node = queue[front++];
            levelSum += node->val;
            
            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        
        if (levelSum > maxSum) {
            maxSum = levelSum;
            maxLevel = levelSize;
        }
    }
    
    return maxLevel;
    
}