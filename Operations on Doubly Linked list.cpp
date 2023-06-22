#include <iostream>
#include <vector>

using namespace std;

// defining a doubly linked list node
struct Node {
    int n;
    Node* prev;
    Node* next;
};

// defining a doubly linked list class
class dList {
private:
    Node* head;
    Node* tail;

public:
    // constructor to initialize the linked list with null values for head and
    // tail
    dList() {
        head = NULL;
        tail = NULL;
    }

    // destructor to free the memory allocated for the linked list
    ~dList() {}

    // generating a doubly linked list from the given vector of integers
    void generate_dlist(const vector<int>& v) {
        for (int i = 0; i < v.size(); i++) {
            Node* newNode = new Node;
            newNode->n = v[i];
            newNode->prev = tail;
            newNode->next = NULL;
            if (tail != NULL) {
                tail->next = newNode;
            }
            tail = newNode;
            if (head == NULL) {
                head = newNode;
            }
        }
    }

    // printing the doubly linked list
    void print() {
        Node* new_node;
        new_node = head;

        while (new_node != NULL) {
            cout << "[";
            cout << new_node->n;

            // checking length of the number
            int num_digits = 0, temp = new_node->n;
            while (temp != 0) {
                num_digits++;
                temp /= 10;
            }
            cout << ", " << num_digits;

            // checking if the integer is a palindrome
            int is_palindrome = 1, reverse_num = 0, digit;
            temp = new_node->n;
            while (temp != 0) {
                digit = temp % 10;
                reverse_num = reverse_num * 10 + digit;
                temp /= 10;
            }
            if (new_node->n != reverse_num) {
                is_palindrome = 0;
            }
            cout << ", " << is_palindrome;

            cout << "]" << endl;
            new_node = new_node->next;
        }
    }

    // finding the largest number in the doubly linked list
    int largest_integer() {
        int largest_val = 0;
        Node* new_node;
        new_node = head;

        while (new_node != NULL) {
            if (new_node->n > largest_val) {
                largest_val = new_node->n;
            }
            new_node = new_node->next;
        }

        return largest_val;
    }

    // finding the neighbors of the given integer in the doubly linked list
    void neighbors(int k) {
        Node* new_node = head;
        while (new_node != NULL) {
            if (new_node->n == k) {
                if (new_node == head) {
                    cout << "__, ";
                }
                else {
                    cout << new_node->prev->n << ", ";
                }
                if (new_node == tail) {
                    cout << "__" << endl;
                }
                else {
                    cout << new_node->next->n << endl;
                }
            }
            new_node = new_node->next;
        }
    }

    // inserting a new integer before the given integer in the doubly linked list
    void insert_before(int k, int x) {
        Node* new_node = new Node;
        new_node->n = x;

        Node* current_node = head;
        while (current_node != NULL) {
            if (current_node->n == k) {
                new_node->prev = current_node->prev;
                new_node->next = current_node;
                if (current_node->prev != NULL) {
                    current_node->prev->next = new_node;
                }
                else {
                    head = new_node;
                }
                current_node->prev = new_node;
            }
            current_node = current_node->next;
        }
    }

    // deleting an integer in the doubly linked list
    void delete_integer(int k) {
        Node* current_node = head;

        while (current_node != NULL) {
            if (current_node->n == k) {
                if (current_node->prev != NULL) {
                    current_node->prev->next = current_node->next;
                }
                else {
                    head = current_node->next;
                }

                if (current_node->next != NULL) {
                    current_node->next->prev = current_node->prev;
                }
                else {
                    tail = current_node->prev;
                }

                Node* temp = current_node;
                current_node = current_node->next;
                delete temp;
            }
            else {
                current_node = current_node->next;
            }
        }
    }

    // reversing the doubly linked list
    void reverse_list() {
        Node* current_node = head;
        Node* temp_node;

        while (current_node != NULL) {
            temp_node = current_node->prev;
            current_node->prev = current_node->next;
            current_node->next = temp_node;
            current_node = current_node->prev;
        }

        if (temp_node != NULL) {
            head = temp_node->prev;
        }
    }
};

int main() {
    dList L;
    vector<int> v = { 258,      121,    33,       678876,    12721, 95441159,
                     12626387, 1271,   27182712, 999269873, 5281,  23764,
                     9988,     126712, 33,       1271 };

    L.generate_dlist(v);
    L.print();
    cout << "-------------------" << endl;
    cout << "-------------------" << endl;
    cout << L.largest_integer() << endl;
    L.neighbors(33);
    cout << "-------------------" << endl;
    L.insert_before(121, 2);
    L.print();
    cout << "-------------------" << endl;
    L.delete_integer(5281);
    L.print();
    cout << "-------------------" << endl;
    L.reverse_list();
    L.print();
    return 0;
}
