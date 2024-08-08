Code Breakdown
-----------------------
Product Class:
------------------------------
Represents a product with attributes: name, quantity, and price.

Provides getters and setters for these attributes.
Includes a method display() to print the product details.

InventoryManager Class:
----------------------------
Manages a collection of Product objects using an unordered_map.
unordered_map<string, Product> products;: Stores products with their name as the key and a Product object as the value.

addProduct(const string &name, int quantity, double price): Adds a new product to the inventory.

displayProducts(): Displays all products in the inventory.

searchProduct(const string &name): Searches for a product by name and displays its details if found.

updateProductQuantity(const string &name, int newQuantity): Updates the quantity of a specified product.

updateProductPrice(const string &name, double newPrice): Updates the price of a specified product.

deleteProduct(const string &name): Removes a product from the inventory.

userInterface Function:
---------------------------------
Provides a menu-driven interface for the user to interact with the InventoryManager.

Supports operations like adding, displaying, searching, updating, and deleting products.

main Function:
------------------------
Initializes the InventoryManager.

Adds some initial products.

Calls userInterface() to allow the user to perform various operations.


