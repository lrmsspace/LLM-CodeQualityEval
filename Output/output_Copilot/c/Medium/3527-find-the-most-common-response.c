/*
 You are given a 2D string array responses where each responses[i] is an array of strings representing survey responses from the ith day.
 Return the most common response across all days after removing duplicate responses within each responses[i]. If there is a tie, return the lexicographically smallest response.
 Example 1:
 Input: responses = [["good","ok","good","ok"],["ok","bad","good","ok","ok"],["good"],["bad"]]
 Output: "good"
 Explanation:
 After removing duplicates within each list, responses = [["good", "ok"], ["ok", "bad", "good"], ["good"], ["bad"]].
 "good" appears 3 times, "ok" appears 2 times, and "bad" appears 2 times.
 Return "good" because it has the highest frequency.
 Example 2:
 Input: responses = [["good","ok","good"],["ok","bad"],["bad","notsure"],["great","good"]]
 Output: "bad"
 Explanation:
 After removing duplicates within each list we have responses = [["good", "ok"], ["ok", "bad"], ["bad", "notsure"], ["great", "good"]].
 "bad", "good", and "ok" each occur 2 times.
 The output is "bad" because it is the lexicographically smallest amongst the words with the highest frequency.
 Constraints:
 1 <= responses.length <= 1000
 1 <= responses[i].length <= 1000
 1 <= responses[i][j].length <= 10
 responses[i][j] consists of only lowercase English letters
*/

char* findCommonResponse(char*** responses, int responsesSize, int* responsesColSize) {
    // Frequency map to count occurrences of each response
    int freq[1001] = {0};
    char* mostCommon = NULL;
    int maxCount = 0;

    for (int i = 0; i < responsesSize; i++) {
        // Use a set to track unique responses for the day
        int seen[1001] = {0};
        for (int j = 0; j < responsesColSize[i]; j++) {
            int idx = responses[i][j][0] - 'a';
            if (!seen[idx]) {
                seen[idx] = 1;
                freq[idx]++;
                // Update most common response
                if (freq[idx] > maxCount || (freq[idx] == maxCount && mostCommon && strcmp(responses[i][j], mostCommon) < 0)) {
                    maxCount = freq[idx];
                    mostCommon = responses[i][j];
                }
            }
        }
    }

    return mostCommon;
}