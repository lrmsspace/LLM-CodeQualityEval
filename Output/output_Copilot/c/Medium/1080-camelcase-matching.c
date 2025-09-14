/**https://leetcode.com/problems/camelcase-matching/ */
//Given an array of strings queries and a string pattern, return a boolean array answer where answer[i] is true if queries[i] matches pattern, and false otherwise.
//A query word queries[i] matches pattern if you can insert lowercase English letters pattern so that it equals the query. You may insert each character at any position and you may not insert any characters.
// 
//Example 1:
//Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
//Output: [true,false,true,true,false]
//Explanation: "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
//"FootBall" can be generated like this "F" + "oot" + "B" + "all".
//"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
//Example 2:
//Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
//Output: [true,false,true,false,false]
//Explanation: "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
//"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
//Example 3:
//Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
//Output: [false,true,false,false,false]
//Explanation: "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
// 
//Constraints:
//	1 <= pattern.length, queries.length <= 100
//	1 <= queries[i].length <= 100
//	queries[i] and pattern consist of English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* camelMatch(char** queries, int queriesSize, char* pattern, int* returnSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[100] = {0};
    int b[100] = {0};
    int c[100] = {0};
    int d[100] = {0};
    int e[100] = {0};
    int f[100] = {0};
    int g[100] = {0};
    int h[100] = {0};
    bool *ret = (bool *)malloc(sizeof(bool) * queriesSize);
    for(i = 0; i < queriesSize; i++) {
        ret[i] = true;
    }
    for(i = 0; i < queriesSize; i++) {
        a[i] = strlen(queries[i]);
    }
    b[0] = strlen(pattern);
    for(i = 0; i < queriesSize; i++) {
        for(j = 0; j < a[i]; j++) {
            if(queries[i][j] >= 'A' && queries[i][j] <= 'Z') {
                if(k < b[0] && queries[i][j] == pattern[k]) {
                    k++;
                } else {
                    ret[i] = false;
                    break;
                }
            }
        }
        if(k < b[0]) {
            ret[i] = false;
        }
    }
    *returnSize = queriesSize;
    return ret;  
}