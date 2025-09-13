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
    int c = 0, r = 0, o = 0, a = 0, k = 0, max = 0;
    for (int i = 0; croakOfFrogs[i] != '\0'; i++) {
        switch (croakOfFrogs[i]) {
            case 'c':
                c++;
                break;
            case 'r':
                r++;
                break;
            case 'o':
                o++;
                break;
            case 'a':
                a++;
                break;
            case 'k':
                k++;
                break;
        }
        if (c < r || r < o || o < a || a < k) {
            return -1;
        }
        max = fmax(max, c);
    }
    if (c == r && r == o && o == a && a == k) {
        return max;
    }
    return -1;    
}