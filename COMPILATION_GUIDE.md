# COMPILATION GUIDE - Food Delivery System

Complete step-by-step instructions to compile and run the Food Delivery System project on any platform.

---

## 🖥️ **System Requirements**

### **Minimum Requirements**
- C++ Compiler (C++11 or higher)
- 2 MB disk space
- Terminal/Command Prompt
- Standard C++ Library

### **Supported Compilers**
- G++ (Linux/macOS/Windows)
- Clang (Linux/macOS)
- MSVC (Windows)
- MinGW (Windows)

### **Supported Operating Systems**
- ✅ Linux (Ubuntu, Fedora, Debian, etc.)
- ✅ macOS
- ✅ Windows 7/8/10/11
- ✅ WSL (Windows Subsystem for Linux)

---

## 📦 **Installation Guide by OS**

### **Linux (Ubuntu/Debian)**

#### **Step 1: Install G++ Compiler**
```bash
sudo apt-get update
sudo apt-get install g++
```

#### **Step 2: Verify Installation**
```bash
g++ --version
# Output: g++ (Ubuntu 9.3.0-10ubuntu2) 9.3.0
```

#### **Step 3: Navigate to Project Directory**
```bash
cd /path/to/Food-Delivery-System-C-
ls -la
# Should show: FoodDeliverySystem.cpp
```

---

### **macOS**

#### **Step 1: Install Xcode Command Line Tools**
```bash
xcode-select --install
```

#### **Step 2: Verify Installation**
```bash
g++ --version
clang --version
```

#### **Step 3: Navigate to Project**
```bash
cd /path/to/Food-Delivery-System-C-
```

---

### **Windows 10/11**

#### **Option A: Using MinGW**

**Step 1: Download MinGW**
- Visit: https://www.mingw-w64.org/
- Download installer

**Step 2: Install MinGW**
- Run installer
- Select: x86_64, POSIX, SEH
- Complete installation

**Step 3: Add to PATH**
- System Properties → Environment Variables
- Add: `C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\bin`
- Click OK

**Step 4: Verify**
```bash
g++ --version
```

#### **Option B: Using Windows Subsystem for Linux (WSL)**

**Step 1: Enable WSL**
```powershell
wsl --install
```

**Step 2: Install Linux Distribution**
- Ubuntu 20.04 LTS recommended
- Install from Microsoft Store

**Step 3: Open WSL Terminal**
```bash
wsl
sudo apt-get update
sudo apt-get install g++
```

---

## 🔨 **Compilation Steps**

### **Basic Compilation**

#### **Command 1: Simple Compilation**
```bash
g++ -o FoodDeliverySystem FoodDeliverySystem.cpp
```

**What it does:**
- Compiles `FoodDeliverySystem.cpp`
- Creates executable named `FoodDeliverySystem`
- `-o` specifies output filename

#### **Command 2: With C++17 Standard**
```bash
g++ -std=c++17 -o FoodDeliverySystem FoodDeliverySystem.cpp
```

**Recommended** because:
- Uses modern C++ features
- Better compatibility
- Newer compiler optimizations

#### **Command 3: Verbose Compilation (with Warnings)**
```bash
g++ -std=c++17 -Wall -Wextra -o FoodDeliverySystem FoodDeliverySystem.cpp
```

**Flags:**
- `-Wall` : All warnings
- `-Wextra` : Extra warnings (good practice)
- Helps catch potential issues

#### **Command 4: Optimized Compilation**
```bash
g++ -std=c++17 -O2 -o FoodDeliverySystem FoodDeliverySystem.cpp
```

**Benefits:**
- `-O2` : Code optimization level
- Faster execution
- Smaller executable

---

## ▶️ **Running the Program**

### **Linux/macOS**
```bash
./FoodDeliverySystem
```

### **Windows (Command Prompt)**
```bash
FoodDeliverySystem.exe
```

### **Windows (PowerShell)**
```powershell
.\FoodDeliverySystem.exe
```

### **Windows (WSL)**
```bash
./FoodDeliverySystem
```

---

## 🚀 **Complete Execution Example**

### **Linux/macOS**
```bash
$ cd ~/projects/Food-Delivery-System-C-
$ g++ -std=c++17 -o FoodDeliverySystem FoodDeliverySystem.cpp
$ ./FoodDeliverySystem

# Output:
# ************************************************************
#                   WELCOME TO FOOD DELIVERY SYSTEM
# ************************************************************
# 
# Select User Type:
# 1. Regular User (Delivery: ₹40)
# 2. Premium User (Free Delivery + 5% Extra Discount)
# Enter choice (1/2):
```

