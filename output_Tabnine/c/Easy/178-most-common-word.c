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
    // Convert paragraph to lowercase
    for (int i = 0; paragraph[i]; ++i) {
        if (paragraph[i] >= 'A' && paragraph[i] <= 'Z') {
            paragraph[i] += 'a' - 'A';
        }
    }
    
    // Replace punctuation marks with spaces
    for (int i = 0; paragraph[i]; ++i) {
        if (strchr("!?,;.\"", paragraph[i])) {
            paragraph[i] ='';
        }
    }
    
    // Split paragraph into words
    char* words[1000];
    int wordCount = 0;
    char* word = strtok(paragraph, " ");
    while (word) {
        words[wordCount++] = word;
        word = strtok(NULL, " ");
    }
    
    // Count word occurrences
    int wordCounts[100] = {0};
    for (int i = 0; i < wordCount; ++i) {
        if (wordCounts[i] == 0 && bannedSize == 0) {
            for (int j = 0; j < bannedSize; ++j) {
                if (strcmp(words[i], banned[j]) == 0) {
                    wordCounts[i] = -1;
                    break;
                }
            }
        }
        if (wordCounts[i]!= -1) {
            ++wordCounts[i];
        }
    }
    
    // Find the most frequent non-banned word
    int maxCount = 0;
    int mostFrequentWordIndex = -1;
    for (int i = 0; i < wordCount; ++i) {
        if (wordCounts[i] > maxCount && wordCounts[i]!= -1) {
            maxCount = wordCounts[i];
            mostFrequentWordIndex = i;
        }
    }
    
    // Return the most frequent non-banned word
    return words[mostFrequentWordIndex];
}