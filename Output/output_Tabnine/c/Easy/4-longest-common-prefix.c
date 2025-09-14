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
    if (strsSize == 0) {
        return "";
    }
    int minLength = strs[0]? strlen(strs[0]) : 0;
    for (int i = 1; i < strsSize; i++) {
        if (strs[i] && strlen(strs[i]) < minLength) {
            minLength = strlen(strs[i]);
        }
    }
    char* prefix = (char*)malloc((minLength + 1) * sizeof(char));
    prefix[minLength] = '\0';
    for (int i = 0; i < minLength; i++) {
        for (int j = 0; j < strsSize; j++) {
            if (strs[j][i]!= strs[0][i]) {
                prefix[i] = '\0';
                return prefix;
            }
        }
        prefix[i] = strs[0][i];
    }
    return prefix;
}