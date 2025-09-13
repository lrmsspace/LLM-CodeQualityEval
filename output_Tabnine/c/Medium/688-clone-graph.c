/**https://leetcode.com/problems/clone-graph/ */
//Given a reference of a node in a connected undirected graph.
//Return a deep copy (clone) of the graph.
//Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
//class Node {
//    public int val;
//    public List<Node> neighbors;
//}
// 
//Test case format:
//For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.
//An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.
//The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.
// 
//Example 1:
//Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
//Output: [[2,4],[1,3],[2,4],[1,3]]
//Explanation: There are 4 nodes in the graph.
//1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
//2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
//3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
//4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
//Example 2:
//Input: adjList = [[]]
//Output: [[]]
//Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
//Example 3:
//Input: adjList = []
//Output: []
//Explanation: This an empty graph, it does not have any nodes.
// 
//Constraints:
//	The number of nodes in the graph is in the range [0, 100].
//	1 <= Node.val <= 100
//	Node.val is unique for each node.
//	There are no repeated edges and no self-loops in the graph.
//	The Graph is connected and all nodes can be visited starting from the given node.
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node *cloneGraph(struct Node *s) {
    if (!s) return NULL;
    
    struct Node *clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = s->val;
    clone->numNeighbors = s->numNeighbors;
    clone->neighbors = (struct Node**)malloc(clone->numNeighbors * sizeof(struct Node*));
    
    // Create a map to store the original node and its clone
    struct Node *map[100] = {0};
    map[s->val] = clone;
    
    // Breadth-first search to clone the graph
    struct Node *queue[100] = {s};
    int front = 0, rear = 0;
    
    while (front <= rear) {
        struct Node *node = queue[front++];
        for (int i = 0; i < node->numNeighbors; i++) {
            struct Node *neighbor = node->neighbors[i];
            
            if (!map[neighbor->val]) {
                // Create a new clone for the neighbor
                map[neighbor->val] = (struct Node*)malloc(sizeof(struct Node));
                map[neighbor->val]->val = neighbor->val;
                map[neighbor->val]->numNeighbors = neighbor->numNeighbors;
                map[neighbor->val]->neighbors = (struct Node**)malloc(neighbor->numNeighbors * sizeof(struct Node*));
                
                // Add the neighbor to the queue
                queue[++rear] = map[neighbor->val];
            }
            
            // Connect the clone to its neighbors
            map[node->val]->neighbors[i] = map[neighbor->val];
        }
    }
    
    return clone;
	
}