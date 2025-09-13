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
    char* word = (char*)malloc(1000 * sizeof(char));
    char* words[1000];
    int count[1000] = {0}, max = 0, i = 0, j = 0, k = 0, l = 0;
    while (paragraph[i] != '\0') {
        if (paragraph[i] == ' ' || paragraph[i] == '!' || paragraph[i] == '?' || paragraph[i] == '\'' || paragraph[i] == ',' || paragraph[i] == ';' || paragraph[i] == '.') {
            if (l > 0) {
                word[l] = '\0';
                words[k] = (char*)malloc((l + 1) * sizeof(char));
                strcpy(words[k], word);
                l = 0;
                k++;
            }
        } else {
            word[l] = tolower(paragraph[i]);
            l++;
        }
        i++;
    }
    if (l > 0) {
        word[l] = '\0';
        words[k] = (char*)malloc((l + 1) * sizeof(char));
        strcpy(words[k], word);
        k++;
    }
    for (i = 0; i < bannedSize; i++) {
        for (j = 0; j < k; j++) {
            if (strcmp(words[j], banned[i]) == 0) {
                count[j] = -1;
            }
        }
    }
    for (i = 0; i < k; i++) {
        if (count[i] != -1) {
            count[i] = 1;
            for (j = i + 1; j < k; j++) {
                if (strcmp(words[i], words[j]) == 0) {
                    count[i]++;
                    count[j] = -1;
                }
            }
            if (count[i] > max) {
                max = count[i];
                j = i;
            }
        }
    }
    return words[j];
}