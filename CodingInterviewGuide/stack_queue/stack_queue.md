# 使用栈实现队列

https://leetcode-cn.com/problems/implement-queue-using-stacks/

使用栈实现队列的下列操作：

- push(x) -- 将一个元素放入队列的尾部。
- pop() -- 从队列首部移除元素。
- peek() -- 返回队列首部的元素。
- empty() -- 返回队列是否为空。

示例

```bash
MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false
```

说明


- 你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
- 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
- 假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。

## 解答

> 使用两个栈，一个栈作为`压入栈`，压入数据时只往`压入栈`push
> 另一个栈作为`弹出栈`，数据出栈时只从`弹出栈`pop


```python
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack_push = []
        self.stack_pop = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.stack_push.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if len(self.stack_pop) == len(self.stack_push) == 0:
            raise
        elif len(self.stack_pop) == 0:
            while len(self.stack_push) > 0:
                self.stack_pop.append(self.stack_push.pop())

        return self.stack_pop.pop()

    def peek(self) -> int:
        """
        Get the front element.
        """
        if len(self.stack_pop) == len(self.stack_push) == 0:
            raise
        elif len(self.stack_pop) == 0:
            while len(self.stack_push) > 0:
                self.stack_pop.append(self.stack_push.pop())

        return self.stack_pop[-1]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return len(self.stack_push) == len(self.stack_pop) == 0

# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
```

