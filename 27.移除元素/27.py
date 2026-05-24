class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        left=0
        right=len(nums)
        while left<right:
            if nums[left]==val:
                nums[left]=nums[right-1]
                right-=1
            else :left+=1 #不能无条件加，因为复制过来的尾部元素也有可能是和val相等的元素
        return left
        
                
            