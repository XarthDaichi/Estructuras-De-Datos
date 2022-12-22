import queue
class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
class Binary_Tree_EX2:
    def __init__(self):
        self.root = None

    def create_from_file(self, name):
        try:
            handle = open(name, 'r')
        except IOError:
            return None
        # this is a wrapper, wrappers are used a lot in trees
        self.root = self._create_from_file(handle)
        handle.close()

        if self.root is None:
            return None

        return 1

    # the underscore before the function is to make it private
    def _create_from_file(self, handle):
        c = handle.read(1)

        if c == '$':
            return None

        tmp = Node(int(c))
        tmp.left = self._create_from_file(handle)
        tmp.right = self._create_from_file(handle)

        return tmp

    def pre_orden(self):
        self._pre_orden(self.root)

    def _pre_orden(self, current:Node):
        if current is None:
            return None
        print(current.value, end='')
        self._pre_orden(current.left)
        self._pre_orden(current.right)

    def in_orden(self):
        self._in_orden(self.root)

    def _in_orden(self, current:Node):
        if current is None:
            return None
        self._in_orden(current.left)
        print(current.value, end='')
        self._in_orden(current.right)

    def pos_orden(self):
        self._pos_orden(self.root)

    def _pos_orden(self, current:Node):
        if current is None:
            return None
        self._pos_orden(current.left)
        self._pos_orden(current.right)
        print(current.value, end='')

    def by_level_travel(self):
        if self.root is None:
            return

        que = queue.Queue()

        que.put(self.root)

        while not que.empty():
            tmp = que.get()
            print(tmp.value, end=' ')
            if tmp.left is not None:
                que.put(tmp.left)
            if tmp.right is not None:
                que.put(tmp.right)

    def insert(self, value):
        if self.root is None:
            self.root = Node(value)
            return
        que = queue.Queue()
        que.put(self.root)
        while True:
            tmp = que.get()
            if tmp.left is None:
                tmp.left = Node(value)
                break
            elif tmp.right is None:
                tmp.right = Node(value)
                break
            que.put(tmp.left)
            que.put(tmp.right)

    def deepest_node(self):
        if self.root is None:
            return
        tmp = self.root
        que= queue.Queue()
        que.put(self.root)
        while not que.empty():
            tmp = que.get()
            if tmp.left is not None:
                que.put(tmp.left)
            if tmp.right is not None:
                que.put(tmp.right)
        return tmp

    def search_recursive(self, val):
        tmp = self._search_recursive(val, self.root)
        if tmp is not None:
            return True
        return False

    def _search_recursive(self, val, current):
        if current is None:
            return
        if val is current.value:
            return current
        tmp = self._search_recursive(val, current.left)
        if tmp is None:
            tmp = self._search_recursive(val, current.right)
        return tmp

    def search_iterative(self, val):
        tmp = self._search_iterative(val)
        if tmp is not None:
            return True
        return False

    def _search_iterative(self, val):
        if self.root is None:
            return

        que = queue.Queue()
        que.put(self.root)
        while not que.empty():
            tmp = que.get()
            if tmp.value is val:
                return tmp

            if tmp.left is not None:
                que.put(tmp.left)
            if tmp.right is not None:
                que.put(tmp.right)

    # Escriba un metodo recursivo que retorne el elemento mayor de un arbol binario cuyos elementos son numeros enteros

    def max(self):
        return self._max(self.root)

    def _max(self, current:Node):
        if current is None:
            return 0

        left = self._max(current.left)
        right = self._max(current.right)
        return max(left, right, current.value)