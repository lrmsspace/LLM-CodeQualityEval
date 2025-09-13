/**https://leetcode.com/problems/isomorphic-strings/ */
//Given two strings s and t, determine if they are isomorphic.
//Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
// 
//Example 1:
//Input: s = "egg", t = "add"
//Output: true
//Example 2:
//Input: s = "foo", t = "bar"
//Output: false
//Example 3:
//Input: s = "paper", t = "title"
//Output: true
// 
//Constraints:
//	1 <= s.length <= 5 * 104
//	t.length == s.length
//	s and t consist of any valid ascii character.
bool isIsomorphic(char * s, char * t){
    if (strlen(s) != strlen(t)) {
        return false;
    }

    // 创建两个哈希表，用于存储字符之间的映射关系
    int mapS[256] = {0}; // 从 s 到 t 的映射
    int mapT[256] = {0}; // 从 t 到 s 的映射

    for (int i = 0; s[i] != '\0'; i++) {
        char charS = s[i];
        char charT = t[i];

        // 检查当前字符是否已经映射
        if (mapS[charS] == 0 && mapT[charT] == 0) {
            // 如果没有映射，建立新的映射关系
            mapS[charS] = charT;
            mapT[charT] = charS;
        } else {
            // 如果已有映射，检查映射是否一致
            if (mapS[charS] != charT || mapT[charT] != charS) {
                return false;
            }
        }
    }
    return true;
}