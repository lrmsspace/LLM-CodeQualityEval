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
    
/**
 * Converts a string to lowercase
 */
char* toLowerCase(const char* word) {
    int len = strlen(word);
    char* lower = (char*)malloc((len + 1) * sizeof(char));
    
    for (int i = 0; i < len; i++) {
        lower[i] = tolower(word[i]);
    }
    lower[len] = '\0';
    
    return lower;
}

/**
 * Creates a vowel-agnostic pattern by replacing vowels with '*'
 */
char* getVowelPattern(const char* word) {
    int len = strlen(word);
    char* pattern = (char*)malloc((len + 1) * sizeof(char));
    
    for (int i = 0; i < len; i++) {
        char c = tolower(word[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            pattern[i] = '*';
        } else {
            pattern[i] = c;
        }
    }
    pattern[len] = '\0';
    
    return pattern;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** spellchecker(char** wordlist, int wordlistSize, char** queries, int queriesSize, int* returnSize) {
    // Allocate memory for results
    char** result = (char**)malloc(queriesSize * sizeof(char*));
    *returnSize = queriesSize;
    
    // Create hash tables for case-insensitive matches and vowel-agnostic matches
    // In C, we'll use arrays to simulate hash tables
    char** lowerCaseWords = (char**)malloc(wordlistSize * sizeof(char*));
    char** vowelPatterns = (char**)malloc(wordlistSize * sizeof(char*));
    int* firstOccurrence = (int*)malloc(wordlistSize * sizeof(int));
    
    for (int i = 0; i < wordlistSize; i++) {
        lowerCaseWords[i] = toLowerCase(wordlist[i]);
        vowelPatterns[i] = getVowelPattern(wordlist[i]);
        firstOccurrence[i] = -1;
    }
    
    // Process each query
    for (int i = 0; i < queriesSize; i++) {
        char* query = queries[i];
        bool found = false;
        
        // Case 1: Exact match
        for (int j = 0; j < wordlistSize; j++) {
            if (strcmp(query, wordlist[j]) == 0) {
                result[i] = strdup(wordlist[j]);
                found = true;
                break;
            }
        }
        
        // Case 2: Case-insensitive match
        if (!found) {
            char* lowerQuery = toLowerCase(query);
            for (int j = 0; j < wordlistSize; j++) {
                if (strcmp(lowerQuery, lowerCaseWords[j]) == 0) {
                    result[i] = strdup(wordlist[j]);
                    found = true;
                    break;
                }
            }
            free(lowerQuery);
        }
        
        // Case 3: Vowel-agnostic match
        if (!found) {
            char* vowelPattern = getVowelPattern(query);
            for (int j = 0; j < wordlistSize; j++) {
                if (strcmp(vowelPattern, vowelPatterns[j]) == 0) {
                    result[i] = strdup(wordlist[j]);
                    found = true;
                    break;
                }
            }
            free(vowelPattern);
        }
        
        // No match found
        if (!found) {
            result[i] = strdup("");
        }
    }
    
    // Clean up
    for (int i = 0; i < wordlistSize; i++) {
        free(lowerCaseWords[i]);
        free(vowelPatterns[i]);
    }
    free(lowerCaseWords);
    free(vowelPatterns);
    free(firstOccurrence);
    
    return result;
}
