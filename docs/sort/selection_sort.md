# 选择排序

```python
def selection_sort(lst):

    arrlen = len(lst)

    for index in range(arrlen):
        minindex = index

        for j in range(index + 1, arrlen):
            if lst[minindex] > lst[j]:
                minindex = j

        if index != minindex:
            lst[index], lst[minindex] = lst[minindex], lst[index]

    return lst


datalist = [17, 23, 20, 14, 12, 25, 1, 20, 81, 14, 11, 12]

selection_sort(datalist)
```
