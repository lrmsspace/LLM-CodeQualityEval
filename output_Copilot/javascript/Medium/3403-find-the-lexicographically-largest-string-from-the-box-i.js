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

/**
 * @param {string} word
 * @param {number} numFriends
 * @return {string}
 */
var answerString = function(word, numFriends) {
    let n = word.length;
    let maxString = "";

    // Generate all possible splits
    function generateSplits(start, currentSplit) {
        if (currentSplit.length === numFriends - 1) {
            // Last part is the rest of the string
            let lastPart = word.slice(start);
            currentSplit.push(lastPart);
            let candidate = currentSplit.join('');
            maxString = maxString < candidate ? candidate : maxString;
            currentSplit.pop();
            return;
        }

        for (let i = start; i < n; i++) {
            let part = word.slice(start, i + 1);
            currentSplit.push(part);
            generateSplits(i + 1, currentSplit);
            currentSplit.pop();
        }
    }

    generateSplits(0, []);
    return maxString;    
};