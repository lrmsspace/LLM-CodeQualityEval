/**https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/ */
//You are given an array of strings words and a string chars.
//A string is good if it can be formed by characters from chars (each character can only be used once).
//Return the sum of lengths of all good strings in words.
// 
//Example 1:
//Input: words = ["cat","bt","hat","tree"], chars = "atach"
//Output: 6
//Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
//Example 2:
//Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
//Output: 10
//Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
// 
//Constraints:
//	1 <= words.length <= 1000
//	1 <= words[i].length, chars.length <= 100
//	words[i] and chars consist of lowercase English letters.
int countCharacters(char** words, int wordsSize, char* chars) {
    int i, j, k, l, m, n, len, sum = 0;
    int *charsCount = (int *)malloc(sizeof(int) * 26);
    int *wordCount = (int *)malloc(sizeof(int) * 26);
    for (i = 0; i < wordsSize; i++) {
        memset(charsCount, 0, sizeof(int) * 26);
        memset(wordCount, 0, sizeof(int) * 26);
        len = strlen(words[i]);
        for (j = 0; j < len; j++) {
            wordCount[words[i][j] - 'a']++;
        }
        len = strlen(chars);
        for (j = 0; j < len; j++) {
            charsCount[chars[j] - 'a']++;
        }
        for (j = 0; j < 26; j++) {
            if (wordCount[j] > charsCount[j]) {
                break;
            }
        }
        if (j == 26) {
            sum += len;
        }
    }
    free(charsCount);
    free(wordCount);
    return sum;    
}