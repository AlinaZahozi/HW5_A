// Include necessary libraries and namespaces
#include "doctest.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "sources/MagicalContainer.hpp"
using namespace std;
using namespace ariel;


    TEST_CASE("Test 1 - Check constructor, add, size and remove methods"){

        // Construct an empty MagicalContainer object
        MagicalContainer magiContainer;
        
        // Check that the size of the newly constructed object is 0 (as it should have no elements)
        CHECK(magiContainer.size() == 0);

        // Add numbers 1 through 100 to the container
        for(int i = 1 ; i <= 100 ; i++){
            magiContainer.addElement(i);
        }
        
        // Check that the size of the container is now 100 (as we added 100 elements)
        CHECK(magiContainer.size() == 100);

        // Check that adding an existing element does not change the size
        magiContainer.addElement(50);
        CHECK(magiContainer.size() == 100);

        // Check that adding a new element increases the size by 1
        magiContainer.addElement(101);
        CHECK(magiContainer.size() == 101);

        // Remove numbers 99 through 0 from the container
        for(int i = 99 ; i >= 0 ; i--){
            magiContainer.removeElement(i);
        }

        // Check that the size of the container is now 1 (as we removed all the elements except 101)
        CHECK(magiContainer.size() == 1);

        // Check that removing an element that does not exist does not change the size
        magiContainer.removeElement(50);
        CHECK(magiContainer.size() == 1);

        // Check that removing an existing element decreases the size by 1
        magiContainer.removeElement(101);
        CHECK(magiContainer.size() == 0);

        // Attempt to remove an element from an empty container should throw an exception
        CHECK_THROWS(magiContainer.removeElement(1));
    }  


    TEST_CASE("Test 2 - AscendingIterator functionality") {

        // Test with an empty container
        MagicalContainer emptyContainer;

        // Create an AscendingIterator for the empty container
        MagicalContainer::AscendingIterator emptyIterator(emptyContainer);

        // Check that begin() and end() are equal for the empty container (no elements to iterate over)
        CHECK(emptyIterator.begin() == emptyIterator.end());
        
        // Attempt to remove an element from an empty container should throw an exception
        CHECK_THROWS(emptyContainer.removeElement(1));

        // Test with a single element
        MagicalContainer singleElementContainer;

        // Add a single element to the container
        singleElementContainer.addElement(1);

        // Create an AscendingIterator for the single element container
        MagicalContainer::AscendingIterator singleElementIterator(singleElementContainer);

        // Check that the first (and only) element is the one we added
        CHECK(*singleElementIterator.begin() == 1);

        // Check that incrementing the iterator once brings us to the end (only one element)
        CHECK(++singleElementIterator.begin() == singleElementIterator.end());

        // Test with multiple elements in ascending order
        MagicalContainer ascendingContainer;

        // Add multiple elements in ascending order
        for(int i = 1; i <= 100; i++){
            ascendingContainer.addElement(i);
        }

        // Create an AscendingIterator for the container with multiple elements
        MagicalContainer::AscendingIterator ascendingIterator(ascendingContainer);

        // Initialize expected value for the test
        int expectedValue = 1;

        // Check that the iterator returns the elements in the correct order
        for(auto iter = ascendingIterator.begin(); iter != ascendingIterator.end(); ++iter) {
            CHECK(*iter == expectedValue++);
        }

        // Test with multiple elements in descending order
        MagicalContainer descendingContainer;

        // Add multiple elements in descending order
        for(int i = 100; i > 0; i--){
            descendingContainer.addElement(i);
        }

        // Create an AscendingIterator for the container with multiple elements
        MagicalContainer::AscendingIterator descendingIterator(descendingContainer);

        // Reset expected value for the new test
        expectedValue = 1;

        // Check that the iterator still returns the elements in ascending order
        for(auto iter = descendingIterator.begin(); iter != descendingIterator.end(); ++iter) {
            CHECK(*iter == expectedValue++);
        }

        // Test with multiple elements in random order
        MagicalContainer randomContainer;
        
        // Add multiple elements in a random order
        randomContainer.addElement(98);
        randomContainer.addElement(21);
        randomContainer.addElement(87);
        randomContainer.addElement(32);
        randomContainer.addElement(76);
        randomContainer.addElement(43);
        randomContainer.addElement(65);
        randomContainer.addElement(54);

        // Create an AscendingIterator for the container with multiple elements in a random order
        MagicalContainer::AscendingIterator randomIterator(randomContainer);

        // Define the expected order of the elements
        vector<int> expectedOrder = {21, 32, 43, 54, 65, 76, 87, 98};

        // Initialize an iterator for the expected order
        auto expectedIter = expectedOrder.begin();

        // Check that the iterator returns the elements in the correct (ascending) order
        for(auto iter = randomIterator.begin(); iter != randomIterator.end(); ++iter) {
            CHECK(*iter == *expectedIter++);
        }
    }


    TEST_CASE("Test 3 - PrimeIterator functionality"){

        // Test with an empty container
        MagicalContainer emptyContainer;

        // Create a PrimeIterator for the empty container
        MagicalContainer::PrimeIterator emptyIterator(emptyContainer);

        // Check that begin() and end() are equal for the empty container (no elements to iterate over)
        CHECK(emptyIterator.begin() == emptyIterator.end());

        // Attempt to remove an element from an empty container should throw an exception
        CHECK_THROWS(emptyContainer.removeElement(1));

        // Test with a single prime element
        MagicalContainer singlePrimeContainer;

        // Add a single prime element to the container
        singlePrimeContainer.addElement(2);

        // Create a PrimeIterator for the single prime element container
        MagicalContainer::PrimeIterator singlePrimeIterator(singlePrimeContainer);

        // Check that the first (and only) element is the one we added
        CHECK(*singlePrimeIterator.begin() == 2);

        // Check that incrementing the iterator once brings us to the end (only one element)
        CHECK(++singlePrimeIterator.begin() == singlePrimeIterator.end());

        // Test with multiple prime elements
        MagicalContainer primeContainer;

        // Add multiple prime elements 
        primeContainer.addElement(2);
        primeContainer.addElement(3);
        primeContainer.addElement(5);
        primeContainer.addElement(7);
        primeContainer.addElement(11);

        // Create a PrimeIterator for the container with multiple prime elements
        MagicalContainer::PrimeIterator primeIterator(primeContainer);

        // Initialize expected value for the test
        int expectedValue = 2;

        // Check that the iterator returns the elements in the correct order
        for(auto iter = primeIterator.begin(); iter != primeIterator.end(); ++iter) {
            CHECK(*iter == expectedValue);
            if(expectedValue == 2) expectedValue++;  // Only even prime number is 2, all others are odd
            else expectedValue += 2;
        }

        // Test with multiple elements where some are not prime
        MagicalContainer mixedContainer;

        // Add multiple elements where some are not prime
        mixedContainer.addElement(2);  // Prime
        mixedContainer.addElement(4);  // Not prime
        mixedContainer.addElement(6);  // Not prime
        mixedContainer.addElement(7);  // Prime
        mixedContainer.addElement(9);  // Not prime
        mixedContainer.addElement(11); // Prime

        // Create a PrimeIterator for the container with multiple elements where some are not prime
        MagicalContainer::PrimeIterator mixedIterator(mixedContainer);

        // Define the expected order of the prime elements
        vector<int> expectedOrder = {2, 7, 11};

        // Initialize an iterator for the expected order
        auto expectedIter = expectedOrder.begin();

        // Check that the iterator returns only the prime elements in the correct order
        for(auto iter = mixedIterator.begin(); iter != mixedIterator.end(); ++iter) {
            CHECK(*iter == *expectedIter++);
        }
    }


    TEST_CASE("Test 4 - SideCrossIterator functionality"){

        // Test with an empty container
        MagicalContainer emptyContainer;

        // Create a SideCrossIterator for the empty container
        MagicalContainer::SideCrossIterator emptyIterator(emptyContainer);

        // Check that begin() and end() are equal for the empty container
        CHECK(emptyIterator.begin() == emptyIterator.end());

        // Attempt to remove an element from an empty container should throw an exception
        CHECK_THROWS(emptyContainer.removeElement(1));

        // Test with a single element
        MagicalContainer singleElementContainer;

        // Add a single element to the container
        singleElementContainer.addElement(1);

        // Create a SideCrossIterator for the single element container
        MagicalContainer::SideCrossIterator singleElementIterator(singleElementContainer);

        // Check that the first (and only) element is the one we added
        CHECK(*singleElementIterator.begin() == 1);

        // Check that incrementing the iterator once brings us to the end (only one element)
        CHECK(++singleElementIterator.begin() == singleElementIterator.end());

        // Test with multiple elements in ascending order
        MagicalContainer sequentialContainer;

        // Add elements from 1 to 10 to the container
        for(int i = 1; i <= 10; i++){
            sequentialContainer.addElement(i);
        }

        // Create a SideCrossIterator for the container with multiple elements
        MagicalContainer::SideCrossIterator sequentialIterator(sequentialContainer);

        // Define the expected order for the side-cross iterator (assumes alternating from start and end)
        vector<int> expectedOrder = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};

        // Initialize an iterator for the expected order
        auto expectedIter = expectedOrder.begin();

        // Check that the iterator returns the elements in the correct order
        for(auto iter = sequentialIterator.begin(); iter != sequentialIterator.end(); ++iter) {
            CHECK(*iter == *expectedIter++);
        }
    }
