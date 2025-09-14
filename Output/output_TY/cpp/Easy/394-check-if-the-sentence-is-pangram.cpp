/**https://leetcode.com/problems/check-if-the-sentence-is-pangram/ */
//A pangram is a sentence where every letter of the English alphabet appears at least once.
//Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
// 
//Example 1:
//Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
//Output: true
//Explanation: sentence contains at least one of every letter of the English alphabet.
//Example 2:
//Input: sentence = "leetcode"
//Output: false
// 
//Constraints:
//	1 <= sentence.length <= 1000
//	sentence consists of lowercase English letters.
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int i = 0;
        int j = 0;
        int count = 0;
        int arr[26] = {0};
        while(i < sentence.length())
        {
            if(arr[sentence[i] - 'a'] == 0)
            {
                arr[sentence[i] - 'a'] = 1;
                count++;
            }
            i++;
        }
        if(count == 26)
            return true;
        else
            return false;
    }
};