/**https://leetcode.com/problems/valid-anagram/ */
//Given two strings s and t, return true if t is an anagram of s, and false otherwise.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// 
//Example 1:
//Input: s = "anagram", t = "nagaram"
//Output: true
//Example 2:
//Input: s = "rat", t = "car"
//Output: false
// 
//Constraints:
//	1 <= s.length, t.length <= 5 * 104
//	s and t consist of lowercase English letters.
// 
//Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
bool isAnagram(char * s, char * t){
    if (strlen(s) != strlen(t)) {
        return false;
    }

    // 创建一个计数数组，用于记录每个字符的出现次数
    int count[256] = {0};

    // 遍历字符串 s，增加对应字符的计数
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i]]++;
    }

    // 遍历字符串 t，减少对应字符的计数
    for (int i = 0; t[i] != '\0'; i++) {
        count[t[i]]--;
        // 如果某个字符的计数小于 0，说明 t 中有额外的字符，返回 false
        if (count[t[i]] < 0) {
            return false;
        }
    }

    // 如果所有字符的计数都为 0，说明 t 是 s 的一个变位词
    return true;
}