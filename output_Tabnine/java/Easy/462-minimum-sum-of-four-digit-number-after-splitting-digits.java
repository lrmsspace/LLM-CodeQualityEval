/**https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/ */
//You are given a positive integer num consisting of exactly four digits. Split num into two new integers new1 and new2 by using the digits found in num. Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.
//	For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3. Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].
//Return the minimum possible sum of new1 and new2.
// 
//Example 1:
//Input: num = 2932
//Output: 52
//Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
//The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.
//Example 2:
//Input: num = 4009
//Output: 13
//Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc. 
//The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.
// 
//Constraints:
//	1000 <= num <= 9999
class Solution {
    public int minimumSum(int num) {
        int[] digits = new int[4];
        int sum = 0;
        
        // Separate digits into an array
        for (int i = 0; i < 4; i++) {
            digits[i] = num % 10;
            num /= 10;
        }
        
        // Sort the digits in ascending order
        Arrays.sort(digits);
        
        // Construct the smallest possible new1 by combining the smallest two digits
        int new1 = digits[0] * 10 + digits[1];
        
        // Construct the smallest possible new2 by combining the largest two digits
        int new2 = digits[2] * 10 + digits[3];
        
        // Calculate the sum of new1 and new2
        sum = new1 + new2;
        
        return sum;
        
    }
}