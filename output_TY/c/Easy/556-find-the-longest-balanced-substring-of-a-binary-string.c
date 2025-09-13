/**https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/ */
//You are given a binary string s consisting only of zeroes and ones.
//A substring of s is considered balanced if all zeroes are before ones and the number of zeroes is equal to the number of ones inside the substring. Notice that the empty substring is considered a balanced substring.
//Return the length of the longest balanced substring of s.
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: s = "01000111"
//Output: 6
//Explanation: The longest balanced substring is "000111", which has length 6.
//Example 2:
//Input: s = "00111"
//Output: 4
//Explanation: The longest balanced substring is "0011", which has length 4. 
//Example 3:
//Input: s = "111"
//Output: 0
//Explanation: There is no balanced substring except the empty substring, so the answer is 0.
// 
//Constraints:
//	1 <= s.length <= 50
//	'0' <= s[i] <= '1'
int findTheLongestBalancedSubstring(char * s){
    int maxLength = 0;
    int zeroCount = 0;
    int oneCount = 0;
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (oneCount > 0) {
                // 如果之前有连续的 '1'，重置计数器
                zeroCount = 1;
                oneCount = 0;
            } else {
                zeroCount++;
            }
        } else if (s[i] == '1') {
            oneCount++;
            if (oneCount <= zeroCount) {
                // 当前的 '1' 数量不超过之前的 '0' 数量时，更新最大长度
                maxLength = (oneCount * 2 > maxLength) ? oneCount * 2 : maxLength;
            }
        }
    }

    return maxLength;
}