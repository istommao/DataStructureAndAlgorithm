# 队列 (Queue)

> 队列 是 先进先出的线性表, 在具体实现中，通常用链表或数组来实现

`特点`
- 队列只允许在后端(rear)进行插入，在前端(front) 进行删除


## Python实现 循环队列

```python

class Queue(object):

    def __init__(self, size):
        self.head = -1
        self.tail = -1
        self.size = size
        self._lst = []

    def enQueue(self, val):
        if self.isFull():
            return False

        if self.isEmpty():
            head = 0

        self.tail = (self.tail + 1) % self.size
        self._lst[self.tail] = val
        return True

    def deQueue(self):
        if self.isEmpty():
            return False

        if (self.head == self.tail):
            self.head = -1
            self.tail = -1
            return True

        self.head = (self.head + 1) % self.size
        return True

    def front(self):
        if self.isEmpty():
            return -1

        return self._lst[self.head]

    def rear(self):
        if self.isEmpty():
            return -1

        return self._lst[self.tail]

    def isEmpty(self):
        return self.head == -1

    def isFull(self):
        return ((self.tail + 1) % self.size) == self.head
```

## C语言实现 循环队列

```c
typedef struct Queue {
    int head;
    int tail;
    int size;

    int enQueue(int value);
    int deQueue(void);
    int front(void);
    int rear(void);
    int isEmpty(void);
    int isFull(void);
} Queue;

int main() {

    return 0;
}
```
