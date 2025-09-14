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
char * numberToWords(int num){
    char * result = malloc(sizeof(char) * 100);
    char * nums[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    char * tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char * units[] = {"", "Thousand", "Million", "Billion", "Trillion"};
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0;
    while(n > 0){
        int temp = n % 1000;
        if(temp != 0){
            if(temp < 20){
                if(temp == 0){
                    q += 1;
                }
                else{
                    q += sprintf(buf + q, "%s ", units[i]);
                    q += sprintf(buf + q, "%s", ones[temp]);
               }
            }
        }
    }
    return buf;
}