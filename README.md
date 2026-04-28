# README - Food Delivery System C++ Project

## 🍔 Project Overview

A **comprehensive C++ mini-project** implementing a **Food Delivery System** with complete Object-Oriented Programming (OOP) concepts. This project demonstrates real-world application design patterns suitable for college-level computer science assignments.

### 📌 **What This Project Teaches:**
- Object-Oriented Programming (Classes, Inheritance, Polymorphism, Encapsulation, Abstraction)
- Dynamic Memory Management
- STL Containers (vector)
- Virtual Functions and Method Overriding
- Real-world System Design

---

## 🎯 **Key Features**

### ✨ **Core Functionality:**
- 👥 **User Types**: Regular & Premium users with different benefits
- 🏪 **Multiple Restaurants**: 3 pre-configured restaurants with diverse menus
- 🍽️ **Menu Items**: Vegetarian & Non-Vegetarian items with pricing
- 🛒 **Order Management**: Select items, set quantities, add to cart
- 🏷️ **Discount Coupons**: SAVE10 (10% off) and SAVE20 (20% off)
- 💰 **Automatic Billing**: Calculates subtotal, GST, delivery charges, discounts
- 📄 **Formatted Invoice**: Professional bill generation with detailed breakdown

### 💎 **Premium User Benefits:**
- ✅ Free Delivery (saves ₹40)
- ✅ Extra 5% Discount on all orders
- ✅ Coupon discounts stack with premium discount

---

## 🏗️ **OOP Concepts Implemented**

### 1. **Classes & Objects** ✅
```cpp
FoodItem, VegItem, NonVegItem, User, RegularUser, PremiumUser, 
Restaurant, Order
```

### 2. **Encapsulation** ✅
```cpp
Private data members with public accessor methods
(getPrice, getItemName, getUserType, etc.)
```

### 3. **Inheritance** ✅
```cpp
FoodItem ← VegItem, NonVegItem
User ← RegularUser, PremiumUser
```

### 4. **Polymorphism** ✅
```cpp
Virtual functions: displayDetails(), getDeliveryCharge(), getDiscountRate()
Runtime method selection based on object type
```

### 5. **Abstraction** ✅
```cpp
Pure virtual functions define interfaces
Cannot instantiate base classes directly
```

---

## 📂 **Project Files**

```
Food-Delivery-System-C-/
├── FoodDeliverySystem.cpp          # Main program (500+ lines)
├── DOCUMENTATION.md                 # Project documentation & architecture
├── OOP_CONCEPTS_EXPLAINED.md        # Detailed OOP concept explanations
├── COMPILATION_GUIDE.md             # Setup & compilation instructions
└── README.md                        # This file
```

---

## 🚀 **Quick Start**

### **Compile (Linux/macOS/Windows):**
```bash
g++ -std=c++17 -o FoodDeliverySystem FoodDeliverySystem.cpp
```

### **Run:**
```bash
./FoodDeliverySystem  # Linux/macOS
FoodDeliverySystem.exe # Windows
```

### **Complete Example:**
```bash
$ g++ -std=c++17 -o FoodDeliverySystem FoodDeliverySystem.cpp
$ ./FoodDeliverySystem
Welcome to Food Delivery System!
(Follow menu-driven prompts to place order)
```

---

## 💰 **Billing Example**

### **Scenario:**
- User: John (Regular User)
- Restaurant: Pizza Palace
- Order: Margherita Pizza (₹250 × 1) + Chicken Pepperoni (₹350 × 2)
- Coupon: SAVE10

### **Bill Calculation:**
```
Subtotal:           ₹810.00
GST (5%):          +₹40.50
Delivery Charge:   +₹40.00
Discount (10%):    -₹81.00
─────────────────────────
FINAL AMOUNT:      ₹809.50
```

---

## 🎯 **System Workflow**

```
1. Welcome Screen
          ↓
2. Select User Type (Regular/Premium)
          ↓
3. Enter Name
          ↓
4. Choose Restaurant
          ↓
5. Browse Menu
          ↓
6. Add Items to Order
          ↓
7. Apply Coupon (Optional)
          ↓
8. Generate & Display Bill
          ↓
9. Exit Program
```

