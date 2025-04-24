# MediCore Hospital Management System

A comprehensive C-based console application for managing hospital patient and doctor records, featuring secure login, animated UI effects, and full CRUD functionality.

## 🏥 Project Description

The MediCore Hospital Management System (HMS) is a menu-driven application built in C for managing hospital operations such as patient and doctor records. It is intended for use by hospital administrators and includes features for securely handling patient admissions, updates, and doctor assignments. The interface includes animations, typing effects, and cursor control to enhance usability.

## ✨ Features

### 👤 Admin Access
- Secure login with password masking
- Restricted access to patient and doctor records

### 🧑‍⚕️ Patient Management
- Add inpatient or outpatient
- View all patients
- Search patient by National ID
- Modify patient details
- Delete patient records
- Data stored in `patients.dat` file (text-based)

### 👨‍⚕️ Doctor Management
- Add doctor with specialty
- View all doctors
- Search doctor by ID
- Modify doctor information
- Delete doctor records
- Data stored in `doctors.txt` file (text-based)

### 🖥️ UI Enhancements
- Console animations (dots, loading, searching, etc.)
- Typing effects for dynamic feedback
- Cursor visibility control
- Color-coded output using ANSI escape sequences

## 🔐 Admin Credentials
- **Username:** `admin`
- **Password:** `admin`

## 🛠️ Build & Run

### Requirements:
- Windows OS (uses `windows.h`)
- GCC Compiler or Code::Blocks / Dev C++

### Compile
```bash
gcc HMS.c -o HMS.exe
