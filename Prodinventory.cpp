#include<iostream>
#include<unordered_map>
#include<algorithm> 

using namespace std;

// Product class
class Product {
private:
    string name;
    int quantity;
    double price;

public:
    // Constructor
    Product(string n, int q, double p) : name(n), quantity(q), price(p) {}

    // Getters
    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }

    // Setters
    void setName(string n) { name = n; }
    void setQuantity(int q) { quantity = q; }
    void setPrice(double p) { price = p; }

    // Function to display product details
    void display() const {
        cout << "Name: " << name << "\tQuantity: " << quantity << "\tPrice: $" << price << endl;
    }
};

// Inventory Manager class
class InventoryManager {
private:
    unordered_map<string, Product> products;

public:
    // Add a new product to the inventory
    void addProduct(const string &name, int quantity, double price) {
        products.emplace(name, Product(name, quantity, price));
        cout << "Product added successfully." << endl;
    }

    // Display all products in the inventory
    void displayProducts() const {
        cout << "Inventory:" << endl;
        for (const auto &kv : products) {
            kv.second.display();
        }
    }

    // Search for a product by name
    void searchProduct(const string &name) const {
        auto it = products.find(name);
        if (it != products.end()) {
            cout << "Product found:" << endl;
            it->second.display();
        } else {
            cout << "Product not found." << endl;
        }
    }

    // Update quantity of a product
    void updateProductQuantity(const string &name, int newQuantity) {
        auto it = products.find(name);
        if (it != products.end()) {
            it->second.setQuantity(newQuantity);
            cout << "Quantity updated successfully." << endl;
        } else {
            cout << "Product not found." << endl;
        }
    }

    // Update price of a product
    void updateProductPrice(const string &name, double newPrice) {
        auto it = products.find(name);
        if (it != products.end()) {
            it->second.setPrice(newPrice);
            cout << "Price updated successfully." << endl;
        } else {
            cout << "Product not found." << endl;
        }
    }

    // Delete a product from inventory
    void deleteProduct(const string &name) {
        auto it = products.find(name);
        if (it != products.end()) {
            products.erase(it);
            cout << "Product deleted successfully." << endl;
        } else {
            cout << "Product not found." << endl;
        }
    }
};

// Function to get user input and perform operations
void userInterface(InventoryManager &inventory) {
    int choice;
    string name;
    int quantity;
    double price;

    while (true) {
        cout << "\n===== Inventory Management System =====" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Products" << endl;
        cout << "3. Search Product" << endl;
        cout << "4. Update Product Quantity" << endl;
        cout << "5. Update Product Price" << endl;
        cout << "6. Delete Product" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter product details:" << endl;
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Quantity: ";
                cin >> quantity;
                cout << "Price: ";
                cin >> price;
                inventory.addProduct(name, quantity, price);
                break;

            case 2:
                inventory.displayProducts();
                break;

            case 3:
                cout << "\nEnter product name to search: ";
                cin.ignore();
                getline(cin, name);
                inventory.searchProduct(name);
                break;

            case 4:
                cout << "\nEnter product name to update quantity: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new quantity: ";
                cin >> quantity;
                inventory.updateProductQuantity(name, quantity);
                break;

            case 5:
                cout << "\nEnter product name to update price: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter new price: ";
                cin >> price;
                inventory.updateProductPrice(name, price);
                break;

            case 6:
                cout << "\nEnter product name to delete: ";
                cin.ignore();
                getline(cin, name);
                inventory.deleteProduct(name);
                break;

            case 7:
                cout << "\nExiting program..." << endl;
                return;

            default:
                cout << "\nInvalid choice. Please enter a number between 1 and 7." << endl;
        }
    }
}

// Main function
int main() {
    InventoryManager inventory;

    // Adding some initial products
    inventory.addProduct("Laptop", 10, 999.99);
    inventory.addProduct("Mouse", 50, 19.99);
    inventory.addProduct("Keyboard", 30, 49.99);

    // User interface
    userInterface(inventory);

    return 0;
}
