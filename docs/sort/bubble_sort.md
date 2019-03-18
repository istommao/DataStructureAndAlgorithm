# 冒泡排序

```python
def bubble_sort(data):
    for i, _ in enumerate(data):
        for j, _ in enumerate(data):
            if data[i] > data[j]:
                data[i], data[j] = data[j], data[i]

    print(data)


datalst = [9, 43, 56, 123, 3, 92]
bubble_sort(datalst)
```
