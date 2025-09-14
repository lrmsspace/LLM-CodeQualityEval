/**https://leetcode.com/problems/longest-well-performing-interval/ */
//We are given hours, a list of the number of hours worked per day for a given employee.
//A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.
//A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.
//Return the length of the longest well-performing interval.
// 
//Example 1:
//Input: hours = [9,9,6,0,6,6,9]
//Output: 3
//Explanation: The longest well-performing interval is [9,9,6].
//Example 2:
//Input: hours = [6,6,6]
//Output: 0
// 
//Constraints:
//	1 <= hours.length <= 104
//	0 <= hours[i] <= 16
int longestWPI(int* hours, int hoursSize) {
    int max = 0;
    int sum = 0;
    int first[10001];
    memset(first, -1, sizeof(first));
    for (int i = 0; i < hoursSize; i++) {
        sum += (hours[i] > 8) ? 1 : -1;
        if (sum > 0) {
            max = i + 1;
        } else {
            if (first[sum + 10000] == -1) {
                first[sum + 10000] = i;
            }
            if (first[sum - 1 + 10000] != -1) {
                max = fmax(max, i - first[sum - 1 + 10000]);
            }
        }
    }
    return max;
}