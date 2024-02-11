import java.util.LinkedList;

class Queue {
    private LinkedList<Integer> list;

    public Queue() {
        list = new LinkedList<>();
    }

    public boolean isEmpty() {
        return list.isEmpty();
    }

    public void enqueue(int item) {
        list.addLast(item);
    }

    public int dequeue() {
        if (!isEmpty()) {
            return list.removeFirst();
        } else {
            throw new IllegalStateException("Queue is empty");
        }
    }

    public int front() {
        if (!isEmpty()) {
            return list.getFirst();
        } else {
            throw new IllegalStateException("Queue is empty");
        }
    }

    public static void main(String[] args) {
        Queue queue = new Queue();
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);

        System.out.println("Front element: " + queue.front());

        System.out.println("Dequeued element: " + queue.dequeue());
        System.out.println("Dequeued element: " + queue.dequeue());

        System.out.println("Front element after dequeues: " + queue.front());
    }
}
