import queue

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def create_from_file(self, name):
        try:
            handle = open(name, 'r')
        except IOError:
            return None
        self.root = self._create_from_file(handle)
        handle.close()

        if self.root is None:
            return None

        return 1

    def _create_from_file(self, handle):
        c = handle.read(1)

        if c == '$':
            return None

        tmp = Node(c)
        tmp.left = self._create_from_file(handle)
        tmp.right = self._create_from_file(handle)

        return tmp

    def is_bst(self):
        if self.root is None:
            return False
        return self._is_bst(self.root)

    def _is_bst(self, current:Node):
        if current is None:
            return True

        tmp_left = self._is_bst(current.left)
        tmp_right = self._is_bst(current.right)

        if current.left is not None and tmp_left is True:
            tmp_left = current.left.value < current.value
        if current.right is not None and tmp_right is True:
            tmp_right = current.right.value > current.value

        return tmp_left and tmp_right

    def insertar(self, val):
        if self.root == None:
            self.root = Node(val)
        else:
            self._insertar(val, self.root)

    def _insertar(self, val, nodo):
        if val < nodo.value:
            if nodo.left == None:
                nodo.left = Node(val)
            else:
                self._insertar(val, nodo.left)
        elif val > nodo.value:
            if nodo.right == None:
                nodo.right = Node(val)
            else:
                self._insertar(val, nodo.right)
        else:
            print("El valor ya existe en el árbol")

    def borrar_nodo(self, key):
        temp = self._busqueda_binaria_nodo(key, self.root)

        while temp.left is not None:
            temp.value = temp.left.value
        temp = temp.left
        temp = None

    def busqueda_binaria_nodo(self, v):
        tmp = self._busqueda_binaria_nodo(v, self.root)
        if tmp is not None:
            return True
        return False

    def _busqueda_binaria_nodo(self, v, node):
        if node is None:
            return

        if node.value is v:
            return node

        tmp = None
        if v < node.value:
            if node.left is not None:
                tmp = self._busqueda_binaria_nodo(v, node.left)

        if v > node.value:
            if node.right is not None:
                tmp = self._busqueda_binaria_nodo(v, node.right)

        return tmp

    def imprimir(self):
        self._imprimir(" ", self.root, False)

    def _imprimir(self, p, actual, es_izq):
        if actual:
            print(p, end='')

            if es_izq:
                print("|--", end='')
                cad = "|    "
            else:
                print("'--", end='')
                cad = "    "

            print(actual.value)
            self._imprimir(p + cad, actual.right, False)
            self._imprimir(p + cad, actual.left, True)

    def in_orden(self):
        self._in_orden(self.root)

    def _in_orden(self, current:Node):
        if current is None:
            return None
        self._in_orden(current.left)
        print(current.value,',', end='')
        self._in_orden(current.right)

    def _buscarMin(self, nodo):
        if nodo.left != None:
            return self._buscarMin(nodo.left)
        else:
            return nodo.value

    def borrarNodo(self, val):
        if self.root is not None:
            self._borrarNodo(val, self.root)

    def _borrarNodo(self, val, nodo):
        if nodo is not None:
            if val < nodo.value:
                self._borrarNodo(val, nodo.left)
            elif val > nodo.value:
                self._borrarNodo(val, nodo.right)
            else:
                if nodo.left is not None and nodo.right is not None:
                    nodo.value = self._buscarMin(nodo.right)
                    self._borrarNodo(nodo.value, nodo.right)
                elif nodo.left is None and nodo.right is None:
                    nodo = None
                elif nodo.left is not None:
                    nodo = nodo.left
                else:
                    nodo = nodo.right