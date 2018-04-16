# 堆栈(Stack) Python实现

## 数组实现

```python
class Stack(object):

    def __init__(self):
        self._items = []

    def push(self, item):
        self._items.append(item)

    def pop(self):
        return self._items.pop()

    def is_empty(self):
        return len(self._items) == 0

    def top(self):
        return self._items[-1]
```

## 链表实现

```python
class Node(object):

    def __init__(self, val, next_node=None):
        self.val = val
        self.next = next_node

class Stack(object):

    def __init__(self):
        self._top = None

    def top(self):
        return self._top.val

    def push(self, val):
        self._top = Node(val, self._top)

    def pop(self):
        top = self._top
        self._top = top.next
        return top.val
```