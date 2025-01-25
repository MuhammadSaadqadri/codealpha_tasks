# File Manager Program

This is a simple file manager program written in C++ for managing files and directories on a Windows operating system. The program allows the user to create directories, list directory contents, create files, copy files, and move files through a menu-driven interface.

## Features:
- **Create Directory**: Allows you to create a new directory.
- **List Directory**: Lists the contents of an existing directory.
- **Create Files**: Allows you to create a new file with the content "Hello World" in a specified directory.
- **Copy Files**: Copies a file from a source to a destination path.
- **Move Files**: Moves a file from a source to a destination path.

## Requirements:
- This program is designed to run on **Windows**.
- It uses Windows-specific functions such as `CopyFile()` and `MoveFile()`.

## Compilation:
1. Open a terminal or command prompt.
2. Use a C++ compiler (such as g++ or Visual Studio's compiler).
3. Compile the program by running the following command:
   ```bash
   g++ -o FileManager FileManager.cpp
