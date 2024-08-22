#include "iostream" // Include the iostream library for input-output operations
#include "stdlib.h" // Include the standard library for functions like exit()

// Define a structure for the nodes of the queue
struct node {
    int info; // Data part of the node
    struct node *next; // Pointer to the next node in the queue
};

// Define a Queue class
class Queue {
private:
    node *rear; // Pointer to the rear of the queue
    node *front; // Pointer to the front of the queue

public:
    // Constructor to initialize front and rear to NULL
    Queue() {
        rear = NULL;
        front = NULL;
    }

    // Function to add an element to the queue
    void EnQueue();

    // Function to remove an element from the queue
    void DeQueue();

    // Function to display the elements of the queue
    void Display();
};

// Implementation of EnQueue function
void Queue::EnQueue() {
    int data; // Variable to store input data
    node *temp = new node; // Create a new node
    std::cout << "\nEnter the data to be inserted: ";
    std::cin >> data; // Take input from the user
    temp->info = data; // Set the info part of the node with input data
    temp->next = NULL; // Set the next part of the node to NULL

    // If the queue is empty, set front to the new node
    if (front == NULL) {
        front = temp;
    } else {
        // If the queue is not empty, add the
        // new node to the end of the queue and update the rear pointer
        rear->next = temp;
    }
    rear = temp; // Update the rear pointer to the new node
    std::cout << "Element inserted into the queue." << std::endl;
}

// Implementation of DeQueue function
void Queue::DeQueue() {
    if (front == NULL) {
        std::cout << "Queue is empty. Cannot perform DeQueue operation." << std::endl;
        return;
    }
    node *temp = front; // Store the front node in a temporary pointer
    front = front->next; // Move the front pointer to the next node
    std::cout << "Element removed: " << temp->info << std::endl;
    delete temp; // Delete the old front node

    // If the queue becomes empty after the DeQueue operation, set rear to NULL
    if (front == NULL) {
        rear = NULL;
    }
}

// Implementation of Display function
void Queue::Display() {
    if (front == NULL) {
        std::cout << "Queue is empty." << std::endl;
        return;
    }
    node *temp = front; // Start from the front of the queue
    std::cout << "Queue elements: ";
    while (temp != NULL) {
        std::cout << temp->info << " "; // Print the info part of the node
        temp = temp->next; // Move to the next node
    }
    std::cout << std::endl;
}

// Main function to demonstrate the queue operations
int main() {
    Queue q; // Create a Queue object
    int choice;

    while (true) {
        std::cout << "\n1. EnQueue\n2. DeQueue\n3. Display\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                q.EnQueue();
                break;
            case 2:
                q.DeQueue();
                break;
            case 3:
                q.Display();
                break;
            case 4:
                exit(0); // Exit the program
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
