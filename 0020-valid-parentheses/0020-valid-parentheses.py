class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {')': '(', '}': '{', ']': '['}
        
        for char in s:
            if char in mapping.values():  # If it's an opening bracket
                stack.append(char)
            else:  # It's a closing bracket
                if not stack or stack[-1] != mapping[char]:
                    return False
                stack.pop()
        
        return not stack
