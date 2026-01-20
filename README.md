# Rule-Based Sand Simulation (SFML)

## Overview
This project is a **2D rule-based simulation** written in **C++** using **SFML**.  
The primary goal is to build a **simple falling sand–style simulation**, including elements such as sand and fire, while progressively learning and applying SFML concepts.

This repository also serves as a development log for SFML experimentation. Early commits focus on foundational systems and may appear minimal or exploratory by design.

---

## Motivation
The project is intended to strike a balance between **learning and building**:
- Learn SFML through hands-on practice
- Apply that knowledge to a small but complete simulation project
- Avoid unnecessary complexity or advanced physics systems

The focus is on clarity, correctness, and incremental progress.

---

## Current Focus
At this stage, development is centered around:
- Window creation and lifecycle management
- Event handling (keyboard input, resizing, focus changes)
- Application loop structure and frame limiting
- Understanding SFML’s modern event API

Rendering and simulation logic will be layered on top once these fundamentals are stable.

---

## Simulation Direction
The simulation is inspired by classic falling sand games and cellular simulations, featuring:
- Gravity-driven sand particles
- Simple fire behavior with spread and decay rules
- Rule-based interactions between elements
- Grid-based or lightweight particle representations

The design intentionally prioritizes **simple, deterministic rules** over realism.

---

## Technology Stack
- **Language:** C++ (modern standard)
- **Graphics Library:** SFML
- **Build System:** CMake

---

## Development Notes
This is an evolving project. Code structure, abstractions, and design decisions may change as understanding of SFML and simulation systems improves. Refactoring is expected and intentional.

---

## Status
Work in progress. Features and structure will continue to evolve over time.
