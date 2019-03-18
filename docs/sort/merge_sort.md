# 归并排序

- [归并排序 wiki](https://www.wikiwand.com/zh-hans/%E5%BD%92%E5%B9%B6%E6%8E%92%E5%BA%8F)


## 特点

- 时间复杂度：平均 $$ O(nlog_2{n}) $$ 最坏情况 O($$n^2$$)
- 稳定排序


```python
# Recursively implementation of Merge Sort
def merge(left, right):
    result = []
    while left and right:
        if left[0] <= right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))

    if left:
        result += left
    if right:
        result += right
    return result


def merge_sort(lst):
    if len(lst) <= 1:
        # When D&C to 1 element, just return it
        return lst

    mid = len(lst) // 2
    left = lst[:mid]
    right = lst[mid:]

    left = merge_sort(left)
    right = merge_sort(right)
    # conquer sub-problem recursively
    return merge(left, right)


dataset = [1, 4, 2, 3.6, -1, 0, 25, -34, 8, 9, 1, 0]
print("original:", dataset)
print("Sorted:", merge_sort(dataset))
```
