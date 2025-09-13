/*
 You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.
 You can apply the following operation on any of the two strings any number of times:
 Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
 Return true if you can make the strings s1 and s2 equal, and false otherwise.
 Example 1:
 Input: s1 = "abcdba", s2 = "cabdab"
 Output: true
 Explanation: We can apply the following operations on s1:
 - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
 - Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
 - Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
 Example 2:
 Input: s1 = "abe", s2 = "bea"
 Output: false
 Explanation: It is not possible to make the two strings equal.
 Constraints:
 n == s1.length == s2.length
 1 <= n <= 105
 s1 and s2 consist only of lowercase English letters.
*/

class Solution {
    public boolean checkStrings(String s1, String s2) {
        char[] odd1 = new char[s1.length()/2];
        char[] odd2 = new char[s2.length()/2];
        char[] even1 = new char[s1.length()/2];
        char[] even2 = new char[s2.length()/2];
        int oddIndex = 0;
        int evenIndex = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                even1[evenIndex] = s1.charAt(i);
                even2[evenIndex] = s2.charAt(i);
                evenIndex++;
            } else {
                odd1[oddIndex] = s1.charAt(i);
                odd2[oddIndex] = s2.charAt(i);
                oddIndex++;
            }
        }
        Arrays.sort(odd1);
        Arrays.sort(odd2);
        Arrays.sort(even1);
        Arrays.sort(even2);
        return Arrays.equals(odd1, odd2) && Arrays.equals(even1, even2);
           
    }
}