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

int main() {
    int count = 0;
    Node *head = nullptr;
    // Generate 3 Customers
    for (int i = 0; i < 3; i++){
        int randName = rand() % 10 + 1;
        int randDrink = rand() % 10 + 1;

        addNode(head, names[randName], drinks[randDrink]);
    }

    while (count < 10) {
        // Random probability number
        int rand_num = rand() % 100;

        // If 50% add person to queue
        if (rand_num < 50) {
            int randName = rand() % 10 + 1;
            int randDrink = rand() % 10 + 1;

            addNode(head, names[randName], drinks[randDrink]);
        }
        
        count++;
    }

}