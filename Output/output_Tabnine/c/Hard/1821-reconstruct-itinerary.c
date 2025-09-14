/**https://leetcode.com/problems/reconstruct-itinerary/ */
//You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.
//All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
//	For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
//You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
// 
//Example 1:
//Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
//Output: ["JFK","MUC","LHR","SFO","SJC"]
//Example 2:
//Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
//Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
//Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
// 
//Constraints:
//	1 <= tickets.length <= 300
//	tickets[i].length == 2
//	fromi.length == 3
//	toi.length == 3
//	fromi and toi consist of uppercase English letters.
//	fromi != toi
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findItinerary(char*** tickets, int ticketsSize, int* ticketsColSize, int* returnSize) {
    // Create a graph from the tickets
    int graph[26][26] = {0};
    for (int i = 0; i < ticketsSize; i++) {
        graph[tickets[i][0] - 'A'][tickets[i][1] - 'A']++;
    }
    
    // Initialize the stack with JFK
    char* stack[300];
    int top = 0;
    stack[top++] = "JFK";
    
    // Initialize the result array
    char** result = (char**)malloc(ticketsSize * sizeof(char*));
    *returnSize = ticketsSize;
    
    // Iterate until the stack is empty
    while (top > 0) {
        // Find the node with the least outgoing edges
        int node = 0;
        for (int i = 0; i < 26; i++) {
            if (graph[node][i] > 0 && (node == 0 || graph[node][i] < graph[node][node])) {
                node = i;
            }
        }
        
        // Remove the edges from the graph and push the node to the stack
        graph[node][node]--;
        result[--*returnSize] = (char*)malloc(4 * sizeof(char));
        strcpy(result[*returnSize], tickets[node][1]);
        for (int i = 0; i < 26; i++) {
            if (graph[node][i] == 0) {
                graph[node][i]--;
                stack[top++] = tickets[node][1];
                break;
            }
        }
    }
    
    // Reverse the result array
    for (int i = 0; i < *returnSize / 2; i++) {
        char* temp = result[i];
        result[i] = result[*returnSize - 1 - i];
        result[*returnSize - 1 - i] = temp;
    }
    
    return result;
    
}