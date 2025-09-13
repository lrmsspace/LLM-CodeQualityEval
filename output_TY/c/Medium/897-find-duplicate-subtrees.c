/**https://leetcode.com/problems/find-duplicate-subtrees/ */
//Given the root of a binary tree, return all duplicate subtrees.
//For each kind of duplicate subtrees, you only need to return the root node of any one of them.
//Two trees are duplicate if they have the same structure with the same node values.
// 
//Example 1:
//Input: root = [1,2,3,4,null,2,4,null,null,4]
//Output: [[2,4],[4]]
//Example 2:
//Input: root = [2,1,1]
//Output: [[1]]
//Example 3:
//Input: root = [2,2,2,3,null,3,null]
//Output: [[2,3],[3]]
// 
//Constraints:
//	The number of the nodes in the tree will be in the range [1, 5000]
//	-200 <= Node.val <= 200
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
struct TreeNode** findDuplicateSubtrees(struct TreeNode* root, int* returnSize){
    int i,j;
    int cnt[100000] = {0};
    struct TreeNode** ans = malloc(sizeof(struct TreeNode*) * 100000);
    *returnSize = 0;
    if(root == NULL) return ans;
    int id = 0;
    int* id_map = malloc(sizeof(int) * 100000);
    struct TreeNode** tree = malloc(sizeof(struct TreeNode*) * 100000);
    for(i = 0; i < 100000; i++) id_map[i] = -1;
    tree[id] = root;
    for(i = 0; i <= id; i++){
        struct TreeNode* node = tree[i];
        int left = -1, right = -1;
        if(node->left != NULL){
            left = id + 1;
            tree[left] = node->left;
        }
        if(node->right != NULL){
            right = id + 2;
            tree[right] = node->right;
        }
    }
    return dfs(root);

}