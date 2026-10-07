class Solution:
    def removeInvalidParentheses(self, s: str):
        ans = set()

        def is_valid(string):
            balance = 0

            for ch in string:
                if ch == '(':
                    balance += 1
                elif ch == ')':
                    balance -= 1

                if balance < 0:
                    return False

            return balance == 0

        def backtrack(index, path, removals):
            # We only remove the minimum number of characters
            if removals > min_removals:
                return

            if index == len(s):
                current = ''.join(path)

                if is_valid(current):
                    if removals < min_removals:
                        ans.clear()
                        ans.add(current)
                    elif removals == min_removals:
                        ans.add(current)

                return

            # Keep current character
            path.append(s[index])
            backtrack(index + 1, path, removals)
            path.pop()

            # Remove current character only if it is a parenthesis
            if s[index] in '()':
                backtrack(index + 1, path, removals + 1)

        # Find minimum number of removals required
        left = right = 0

        for ch in s:
            if ch == '(':
                left += 1
            elif ch == ')':
                if left > 0:
                    left -= 1
                else:
                    right += 1

        min_removals = left + right

        backtrack(0, [], 0)

        return list(ans)