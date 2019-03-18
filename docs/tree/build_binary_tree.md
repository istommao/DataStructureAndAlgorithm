# 构造二叉树

## 先序构造

*@leetcode 1008* [先序遍历构造二叉树](https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal/)

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        root = TreeNode(preorder[0])

        def structure_tree(node, val):
            if not node:
                return

            if val < node.val:
                if node.left:
                    structure_tree(node.left, val)
                else:
                    node.left = TreeNode(val)
            if val > node.val:
                if node.right:
                    structure_tree(node.right, val)
                else:
                    node.right = TreeNode(val)

        for i in preorder[1:]:
            structure_tree(root, i)

        return root
```
