/**https://leetcode.com/problems/print-binary-tree/ */
//Given the root of a binary tree, construct a 0-indexed m x n string matrix res that represents a formatted layout of the tree. The formatted layout matrix should be constructed using the following rules:
//	The height of the tree is height and the number of rows m should be equal to height + 1.
//	The number of columns n should be equal to 2height+1 - 1.
//	Place the root node in the middle of the top row (more formally, at location res[0][(n-1)/2]).
//	For each node that has been placed in the matrix at position res[r][c], place its left child at res[r+1][c-2height-r-1] and its right child at res[r+1][c+2height-r-1].
//	Continue this process until all the nodes in the tree have been placed.
//	Any empty cells should contain the empty string "".
//Return the constructed matrix res.
// 
//Example 1:
//Input: root = [1,2]
//Output: 
//[["","1",""],
// ["2","",""]]
//Example 2:
//Input: root = [1,2,3,null,4]
//Output: 
//[["","","","1","","",""],
// ["","2","","","","3",""],
// ["","","4","","","",""]]
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 210].
//	-99 <= Node.val <= 99
//	The depth of the tree will be in the range [1, 10].
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** printTree(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    *returnSize = 1;
    *returnColumnSizes = (int*)malloc(sizeof(int));
    (*returnColumnSizes)[0] = 1;
    char*** result = (char***)malloc(sizeof(char**));
    result[0] = (char**)malloc(sizeof(char*));
    result[0][0] = (char*)malloc(sizeof(char));
    result[0][0][0] = '\0';
    queue<struct TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                (*returnSize)++;
                (*returnColumnSizes) = (int*)realloc(*returnColumnSizes, sizeof(int) * (*returnSize));
                (*returnColumnSizes)[*returnSize - 1] = (*returnColumnSizes)[*returnSize - 2] * 2 + 1;
                result = (char***)realloc(result, sizeof(char**) * (*returnSize));
                result[*returnSize - 1] = (char**)malloc(sizeof(char*) * (*returnColumnSizes)[*returnSize - 1]);
                for (int j = 0; j < (*returnColumnSizes)[*returnSize - 1]; j++) {
                    result[*returnSize - 1][j] = (char*)malloc(sizeof(char));
                    result[*returnSize - 1][j][0] = '\0';
                }
                for (int j = 0; j < (*returnColumnSizes)[*returnSize - 2]; j++) {
                    result[*returnSize - 1][j * 2 + 1] = result[*returnSize - 2][j];
                }
                result[*returnSize - 1][(*returnColumnSizes)[*returnSize - 2] * 2] = (char*)malloc(sizeof(char));
                result[*returnSize - 1][(*returnColumnSizes)[*returnSize - 2] * 2][0] = '\0';
            }
            if (node->right) {
                q.push(node->right);
                (*returnSize)++;
                (*returnColumnSizes) = (int*)realloc(*returnColumnSizes, sizeof(int) * (*returnSize));
                (*returnColumnSizes)[*returnSize - 1] = (*returnColumnSizes)[*returnSize - 2] * 2 + 1;
                result = (char***)realloc(result, sizeof(char**) * (*returnSize));
                result[*returnSize - 1] = (char**)malloc(sizeof(char*) * (*returnColumnSizes)[*returnSize - 1]);
                for (int j = 0; j < (*returnColumnSizes)[*returnSize - 1]; j++) {
                    result[*returnSize - 1][j] = (char*)malloc(sizeof(char));
                    result[*returnSize - 1][j][0] = '\0';
                }
                for (int j = 0; j < (*returnColumnSizes)[*returnSize - 2]; j++) {
                    result[*returnSize - 1][j * 2 + 1] = result[*returnSize - 2][j];
                }
                result[*returnSize - 1][(*returnColumnSizes)[*returnSize - 2] * 2] = (char*)malloc(sizeof(char));
                result[*returnSize - 1][(*returnColumnSizes)[*returnSize - 2] * 2][0] = '\0';
            }
            if (node->left) {
                result[*returnSize - 1][(*returnColumnSizes)[*returnSize - 2] * 2 - 1] = (char*)malloc(sizeof(char));
                result[*returnSize - 1][(*returnColumnSizes)[*returnSize - 2] * 2 - 1][0] = '\0';
                sprintf(result[*returnSize - 1][(*returnColumnSizes)[*returnSize - 2] * 2 - 1], "%d", node->left->val);
            }
            if (node->right) {
                result[*returnSize - 1][(*returnColumnSizes)[*returnSize - 2] * 2 + 1] = (char*)malloc(sizeof(char));
                result[*returnSize - 1][(*returnColumnSizes)[*returnSize - 2] * 2 + 1][0] = '\0';
                sprintf(result[*returnSize - 1][(*returnColumnSizes)[*returnSize - 2] * 2 + 1], "%d", node->right->val);
            }
            result[*returnSize - 1][(*returnColumnSizes)[*returnSize - 2]] = (char*)malloc(sizeof(char));
            result[*returnSize - 1][(*returnColumnSizes)[*returnSize - 2]][0] = '\0';
            sprintf(result[*returnSize - 1][(*returnColumnSizes)[*returnSize - 2]], "%d", node->val);
        }
    }
    return result;  
    
}