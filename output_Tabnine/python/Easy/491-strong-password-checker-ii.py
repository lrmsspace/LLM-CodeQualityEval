#https://leetcode.com/problems/strong-password-checker-ii/
#A password is said to be strong if it satisfies all the following criteria:
#	It has at least 8 characters.
#	It contains at least one lowercase letter.
#	It contains at least one uppercase letter.
#	It contains at least one digit.
#	It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
#	It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).
#Given a string password, return true if it is a strong password. Otherwise, return false.
# 
#Example 1:
#Input: password = "IloveLe3tcode!"
#Output: true
#Explanation: The password meets all the requirements. Therefore, we return true.
#Example 2:
#Input: password = "Me+You--IsMyDream"
#Output: false
#Explanation: The password does not contain a digit and also contains 2 of the same character in adjacent positions. Therefore, we return false.
#Example 3:
#Input: password = "1aB!"
#Output: false
#Explanation: The password does not meet the length requirement. Therefore, we return false.
# 
#Constraints:
#	1 <= password.length <= 100
#	password consists of letters, digits, and special characters: "!@#$%^&*()-+".
class Solution(object):
    def strongPasswordCheckerII(self, password):
        """
        :type password: str
        :rtype: bool
        """
        # Check length requirement
        if len(password) < 8:
            return False
        
        # Check for lowercase, uppercase, digit, and special character
        has_lower, has_upper, has_digit, has_special = False, False, False, False
        for i in range(len(password) - 1):
            if password[i].islower():
                has_lower = True
            elif password[i].isupper():
                has_upper = True
            elif password[i].isdigit():
                has_digit = True
            elif password[i] in "!@#$%^&*()-+":
                has_special = True
                
            if password[i] == password[i+1]:
                return False
        
        # Check for consecutive special characters
        for i in range(len(password) - 2):
            if password[i] in "!@#$%^&*()-+" and password[i+1] in "!@#$%^&*()-+" and password[i+2] in "!@#$%^&*()-+":
                return False
        
        return has_lower and has_upper and has_digit and has_special
        