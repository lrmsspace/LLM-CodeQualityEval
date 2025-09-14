#https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/
#You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. Ingredients to a recipe may need to be created from other recipes, i.e., ingredients[i] may contain a string that is in recipes.
#You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
#Return a list of all the recipes that you can create. You may return the answer in any order.
#Note that two recipes may contain each other in their ingredients.
# 
#Example 1:
#Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
#Output: ["bread"]
#Explanation:
#We can create "bread" since we have the ingredients "yeast" and "flour".
#Example 2:
#Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
#Output: ["bread","sandwich"]
#Explanation:
#We can create "bread" since we have the ingredients "yeast" and "flour".
#We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
#Example 3:
#Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
#Output: ["bread","sandwich","burger"]
#Explanation:
#We can create "bread" since we have the ingredients "yeast" and "flour".
#We can create "sandwich" since we have the ingredient "meat" and can create the ingredient "bread".
#We can create "burger" since we have the ingredient "meat" and can create the ingredients "bread" and "sandwich".
# 
#Constraints:
#	n == recipes.length == ingredients.length
#	1 <= n <= 100
#	1 <= ingredients[i].length, supplies.length <= 100
#	1 <= recipes[i].length, ingredients[i][j].length, supplies[k].length <= 10
#	recipes[i], ingredients[i][j], and supplies[k] consist only of lowercase English letters.
#	All the values of recipes and supplies combined are unique.
#	Each ingredients[i] does not contain any duplicate values.
class Solution(object):
    def findAllRecipes(self, recipes, ingredients, supplies):
        """
        :type recipes: List[str]
        :type ingredients: List[List[str]]
        :type supplies: List[str]
        :rtype: List[str]
        """
        # Initialize a graph representing the relationships between recipes and ingredients
        graph = collections.defaultdict(list)
        for i, recipe in enumerate(ingredients):
            for ingredient in recipe:
                graph[ingredient].append(recipes[i])
        
        # Initialize a dictionary to keep track of the remaining supplies for each recipe
        remaining_supplies = {recipe: supplies.count(recipe) for recipe in recipes}
        
        # Initialize an empty list to store the final result
        result = []
        
        # Initialize a queue to store the recipes that have all their ingredients
        queue = collections.deque(recipe for recipe in recipes if supplies.count(recipe) == len(recipe))
        
        while queue:
            recipe = queue.popleft()
            result.append(recipe)
            
            # Decrement the remaining supplies for the current recipe
            for ingredient in graph[recipe]:
                remaining_supplies[ingredient] -= 1
            # If all the ingredients for the current recipe are satisfied, add it to the queue
            if all(remaining_supplies[ingredient] >= 0 for ingredient in graph[recipe]):
                for ingredient in graph[recipe]:
                    queue.append(ingredient)
        
        # Return the result
        return result
        