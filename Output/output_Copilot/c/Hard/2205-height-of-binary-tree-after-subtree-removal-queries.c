/**https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/ */
//You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.
//You have to perform m independent queries on the tree where in the ith query you do the following:
//	Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
//Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.
//Note:
//	The queries are independent, so the tree returns to its initial state after each query.
//	The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.
// 
//Example 1:
//Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
//Output: [2]
//Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
//The height of the tree is 2 (The path 1 -> 3 -> 2).
//Example 2:
//Input: root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
//Output: [3,2,3,2]
//Explanation: We have the following queries:
//- Removing the subtree rooted at node with value 3. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 4).
//- Removing the subtree rooted at node with value 2. The height of the tree becomes 2 (The path 5 -> 8 -> 1).
//- Removing the subtree rooted at node with value 4. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 6).
//- Removing the subtree rooted at node with value 8. The height of the tree becomes 2 (The path 5 -> 9 -> 3).
// 
//Constraints:
//	The number of nodes in the tree is n.
//	2 <= n <= 105
//	1 <= Node.val <= n
//	All the values in the tree are unique.
//	m == queries.length
//	1 <= m <= min(n, 104)
//	1 <= queries[i] <= n
//	queries[i] != root.val
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
int* treeQueries(struct TreeNode* root, int* queries, int queriesSize, int* returnSize) {
    int* answer = (int*)malloc(sizeof(int) * queriesSize);
    int* height = (int*)malloc(sizeof(int) * 100001);
    memset(height, 0, sizeof(int) * 100001);
    int* parent = (int*)malloc(sizeof(int) * 100001);
    memset(parent, 0, sizeof(int) * 100001);
    int* left = (int*)malloc(sizeof(int) * 100001);
    memset(left, 0, sizeof(int) * 100001);
    int* right = (int*)malloc(sizeof(int) * 100001);
    memset(right, 0, sizeof(int) * 100001);
    int* size = (int*)malloc(sizeof(int) * 100001);
    memset(size, 0, sizeof(int) * 100001);
    int* idx = (int*)malloc(sizeof(int) * 100001);
    for (int i = 0; i < 100001; i++) {
        idx[i] = i;
    }
    qsort(idx, 100001, sizeof(int), cmp);
    int* find = (int*)malloc(sizeof(int) * 100001);
    for (int i = 0; i < 100001; i++) {
        find[i] = i;
    }
    int* rank = (int*)malloc(sizeof(int) * 100001);
    memset(rank, 0, sizeof(int) * 100001);
    int* mst = (int*)malloc(sizeof(int) * 100001);
    int* mstIdx = (int*)malloc(sizeof(int) * 100001);
    int* mstSize = (int*)malloc(sizeof(int) * 100001);
    for (int i = 0; i < 100001; i++) {
        mstSize[i] = 1;
    }
    int* mstRank = (int*)malloc(sizeof(int) * 100001);
    memset(mstRank, 0, sizeof(int) * 100001);
    int* mstParent = (int*)malloc(sizeof(int) * 100001);
    for (int i = 0; i < 100001; i++) {
        mstParent[i] = i;
    }
    int* mstLeft = (int*)malloc(sizeof(int) * 100001);
    memset(mstLeft, 0, sizeof(int) * 100001);
    int* mstRight = (int*)malloc(sizeof(int) * 100001);
    memset(mstRight, 0, sizeof(int) * 100001);

    // Function to calculate the height of the tree
    void calculateHeight(struct TreeNode* node, int depth) {
        if (!node) return;
        height[node->val] = depth;
        if (node->left) {
            parent[node->left->val] = node->val;
            left[node->val] = node->left->val;
            calculateHeight(node->left, depth + 1);
        }
        if (node->right) {
            parent[node->right->val] = node->val;
            right[node->val] = node->right->val;
            calculateHeight(node->right, depth + 1);
        }
    }

    // Initialize the height and parent arrays
    calculateHeight(root, 0);

    // Process each query
    for (int i = 0; i < queriesSize; i++) {
        int queryNode = queries[i];
        int originalParent = parent[queryNode];
        int originalHeight = height[originalParent];

        // Temporarily remove the subtree
        if (left[originalParent] == queryNode) {
            left[originalParent] = 0;
        } else if (right[originalParent] == queryNode) {
            right[originalParent] = 0;
        }

        // Recalculate the height of the tree
        memset(size, 0, sizeof(int) * 100001);
        calculateHeight(root, 0);

        // Store the result
        answer[i] = height[root->val];

        // Restore the subtree
        if (left[originalParent] == 0) {
            left[originalParent] = queryNode;
        } else if (right[originalParent] == 0) {
            right[originalParent] = queryNode;
        }
    }

    *returnSize = queriesSize;
    free(height);
    free(parent);
    free(left);
    free(right);
    free(size);
    free(idx);
    free(find);
    free(rank);
    free(mst);
    free(mstIdx);
    free(mstSize);
    free(mstRank);
    free(mstParent);
    free(mstLeft);
    free(mstRight);
    return answer;  
}