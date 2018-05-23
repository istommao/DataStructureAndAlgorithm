"""stack."""


class Stack(object):

    def __init__(self, item):
        self._data = [item]

    def push(self, item):
        self._data.append(item)

    def pop(self):
        if len(self._data) == 0:
            raise ValueError('Your stack is empty')

        return self._data.pop()

    def getMin(self):
        if len(self._data) == 0:
            raise ValueError('Your stack is empty')

        return min(self._data)
