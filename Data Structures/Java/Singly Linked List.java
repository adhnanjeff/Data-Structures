import java.util.Scanner;

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class SinglyLinkedList {
    private static Node head = null;

    public static void insertBeginning(int value) {
        Node newNode = new Node(value);
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
        head = head.next;
        temp = null;
        System.out.println("Element deleted from the beginning successfully.");
    }

    public static void insertEnd(int value) {
        Node newNode = new Node(value);

        if (head == null) {
            head = newNode;
            System.out.println("Element inserted at the end successfully.");
            return;
        }

        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }

        temp.next = newNode;
        System.out.println("Element inserted at the end successfully.");
    }

    public static void deleteEnd() {
        if (head == null) {
            System.out.println("List is empty. Cannot delete from the end.");
            return;
        }

        if (head.next == null) {
            head = null;
            System.out.println("Element deleted from the end successfully.");
            return;
        }

        Node temp = head;
        Node prev = null;
        while (temp.next != null) {
            prev = temp;
            temp = temp.next;
        }

        prev.next = null;
        temp = null;
        System.out.println("Element deleted from the end successfully.");
    }

    public static void insertMiddle(int value) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the position to insert after: ");
        int position = scanner.nextInt();

        Node newNode = new Node(value);

        Node temp = head;
        for (int i = 1; i < position && temp != null; i++) {
            temp = temp.next;
        }

        if (temp == null) {
            System.out.println("Invalid position. Element not inserted.");
            return;
        }

        newNode.next = temp.next;
        temp.next = newNode;
        System.out.println("Element inserted at position " + position + " successfully.");
    }

    public static void deleteMiddle() {
        if (head == null) {
            System.out.println("List is empty. Cannot delete from the middle.");
            return;
        }

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the position to delete: ");
        int position = scanner.nextInt();

        Node temp = head;
        Node prev = null;
        for (int i = 1; i < position && temp != null; i++) {
            prev = temp;
            temp = temp.next;
        }

        if (temp == null) {
            System.out.println("Invalid position. Element not deleted.");
            return;
        }

        if (prev == null) {
            head = temp.next;
        } else {
            prev.next = temp.next;
        }

        temp = null;
        System.out.println("Element deleted from position " + position + " successfully.");
    }

    public static void displayList() {
        Node temp = head;
        System.out.print("List: ");
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int choice, value;

        do {
            System.out.println("\n***** Singly Linked List Operations *****");
            System.out.println("1. Insert Beginning");
            System.out.println("2. Delete Beginning");
            System.out.println("3. Insert End");
            System.out.println("4. Delete End");
            System.out.println("5. Insert Middle");
            System.out.println("6. Delete Middle");
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
                    insertMiddle(value);
                    break;
                case 6:
                    deleteMiddle();
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
