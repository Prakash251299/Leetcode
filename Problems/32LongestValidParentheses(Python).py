class Solution(object):
    def check(self, s, i, j):
        if s[i] == '(' and s[j] == ')':
            return 1
        return 0

    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0 or len(s) == 1:
            return 0

        v = []  # Stack
        max_length = 0

        v.append(0)
        for i in range(1, len(s)):
            a = i
            if len(v) >= 1:
                b = v[-1]
                if self.check(s, b, a):
                    s = s[:a] + '1' + s[a+1:]
                    s = s[:b] + '1' + s[b+1:]
                    v.pop()
                else:
                    v.append(i)
            else:
                v.append(i)

        v = []  # Reset stack
        i = len(s) - 1

        while i >= 0:
            if s[i] == '1':
                v.append(1)
            else:
                v.append(0)
            i -= 1

        start = -1
        end = -1
        max_length = 0

        for i in range(len(s)):
            if v[-1] == 0:
                start = i
                end = i
            else:
                end = i
                max_length = max(max_length, end - start)
            v.pop()

        return max_length
