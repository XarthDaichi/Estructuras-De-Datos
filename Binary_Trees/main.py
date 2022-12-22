import binary_tree
import binary_tree_excersice1
import binary_tree_excersice2
import binary_tree_excersice3
import binary_tree_excersice4

if __name__ == '__main__':
    arbolito = binary_tree.Binary_Tree()
    arbolito.create_from_file('tree_char.txt')
    arbolito.pre_orden()
    print()
    arbolito.in_orden()
    print()
    arbolito.pos_orden()
    print()
    arbolito.by_level_travel()
    print()
    arbolito.insert('D')
    arbolito.by_level_travel()
    print()
    print(arbolito.deepest_node().value)

    print(f"Searching for 'N', iteratively: {arbolito.search_iterative('N')}")
    print(f"Searching for 'N', recursively: {arbolito.search_recursive('N')}")
    print(f"Searching for 'Z', iteratively: {arbolito.search_iterative('Z')}")
    print(f"Searching for 'Z', recursively: {arbolito.search_recursive('Z')}")

    arbolito1 = binary_tree_excersice1.Binary_Tree_EX1()
    arbolito1.create_from_file('tree_int.txt')
    arbolito1.by_level_travel()
    print()

    print(arbolito1.sumatoria())

    arbolito2 = binary_tree_excersice2.Binary_Tree_EX2()
    arbolito2.create_from_file('tree_int.txt')
    arbolito2.by_level_travel()
    print()

    print(arbolito2.max())

    arbolito3 = binary_tree_excersice3.Binary_Tree_EX3()
    arbolito3.create_from_file('tree_int.txt')
    arbolito3.by_level_travel()
    print()

    print(arbolito3.max_level_sum())

    arbolito4 = binary_tree_excersice4.Binary_Tree_EX4()
    arbolito4.create_from_file('tree_int.txt')
    new_node = binary_tree_excersice4.Node(10)
    new_node1 = binary_tree_excersice4.Node(11)
    new_node2 = binary_tree_excersice4.Node(12)
    new_node3 = binary_tree_excersice4.Node(13)
    new_node4 = binary_tree_excersice4.Node(9)
    arbolito4.insert_node(new_node)
    arbolito4.insert_node(new_node1)
    arbolito4.insert_node(new_node2)
    arbolito4.insert_node(new_node3)
    arbolito4.pre_orden()
    print()

    print(arbolito4.ancestors(new_node))
    print(arbolito4.ancestors(new_node1))
    print(arbolito4.ancestors(new_node2))
    print(arbolito4.ancestors(new_node3))
    print(arbolito4.ancestors(new_node4))


