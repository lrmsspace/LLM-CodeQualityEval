/**https://leetcode.com/problems/binary-tree-right-side-view/ */
//Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
// 
//Example 1:
//Input: root = [1,2,3,null,5,null,4]
//Output: [1,3,4]
//Example 2:
//Input: root = [1,null,3]
//Output: [1,3]
//Example 3:
//Input: root = []
//Output: []
// 
//Constraints:
//	The number of nodes in the tree is in the range [0, 100].
//	-100 <= Node.val <= 100
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
int* rightSideView(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if(!root) return NULL;
    int *res = malloc(sizeof(int) * 100);
    struct TreeNode **queue = malloc(sizeof(struct TreeNode *) * 100);
    queue[0] = root;
    int head = 0, tail = 1;
    while(head < tail){
        struct TreeNode *node = queue[head++];
        if(node->left) queue[tail++] = node->left;
        if(node->right) queue[tail++] = node->right;
    }
    for(int i = 0; i < tail; i++){
        res[i] = queue[i]->val;
    }
    *returnSize = tail;
    return res;
}