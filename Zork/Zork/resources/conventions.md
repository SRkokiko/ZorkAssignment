## Conventions

### Naming Classes & Structs
PascalCase — e.g. `Entity`, `GameWorld`

### Naming Methods & Functions
PascalCase — e.g. `GetName()`, `Describe()`

### Naming Member Variables
`m_` prefix + camelCase — e.g. `m_name`, `m_entities`

### Naming Local Variables
camelCase — e.g. `currentRoom`, `itemCount`

### Naming Constants & Enums
PascalCase for both the enum class name and its values.
Enum values do **not** use the `m_` prefix.
e.g. `enum class Direction { North, South, East, West };`

### Naming Files
Match the class name exactly, one class per file.
e.g. `Entity.h` / `Entity.cpp`

## Header Rules
- Use `#pragma once` at the top of every header
- **Never** use `using namespace std` in `.h` files — always qualify: `std::string`, `std::vector`
- `using namespace std` is allowed in `.cpp` files only

## Const Correctness
- All getters must be marked `const`
- Return `const std::string&` instead of `std::string` to avoid copies
- Return `const std::list<Entity*>&` for container getters; provide a
  non-const overload if callers need to mutate elements
- Pass objects by `const&` when the method does not modify them
- Any method that only reads state must be `const`