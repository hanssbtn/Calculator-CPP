#ifndef __LINKED_LIST
#define __LINKED_LIST

#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath> 
#include <sstream>
#include <numbers>
#include <type_traits>
#include <functional>
#include <cstdint>
#include <unordered_map>

/// @brief Custom singly linked list node to store user log.
struct Node {
    /// @brief Calculated value of the logged calculation.
    double result;

    /// @brief User calculation log.
    std::string equation;

    /// @brief Pointer to the next element of the array.
    Node* nextNodePtr;

    /// @brief Default constructor for node class.
    Node();

    /// @brief Overloaded constructor with parameters to initialize the node.
    /// @param inputLog User calculation log.
    /// @param logResult Calculated value. 
    Node(std::string inputLog, double logResult);
};

/// @brief Custom made singly linked list class to story all user logs.
class LinkedList{
    public:
        /// @brief Constructor for the linked list class.
        LinkedList();

        /// @brief Linked list destructor. 
        /// Called when the postfix notation of the equation is formed. 
        ~LinkedList();

        /// @brief Method for appending another node to the list.
        /// @param inputLog Logged user calculation.
        /// @param result Result of the calculation. 
        /// @return true if the operations is successful, false otherwise.
        bool insertNode(std::string inputLog, double result);

        /// @brief Method for traversing the linked list and printing the contents. 
        /// @returns a pointer to the currently accessed node. 
        void traverseLinkedList();

        /// @brief Method for deleting the last node on the list. 
        void deleteTailNode();

        /// @brief Method for accessing the last node on the list.
        /// @return a const reference to the tail node.
        const Node& getTailNode();

    private: 
        /// @brief Pointer to the last element of the list.
        Node* tailNode;

        /// @brief Pointer to the currently traversed node.
        Node* currentNode;

        /// @brief Pointer to the first element of the list.
        Node* headNode;
};

#endif