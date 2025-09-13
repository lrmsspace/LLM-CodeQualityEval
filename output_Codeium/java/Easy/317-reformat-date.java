/**https://leetcode.com/problems/reformat-date/ */
//Given a date string in the form Day Month Year, where:
//	Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
//	Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
//	Year is in the range [1900, 2100].
//Convert the date string to the format YYYY-MM-DD, where:
//	YYYY denotes the 4 digit year.
//	MM denotes the 2 digit month.
//	DD denotes the 2 digit day.
// 
//Example 1:
//Input: date = "20th Oct 2052"
//Output: "2052-10-20"
//Example 2:
//Input: date = "6th Jun 1933"
//Output: "1933-06-06"
//Example 3:
//Input: date = "26th May 1960"
//Output: "1960-05-26"
// 
//Constraints:
//	The given dates are guaranteed to be valid, so no error handling is necessary.
class Solution {
    public String reformatDate(String date) {
        String[] parts = date.split(" ");
        String day = parts[0];
        String month = parts[1];
        String year = parts[2];
        String newDay = day.substring(0, day.length()-2);
        String newMonth = "";
        switch (month) {
            case "Jan":
                newMonth = "01";
                break;
            case "Feb":
                newMonth = "02";
                break;
            case "Mar":
                newMonth = "03";
                break;
            case "Apr":
                newMonth = "04";
                break;
            case "May":
                newMonth = "05";
                break;
            case "Jun":
                newMonth = "06";
                break;
            case "Jul":
                newMonth = "07";
                break;
            case "Aug":
                newMonth = "08";
                break;
            case "Sep":
                newMonth = "09";
                break;
            case "Oct":
                newMonth = "10";
                break;
            case "Nov":
                newMonth = "11";
                break;
            case "Dec":
                newMonth = "12";
                break;
        }
        return String.format("%s-%s-%s", year, newMonth, newDay);
    }
}