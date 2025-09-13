/**https://leetcode.com/problems/jump-game-iv/ */
//Given an array of integers arr, you are initially positioned at the first index of the array.
//In one step you can jump from index i to index:
//	i + 1 where: i + 1 < arr.length.
//	i - 1 where: i - 1 >= 0.
//	j where: arr[i] == arr[j] and i != j.
//Return the minimum number of steps to reach the last index of the array.
//Notice that you can not jump outside of the array at any time.
// 
//Example 1:
//Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
//Output: 3
//Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
//Example 2:
//Input: arr = [7]
//Output: 0
//Explanation: Start index is the last index. You do not need to jump.
//Example 3:
//Input: arr = [7,6,9,6,9,6,9,7]
//Output: 1
//Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
// 
//Constraints:
//	1 <= arr.length <= 5 * 104
//	-108 <= arr[i] <= 108
class Solution {
    public int minJumps(int[] arr) {
           int n = arr.length;
            if (n == 1) return 0; // Already at the last index
    
            Map<Integer, List<Integer>> graph = new HashMap<>();
            for (int i = 0; i < n; i++) {
                graph.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
            }
    
            Queue<Integer> queue = new LinkedList<>();
            boolean[] visited = new boolean[n];
            queue.offer(0); // Start from index 0
            visited[0] = true;
            int steps = 0;
    
            while (!queue.isEmpty()) {
                int size = queue.size();
                for (int i = 0; i < size; i++) {
                    int index = queue.poll();
                    if (index == n - 1) return steps; // Reached the last index
    
                    // Check neighbors: index + 1, index - 1, and all indices with the same value
                    if (index + 1 < n && !visited[index + 1]) {
                        queue.offer(index + 1);
                        visited[index + 1] = true;
                    }
                    if (index - 1 >= 0 && !visited[index - 1]) {
                        queue.offer(index - 1);
                        visited[index - 1] = true;
                    }
                    for (int neighbor : graph.get(arr[index])) {
                        if (!visited[neighbor]) {
                            queue.offer(neighbor);
                            visited[neighbor] = true;
                        }
                    }
                    graph.get(arr[index]).clear(); // Clear to avoid redundant checks
                }
                steps++;
            }
    
            return -1; // Should never reach here if input is valid     
    }
}