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
 * @param {string[][]} tickets
 * @return {string[]}
 */
var findItinerary = function(tickets) {
    let graph = new Map();
    let result = [];
    
    // Create a graph from the tickets
    for (let [from, to] of tickets) {
        if (!graph.has(from)) {
            graph.set(from, []);
        }
        graph.get(from).push(to);
    }
    
    // Sort the graph values in ascending order to minimize lexical order
    for (let [airport, destinations] of graph) {
        destinations.sort();
    }
    
    // Helper function to traverse the graph recursively
    function dfs(airport) {
        while (graph.has(airport) && graph.get(airport).length > 0) {
            let nextAirport = graph.get(airport).shift();
            dfs(nextAirport);
        }
        result.unshift(airport);
    }
    
    // Start from JFK and traverse the graph
    dfs('JFK');
    
    return result;
    
};