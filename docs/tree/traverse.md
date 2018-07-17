# 二叉树遍历

- 前序遍历: 根节点 -> 左子树 -> 右子树
- 中序遍历: 左子树 -> 根节点 -> 右子树
- 后序遍历: 左子树 -> 右子树 -> 根节点
- 层次遍历

```python
class Node(object):

    def __init__(self, val=-1, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Tree(object):

    def __init__(self):
        self.root = Node()
        self.storage = []

    def add(self, val):
        node = Node(val)
        if self.root.val == -1:
            self.root = node
            self.storage.append(self.root)
        else:
            treeNode = self.storage[0]
            if not treeNode.left:
                treeNode.left = node
                self.storage.append(treeNode.left)
            else:
                treeNode.right = node
                self.storage.append(treeNode.right)
                self.storage.pop(0)

    def front_recursive(self, root):
        if not root:
            return
        print(root.val)
        self.front_recursive(root.left)
        self.front_recursive(root.right)

    def middle_recursive(self, root):
        if not root:
            return
        self.middle_recursive(root.left)
        print(root.val)
        self.middle_recursive(root.right)

    def later_recursive(self, root):
        if not root:
            return
        self.later_recursive(root.left)
        self.later_recursive(root.right)
        print(root.val)

    def front_stack(self, root):
        if not root:
            return
        stack = []
        node = root
        while node or stack:
            while node:
                print(node.val)
                stack.append(node)
                node = node.left
            node = stack.pop()
            node = node.right

    def middle_stack(self, root):
        if not root:
            return
        stack = []
        node = root
        while node or stack:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            print(node.val)
            node = node.right

    def later_stack(self, root):
        if not root:
            return
        stack1 = []
        stack2 = []
        node = root
        stack1.append(node)
        while stack1:
            node = stack1.pop()
            if node.left:
                stack1.append(node.left)
            if node.right:
                stack1.append(node.right)
            stack2.append(node)
        while stack2:
            print(stack2.pop().val)

    def level_queue(self, root):
        if not root:
            return
        storage = []
        node = root
        storage.append(node)
        while storage:
            node = storage.pop(0)
            print(node.val)
            if node.left:
                storage.append(node.left)
            if node.right:
                storage.append(node.right)

def main(data=10):
    vals = range(data)
    tree = Tree()
    for val in vals:
        tree.add(val)

    print('队列实现层次遍历:')
    tree.level_queue(tree.root)

    print('\n\n递归实现先序遍历:')
    tree.front_recursive(tree.root)
    print('\n递归实现中序遍历:' )
    tree.middle_recursive(tree.root)
    print('\n递归实现后序遍历:')
    tree.later_recursive(tree.root)

    print('\n\n堆栈实现先序遍历:')
    tree.front_stack(tree.root)
    print('\n堆栈实现中序遍历:')
    tree.middle_stack(tree.root)
    print('\n堆栈实现后序遍历:')
    tree.later_stack(tree.root)
```
