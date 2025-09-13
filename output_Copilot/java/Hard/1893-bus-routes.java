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
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) return 0; // If source and target are the same, no buses are needed

        Map<Integer, List<Integer>> busStopToRoutes = new HashMap<>(); // Map to store bus stops and their corresponding routes
        for (int i = 0; i < routes.length; i++) {
            for (int stop : routes[i]) {
                busStopToRoutes.computeIfAbsent(stop, k -> new ArrayList<>()).add(i); // Add route index to the bus stop
            }
        }

        Queue<Integer> queue = new LinkedList<>();
        boolean[] visitedRoutes = new boolean[routes.length]; // Track visited routes
        queue.offer(source); // Start from the source bus stop
        int buses = 0; // Count of buses taken

        while (!queue.isEmpty()) {
            buses++; // Increment bus count for each level of BFS
            int size = queue.size(); // Number of stops at the current level

            for (int i = 0; i < size; i++) {
                int currentStop = queue.poll(); // Get the current bus stop

                for (int routeIndex : busStopToRoutes.getOrDefault(currentStop, new ArrayList<>())) {
                    if (visitedRoutes[routeIndex]) continue; // Skip if this route has already been visited
                    visitedRoutes[routeIndex] = true; // Mark this route as visited

                    for (int nextStop : routes[routeIndex]) { // Explore all stops in this route
                        if (nextStop == target) return buses; // If we reach the target, return the bus count
                        queue.offer(nextStop); // Add next stop to the queue for further exploration
                    }
                }
            }
        }

        return -1; // If we exhaust all options and don't reach the target, return -1        
    }
}