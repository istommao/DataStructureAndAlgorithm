# 堆排序

- [堆排序 wiki](https://www.wikiwand.com/zh-hans/%E5%A0%86%E6%8E%92%E5%BA%8F)

## 最小堆排序

```python
def heap_sort(lst):

    def sift_down(start, end):
        """最小堆调整"""
        root = start
        while True:
            child = 2 * root + 1
            if child > end:
                break

            if child + 1 <= end and lst[child] < lst[child + 1]:
                child += 1
            if lst[root] < lst[child]:
                lst[root], lst[child] = lst[child], lst[root]
                root = child
            else:
                break

    # 创建最小堆
    for start in range((len(lst) - 2) // 2, -1, -1):
        sift_down(start, len(lst) - 1)

    # 堆排序
    for end in range(len(lst) - 1, 0, -1):
        lst[0], lst[end] = lst[end], lst[0]
        sift_down(0, end - 1)
    return lst


dataset = [9, 2, 1, 7, 6, 8, 5, 3, 4]
heap_sort(dataset)
```
