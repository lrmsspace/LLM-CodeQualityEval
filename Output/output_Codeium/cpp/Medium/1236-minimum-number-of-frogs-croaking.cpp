/**https://leetcode.com/problems/minimum-number-of-frogs-croaking/ */
//You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.
//Return the minimum number of different frogs to finish all the croaks in the given string.
//A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.
// 
//Example 1:
//Input: croakOfFrogs = "croakcroak"
//Output: 1 
//Explanation: One frog yelling "croak" twice.
//Example 2:
//Input: croakOfFrogs = "crcoakroak"
//Output: 2 
//Explanation: The minimum number of frogs is two. 
//The first frog could yell "crcoakroak".
//The second frog could yell later "crcoakroak".
//Example 3:
//Input: croakOfFrogs = "croakcrook"
//Output: -1
//Explanation: The given string is an invalid combination of "croak" from different frogs.
// 
//Constraints:
//	1 <= croakOfFrogs.length <= 105
//	croakOfFrogs is either 'c', 'r', 'o', 'a', or 'k'.
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> counts(5, 0); // to track 'c', 'r', 'o', 'a', 'k'
        int maxFrogs = 0, currentFrogs = 0;
        
        for (char ch : croakOfFrogs) {
            if (ch == 'c') {
                counts[0]++;
                currentFrogs++;
            } else if (ch == 'r') {
                counts[1]++;
            } else if (ch == 'o') {
                counts[2]++;
            } else if (ch == 'a') {
                counts[3]++;
            } else if (ch == 'k') {
                counts[4]++;
                currentFrogs--;
            }
            
            // Check if the sequence is correct
            if (counts[1] > counts[0] || counts[2] > counts[1] || counts[3] > counts[2] || counts[4] > counts[3]) {
                return -1;
            }
            
            maxFrogs = max(maxFrogs, currentFrogs);
        }
        
        // All counts should be equal for a valid sequence
        if (counts[0] == counts[1] && counts[1] == counts[2] && counts[2] == counts[3] && counts[3] == counts[4]) {
            return maxFrogs;
        } else {
            return -1;
        }

    }
};