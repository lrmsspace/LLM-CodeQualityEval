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
char * longestCommonPrefix(char ** strs, int strsSize){
     if (strsSize == 0) {
        return "";
    }

    // 使用第一个字符串作为初始前缀
    char *prefix = strs[0];
    int prefixLen = strlen(prefix);

    // 遍历字符串数组，从第二个字符串开始
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        // 比较当前前缀和当前字符串
        while (j < prefixLen && j < strlen(strs[i]) && prefix[j] == strs[i][j]) {
            j++;
        }
        // 更新前缀长度
        prefixLen = j;
        // 如果前缀长度为0，直接返回空字符串
        if (prefixLen == 0) {
            return "";
        }
    }

    // 动态分配内存并复制前缀
    char *result = (char *)malloc((prefixLen + 1) * sizeof(char));
    strncpy(result, prefix, prefixLen);
    result[prefixLen] = '\0';

    return result;
}