/**https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/ */
//You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.
//The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.
//Return the minimum number of operations needed to make s alternating.
// 
//Example 1:
//Input: s = "0100"
//Output: 1
//Explanation: If you change the last character to '1', s will be "0101", which is alternating.
//Example 2:
//Input: s = "10"
//Output: 0
//Explanation: s is already alternating.
//Example 3:
//Input: s = "1111"
//Output: 2
//Explanation: You need two operations to reach "0101" or "1010".
// 
//Constraints:
//	1 <= s.length <= 104
//	s[i] is either '0' or '1'.
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int count0 = 0, count1 = 0;
        for (char c : s) {
            if (c == '0') ++count0;
            else ++count1;
        }
        return min(count0, count1);  // If the count of '0's and '1's are equal, return the count of '0's. Otherwise, return the smaller count.
        
    }
};