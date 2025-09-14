/**https://leetcode.com/problems/most-common-word/ */
//Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.
//The words in paragraph are case-insensitive and the answer should be returned in lowercase.
// 
//Example 1:
//Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
//Output: "ball"
//Explanation: 
//"hit" occurs 3 times, but it is a banned word.
//"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
//Note that words in the paragraph are not case sensitive,
//that punctuation is ignored (even if adjacent to words, such as "ball,"), 
//and that "hit" isn't the answer even though it occurs more because it is banned.
//Example 2:
//Input: paragraph = "a.", banned = []
//Output: "a"
// 
//Constraints:
//	1 <= paragraph.length <= 1000
//	paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
//	0 <= banned.length <= 100
//	1 <= banned[i].length <= 10
//	banned[i] consists of only lowercase English letters.
char* mostCommonWord(char* paragraph, char** banned, int bannedSize) {
    char* result = (char*)malloc(sizeof(char) * 1000);
    int resultSize = 0;
    int* hash = (int*)malloc(sizeof(int) * 1000);
    memset(hash, 0, sizeof(int) * 1000);
    int i = 0;
    while (paragraph[i] != '\0') {
        if (paragraph[i] >= 'A' && paragraph[i] <= 'Z') {
            paragraph[i] = paragraph[i] - 'A' + 'a';
        }
        if (paragraph[i] >= 'a' && paragraph[i] <= 'z') {
            hash[paragraph[i]]++;
        }
        else {
            hash[0]++;
        }
        i++;
    }
    int max = 0;
    for (i = 0; i < bannedSize; i++) {
        int j = 0;
        while (banned[i][j] != '\0') {
            hash[banned[i][j]] = -1;
            j++;
        }
    }
    for (i = 0; i < 1000; i++) {
        if (hash[i] > max) {
            max = hash[i];
            resultSize = 0;
            result[resultSize++] = i;
        }
        else if (hash[i] == max) {
            result[resultSize++] = i;
        }
    }
    result[resultSize] = '\0';
    return result;
    
}