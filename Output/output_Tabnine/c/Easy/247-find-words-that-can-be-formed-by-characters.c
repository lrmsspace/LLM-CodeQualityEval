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
    int charCount[26] = {0};
    for (int i = 0; chars[i]; ++i) {
        charCount[chars[i] - 'a']++;
    }
    int sum = 0;
    for (int i = 0; i < wordsSize; ++i) {
        int tempCount[26] = {0};
        bool isValid = true;
        for (int j = 0; words[i][j]; ++j) {
            if (charCount[words[i][j] - 'a'] == 0) {
                isValid = false;
                break;
            }
            tempCount[words[i][j] - 'a']++;
        }
        if (isValid) {
            sum += strlen(words[i]);
        }
    }
    return sum;
}