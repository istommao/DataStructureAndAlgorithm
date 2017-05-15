# 队列 (Queue)

> 队列 是 先进先出的线性表, 在具体实现中，通常用链表或数组来实现

`特点`
- 队列只允许在后端(rear)进行插入，在前端(front) 进行删除


## Python实现

```python
class Queue(object):

    def __init__(self, size=8):
        self._size = size
        self._vals = [0] * size
        self._head = 0
        self._num = 0

    def is_empty(self):
        returnm self._num == 0

    def peek(self):
        return self._vals[self._head]

    def dequeue(self):
        val = self._vals[self._head]
        self._head = (self._head + 1) % self._size
        self._num -= 1
        return val

    def enqueue(self, val):
        self._vals.append(val)

        self._num += 1
```
