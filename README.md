# Municipal Financial Management System (MFMS) - Demo

This is a demonstration prototype based on the PAP521S Project A brief.

# Municipal Financial Management System (MFMS)

## Group Number
Group 

## Group Members
- 1. 225172534 – Amuthenu - Employee Management 
- 2. 226122409 – Angula - Budget Management 
- 3. 224092308 – Simataa - Supplier Management 
- 4. 225129205 – Nganjone - Asset Management
- 5. 223077941 – Hausiku  - Reports 
- 6. 225170752 – Mbambi  - Functions, integration and validation  
- 7. 225178958 – Ferreira - Testing, documentation and Git coordination 

## Project Description
The Municipal Financial Management System (MFMS) is a C-based application designed to help municipalities manage employee records, budgets, suppliers, assets, and financial reports efficiently.

## System Features
- Employee management (add, search, display)
- Budget tracking and calculations
- Supplier registration and tender evaluation
- Asset management and depreciation tracking
- Report generation for financial summaries

## Language
ANSI C / C99

## Compile with GCC

```bash
gcc -std=c99 -Wall -Wextra main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms
```

## Run on Windows

```bash
mfms.exe
```

## Run on Linux/macOS

```bash
./mfms
```

## Included modules

1. Employee Management
2. Budget Management
3. Supplier Management
4. Asset Management
5. Reports

The program starts with sample records so the menus and reports can be tested immediately. New records can also be added while the program is running.

## Note

This is a console demonstration. It stores data in memory while the program is running; it does not use a database or permanent file storage.
