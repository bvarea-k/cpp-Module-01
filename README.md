# 🚀 C++ Modules 00–04 — 42 School

> A practical and structured introduction to Object-Oriented Programming in C++ (C++98 standard), built through the 42 curriculum.

---

## 📌 Overview

This repository contains my implementations for **CPP00 → CPP04**, designed to help students transition from procedural programming in C to **Object-Oriented Programming (OOP)** in C++.

---

## 🧭 What do we learn in these modules?

```mermaid
flowchart LR
    A[CPP00: Basics] --> B[CPP01: Memory]
    B --> C[CPP02: Canonical Form]
    C --> D[CPP03: Inheritance]
    D --> E[CPP04: Polymorphism]
```

---

## 🧠 Core Concepts Visualization

### 🧱 CPP00 — First Steps in C++

> *"From C to C++ mindset shift"*

* Namespaces (`std::`)
* Classes & member functions
* Streams (`std::cout`, `std::cin`)
* Basic encapsulation

✅ **Goal:** Understand how C++ structures code differently from C.

⚠️ **Common mistakes:**

1. Forgetting `std::`
2. Misunderstanding class vs struct
3. Not separating `.hpp` / `.cpp`

📏 **Evaluator Tip (PhoneBook formatting):**

Some evaluators pay **special attention** to column alignment in the `PhoneBook` exercise.

* The output must be perfectly aligned using fixed-width columns.
* Vertical separators (`|`) must line up exactly.

💥 **Important detail:**
Only use **ASCII characters** in displayed strings.

Characters like:

* `á`, `é`, `ñ`, etc.

may visually take more space than expected, breaking alignment even if your code seems correct.

🧪 **Recommendation:**

* Stick to standard ASCII characters
* Use `std::setw()` for consistent formatting
* Test your output with different inputs

✅ Correct Output
|     index|first name| last name|  nickname|
|         0|      John|       Doe|      JDoe|

✔️ Columns aligned
✔️ Width respected
✔️ Clean formatting

❌ Incorrect Output
| index | first name | last name | nickname |
| 0 | John | Doe | JDoe |

💥 Problems:

Misaligned columns
Inconsistent spacing
Wrong formatting


---

### 🧠 CPP01 — Stack vs Heap

```mermaid
flowchart TD
    A[Program Start] --> B{Memory Type}

    B -->|Stack| C[Automatic Allocation]
    B -->|Heap| D[Dynamic Allocation]

    C --> E[Destroyed automatically]
    D --> F[Must use delete]

    F --> G[Memory freed manually]
```

💡 Stack = safer, Heap = more flexible but dangerous.

⚠️ Common mistakes:

1. Memory leaks

🧪 What to double-check:

* Every new has a matching delete
* Arrays use delete[]
* No leaks in error paths

---

### ⚙️ CPP02 — Orthodox Canonical Form

```mermaid
flowchart LR
    A[Class] --> B[Default Constructor]
    A --> C[Copy Constructor]
    A --> D[Copy Assignment Operator]
    A --> E[Destructor]
```

⚠️ Common mistakes:

1. Not using the Orthodox Canonical Form
2. Shallow copy instead of deep copy
3. Self-assignment bugs
4. Returning wrong types

---

### 🧬 CPP03 — Inheritance Hierarchy

```mermaid
classDiagram
    class ClapTrap {
        +attack()
        +takeDamage()
        +beRepaired()
    }

    class ScavTrap {
        +guardGate()
    }

    class FragTrap {
        +highFivesGuys()
    }

    ClapTrap <|-- ScavTrap
    ClapTrap <|-- FragTrap
```

💡 Child classes reuse and extend parent behavior.

⚠️ Common mistakes:

1. Not calling the base constructor explicitly
2. Re-declaring attributes already in the base class
3. Using wrong access specifiers (private instead of protected)

---

### 🎭 CPP04 — Polymorphism

```mermaid
classDiagram
    class Animal {
        <<abstract>>
        +makeSound()
    }

    class Dog {
        +makeSound()
    }

    class Cat {
        +makeSound()
    }

    Animal <|-- Dog
    Animal <|-- Cat
```

---

### 🔁 Virtual Function Behavior

```mermaid
sequenceDiagram
    participant Main
    participant Animal
    participant Dog

    Main->>Animal: call makeSound()
    Animal-->>Dog: resolved at runtime
    Dog-->>Main: "Bark"
```

💥 This is **runtime polymorphism**


⚠️ Common mistakes:

1. Missing virtual destructor
  If you delete a derived object through a base pointer without a virtual destructor → undefined behavior.

    Base* obj = new Derived();
    delete obj; //  problem if destructor is not virtual

    -> How to fix it
   virtual ~Base();

3. Shallow copy in complex objects
    If your class contains pointers:

    Copy constructor must duplicate the data (deep copy)
    Not just copy the pointer

4. Wrong polymorphism
    Evaluators will check:

    * Are functions truly overridden?
    * Are you using virtual correctly?
    * Does behavior change at runtime
---

## ⚙️ Compilation

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

---

## 🔍 Debugging & Testing

### Memory leaks

```bash
valgrind --leak-check=full ./program
```

---

