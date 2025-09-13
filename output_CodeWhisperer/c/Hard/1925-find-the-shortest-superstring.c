/**https://leetcode.com/problems/find-the-shortest-superstring/ */
//Given an array of strings words, return the smallest string that contains each string in words as a substring. If there are multiple valid strings of the smallest length, return any of them.
//You may assume that no string in words is a substring of another string in words.
// 
//Example 1:
//Input: words = ["alex","loves","leetcode"]
//Output: "alexlovesleetcode"
//Explanation: All permutations of "alex","loves","leetcode" would also be accepted.
//Example 2:
//Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
//Output: "gctaagttcatgcatc"
// 
//Constraints:
//	1 <= words.length <= 12
//	1 <= words[i].length <= 20
//	words[i] consists of lowercase English letters.
//	All the strings of words are unique.    
int calculateOverlap(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int maxOverlap = 0;
    
    // Try all possible overlaps
    for (int i = 1; i <= len1 && i <= len2; i++) {
        // Check if suffix of s1 matches prefix of s2
        if (strncmp(s1 + len1 - i, s2, i) == 0) {
            maxOverlap = i;
        }
    }
    
    return maxOverlap;
}

// Function to reconstruct the path from dp table
void reconstructPath(int** dp, int** parent, int** overlap, char** words, int n, int mask, int last, char* result) {
    // Base case: if only one word is left
    if (mask == (1 << last)) {
        strcpy(result, words[last]);
        return;
    }
    
    int prevMask = mask & ~(1 << last);
    int prev = parent[prevMask][last];
    
    // Reconstruct the path recursively
    reconstructPath(dp, parent, overlap, words, n, prevMask, prev, result);
    
    // Append the current word with overlap
    int overlapLen = overlap[prev][last];
    strcat(result, words[last] + overlapLen);
}

char* shortestSuperstring(char** words, int wordsSize) {
    int n = wordsSize;
    
    // Calculate overlap between each pair of words
    int** overlap = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        overlap[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (i != j) {
                overlap[i][j] = calculateOverlap(words[i], words[j]);
            } else {
                overlap[i][j] = 0;
            }
        }
    }
    
    // dp[mask][last] = minimum length of superstring covering all words in mask and ending with word 'last'
    int** dp = (int**)malloc((1 << n) * sizeof(int*));
    for (int i = 0; i < (1 << n); i++) {
        dp[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    
    // parent[mask][last] = previous word in the optimal path
    int** parent = (int**)malloc((1 << n) * sizeof(int*));
    for (int i = 0; i < (1 << n); i++) {
        parent[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            parent[i][j] = -1;
        }
    }
    
    // Base case: single word
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = strlen(words[i]);
    }
    
    // Fill dp table
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int last = 0; last < n; last++) {
            // If last word is not in the mask, skip
            if (!(mask & (1 << last))) continue;
            
            // If only one word in mask, already handled in base case
            if (mask == (1 << last)) continue;
            
            // Try all possible previous words
            int prevMask = mask & ~(1 << last);
            for (int prev = 0; prev < n; prev++) {
                if (!(prevMask & (1 << prev))) continue;
                
                int newLength = dp[prevMask][prev] + strlen(words[last]) - overlap[prev][last];
                if (newLength < dp[mask][last]) {
                    dp[mask][last] = newLength;
                    parent[mask][last] = prev;
                }
            }
        }
    }
    
    // Find the ending word that gives the shortest superstring
    int minLength = INT_MAX;
    int lastWord = -1;
    int fullMask = (1 << n) - 1;
    
    for (int i = 0; i < n; i++) {
        if (dp[fullMask][i] < minLength) {
            minLength = dp[fullMask][i];
            lastWord = i;
        }
    }
    
    // Allocate memory for the result
    char* result = (char*)malloc((minLength + 1) * sizeof(char));
    result[0] = '\0';
    
    // Reconstruct the shortest superstring
    reconstructPath(dp, parent, overlap, words, n, fullMask, lastWord, result);
    
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(overlap[i]);
    }
    free(overlap);
    
    for (int i = 0; i < (1 << n); i++) {
        free(dp[i]);
        free(parent[i]);
    }
    free(dp);
    free(parent);
    
    return result;
}