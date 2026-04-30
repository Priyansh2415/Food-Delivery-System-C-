# 🍔 Food Delivery System (C++ OOP Project)

## 📌 Overview

This is a **console-based Food Delivery System** implemented in C++ using Object-Oriented Programming (OOP) concepts.
The project simulates real-world food delivery apps by allowing users to select restaurants, order food, and generate bills with taxes and discounts.

---

## 🚀 Features

* 🍽️ Multiple restaurants with different menus
* 🧾 Order multiple food items
* 💰 Automatic bill generation
* 🧮 GST calculation (5%)
* 🚚 Delivery charges (₹40 for Regular users, Free for Premium users)
* 🎟️ Discount coupons:

  * `SAVE10` → 10% discount
  * `SAVE20` → 20% discount
* ⭐ Extra 5% discount for Premium users
* 🔁 Menu-driven interface

---

## 🧱 OOP Concepts Used

### ✅ Encapsulation

* Data (like price, total, items) is wrapped inside classes

### ✅ Inheritance

* `FoodItem` → `VegItem`, `NonVegItem`
* `User` → `RegularUser`, `PremiumUser`

### ✅ Polymorphism

* Virtual functions like `getDeliveryCharge()` behave differently
  for Regular and Premium users

### ✅ Abstraction

* User interacts with a simple menu, while complex logic is hidden

---

## 🏗️ Class Structure

```
FoodItem
 ├── VegItem
 └── NonVegItem

User
 ├── RegularUser
 └── PremiumUser

Restaurant
Order
```

---

## 💻 Technologies Used

* C++
* STL (`vector`)
* OOP Principles

---

## ▶️ How to Run

1. Copy the code into a `.cpp` file
2. Compile using:

   ```
   g++ filename.cpp -o output
   ```
3. Run:

   ```
   ./output
   ```

---

## 🖥️ Sample Output

```
1. Regular User
2. Premium User
Choose: 2

Select Restaurant:
1. Pizza Palace
2. Burger Hub
3. Indian Tadka
4. Chinese Corner

Menu of Pizza Palace:
1. Margherita Pizza - Rs.200
2. Farmhouse Pizza - Rs.280

=========== BILL ===========
Margherita Pizza - Rs.200
----------------------------
Subtotal      : Rs.200
GST (5%)      : Rs.10
Delivery      : Rs.0
Discount      : -Rs.30
----------------------------
Total Payable : Rs.180
============================
```

---

## 🎯 Learning Outcomes

* Understand real-world application of OOP
* Practice inheritance and polymorphism
* Use STL for dynamic data handling
* Build modular and scalable systems

---

## 🔮 Future Improvements

* 💾 File handling (save order history)
* 🔐 Login system
* 🧑‍💼 Admin panel (add/remove restaurants)
* 🌐 GUI version (Qt / Web-based)

---

## 👨‍💻 Author

**Priyansh Shah**

---

## ⭐ Note

This project is designed for **college mini-project demonstration** and viva.
