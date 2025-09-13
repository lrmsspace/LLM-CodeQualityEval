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
public:
    string reformatDate(string date) {
        stringstream ss(date);
        string day, month, year;
        ss >> day >> month >> year;
        stringstream ss2;
        ss2 << year << "-";
        if(month == "Jan") ss2 << "01";
        else if(month == "Feb") ss2 << "02";
        else if(month == "Mar") ss2 << "03";
        else if(month == "Apr") ss2 <<"04";
        else if(month == "May") ss2 << "05";
        else if(month == "Jun") ss2 << "06";
        else if(month == "Jul") ss2 << "07";
        else if(month == "Aug") ss2 << "08";
        else if(month == "Sep") ss2 << "09";
        else if(month == "Oct") ss2 << "10";
        elseif(month == "Nov") ss2 << "11";
        else ss2 << "12";
        ss2 << "-";
        if(day.size() == 3) ss2 << "0" << day[0];
        else ss2 << day[0] << day[1];
        return ss2.str();
    }
};