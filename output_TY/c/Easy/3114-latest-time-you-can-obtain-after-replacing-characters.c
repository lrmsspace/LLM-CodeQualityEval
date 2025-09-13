/*
 You are given a string s representing a 12-hour format time where some of the digits (possibly none) are replaced with a "?".
 12-hour times are formatted as "HH:MM", where HH is between 00 and 11, and MM is between 00 and 59. The earliest 12-hour time is 00:00, and the latest is 11:59.
 You have to replace all the "?" characters in s with digits such that the time we obtain by the resulting string is a valid 12-hour format time and is the latest possible.
 Return the resulting string.
 Example 1:
 Input: s = "1?:?4"
 Output: "11:54"
 Explanation: The latest 12-hour format time we can achieve by replacing "?" characters is "11:54".
 Example 2:
 Input: s = "0?:5?"
 Output: "09:59"
 Explanation: The latest 12-hour format time we can achieve by replacing "?" characters is "09:59".
 Constraints:
 s.length == 5
 s[2] is equal to the character ":".
 All characters except s[2] are digits or "?" characters.
 The input is generated such that there is at least one time between "00:00" and "11:59" that you can obtain after replacing the "?" characters.
*/

char* findLatestTime(char* s) {
    char* res = (char*)malloc(6); // 分配结果字符串空间
    res[5] = '\0'; // 字符串结束符

    // 处理小时部分 HH
    if (s[0] == '?' && s[1] == '?') {
        res[0] = '1'; res[1] = '1'; // 最大为 "11"
    } else if (s[0] == '?') {
        if (s[1] <= '1') res[0] = '1'; // 若第二位是0或1，则第一位可以是1
        else res[0] = '0'; // 否则只能是0
    } else if (s[1] == '?') {
        if (s[0] == '1') res[1] = '1'; // 最大为11
        else res[1] = '9'; // 如"0?"，最大为09
    }

    // 处理分钟部分 MM
    if (s[3] == '?') res[3] = '5'; // 第一位最大为5
    else res[3] = s[3];
    
    if (s[4] == '?') res[4] = '9'; // 第二位最大为9
    else res[4] = s[4];

    // 组装结果
    res[0] = s[0] != '?' ? s[0] : res[0];
    res[1] = s[1] != '?' ? s[1] : res[1];
    res[2] = ':'; // 固定格式

    return res;
}