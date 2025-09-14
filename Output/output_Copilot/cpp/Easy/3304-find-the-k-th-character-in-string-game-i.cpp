/*
 Alice and Bob are playing a game. Initially, Alice has a string word = "a".
 You are given a positive integer k.
 Now Bob will ask Alice to perform the following operation forever:
 Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
 For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
 Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.
 Note that the character 'z' can be changed to 'a' in the operation.
 Example 1:
 Input: k = 5
 Output: "b"
 Explanation:
 Initially, word = "a". We need to do the operation three times:
 Generated string is "b", word becomes "ab".
 Generated string is "bc", word becomes "abbc".
 Generated string is "bccd", word becomes "abbcbccd".
 Example 2:
 Input: k = 10
 Output: "c"
 Constraints:
 1 <= k <= 500
*/

class Solution {
public:
    char kthCharacter(int k) {
        // Calculate the number of operations needed to reach at least k characters
        int operations = 0;
        int length = 1; // Initial length of the word "a"

        while (length < k) {
            operations++;
            length += operations; // Each operation adds 'operations' characters
        }

        // Find the character at position k after enough operations
        int index = k - 1; // Convert to 0-based index
        char result = 'a' + (index % 26); // Calculate the character based on the index

        return result;
        
    }
};