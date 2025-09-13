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
    public String convertDateToBinary(String date) {
        // Split the date into year, month, and day
        String[] parts = date.split("-");
        int year = Integer.parseInt(parts[0]);
        int month = Integer.parseInt(parts[1]);
        int day = Integer.parseInt(parts[2]);
        
        // Convert year, month, and day to binary
        String binaryYear = Integer.toBinaryString(year);
        String binaryMonth = Integer.toBinaryString(month);
        String binaryDay = Integer.toBinaryString(day);
        
        // Pad binary representations with leading zeroes if necessary
        binaryYear = String.format("%012s", binaryYear).replace(' ', '0');
        binaryMonth = String.format("%03s", binaryMonth).replace(' ', '0');
        binaryDay = String.format("%05s", binaryDay).replace(' ', '0');
        
        // Combine binary representations into a single string
        return binaryYear + "-" + binaryMonth + "-" + binaryDay;
        
    }
}