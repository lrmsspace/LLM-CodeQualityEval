/**https://leetcode.com/problems/largest-time-for-given-digits/ */
//Given an array arr of 4 digits, find the latest 24-hour time that can be made using each digit exactly once.
//24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.
//Return the latest 24-hour time in "HH:MM" format. If no valid time can be made, return an empty string.
// 
//Example 1:
//Input: arr = [1,2,3,4]
//Output: "23:41"
//Explanation: The valid 24-hour times are "12:34", "12:43", "13:24", "13:42", "14:23", "14:32", "21:34", "21:43", "23:14", and "23:41". Of these times, "23:41" is the latest.
//Example 2:
//Input: arr = [5,5,5,5]
//Output: ""
//Explanation: There are no valid 24-hour times as "55:55" is not valid.
// 
//Constraints:
//	arr.length == 4
//	0 <= arr[i] <= 9
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int max_h = 24;
        int max_m = 60;
        int max_time = 0;
        int max_hours = 0;
        int max_minutes = 0;
        int max_hours_index = 0;
        int max_minutes_index = 0;
        int max_hours_index_2 = 0;
        int max_minutes_index_2 = 0;
        int max_hours_index_3 = 0;
        int max_minutes_index_3 = 0;
        int max_hours_index_4 = 0;
        int max_minutes_index_4 = 0;
        for (int i = 0; i < n; i++){
            if (arr[i] < 2){
                max_hours = arr[i] * 10 + arr[i + 1];
                max_hours_index = i;
                i++;
            }
            else{
                max_minutes = arr[i] * 10 + arr[i + 1];
                max_minutes_index = i;
                i++;
            }
        }
        for (int i = 0; i < n; i++){
            if (i != max_hours_index && i != max_minutes_index){
                if (arr[i] < 2){
                    int temp = arr[i] * 10 + arr[i + 1];
                    if (temp < max_hours){
                        max_hours = temp;
                        max_hours_index_2 = i;
                        i++;
                    }
                }
                else{
                    int temp = arr[i] * 10 + arr[i + 1];
                    if (temp < max_minutes){
                        max_minutes= temp;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (i != max_hours_index && i != max_minutes_index && i != max_hours_index_2){
                if (arr[i] < 2){
                    int temp = arr[i] * 10 + arr[i + 1];
                    if (temp < max_hours){
                        max_hours = temp;
                        max_hours_index_3 = i;
                        i++;
                    }
                }
                else{
                    int temp = arr[i] * 10 + arr[i + 1];
                    if (temp < max_minutes){
                        max_minutes = temp;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (i != max_hours_index && i != max_minutes_index && i != max_hours_index_2 && i != max_hours_index_3){
                if (arr[i] < 2){
                    int temp = arr[i] * 10 + arr[i + 1];
                    if (temp < max_hours){
                        max_hours = temp;
                        max_hours_index_4 = i;
                        i++;
                    }
                }
                else{
                    int temp = arr[i] * 10 + arr[i +1];
                    if (temp < max_minutes){
                        max_minutes = temp;
                    }
                    i++;
                    if (i == n - 1){
                        max_minutes_index_4 = i;
                    }
                    max_time = max_hours * 100 + max_minutes;
                    return to_string(max_hours) + ":" + to_string(max_minutes);
                }
            }
        }
        return "";
    }
};