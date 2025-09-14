/**https://leetcode.com/problems/odd-string-difference/ */
//You are given an array of equal-length strings words. Assume that the length of each string is n.
//Each string words[i] can be converted into a difference integer array difference[i] of length n - 1 where difference[i][j] = words[i][j+1] - words[i][j] where 0 <= j <= n - 2. Note that the difference between two letters is the difference between their positions in the alphabet i.e. the position of 'a' is 0, 'b' is 1, and 'z' is 25.
//	For example, for the string "acb", the difference integer array is [2 - 0, 1 - 2] = [2, -1].
//All the strings in words have the same difference integer array, except one. You should find that string.
//Return the string in words that has different difference integer array.
// 
//Example 1:
//Input: words = ["adc","wzy","abc"]
//Output: "abc"
//Explanation: 
//- The difference integer array of "adc" is [3 - 0, 2 - 3] = [3, -1].
//- The difference integer array of "wzy" is [25 - 22, 24 - 25]= [3, -1].
//- The difference integer array of "abc" is [1 - 0, 2 - 1] = [1, 1]. 
//The odd array out is [1, 1], so we return the corresponding string, "abc".
//Example 2:
//Input: words = ["aaa","bob","ccc","ddd"]
//Output: "bob"
//Explanation: All the integer arrays are [0, 0] except for "bob", which corresponds to [13, -13].
// 
//Constraints:
//	3 <= words.length <= 100
//	n == words[i].length
//	2 <= n <= 20
//	words[i] consists of lowercase English letters.
char* oddString(char** words, int wordsSize) {
    int* diff = (int*)malloc(sizeof(int) * (wordsSize - 1));
    int* count = (int*)malloc(sizeof(int) * wordsSize);
    memset(count, 0, sizeof(int) * wordsSize);
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < strlen(words[i]) - 1; j++) {
            diff[j] = words[i][j + 1] - words[i][j];
        }
        for (int j = i - 1; j >= 0; j--) {
            int k;
            for (k = 0; k < strlen(words[i]) - 1; k++) {
                if (diff[k] != (words[j][k + 1] - words[j][k])) {
                    break;
                }
            }
            if (k == strlen(words[i]) - 1) {
                count[i] = count[j];
                break;
            }
        }
        if (count[i] == 0) {
            count[i] = i + 1;
        }
    }
    for (int i = 0; i < wordsSize; i++) {
        if (count[i] != count[0]) {
            return words[i];
        }
    }
    return "";
    
}