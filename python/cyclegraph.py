class Node(object):
    def __init__(self, value):
        self.value = value
        self.visited = False  #dfs

    def __repr__(self):
        return str(self.value) + "Visited : " + str(self.visited) + "\n"


class Edge(object):
    def __init__(self, node_one, node_two):
        self.node_one = node_one
        self.node_two = node_two

    def __repr__(self):
        return str(self.node_one) + \
            " --> " +  str(self.node_two)


class Graph(object):
    def __init__(self, edge_list):
        self.edges = []
        self.node_dict = {}
        self.create_graph(edge_list)

    def do_dfs(self, node):
        if node.visited is False:
            node.visited = True
            for node in node.neigh:
                self.do_dfs(node)

    def add_edge(self, prev_key, key):
        if prev_key in self.node_dict and key in self.node_dict:
            self.edges.append(Edge(prev_key, key))

    def create_nodes(self, keys):
        for key in keys:
            if key not in self.node_dict:
                self.node_dict[key] = Node(key)

    def create_edges(self, keys):
        prev_key = -1
        for key in keys:
            self.add_edge(prev_key, key)
            prev_key = key

    def go_rev(self, edge_index):
        """
        Goes reverse and prints the array.
        """
        rev_cycle = []
        index = edge_index
        node_val = self.edges[index].node_two
        val = -1
        while (val != node_val):
            edge = self.edges[index]
            val = edge.node_one
            rev_cycle.append(val)
            index = index - 1

        return rev_cycle[::-1]

    def get_first_cycle(self):
        """
        Look at the nodes, if the node 
        """
        # save the first point in a set
        edge_status = set()
        for edge_index, edge in enumerate(self.edges):
            edge_status.add(edge.node_one)
            if edge.node_two in edge_status:
                return self.go_rev(edge_index)

    def create_graph(self, edge_list):
        """ 
        Each number is a node and each number has a next which could be pointing to itself.
        """
        self.create_nodes(keys)
        self.create_edges(keys)

    def __repr__(self):
        return "Verticies = " + str(self.node_dict) + "Edges" + str(self.edges)


def disp(output):

    for num in output:
        print num,
    print


import sys
test_cases = open(sys.argv[1], 'r')
for test in test_cases:
    keys = (test.strip().split())
    graph_obj = Graph(keys)
    disp(graph_obj.get_first_cycle())

test_cases.close()
