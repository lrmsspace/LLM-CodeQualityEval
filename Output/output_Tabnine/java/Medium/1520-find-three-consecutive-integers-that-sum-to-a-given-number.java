/**https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/ */
//Given an integer num, return three consecutive integers (as a sorted array) that sum to num. If num cannot be expressed as the sum of three consecutive integers, return an empty array.
// 
//Example 1:
//Input: num = 33
//Output: [10,11,12]
//Explanation: 33 can be expressed as 10 + 11 + 12 = 33.
//10, 11, 12 are 3 consecutive integers, so we return [10, 11, 12].
//Example 2:
//Input: num = 4
//Output: []
//Explanation: There is no way to express 4 as the sum of 3 consecutive integers.
// 
//Constraints:
//	0 <= num <= 1015
class Solution {
    public long[] sumOfThree(long num) {
        long[] result = new long[3];
        for (long i = 1; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                long j = num / i;
                if (i * j == num && (i - 1) * (j - 1) == num) {
                    result[0] = i - 1;
                    result[1] = i;
                    result[2] = j;
                    return result;
                }
            }
        }
        return new long[0];  // num cannot be expressed as the sum of three consecutive integers.
        
    }
}