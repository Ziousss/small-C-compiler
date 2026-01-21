# TELLA Compiler

Welcome to **TELLA**, a basic **C compiler written in C**.

This project is an educational compiler developed to improve my practical knowledge of the C language and to deepen my understanding of fundamental concepts such as **pointers**, **parsing**, and **semantic analysis**.

---

## Overview

- **Source language:** C  
- **Implementation language:** C  
- **Current stage:** Up to semantic analysis  
- **Build system:** CMake  

---

## Goal

The goal of this compiler is to **analyze C source code**, **detect errors**, and eventually **translate it into machine code** so that it can be safely executed.

This project is primarily focused on learning compiler design concepts rather than providing a production-ready compiler.

---

## Current Progress

The following compiler stages are implemented:

- ✅ Lexer  
- ✅ Parser  
- ✅ Semantic Analyzer  

These components are mostly functional but may still require fixes and improvements.

---

## Next Steps

The next major step is to implement the **code generation phase**.

This will require additional research, particularly regarding:
- Target architecture
- Instruction selection
- Code emission

---

## Installation

Clone the repository and build the project using CMake:

```bash
git clone https://github.com/ziousss/tella-compiler
cd tella-compiler
mkdir build && cd build
cmake ..
make
```

---

## Test

To use this compiler,

```bash
cd build
./compiler /path/to/the/file
```

You can also use the test file given in the folder.
Write the code to try in the test.c file.

```bash
cd build
./compiler ../test.c
```