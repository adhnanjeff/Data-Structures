from collections import defaultdict, deque

class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adjacency_matrix = defaultdict(list)

    def add_edge(self, src, dest):
        self.adjacency_matrix[src].append(dest)
        self.adjacency_matrix[dest].append(src)

    def BFS(self, start_vertex):
        visited = [False] * self.vertices
        queue = deque([start_vertex])

        visited[start_vertex] = True
        print(start_vertex, end=" ")

        while queue:
            current_vertex = queue.popleft()

            for neighbor in self.adjacency_matrix[current_vertex]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    print(neighbor, end=" ")
                    queue.append(neighbor)

if __name__ == "__main__":
    vertices = 5
    graph = Graph(vertices)

    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(1, 3)
    graph.add_edge(1, 4)

    print("Breadth-First Traversal:", end=" ")
    graph.BFS(0)
