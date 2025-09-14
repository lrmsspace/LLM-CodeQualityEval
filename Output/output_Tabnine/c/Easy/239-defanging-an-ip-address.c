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
    char *result = malloc(strlen(address) * 3 + 1);
    char *p = result;
    while (*address) {
        if (*address == '.') {
            *p++ = '[';
            *p++ = '.';
            *p++ = ']';
        } else {
            *p++ = *address;
        }
        address++;
    }
    *p = '\0';
    return result;
}