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

/**
 * @param {string[][]} responses
 * @return {string}
 */
var findCommonResponse = function(responses) {
    // Create a map to store the frequency of each response
    let frequencyMap = new Map();
    
    // Iterate through each response array
    for (let responseArray of responses) {
        // Remove duplicates within each response array
        let uniqueResponses = [...new Set(responseArray)];
        
        // Update the frequency of each unique response
        for (let response of uniqueResponses) {
            frequencyMap.set(response, (frequencyMap.get(response) || 0) + 1);
        }
    }
    
    // Find the response with the highest frequency
    let maxFrequency = 0;
    let mostCommonResponse = null;
    for (let [response, frequency] of frequencyMap) {
        if (frequency > maxFrequency) {
            maxFrequency = frequency;
            mostCommonResponse = response;
        } else if (frequency === maxFrequency && response < mostCommonResponse) {
            mostCommonResponse = response;
        }
    }
    return mostCommonResponse;
    
};