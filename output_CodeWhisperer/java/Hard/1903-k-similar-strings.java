/**https://leetcode.com/problems/k-similar-strings/ */
//Strings s1 and s2 are k-similar (for some non-negative integer k) if we can swap the positions of two letters in s1 exactly k times so that the resulting string equals s2.
//Given two anagrams s1 and s2, return the smallest k for which s1 and s2 are k-similar.
// 
//Example 1:
//Input: s1 = "ab", s2 = "ba"
//Output: 1
//Explanation: The two string are 1-similar because we can use one swap to change s1 to s2: "ab" --> "ba".
//Example 2:
//Input: s1 = "abc", s2 = "bca"
//Output: 2
//Explanation: The two strings are 2-similar because we can use two swaps to change s1 to s2: "abc" --> "bac" --> "bca".
// 
//Constraints:
//	1 <= s1.length <= 20
//	s2.length == s1.length
//	s1 and s2 contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}.
//	s2 is an anagram of s1.
class Solution {
    public int kSimilarity(String s1, String s2) {
        if (s1.equals(s2)) {
            return 0;
        }
        int n = s1.length();
        char[] arr1 = s1.toCharArray();
        char[] arr2 = s2.toCharArray();
        int i = 0;
        while (i < n && arr1[i] == arr2[i]) {
            i++;
        }
        for (int j = i + 1; j < n; j++) {
            if (arr1[j] == arr2[i]) {
                char tmp = arr1[j];
                arr1[j] = arr1[i];
                arr1[i] = tmp;
                return 1 + kSimilarity(new String(arr1), s2);
            }
        }
        char tmp = arr1[i];
        for (int j = i + 1; j < n; j++) {
            if (arr1[j] == arr2[i]) {
                arr1[i] = arr1[j];
                arr1[j] = tmp;
                return 1 + kSimilarity(new String(arr1), s2);
            }
        }
        return Integer.MAX_VALUE;       
    }
}