/**
 * Name: Yosiah de Koeyer
 * Student No: c3329520
 * Course: SENG1120 - A3
 *
 * File: HTable.h
 * Description: HTable Declaration and Implementation
 */

#include <iostream>
#include <string>

#ifndef HTABLE_H
#define HTABLE_H

template <typename value_type>
class HTable {
public:
    /**
     * HTable constructor
     */
    HTable() {
        current = 0;
    }

    /**
     * Htable constructor
     * @param data given data to be added to the HTable
     */
    HTable(value_type const data) {
        add(data);  // Add given data to HTable
    }

    /**
     * HTable::~Htable() method
     * A Instance of HTable doesnt store anything on the heap so the destructor has nothing to do
     */
    ~HTable() {
        // Nothing to do here
    }

    /**
     * HTable::add() method
     * @param givenData data of given value_type to add to the HTable
     */
    void add(value_type const givenData) {
        data[hashFunc(givenData)] = givenData;      // Assign data to array at index given by hashFunc()
    }

    /**
     * HTable::remove() method
     * @param givendata data of given value_type to remove from the HTable
     */
    void remove(value_type const givendata) {
        if (data[hashFunc(givendata)] == givendata) { // only remove if its there
            data[hashFunc(givendata)] = "";
        }
    }


    /**
     * HTable::toString() method
     * @return a String representation of the table
     */
    std::string toString() const {
        std::string hashTableString;
        for (int i = 0; i < SIZE; i++) {            // For each element in the array
            if (data[i] != "") {                    // If contains data, append to string
                hashTableString += data[i] + " ";
            }
        }
        return hashTableString;
    }

    /**
     * HTable::getDataAtCurrent() method
     * @return data stored in the HTable of given value_type at the current
     */
    value_type getDataAtCurrent() const {
        return data[current];
    }

    /**
     * HTable::resetCurrent() method
     * Resets the current pointer back to 0
     */
    void resetCurrent() {
        current = 0;
    }

    /**
     * HTable::incrementCurrent() method
     * Increments the current pointer by 1
     */
    void incrementCurrent() {
        current++;
    }

    /**
     * Overloaded += operator
     * @param HTable2 second HTable to add all values of to this table
     */
    void operator += (HTable& HTable2) {
        for (int i = 0; i < HTable2.getSize(); i ++) {
            if (HTable2.getDataAtCurrent()!= "") {
                add(HTable2.getDataAtCurrent());
            }
            HTable2.incrementCurrent();
        }
        HTable2.resetCurrent();
    }

    /**
     * HTable::getSize() method
     * @return a int containing the max size of the HTable array
     */
    const int getSize() {
        return SIZE;
    }

private:
    static const int SIZE = 150;    // size of HTable array
    value_type data[SIZE];          // array of given value_type to store data in
    int current;                    // current pointer

    /**
     * HTable::hashFunc() method
     * @param givenData data of given value_type to calculate the hash value of
     * @return an int, the 'hash' representing where the given data should be stored in the array
     */
    int hashFunc(value_type const givenData) { // TODO: hardcode as string?
        int addResult = 0;
        for (unsigned long int i = 0; i < givenData.length(); i++ ) { // TODO: refactor to use iterator?
            addResult += (int)givenData[i];
        }
        return  addResult % SIZE;
    }

};

/**
 * HTable overloaded << operator
 */
template <typename value_type>
std::ostream& operator << (std::ostream& out, HTable<value_type>& hashTable) {
    std::string HTstring = hashTable.toString();
    out << HTstring;
    return out;
}

#endif //HTABLE_H
