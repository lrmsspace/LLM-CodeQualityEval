/**https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/ */
//You are given the root of a binary tree and a positive integer k.
//The level sum in the tree is the sum of the values of the nodes that are on the same level.
//Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
//Note that two nodes are on the same level if they have the same distance from the root.
// 
//Example 1:
//Input: root = [5,8,9,2,1,3,7,4,6], k = 2
//Output: 13
//Explanation: The level sums are the following:
//- Level 1: 5.
//- Level 2: 8 + 9 = 17.
//- Level 3: 2 + 1 + 3 + 7 = 13.
//- Level 4: 4 + 6 = 10.
//The 2nd largest level sum is 13.
//Example 2:
//Input: root = [1,2,null,3], k = 1
//Output: 3
//Explanation: The largest level sum is 3.
// 
//Constraints:
//	The number of nodes in the tree is n.
//	2 <= n <= 105
//	1 <= Node.val <= 106
//	1 <= k <= n
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
long long kthLargestLevelSum(struct TreeNode* root, int k) {
    if (!root) return -1;
    long long res = INT_MIN;
    struct TreeNode* cur = root;
    struct TreeNode* pre = NULL;
    struct TreeNode* tmp = NULL;
    int level = 0;
    int sum = 0;
    int max = 0;
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 10000);
    int front = 0;
    int rear = 0;
    queue[rear++] = cur;
    while (front < rear) {
        max = rear;
        sum = 0;
        for (int i = front; i < max; i++) {
            cur = queue[i];
            sum += cur->val;
            if (cur->left) queue[rear++] = cur->left;
            if (cur->right) queue[rear++] = cur->right;
        }
        front = max;
        if (sum > res) res = sum;
    }
    return res;    
}