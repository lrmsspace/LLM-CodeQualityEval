#https://leetcode.com/problems/strong-password-checker/
#A password is considered strong if the below conditions are all met:
#	It has at least 6 characters and at most 20 characters.
#	It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
#	It does not contain three repeating characters in a row (i.e., "Baaabb0" is weak, but "Baaba0" is strong).
#Given a string password, return the minimum number of steps required to make password strong. if password is already strong, return 0.
#In one step, you can:
#	Insert one character to password,
#	Delete one character from password, or
#	Replace one character of password with another character.
# 
#Example 1:
#Input: password = "a"
#Output: 5
#Example 2:
#Input: password = "aA1"
#Output: 3
#Example 3:
#Input: password = "1337C0d3"
#Output: 0
# 
#Constraints:
#	1 <= password.length <= 50
#	password consists of letters, digits, dot '.' or exclamation mark '!'.
class Solution(object):
    def strongPasswordChecker(self, password):
        """
        :type password: str
        :rtype: int
        """
        # Step 1: Count the number of each character type
        lower, upper, digit, special = 0, 0, 0, 0
        for c in password:
            if c.islower():
                lower += 1
            elif c.isupper():
                upper += 1
            elif c.isdigit():
                digit += 1
            elif c in ['!', '.', '?']:
                special += 1
        
        # Step 2: Check if password has at least 6 and at most 20 characters
        if len(password) < 6 or len(password) > 20:
            return max(6 - len(password), 0)
        
        # Step 3: Check if password contains at least one lowercase letter, one uppercase letter, and one digit
        if lower == 0 or upper == 0 or digit == 0:
            return 3
        
        # Step 4: Check if password contains three repeating characters in a row
        for i in range(len(password) - 2):
            if password[i] == password[i+1] == password[i+2]:
                return 1
        
        # Step 5: Check if password contains at least one special character
        if special == 0:
            return 1
        
        # Step 6: Calculate the minimum number of steps required to make password strong
        steps = 0
        steps += max(0, 6 - len(password))  # Add required characters
        steps += max(0, 3 - lower)  # Add missing lowercase letters
        steps += max(0, 3 - upper)  # Add missing uppercase letters
        steps += max(0, 3 - digit)  # Add missing digits
        steps += special  # Add missing special characters
        
        return steps
        