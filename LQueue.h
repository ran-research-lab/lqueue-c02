//
// Implementation of a stack using array
//

#ifndef AQUEUE_H
#define AQUEUE_H
#include "Queue.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;
typedef int queueElementType;

class Node {         // Singly linked list node class
public:
    queueElementType data;    // Value for this node
    Node *next;      // Point to next node in list

    // Constructor
    Node(queueElementType d = 0, Node *n = NULL) { data = d; next = n; }
};


// Linked queue implementation
class LQueue : public Queue {
private:
  Node* front; // Pointer to front queue node
  Node* rear;  // Pointer to rear queue node
  int size;   // Number of elements in queue
public:
  LQueue(int dummy = 0) { 
    
    front = rear = new Node();
    size = 0;
  }

  // Put element on rear
  bool enqueue(const queueElementType& it) {
    rear->next = new Node(it);
    rear = rear->next;
    size++;
    return true;
  }

  // Remove and return element from front
  queueElementType dequeue() {
    if (size == 0) 
      throw std::out_of_range("trying to dequeue from empty LStack");
    Node *tmp = front->next;
    queueElementType it = front->next->data; // Store the value
    front->next = front->next->next; // Advance front
    if (front->next == NULL) rear = front; // Last element
    delete tmp;
    size--;
    return it; // Return element
  }

  // Return front element
  queueElementType frontValue() {
    if (size == 0) 
      throw std::out_of_range("trying to get front value from empty LStack");
    return front->next->data;
  }

  // Return queue size
  int length() const { 
    std::cout << "length....\n" << size << endl;
    return size; }

  // Check if the queue is empty
  bool isEmpty() const { return size == 0; }


  string to_string() const {
    string res;
      Node *tmp = front->next;
      while (tmp!=NULL) {

          res += std::to_string(tmp->data);
          if (tmp!= rear)  res += ",";
          tmp = tmp->next;
      }

      return res;


  }
  
};

#endif //AQUEUE_H
