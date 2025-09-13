/**https://leetcode.com/problems/number-of-valid-clock-times/ */
//You are given a string of length 5 called time, representing the current time on a digital clock in the format "hh:mm". The earliest possible time is "00:00" and the latest possible time is "23:59".
//In the string time, the digits represented by the ? symbol are unknown, and must be replaced with a digit from 0 to 9.
//Return an integer answer, the number of valid clock times that can be created by replacing every ? with a digit from 0 to 9.
// 
//Example 1:
//Input: time = "?5:00"
//Output: 2
//Explanation: We can replace the ? with either a 0 or 1, producing "05:00" or "15:00". Note that we cannot replace it with a 2, since the time "25:00" is invalid. In total, we have two choices.
//Example 2:
//Input: time = "0?:0?"
//Output: 100
//Explanation: Each ? can be replaced by any digit from 0 to 9, so we have 100 total choices.
//Example 3:
//Input: time = "??:??"
//Output: 1440
//Explanation: There are 24 possible choices for the hours, and 60 possible choices for the minutes. In total, we have 24 * 60 = 1440 choices.
// 
//Constraints:
//	time is a valid string of length 5 in the format "hh:mm".
//	"00" <= hh <= "23"
//	"00" <= mm <= "59"
//	Some of the digits might be replaced with '?' and need to be replaced with digits from 0 to 9.
int countTime(char* time) {
    int n = strlen(time);
    int ans = 0;
    int h[2] = {0, 0}, m[2] = {0, 0};
    for (int i = 0; i < n; ++i) {
        if (time[i] == '?') {
            h[i % 2] = 10;
            m[i % 2] = 6;
        } else {
            h[i % 2] = time[i] - '0';
            m[i % 2] = time[i + 1] - '0';
        }
    }
    for (int i = 0; i <= h[0]; ++i) {
        for (int j = 0; j <= m[0]; ++j) {
            if (i == 2 && j == 4) continue;
            if (i == 3 && j == 6) continue;
            if (i == 4 && j == 8) continue;
            if (i == 5 && j == 0) continue;
            if (i == 6 && j == 2) continue;
            if (i == 7 && j == 4) continue;
            if (i == 8 && j == 6) continue;
            if (i == 9 && j == 8) continue;
            ans += (h[1] - i + 10) * (m[1] - j + 10);
        }
    }
    return ans;
    
}