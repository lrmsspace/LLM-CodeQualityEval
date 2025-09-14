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
    char* defanged = (char*)malloc(22 * sizeof(char));
    int i = 0, j = 0;
    while (address[i] != '\0') {
        if (address[i] == '.') {
            defanged[j] = '[';
            defanged[j + 1] = '.';
            defanged[j + 2] = ']';
            j += 3;
        } else {
            defanged[j] = address[i];
            j++;
        }
        i++;
    }
    defanged[j] = '\0';
    return defanged;
}