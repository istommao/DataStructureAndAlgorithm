# 删除链表的倒数第N个节点

https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

*示例：*

```bash
给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
```

*说明：*

给定的 n 保证是有效的。

*进阶：*

你能尝试使用一趟扫描实现吗？


## 解答

> 双指针法，第一个指针先走 N 步，然后两个指针再同时走
> 第一个指针到末尾时第二个指针所指即为倒数第N个节点

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        root = head
        first = second = head

        while n > 0:
            first = first.next
            n -= 1

        if not first:
            return root.next

        while first.next:
            first = first.next
            second = second.next

        second.next = second.next.next;
        return root
```
