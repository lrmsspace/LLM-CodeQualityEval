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
    
    int i, j, k, n, m, count[26] = {0}, max = 0;
    char *result = (char *)malloc(sizeof(char) * 1001);
    for (i = 0; i < responsesSize; i++) {
        for (j = 0; j < responsesColSize[i]; j++) {
            n = strlen(responses[i][j]);
            for (k = 0; k < n; k++) {
                count[responses[i][j][k] - 'a']++;
            }
        }
    }
    for (i = 0; i < 26; i++) {
        if (count[i] > max) {
            max = count[i];
        }
    }
    for (i = 0; i < 26; i++) {
        if (count[i] == max) {
            result[k++] = i + 'a';
        }
    }   
    return result;
}