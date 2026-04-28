#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

using namespace std;

// ==================== ABSTRACTION & BASE CLASSES ====================

// Abstract Base Class for Food Items
class FoodItem {
protected:
    string itemName;
    float price;
    int itemID;
    
public:
    FoodItem(int id, string name, float p) : itemID(id), itemName(name), price(p) {}
    
    virtual ~FoodItem() {}
    
    // Pure virtual function (Abstraction)
    virtual void displayDetails() const = 0;
    
    virtual float getPrice() const {
        return price;
    }
    
    virtual string getItemName() const {
        return itemName;
    }
    
    virtual int getItemID() const {
        return itemID;
    }
    
    virtual string getItemType() const = 0;
};

// ==================== INHERITANCE & POLYMORPHISM ====================

// Derived Class: Vegetarian Items
class VegItem : public FoodItem {
public:
    VegItem(int id, string name, float p) : FoodItem(id, name, p) {}
    
    // Implementation of pure virtual function (Polymorphism)
    void displayDetails() const override {
        cout << "[VEG] ID: " << itemID << " | " << itemName 
             << " | ₹" << fixed << setprecision(2) << price << endl;
    }
    
    string getItemType() const override {
        return "VEG";
    }
};

// Derived Class: Non-Vegetarian Items
class NonVegItem : public FoodItem {
public:
    NonVegItem(int id, string name, float p) : FoodItem(id, name, p) {}
    
    // Implementation of pure virtual function (Polymorphism)
    void displayDetails() const override {
        cout << "[NON-VEG] ID: " << itemID << " | " << itemName 
             << " | ₹" << fixed << setprecision(2) << price << endl;
    }
    
    string getItemType() const override {
        return "NON-VEG";
    }
};

// ==================== USER CLASSES ====================

// Abstract Base Class for Users
class User {
protected:
    string userName;
    string userType;
    
public:
    User(string name, string type) : userName(name), userType(type) {}
    
    virtual ~User() {}
    
    // Pure virtual function (Abstraction)
    virtual float getDeliveryCharge() const = 0;
    virtual float getDiscountRate() const = 0;
    
    virtual string getUserType() const {
        return userType;
    }
    
    virtual string getUserName() const {
        return userName;
    }
};

// Derived Class: Regular User
class RegularUser : public User {
public:
    RegularUser(string name) : User(name, "REGULAR") {}
    
    float getDeliveryCharge() const override {
        return 40.0f;  // ₹40 delivery charge
    }
    
    float getDiscountRate() const override {
        return 0.0f;   // No extra discount
    }
};

// Derived Class: Premium User
class PremiumUser : public User {
public:
    PremiumUser(string name) : User(name, "PREMIUM") {}
    
    float getDeliveryCharge() const override {
        return 0.0f;   // Free delivery
    }
    
    float getDiscountRate() const override {
        return 0.05f;  // Extra 5% discount
    }
};

// ==================== RESTAURANT CLASS ====================

class Restaurant {
private:
    string restaurantName;
    int restaurantID;
    vector<FoodItem*> menu;
    
public:
    Restaurant(int id, string name) : restaurantID(id), restaurantName(name) {}
    
    ~Restaurant() {
        // Cleanup dynamically allocated memory
        for (auto item : menu) {
            delete item;
        }
    }
    
    void addMenuItem(FoodItem* item) {
        menu.push_back(item);
    }
    
    void displayMenu() const {
        cout << "\n" << string(50, "=") << endl;
        cout << "RESTAURANT: " << restaurantName << endl;
        cout << string(50, "=") << "\n";
        
        for (const auto& item : menu) {
            item->displayDetails();
        }
    }
    
    FoodItem* getMenuItem(int itemID) const {
        for (auto item : menu) {
            if (item->getItemID() == itemID) {
                return item;
            }
        }
        return nullptr;
    }
    
    string getRestaurantName() const {
        return restaurantName;
    }
    
    int getMenuSize() const {
        return menu.size();
    }
};

// ==================== ORDER CLASS ====================

class Order {
private:
    struct OrderItem {
        FoodItem* item;
        int quantity;
    };
    
    vector<OrderItem> orderedItems;
    User* user;
    string couponCode;
    
public:
    Order(User* u) : user(u), couponCode("") {}
    
    ~Order() {
        // User pointer is managed elsewhere
    }
    
    void addItem(FoodItem* item, int quantity) {
        // Check if item already exists
        for (auto& oItem : orderedItems) {
            if (oItem.item->getItemID() == item->getItemID()) {
                oItem.quantity += quantity;
                return;
            }
        }
        
        // Add new item
        orderedItems.push_back({item, quantity});
    }
    
