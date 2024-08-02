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
