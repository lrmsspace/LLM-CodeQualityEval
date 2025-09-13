/*
 You are given a string s consisting of lowercase English letters, and an integer k.
 Your task is to delete some (possibly none) of the characters in the string so that the number of distinct characters in the resulting string is at most k.
 Return the minimum number of deletions required to achieve this.
 Example 1:
 Input: s = "abc", k = 2
 Output: 1
 Explanation:
 s has three distinct characters: 'a', 'b' and 'c', each with a frequency of 1.
 Since we can have at most k = 2 distinct characters, remove all occurrences of any one character from the string.
 For example, removing all occurrences of 'c' results in at most k distinct characters. Thus, the answer is 1.
 Example 2:
 Input: s = "aabb", k = 2
 Output: 0
 Explanation:
 s has two distinct characters ('a' and 'b') with frequencies of 2 and 2, respectively.
 Since we can have at most k = 2 distinct characters, no deletions are required. Thus, the answer is 0.
 Example 3:
 Input: s = "yyyzz", k = 1
 Output: 2
 Explanation:
 s has two distinct characters ('y' and 'z') with frequencies of 3 and 2, respectively.
 Since we can have at most k = 1 distinct character, remove all occurrences of any one character from the string.
 Removing all 'z' results in at most k distinct characters. Thus, the answer is 2.
 Constraints:
 1 <= s.length <= 16
 1 <= k <= 16
 s consists only of lowercase English letters.
*/

class Solution {
    public int minDeletion(String s, int k) {
        int[] freq = new int[26];
        for(int i = 0; i < s.length(); i++){
            freq[s.charAt(i) - 'a']++;
        }
        int[] freqs = new int[100001];
        for(int i = 0; i < 26; i++){
            freqs[freq[i]]++;
        }
        int deletions = 0;
        for(int i = 100000; i > 0; i--){
            if(freqs[i] == 0){
                deletions += freqs[i];
            } else if(freqs[i] > k){
                deletions += freqs[i] - k;
                freqs[i - 1] += freqs[i] - k;
                freqs[i] = k;
            }
            if(freqs[i] > 0 && freqs[i] <= k){
                k -= freqs[i];
            }
            if(k == 0){
                break;
            }
        }
        return deletions;
            
    }
}