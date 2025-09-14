/**https://leetcode.com/problems/substring-with-concatenation-of-all-words/ */
//You are given a string s and an array of strings words. All the strings of words are of the same length.
//A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.
//	For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
//Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.
// 
//Example 1:
//Input: s = "barfoothefoobarman", words = ["foo","bar"]
//Output: [0,9]
//Explanation:
//The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
//The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
//Example 2:
//Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
//Output: []
//Explanation:
//There is no concatenated substring.
//Example 3:
//Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
//Output: [6,9,12]
//Explanation:
//The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
//The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
//The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].
// 
//Constraints:
//	1 <= s.length <= 104
//	1 <= words.length <= 5000
//	1 <= words[i].length <= 30
//	s and words[i] consist of lowercase English letters.
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        if (words.length == 0 || s.length() == 0) return res;
        int n = words.length, m = words[0].length();
        Map<String, Integer> count = new HashMap<>();
        for (String word : words) count.put(word, count.getOrDefault(word, 0) + 1);
        for (int i = 0; i <= s.length() - n * m; ++i) {
            Map<String, Integer> seen = new HashMap<>();
            int j = 0;
            for (; j < n; ++j) {
                String word = s.substring(i + j * m, i + (j + 1) * m);
                if (!count.containsKey(word) || seen.put(word, seen.getOrDefault(word, 0) + 1) > count.get(word)) break;
            }
            if (j == n) res.add(i);
        }
        return res;
    }
}