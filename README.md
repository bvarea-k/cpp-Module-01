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

### 🧱 From Object to Class

```mermaid
classDiagram
    class Human {
        +name: string
        +age: int
        +eat()
        +sleep()
    }
```

---

### 🧠 CPP01: Stack vs Heap

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

### ⚙️ CPP02: Orthodox Canonical Form

```mermaid
flowchart LR
    A[Class] --> B[Default Constructor]
    A --> C[Copy Constructor]
    A --> D[Copy Assignment Operator]
    A --> E[Destructor]
```

---

### 🧬 CPP03: Inheritance Hierarchy

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

### 🎭 CPP04: Polymorphism

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

Master them, and CPP05+ becomes much easier.
