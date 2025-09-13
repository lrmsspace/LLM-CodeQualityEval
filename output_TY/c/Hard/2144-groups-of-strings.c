/**https://leetcode.com/problems/groups-of-strings/ */
//You are given a 0-indexed array of strings words. Each string consists of lowercase English letters only. No letter occurs more than once in any string of words.
//Two strings s1 and s2 are said to be connected if the set of letters of s2 can be obtained from the set of letters of s1 by any one of the following operations:
//	Adding exactly one letter to the set of the letters of s1.
//	Deleting exactly one letter from the set of the letters of s1.
//	Replacing exactly one letter from the set of the letters of s1 with any letter, including itself.
//The array words can be divided into one or more non-intersecting groups. A string belongs to a group if any one of the following is true:
//	It is connected to at least one other string of the group.
//	It is the only string present in the group.
//Note that the strings in words should be grouped in such a manner that a string belonging to a group cannot be connected to a string present in any other group. It can be proved that such an arrangement is always unique.
//Return an array ans of size 2 where:
//	ans[0] is the maximum number of groups words can be divided into, and
//	ans[1] is the size of the largest group.
// 
//Example 1:
//Input: words = ["a","b","ab","cde"]
//Output: [2,3]
//Explanation:
//- words[0] can be used to obtain words[1] (by replacing 'a' with 'b'), and words[2] (by adding 'b'). So words[0] is connected to words[1] and words[2].
//- words[1] can be used to obtain words[0] (by replacing 'b' with 'a'), and words[2] (by adding 'a'). So words[1] is connected to words[0] and words[2].
//- words[2] can be used to obtain words[0] (by deleting 'b'), and words[1] (by deleting 'a'). So words[2] is connected to words[0] and words[1].
//- words[3] is not connected to any string in words.
//Thus, words can be divided into 2 groups ["a","b","ab"] and ["cde"]. The size of the largest group is 3.  
//Example 2:
//Input: words = ["a","ab","abc"]
//Output: [1,3]
//Explanation:
//- words[0] is connected to words[1].
//- words[1] is connected to words[0] and words[2].
//- words[2] is connected to words[1].
//Since all strings are connected to each other, they should be grouped together.
//Thus, the size of the largest group is 3.
// 
//Constraints:
//	1 <= words.length <= 2 * 104
//	1 <= words[i].length <= 26
//	words[i] consists of lowercase English letters only.
//	No letter occurs more than once in words[i].
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* groupStrings(char ** words, int wordsSize, int* returnSize){
    int *ret = (int *)malloc(2 * sizeof(int));
    int *cnt = (int *)calloc(26, sizeof(int));
    int *cnts = (int *)calloc(26, sizeof(int));
    int *groups = (int *)calloc(26, sizeof(int));
    int *group_size = (int *)calloc(26, sizeof(int));
    int *group_max = (int *)calloc(26, sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        int len = strlen(words[i]);
        memset(cnt, 0, sizeof(int) * 26);
        for (int j = 0; j < len; j++) {
            cnt[words[i][j] - 'a']++;
        }
        int *p = cnt;
        int *q = cnts;
        for (int j = 0; j < 26; j++) {
            if (cnt[j] > 0) {
                *q++ = cnt[j];
            }
}
    }
    for (int i = 0; i < 26; i++) {
        int *p = cnts;
        int *q = cnts + 1;
        int *r = groups;
        int *s = group_size;
        int *t = group_max;
        int group = 0;
        int size = 0;
        int max = 0;
        while (q - cnts < 26){
            if (*p == *q) {
                *r++ = group;
                *s++ = size;
                *t++ = max;
                group = 0;
                size = 0;
                max = 0;
            } else {
                group++;
                size += *p;
                max = max < *p ? *p : max;
            }
        }
    }
    ret[0] = groups[0];
    ret[1] = group_max[0];
    *returnSize = 2;
    return ret;
}