### **Windows (Command Prompt)**
```bash
> cd C:\Users\YourName\projects\Food-Delivery-System-C-
> g++ -std=c++17 -o FoodDeliverySystem FoodDeliverySystem.cpp
> FoodDeliverySystem.exe

# Output: (same as above)
```

---

## 💻 **IDE Setup**

### **Visual Studio Code**

#### **Step 1: Install Extensions**
1. Open VS Code
2. Click Extensions (Ctrl+Shift+X)
3. Search and install:
   - "C/C++" by Microsoft
   - "Code Runner" (optional)

#### **Step 2: Create Folder Structure**
```
project-folder/
├── FoodDeliverySystem.cpp
├── .vscode/
│   ├── launch.json
│   └── tasks.json
└── README.md
```

#### **Step 3: Setup tasks.json**
Create `.vscode/tasks.json`:
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "command": "g++",
            "args": [
                "-std=c++17",
                "-Wall",
                "-Wextra",
                "-o",
                "FoodDeliverySystem",
                "FoodDeliverySystem.cpp"
            ],
            "problemMatcher": ["$gcc"],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

#### **Step 4: Run in VS Code**
- Press `Ctrl+Shift+B` to compile
- Press `Ctrl+F5` to debug

---

### **Code::Blocks**

#### **Step 1: Create New Project**
1. File → New → Project
2. Select: Console application
3. Language: C++

#### **Step 2: Add Source File**
1. Project → Add files
2. Select: FoodDeliverySystem.cpp

#### **Step 3: Set Compiler**
1. Project → Build options
2. Compiler: GNU GCC
3. Select C++ standard: C++17

#### **Step 4: Build & Run**
- Ctrl+F9 to build
- Ctrl+F10 to run

---

### **Dev-C++**

#### **Step 1: Create New Project**
1. File → New → Project
2. Select: Console Application
3. Language: C++

#### **Step 2: Add Files**
1. Project → Add to Project
2. Select: FoodDeliverySystem.cpp

#### **Step 3: Compile**
1. Execute → Compile (Ctrl+F9)
2. Execute → Run (Ctrl+F10)

---

### **CLion (JetBrains)**

#### **Step 1: Open Project**
1. File → Open
2. Select project folder

#### **Step 2: Create CMakeLists.txt**
```cmake
cmake_minimum_required(VERSION 3.15)
project(FoodDeliverySystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(FoodDeliverySystem FoodDeliverySystem.cpp)
```

#### **Step 3: Run**
- Click Green Play button
- Or: Shift+F10

---

### **Visual Studio**

#### **Step 1: Create Project**
1. New Project
2. Select: C++ Console App
3. Name: FoodDeliverySystem

#### **Step 2: Add Source**
1. Replace default `main()` content
2. Paste: FoodDeliverySystem.cpp code

#### **Step 3: Build & Run**
- Build: Ctrl+Shift+B
- Run: Ctrl+F5 (with debugging)
- Run: Ctrl+Shift+B then F5 (without debugging)

---

## ✅ **Compilation Checklist**

Before compiling, verify:
- ✅ Compiler is installed (`g++ --version`)
- ✅ File `FoodDeliverySystem.cpp` exists
- ✅ No typos in filename
- ✅ In correct directory (`ls` or `dir`)
- ✅ Read/write permissions on folder
- ✅ Enough disk space (~2 MB)

---

## 🧪 **Test Cases**

### **Test Case 1: Regular User with SAVE10**

**Input**:
```
User Type: 1 (Regular)
Name: John
Restaurant: 1 (Pizza Palace)
Items: 101 (Margherita - ₹250, qty 1)
       103 (Chicken Pepperoni - ₹350, qty 1)
Coupon: SAVE10
```

**Expected Output**:
```
Subtotal: ₹600.00
GST: ₹30.00
Delivery: ₹40.00
Discount: ₹60.00 (10%)
Final: ₹610.00
```

---

### **Test Case 2: Premium User with SAVE20**

**Input**:
```
User Type: 2 (Premium)
Name: Alice
Restaurant: 2 (Biryani House)
Items: 203 (Chicken Biryani - ₹280, qty 2)
Coupon: SAVE20
```

**Expected Output**:
```
Subtotal: ₹560.00
GST: ₹28.00
Delivery: ₹0.00 (Free)
Discount: ₹156.80 (20% + 5%)
Final: ₹431.20
```

---

### **Test Case 3: Premium User No Coupon**

**Input**:
```
User Type: 2 (Premium)
Name: Bob
Restaurant: 3 (Burger Bliss)
Items: 302 (Cheese Burger - ₹140, qty 1)
Coupon: (skip)
```

