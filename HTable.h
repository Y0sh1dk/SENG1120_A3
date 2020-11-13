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
        // TODO: initalize array maybe?
    }

    /**
     * Htable constructor
     * @param data given data to be added to the HTable
     */
    HTable(value_type data) {
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
    void add(value_type givenData) {
        data[hashFunc(givenData)] = givenData;      // Assign data to array at index given by hashFunc()
    }

    /**
     * HTable::remove() method
     * @param givendata data of given value_type to remove from the HTable
     */
    void remove(value_type givendata) {
        if (data[hashFunc(givendata)] == givendata) { // only remove if its there
            data[hashFunc(givendata)] = "";
        }
    }


    /**
     * HTable::toString() method
     * @return a String representation of the table
     */
    std::string toString() {
        std::string hashTableString;
        for (int i = 0; i < SIZE; i++) {            // For each element in the array
            if (data[i] != "") {                    // If contains data, append to string
                hashTableString += data[i] + " ";
            }
        }
        return hashTableString;
    }

    /**
     * Overloaded += operator
     * @param HTable2 second HTable to add all values of to this table
     */
    void operator += (HTable& HTable2) {
        std::string HTable2String;
        HTable2String = HTable2.toString();
        int pos = -1;
        for (unsigned long int i = 0; i <= HTable2String.length(); i++) { // TODO: refactor to use iterator?
            if (isspace(HTable2String[i])) {
                add(HTable2String.substr(pos+1, i-(pos+1)));
                pos = i;
            }
        }
    }

private:
    static const int SIZE = 150;    // size of HTable array
    value_type data[SIZE];          // array of given value_type to store data in

    /**
     * HTable::hashFunc() method
     * @param givenData data of given value_type to calculate the hash value of
     * @return an int, the 'hash' representing where the given data should be stored in the array
     */
    int hashFunc(value_type givenData) { // TODO: hardcode as string?
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
