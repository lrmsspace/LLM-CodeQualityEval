/**https://leetcode.com/problems/ransom-note/ */
//Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//Each letter in magazine can only be used once in ransomNote.
// 
//Example 1:
//Input: ransomNote = "a", magazine = "b"
//Output: false
//Example 2:
//Input: ransomNote = "aa", magazine = "ab"
//Output: false
//Example 3:
//Input: ransomNote = "aa", magazine = "aab"
//Output: true
// 
//Constraints:
//	1 <= ransomNote.length, magazine.length <= 105
//	ransomNote and magazine consist of lowercase English letters.
bool canConstruct(char * ransomNote, char * magazine){
    // 哈希表大小
    const int hashSize = 256;
    int* count = (int*)calloc(hashSize, sizeof(int));

    // 记录 magazine 中每个字符的出现次数
    for (int i = 0; magazine[i] != '\0'; i++) {
        count[magazine[i]]++;
    }

    // 检查 ransomNote 中每个字符是否在 magazine 中有足够数量
    for (int i = 0; ransomNote[i] != '\0'; i++) {
        if (count[ransomNote[i]] == 0) {
            free(count);
            return false;
        }
        count[ransomNote[i]]--;
    }

    // 释放内存
    free(count);

    return true;
}