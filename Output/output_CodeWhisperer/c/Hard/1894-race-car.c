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
int racecar(int target) {
    int* dp = (int*)malloc(sizeof(int) * (target + 1));
    memset(dp, 0, sizeof(int) * (target + 1));
    dp[1] = 1;
    for (int i = 2; i <= target; i++) {
        int n = 1, j = 1;
        while (j < i) {
            j = (1 << ++n) - 1;
            if (j == i) {
                dp[i] = n;
                break;
            }
            else if (j > i) {
                dp[i] = dp[j - i] + n + 1;
                while (--n > 0) {
                    j = (1 << n) - 1;
                    dp[i] = fmin(dp[i], dp[i - j] + n + 2);
                }
                break;
            }
        }
        if (dp[i] == 0) {
            dp[i] = dp[i - 1] + 1;
        }
    }
    int ret = dp[target];
    free(dp);
    return ret;
    
}