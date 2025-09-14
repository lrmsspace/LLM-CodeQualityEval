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
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    int maxLevel = 0;
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 1000);
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        int levelSize = rear - front;
        maxLevel = fmax(maxLevel, levelSize);
        (*returnColumnSizes) = realloc((*returnColumnSizes), sizeof(int) * (maxLevel + 1));
        (*returnColumnSizes)[maxLevel] = levelSize;
        
        struct Node** levelNodes = (struct Node**)malloc(sizeof(struct Node*) * levelSize);
        for (int i = 0; i < levelSize; ++i) {
            levelNodes[i] = queue[front++];
        }
        
        (*returnSize)++;
        (*returnColumnSizes)[(*returnSize) - 1] = levelSize;
        (*return)[(*returnSize) - 1] = levelNodes;
        
        for (int i = 0; i < levelSize; ++i) {
            struct Node* node = levelNodes[i];
            for (int j = 0; j < node->numChildren; ++j) {
                queue[rear++] = node->children[j];
            }
        }
        
        free(levelNodes);

    }
    
    free(queue);
    return (*returnSize) > 0? (*return) : NULL;
    
}