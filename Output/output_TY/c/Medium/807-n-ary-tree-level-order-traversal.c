/**https://leetcode.com/problems/n-ary-tree-level-order-traversal/ */
//Given an n-ary tree, return the level order traversal of its nodes' values.
//Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
// 
//Example 1:
//Input: root = [1,null,3,2,4,null,5,6]
//Output: [[1],[3,2,4],[5,6]]
//Example 2:
//Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
//Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
// 
//Constraints:
//	The height of the n-ary tree is less than or equal to 1000
//	The total number of nodes is between [0, 104]
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    int** res = NULL;
    *returnSize = 0;
    *returnColumnSizes = NULL;
    if (root == NULL) return res;
    int level = 0;
    struct Node* cur = root;
    while (cur != NULL) {
        int* tmp = (int*)malloc(sizeof(int) * 10000);
        int size = 0;
        struct Node* next = NULL;
        while (cur != NULL) {
            tmp[size++] = cur->val;
            for (int i = 0; i < cur->childrenSize; i++) {
                next = cur->children[i];
            }
            cur = cur->next;
        }
        res = (int**)realloc(res, sizeof(int*) * (level + 1));
    }
    return res;
}
