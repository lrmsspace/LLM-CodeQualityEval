/**https://leetcode.com/problems/word-pattern/ */
//Given a pattern and a string s, find if s follows the same pattern.
//Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
// 
//Example 1:
//Input: pattern = "abba", s = "dog cat cat dog"
//Output: true
//Example 2:
//Input: pattern = "abba", s = "dog cat cat fish"
//Output: false
//Example 3:
//Input: pattern = "aaaa", s = "dog cat cat dog"
//Output: false
// 
//Constraints:
//	1 <= pattern.length <= 300
//	pattern contains only lower-case English letters.
//	1 <= s.length <= 3000
//	s contains only lowercase English letters and spaces ' '.
//	s does not contain any leading or trailing spaces.
//	All the words in s are separated by a single space.
bool wordPattern(char * pattern, char * s){
    // 哈希表大小
    const int hashSize = 128;
    char* wordToPattern[hashSize] = {0};
    char patternToWord[hashSize] = {0};

    // 分割字符串 s 为单词
    char* token = strtok(s, " ");
    int patternIndex = 0;

    while (token != NULL && pattern[patternIndex] != '\0') {
        char ch = pattern[patternIndex];

        // 检查当前单词和模式字符是否已经映射
        if (wordToPattern[ch] == NULL && patternToWord[ch] == 0) {
            // 如果没有映射，建立新的映射
            wordToPattern[ch] = strdup(token);
            patternToWord[ch] = 1;
        } else {
            // 如果已经有映射，检查是否一致
            if (wordToPattern[ch] == NULL || strcmp(wordToPattern[ch], token) != 0) {
                return false;
            }
        }

        // 获取下一个单词
        token = strtok(NULL, " ");
        patternIndex++;
    }

    // 检查是否所有单词和模式字符都已匹配
    if (token != NULL || pattern[patternIndex] != '\0') {
        return false;
    }

    return true;
}