    void applyCoupon(string code) {
        couponCode = code;
    }
    
    float calculateSubtotal() const {
        float subtotal = 0.0f;
        for (const auto& oItem : orderedItems) {
            subtotal += oItem.item->getPrice() * oItem.quantity;
        }
        return subtotal;
    }
    
    float calculateDiscount(float subtotal) const {
        float discountPercent = 0.0f;
        
        // Coupon discount
        if (couponCode == "SAVE10") {
            discountPercent = 0.10f;
        } else if (couponCode == "SAVE20") {
            discountPercent = 0.20f;
        }
        
        // Add premium user discount
        discountPercent += user->getDiscountRate();
        
        return subtotal * discountPercent;
    }
    
    void displayBill() {
        if (orderedItems.empty()) {
            cout << "\nNo items in order!" << endl;
            return;
        }
        
        float subtotal = calculateSubtotal();
        float gstAmount = subtotal * 0.05f;  // 5% GST
        float deliveryCharge = user->getDeliveryCharge();
        float discount = calculateDiscount(subtotal);
        float finalAmount = subtotal + gstAmount + deliveryCharge - discount;
        
        // Display Bill
        cout << "\n" << string(60, "=") << endl;
        cout << setw(30) << left << "FOOD DELIVERY SYSTEM BILL" << setw(30) << right << "" << endl;
        cout << string(60, "=") << endl;
        
        cout << "\nUser: " << user->getUserName() << endl;
        cout << "User Type: " << user->getUserType() << endl;
        
        cout << "\n" << string(60, "-") << endl;
        cout << "ORDER DETAILS:" << endl;
        cout << string(60, "-") << endl;
        
        cout << left << setw(30) << "Item Name" 
             << setw(12) << "Qty" 
             << setw(12) << "Price" 
             << setw(12) << "Total" << endl;
        cout << string(60, "-") << endl;
        
        for (const auto& oItem : orderedItems) {
            float itemTotal = oItem.item->getPrice() * oItem.quantity;
            cout << left << setw(30) << oItem.item->getItemName()
                 << setw(12) << oItem.quantity
                 << setw(12) << "₹" + to_string((int)oItem.item->getPrice())
                 << setw(12) << "₹" + to_string((int)itemTotal) << endl;
        }
        
        cout << string(60, "-") << endl;
        cout << right << setw(40) << "Subtotal: " 
             << "₹" << fixed << setprecision(2) << subtotal << endl;
        cout << right << setw(40) << "GST (5%): " 
             << "₹" << gstAmount << endl;
        cout << right << setw(40) << "Delivery Charge: " 
             << "₹" << deliveryCharge << endl;
        
        if (discount > 0) {
            cout << right << setw(40) << "Discount: " 
                 << "₹" << discount << endl;
        }
        
        cout << string(60, "=") << endl;
        cout << right << setw(40) << "FINAL AMOUNT: " 
             << "₹" << finalAmount << endl;
        cout << string(60, "=") << endl << endl;
    }
    
    bool hasItems() const {
        return !orderedItems.empty();
    }
};

// ==================== UTILITY FUNCTIONS ====================

string toUpperCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

void displayWelcome() {
    cout << "\n" << string(60, "*") << endl;
    cout << setw(30) << left << "" << "WELCOME TO FOOD DELIVERY SYSTEM" << endl;
    cout << string(60, "*") << endl << endl;
}

void displayUserTypeMenu() {
    cout << "Select User Type:" << endl;
    cout << "1. Regular User (Delivery: ₹40)" << endl;
    cout << "2. Premium User (Free Delivery + 5% Extra Discount)" << endl;
    cout << "Enter choice (1/2): ";
}

void displayRestaurantMenu(vector<Restaurant*>& restaurants) {
    cout << "\n" << string(50, "=") << endl;
    cout << "SELECT A RESTAURANT:" << endl;
    cout << string(50, "=") << endl;
    
    for (size_t i = 0; i < restaurants.size(); i++) {
        cout << i + 1 << ". " << restaurants[i]->getRestaurantName() << endl;
    }
    cout << "Enter choice: ";
}

// ==================== MAIN PROGRAM ====================

