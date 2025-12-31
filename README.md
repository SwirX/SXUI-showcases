# SXUI Showcases

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Repo Size](https://img.shields.io/github/repo-size/SwirX/SXUI-showcases)](https://github.com/SwirX/SXUI-showcases)
[![Language: C](https://img.shields.io/badge/language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![SXUI](https://img.shields.io/badge/SXUI-library-lightgrey.svg)](https://github.com/SwirX/SXUI)

Welcome to the official showcase gallery for **[SXUI](https://github.com/SwirX/SXUI)**.

This repository contains a collection of standalone examples that demonstrate the capabilities of SXUI while teaching the fundamentals of C GUI programming.

---

## 🚀 About SXUI

**SXUI** is a minimal, explicit, and lightweight UI library for C, built on top of SDL2.

It’s designed for developers who want full control over their interfaces, without bloat or hidden behavior:

* **Explicit State:** You handle your data; SXUI handles pixels.
* **No "Magic":** No scripting, no markup, no runtime surprises.
* **Event-Driven:** Simple callback systems for buttons, inputs, and custom elements.
* **Educational:** Perfect for understanding how UI really works under the hood.

---

## 📂 Repository Structure

Each directory in this repository is a **Showcase** — a focused example of SXUI in action.

Each showcase contains:

1. **`main.c`** — The heavily commented source code, showing the implementation.
2. **`README.md`** — An optional deep-dive tutorial explaining concepts like pointers, memory management, and bitwise logic.

### Current Showcases

* **[Simple Login Form](showcases/simple_login_form)** — Covers window setup, frames, labels, inputs, buttons, bitwise flags, and event-driven callbacks.

---

## 🛠 Getting Started

### Prerequisites

* C compiler (GCC or Clang)
* **SDL2** development libraries

### Building

Clone the repository (with SXUI as a submodule) and build all showcases from the root directory:

```bash
git clone --recursive https://github.com/SwirX/SXUI-showcases.git
cd SXUI-showcases
make
```

### Running

All binaries are placed in the `bin/` folder:

```bash
./bin/simple_login_form
```

---

## 🧠 What to Expect

Each showcase is designed to be a **mini-course in C GUI programming**. You will learn:

* **Memory Management:** How to use pointers safely.
* **Bitwise Logic:** How to toggle UI states efficiently.
* **Event Loops:** The heartbeat of GUI applications.
* **Real C Code:** No frameworks hiding what’s really happening.

The goal is to teach **how UI actually works**, not just to make pretty windows.

---

## License

These showcases are licensed under MIT, just like SXUI itself. Feel free to study, modify, and reuse the code.
