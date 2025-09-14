/*
 You are given an array of strings words. Find all shortest common supersequences (SCS) of words that are not permutations of each other.
 A shortest common supersequence is a string of minimum length that contains each string in words as a subsequence.
 Return a 2D array of integers freqs that represent all the SCSs. Each freqs[i] is an array of size 26, representing the frequency of each letter in the lowercase English alphabet for a single SCS. You may return the frequency arrays in any order.
 Example 1:
 Input: words = ["ab","ba"]
 Output: [[1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],[2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
 Explanation:
 The two SCSs are "aba" and "bab". The output is the letter frequencies for each one.
 Example 2:
 Input: words = ["aa","ac"]
 Output: [[2,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
 Explanation:
 The two SCSs are "aac" and "aca". Since they are permutations of each other, keep only "aac".
 Example 3:
 Input: words = ["aa","bb","cc"]
 Output: [[2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]
 Explanation:
 "aabbcc" and all its permutations are SCSs.
 Constraints:
 1 <= words.length <= 256
 words[i].length == 2
 All strings in words will altogether be composed of no more than 16 unique lowercase letters.
 All strings in words are unique.
*/

class Solution {
    public List<List<Integer>> supersequences(String[] words) {
        Set<String> scsSet = new HashSet<>();
        
        for (String word : words) {
            char first = word.charAt(0);
            char second = word.charAt(1);
            
            String scs1 = "" + first + second + first;
            String scs2 = "" + second + first + second;
            
            scsSet.add(scs1);
            scsSet.add(scs2);
        }
        
        List<List<Integer>> freqs = new ArrayList<>();
        
        for (String scs : scsSet) {
            List<Integer> freq = new ArrayList<>();
            
            for (int i = 0; i < 26; i++) {
                freq.add(0);
            }
            
            for (char c : scs.toCharArray()) {
                freq.set(c - 'a', freq.get(c - 'a') + 1);
            }
            
            freqs.add(freq);
        }
        
        return freqs;

    }
}