# 插入排序

```python
def insert_sort(lst):

    arrlen = len(lst)
    if arrlen == 1:
        return lst

    for index in range(1, arrlen):
        for j in range(index, 0, -1):
            if lst[j] < lst[j - 1]:
                lst[j], lst[j - 1] = lst[j - 1], lst[j]
            else:
                break

    return lst

datalst = [9, 43, 56, 123, 3, 92]
insert_sort(datalst)
```
