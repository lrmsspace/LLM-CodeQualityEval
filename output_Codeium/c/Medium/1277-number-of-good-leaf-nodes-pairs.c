/**https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/ */
//You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.
//Return the number of good leaf node pairs in the tree.
// 
//Example 1:
//Input: root = [1,2,3,null,4], distance = 3
//Output: 1
//Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
//Example 2:
//Input: root = [1,2,3,4,5,6,7], distance = 3
//Output: 2
//Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
//Example 3:
//Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
//Output: 1
//Explanation: The only good pair is [2,5].
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 210].
//	1 <= Node.val <= 100
//	1 <= distance <= 10
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* node, int distance, int dep[], int* res) {
    if (!node) return;
    if (!node->left && !node->right) {
        for (int i = 0; i < distance; i++) {
            (*res) += dep[i];
        }
        dep[distance]++;
        return;
    }
    int bak = dep[distance];
    dep[distance] = 0;
    dfs(node->left, distance, dep, res);
    dfs(node->right, distance, dep, res);
    dep[distance] = bak;
}
int countPairs(struct TreeNode* root, int distance) {
    if (!root) return 0;
    int res = 0;
    int dep[11] = {0};
    dfs(root, distance, dep, &res);
    return res;
}
    