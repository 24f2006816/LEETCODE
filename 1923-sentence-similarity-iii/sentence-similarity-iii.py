class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        a = sentence1.split()
        b = sentence2.split()

        if len(a) > len(b):
            a,b = b,a

        n = len(a)
        m = len(b)

        left = 0
        while left < n and a[left] == b[left]:
            left += 1

        right = 0
        while right < n-left and a[n-1-right] == b[m-1-right]:
            right += 1
        
        return left+right >=n