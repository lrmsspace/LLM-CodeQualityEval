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
        
        for (int i = 0; i < n; i++) {
            if (n - 1 < k) {
                answer[i] = 0;
                continue;
            }
            
            String[] remainingWords = new String[n - 1];
            for (int j = 0, index = 0; j < n; j++) {
                if (j != i) {
                    remainingWords[index++] = words[j];
                }
            }
            
            answer[i] = findLongestCommonPrefix(remainingWords, k);
        }
        
        return answer;        
    }
}