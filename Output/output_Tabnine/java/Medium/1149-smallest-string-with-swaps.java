/**https://leetcode.com/problems/smallest-string-with-swaps/ */
//You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
//You can swap the characters at any pair of indices in the given pairs any number of times.
//Return the lexicographically smallest string that s can be changed to after using the swaps.
// 
//Example 1:
//Input: s = "dcab", pairs = [[0,3],[1,2]]
//Output: "bacd"
//Explaination: 
//Swap s[0] and s[3], s = "bcad"
//Swap s[1] and s[2], s = "bacd"
//Example 2:
//Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
//Output: "abcd"
//Explaination: 
//Swap s[0] and s[3], s = "bcad"
//Swap s[0] and s[2], s = "acbd"
//Swap s[1] and s[2], s = "abcd"
//Example 3:
//Input: s = "cba", pairs = [[0,1],[1,2]]
//Output: "abc"
//Explaination: 
//Swap s[0] and s[1], s = "bca"
//Swap s[1] and s[2], s = "bac"
//Swap s[0] and s[1], s = "abc"
// 
//Constraints:
//	1 <= s.length <= 10^5
//	0 <= pairs.length <= 10^5
//	0 <= pairs[i][0], pairs[i][1] < s.length
//	s only contains lower case English letters.
class Solution {
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        int n = s.length();
        List<Integer>[] indexMap = new List[n];
        for (int i = 0; i < n; i++) {
            indexMap[i] = new ArrayList<>();
        }
        for (List<Integer> pair : pairs) {
            indexMap[pair.get(0)].add(pair.get(1));
            indexMap[pair.get(1)].add(pair.get(0));
        }
        
        char[] chars = s.toCharArray();
        for (int i = 0; i < n; i++) {
            int minIndex = i;
            for (int j : indexMap[i]) {
                if (chars[j] < chars[minIndex]) {
                    minIndex = j;
                }
            }
            swap(chars, i, minIndex);
        }
        
        return new String(chars);
        
    }
}