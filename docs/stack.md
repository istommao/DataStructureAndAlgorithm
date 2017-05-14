# 堆栈 (Stack)

## 概念

> 栈是一种后进先出的数据结构

`栈的特点`

- 先入后出，后入先出
- 除了尾节点之外，每个元素都有一个前驱，一个后继

## 应用场景

> 栈是一种非常重要的数据结构

- 函数调用


## 实现

栈可用使用 `链表`和`数组` 来实现

### Python实现

```python
class Stack(object):

    def __init__(self):
        self._items = []

    def push(self, item):
        self._items.append(item)

    def pop(self):
        return self.items.pop()

    def is_empty(self):
        return len(self._items) == 0

    def top(self):
        return self._items[-1]
```
