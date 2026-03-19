class Solution:
    def isPalindrome(self, s: str) -> bool:
        i, j = 0, len(s) - 1
        while i < j:
            a, b = s[i], s[j]

            # skip non-alphanumeric left
            if not (('a' <= a <= 'z') or ('A' <= a <= 'Z') or ('0' <= a <= '9')):
                i += 1
                continue
            # skip non-alphanumeric right
            if not (('a' <= b <= 'z') or ('A' <= b <= 'Z') or ('0' <= b <= '9')):
                j -= 1
                continue

            # normalize uppercase to lowercase with bit trick
            if 'A' <= a <= 'Z':
                a = chr(ord(a) | 32)
            if 'A' <= b <= 'Z':
                b = chr(ord(b) | 32)

            if a != b:
                return False

            i += 1
            j -= 1
        return True
