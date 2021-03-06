# 链表（Linked list）
> 是一种线性表，但不按线性顺序存储数据，而是在每个节点里存放到下一节点的指针

`时间复杂度`
- 插入: O(1)
- 查找节点: O(n)

## 历史

> 链表开发于1955-56，由当时所属于兰德公司（英语：RAND Corporation）的艾伦纽维尔（Allen Newell），
> 克里夫肖（Cliff Shaw）和赫伯特西蒙（Herbert Simon）在他们编写的信息处理语言（IPL）
> 中做为原始数据类型所编写。IPL被作者们用来开发几种早期的人工智能程序，包括逻辑推理机，
> 通用问题解算器和一个计算机象棋程序。

## 单向链表

### C语言实现

```c

```

### Python实现

```python
class LinkedList(object):

    def __init__(self, val):
        self._next = None
        self.val = val

    def reverse(self, head):
        pre = None
        while head:
            temp = head._next
            head._next = prev
            prev = head
            head = temp
        return prev

    def print(self):
        while self._next:
            print(self._next.val)
```


## 双向链表

```python
class LinkedList(object):

    def __init__(self, val):
        self.val = val
        self._prev = self._next = None

    def reverse(self, head):
        curt = None
        while head:
            curt = head
            head = curt._next
            curt._next = curt._prev
            curt._prev = head
        return curt
```


## 循环链表


## 链表的作用

> 链表用来构建许多其它数据结构，如堆栈，队列和他们的派生。


## 常见用途

> 常用于组织删除、检索较少，而添加、遍历较多的数据

