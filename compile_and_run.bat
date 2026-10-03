@echo off
title MFMS - Municipal Financial Management System

echo ===============================================
echo    BUILDING MUNICIPAL FINANCIAL MANAGEMENT
echo ===============================================
echo.

gcc -std=c99 -Wall -Wextra main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms.exe

if errorlevel 1 (
    echo.
    echo Build failed. Make sure GCC is installed and in PATH.
    pause
    exit /b 1
)

echo.
echo Build successful!
echo Starting MFMS...
echo.
mfms.exe
pause
