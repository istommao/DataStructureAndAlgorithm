# 快速排序

> 1960年左右由英国金数据科学家(C.A.R.Hoare)提出
> 本质采用了分治的思想

## 特点

- 时间复杂度：平均 $$ O(nlog_2{n}) $$ 最坏情况 O($$n^2$$)
- 不稳定排序

## 思路

- 从数列中挑出一个元素，称为"基准" (pivot)
- 重新排序数列，所有比基准值小的元素摆放在基准前面，所有比基准值大的元素摆在基准后面（相同的数可以到任一边）。在这个分区结束之后，该基准就处于数列的中间位置。这个称为分区（partition）操作。
- 递归地（recursively）把小于基准值元素的子数列和大于基准值元素的子数列排序。


![](./_image/Sorting_quicksort_anim.gif)


## 实现

### 递归实现

```python
def qsort(lst):
    if not lst:
        return lst

    pivot = lst[0]
    less = [x for x in lst if x < pivot]
    more = [x for x in lst[1:] if x >= pivot]
    return qsort(less) + [pivot] + qsort(more)
```

```python
def qsort(a, start, end):

    def partition(lst, start, end):
        x = lst[end]
        i = start - 1
        for j in range(start, end):
            if lst[j] <= x:
                i += 1
                lst[i], lst[j] = lst[j], lst[i]
        lst[i + 1], lst[end] = lst[end], lst[i + 1]
        return i + 1

    if start < end:
        middle = partition(a, start, end)
        qsort(a, start, middle - 1)
        qsort(a, middle + 1, end)
    return a

data = [234, 21, 56, 45, 79, 3]
lst = qsort(data, 0, len(data) - 1)
```
