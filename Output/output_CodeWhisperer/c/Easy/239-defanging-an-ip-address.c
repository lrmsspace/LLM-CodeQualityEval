/**https://leetcode.com/problems/defanging-an-ip-address/ */
//Given a valid (IPv4) IP address, return a defanged version of that IP address.
//A defanged IP address replaces every period "." with "[.]".
// 
//Example 1:
//Input: address = "1.1.1.1"
//Output: "1[.]1[.]1[.]1"
//Example 2:
//Input: address = "255.100.50.0"
//Output: "255[.]100[.]50[.]0"
// 
//Constraints:
//	The given address is a valid IPv4 address.


char * defangIPaddr(char * address){
    int len = strlen(address);
    char *result = (char *)malloc(sizeof(char) * (len + 7));
    int i = 0, j = 0;
    while (i < len) {
        if (address[i] == '.') {
            result[j++] = '[';
            result[j++] = '.';
            result[j++] = ']';
        } else {
            result[j++] = address[i];
        }
        i++;
    }
    result[j] = '\0';
    return result;

}