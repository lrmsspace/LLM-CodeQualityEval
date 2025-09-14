/**https://leetcode.com/problems/longest-well-performing-interval/ */
//We are given hours, a list of the number of hours worked per day for a given employee.
//A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.
//A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.
//Return the length of the longest well-performing interval.
// 
//Example 1:
//Input: hours = [9,9,6,0,6,6,9]
//Output: 3
//Explanation: The longest well-performing interval is [9,9,6].
//Example 2:
//Input: hours = [6,6,6]
//Output: 0
// 
//Constraints:
//	1 <= hours.length <= 104
//	0 <= hours[i] <= 16
class Solution {
    public int longestWPI(int[] hours) {
        int max = 0;
        int sum = 0;
        int[] preSum = new int[hours.length + 1];
        for (int i = 1; i <= hours.length; i++) {
            preSum[i] = preSum[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
        }
        for (int i = 1; i <= hours.length; i++) {
            for (int j = i; j <= hours.length; j++) {
                sum = preSum[j] - preSum[i - 1];
                if (sum > 0) {
                    max = Math.max(max, j - i + 1);
                }
            }
        }
        return max;
    }
}