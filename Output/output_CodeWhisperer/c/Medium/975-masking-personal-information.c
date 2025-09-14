/**https://leetcode.com/problems/masking-personal-information/ */
//You are given a personal information string s, representing either an email address or a phone number. Return the masked personal information using the below rules.
//Email address:
//An email address is:
//	A name consisting of uppercase and lowercase English letters, followed by
//	The '@' symbol, followed by
//	The domain consisting of uppercase and lowercase English letters with a dot '.' somewhere in the middle (not the first or last character).
//To mask an email:
//	The uppercase letters in the name and domain must be converted to lowercase letters.
//	The middle letters of the name (i.e., all but the first and last letters) must be replaced by 5 asterisks "*****".
//Phone number:
//A phone number is formatted as follows:
//	The phone number contains 10-13 digits.
//	The last 10 digits make up the local number.
//	The remaining 0-3 digits, in the beginning, make up the country code.
//	Separation characters from the set {'+', '-', '(', ')', ' '} separate the above digits in some way.
//To mask a phone number:
//	Remove all separation characters.
//	The masked phone number should have the form:
//	
//		"***-***-XXXX" if the country code has 0 digits.
//		"+*-***-***-XXXX" if the country code has 1 digit.
//		"+**-***-***-XXXX" if the country code has 2 digits.
//		"+***-***-***-XXXX" if the country code has 3 digits.
//	
//	
//	"XXXX" is the last 4 digits of the local number.
// 
//Example 1:
//Input: s = "LeetCode@LeetCode.com"
//Output: "l*****e@leetcode.com"
//Explanation: s is an email address.
//The name and domain are converted to lowercase, and the middle of the name is replaced by 5 asterisks.
//Example 2:
//Input: s = "AB@qq.com"
//Output: "a*****b@qq.com"
//Explanation: s is an email address.
//The name and domain are converted to lowercase, and the middle of the name is replaced by 5 asterisks.
//Note that even though "ab" is 2 characters, it still must have 5 asterisks in the middle.
//Example 3:
//Input: s = "1(234)567-890"
//Output: "***-***-7890"
//Explanation: s is a phone number.
//There are 10 digits, so the local number is 10 digits and the country code is 0 digits.
//Thus, the resulting masked number is "***-***-7890".
// 
//Constraints:
//	s is either a valid email or a phone number.
//	If s is an email:
//	
//		8 <= s.length <= 40
//		s consists of uppercase and lowercase English letters and exactly one '@' symbol and '.' symbol.
//	
//	
//	If s is a phone number:
//	
//		10 <= s.length <= 20
//		s consists of digits, spaces, and the symbols '(', ')', '-', and '+'.
//	    
bool isEmail(const char* s) {
    // Check if the string contains '@' symbol
    const char* at = strchr(s, '@');
    if (!at) return false;
    
    // Check if there's a '.' in the domain part
    const char* dot = strchr(at, '.');
    if (!dot) return false;
    
    // Check if the dot is not the first or last character of the domain
    if (dot == at + 1 || dot[1] == '\0') return false;
    
    return true;
}

char* maskEmail(const char* s) {
    // Find the '@' symbol
    const char* at = strchr(s, '@');
    
    // Get the name part (before '@')
    int nameLen = at - s;
    
    // Allocate memory for the result
    // Format: first + "*****" + last + "@" + domain
    char* result = (char*)malloc(nameLen + 6 + strlen(at) + 1);
    
    // Copy the first character of the name (converted to lowercase)
    result[0] = tolower(s[0]);
    
    // Add 5 asterisks
    strcpy(result + 1, "*****");
    
    // Add the last character of the name (converted to lowercase)
    result[6] = tolower(s[nameLen - 1]);
    
    // Add '@' symbol
    result[7] = '@';
    
    // Copy the domain part (converted to lowercase)
    int i = 8;
    for (const char* p = at + 1; *p; p++) {
        result[i++] = tolower(*p);
    }
    result[i] = '\0';
    
    return result;
}

char* maskPhoneNumber(const char* s) {
    // Count digits and extract them
    char digits[14] = {0}; // Max 13 digits + null terminator
    int digitCount = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            digits[digitCount++] = s[i];
        }
    }
    digits[digitCount] = '\0';
    
    // Determine country code length
    int countryCodeLen = digitCount - 10;
    
    // Allocate memory for the result
    // Format depends on country code length
    char* result;
    
    if (countryCodeLen == 0) {
        // "***-***-XXXX"
        result = (char*)malloc(13); // 12 chars + null terminator
        sprintf(result, "***-***-%.4s", digits + 6);
    } else if (countryCodeLen == 1) {
        // "+*-***-***-XXXX"
        result = (char*)malloc(17); // 16 chars + null terminator
        sprintf(result, "+*-***-***-%.4s", digits + 7);
    } else if (countryCodeLen == 2) {
        // "+**-***-***-XXXX"
        result = (char*)malloc(18); // 17 chars + null terminator
        sprintf(result, "+**-***-***-%.4s", digits + 8);
    } else { // countryCodeLen == 3
        // "+***-***-***-XXXX"
        result = (char*)malloc(19); // 18 chars + null terminator
        sprintf(result, "+***-***-***-%.4s", digits + 9);
    }
    
    return result;
}

char* maskPII(char* s) {
    if (isEmail(s)) {
        return maskEmail(s);
    } else {
        return maskPhoneNumber(s);
    }
}
