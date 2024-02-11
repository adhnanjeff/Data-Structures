import java.util.LinkedList;
import java.util.Queue;

class Graph {
    private int vertices;
    private int[][] adjacencyMatrix;

    public Graph(int vertices) {
        this.vertices = vertices;
        this.adjacencyMatrix = new int[vertices][vertices];
    }

    public void addEdge(int src, int dest) {
        this.adjacencyMatrix[src][dest] = 1;
        this.adjacencyMatrix[dest][src] = 1;
    }

    public void BFS(int startVertex) {
        boolean[] visited = new boolean[vertices];
        Queue<Integer> queue = new LinkedList<>();

        visited[startVertex] = true;
        System.out.print(startVertex + " ");

        queue.add(startVertex);

        while (!queue.isEmpty()) {
            int currentVertex = queue.poll();

            for (int i = 0; i < vertices; ++i) {
                if (adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    System.out.print(i + " ");
                    queue.add(i);
                }
            }
        }
    }

    public static void main(String[] args) {
        int vertices = 5;
        Graph graph = new Graph(vertices);

        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 3);
        graph.addEdge(1, 4);

        System.out.print("Breadth-First Traversal: ");
        graph.BFS(0);
    }
}
