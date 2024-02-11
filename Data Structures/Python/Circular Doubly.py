class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class CircularDoublyLinkedList:
    def __init__(self):
        self.head = None

    def insert_beginning(self, value):
        new_node = Node(value)
        if not self.head:
            new_node.next = new_node  # Circular reference to itself
            new_node.prev = new_node
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = new_node
            new_node.prev = temp
        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node
        print("Element inserted at the beginning successfully.")

    def delete_beginning(self):
        if not self.head:
            print("List is empty. Cannot delete from the beginning.")
            return

        temp = self.head
        while temp.next != self.head:
            temp = temp.next

        if temp == self.head:
            self.head = None
        else:
            temp.next = self.head.next
            self.head.next.prev = temp
            self.head = temp.next

        print("Element deleted from the beginning successfully.")

    def insert_end(self, value):
        new_node = Node(value)

        if not self.head:
            new_node.next = new_node  # Circular reference to itself
            new_node.prev = new_node
            self.head = new_node
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = new_node
            new_node.prev = temp

        new_node.next = self.head
        self.head.prev = new_node
        print("Element inserted at the end successfully.")

    def delete_end(self):
        if not self.head:
            print("List is empty. Cannot delete from the end.")
            return

        temp = self.head
        prev = None

        while temp.next != self.head:
            prev = temp
            temp = temp.next

        if temp == self.head:
            self.head = None
        else:
            prev.next = temp.next
            temp.next.prev = prev

        print("Element deleted from the end successfully.")

    def insert_at_position(self, value, position):
        if position < 1:
            print("Invalid position. Element not inserted.")
            return

        if position == 1:
            self.insert_beginning(value)
            return

        new_node = Node(value)

        temp = self.head
        for i in range(1, position - 1):
            if not temp:
                print("Invalid position. Element not inserted.")
                return
            temp = temp.next

        new_node.next = temp.next
        new_node.prev = temp
        if temp.next != self.head:
            temp.next.prev = new_node
        temp.next = new_node

        print(f"Element inserted at position {position} successfully.")

    def delete_at_position(self, position):
        if not self.head:
            print("List is empty. Cannot delete from the specified position.")
            return

        if position < 1:
            print("Invalid position. Element not deleted.")
            return

        temp = self.head
        prev = None

        for i in range(1, position):
            prev = temp
            temp = temp.next

        if temp == self.head:
            if temp.next == self.head:
                self.head = None
            else:
                prev.next = temp.next
                temp.next.prev = prev
                self.head = prev.next
        else:
            prev.next = temp.next
            temp.next.prev = prev

        print(f"Element deleted from position {position} successfully.")

    def display_list(self):
        if not self.head:
            print("List is empty.")
            return

        temp = self.head

        while True:
            print(temp.data, end=" ")
            temp = temp.next
            if temp == self.head:
                break

        print()

if __name__ == "__main__":
    circular_doubly_linked_list = CircularDoublyLinkedList()

    while True:
        print("\n***** Circular Doubly Linked List Operations *****")
        print("1. Insert Beginning")
        print("2. Delete Beginning")
        print("3. Insert End")
        print("4. Delete End")
        print("5. Insert at Position")
        print("6. Delete at Position")
        print("7. Display List")
        print("8. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            value = int(input("Enter the value to insert: "))
            circular_doubly_linked_list.insert_beginning(value)
        elif choice == 2:
            circular_doubly_linked_list.delete_beginning()
        elif choice == 3:
            value = int(input("Enter the value to insert: "))
            circular_doubly_linked_list.insert_end(value)
        elif choice == 4:
            circular_doubly_linked_list.delete_end()
        elif choice == 5:
            value = int(input("Enter the value to insert: "))
            position = int(input("Enter the position to insert: "))
            circular_doubly_linked_list.insert_at_position(value, position)
        elif choice == 6:
            position = int(input("Enter the position to delete: "))
            circular_doubly_linked_list.delete_at_position(position)
        elif choice == 7:
            circular_doubly_linked_list.display_list()
        elif choice == 8:
            print("Exiting program. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a valid option.")
