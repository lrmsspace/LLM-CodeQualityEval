/**https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/ */
//You are given two strings s and t. In one step, you can append any character to either s or t.
//Return the minimum number of steps to make s and t anagrams of each other.
//An anagram of a string is a string that contains the same characters with a different (or the same) ordering.
// 
//Example 1:
//Input: s = "leetcode", t = "coats"
//Output: 7
//Explanation: 
//- In 2 steps, we can append the letters in "as" onto s = "leetcode", forming s = "leetcodeas".
//- In 5 steps, we can append the letters in "leede" onto t = "coats", forming t = "coatsleede".
//"leetcodeas" and "coatsleede" are now anagrams of each other.
//We used a total of 2 + 5 = 7 steps.
//It can be shown that there is no way to make them anagrams of each other with less than 7 steps.
//Example 2:
//Input: s = "night", t = "thing"
//Output: 0
//Explanation: The given strings are already anagrams of each other. Thus, we do not need any further steps.
// 
//Constraints:
//	1 <= s.length, t.length <= 2 * 105
//	s and t consist of lowercase English letters.
int minSteps(char * s, char * t){
    int i, j, k, l, m, n, o, p, q, r, s1, t1, u, v, w, x, y, z;
    int a[26] = {0}, b[26] = {0}, c[26] = {0}, d[26] = {0}, e[26] = {0}, f[26] = {0}, g[26] = {0}, h[26] = {0}, i1[26] = {0}, j1[26] = {0}, k1[26] = {0}, l1[26] = {0}, m1[26] = {0}, n1[26] = {0}, o1[26] = {0}, p1[26] = {0}, q1[26] = {0}, r1[26] = {0}, s2[26] = {0}, t2[26] = {0}, u1[26] = {0},v1[26] = {0}, w1[26] = {
        0}, x1[26] = {0}, y1[26] = {0}, z1[26] = {0};
        for (i = 0; i < strlen(s); i++) {
            a[s[i] - ' a ']++;
        }
        for (i = 0; i < strlen(t); i++) {
            b[t[i] - ' a ']++;
        }
        for (i = 0; i < 26; i++) {
            x1[i] = a[i] - b[i];
            y1[i] = b[i] - a[i];
            z1[i] = abs(x1[i]);
        }
        for (i = 0; i < 26; i++) {
            if (x1[i] < 0) {
                return -1;
            }
        }
        for (i = 0; i < 26; i++) {
            if (y1[i] < 0) {
                return -1;
            }
        }
        for (i = 0; i < 26; i++) {
            if (z1[i] % 2 == 0) {
                c += z1[i] / 2;
            } else {
                c += (z1[i] - 1) / 2 + 1;
            }
        }
        return c;
}