# 其他

```python
# 第二小的元素
def func(lst):
    l1 = lst[0]
    l2 = None
    for i in lst[1:]:
        if not l2:
            l2 = max(l1, i)
        else:
            if (i <= l1 <= l2) or (l2 <= l1 <= i):
                l2 = l1
            if (l1 <= i <= l2) or (l2 <= i <= l1):
                l2 = i
        if i < l1:
            l1 = i

    return l2
```
