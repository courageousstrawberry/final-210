#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>
#include <list>

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

struct Bracelet {
    string name;
    string color;
};

struct Outfit {
    string name;
    string item;
};

const string names[] = {"Alicia", "Frank", "John", "Emma", "Sophia", "Liam", "Olivia", "Noah", "Ava", "James"};
const string drinks[] = {"Cappuccino", "Mocha", "Americano", "Latte", "Espresso", "Macchiato", "Flat", "Affogato", "Cortado", "Irish"};
const string muffins[] = {"Blueberry", "Chocolate", "Banana", "Bran", "Corn", "Pumpkin", "Apple", "Cranberry", "Lemon", "Poppyseed"};
const string colors[] = {"Red", "Blue", "Green", "Yellow", "Purple", "Orange", "Pink", "Brown", "Black", "White"};
const string clothing[] = {"T-shirt", "Jeans", "Jacket", "Sweater", "Dress", "Skirt", "Shorts", "Blouse", "Coat", "Scarf"};

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
    vector<Bracelet> friendship;
    list<Outfit> clothingQue;

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

        //Friendship Bracelet Vendor
        randName = rand() % 10;
        int randColor = rand() % 10;
        Bracelet addBracelet;
        addBracelet.name = names[randName];
        addBracelet.color = colors[randColor];
        friendship.push_back(addBracelet);

        // Clothing Vendor
        randName = rand() % 10;
        int randCloth = rand() % 10;
        Outfit addOutfit;
        addOutfit.name = names[randName];
        addOutfit.item = clothing[randCloth];
        clothingQue.push_back(addOutfit);
    }

    while (count < 10) {
        // Display all four Queues
        cout << "[" << count+1 << "]" << endl;
        cout << "Coffee Vendor Queue: " << endl;
        display(head);

        cout << "Muffin Vendor Queue: " << endl;
        for (const auto& it : muffinQue) {
            cout << "- " << it.name << ", " << it.muffin << endl;
        }
        
        cout << "Friendship Bracelet Queue: " << endl;
        for (const Bracelet bracelet : friendship) {
            cout << "- " << bracelet.name << ", " << bracelet.color << endl;
        }
        cout << "--------------" << endl;

        cout << "Clothing Vendor Queue: " << endl;
        for (Outfit value : clothingQue) {
            cout << "- " << value.name << ", " << value.item << endl;
        }

        // Random probability number
        int coffee_prob = rand() % 100;
        int muffin_prob = rand() % 100;
        int bracelet_prob = rand() % 100;
        int clothing_prob = rand() % 100;

        // If 50% add person to queue
        if (coffee_prob < 50) {
            int randName = rand() % 10;
            int randDrink = rand() % 10;

            addNode(head, names[randName], drinks[randDrink]);
        }

        if (muffin_prob < 50) {
            int randName = rand() % 10;
            int randMuffin = rand() % 10;
            MuffinCust addCust;
            addCust.name = names[randName];
            addCust.muffin = muffins[randMuffin];
            muffinQue.push_back(addCust);
        }

        if (bracelet_prob < 50) {
            int randName = rand() % 10;
            int randColor = rand() % 10;
            Bracelet addBracelet;
            addBracelet.name = names[randName];
            addBracelet.color = colors[randColor];
            friendship.push_back(addBracelet);
        }

        if (clothing_prob < 50) {
            int randName = rand() % 10;
            int randCloth = rand() % 10;
            Outfit addOutfit;
            addOutfit.name = names[randName];
            addOutfit.item = clothing[randCloth];
            clothingQue.push_back(addOutfit);
        }
        
        // Delete first in line for all the queues
        if (!muffinQue.empty()) {
            muffinQue.pop_front();
        }

        if (!friendship.empty()) {
            for (int i = 0; i < (friendship.size()-1); i++){
                friendship[i] = friendship[i+1];
            }
        }

        if (!clothingQue.empty()) {
            clothingQue.pop_front();
        }
        deleteFrontNode(head);
        
        count++;
    }
    return 0;
}