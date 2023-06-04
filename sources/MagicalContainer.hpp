#pragma once // Ensures the header file is included only once during compilation
#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace ariel{

    class MagicalContainer {

    private:

        vector<int> dataVector; // Vector storing the data
        bool hasAssignment = false; // State indicating if the container is assigned to something

    public:

        // Default Constructor
        MagicalContainer ();

        // Method to add an element to the container
        void addElement(int newItem);

        // Method to remove an element from the container
        void removeElement(int targetItem);

        // Method to return the size of the container
        size_t size() const;

        // Method to set the assignment state
        void assignd(bool assignState);

        // Inner classes for custom iterators
        class AscendingIterator;
        class SideCrossIterator;
        class PrimeIterator;
    };

    class MagicalContainer::AscendingIterator {

    private:

        MagicalContainer iteratorScope; // The container this iterator is associated with
        size_t curIndex; // Current index for this iterator

    public:

        // Default constructor
        AscendingIterator();

        // Construct an iterator associated with a container
        AscendingIterator(MagicalContainer &scope);

        // Construct an iterator associated with a container with a current index
        AscendingIterator(MagicalContainer &scope, size_t curIndex);

        // Copy constructor
        AscendingIterator(const AscendingIterator &src);

        // Destructor
        ~AscendingIterator();

        // Assignment operator
        AscendingIterator &operator=(const AscendingIterator &src);

        // Method to sort elements in ascending order
        void sortAscending();

        // Dereference operator
        int operator*() const;

        // Prefix increment operator
        AscendingIterator &operator++();

        // Equality comparison operator
        bool operator==(const AscendingIterator &other) const;

        // Inequality comparison operator
        bool operator!=(const AscendingIterator &other) const;

        // Greater-than comparison operator
        bool operator>(const AscendingIterator &other) const;

        // Less-than comparison operator
        bool operator<(const AscendingIterator &other) const;

        // Returns an iterator pointing to the first element
        AscendingIterator begin();

        // Returns an iterator pointing one past the last element
        AscendingIterator end();
    };



    class MagicalContainer::PrimeIterator {

    private:

        const MagicalContainer &iterScope; // The container this iterator is associated with
        size_t curIdx; // Current index for this iterator

        // Method to check if a number is prime
        bool isPrime(int candidate) const; 

    public:

        // Default constructor
        PrimeIterator();
        
        // Construct an iterator associated with a container
        PrimeIterator(const MagicalContainer &scope);

        // Construct an iterator associated with a container with a current index
        PrimeIterator(const MagicalContainer &scope, size_t curIdx);

        // Copy constructor
        PrimeIterator(const PrimeIterator &src);

        // Destructor
        ~PrimeIterator();

        // Assignment operator
        PrimeIterator &operator=(const PrimeIterator &src);

        // Dereference operator
        int operator*() const;

        // Prefix increment operator
        PrimeIterator &operator++();

        // Equality comparison operator
        bool operator==(const PrimeIterator &other) const;
        
        // Inequality comparison operator
        bool operator!=(const PrimeIterator &other) const;

        // Greater-than comparison operator
        bool operator>(const PrimeIterator &other) const;

        // Less-than comparison operator
        bool operator<(const PrimeIterator &other) const;

        // Returns an iterator pointing to the first element
        PrimeIterator begin();

        // Returns an iterator pointing one past the last element
        PrimeIterator end();
    };

    class MagicalContainer::SideCrossIterator {

    private:

        MagicalContainer &iterScope; // The container this iterator is associated with
        size_t curIdx; // Current index for this iterator
        size_t startIdx; // Start index for this iterator
        size_t endIdx; // End index for this iterator
        bool isBeginning; // Boolean to determine the direction of traversal

    public:

        // Default constructor
        SideCrossIterator();

        // Construct an iterator associated with a container
        SideCrossIterator(MagicalContainer &scope);

        // Construct an iterator associated with a container with a current index, start index, end index and direction of traversal
        SideCrossIterator(MagicalContainer &scope, size_t startIdx, size_t endIdx, bool isBeginning);

        // Copy constructor
        SideCrossIterator(const SideCrossIterator &src);

        // Destructor
        ~SideCrossIterator();

        // Assignment operator
        SideCrossIterator &operator=(const SideCrossIterator &src);

        // Method to arrange elements in a specific pattern
        void arrangeSideCross(MagicalContainer &scope);

        // Dereference operator
        int operator*() const;

        // Prefix increment operator
        SideCrossIterator &operator++();

        // Equality comparison operator
        bool operator==(const SideCrossIterator &other) const;

        // Inequality comparison operator
        bool operator!=(const SideCrossIterator &other) const;

        // Greater-than comparison operator
        bool operator>(const SideCrossIterator &other) const;

        // Less-than comparison operator
        bool operator<(const SideCrossIterator &other) const;

        // Returns an iterator pointing to the first element
        SideCrossIterator begin();

        // Returns an iterator pointing one past the last element
        SideCrossIterator end();
    };
}
