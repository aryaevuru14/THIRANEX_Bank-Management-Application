# Bank Management Application 🏦

A C++ console-based application that simulates essential core banking operations, featuring object-oriented design and persistent data storage using binary files. Developed for the **Thiranex Internship Program**.

## 🚀 Key Features

* **Account Creation:** Register new accounts with account numbers, holder names, and initial balances.
* **Deposits & Withdrawals:** Process dynamic account transactions with built-in balance validation.
* **Balance Inquiry:** Search and retrieve account balances instantaneously by account number.
* **Display Records:** Output all registered accounts in a clean, formatted table.
* **Data Persistence:** Read and write account data seamlessly using binary file handling (`bank_data.dat`).

---

## 🛠️ Tech Stack

* **Language:** C++
* **Paradigm:** Object-Oriented Programming (OOP)
* **Storage:** Binary File I/O (`std::fstream`, `std::ifstream`, `std::ofstream`)
* **Formatting:** Stream manipulation (`std::iomanip`)

---

## 💻 Setup and Run

### Prerequisites
Ensure you have a C++ compiler installed (such as GCC/MinGW).

### Execution Steps

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/aryaevuru14/THIRANEX_Bank-Management-Application.git](https://github.com/aryaevuru14/THIRANEX_Bank-Management-Application.git)
   cd THIRANEX_Bank-Management-Application

2. **Compile the code:**
```bash
g++ BankManagementApplication.cpp -o BankManagement

3. **Run the program:**
```bash
.\BankManagement.exe

## 📁 File Structure

```text
├── BankManagementApplication.cpp   # Source code
├── bank_data.dat                  # Binary database file (generated automatically)
└── README.md                      # Documentation
