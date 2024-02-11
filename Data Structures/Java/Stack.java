import java.util.EmptyStackException;

class Stack {
    private static final int MAX_SIZE = 100;
    private int[] arr;
    private int top;

    public Stack() {
        arr = new int[MAX_SIZE];
        top = -1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == MAX_SIZE - 1;
    }

    public void push(int item) {
        if (!isFull()) {
            arr[++top] = item;
        } else {
            System.out.println("Stack overflow");
        }
    }

    public int pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            throw new EmptyStackException();
        }
    }

    public int peek() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            throw new EmptyStackException();
        }
    }

    public static void main(String[] args) {
        Stack stack = new Stack();
        stack.push(10);
        stack.push(20);
        stack.push(30);

        System.out.println("Top element: " + stack.peek());

        System.out.println("Popped element: " + stack.pop());
        System.out.println("Popped element: " + stack.pop());

        System.out.println("Top element after pops: " + stack.peek());
    }
}
