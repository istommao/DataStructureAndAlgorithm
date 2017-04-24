# 快速排序

> 1960年左右由英国金数据科学家(C.A.R.Hoare)提出
> 本质采用了分治的思想

## 特点

- 时间复杂度：平均 O(nlogn) 最坏情况 O(n^2)
- 不稳定排序

## 思路

- 从数列中挑出一个元素，称为"基准" (pivot)
- 重新排序数列，所有比基准值小的元素摆放在基准前面，所有比基准值大的元素摆在基准后面（相同的数可以到任一边）。在这个分区结束之后，该基准就处于数列的中间位置。这个称为分区（partition）操作。
- 递归地（recursively）把小于基准值元素的子数列和大于基准值元素的子数列排序。

## 实现

### 递归实现

```python
def qsort(lst):
    if len(lst) <= 1:
        return lst

    return qsort([x for x in lst[1:] if x < lst[0]]) + [lst[0]] + qsort([x for x in lst[1:] if x >= lst[0]])
```
