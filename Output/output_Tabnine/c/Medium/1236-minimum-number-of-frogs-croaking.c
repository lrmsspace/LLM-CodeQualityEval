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
int minNumberOfFrogs(char* croakOfFrogs) {
    int count[5] = {0};
    int frogCount = 0;
    for (char* c = croakOfFrogs; *c; c++) {
        if (*c == 'c') {
            count[0]++;
        } else if (*c == 'r') {
            count[1]++;
        } else if (*c == 'o') {
            count[2]++;
        } else if (*c == 'a') {
            count[3]++;
        } else if (*c == 'k') {
            count[4]++;
            if (count[0] <= 0 || count[1] <= 0 || count[2] <= 0 || count[3] <= 0 || count[4] <= 0) {
                return -1;
            }
            count[0]--;
            count[1]--;
            count[2]--;
            count[3]--;
            count[4]--;
            frogCount++;
        }
    }
    return frogCount;
    
}