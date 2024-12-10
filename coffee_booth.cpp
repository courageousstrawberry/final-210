#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    string name;
    string drinkOrder;
    Node* next;
};

const string names[] = {"Alicia", "Frank", "John", "Emma", "Sophia", "Liam", "Olivia", "Noah", "Ava", "James"};
const string drinks[] = {"Cappuccino", "Mocha", "Americano", "Latte", "Espresso", "Macchiato", "Flat", "Affogato", "Cortado", "Irish"};

// Function that adds a node to a linked list
void addNode(Node*& head, const string& name, const string& drink) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->drinkOrder = drink;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        }
}

void deleteFrontNode(Node*& head) {    
    if(head == nullptr) {
        return;
    }
    else {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void display(Node*& head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << "- " << temp->name << ", " << temp->drinkOrder << endl;
        temp = temp->next;
    }
}

int main() {
    int count = 0;
    Node *head = nullptr;
    srand(time(0));
    // Generate 3 Customers
    for (int i = 0; i < 3; i++){
        int randName = rand() % 10 + 1;
        int randDrink = rand() % 10 + 1;

        addNode(head, names[randName], drinks[randDrink]);
    }

    while (count < 10) {
        display(head);
        // Random probability number
        int rand_num = rand() % 100;

        // If 50% add person to queue
        if (rand_num < 50) {
            int randName = rand() % 10;
            int randDrink = rand() % 10;

            addNode(head, names[randName], drinks[randDrink]);
        }
        
        deleteFrontNode(head);
        
        count++;
        cout << "--------------" << endl;
    }

}