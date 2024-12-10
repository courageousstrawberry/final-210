#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>

using namespace std;

struct Node {
    string name;
    string drinkOrder;
    Node* next;
};

struct MuffinCust {
    string name;
    string muffin;
};

const string names[] = {"Alicia", "Frank", "John", "Emma", "Sophia", "Liam", "Olivia", "Noah", "Ava", "James"};
const string drinks[] = {"Cappuccino", "Mocha", "Americano", "Latte", "Espresso", "Macchiato", "Flat", "Affogato", "Cortado", "Irish"};
const string muffins[] = {"Blueberry", "Chocolate", "Banana", "Bran", "Corn", "Pumpkin", "Apple", "Cranberry", "Lemon", "Poppyseed"};

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
    deque<MuffinCust> muffinQue;
    srand(time(0));
    // Generate 3 Customers
    for (int i = 0; i < 3; i++){
        // Coffee Vendor
        int randName = rand() % 10;
        int randDrink = rand() % 10;

        addNode(head, names[randName], drinks[randDrink]);
        // Muffin Vendor
        randName = rand() % 10;
        int randMuffin = rand() % 10;
        MuffinCust addCust;
        addCust.name = names[randName];
        addCust.muffin = muffins[randMuffin];
        muffinQue.push_back(addCust);
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
        
        cout << "Coffee Vendor Queue: " << endl;
        deleteFrontNode(head);
        
        cout << "Muffin Vendor Queue: " << endl;
        for (const auto& it : muffinQue) {
            cout << "- " << it.name << it.muffin << endl;
        }
        count++;
        cout << "--------------" << endl;
    }

}