/**https://leetcode.com/problems/find-longest-awesome-substring/ */
//You are given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps in order to make it a palindrome.
//Return the length of the maximum length awesome substring of s.
// 
//Example 1:
//Input: s = "3242415"
//Output: 5
//Explanation: "24241" is the longest awesome substring, we can form the palindrome "24142" with some swaps.
//Example 2:
//Input: s = "12345678"
//Output: 1
//Example 3:
//Input: s = "213123"
//Output: 6
//Explanation: "213123" is the longest awesome substring, we can form the palindrome "231132" with some swaps.
// 
//Constraints:
//	1 <= s.length <= 105
//	s consists only of digits.
class Solution {
    public int longestAwesome(String s) {
        int n = s.length(), ans = 0;
        int[] count = new int[1024]; // 2^10 = 1024, for 10 digits
        count[0] = -1; // Initialize count[0] to -1 to handle the case when the whole string is a palindrome.
        int mask = 0; // mask to track odd/even counts of digits

        for (int i = 0; i < n; i++) {
            mask ^= (1 << (s.charAt(i) - '0')); // Toggle the bit corresponding to the digit
            ans = Math.max(ans, i - count[mask]); // Check if this mask has been seen before

            // Check for masks with one bit different (odd count of one digit)
            for (int j = 0; j < 10; j++) {
                ans = Math.max(ans, i - count[mask ^ (1 << j)]); // Check the mask with one bit flipped
            }

            if (count[mask] == 0) { // If this mask hasn't been seen before, store the index
                count[mask] = i + 1;
            }
        }
        return ans;        
    }
}