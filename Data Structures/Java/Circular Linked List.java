import java.util.Scanner;

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class CircularLinkedList {
    private static Node head = null;

    public static void insertBeginning(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            newNode.next = newNode; // Circular reference to itself
        } else {
            Node temp = head;
            while (temp.next != head) {
                temp = temp.next;
            }
            temp.next = newNode;
        }
        newNode.next = head;
        head = newNode;
        System.out.println("Element inserted at the beginning successfully.");
    }

    public static void deleteBeginning() {
        if (head == null) {
            System.out.println("List is empty. Cannot delete from the beginning.");
            return;
        }

        Node temp = head;
        while (temp.next != head) {
            temp = temp.next;
        }

        if (temp == head) {
            head = null;
        } else {
            temp.next = head.next;
            head = temp.next;
        }

        System.out.println("Element deleted from the beginning successfully.");
    }

    public static void insertEnd(int value) {
        Node newNode = new Node(value);

        if (head == null) {
            newNode.next = newNode; // Circular reference to itself
            head = newNode;
        } else {
            Node temp = head;
            while (temp.next != head) {
                temp = temp.next;
            }
            temp.next = newNode;
        }

        newNode.next = head;
        System.out.println("Element inserted at the end successfully.");
    }

    public static void deleteEnd() {
        if (head == null) {
            System.out.println("List is empty. Cannot delete from the end.");
            return;
        }

        Node temp = head;
        Node prev = null;

        while (temp.next != head) {
            prev = temp;
            temp = temp.next;
        }

        if (temp == head) {
            head = null;
        } else {
            prev.next = temp.next;
        }

        System.out.println("Element deleted from the end successfully.");
    }

    public static void insertAtPosition(int value, int position) {
        if (position < 1) {
            System.out.println("Invalid position. Element not inserted.");
            return;
        }

        if (position == 1) {
            insertBeginning(value);
            return;
        }

        Node newNode = new Node(value);

        Node temp = head;
        for (int i = 1; i < position - 1; i++) {
            if (temp == null) {
                System.out.println("Invalid position. Element not inserted.");
                return;
            }
            temp = temp.next;
        }

        newNode.next = temp.next;
        temp.next = newNode;

        System.out.println("Element inserted at position " + position + " successfully.");
    }

    public static void deleteAtPosition(int position) {
        if (head == null) {
            System.out.println("List is empty. Cannot delete from the specified position.");
            return;
        }

        if (position < 1) {
            System.out.println("Invalid position. Element not deleted.");
            return;
        }

        Node temp = head;
        Node prev = null;

        for (int i = 1; i < position; i++) {
            prev = temp;
            temp = temp.next;
        }

        if (temp == head) {
            if (temp.next == head) {
                head = null;
            } else {
                prev.next = temp.next;
                head = prev.next;
            }
        } else {
            prev.next = temp.next;
        }

        System.out.println("Element deleted from position " + position + " successfully.");
    }

    public static void displayList() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        Node temp = head;

        do {
            System.out.print(temp.data + " ");
            temp = temp.next;
        } while (temp != head);

        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice, value, position;

        do {
            System.out.println("\n***** Circular Linked List Operations *****");
            System.out.println("1. Insert Beginning");
            System.out.println("2. Delete Beginning");
            System.out.println("3. Insert End");
            System.out.println("4. Delete End");
            System.out.println("5. Insert at Position");
            System.out.println("6. Delete at Position");
            System.out.println("7. Display List");
            System.out.println("8. Exit");

            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the value to insert: ");
                    value = scanner.nextInt();
                    insertBeginning(value);
                    break;
                case 2:
                    deleteBeginning();
                    break;
                case 3:
                    System.out.print("Enter the value to insert: ");
                    value = scanner.nextInt();
                    insertEnd(value);
                    break;
                case 4:
                    deleteEnd();
                    break;
                case 5:
                    System.out.print("Enter the value to insert: ");
                    value = scanner.nextInt();
                    System.out.print("Enter the position to insert: ");
                    position = scanner.nextInt();
                    insertAtPosition(value, position);
                    break;
                case 6:
                    System.out.print("Enter the position to delete: ");
                    position = scanner.nextInt();
                    deleteAtPosition(position);
                    break;
                case 7:
                    displayList();
                    break;
                case 8:
                    System.out.println("Exiting program. Goodbye!");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }
        } while (choice != 8);
    }
}
