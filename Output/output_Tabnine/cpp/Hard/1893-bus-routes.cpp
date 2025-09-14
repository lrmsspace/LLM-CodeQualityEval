/**https://leetcode.com/problems/bus-routes/ */
//You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.
//	For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
//You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
//Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
// 
//Example 1:
//Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
//Output: 2
//Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
//Example 2:
//Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
//Output: -1
// 
// 
//Constraints:
//	1 <= routes.length <= 500.
//	1 <= routes[i].length <= 105
//	All the values of routes[i] are unique.
//	sum(routes[i].length) <= 105
//	0 <= routes[i][j] < 106
//	0 <= source, target < 106
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // Step 1: Create a graph where each node represents a bus stop and each edge represents a bus route.
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < routes.size(); ++i) {
            for (int j = 0; j < routes[i].size(); ++j) {
                graph[routes[i][j]].push_back(i);
            }
        }
        
        // Step 2: Initialize a queue to store the bus stops that need to be visited.
        queue<pair<int, int>> q;  // (bus stop, number of buses)
        q.push({source, 0});
        
        // Step 3: Create a set to keep track of visited bus stops.
        unordered_set<int> visited;
        
        // Step 4: Perform breadth-first search to find the shortest path from the source to the target.

        while (!q.empty()) {
            int stop = q.front().first;
            int numBuses = q.front().second;
            q.pop();
            
            if (stop == target) {
                return numBuses;
            }
            
            visited.insert(stop);
            
            for (int neighbor : graph[stop]) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push({neighbor, numBuses + 1});
                }
            }
        }
        
        // Step 5: Return -1 if it is not possible to travel from the source to the target.
        return -1;
        
    }
};