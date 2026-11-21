
#include <iostream>
#include <stdexcept>
using namespace std;
struct Node {
  int data;
  Node *next;
  Node *prev;

  Node(int value) {
    data = value;
    next = nullptr;
    prev = nullptr;
  }
};
class LinkedList {

private:
  Node *head;
  Node *tail;

public:
  LinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  LinkedList(int data) {
    Node *firstNode = new Node(data);
    head = tail = firstNode;
    head->next = head;
    head->prev = head;
  }

  Node *find(int value) {
    if (head == nullptr)
      return nullptr;

    Node *current = head;

    do {
      if (current->data == value) {
        // cout<<"value exist \n";
        return current;
      }

      current = current->next;

    } while (current != head);
    cout << "Value not found \n";
    return nullptr;
  }

  void display() {
    if (head == nullptr) {
      cout << "Empty List\n";
      return;
    }

    Node *current = head;

    do {
      cout << current->data << "   ";
      current = current->next;
    } while (current != head);
  }

  void add(int data) {

    Node *newNode = new Node(data);

    if (head == nullptr) {
      head = tail = newNode;

      head->next = head;
      head->prev = head;

      return;
    }

    newNode->prev = tail;
    newNode->next = head;

    tail->next = newNode;
    head->prev = newNode;

    tail = newNode;
  }

  void InsertAfter(int data, int afterData) {

    Node *current = find(afterData);

    if (current == nullptr) {
      cout << "the list is empty\n";
      return;
    }

    Node *newNode = new Node(data);

    newNode->next = current->next;
    newNode->prev = current;

    current->next->prev = newNode;
    current->next = newNode;

    if (current == tail)
      tail = newNode;
  }

  void InsertBefore(int data, int beforeData) {

    Node *current = find(beforeData);

    if (current == nullptr)
      return;

    Node *newNode = new Node(data);

    newNode->next = current;
    newNode->prev = current->prev;

    current->prev->next = newNode;
    current->prev = newNode;

    if (current == head)
      head = newNode;
  }

  int GetCount() {

    if (head == nullptr)
      return 0;

    int count = 0;
    Node *current = head;

    do {
      count++;
      current = current->next;
    } while (current != head);

    return count;
  }

  int GetDataByIndex(int index) {

    if (index < 0) {
      cout << "Invalid index";
      return 0;
    }

    Node *current = head;
    int count = 0;

    if (head == nullptr) {
      cout << "Empty list";
      return 0;
    }

    while (current != nullptr) {

      if (count == index)
        return current->data;

      current = current->next;
      count++;

      if (current == head)
        break;
    }

    throw out_of_range("Index out of range");
  }

  // Destructor
  ~LinkedList() {

    if (head == nullptr)
      return;

    Node *current = head->next;

    while (current != head) {
      Node *temp = current;
      current = current->next;
      delete temp;
    }

    delete head;

    head = nullptr;
    tail = nullptr;
  }
};
