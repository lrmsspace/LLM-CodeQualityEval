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
    int croak[5] = {0};
    int frogs = 0, max_frogs = 0;
    for (int i = 0; croakOfFrogs[i] != '\0'; i++) {
        switch (croakOfFrogs[i]) {
            case 'c':
                croak[0]++;
                frogs++;
                break;
            case 'r':
                croak[1]++;
                break;
            case 'o':
                croak[2]++;
                break;
            case 'a':
                croak[3]++;
                break;
            case 'k':
                croak[4]++;
                frogs--;
                break;
        }
        for (int j = 0; j < 4; j++) {
            if (croak[j] < croak[j + 1]) return -1;
        }
        max_frogs = fmax(max_frogs, frogs);
    }
    return frogs == 0 ? max_frogs : -1;
}