#include "MagicalContainer.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

namespace ariel{

    // Default Constructor for MagicalContainer
    MagicalContainer::MagicalContainer() : 
    dataVector(vector<int>{}){} // empty vector

    // A method that assigns a boolean value to MagicalContainer. The purpose of this method needs to be defined.
    void MagicalContainer::assignd(bool value){}

    // Method to add an element to MagicalContainer
    void MagicalContainer::addElement(int element){}

    // Method to remove an element from MagicalContainer
    void MagicalContainer::removeElement(int element){}

    // Returns the size of MagicalContainer
    size_t MagicalContainer::size() const {
        return dataVector.size();
    }

    // Default Constructor for AscendingIterator
    MagicalContainer::AscendingIterator::AscendingIterator(): 
    iteratorScope(*(new MagicalContainer())), 
    curIndex(0) {} // default current index is 0

    // Constructor for AscendingIterator taking MagicalContainer as argument
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container): 
    iteratorScope(container), 
    curIndex(0){ // default current index is 0
        sortAscending();
    }

    // Constructor for AscendingIterator taking MagicalContainer and current index as arguments
    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container, size_t currentIndex): 
    iteratorScope(container), 
    curIndex(currentIndex) {}

    // Copy constructor for AscendingIterator
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &source): 
    iteratorScope(source.iteratorScope), 
    curIndex(source.curIndex) {}

    // Destructor for AscendingIterator
    MagicalContainer::AscendingIterator::~AscendingIterator() {}

    // Method to sort MagicalContainer in ascending order
    void MagicalContainer::AscendingIterator::sortAscending(){}

    // Assignment operator for AscendingIterator
    MagicalContainer::AscendingIterator &ariel::MagicalContainer::AscendingIterator::operator=(const AscendingIterator &source){
        return *this;
    }

    // Prefix increment operator for AscendingIterator
    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++(){
        return *this;
    }

    // Dereference operator for AscendingIterator
    int MagicalContainer::AscendingIterator::operator*() const {
        return 0;
    }

    // Equality comparison operator for AscendingIterator
    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const {
        return false;
    }

    // Inequality comparison operator for AscendingIterator
    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const {
        return false;
    }

    // Greater-than comparison operator for AscendingIterator
    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const {
        return false;
    }

    // Less-than comparison operator for AscendingIterator
    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const {
        return false;
    }

    // Returns an AscendingIterator pointing to the first element
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
        return *this;
    }

    // Returns an AscendingIterator pointing one past the last element
    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
        return *this;
    }

    // Default Constructor for SideCrossIterator
    MagicalContainer::SideCrossIterator::SideCrossIterator() :
    iterScope(*(new MagicalContainer())),
    startIdx(0),
    endIdx(0),
    isBeginning(true){} // by default, it is the beginning
    
        // Default constructor for PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator() : 
    iterScope(*(new MagicalContainer())), 
    curIdx(0) {} // default current index is 0

    // Constructor for PrimeIterator taking MagicalContainer and current index as arguments
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container, size_t currentIndex) : 
    iterScope(container), 
    curIdx(currentIndex) {}

    // Copy constructor for PrimeIterator
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &source): 
    iterScope(source.iterScope),
    curIdx(source.curIdx) {}

    // Assignment operator for PrimeIterator
    MagicalContainer::PrimeIterator &ariel::MagicalContainer::PrimeIterator::operator=(const PrimeIterator &source){
        return *this;
    }

    // Constructor for PrimeIterator taking MagicalContainer as argument
    MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &container) :
    iterScope(container) {}

    // Destructor for PrimeIterator
    MagicalContainer::PrimeIterator::~PrimeIterator() {}

    // Method to check if a number is prime
    bool MagicalContainer::PrimeIterator::isPrime(int number) const {
        return false;
    }

    // Dereference operator for PrimeIterator
    int MagicalContainer::PrimeIterator::operator*() const {
        return 0;
    }

    // Prefix increment operator for PrimeIterator
    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++(){
        return *this;
    }

    // Equality comparison operator for PrimeIterator
    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const {
        return false;
    }

    // Inequality comparison operator for PrimeIterator
    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const {
        return false;
    }

    // Greater-than comparison operator for PrimeIterator
    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const {
        return false;
    }

    // Less-than comparison operator for PrimeIterator
    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const {
        return false;
    }

    // Returns an PrimeIterator pointing to the first element
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
        return *this;
    }

    // Returns an PrimeIterator pointing one past the last element
    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
        return *this;
    }

    // Constructor for SideCrossIterator taking MagicalContainer as argument
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : 
    iterScope(*new MagicalContainer()) {}

    // Copy constructor for SideCrossIterator
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &source): 
    iterScope(source.iterScope),
    startIdx(source.startIdx),
    endIdx(source.endIdx),
    isBeginning(source.isBeginning) {}
    

    // Destructor for SideCrossIterator
    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

    // Method to arrange the SideCross in MagicalContainer
    void MagicalContainer::SideCrossIterator::arrangeSideCross(MagicalContainer &container){}

    // Assignment operator for SideCrossIterator
    MagicalContainer::SideCrossIterator &ariel::MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &source){
        return *this;
    }

    // Constructor for SideCrossIterator taking MagicalContainer, start index, end index and a boolean value as arguments
    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, size_t startIndex, size_t endIndex, bool isFront) :
    iterScope(container),
    startIdx(startIndex), 
    endIdx(endIndex), 
    isBeginning(isFront) {}

    // Dereference operator for SideCrossIterator
    int MagicalContainer::SideCrossIterator::operator*() const {
        return 0;
    }

    // Prefix increment operator for SideCrossIterator
    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++(){
        return *this;
    }

    // Equality comparison operator for SideCrossIterator
    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const {
        return false;
    }

    // Inequality comparison operator for SideCrossIterator
    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const {
        return false;
    }

    // Greater-than comparison operator for SideCrossIterator
    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const {
        return false;
    }

    // Less-than comparison operator for SideCrossIterator
    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const {
        return false;
    }

    // Returns a SideCrossIterator pointing to the first element
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
        return *this;
    }

    // Returns a SideCrossIterator pointing one past the last element
    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
        return *this;
    }
} 

