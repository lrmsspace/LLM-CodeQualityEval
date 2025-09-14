/**https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/ */
//Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.
//The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
//Any two characters may be swapped, even if they are not adjacent.
// 
//Example 1:
//Input: s = "111000"
//Output: 1
//Explanation: Swap positions 1 and 4: "111000" -> "101010"
//The string is now alternating.
//Example 2:
//Input: s = "010"
//Output: 0
//Explanation: The string is already alternating, no swaps are needed.
//Example 3:
//Input: s = "1110"
//Output: -1
// 
//Constraints:
//	1 <= s.length <= 1000
//	s[i] is either '0' or '1'.
int minSwaps(char* s) {
    int n = strlen(s);
    int count[2] = {0, 0};
    for (int i = 0; i < n; i++) {
        count[s[i] - '0']++;
    }
    if (count[0] % 2!= 0 || count[1] % 2!= 0) {
        return -1;
    }
    
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i]!= s[n - 1 - i]) {
            ans++;
            for (int j = n - 1; j > i; j--) {
                if (s[j] == s[i]) {
                    swap(s[i], s[j]);
                    break;
                }
            }
        }
    }
    
    return ans;
    
}