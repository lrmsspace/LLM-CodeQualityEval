/**https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/ */
//We run a preorder depth-first search (DFS) on the root of a binary tree.
//At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
//If a node has only one child, that child is guaranteed to be the left child.
//Given the output traversal of this traversal, recover the tree and return its root.
// 
//Example 1:
//Input: traversal = "1-2--3--4-5--6--7"
//Output: [1,2,5,3,4,6,7]
//Example 2:
//Input: traversal = "1-2--3---4-5--6---7"
//Output: [1,2,5,3,null,6,null,4,null,7]
//Example 3:
//Input: traversal = "1-401--349---90--88"
//Output: [1,401,null,349,88,90]
// 
//Constraints:
//	The number of nodes in the original tree is in the range [1, 1000].
//	1 <= Node.val <= 109
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* recoverFromPreorder(char* traversal) {
    int len = strlen(traversal);
    int* stack = (int*)malloc(sizeof(int) * len);
    int top = -1;
    int i = 0;
    while (i < len) {
        int level = 0;
        while (traversal[i] == '-') {
            level++;
            i++;
        }
        int val = 0;
        while (i < len && traversal[i] != '-') {
            val = val * 10 + (traversal[i] - '0');
            i++;
        }
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        while (top >= 0 && stack[top] >= level) {
            top--;
        }
        if (top >= 0) {
            if (stack[top] == level - 1) {
                struct TreeNode* parent = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                parent = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                parent = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                parent = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            }
            else {
                struct TreeNode* parent = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                parent = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                parent = (struct TreeNode*)malloc(sizeof(struct TreeNode));
                parent = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            }
            if (parent->left == NULL) {
                parent->left = node;
            }
        }
        stack[++top] = level;
            
}