int main() {
    vector<Restaurant*> restaurants;
    
    // Initialize restaurants and menus
    // Restaurant 1: Pizza Palace
    Restaurant* pizzaPalace = new Restaurant(1, "Pizza Palace");
    pizzaPalace->addMenuItem(new VegItem(101, "Margherita Pizza", 250.0f));
    pizzaPalace->addMenuItem(new VegItem(102, "Paneer Tikka Pizza", 300.0f));
    pizzaPalace->addMenuItem(new NonVegItem(103, "Chicken Pepperoni", 350.0f));
    pizzaPalace->addMenuItem(new NonVegItem(104, "Tandoori Chicken", 320.0f));
    restaurants.push_back(pizzaPalace);
    
    // Restaurant 2: Biryani House
    Restaurant* biryaniHouse = new Restaurant(2, "Biryani House");
    biryaniHouse->addMenuItem(new VegItem(201, "Veg Biryani", 200.0f));
    biryaniHouse->addMenuItem(new VegItem(202, "Paneer Fried Rice", 180.0f));
    biryaniHouse->addMenuItem(new NonVegItem(203, "Chicken Biryani", 280.0f));
    biryaniHouse->addMenuItem(new NonVegItem(204, "Mutton Biryani", 350.0f));
    restaurants.push_back(biryaniHouse);
    
    // Restaurant 3: Burger Bliss
    Restaurant* burgerBliss = new Restaurant(3, "Burger Bliss");
    burgerBliss->addMenuItem(new VegItem(301, "Veggie Burger", 120.0f));
    burgerBliss->addMenuItem(new VegItem(302, "Cheese Burger (Veg)", 140.0f));
    burgerBliss->addMenuItem(new NonVegItem(303, "Chicken Burger", 160.0f));
    burgerBliss->addMenuItem(new NonVegItem(304, "Beef Burger", 200.0f));
    restaurants.push_back(burgerBliss);
    
    displayWelcome();
    
    // Step 1: Get User Type
    int userChoice;
    displayUserTypeMenu();
    cin >> userChoice;
    
    if (userChoice != 1 && userChoice != 2) {
        cout << "Invalid choice! Exiting..." << endl;
        return 0;
    }
    
    string userName;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, userName);
    
    User* currentUser = nullptr;
    if (userChoice == 1) {
        currentUser = new RegularUser(userName);
    } else {
        currentUser = new PremiumUser(userName);
    }
    
    // Step 2: Select Restaurant
    displayRestaurantMenu(restaurants);
    int restaurantChoice;
    cin >> restaurantChoice;
    
    if (restaurantChoice < 1 || restaurantChoice > (int)restaurants.size()) {
        cout << "Invalid restaurant choice!" << endl;
        delete currentUser;
        for (auto r : restaurants) delete r;
        return 0;
    }
    
    Restaurant* selectedRestaurant = restaurants[restaurantChoice - 1];
    
    // Step 3: Display Menu
    selectedRestaurant->displayMenu();
    
    // Step 4: Place Order
    Order order(currentUser);
    
    while (true) {
        cout << "\nEnter item ID to add to cart (0 to finish ordering): ";
        int itemID;
        cin >> itemID;
        
        if (itemID == 0) break;
        
        FoodItem* selectedItem = selectedRestaurant->getMenuItem(itemID);
        
        if (selectedItem == nullptr) {
            cout << "Item not found! Try again." << endl;
            continue;
        }
        
        cout << "Enter quantity: ";
        int quantity;
        cin >> quantity;
        
        if (quantity <= 0) {
            cout << "Invalid quantity!" << endl;
            continue;
        }
        
        order.addItem(selectedItem, quantity);
        cout << "✓ " << selectedItem->getItemName() << " x" << quantity << " added to cart!" << endl;
    }
    
    if (!order.hasItems()) {
        cout << "\nNo items ordered. Exiting..." << endl;
        delete currentUser;
        for (auto r : restaurants) delete r;
        return 0;
    }
    
    // Step 5: Apply Coupon Code
    cout << "\n" << string(50, "-") << endl;
    cout << "Available Coupons: SAVE10 (10% off), SAVE20 (20% off)" << endl;
    cout << "Enter coupon code (or press Enter to skip): ";
    cin.ignore();
    string coupon;
    getline(cin, coupon);
    
    coupon = toUpperCase(coupon);
    if (!coupon.empty()) {
        if (coupon == "SAVE10" || coupon == "SAVE20") {
            order.applyCoupon(coupon);
            cout << "✓ Coupon '" << coupon << "' applied!" << endl;
        } else {
            cout << "Invalid coupon code!" << endl;
        }
    }
    
    // Step 6: Generate Bill
    order.displayBill();
    
    // Cleanup
    delete currentUser;
    for (auto restaurant : restaurants) {
        delete restaurant;
    }
    
    cout << "Thank you for using Food Delivery System!" << endl;
    
    return 0;
}
