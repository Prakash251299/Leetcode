class Solution(object):
    def findDifference(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[List[int]]
        """
        a=[]
        b=[]
        res = []
        for i in nums1:
            if(i not in nums2):
                if(i not in a):
                    a.append(i)
        res.append(a)
        for i in nums2:
            if(i not in nums1):
                if(i not in b):
                    b.append(i)
        res.append(b)
        return res
        
