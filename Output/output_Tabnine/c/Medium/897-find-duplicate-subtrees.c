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
struct TreeNode** findDuplicateSubtrees(struct TreeNode* root, int* returnSize) {
    // Create a hash map to store the serialized trees and their roots
    int* map = (int*)calloc(100000, sizeof(int));
    // Create a list to store the duplicate subtrees
    struct TreeNode** result = (struct TreeNode**)calloc(100000, sizeof(struct TreeNode*));
    *returnSize = 0;
    
    // Recursive function to serialize and count the duplicate subtrees
    void dfs(struct TreeNode* node, char* str, int* count) {
        if (!node) {
            str[0] = '\0';
            return;
        }
        
        // Serialize the tree using pre-order traversal
        sprintf(str, "%d,%d,%d", node->val, dfs(node->left, str + strlen(str), count), dfs(node->right, str + strlen(str), count));
        
        // Increment the count for the serialized tree
        int index = atoi(str);
        if (map[index] == 0) {
            map[index] = 1;
        } else {
            (*count)++;
            result[*returnSize] = node;
            (*returnSize)++;
        }
    }
    
    // Call the recursive function to find duplicate subtrees
    dfs(root, "", returnSize);
    
    // Free the hash map
    free(map);
    
    return result;
    
}