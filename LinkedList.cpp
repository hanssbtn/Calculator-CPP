#include "LinkedList.hpp"
#include <iostream>

// Use initializer list to initialize the nodes.
Node::Node() : result(0.0), equation(""), nextNodePtr(nullptr) {}
Node::Node(std::string inputLog, double logResult) : result(logResult), equation(inputLog), nextNodePtr(nullptr) {}

LinkedList::LinkedList(){
    // Initialize the head tail node to null.
    this->tailNode = new Node;

    // Initialize the head to point to the tail.
    this->headNode = new Node;
    this->headNode->nextNodePtr = this->tailNode;

    // Initialize the current node pointer to point to the list's head.
    this->currentNode = this->headNode;
}

LinkedList::~LinkedList() {
    // Check if the list is empty. If yes, return.
    if (this->headNode == nullptr) return;

    // Initialize currentNode to the head.
    this->currentNode = this->headNode; 

    // Initialize a temporary Node* variable to hold the address of the next pointer.
    Node* tempNodePtr = this->currentNode->nextNodePtr;

    // Traverse the list by checking if the nextNodePtr is null. If yes, the end of list has been reached.
    while (this->currentNode->nextNodePtr != nullptr){
        // Initialize a temporary Node* variable to hold the address of the next pointer.
        tempNodePtr = this->currentNode->nextNodePtr;

        // Free the memory used by the node.
        delete this->currentNode;

        // Continue traversing the list.
        this->currentNode = tempNodePtr;
    }

    // Free the memory used by the last node.
    delete tempNodePtr;
}

bool LinkedList::insertNode(std::string inputLog, double result){
    // Declare new node to append at the start of the list.
    Node* newNode;

    // Try to allocate memory for the new node. If fails, handle exception and return false.
    try {
        newNode = new Node(inputLog, result);
    } catch (std::bad_alloc& err) {
        std::cerr << "bad_alloc caught: " << err.what() << std::endl << "Failed to allocate new node. Clear history to continue." << std::endl;
        return false;
    }

    // Check if the head and tail nodes are empty. If yes, assign the values to the tail / head node.
    if (this->tailNode->equation.empty()){
        this->tailNode->equation = inputLog;
        this->tailNode->result = result;
        this->currentNode = this->tailNode;
        return true;
    }
    if (this->headNode->equation.empty()){
        this->headNode->equation = inputLog;
        this->headNode->result = result;
        this->currentNode = this->headNode;
        return true;
    }

    // Set the pointer of the new node to the head node.
    newNode->nextNodePtr = this->headNode;
    
    // Set new node to be the new head and the current node to point at it, then return true.
    this->headNode = newNode;
    this->currentNode = this->headNode;
    return true;
}

void LinkedList::traverseLinkedList() {
    // Set the current node to the head node.
    this->currentNode = this->headNode;

    // Iterate over the linked list and print out the values inside each node.
    while (this->currentNode != nullptr){
        std::cout << "Equation: " << this->currentNode->equation << ", Result: " << this->currentNode->result << '\n';
        this->currentNode = this->currentNode->nextNodePtr;
    }
    std::cout << '\n' << std::endl;
}

void LinkedList::deleteTailNode() {
    // Initialize a temporary node pointer to traverse the list.
    Node* tempNodePointer = this->headNode;

    // Find the second to last node on the list.
    while (tempNodePointer->nextNodePtr != this->tailNode){
        tempNodePointer = tempNodePointer->nextNodePtr;
    }

    // Check if the node is the head node. If yes, delete the values,
    // And add a tail node and assign its address to headNode's nextNodePtr.
    if (tempNodePointer == this->headNode) {
        this->headNode->equation = "";
        this->headNode->result = 0;
        this->headNode->nextNodePtr = new Node;
        this->headNode->nextNodePtr->equation = "";
        this->headNode->nextNodePtr->result = 0;
        this->headNode->nextNodePtr->nextNodePtr = nullptr;
        this->tailNode = this->headNode->nextNodePtr;
        return;
    }

    // Delete the last node on the list, then reassign the tail to the value of the temporary node pointer.
    // Set the pointer to the next node at the new tail to nullptr.
    delete this->tailNode;
    tempNodePointer->nextNodePtr = nullptr;
    this->tailNode = tempNodePointer;
}

const Node& LinkedList::getTailNode(){
    // Initialize a const Node& variable to hold the reference.
    const Node& tailRef = *this->tailNode;

    // Return the reference variable.
    return tailRef; 
}