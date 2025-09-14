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
class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        List<String> result = new ArrayList<>();
        Map<String, List<String>> graph = new HashMap<>();
        for (List<String> ticket : tickets) {
            graph.computeIfAbsent(ticket.get(0), k -> new ArrayList<>()).add(ticket.get(1));
        }
        graph.forEach((k, v) -> Collections.sort(v));
        dfs("JFK", result, graph);
        return result;
    }

    private void dfs(String cur, List<String> result, Map<String, List<String>> graph) {
        result.add(cur);
        if (cur.equals("JFK") && result.size() == graph.size() + 1) {
            return;
        }
        if (graph.containsKey(cur)) {
            for (String next : graph.get(cur)) {
                graph.get(cur).remove(next);
                dfs(next, result, graph);
                if (result.size() == graph.size() + 1) {
                    return;
                }
                graph.get(cur).add(next);
                Collections.sort(graph.get(cur));
            }
        }
    }
}