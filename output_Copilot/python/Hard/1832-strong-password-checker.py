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
        n = len(password)
        has_lower = any(c.islower() for c in password)
        has_upper = any(c.isupper() for c in password)
        has_digit = any(c.isdigit() for c in password)
        missing_types = 3 - (has_lower + has_upper + has_digit)

        replace_count = 0
        one_repeat = two_repeat = 0
        i = 2

        while i < n:
            if password[i] == password[i - 1] == password[i - 2]:
                length = 2
                while i < n and password[i] == password[i - 1]:
                    length += 1
                    i += 1
                replace_count += length // 3
                if length % 3 == 0:
                    one_repeat += 1
                elif length % 3 == 1:
                    two_repeat += 1
            else:
                i += 1

        if n < 6:
            return max(6 - n, missing_types)
        elif n <= 20:
            return max(replace_count, missing_types)
        else:
            delete_count = n - 20
            replace_count -= min(delete_count, one_repeat * 1) // 1
            delete_count -= max(0, delete_count - one_repeat * 1) // 2 * 2
            replace_count -= min(delete_count, two_repeat * 2) // 2
            delete_count -= max(0, delete_count - two_repeat * 2) // 3 * 3

            return n - 20 + max(replace_count, missing_types) + delete_count        
        
# Test cases