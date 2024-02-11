class Queue:
    def __init__(self):
        self.items = []

    def is_empty(self):
        return len(self.items) == 0

    def enqueue(self, item):
        self.items.append(item)
        print(f"Enqueued: {item}")

    def dequeue(self):
        if not self.is_empty():
            dequeued_item = self.items.pop(0)
            print(f"Dequeued: {dequeued_item}")
            return dequeued_item
        else:
            print("Queue is empty. Cannot dequeue.")

    def front(self):
        if not self.is_empty():
            return self.items[0]
        else:
            print("Queue is empty. Cannot get front element.")

    def display(self):
        if not self.is_empty():
            print("Queue elements:")
            for item in self.items:
                print(item)
        else:
            print("Queue is empty.")


queue = Queue()

queue.enqueue(10)
queue.enqueue(20)
queue.enqueue(30)

queue.display()

front_element = queue.front()
print(f"Front element: {front_element}")

dequeued_item = queue.dequeue()
print(f"Dequeued item: {dequeued_item}")

queue.display()
