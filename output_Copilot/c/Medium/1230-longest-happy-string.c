/**https://leetcode.com/problems/longest-happy-string/ */
//A string s is called happy if it satisfies the following conditions:
//	s only contains the letters 'a', 'b', and 'c'.
//	s does not contain any of "aaa", "bbb", or "ccc" as a substring.
//	s contains at most a occurrences of the letter 'a'.
//	s contains at most b occurrences of the letter 'b'.
//	s contains at most c occurrences of the letter 'c'.
//Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: a = 1, b = 1, c = 7
//Output: "ccaccbcc"
//Explanation: "ccbccacc" would also be a correct answer.
//Example 2:
//Input: a = 7, b = 1, c = 0
//Output: "aabaa"
//Explanation: It is the only correct answer in this case.
// 
//Constraints:
//	0 <= a, b, c <= 100
//	a + b + c > 0
char* longestDiverseString(int a, int b, int c) {
    char *res = (char *)malloc(sizeof(char) * 1000);
    int i = 0;
    while (a || b || c) {
        if ((a >= b && a >= c && a > 0) || (a > 0 && b == c)) {
            if (i >= 2 && res[i - 1] == 'a' && res[i - 2] == 'a') {
                res[i++] = 'b';
                b--;
            } else {
                res[i++] = 'a';
                a--;
            }
        } else if ((b >= a && b >= c && b > 0) || (b > 0 && a == c)) {
            if (i >= 2 && res[i - 1] == 'b' && res[i - 2] == 'b') {
                res[i++] = 'c';
                c--;
            } else {
                res[i++] = 'b';
                b--;
            }
        } else if ((c >= a && c >= b && c > 0) || (c > 0 && a == b)) {
            if (i >= 2 && res[i - 1] == 'c' && res[i - 2] == 'c') {
                res[i++] = 'a';
                a--;
            } else {
                res[i++] = 'c';
                c--;
            }
        }
    }
    res[i] = '\0';
    return res;    
}