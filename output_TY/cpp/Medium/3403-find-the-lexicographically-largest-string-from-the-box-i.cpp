/*
 You are given a string word, and an integer numFriends.
 Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:
 word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
 All the split words are put into a box.
 Find the lexicographically largest string from the box after all the rounds are finished.
 Example 1:
 Input: word = "dbca", numFriends = 2
 Output: "dbc"
 Explanation: 
 All possible splits are:
 "d" and "bca".
 "db" and "ca".
 "dbc" and "a".
 Example 2:
 Input: word = "gggg", numFriends = 4
 Output: "g"
 Explanation: 
 The only possible split is: "g", "g", "g", and "g".
 Constraints:
 1 <= word.length <= 5 * 103
 word consists only of lowercase English letters.
 1 <= numFriends <= word.length
*/

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        int i = 0;
        while(i < n && word[i] == 'a') i++;
        if(i == n) return word;
        int j = n - 1;
        while(j >= 0 && word[j] == 'a') j--;
        if(j < 0) return word;
        int k = i;
        while(k <= j && k < n && word[k] <= word[k - 1]) k++;
        if(k > j) return word;
        int l = k;
        while(l <= j && l < n && word[l] >= word[l - 1]) l++;
        reverse()(word.begin() + k, word.begin() + l);
        return word;
        
    }
};