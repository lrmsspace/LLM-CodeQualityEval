/**https://leetcode.com/problems/groups-of-special-equivalent-strings/ */
//You are given an array of strings of the same length words.
//In one move, you can swap any two even indexed characters or any two odd indexed characters of a string words[i].
//Two strings words[i] and words[j] are special-equivalent if after any number of moves, words[i] == words[j].
//	For example, words[i] = "zzxy" and words[j] = "xyzz" are special-equivalent because we may make the moves "zzxy" -> "xzzy" -> "xyzz".
//A group of special-equivalent strings from words is a non-empty subset of words such that:
//	Every pair of strings in the group are special equivalent, and
//	The group is the largest size possible (i.e., there is not a string words[i] not in the group such that words[i] is special-equivalent to every string in the group).
//Return the number of groups of special-equivalent strings from words.
// 
//Example 1:
//Input: words = ["abcd","cdab","cbad","xyzz","zzxy","zzyx"]
//Output: 3
//Explanation: 
//One group is ["abcd", "cdab", "cbad"], since they are all pairwise special equivalent, and none of the other strings is all pairwise special equivalent to these.
//The other two groups are ["xyzz", "zzxy"] and ["zzyx"].
//Note that in particular, "zzxy" is not special equivalent to "zzyx".
//Example 2:
//Input: words = ["abc","acb","bac","bca","cab","cba"]
//Output: 3
// 
//Constraints:
//	1 <= words.length <= 1000
//	1 <= words[i].length <= 20
//	words[i] consist of lowercase English letters.
//	All the strings are of the same length.

bool isSpecialEquiv(char* a, char* b) {
    int len = strlen(a);
    char oddA[26] = {0}, evenA[26] = {0};
    char oddB[26] = {0}, evenB[26] = {0};

    for (int i = 0; i < len; i++) {
        if (i % 2 == 0) {
            evenA[a[i] - 'a']++;
            evenB[b[i] - 'a']++;
        } else {
            oddA[a[i] - 'a']++;
            oddB[b[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (evenA[i] != evenB[i] || oddA[i] != oddB[i]) {
            return false;
        }
    }

    return true;
}

int numSpecialEquivGroups(char** words, int wordsSize) {
    int count = 0;
    bool visited[wordsSize] = {false};

    for (int i = 0; i < wordsSize; i++) {
        if (!visited[i]) {
            count++;
            for (int j = i + 1; j < wordsSize; j++) {
                if (isSpecialEquiv(words[i], words[j])) {
                    visited[j] = true;
                }
            }
        }
    }

    return count;
}   