# SEI CERT Coding Guidelines Implementation

## **Overview**
This repository contains implementations of selected SEI CERT Coding Guidelines for C, C++, and Java. Each guideline includes:
- The **guideline name** and **CERT number**.
- A **brief description** in simple terms.
- A **compliant code example** (and optionally a non-compliant example).

This project ensures adherence to secure coding practices, improving software security and stability.

---

## **Guidelines Covered**

### **C Guidelines**
1. **Do not use `gets()` to read user input** (`FIO30-C`)
   - **Description:** Using `gets()` can lead to buffer overflows, causing security vulnerabilities. Instead, `fgets()` should be used.
   - **Compliant Code:** [`C_Guidelines/guideline1.c`](C_Guidelines/guideline1.c)
  
2. **Validate function parameters before use** (`API00-C`)
   - **Description:** Functions should validate input parameters to prevent unexpected behavior or security issues.
   - **Compliant Code:** [`C_Guidelines/guideline2.c`](C_Guidelines/guideline2.c)
  
3. **Do not modify the standard library namespace** (`DCL58-C`)
   - **Description:** Changing or adding new declarations inside `std` or `posix` namespaces leads to undefined behavior.
   - **Compliant Code:** [`C_Guidelines/guideline3.c`](C_Guidelines/guideline3.c)

---

### **C++ Guidelines**
1. **Always declare virtual destructors in base classes** (`OOP52-CPP`)
   - **Description:** Ensures proper cleanup when deleting objects through a base class pointer.
   - **Compliant Code:** [`CPP_Guidelines/guideline1.cpp`](CPP_Guidelines/guideline1.cpp)

2. **Ensure exception safety** (`ERR56-CPP`)
   - **Description:** Exception safety guarantees prevent memory leaks or inconsistent program states during exceptions.
   - **Compliant Code:** [`CPP_Guidelines/guideline2.cpp`](CPP_Guidelines/guideline2.cpp)

3. **Do not disable bytecode verification** (`ENV04-J`)
   - **Description:** Disabling Java bytecode verification allows execution of tampered or insecure class files.
   - **Compliant Code:** [`CPP_Guidelines/guideline3.cpp`](CPP_Guidelines/guideline3.cpp)

---

### **Java Guidelines**
1. **Do not log sensitive data** (`FIO13-J`)
   - **Description:** Logs should not contain personally identifiable information (PII) such as passwords, IP addresses, or credit card numbers.
   - **Compliant Code:** [`Java_Guidelines/guideline1.java`](Java_Guidelines/guideline1.java)

2. **Validate deserialized objects** (`SER07-J`)
   - **Description:** Deserializing untrusted data without validation can allow attackers to manipulate object states.
   - **Compliant Code:** [`Java_Guidelines/guideline2.java`](Java_Guidelines/guideline2.java)

3. **Prevent multiple instantiations of singleton objects** (`MSC07-J`)
   - **Description:** Singletons should prevent deserialization from creating multiple instances.
   - **Compliant Code:** [`Java_Guidelines/guideline3.java`](Java_Guidelines/guideline3.java)

---

## **Instructions to Run the Code**
To test each file, compile and run it in the appropriate environment.

### **C Files**
```sh
gcc C_Guidelines/guideline1.c -o guideline1.out
./guideline1.out
