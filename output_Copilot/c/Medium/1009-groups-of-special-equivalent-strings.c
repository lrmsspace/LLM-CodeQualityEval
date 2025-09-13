/**https://leetcode.com/problems/groups-of-special-equivalent-strings/ */
//You are given an array of strings of the same length words.
//In one move, you can swap any two even indexed characters or any two odd indexed characters of a string words[i].
//Two strings words[i] and words[j] are special-equivalent if after any number of moves, words[i] == words[j].
//	For example, words[i] = "zzxy" and words[j] = "xyzz" are special-equivalent because we may make the moves "zzxy" -> "xzzy" -> "xyzz".
//A group of special-equivalent strings from words is a non-empty subset of words such that:
//	Every pair of strings in the group are special equivalent, and
//	The group is the largest size possible (i.e., there is not a string words[i] not in the group such that words[i] is special-equivalent to every string in the group).
//Return the number of groups of special-equivalent strings from words.
// 
//Example 1:
//Input: words = ["abcd","cdab","cbad","xyzz","zzxy","zzyx"]
//Output: 3
//Explanation: 
//One group is ["abcd", "cdab", "cbad"], since they are all pairwise special equivalent, and none of the other strings is all pairwise special equivalent to these.
//The other two groups are ["xyzz", "zzxy"] and ["zzyx"].
//Note that in particular, "zzxy" is not special equivalent to "zzyx".
//Example 2:
//Input: words = ["abc","acb","bac","bca","cab","cba"]
//Output: 3
// 
//Constraints:
//	1 <= words.length <= 1000
//	1 <= words[i].length <= 20
//	words[i] consist of lowercase English letters.
//	All the strings are of the same length.
int numSpecialEquivGroups(char** words, int wordsSize) {
    int i, j, k, n = 0;
    int len = strlen(words[0]);
    char *s1, *s2;
    char *s = (char *)malloc(sizeof(char) * len * 2);
    char *p = (char *)malloc(sizeof(char) * len * 2);
    int *a = (int *)malloc(sizeof(int) * 26);
    int *b = (int *)malloc(sizeof(int) * 26);
    int *c = (int *)malloc(sizeof(int) * 26);
    for (i = 0; i < wordsSize; i++) {
        s1 = (char *)malloc(sizeof(char) * len);
        s2 = (char *)malloc(sizeof(char) * len);
        for (j = 0; j < len; j++) {
            s1[j] = words[i][j];
            s2[j] = words[i][j];
        }
        for (j = 0; j < len; j++) {
            if (j % 2 == 0) {
                s[j] = s1[j / 2];
            } else {
                s[j] = s2[j / 2];
            }
        }
        for (j = 0; j < len; j++) {
            p[j] = s[j];
        }
        for (j = 0; j < 26; j++) {
            a[j] = 0;
            b[j] = 0;
            c[j] = 0;
        }
        for (j = 0; j < len; j++) {
            if (j % 2 == 0) {
                a[s[j] - 'a']++;
            } else {
                b[s[j] - 'a']++;
            }
        }
        for (j = 0; j < len; j++) {
            if (j % 2 == 0) {
                c[s[j] - 'a']++;
            } else {
                c[s[j] - 'a']--;
            }
        }
        for (j = 0; j < 26; j++) {
            if (a[j] != b[j] || b[j] != c[j]) {
                break;
            }
        }
        if (j == 26) {
            n++;
        }
    }
    return n;    
}