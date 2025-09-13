/**https://leetcode.com/problems/verbal-arithmetic-puzzle/ */
//Given an equation, represented by words on the left side and the result on the right side.
//You need to check if the equation is solvable under the following rules:
//	Each character is decoded as one digit (0 - 9).
//	No two characters can map to the same digit.
//	Each words[i] and result are decoded as one number without leading zeros.
//	Sum of numbers on the left side (words) will equal to the number on the right side (result).
//Return true if the equation is solvable, otherwise return false.
// 
//Example 1:
//Input: words = ["SEND","MORE"], result = "MONEY"
//Output: true
//Explanation: Map 'S'-> 9, 'E'->5, 'N'->6, 'D'->7, 'M'->1, 'O'->0, 'R'->8, 'Y'->'2'
//Such that: "SEND" + "MORE" = "MONEY" ,  9567 + 1085 = 10652
//Example 2:
//Input: words = ["SIX","SEVEN","SEVEN"], result = "TWENTY"
//Output: true
//Explanation: Map 'S'-> 6, 'I'->5, 'X'->0, 'E'->8, 'V'->7, 'N'->2, 'T'->1, 'W'->'3', 'Y'->4
//Such that: "SIX" + "SEVEN" + "SEVEN" = "TWENTY" ,  650 + 68782 + 68782 = 138214
//Example 3:
//Input: words = ["LEET","CODE"], result = "POINT"
//Output: false
//Explanation: There is no possible mapping to satisfy the equation, so we return false.
//Note that two different characters cannot map to the same digit.
// 
//Constraints:
//	2 <= words.length <= 5
//	1 <= words[i].length, result.length <= 7
//	words[i], result contain only uppercase English letters.
//	The number of different characters used in the expression is at most 10.
class Solution {
    public boolean isSolvable(String[] words, String result) {
// Implement the logic to check if the equation is solvable
public boolean isSolvable(String[] words, String result) {
    // Collect all unique letters
    Set<Character> uniqueLetters = new HashSet<>();
    for (String word : words) {
        for (char c : word.toCharArray()) {
            uniqueLetters.add(c);
        }
    }
    for (char c : result.toCharArray()) {
        uniqueLetters.add(c);
    }

    // If there are more than 10 unique letters, it's impossible to map each to a digit
    if (uniqueLetters.size() > 10) return false;

    // Create a list from the set to iterate over it
    List<Character> letters = new ArrayList<>(uniqueLetters);

    // Start backtracking to find a valid mapping
    return backtrack(words, result, letters, new int[10], new boolean[10], 0);
}

// Helper function to perform backtracking
private boolean backtrack(String[] words, String result, List<Character> letters, int[] map, boolean[] used, int index) {
    if (index == letters.size()) {
        return isValid(words, result, map);
    }

    char letter = letters.get(index);
    for (int digit = 0; digit < 10; digit++) {
        if (!used[digit]) {
            map[letter - 'A'] = digit;
            used[digit] = true;
            if (backtrack(words, result, letters, map, used, index + 1)) {
                return true;
            }
            used[digit] = false;
        }
    }
    return false;
}

// Helper function to check if the current mapping is valid
private boolean isValid(String[] words, String result, int[] map) {
    int sum = 0;
    for (String word : words) {
        if (map[word.charAt(0) - 'A'] == 0 && word.length() > 1) return false; // No leading zero
        sum += mapWord(word, map);
    }
    if (map[result.charAt(0) - 'A'] == 0 && result.length() > 1) return false; // No leading zero
    return sum == mapWord(result, map);
}

// Helper function to calculate the numerical value of a word
private int mapWord(String word, int[] map) {
    int num = 0;
    for (char c : word.toCharArray()) {
        num = num * 10 + map[c - 'A'];
    }
    return num;
}
        
}