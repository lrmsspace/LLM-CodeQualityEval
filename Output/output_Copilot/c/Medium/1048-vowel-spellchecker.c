/**https://leetcode.com/problems/vowel-spellchecker/ */
//Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.
//For a given query word, the spell checker handles two categories of spelling mistakes:
//	Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
//	
//		Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
//		Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
//		Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
//	
//	
//	Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
//	
//		Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
//		Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
//		Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
//	
//	
//In addition, the spell checker operates under the following precedence rules:
//	When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
//	When the query matches a word up to capitlization, you should return the first such match in the wordlist.
//	When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
//	If the query has no matches in the wordlist, you should return the empty string.
//Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].
// 
//Example 1:
//Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
//Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
//Example 2:
//Input: wordlist = ["yellow"], queries = ["YellOw"]
//Output: ["yellow"]
// 
//Constraints:
//	1 <= wordlist.length, queries.length <= 5000
//	1 <= wordlist[i].length, queries[i].length <= 7
//	wordlist[i] and queries[i] consist only of only English letters.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** spellchecker(char** wordlist, int wordlistSize, char** queries, int queriesSize, int* returnSize) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    int a[5000] = {0};
    int b[5000] = {0};
    int c[5000] = {0};
    int d[5000] = {0};
    int e[5000] = {0};
    int f[5000] = {0};
    int g[5000] = {0};
    int h[5000] = {0};
    char **ret = (char **)malloc(sizeof(char *) * queriesSize);
    for(i = 0; i < queriesSize; i++) {
        ret[i] = (char *)malloc(sizeof(char) * 8);
    }
    for(i = 0; i < wordlistSize; i++) {
        a[i] = strlen(wordlist[i]);
    }
    for(i = 0; i < queriesSize; i++) {
        b[i] = strlen(queries[i]);
    }
    for(i = 0; i < wordlistSize; i++) {
        for(j = 0; j < queriesSize; j++) {
            if(strcmp(wordlist[i], queries[j]) == 0) {
                strcpy(ret[j], wordlist[i]);
                continue;
            }
            if(b[j] == a[i]) {
                for(k = 0; k < b[j]; k++) {
                    if(queries[j][k] >= 'A' && queries[j][k] <= 'Z') {
                        queries[j][k] += 32;
                    }
                    if(wordlist[i][k] >= 'A' && wordlist[i][k] <= 'Z') {
                        wordlist[i][k] += 32;
                    }
                }
                if(strcmp(wordlist[i], queries[j]) == 0) {
                    strcpy(ret[j], wordlist[i]);
                    continue;
                }
                for(k = 0; k < b[j]; k++) {
                    if(queries[j][k] == 'a' || queries[j][k] == 'e' || queries[j][k] == 'i' || queries[j][k] == 'o' || queries[j][k] == 'u') {
                        queries[j][k] = 'a';
                    }
                    if(wordlist[i][k] == 'a' || wordlist[i][k] == 'e' || wordlist[i][k] == 'i' || wordlist[i][k] == 'o' || wordlist[i][k] == 'u') {
                        wordlist[i][k] = 'a';
                    }
                }
            }
        }
    }
    *returnSize = queriesSize;
    return ret;  
}