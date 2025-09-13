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
int countZero = 0, countOne = 0, swapCount01 = 0, swapCount10 = 0;
int len = strlen(s);

for (int i = 0; i < len; i++) {
    if (s[i] == '0') countZero++;
    else countOne++;

    if (i % 2 == 0) {
        if (s[i] != '0') swapCount01++;
        if (s[i] != '1') swapCount10++;
    } else {
        if (s[i] != '1') swapCount01++;
        if (s[i] != '0') swapCount10++;
    }
}

if (abs(countZero - countOne) > 1) return -1;

if (countZero > countOne) return swapCount10 / 2;
if (countOne > countZero) return swapCount01 / 2;
return fmin(swapCount01, swapCount10) / 2;

}