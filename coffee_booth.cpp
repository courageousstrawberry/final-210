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

int main() {
    int count = 0;
    Node *head = nullptr;
    // Generate 3 Customers
    for (int i = 0; i < 3; i++){
        int randName = rand() % 10 + 1;
        int randDrink = rand() % 10 + 1;

        Node* newNode = new Node;
        newNode->name = names[randName];
        newNode->drinkOrder = drinks[randDrink];
        newNode->next = nullptr;
        head = newNode;
    }

    while (count < 10) {
        
        
        count++;
    }

}