# 最小栈

> 设计一个有 getMin功能的栈

https://leetcode-cn.com/problems/min-stack/

```bash
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
```

示例

```bash
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
```

## 解答

> 使用两个栈，一个保存数据，一个保存每一步的最小值

```python
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self._lst = []
        self._minlst = []

    def push(self, x: int) -> None:
        self._lst.append(x)
        if len(self._minlst) == 0:
            self._minlst.append(x)
        elif x <= self._minlst[-1]:
            self._minlst.append(x)

    def pop(self) -> None:
        val = self._lst.pop()
        if val <= self._minlst[-1]:
            self._minlst.pop()

    def top(self) -> int:
        return self._lst[-1]

    def getMin(self) -> int:
        return self._minlst[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
```
