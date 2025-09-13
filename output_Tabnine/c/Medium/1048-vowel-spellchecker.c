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
    int i, j, k, m;
    int wordlistLen = wordlistSize;
    int queriesLen = queriesSize;
    char** result = (char**)malloc(queriesLen * sizeof(char*));
    *returnSize = queriesLen;
    
    for(i = 0; i < queriesLen; i++) {
        result[i] = (char*)malloc(8 * sizeof(char));
        strcpy(result[i], "");
    }
    
    // Convert all words to lowercase
    for(i = 0; i < wordlistLen; i++) {
        for(j = 0; wordlist[i][j]; j++) {
            wordlist[i][j] = tolower(wordlist[i][j]);
        }
    }
    
    // Create a map for quick lookup of words in wordlist
    char** wordMap = (char**)malloc(wordlistLen * sizeof(char*));
    for(i = 0; i < wordlistLen; i++) {
        wordMap[i] = (char*)malloc(8 * sizeof(char));
        strcpy(wordMap[i], wordlist[i]);
    }
    
    // Sort the wordlist in lexicographical order
    qsort(wordlist, wordlistLen, sizeof(char*), compare);
    
    // Iterate through each query
    for(i = 0; i < queriesLen; i++) {
        // Convert query to lowercase
        for(j = 0; queries[i][j]; j++) {
            queries[i][j] = tolower(queries[i][j]);
        }
        
        // Check for exact match in wordlist
        for(j = 0; j < wordlistLen; j++) {
            if(strcmp(queries[i], wordlist[j]) == 0) {
                strcpy(result[i], wordlist[j]);
                break;
            }
        }
        
        // Check for match up to capitalization
        if(strcmp(result[i], "") == 0) {
            for(j = 0; j < wordlistLen; j++) {
                if(strcmp(queries[i], wordlist[j]) == 0) {
                    strcpy(result[i], wordlist[j]);
                    break;
                }
            }
        }
        
        // Check for match up to vowel errors
        if(strcmp(result[i], "") == 0) {
            for(j = 0; j < wordlistLen; j++) {
                int count = 0;
                for(k = 0; k < 7 && queries[i][k] && wordlist[j][k]; k++) {
                    if(queries[i][k]!= wordlist[j][k]) {
                        if(isVowel(queries[i][k]) && isVowel(wordlist[j][k])) {
                            count++;
                        }
                    }
                }
                if(count == 1) {
                    strcpy(result[i], wordlist[j]);
                    break;
                }
            }
        }
        
        // If no match found, return an empty string
        if(strcmp(result[i], "") == 0) {
            strcpy(result[i], " ");
        }
    }
    
    // Free up memory
    for(i = 0; i < wordlistLen; i++) {
        free(wordMap[i]);
    }
    free(wordMap);
    
    return result;
}