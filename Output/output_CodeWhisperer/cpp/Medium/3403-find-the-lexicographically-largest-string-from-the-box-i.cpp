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
        vector<string> box;
        sort(word.begin(), word.end(), greater<char>());
        box.push_back(string(1, word[0]));
        word.erase(word.begin());
        while (!word.empty()) {
            vector<string> newBox;
            for (const string& s : box) {
                for (int i = 0; i <= s.length(); ++i) {
                    string newString = s;
                    newString.insert(newString.begin() + i, word[0]);
                    newBox.push_back(newString);
                }
            }
            sort(newBox.begin(), newBox.end(), greater<string>());
            box = vector<string>(newBox.begin(), newBox.begin() + min(numFriends, (int)newBox.size()));
            word.erase(word.begin());
        }
        sort(box.begin(), box.end(), greater<string>());
        return box[0];        
    }
};