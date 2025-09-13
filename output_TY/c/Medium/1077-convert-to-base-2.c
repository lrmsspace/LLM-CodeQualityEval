/**https://leetcode.com/problems/convert-to-base-2/ */
//Given an integer n, return a binary string representing its representation in base -2.
//Note that the returned string should not have leading zeros unless the string is "0".
// 
//Example 1:
//Input: n = 2
//Output: "110"
//Explantion: (-2)2 + (-2)1 = 2
//Example 2:
//Input: n = 3
//Output: "111"
//Explantion: (-2)2 + (-2)1 + (-2)0 = 3
//Example 3:
//Input: n = 4
//Output: "100"
//Explantion: (-2)2 = 4
// 
//Constraints:
//	0 <= n <= 109
char * baseNeg2(int n){
    char *s = malloc(sizeof(char) * 33);
    s[32] = '\0';
    int i = 31;
    while (n) {
        s[i--] = (n & 1) ? '1' : '0';
        n = -(n >> 1);
    }
    return s + i + 1;
}