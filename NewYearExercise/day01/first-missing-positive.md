# 寻找缺失的最小正数

> https://leetcode-cn.com/problems/first-missing-positive/submissions/

给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:

```
输入: [1,2,0]
输出: 3
示例 2:
```

```
输入: [3,4,-1,1]
输出: 2
示例 3:
```

```
输入: [7,8,9,11,12]
输出: 1
说明:
```

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。

## 解答

```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        count = len(nums)
        for index in range(count):
            while nums[index] != index + 1:
                if 0 < nums[index] < count and nums[nums[index] - 1] != nums[index]:
                    temp = nums[nums[index] - 1]
                    nums[nums[index] - 1] = nums[index]
                    nums[index] = temp
                else:
                    break

        for index in range(count):
            if nums[index] != index + 1:
                return index + 1
        return count + 1
```
