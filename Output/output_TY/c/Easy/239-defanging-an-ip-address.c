/**https://leetcode.com/problems/defanging-an-ip-address/ */
//Given a valid (IPv4) IP address, return a defanged version of that IP address._x000D_
//_x000D_
//A defanged IP address replaces every period "." with "[.]"._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//Input: address = "1.1.1.1"_x000D_
//Output: "1[.]1[.]1[.]1"_x000D_
//Example 2:_x000D_
//Input: address = "255.100.50.0"_x000D_
//Output: "255[.]100[.]50[.]0"_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	The given address is a valid IPv4 address._x000D_


char * defangIPaddr(char * address){
    char *res = (char *)malloc(sizeof(char) * (strlen(address) + 6));
    char *p = res;
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
    return res;
}