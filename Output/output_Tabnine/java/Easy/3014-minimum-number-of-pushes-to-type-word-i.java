/*
 You are given a string word containing distinct lowercase English letters.
 Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .
 It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
 Return the minimum number of pushes needed to type word after remapping the keys.
 An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.
 Example 1:
 Input: word = "abcde"
 Output: 5
 Explanation: The remapped keypad given in the image provides the minimum cost.
 "a" -> one push on key 2
 "b" -> one push on key 3
 "c" -> one push on key 4
 "d" -> one push on key 5
 "e" -> one push on key 6
 Total cost is 1 + 1 + 1 + 1 + 1 = 5.
 It can be shown that no other mapping can provide a lower cost.
 Example 2:
 Input: word = "xycdefghij"
 Output: 12
 Explanation: The remapped keypad given in the image provides the minimum cost.
 "x" -> one push on key 2
 "y" -> two pushes on key 2
 "c" -> one push on key 3
 "d" -> two pushes on key 3
 "e" -> one push on key 4
 "f" -> one push on key 5
 "g" -> one push on key 6
 "h" -> one push on key 7
 "i" -> one push on key 8
 "j" -> one push on key 9
 Total cost is 1 + 2 + 1 + 2 + 1 + 1 + 1 + 1 + 1 + 1 = 12.
 It can be shown that no other mapping can provide a lower cost.
 Constraints:
 1 <= word.length <= 26
 word consists of lowercase English letters.
 All letters in word are distinct.
*/

class Solution {
    public int minimumPushes(String word) {
        // Initialize the cost array with the minimum cost for each key
        int[] cost = new int[10];
        cost[2] = cost[3] = cost[4] = 1;
        cost[5] = cost[6] = cost[7] = cost[8] = cost[9] = 2;
        // Initialize the key array with the corresponding letters for each key
        char[][] key = new char[10][];
        key[2] = new char[] {'a', 'b', 'c'};
        key[3] = new char[] {'d', 'e', 'f'};
        key[4] = new char[] {'g', 'h', 'i'};
        key[5] = new char[] {'j', 'k', 'l'};
        key[6] = new char[] {'m', 'n', 'o'};
        key[7] = new char[] {'p', 'q', 'r','s'};
        key[8] = new char[] {'t', 'u', 'v'};
        key[9] = new char[] {'w', 'x', 'y', 'z'};
        // Initialize the minimum cost and the number of pushes
        int minCost = Integer.MAX_VALUE;
        int numPushes = 0;  
        // Iterate through each letter in the word
        for (char c : word.toCharArray()) {
            // Find the key for the current letter
            int keyIndex = 0;
            for (int i = 2; i <= 9; i++) {
                if (key[i]!= null && Arrays.binarySearch(key[i], c) >= 0) {
                    keyIndex = i;
                    break;
                }
            }
            // Calculate the cost for the current letter and update the minimum cost and number of pushes
            int currentCost = cost[keyIndex];
            if (currentCost < minCost) {
                minCost = currentCost;
            }
            numPushes += currentCost;
        }
        // Return the minimum number of pushes needed to type the word
        return numPushes;
    }
}