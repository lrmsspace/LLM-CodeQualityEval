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
    // Create a queue to store the nodes to be visited in the next minute
    struct TreeNode* queue[100000];
    int front = 0, rear = 0;
    int visited[100000] = {0};
    queue[rear++] = root;
    visited[root->val] = 1;
    
    // Initialize the time variable

    int time = 0;
    
    // While there are nodes in the queue
    while (front < rear) {
        int size = rear - front;
        
        // Iterate through the current minute's nodes
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            
            // If the current node is the start node, return the time
            if (node->val == start) {
                return time;
            }
            
            // Add the unvisited adjacent nodes to the queue
            if (node->left &&!visited[node->left->val]) {
                queue[rear++] = node->left;
                visited[node->left->val] = 1;
            }
            
            if (node->right &&!visited[node->right->val]) {
                queue[rear++] = node->right;
                visited[node->right->val] = 1;
            }
        }
        
        // Increment the time
        time++;
    }
    
    // The start node is not found in the tree
    return -1;
}