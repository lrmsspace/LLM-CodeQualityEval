/**https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/ */
//Two strings word1 and word2 are considered almost equivalent if the differences between the frequencies of each letter from 'a' to 'z' between word1 and word2 is at most 3.
//Given two strings word1 and word2, each of length n, return true if word1 and word2 are almost equivalent, or false otherwise.
//The frequency of a letter x is the number of times it occurs in the string.
// 
//Example 1:
//Input: word1 = "aaaa", word2 = "bccb"
//Output: false
//Explanation: There are 4 'a's in "aaaa" but 0 'a's in "bccb".
//The difference is 4, which is more than the allowed 3.
//Example 2:
//Input: word1 = "abcdeef", word2 = "abaaacc"
//Output: true
//Explanation: The differences between the frequencies of each letter in word1 and word2 are at most 3:
//- 'a' appears 1 time in word1 and 4 times in word2. The difference is 3.
//- 'b' appears 1 time in word1 and 1 time in word2. The difference is 0.
//- 'c' appears 1 time in word1 and 2 times in word2. The difference is 1.
//- 'd' appears 1 time in word1 and 0 times in word2. The difference is 1.
//- 'e' appears 2 times in word1 and 0 times in word2. The difference is 2.
//- 'f' appears 1 time in word1 and 0 times in word2. The difference is 1.
//Example 3:
//Input: word1 = "cccddabba", word2 = "babababab"
//Output: true
//Explanation: The differences between the frequencies of each letter in word1 and word2 are at most 3:
//- 'a' appears 2 times in word1 and 4 times in word2. The difference is 2.
//- 'b' appears 2 times in word1 and 5 times in word2. The difference is 3.
//- 'c' appears 3 times in word1 and 0 times in word2. The difference is 3.
//- 'd' appears 2 times in word1 and 0 times in word2. The difference is 2.
// 
//Constraints:
//	n == word1.length == word2.length
//	1 <= n <= 100
//	word1 and word2 consist only of lowercase English letters.
bool checkAlmostEquivalent(char * word1, char * word2){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z, a, b, c, d, e, f, g, h, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    a = b = c = d = e = f = g = h= j = k = l = m = n = o = p = q
    r = s = t = u = v = w = x = y = z = 0;
    for (i = 0; i < strlen(word1); i++) {
        if (word1[i] == 'a') a++;
        else if (word1[i] == 'b') b++;
        else if (word1[i] == 'c') c++;
        else if (word1[i] == 'd') d++;
        else if (word1[i] == 'e') e++;
        else if (word1[i] == 'f') f++;
    }
    for (i = 0; i < strlen(word2); i++) {
        if (word2[i] == 'a') a--;
        else if (word2[i] == 'b') b--;
        else if (word2[i] == 'c') c--;
        else if (word2[i] == 'd') d--;
        else if (word2[i] == 'e') e--;
        else if (word2[i] == 'f') f--;
    }
    if (abs(a) <= 3 && abs(b) <= 3 && abs(c) <= 3 && abs(d) <= 3 && abs(e) <= 3 && abs(f) <= 3) return true;
    else return false;
}