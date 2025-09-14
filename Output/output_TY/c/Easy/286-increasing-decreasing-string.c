/**https://leetcode.com/problems/increasing-decreasing-string/ */
//You are given a string s. Reorder the string using the following algorithm:
//	Pick the smallest character from s and append it to the result.
//	Pick the smallest character from s which is greater than the last appended character to the result and append it.
//	Repeat step 2 until you cannot pick more characters.
//	Pick the largest character from s and append it to the result.
//	Pick the largest character from s which is smaller than the last appended character to the result and append it.
//	Repeat step 5 until you cannot pick more characters.
//	Repeat the steps from 1 to 6 until you pick all characters from s.
//In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.
//Return the result string after sorting s with this algorithm.
// 
//Example 1:
//Input: s = "aaaabbbbcccc"
//Output: "abccbaabccba"
//Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
//After steps 4, 5 and 6 of the first iteration, result = "abccba"
//First iteration is done. Now s = "aabbcc" and we go back to step 1
//After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
//After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
//Example 2:
//Input: s = "rat"
//Output: "art"
//Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.
// 
//Constraints:
//	1 <= s.length <= 500
//	s consists of only lowercase English letters.
char * sortString(char * s){
    int i, j, k, l, m, n, o, p, q, r, t, u, v, w, x, y, z;
    int a[26] = { 0 };
    int b[26] = { 0 };
    int c[26] = { 0 };
    int d[26] = { 0 };
    int e[26] = { 0 };
    int f[26] = { 0 };
    for (i = 0; s[i] != '\0'; i++) {
        a[s[i] - ' a ']++;
    }
    for (i = 0; i < 26; i++) {
        if (a[i] > 0) {
            b[i] = a[i];
        }
    }
    for (i = 0; i < 26; i++) {
        if (b[i] > 0) {
            c[i] = b[i];
        }
    }
    for (i = 0; i < 26; i++) {
        if (c[i] > 0) {
            d[i] = c[i];
        }
    }
    for (i = 0; i < 26; i++) {
        if (d[i] > 0) {
            e[i] = d[i];
        }
    }
    for (i = 0; i < 26; i++) {
        if (e[i] > 0) {
            f[i] = e[i];
        }
    }
    for (i = 0; i < 26; i++) {
        if (f[i] > 0) {
            s[i] = (char)(i + ' a ');
        }
    }
    for (i = 25; i >= 0; i--) {
        if (f[i] > 0) {
            s[i + 26] = (char)(i + ' a ');
        }
    }
    for (i = 0; i < 26; i++) {
        if (f[i] > 0) {
            s[i + 52] = (char)(i + ' a ');
        }
    }
    for (i = 25; i >= 0; i--) {
        if (f[i] > 0) {
            s[i + 78] = (char)(i + ' a ');
        }
    }
    return s;
}