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
class Solution {
    public int racecar(int target) {
        int[] dp = new int[target + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        dp[1] = 1;
        
        for (int i = 2; i <= target; i++) {
            for (int j = 1; j * j <= i; j++) {
                int k = i - j * j;
                if (k >= 0 && dp[k]!= Integer.MAX_VALUE) {
                    dp[i] = Math.min(dp[i], dp[k] + 1 + (j << 1) + (k == 0? 0 : 1));
                }
            }
        }
        
        return dp[target];
        
    }
}