/**https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/ */
//You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.
//Each minute, a node becomes infected if:
//	The node is currently uninfected.
//	The node is adjacent to an infected node.
//Return the number of minutes needed for the entire tree to be infected.
// 
//Example 1:
//Input: root = [1,5,3,null,4,10,6,9,2], start = 3
//Output: 4
//Explanation: The following nodes are infected during:
//- Minute 0: Node 3
//- Minute 1: Nodes 1, 10 and 6
//- Minute 2: Node 5
//- Minute 3: Node 4
//- Minute 4: Nodes 9 and 2
//It takes 4 minutes for the whole tree to be infected so we return 4.
//Example 2:
//Input: root = [1], start = 1
//Output: 0
//Explanation: At minute 0, the only node in the tree is infected so we return 0.
// 
//Constraints:
//	The number of nodes in the tree is in the range [1, 105].
//	1 <= Node.val <= 105
//	Each node has a unique value.
//	A node with a value of start exists in the tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int amountOfTime(struct TreeNode* root, int start) {
    int max = 0;
    struct TreeNode* startNode = NULL;
    struct TreeNode* parent = NULL;
    struct TreeNode* stack[10000];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct TreeNode* node = stack[top--];
        if (node->val == start) {
            startNode = node;
        }
        if (node->left) {
            stack[++top] = node->left;
            node->left->parent = node;
        }
        if (node->right) {
            stack[++top] = node->right;
            node->right->parent = node;
        }
    }
    struct TreeNode* queue[10000];
    int front = 0, rear = 0;
    queue[rear++] = startNode;
    int visited[10001] = {0};
    visited[startNode->val] = 1;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            if (node->left && !visited[node->left->val]) {
                queue[rear++] = node->left;
                visited[node->left->val] = 1;
            }
            if (node->right && !visited[node->right->val]) {
                queue[rear++] = node->right;
                visited[node->right->val] = 1;
            }
            if (node->parent && !visited[node->parent->val]) {
                queue[rear++] = node->parent;
                visited[node->parent->val] = 1;
            }
        }
        if (front < rear) {
            max++;
        }
    }
    return max;
}