/**https://leetcode.com/problems/race-car/ */
//Your car starts at position 0 and speed +1 on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):
//	When you get an instruction 'A', your car does the following:
//	
//		position += speed
//		speed *= 2
//	
//	
//	When you get an instruction 'R', your car does the following:
//	
//		If your speed is positive then speed = -1
//		otherwise speed = 1
//	
//	Your position stays the same.
//For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 --> 3, and your speed goes to 1 --> 2 --> 4 --> -1.
//Given a target position target, return the length of the shortest sequence of instructions to get there.
// 
//Example 1:
//Input: target = 3
//Output: 2
//Explanation: 
//The shortest instruction sequence is "AA".
//Your position goes from 0 --> 1 --> 3.
//Example 2:
//Input: target = 6
//Output: 5
//Explanation: 
//The shortest instruction sequence is "AAARA".
//Your position goes from 0 --> 1 --> 3 --> 7 --> 7 --> 6.
// 
//Constraints:
//	1 <= target <= 104
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.HashSet;
class Solution {
    public int racecar(int target) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 1, 0});
        Set<String> visited = new HashSet<>();
        visited.add("0_1");
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int pos = cur[0], speed = cur[1], steps = cur[2];
            if (pos == target) return steps;
            int[] next = new int[]{pos + speed, speed * 2, steps + 1};
            String key = (next[0] + "_" + next[1]);
            if (!visited.contains(key) && Math.abs(next[0] - target) < target) {
                queue.offer(next);
                visited.add(key);
            }
            next = new int[]{pos, speed > 0 ? -1 : 1, steps + 1};
            key = (next[0] + "_" + next[1]);
            if (!visited.contains(key) && Math.abs(next[0] - target) < target) {
                queue.offer(next);
                visited.add(key);
            }
            }
            return -1;       
    }
}