**Expected Output**:
```
Subtotal: ₹140.00
GST: ₹7.00
Delivery: ₹0.00
Discount: ₹7.00 (5%)
Final: ₹140.00
```

---

## 🐛 **Troubleshooting**

### **Problem: Command not found: g++**

**Solution 1: Install G++**
```bash
# Linux
sudo apt-get install g++

# macOS
xcode-select --install
```

**Solution 2: Add to PATH**
- Windows: Add compiler path to system PATH
- Restart terminal after adding PATH

---

### **Problem: No such file: FoodDeliverySystem.cpp**

**Solution:**
1. Check filename spelling
2. Verify file exists: `ls FoodDeliverySystem.cpp`
3. Check current directory: `pwd` (Linux/Mac) or `cd` (Windows)
4. Navigate to correct folder

---

### **Problem: Compilation errors with -std=c++17**

**Solution:**
1. Use C++11 instead:
   ```bash
   g++ -std=c++11 -o FoodDeliverySystem FoodDeliverySystem.cpp
   ```
2. Or update compiler:
   ```bash
   sudo apt-get install g++ --upgrade
   ```

---

### **Problem: Program crashes after input**

**Solution:**
1. Ensure input is valid (numbers for menus)
2. Enter valid item IDs from menu
3. Enter valid coupon codes: SAVE10, SAVE20 (case-sensitive)
4. Use lowercase 'o' in option entry

---

### **Problem: Memory issues or leaks**

**Solution:**
Check that dynamic memory is properly deleted in destructors:
```bash
# Compile with memory checking (Linux)
g++ -g FoodDeliverySystem.cpp -o FoodDeliverySystem
valgrind ./FoodDeliverySystem

# No memory leaks should be reported
```

---

## 📋 **Quick Reference**

| Task | Command |
|------|---------|
| Compile | `g++ -std=c++17 -o FoodDeliverySystem FoodDeliverySystem.cpp` |
| Run (Linux/Mac) | `./FoodDeliverySystem` |
| Run (Windows) | `FoodDeliverySystem.exe` |
| Check compiler | `g++ --version` |
| Check C++ version | `g++ -std=c++17 -dumpversion` |
| Verbose compile | `g++ -Wall -Wextra -std=c++17 ...` |

---

## 🔧 **Advanced Compilation Options**

### **Debug Build** (for troubleshooting)
```bash
g++ -g -std=c++17 -Wall -Wextra -o FoodDeliverySystem FoodDeliverySystem.cpp
```

### **Release Build** (optimized)
```bash
g++ -O3 -std=c++17 -Wall -o FoodDeliverySystem FoodDeliverySystem.cpp
```

### **Profiling** (analyze performance)
```bash
g++ -pg -std=c++17 -o FoodDeliverySystem FoodDeliverySystem.cpp
./FoodDeliverySystem
gprof FoodDeliverySystem gmon.out
```

---

## 📊 **File Size Information**

After compilation:
- Source file: ~13 KB
- Executable (Linux): ~25 KB
- Executable (Windows): ~35 KB

---

## ✨ **Success Indicators**

✅ **Compilation successful if:**
- No error messages displayed
- Executable file created
- Can run without crashes

❌ **Compilation failed if:**
- Error messages shown
- Executable not created
- Program crashes on startup

---

## 🎓 **Next Steps After Compilation**

1. **Test Basic Functionality**
   - Try all user types
   - Try all restaurants
   - Verify bill calculations

2. **Study the Code**
   - Understand class hierarchies
   - Learn polymorphic behavior
   - Review memory management

3. **Modify and Extend**
   - Add new restaurants
   - Add new food types
   - Implement new features

---

## 📞 **Getting Help**

If you encounter issues:

1. **Check Documentation**
   - Read: README.md
   - Read: DOCUMENTATION.md
   - Read: OOP_CONCEPTS_EXPLAINED.md

2. **Common Fixes**
   - Update compiler: `sudo apt-get install g++ --upgrade`
   - Use different C++ standard: `-std=c++11` or `-std=c++14`
   - Check file permissions: `chmod +x FoodDeliverySystem`

3. **Compiler Resources**
   - G++ Manual: https://gcc.gnu.org/onlinedocs/
   - cppreference: https://en.cppreference.com/

---

## 🎉 **Congratulations!**

You've successfully set up and compiled the Food Delivery System project!

Now you're ready to:
- 🏃 Run the program
- 📖 Study the code
- ✏️ Modify and enhance it
- 🚀 Submit for grading

**Happy Coding!** 💻
