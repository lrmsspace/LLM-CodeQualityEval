/**https://leetcode.com/problems/longest-common-prefix/ */
//Write a function to find the longest common prefix string amongst an array of strings.
//If there is no common prefix, return an empty string "".
// 
//Example 1:
//Input: strs = ["flower","flow","flight"]
//Output: "fl"
//Example 2:
//Input: strs = ["dog","racecar","car"]
//Output: ""
//Explanation: There is no common prefix among the input strings.
// 
//Constraints:
//	1 <= strs.length <= 200
//	0 <= strs[i].length <= 200
//	strs[i] consists of only lowercase English letters.
char* longestCommonPrefix(char** strs, int strsSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    char* result = (char*)malloc(201 * sizeof(char));
    result[0] = '\0';
    if (strsSize == 0) {
        return result;
    }
    for (i = 0; i < strlen(strs[0]); i++) {
        for (j = 1; j < strsSize; j++) {
            if (i >= strlen(strs[j]) || strs[j][i] != strs[0][i]) {
                return result;
            }
        }
        result[i] = strs[0][i];
        result[i + 1] = '\0';
    }
    return result;
    
}