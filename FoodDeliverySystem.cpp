#include <iostream>
#include <vector>
using namespace std;

// ---------- FoodItem Base Class ----------
class FoodItem {
public:
    string name;
    float price;

    FoodItem(string n, float p) {
        name = n;
        price = p;
    }

    virtual void display() {
        cout << name << " - Rs." << price << endl;
    }
};

// ---------- Derived Classes ----------
class VegItem : public FoodItem {
public:
    VegItem(string n, float p) : FoodItem(n, p) {}
};

class NonVegItem : public FoodItem {
public:
    NonVegItem(string n, float p) : FoodItem(n, p) {}
};

// ---------- User Base Class ----------
class User {
public:
    string name;

    User(string n) {
        name = n;
    }

    virtual float getDeliveryCharge() {
        return 40;
    }

    virtual float getExtraDiscount(float total) {
        return 0;
    }
};

// ---------- Derived Users ----------
class PremiumUser : public User {
public:
    PremiumUser(string n) : User(n) {}

    float getDeliveryCharge() override {
        return 0; // Free delivery
    }

    float getExtraDiscount(float total) override {
        return total * 0.05; // Extra 5%
    }
};

class RegularUser : public User {
public:
    RegularUser(string n) : User(n) {}
};

// ---------- Restaurant ----------
class Restaurant {
public:
    string name;
    vector<FoodItem*> menu;

    Restaurant(string n) {
        name = n;
    }

    void addItem(FoodItem* item) {
        menu.push_back(item);
    }

    void showMenu() {
        cout << "\nMenu of " << name << ":\n";
        for (int i = 0; i < menu.size(); i++) {
            cout << i + 1 << ". ";
            menu[i]->display();
        }
    }
};

// ---------- Order ----------
class Order {
public:
    vector<FoodItem*> items;
    float total = 0;

    void addItem(FoodItem* item) {
        items.push_back(item);
        total += item->price;
    }

    void generateBill(User* user, string coupon) {
        float gst = total * 0.05;
        float discount = 0;

        // Coupon logic
        if (coupon == "SAVE10") discount = total * 0.10;
        else if (coupon == "SAVE20") discount = total * 0.20;

        // Premium user extra discount
        discount += user->getExtraDiscount(total);

        float delivery = user->getDeliveryCharge();

        float finalAmount = total + gst + delivery - discount;

        cout << "\n=========== BILL ===========\n";
        for (auto item : items) {
            cout << item->name << " - Rs." << item->price << endl;
        }

        cout << "----------------------------\n";
        cout << "Subtotal      : Rs." << total << endl;
        cout << "GST (5%)      : Rs." << gst << endl;
        cout << "Delivery      : Rs." << delivery << endl;
        cout << "Discount      : -Rs." << discount << endl;
        cout << "----------------------------\n";
        cout << "Total Payable : Rs." << finalAmount << endl;
        cout << "============================\n";
    }
};

// ---------- Main ----------
int main() {

    // ---------- Create Restaurants ----------
    Restaurant r1("Pizza Palace");
    r1.addItem(new VegItem("Margherita Pizza", 200));
    r1.addItem(new VegItem("Farmhouse Pizza", 280));
    r1.addItem(new NonVegItem("Chicken Dominator", 350));

    Restaurant r2("Burger Hub");
    r2.addItem(new VegItem("Veg Burger", 120));
    r2.addItem(new VegItem("Cheese Burger", 150));
    r2.addItem(new NonVegItem("Chicken Burger", 180));

    Restaurant r3("Indian Tadka");
    r3.addItem(new VegItem("Paneer Butter Masala", 220));
    r3.addItem(new VegItem("Dal Fry", 140));
    r3.addItem(new NonVegItem("Butter Chicken", 300));

    Restaurant r4("Chinese Corner");
    r4.addItem(new VegItem("Veg Noodles", 160));
    r4.addItem(new VegItem("Manchurian", 180));
    r4.addItem(new NonVegItem("Chicken Fried Rice", 220));

    vector<Restaurant> restaurants = {r1, r2, r3, r4};

    // ---------- Select User ----------
    int userType;
    cout << "1. Regular User\n2. Premium User\nChoose: ";
    cin >> userType;

    User* user;
    if (userType == 2)
        user = new PremiumUser("Priyansh");
    else
        user = new RegularUser("Priyansh");

    // ---------- Select Restaurant ----------
    int rChoice;
    cout << "\nSelect Restaurant:\n";
    for (int i = 0; i < restaurants.size(); i++) {
        cout << i + 1 << ". " << restaurants[i].name << endl;
    }

    cin >> rChoice;
    Restaurant* selected = &restaurants[rChoice - 1];

    // ---------- Order ----------
    Order order;
    int choice;

    do {
        selected->showMenu();
        cout << "Select item (0 to finish): ";
        cin >> choice;

        if (choice > 0 && choice <= selected->menu.size()) {
            order.addItem(selected->menu[choice - 1]);
            cout << "Item added!\n";
        }

    } while (choice != 0);

    // ---------- Coupon ----------
    string coupon;
    cout << "Enter coupon (SAVE10 / SAVE20 / NONE): ";
    cin >> coupon;

    // ---------- Bill ----------
    order.generateBill(user, coupon);

    return 0;
}