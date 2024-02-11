class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insert_beginning(self, value):
        new_node = Node(value)
        new_node.next = self.head
        if self.head:
            self.head.prev = new_node
        self.head = new_node
        print("Element inserted at the beginning successfully.")

    def delete_beginning(self):
        if not self.head:
            print("List is empty. Cannot delete from the beginning.")
            return

        temp = self.head
        self.head = self.head.next
        if self.head:
            self.head.prev = None
        temp = None
        print("Element deleted from the beginning successfully.")

    def insert_end(self, value):
        new_node = Node(value)

        if not self.head:
            self.head = new_node
            print("Element inserted at the end successfully.")
            return

        temp = self.head
        while temp.next:
            temp = temp.next

        temp.next = new_node
        new_node.prev = temp
        print("Element inserted at the end successfully.")

    def delete_end(self):
        if not self.head:
            print("List is empty. Cannot delete from the end.")
            return

        if not self.head.next:
            self.head = None
            print("Element deleted from the end successfully.")
            return

        temp = self.head
        while temp.next:
            temp = temp.next

        temp.prev.next = None
        temp = None
        print("Element deleted from the end successfully.")

    def insert_middle(self, value):
        print("Enter the position to insert after: ")
        position = int(input())

        new_node = Node(value)

        temp = self.head
        for i in range(1, position):
            if not temp:
                print("Invalid position. Element not inserted.")
                return
            temp = temp.next

        new_node.next = temp.next
        new_node.prev = temp
        if temp.next:
            temp.next.prev = new_node
        temp.next = new_node

        print(f"Element inserted at position {position} successfully.")

    def delete_middle(self):
        if not self.head:
            print("List is empty. Cannot delete from the middle.")
            return

        print("Enter the position to delete: ")
        position = int(input())

        temp = self.head
        for i in range(1, position):
            if not temp:
                print("Invalid position. Element not deleted.")
                return
            temp = temp.next

        if temp.prev:
            temp.prev.next = temp.next
        else:
            self.head = temp.next

        if temp.next:
            temp.next.prev = temp.prev

        temp = None
        print(f"Element deleted from position {position} successfully.")

    def display_list(self):
        temp = self.head
        print("List: ", end="")
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()

if __name__ == "__main__":
    doubly_linked_list = DoublyLinkedList()

    while True:
        print("\n***** Doubly Linked List Operations *****")
        print("1. Insert Beginning")
        print("2. Delete Beginning")
        print("3. Insert End")
        print("4. Delete End")
        print("5. Insert Middle")
        print("6. Delete Middle")
        print("7. Display List")
        print("8. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            value = int(input("Enter the value to insert: "))
            doubly_linked_list.insert_beginning(value)
        elif choice == 2:
            doubly_linked_list.delete_beginning()
        elif choice == 3:
            value = int(input("Enter the value to insert: "))
            doubly_linked_list.insert_end(value)
        elif choice == 4:
            doubly_linked_list.delete_end()
        elif choice == 5:
            value = int(input("Enter the value to insert: "))
            doubly_linked_list.insert_middle(value)
        elif choice == 6:
            doubly_linked_list.delete_middle()
        elif choice == 7:
            doubly_linked_list.display_list()
        elif choice == 8:
            print("Exiting program. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a valid option.")
