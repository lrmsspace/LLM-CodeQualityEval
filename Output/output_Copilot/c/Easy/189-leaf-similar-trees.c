/**https://leetcode.com/problems/leaf-similar-trees/ */
//Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
//For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
//Two binary trees are considered leaf-similar if their leaf value sequence is the same.
//Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
// 
//Example 1:
//Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
//Output: true
//Example 2:
//Input: root1 = [1,2,3], root2 = [1,3,2]
//Output: false
// 
//Constraints:
//	The number of nodes in each tree will be in the range [1, 200].
//	Both of the given trees will have values in the range [0, 200].
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int *leaf1 = (int *)malloc(sizeof(int) * 100);
    int *leaf2 = (int *)malloc(sizeof(int) * 100);
    int len1 = 0, len2 = 0;
    dfs(root1, leaf1, &len1);
    dfs(root2, leaf2, &len2);
    if (len1 != len2) {
        return false;
    }
    for (int i = 0; i < len1; i++) {
        if (leaf1[i] != leaf2[i]) {
            return false;
        }
    }
    return true;    
}