---

## 🍽️ **Included Restaurants**

### **1. Pizza Palace**
- Margherita Pizza (VEG) - ₹250
- Paneer Tikka Pizza (VEG) - ₹300
- Chicken Pepperoni (NON-VEG) - ₹350
- Tandoori Chicken (NON-VEG) - ₹320

### **2. Biryani House**
- Veg Biryani (VEG) - ₹200
- Paneer Fried Rice (VEG) - ₹180
- Chicken Biryani (NON-VEG) - ₹280
- Mutton Biryani (NON-VEG) - ₹350

### **3. Burger Bliss**
- Veggie Burger (VEG) - ₹120
- Cheese Burger (VEG) - ₹140
- Chicken Burger (NON-VEG) - ₹160
- Beef Burger (NON-VEG) - ₹200

---

## 🏪 **User Types & Benefits**

| Feature | Regular User | Premium User |
|---------|---|---|
| Delivery Charge | ₹40 | FREE |
| Extra Discount | None | 5% |
| Coupon Support | ✅ | ✅ |
| Coupon + Premium Stacking | N/A | ✅ |

### **Premium Discount Calculation:**
```
If using SAVE10:
  Discount = Subtotal × (10% + 5%) = Subtotal × 15%

If using SAVE20:
  Discount = Subtotal × (20% + 5%) = Subtotal × 25%

Without coupon:
  Discount = Subtotal × 5%
```

---

## 💡 **Code Highlights**

### **Abstract Base Class:**
```cpp
class FoodItem {
protected:
    string itemName;
    float price;
    
public:
    virtual void displayDetails() const = 0;  // Pure virtual
    virtual string getItemType() const = 0;
};
```

### **Polymorphic Behavior:**
```cpp
class VegItem : public FoodItem {
public:
    void displayDetails() const override {
        cout << "[VEG] " << itemName << " | ₹" << price << endl;
    }
};
```

### **Memory Management:**
```cpp
// Safe cleanup in destructors
~Restaurant() {
    for (auto item : menu) {
        delete item;
    }
}
```

---

## 📋 **Requirements Met**

- ✅ Multiple restaurants with different menus
- ✅ Users can select restaurant and order multiple items
- ✅ Bill generation system with all calculations
- ✅ **OOP Concepts**: Classes, Encapsulation, Inheritance, Polymorphism, Abstraction
- ✅ **Class Design**: Base + derived classes as specified
- ✅ **Advanced Features**: GST, delivery charges, discount coupons
- ✅ **Complete Program Flow**: User selection → Menu → Order → Bill
- ✅ **Formatted Output**: Professional invoice layout
- ✅ **STL Usage**: Vectors for storing menus and orders
- ✅ **Dynamic Binding**: Virtual functions with proper overrides
- ✅ **Clean Code**: Modular, well-structured, commented

---

## 🛠️ **Technical Stack**

- **Language**: C++ (C++17 standard)
- **Compiler**: G++, Clang, MSVC, or any C++17-compatible compiler
- **Libraries**: Standard Library only (iostream, vector, string, iomanip, algorithm, cctype)
- **Memory Model**: Dynamic allocation with cleanup
- **Design Patterns**: Inheritance, Polymorphism, Encapsulation

---

## 📖 **Documentation Files**

1. **DOCUMENTATION.md** - Comprehensive system architecture and design
2. **OOP_CONCEPTS_EXPLAINED.md** - Detailed explanations of each OOP concept with examples
3. **COMPILATION_GUIDE.md** - Step-by-step setup instructions for all platforms
4. **README.md** - This file (project overview)

---

## 🎓 **Educational Benefits**

This project is ideal for:
- 🎯 **College Mini-Projects**: Demonstrates all required OOP concepts
- 📚 **Learning OOP**: Real-world example of abstract concepts
- 💼 **Portfolio**: Shows professional code organization and design
- 🧠 **Interview Prep**: Displays system design thinking
- 🚀 **Extension Practice**: Base for adding advanced features

---

