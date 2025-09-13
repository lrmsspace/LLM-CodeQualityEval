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
char * mostCommonWord(char * paragraph, char ** banned, int bannedSize){
    // 初始化哈希表
    Node *hashTable[HASH_SIZE] = {NULL};

    // 将段落中的所有字母转换为小写，并去除标点符号
    char *token = strtok(paragraph, " ,.;:!?'\"-");
    while (token) {
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }
        insertOrUpdate(hashTable, token);
        token = strtok(NULL, " ,.;:!?'\"-");
    }

    // 将禁用词加入哈希表
    for (int i = 0; i < bannedSize; i++) {
        insertOrUpdate(hashTable, banned[i]);
    }

    // 找到频率最高的非禁用词
    char *mostCommon = NULL;
    int maxCount = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        Node *current = hashTable[i];
        while (current) {
            int isBanned = 0;
            for (int j = 0; j < bannedSize; j++) {
                if (strcmp(current->word, banned[j]) == 0) {
                    isBanned = 1;
                    break;
                }
            }
            if (!isBanned && current->count > maxCount) {
                maxCount = current->count;
                mostCommon = current->word;
            }
            current = current->next;
        }
    }

    // 释放哈希表
    freeHashTable(hashTable);

    return mostCommon;
}