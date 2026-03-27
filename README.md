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

* Forgetting `std::`
* Misunderstanding class vs struct
* Not separating `.hpp` / `.cpp`

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

👉 Misalignment = very common reason for losing points in this exercise.


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

---

### ⚙️ CPP02 — Orthodox Canonical Form

```mermaid
flowchart LR
    A[Class] --> B[Default Constructor]
    A --> C[Copy Constructor]
    A --> D[Copy Assignment Operator]
    A --> E[Destructor]
```

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

## ❗ Common Pitfalls

* Forgetting Orthodox Canonical Form
* Forgetting to add the flag -std=c++98
* Memory leaks (instant fail)
* Missing `virtual` destructor
* Object slicing in inheritance

---
