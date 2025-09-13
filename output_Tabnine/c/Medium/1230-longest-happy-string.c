/**https://leetcode.com/problems/longest-happy-string/ */
//A string s is called happy if it satisfies the following conditions:
//	s only contains the letters 'a', 'b', and 'c'.
//	s does not contain any of "aaa", "bbb", or "ccc" as a substring.
//	s contains at most a occurrences of the letter 'a'.
//	s contains at most b occurrences of the letter 'b'.
//	s contains at most c occurrences of the letter 'c'.
//Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
//A substring is a contiguous sequence of characters within a string.
// 
//Example 1:
//Input: a = 1, b = 1, c = 7
//Output: "ccaccbcc"
//Explanation: "ccbccacc" would also be a correct answer.
//Example 2:
//Input: a = 7, b = 1, c = 0
//Output: "aabaa"
//Explanation: It is the only correct answer in this case.
// 
//Constraints:
//	0 <= a, b, c <= 100
//	a + b + c > 0
char* longestDiverseString(int a, int b, int c) {
    // Initialize the result string
    char* result = (char*)malloc(sizeof(char) * (a + b + c + 1));
    result[a + b + c] = '\0';
    
    // Initialize the counts of each character
    int counts[3] = {a, b, c};
    
    // Initialize the last positions of each character
    int lastPositions[3] = {-1, -1, -1};
    
    // Sort the counts in descending order
    qsort(counts, 3, sizeof(int), compareFunc);
    
    // Iterate through the characters in descending order
    for (int i = 2; i >= 0; i--) {
        // Find the next available position for the current character
        int nextPosition = -1;
        for (int j = 0; j < 3; j++) {
            if (counts[i] > 0 && (lastPositions[j] == -1 || lastPositions[j] < nextPosition)) {
                nextPosition = lastPositions[j];
            }
        }
        
        // Add the current character to the result string
        for (int j = 0; j < counts[i]; j++) {
            result[nextPosition + j] = "abc"[i];
        }
        
        // Update the last position of the current character
        lastPositions[i] = nextPosition + counts[i] - 1;
        
        // Decrement the count of the current character
        counts[i]--;
    }
    
    return result;
    
}