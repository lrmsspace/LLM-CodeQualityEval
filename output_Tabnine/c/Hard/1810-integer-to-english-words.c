/**https://leetcode.com/problems/integer-to-english-words/ */
//Convert a non-negative integer num to its English words representation.
// 
//Example 1:
//Input: num = 123
//Output: "One Hundred Twenty Three"
//Example 2:
//Input: num = 12345
//Output: "Twelve Thousand Three Hundred Forty Five"
//Example 3:
//Input: num = 1234567
//Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// 
//Constraints:
//	0 <= num <= 231 - 1
char* numberToWords(int num) {
    // Define the units, tens, and hundreds of thousands
    char* units[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    char* teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char* tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char* thousands[] = {"", "Thousand", "Million", "Billion"};
    
    // Initialize the result string
    char* result = (char*)malloc(1000 * sizeof(char));
    result[0] = '\0';
    
    // Handle the thousands, hundreds, tens, and units
    int i = 0;
    while (num > 0) {
        int digit = num % 10;
        num /= 10;
        
        // Append the word for the current digit
        if (i == 3) {
            strcat(result, thousands[i]);
            i++;
        } else if (i == 2 && digit == 1) {
            strcat(result, teens[digit]);
            i++;
        } else if (i == 2 && digit > 1) {
            strcat(result, tens[digit]);
            i++;
        } else if (i == 1 && digit > 0) {
            strcat(result, " ");
            strcat(result, tens[digit]);
            i++;
        } else if (i == 0 && digit > 0) {
            strcat(result, " ");
            strcat(result, units[digit]);
            i++;
        }
    }
    
    // Reverse the result string
    char* start = result;
    char* end = result + strlen(result) - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    
    return result;
    
}