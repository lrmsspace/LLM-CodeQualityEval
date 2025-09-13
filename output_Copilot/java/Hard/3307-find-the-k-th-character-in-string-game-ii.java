/*
 Alice and Bob are playing a game. Initially, Alice has a string word = "a".
 You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.
 Now Bob will ask Alice to perform all operations in sequence:
 If operations[i] == 0, append a copy of word to itself.
 If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
 Return the value of the kth character in word after performing all the operations.
 Note that the character 'z' can be changed to 'a' in the second type of operation.
 Example 1:
 Input: k = 5, operations = [0,0,0]
 Output: "a"
 Explanation:
 Initially, word == "a". Alice performs the three operations as follows:
 Appends "a" to "a", word becomes "aa".
 Appends "aa" to "aa", word becomes "aaaa".
 Appends "aaaa" to "aaaa", word becomes "aaaaaaaa".
 Example 2:
 Input: k = 10, operations = [0,1,0,1]
 Output: "b"
 Explanation:
 Initially, word == "a". Alice performs the four operations as follows:
 Appends "a" to "a", word becomes "aa".
 Appends "bb" to "aa", word becomes "aabb".
 Appends "aabb" to "aabb", word becomes "aabbaabb".
 Appends "bbccbbcc" to "aabbaabb", word becomes "aabbaabbbbccbbcc".
 Constraints:
 1 <= k <= 1014
 1 <= operations.length <= 100
 operations[i] is either 0 or 1.
 The input is generated such that word has at least k characters after all operations.
*/

class Solution {
    public char kthCharacter(long k, int[] operations) {
        long length = 1; // Initial length of the string "a"
        for (int op : operations) {
            if (op == 0) {
                length *= 2; // Doubling the length
            } else {
                length = length * 2 + (length / 2); // Doubling and adding the next character transformation
            }
        }

        // Find the k-th character by tracing back through the operations
        for (int i = operations.length - 1; i >= 0; i--) {
            if (k > length) {
                return 'a'; // If k is out of bounds, return 'a'
            }
            if (operations[i] == 0) {
                if (k > length / 2) {
                    k -= length / 2; // Adjust k to the second half
                }
            } else {
                if (k > length / 2) {
                    k -= length / 2; // Adjust k to the second half
                    k--; // Move to the next character in the alphabet
                }
            }
            length /= (operations[i] == 0 ? 2 : 1.5); // Reduce the effective length based on operation type
        }

        return (char) ('a' + (k - 1)); // Convert k to character, adjusting for zero-based index    
            
    }
}