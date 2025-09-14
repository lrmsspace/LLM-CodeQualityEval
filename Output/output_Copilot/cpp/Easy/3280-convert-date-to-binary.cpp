/*
 You are given a string date representing a Gregorian calendar date in the yyyy-mm-dd format.
 date can be written in its binary representation obtained by converting year, month, and day to their binary representations without any leading zeroes and writing them down in year-month-day format.
 Return the binary representation of date.
 Example 1:
 Input: date = "2080-02-29"
 Output: "100000100000-10-11101"
 Explanation:
 100000100000, 10, and 11101 are the binary representations of 2080, 02, and 29 respectively.
 Example 2:
 Input: date = "1900-01-01"
 Output: "11101101100-1-1"
 Explanation:
 11101101100, 1, and 1 are the binary representations of 1900, 1, and 1 respectively.
 Constraints:
 date.length == 10
 date[4] == date[7] == '-', and all other date[i]'s are digits.
 The input is generated such that date represents a valid Gregorian calendar date between Jan 1st, 1900 and Dec 31st, 2100 (both inclusive).
*/

class Solution {
public:
    string convertDateToBinary(string date) {
        // Split the date into year, month, and day
        string year = date.substr(0, 4);
        string month = date.substr(5, 2);
        string day = date.substr(8, 2);

        // Convert each part to an integer
        int y = stoi(year);
        int m = stoi(month);
        int d = stoi(day);

        // Convert each part to binary without leading zeros
        string binaryYear = bitset<12>(y).to_string();
        string binaryMonth = bitset<4>(m).to_string();
        string binaryDay = bitset<5>(d).to_string();

        // Remove leading zeros from the binary representations
        binaryYear.erase(0, binaryYear.find_first_not_of('0'));
        binaryMonth.erase(0, binaryMonth.find_first_not_of('0'));
        binaryDay.erase(0, binaryDay.find_first_not_of('0'));

        // Concatenate the results with hyphens
        return binaryYear + "-" + binaryMonth + "-" + binaryDay;
        
    }
};