/*
 You are given a palindromic string s and an integer k.
 Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.
 Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.
 Example 1:
 Input: s = "abba", k = 2
 Output: "baab"
 Explanation:
 The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
 Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".
 Example 2:
 Input: s = "aa", k = 2
 Output: ""
 Explanation:
 There is only one palindromic rearrangement: "aa".
 The output is an empty string since k = 2 exceeds the number of possible rearrangements.
 Example 3:
 Input: s = "bacab", k = 1
 Output: "abcba"
 Explanation:
 The two distinct palindromic rearrangements of "bacab" are "abcba" and "bacab".
 Lexicographically, "abcba" comes before "bacab". Since k = 1, the output is "abcba".
 Constraints:
 1 <= s.length <= 104
 s consists of lowercase English letters.
 s is guaranteed to be palindromic.
 1 <= k <= 106
*/

class Solution {
    public String smallestPalindrome(String s, int k) {
        char[] chars = s.toCharArray();
        int[] count = new int[26];
        for (char c : chars) {
            count[c - 'a']++;
        }
        
        StringBuilder half = new StringBuilder();
        char middle = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                if (middle != 0) {
                    return ""; // More than one odd count, can't form a palindrome
                }
                middle = (char) (i + 'a');
            }
            for (int j = 0; j < count[i] / 2; j++) {
                half.append((char) (i + 'a'));
            }
        }
        
        String halfStr = half.toString();
        TreeSet<String> permutations = new TreeSet<>();
        generatePermutations(halfStr.toCharArray(), 0, permutations);
        
        if (permutations.size() < k) {
            return "";
        }
        
        Iterator<String> iterator = permutations.iterator();
        for (int i = 0; i < k - 1; i++) {
            iterator.next();
        }
        
        String halfPalindrome = iterator.next();
        String reverseHalf = new StringBuilder(halfPalindrome).reverse().toString();
        return middle == 0 ? halfPalindrome + reverseHalf : halfPalindrome + middle + reverseHalf;
    }
    
    private void generatePermutations(char[] chars, int index, TreeSet<String> permutations) {
        if (index == chars.length) {
            permutations.add(new String(chars));
            return;
        }
        for (int i = index; i < chars.length; i++) {
            swap(chars, i, index);
            generatePermutations(chars, index + 1, permutations);
            swap(chars, i, index);
        }
    }
    
    private void swap(char[] chars, int i, int j) {
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }

}