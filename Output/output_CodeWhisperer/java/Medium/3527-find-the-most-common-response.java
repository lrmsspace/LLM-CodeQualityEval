/*
import java.util.Map;
import java.util.HashSet;
import java.util.HashMap;
import java.util.Set;
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

class Solution {
    public String findCommonResponse(List<List<String>> responses) {
        Map<String, Integer> map = new HashMap<>();
        for (List<String> response : responses) {
            Set<String> set = new HashSet<>();
            for (String s : response) {
                set.add(s);
            }
            for (String s : set) {
                map.put(s, map.getOrDefault(s, 0) + 1);
            }
        }
        int max = 0;

        String result = "";
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            if (entry.getValue() > max) {
                max = entry.getValue();
                result = entry.getKey();
            } else if (entry.getValue() == max) {
                if (entry.getKey().compareTo(result) < 0) {
                    result = entry.getKey();
                }
            }
        }   
        return result;
            
    }
}