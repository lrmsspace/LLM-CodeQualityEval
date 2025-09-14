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
        if (arr.length <= 1) return 0;
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            graph.computeIfAbsent(arr[i], x -> new ArrayList<>()).add(i);
        }
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(0);
        boolean[] visited = new boolean[arr.length];
        visited[0] = true;
        int steps = 0;
        
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int index = queue.poll();
                if (index == arr.length - 1) return steps;

                List<Integer> nextIndices = graph.get(arr[index]);
                nextIndices.add(index - 1);
                nextIndices.add(index + 1);
                
                for (int next : nextIndices) {
                    if (next >= 0 && next < arr.length && !visited[next]) {
                        visited[next] = true;
                        queue.offer(next);
                    }
                }
                nextIndices.clear();
            }
            steps++;
        }
        return -1;
    }   
}
