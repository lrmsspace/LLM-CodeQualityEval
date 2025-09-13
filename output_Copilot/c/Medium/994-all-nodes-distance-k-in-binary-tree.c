/**https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/ */
//Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
//You can return the answer in any order.
// 
//Example 1:
//Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
//Output: [7,4,1]
//Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
//Example 2:
//Input: root = [1], target = 1, k = 3
//Output: []
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 500].
//	0 <= Node.val <= 500
//	All the values Node.val are unique.
//	target is the value of one of the nodes in the tree.
//	0 <= k <= 1000
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
int* distanceK(struct TreeNode* root, struct TreeNode* target, int k, int* returnSize) {
    // Helper function to build parent pointers
    void buildParentMap(struct TreeNode* node, struct TreeNode* parent, struct TreeNode** parentMap) {
        if (!node) return;
        parentMap[node->val] = parent;
        buildParentMap(node->left, node, parentMap);
        buildParentMap(node->right, node, parentMap);
    }

    // Helper function for DFS to find nodes at distance k
    void findNodesAtDistanceK(struct TreeNode* node, struct TreeNode** parentMap, int k, int* visited, int* result, int* index) {
        if (!node || visited[node->val]) return;
        visited[node->val] = 1;
        if (k == 0) {
            result[(*index)++] = node->val;
            return;
        }
        findNodesAtDistanceK(node->left, parentMap, k - 1, visited, result, index);
        findNodesAtDistanceK(node->right, parentMap, k - 1, visited, result, index);
        findNodesAtDistanceK(parentMap[node->val], parentMap, k - 1, visited, result, index);
    }

    // Initialize variables
    *returnSize = 0;
    if (!root || !target || k < 0) return NULL;
    struct TreeNode* parentMap[501] = {NULL};
    int visited[501] = {0};
    int* result = (int*)malloc(500 * sizeof(int));
    int index = 0;

    // Build parent pointers
    buildParentMap(root, NULL, parentMap);

    // Find nodes at distance k
    findNodesAtDistanceK(target, parentMap, k, visited, result, &index);

    *returnSize = index;
    return result;
}   