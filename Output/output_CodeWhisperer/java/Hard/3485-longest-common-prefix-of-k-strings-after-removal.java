/*
 You are given an array of strings words and an integer k.
 For each index i in the range [0, words.length - 1], find the length of the longest common prefix among any k strings (selected at distinct indices) from the remaining array after removing the ith element.
 Return an array answer, where answer[i] is the answer for ith element. If removing the ith element leaves the array with fewer than k strings, answer[i] is 0.
 Example 1:
 Input: words = ["jump","run","run","jump","run"], k = 2
 Output: [3,4,4,3,4]
 Explanation:
 Removing index 0 ("jump"):
 words becomes: ["run", "run", "jump", "run"]. "run" occurs 3 times. Choosing any two gives the longest common prefix "run" (length 3).
 Removing index 1 ("run"):
 words becomes: ["jump", "run", "jump", "run"]. "jump" occurs twice. Choosing these two gives the longest common prefix "jump" (length 4).
 Removing index 2 ("run"):
 words becomes: ["jump", "run", "jump", "run"]. "jump" occurs twice. Choosing these two gives the longest common prefix "jump" (length 4).
 Removing index 3 ("jump"):
 words becomes: ["jump", "run", "run", "run"]. "run" occurs 3 times. Choosing any two gives the longest common prefix "run" (length 3).
 Removing index 4 ("run"):
 words becomes: ["jump", "run", "run", "jump"]. "jump" occurs twice. Choosing these two gives the longest common prefix "jump" (length 4).
 Example 2:
 Input: words = ["dog","racer","car"], k = 2
 Output: [0,0,0]
 Explanation:
 Removing any index results in an answer of 0.
 Constraints:
 1 <= k <= words.length <= 105
 1 <= words[i].length <= 104
 words[i] consists of lowercase English letters.
 The sum of words[i].length is smaller than or equal 105.
*/
class Solution {
    public int[] longestCommonPrefix(String[] words, int k) {
        int n = words.length;
        int[] answer = new int[n];
        
        // For each index i
        for (int i = 0; i < n; i++) {
            // Create a map to store frequency of each string after removing ith element
            Map<String, Integer> freq = new HashMap<>();
            
            // Add all strings except ith element to frequency map
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    freq.put(words[j], freq.getOrDefault(words[j], 0) + 1);
                }
            }
            
            int maxLen = 0;
            // For each string that appears at least k times
            for (String s : freq.keySet()) {
                if (freq.get(s) >= k) {
                    maxLen = Math.max(maxLen, s.length());
                }
            }
            
            // If no string appears k times, try finding common prefix
            if (maxLen == 0 && n - 1 >= k) {
                // Try all possible prefixes
                for (int len = 1; len <= 10000; len++) {
                    Map<String, Integer> prefixFreq = new HashMap<>();
                    boolean valid = true;
                    
                    // Count frequency of prefixes
                    for (int j = 0; j < n; j++) {
                        if (j == i) continue;
                        if (len > words[j].length()) {
                            valid = false;
                            break;
                        }
                        String prefix = words[j].substring(0, len);
                        prefixFreq.put(prefix, prefixFreq.getOrDefault(prefix, 0) + 1);
                    }
                    
                    // Check if any prefix appears k times
                    boolean found = false;
                    if (valid) {
                        for (int count : prefixFreq.values()) {
                            if (count >= k) {
                                found = true;
                                maxLen = len;
                                break;
                            }
                        }
                    }
                    
                    if (!found) break;
                }
            }
            
            answer[i] = maxLen;
        }
        
        return answer;
    }
}           