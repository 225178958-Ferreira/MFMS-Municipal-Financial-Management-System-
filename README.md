# Municipal Financial Management System (MFMS) - Demo

This is a demonstration prototype based on the PAP521S Project A brief.

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
