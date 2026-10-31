# CONTACTS-MANAGER
## personel input
this is contact management program...the purpose of this code is to show that how a hash map is extremely faster in comparison with a vector
this can be easily understood by looking at time taken below
in a hash map the things are stores randomly ..and its order changes everytime some change are made in it
vector checks everytime when we are searching for something
but  a hash map doesnt search it stores the given data at a particular slot , when we have to look that data up it directly goes to that slot without looking at any other slot hence it is a lot faster


# Contact Management System (C++)

A menu-driven Contact Management System implemented in C++ using **Vectors** and **Unordered Maps**. The project supports basic contact operations and compares the search performance of different data structures.

## Features

- Add, search, delete and list contacts.
- Generate 100,000 contacts.
- Clear stored contacts.
- Search using `vector<pair<string, long>>`.
- Search using `unordered_map<string, long>`.
- Search using `unordered_map<long, string>`.
- Benchmark searching performance using `std::chrono`.

## Data Structures Used

| Data Structure | Key | Value |
|---|---|---|
| Vector | Contact name | Phone number |
| Unordered Map 1 | Contact name | Phone number |
| Unordered Map 2 | Phone number | Contact name |

## Performance Benchmark

The benchmark is designed to perform:
- **100,000 successful searches** (existing contacts).
- **50,000 unsuccessful searches** (non-existing contacts).
- **150,000 total search operations**.

### Comparison Table

| Data Structure | Found | Not Found | Total Searches | Time  |
|---|---:|---:|---:|---:|
| Vector | 100,000 | 50,000 | 150,000 | 78.7 sec |
| Unordered Map (String Key) | 100,000 | 50,000 | 150,000 | 25 ms|
| Unordered Map (Integer Key)| 100,000 | 50,000 | 150,000 | 10 ms |

##

| Operation | Vector | Unordered Map (Average) |
|---|---|---|
| Search | O(n) | O(1) |
| Insertion | O(1) amortized | O(1) average |
| Deletion | O(n) | O(1) average |

## Technologies Used

- C++17
- STL (Vector, Pair, Unordered Map)
- Chrono Library
- String Library

## Compilation & Execution (macOS)

Using **Clang++** in the macOS Terminal or VS Code integrated terminal:

```bash
clang++ -std=c++17 main.cpp -o contacts
./contacts
```

## Objective

To understand the practical differences between linear searching and hash-based searching, and evaluate how the choice of data structure affects program performance.
