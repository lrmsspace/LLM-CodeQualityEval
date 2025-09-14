/*
 Given a string s containing only digits, return the lexicographically smallest string that can be obtained after swapping adjacent digits in s with the same parity at most once.
 Digits have the same parity if both are odd or both are even. For example, 5 and 9, as well as 2 and 4, have the same parity, while 6 and 9 do not.
 Example 1:
 Input: s = "45320"
 Output: "43520"
 Explanation: 
 s[1] == '5' and s[2] == '3' both have the same parity, and swapping them results in the lexicographically smallest string.
 Example 2:
 Input: s = "001"
 Output: "001"
 Explanation:
 There is no need to perform a swap because s is already the lexicographically smallest.
 Constraints:
 2 <= s.length <= 100
 s consists only of digits.
*/

class Solution {
    public String getSmallestString(String s) {
        int n = s.length();
        int i = n - 1;
        
        // Find the largest index i such that s[i] < s[i+1] and s[i] has the same parity as s[i+1]
        while (i > 0 && s.charAt(i) >= s.charAt(i-1)) {
            i--;
        }
        
        // If no such index exists, return the original string
        if (i == 0) {
            return s;
        }
        
        // Find the smallest index j such that s[j] > s[i-1] and s[j] has the same parity as s[i-1]
        int j = n - 1;
        while (j > i && s.charAt(j) <= s.charAt(i-1)) {
            j--;
        }
        
        // Swap s[i-1] and s[j]
        char temp = s.charAt(i-1);
        s = s.substring(0, i-1) + s.charAt(j) + s.substring(i, j) + temp;
        
        // Reverse the substring starting from s[i] to make it lexicographically smaller
        s = s.substring(0, i) + new StringBuilder(s.substring(i)).reverse().toString();
        
        return s;
        
    }
}