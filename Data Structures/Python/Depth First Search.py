from collections import defaultdict

class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adjacency_matrix = defaultdict(list)

    def add_edge(self, src, dest):
        self.adjacency_matrix[src].append(dest)
        self.adjacency_matrix[dest].append(src)

    def DFS(self, start_vertex):
        visited = [False] * self.vertices
        stack = [start_vertex]

        visited[start_vertex] = True
        print(start_vertex, end=" ")

        while stack:
            current_vertex = stack.pop()

            for neighbor in self.adjacency_matrix[current_vertex]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    print(neighbor, end=" ")
                    stack.append(neighbor)

if __name__ == "__main__":
    vertices = 5
    graph = Graph(vertices)

    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(1, 3)
    graph.add_edge(1, 4)

    print("Depth-First Traversal:", end=" ")
    graph.DFS(0)
