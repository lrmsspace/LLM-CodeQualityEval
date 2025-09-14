/**https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/ */
//You are given a 0-indexed string hamsters where hamsters[i] is either:
//	'H' indicating that there is a hamster at index i, or
//	'.' indicating that index i is empty.
//You will add some number of food buckets at the empty indices in order to feed the hamsters. A hamster can be fed if there is at least one food bucket to its left or to its right. More formally, a hamster at index i can be fed if you place a food bucket at index i - 1 and/or at index i + 1.
//Return the minimum number of food buckets you should place at empty indices to feed all the hamsters or -1 if it is impossible to feed all of them.
// 
//Example 1:
//Input: hamsters = "H..H"
//Output: 2
//Explanation: We place two food buckets at indices 1 and 2.
//It can be shown that if we place only one food bucket, one of the hamsters will not be fed.
//Example 2:
//Input: hamsters = ".H.H."
//Output: 1
//Explanation: We place one food bucket at index 2.
//Example 3:
//Input: hamsters = ".HHH."
//Output: -1
//Explanation: If we place a food bucket at every empty index as shown, the hamster at index 2 will not be able to eat.
// 
//Constraints:
//	1 <= hamsters.length <= 105
//	hamsters[i] is either'H' or '.'.
int minimumBuckets(char* hamsters) {
    int len = strlen(hamsters);
    int i, count = 0, left = 0, right = 0;
    for (i = 0; i < len; i++) {
        if (hamsters[i] == 'H') {
            count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    if (count == 1) {
        return 1;
    }
    for (i = 0; i < len; i++) {
        if (hamsters[i] == 'H') {
            left = i;
            break;
        }
    }
    for (i = len - 1; i >= 0; i--) {
        if (hamsters[i] == 'H') {
            right = i;
            break;
        }
    }
    if (left == right) {
        return 1;
    }
    if (right - left + 1 > count) {
        return -1;
    }
    return count;    
}