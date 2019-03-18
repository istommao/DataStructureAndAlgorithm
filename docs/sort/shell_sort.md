# 希尔排序

- [希尔排序 wiki](https://www.wikiwand.com/zh-hans/%E5%B8%8C%E5%B0%94%E6%8E%92%E5%BA%8F)

```python
def shell_sort(list):
    arrlen = len(list)
    # 初始步长
    step = arrlen // 2

    while step > 0:
        for index in range(step, arrlen):
            # 每个步长进行插入排序
            temp = list[index]
            j = index
            # 插入排序
            while j >= step and list[j - step] > temp:
                list[j] = list[j - step]
                j -= step
            list[j] = temp

        # 得到新的步长
        step = step // 2
    return list
```
