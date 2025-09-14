/**https://leetcode.com/problems/construct-the-longest-new-string/ */
//You are given three integers x, y, and z.
//You have x strings equal to "AA", y strings equal to "BB", and z strings equal to "AB". You want to choose some (possibly all or none) of these strings and concatenate them in some order to form a new string. This new string must not contain "AAA" or "BBB" as a substring.
//Return the maximum possible length of the new string.
//A substring is a contiguous non-empty sequence of characters within a string.
// 
//Example 1:
//Input: x = 2, y = 5, z = 1
//Output: 12
//Explanation: We can concactenate the strings "BB", "AA", "BB", "AA", "BB", and "AB" in that order. Then, our new string is "BBAABBAABBAB". 
//That string has length 12, and we can show that it is impossible to construct a string of longer length.
//Example 2:
//Input: x = 3, y = 2, z = 2
//Output: 14
//Explanation: We can concactenate the strings "AB", "AB", "AA", "BB", "AA", "BB", and "AA" in that order. Then, our new string is "ABABAABBAABBAA". 
//That string has length 14, and we can show that it is impossible to construct a string of longer length.
// 
//Constraints:
//	1 <= x, y, z <= 50
class Solution {
    public int longestString(int x, int y, int z) {
        int max = 0;
        for (int a = 0; a <= 1; a++) {
            for (int b = 0; b <= 1; b++) {
                int c = 0;
                if (a == 1) c++;
                if (b == 1) c++;
                int A = x, B = y, C = z;
                A -= a;
                B -= b;
                int len = 2 * c;
                while (A > 0 && B > 0) {
                    if (c == 0) break;
                    A--;
                    B--;
                    len += 2;
                }
                while (A > 0 && C > 0) {
                    A--;
                    C--;
                    len += 2;
                }
                while (B > 0 && C > 0) {
                    B--;
                    C--;
                    len += 2;
                }
                max = Math.max(max, len);
            }
        }
        return max;        
    }
}