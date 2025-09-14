/**https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/ */
//Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
// 
//Example 1:
//Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
//Output: "apple"
//Example 2:
//Input: s = "abpcplea", dictionary = ["a","b","c"]
//Output: "a"
// 
//Constraints:
//	1 <= s.length <= 1000
//	1 <= dictionary.length <= 1000
//	1 <= dictionary[i].length <= 1000
//	s and dictionary[i] consist of lowercase English letters.
char * findLongestWord(char * s, char ** dictionary, int dictionarySize){
    int i, j, k, l, m, n, o, p, q, r, t, u, v, w, x, y, z;
    int a[1000], b[1000];
    int c[1000][1000];
    int d[1000][1000];
    int e[1000][1000];
    int f[1000][1000];
    int g[1000][1000];
   int h[1000][1000];
    int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;
    int j1, j2, j3, j4, j5, j6, j7, j8, j9, j10;
    int k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;
    for (i = 0; i < dictionarySize; i++) {
        for (j = 0; j < 1000; j++) {
            a[j] = 0;
            b[j] = 0;
        }
    }
    for (i = 0; i < dictionarySize; i++) {
        for (j = 0; j < strlen(dictionary[i]); j++) {
            a[j] = dictionary[i][j];
        }
        for (j = 0; j < strlen(sentence); j++) {
            b[j] = sentence[j];
        }
        for (i1 = 0; i1 <= strlen(sentence); i1++) {
            for (i2 = 0; i2 <= strlen(dictionary[i]); i2++) {
                if (a[i2] == b[i1]) {
                    if (i2 == strlen(dictionary[i])) {
                        return strlen(dictionary[i]);
                    }
                    i1++;
                }
            }
        }
    }
    return 0;
}