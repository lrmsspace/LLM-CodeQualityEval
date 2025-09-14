/**https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/ */
//You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.
//Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:
//	'L' means to go from a node to its left child node.
//	'R' means to go from a node to its right child node.
//	'U' means to go from a node to its parent node.
//Return the step-by-step directions of the shortest path from node s to node t.
// 
//Example 1:
//Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
//Output: "UURL"
//Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
//Example 2:
//Input: root = [2,1], startValue = 2, destValue = 1
//Output: "L"
//Explanation: The shortest path is: 2 → 1.
// 
//Constraints:
//	The number of nodes in the tree is n.
//	2 <= n <= 105
//	1 <= Node.val <= n
//	All the values in the tree are unique.
//	1 <= startValue, destValue <= n
//	startValue != destValue
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
char* getDirections(struct TreeNode* root, int startValue, int destValue) {
    // Base case: if startValue is equal to destValue, return an empty string
    if (startValue == destValue) {
        return strdup("");
    }
    
    // Create an empty string for storing the directions
    char* directions = strdup("");
    
    // Create a stack to store the nodes to be visited
    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * n);
    int top = -1;
    
    // Initialize the stack with the root node
    stack[++top] = root;
    
    // Create a boolean array to keep track of visited nodes
    bool* visited = (bool*)malloc(sizeof(bool) * n);
    memset(visited, false, n * sizeof(bool));
    
    // Create a boolean array to keep track of visited parents
    bool* visitedParent = (bool*)malloc(sizeof(bool) * n);
    memset(visitedParent, false, n * sizeof(bool));
    
    // Create a queue to store the nodes to be explored
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * n);
    int front = 0;
    int rear = 0;
    
    // Create a boolean array to keep track of visited nodes in the queue
    bool* visitedQueue = (bool*)malloc(sizeof(bool) * n);
    memset(visitedQueue, false, n * sizeof(bool));
    
    // Set the startValue as visited and enqueue it
    visited[startValue - 1] = true;
    visitedQueue[startValue - 1] = true;
    queue[rear++] = root;
    
    // Start the BFS traversal
    while (front!= rear) {
        struct TreeNode* currentNode = queue[front++];
        
        // Check if the currentNode is the destinationValue
        if (currentNode->val == destValue) {
            break;
        }
        
        // Check if the currentNode has a left child
        if (currentNode->left!= NULL) {
            if (!visited[currentNode->left->val - 1]) {
                visited[currentNode->left->val - 1] = true;
                visitedQueue[currentNode->left->val - 1] = true;
                stack[++top] = currentNode->left;
                directions = realloc(directions, (strlen(directions) + 2) * sizeof(char));
                strcat(directions, "L");
            } else if (visitedParent[currentNode->val - 1]) {
                directions = realloc(directions, (strlen(directions) + 2) * sizeof(char));
                strcat(directions, "U");
            }
        }
        
        // Check if the currentNode has a right child
        if (currentNode->right!= NULL) {
            if (!visited[currentNode->right->val - 1]) {
                visited[currentNode->right->val - 1] = true;
                visitedQueue[currentNode->right->val - 1] = true;
                stack[++top] = currentNode->right;
                directions = realloc(directions, (strlen(directions) + 2) * sizeof(char));
                strcat(directions, "R");
            } else if (visitedParent[currentNode->val - 1]) {
                directions = realloc(directions, (strlen(directions) + 2) * sizeof(char));
                strcat(directions, "U");
            }
        }
        
        // Mark the currentNode as visited and its parent as visitedParent
        visitedParent[currentNode->val - 1] = true;
        
        // Add the currentNode's parent to the stack
        if (currentNode->val!= root->val) {
            stack[++top] = currentNode->parent;
        }
    
        // Dequeue the currentNode from the queue
        visitedQueue[currentNode->val - 1] = false;
    
        // Enqueue the currentNode's children to the queue
        if (currentNode->left!= NULL) {
            queue[rear++] = currentNode->left;
        }
        if (currentNode->right!= NULL) {
            queue[rear++] = currentNode->right;
        }
    }
    
    // Free the allocated memory
    free(stack);
    free(visited);
    free(visitedParent);
    free(queue);
    free(visitedQueue);
    
    // Reverse the directions string
    char* reversedDirections = strdup(directions);
    int length = strlen(reversedDirections);
    for (int i = 0; i < length / 2; i++) {
        char temp = reversedDirections[i];
        reversedDirections[i] = reversedDirections[length - 1 - i];
        reversedDirections[length - 1 - i] = temp;
    }
    
    // Return the reversed directions string
    return reversedDirections;
}