## 🌟 **Potential Enhancements**

### Level 1 (Easy):
- Add more restaurants and menu items
- Implement order history
- Add ratings/reviews system

### Level 2 (Medium):
- File I/O for persistent storage
- Admin panel for restaurant management
- Customer loyalty points

### Level 3 (Advanced):
- Database integration (SQLite, MySQL)
- Multi-threading for concurrent orders
- GUI implementation (Qt, SFML)
- REST API for mobile app integration
- Payment gateway integration

---

## 🔍 **Code Quality**

✅ **Well-commented** - Explains OOP concepts and logic  
✅ **Modular Design** - Separate concerns in different classes  
✅ **Error Handling** - Input validation and edge cases  
✅ **Memory Safe** - Proper allocation and cleanup  
✅ **Readable** - Clear variable names and formatting  
✅ **Maintainable** - Easy to understand and modify  

---

## 📊 **Sample Output**

```
============================================================
                   FOOD DELIVERY SYSTEM BILL
============================================================

User: Alice
User Type: PREMIUM

------------------------------------------------------------
ORDER DETAILS:
------------------------------------------------------------
Item Name                     Qty    Price        Total
------------------------------------------------------------
Chicken Biryani               2      ₹280         ₹560
Veg Biryani                   1      ₹200         ₹200
------------------------------------------------------------
                                    Subtotal: ₹760.00
                                   GST (5%): ₹38.00
                            Delivery Charge: ₹0.00
                                   Discount: ₹152.00
============================================================
                                FINAL AMOUNT: ₹646.00
============================================================
```

---

## 🎮 **Usage Tips**

1. **Try Different Combinations:**
   - Regular user + coupon
   - Premium user with/without coupon
   - Multiple items with various quantities

2. **Verify Calculations:**
   - Cross-check GST (5%)
   - Verify delivery charges
   - Check discount application

3. **Test Edge Cases:**
   - Invalid inputs
   - Empty orders
   - Invalid coupon codes

4. **Explore Code:**
   - Understand inheritance hierarchy
   - Study polymorphic behavior
   - Review memory management

---

## 🐛 **Troubleshooting**

### Compilation Issues:
```bash
# If compiler not found:
sudo apt-get install g++        # Linux

# If C++ standard not supported:
g++ -std=c++11 FoodDeliverySystem.cpp -o program

# Full verbose compilation:
g++ -std=c++17 -Wall -Wextra FoodDeliverySystem.cpp -o program
```

### Runtime Issues:
- **Program crashes**: Check input during order selection
- **Calculation errors**: Verify coupon codes (case-sensitive: SAVE10, SAVE20)
- **Input problems**: Make sure to enter numeric choices when prompted

---

## 📝 **License & Usage**

This project is provided for **educational purposes**. Feel free to:
- Use it for college assignments
- Modify and extend it
- Learn from the code
- Share with other students (with attribution)

---

## 🎉 **Conclusion**

This **Food Delivery System** project successfully demonstrates:
1. ✅ All 5 OOP principles (Classes, Encapsulation, Inheritance, Polymorphism, Abstraction)
2. ✅ Professional C++ coding practices
3. ✅ Real-world system modeling
4. ✅ Practical software design patterns
5. ✅ Complete project documentation

Perfect for a college mini-project or learning resource! 🚀

---

## 📞 **Getting Help**

1. **Read Documentation Files:**
   - DOCUMENTATION.md (Architecture & Design)
   - OOP_CONCEPTS_EXPLAINED.md (Learning Guide)
   - COMPILATION_GUIDE.md (Setup Help)

2. **Study the Code:**
   - Comments explain OOP concepts
   - Clear class structure
   - Logical flow

3. **Experiment:**
   - Modify menu items
   - Add new restaurants
   - Extend discount logic

---

## 🙌 **Credits**

Created as a comprehensive demonstration of Object-Oriented Programming concepts in C++.

Suitable for:
- 🎓 Academic Projects
- 📚 Learning Resources
- 💼 Portfolio Building
- 🧠 Interview Preparation

**Happy Learning & Coding!** 🚀
