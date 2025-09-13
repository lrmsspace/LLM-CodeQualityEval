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

void dfs(string start, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, vector<string>& result) {
    while (graph[start].size() > 0) {
        string next = graph[start].top();
        graph[start].pop();
        dfs(next, graph, result);
    }
    result.push_back(start);
}

char** findItinerary(char*** tickets, int ticketsSize, int* ticketsColSize, int* returnSize) {
    
    // build graph
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    for (int i = 0; i < ticketsSize; i++) {
        graph[tickets[i][0]].push(tickets[i][1]);
    }
    
    // dfs
    vector<string> result;
    dfs("JFK", graph, result);
    *returnSize = result.size();
    char** ret = (char**)malloc((*returnSize + 1) * sizeof(char*));
    for (int i = 0; i < *returnSize; i++) {
        ret[i] = (char*)malloc((result[i].size() + 1) * sizeof(char));
        strcpy(ret[i], result[i].c_str());
    }
    ret[*returnSize] = NULL;
    return ret;
}   