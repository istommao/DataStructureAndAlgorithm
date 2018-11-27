# 二叉树遍历

- 前序遍历: 根节点 -> 左子树 -> 右子树
- 中序遍历: 左子树 -> 根节点 -> 右子树
- 后序遍历: 左子树 -> 右子树 -> 根节点
- 层次遍历

## 前序遍历

```python
class TreeNode(object):

    def __init__(self, val=None, left=None, right=None):
        self.left = left
        self.right = right
        self.val = val

class BinTree(object):

    def __init__(self, root):
        self.root = root

    def stack_print(self, root):
        """堆栈实现"""
        stack = []

        while root or stack:
            while root:
                stack.append(root)
                print(root.val)
                root = root.left

            if stack:
                root = stack.pop()
                root = root.right

    def recursive_print(self, root):
        """递归实现"""
        if not root:
            return

        print(root.val)
        self.recursive_print(root.left)
        self.recursive_print(root.right)

def main():
    left = TreeNode(2, left=TreeNode(4), right=TreeNode(5))

    right = TreeNode(3, left=TreeNode(6), right=TreeNode(7))

    root = TreeNode(1, left=left, right=right)

    tree = BinTree(root)

    print('递归 先序遍历:')
    tree.recursive_print(tree.root)
    print('堆栈 先序遍历:')
    tree.stack_print(tree.root)
```

## 中序遍历


```python
class TreeNode(object):

    def __init__(self, val=None, left=None, right=None):
        self.left = left
        self.right = right
        self.val = val

class BinTree(object):

    def __init__(self, root):
        self.root = root

    def stack_print(self, root):
        """堆栈实现"""
        stack = []

        while root or stack:
            while root:
                stack.append(root)
                root = root.left

            if stack:
                root = stack.pop()
                print(root.val)
                root = root.right

    def recursive_print(self, root):
        """递归实现"""
        if not root:
            return

        self.recursive_print(root.left)
        print(root.val)
        self.recursive_print(root.right)

def main():
    left = TreeNode(2, left=TreeNode(4), right=TreeNode(5))

    right = TreeNode(3, left=TreeNode(6), right=TreeNode(7))

    root = TreeNode(1, left=left, right=right)

    tree = BinTree(root)

    print('递归 中序遍历:')
    tree.recursive_print(tree.root)
    print('堆栈 中序遍历:')
    tree.stack_print(tree.root)
```

## 后序遍历

```python
class TreeNode(object):

    def __init__(self, val=None, left=None, right=None):
        self.left = left
        self.right = right
        self.val = val

class BinTree(object):

    def __init__(self, root):
        self.root = root

    def stack_print(self, root):
        """堆栈实现"""
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

    def recursive_print(self, root):
        """递归实现"""
        if not root:
            return

        self.recursive_print(root.left)
        self.recursive_print(root.right)
        print(root.val)

def main():
    left = TreeNode(2, left=TreeNode(4), right=TreeNode(5))

    right = TreeNode(3, left=TreeNode(6), right=TreeNode(7))

    root = TreeNode(1, left=left, right=right)

    tree = BinTree(root)

    print('递归 后序遍历:')
    tree.recursive_print(tree.root)
    print('堆栈 后序遍历:')
    tree.stack_print(tree.root)
```

## 层次遍历

```python
class TreeNode(object):

    def __init__(self, val=None, left=None, right=None):
        self.left = left
        self.right = right
        self.val = val

class BinTree(object):

    def __init__(self, root):
        self.root = root

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

def main():
    left = TreeNode(2, left=TreeNode(4), right=TreeNode(5))

    right = TreeNode(3, left=TreeNode(6), right=TreeNode(7))

    root = TreeNode(1, left=left, right=right)

    tree = BinTree(root)

    print('队列 层次遍历:')
    tree.level_queue(tree.root)
```
