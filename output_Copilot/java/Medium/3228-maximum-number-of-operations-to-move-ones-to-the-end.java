/*
 You are given a binary string s.
 You can perform the following operation on the string any number of times:
 Choose any index i from the string where i + 1 < s.length such that s[i] == '1' and s[i + 1] == '0'.
 Move the character s[i] to the right until it reaches the end of the string or another '1'. For example, for s = "010010", if we choose i = 1, the resulting string will be s = "000110".
 Return the maximum number of operations that you can perform.
 Example 1:
 Input: s = "1001101"
 Output: 4
 Explanation:
 We can perform the following operations:
 Choose index i = 0. The resulting string is s = "0011101".
 Choose index i = 4. The resulting string is s = "0011011".
 Choose index i = 3. The resulting string is s = "0010111".
 Choose index i = 2. The resulting string is s = "0001111".
 Example 2:
 Input: s = "00111"
 Output: 0
 Constraints:
 1 <= s.length <= 105
 s[i] is either '0' or '1'.
*/

class Solution {
    public int maxOperations(String s) {
        int count = 0;
        int ones = 0;
        
        // Count the number of '1's in the string
        for (char c : s.toCharArray()) {
            if (c == '1') {
                ones++;
            }
        }
        
        // If there are no '1's, return 0
        if (ones == 0) {
            return 0;
        }
        
        // Traverse the string and count operations
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1') {
                // Each '1' can potentially move past all '0's to its right
                count += ones - 1; // -1 because we don't count the current '1'
                ones--; // Decrease the count of remaining '1's
            }
        }
        
        return count;        
    }
}