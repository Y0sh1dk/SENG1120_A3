/*
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
    // Pre-Condition: None
    //
    // Post Condition: None
    HTable() {
        // TODO: initalize array maybe?
    }

    // Pre-Condition: data to be added to the table
    // Creates a table and added the given data too it
    // Post Condition: None
    HTable(value_type data) {
        add(data);  // Add given data to HTable
    }

    // Pre-Condition: None
    //
    // Post Condition: None
    ~HTable() {
        // Nothing to do here?
    }

    // Pre-Condition: Data of same value type as the HTable
    // Adds data to the HTable at the location given by the hash function
    // Post Condition: None
    void add(value_type givenData) {
        data[hashFunc(givenData)] = givenData;      // Assign data to array at index given by hashFunc()
    }

    // Pre-Condition: Data of the same value type as the HTable
    // Removes data from the HTable using the hash function to find its location
    // Post Condition: None
    void remove(value_type givendata) {
        data[hashFunc(givendata)] = "";
    }

    // Pre-Condition: None
    //
    // Post Condition: Returns a string representation of the HTable
    std::string toString() {
        std::string hashTableString;
        for (int i = 0; i < SIZE; i++) {            // For each element in the array
            if (data[i] != "") {                    // If contains data, append to string
                hashTableString += data[i] + " ";
            }
        }
        return hashTableString;
    }

    // Pre-Condition: A 2nd HTable
    // Adds all data from the 2nd hash table to the current HTable
    // Post Condition: None
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
    static const int SIZE = 150;
    value_type data[SIZE];

    // Pre-Condition: Data of the HTable value type
    //
    // Post Condition: Returns a int between 0 and 149
    int hashFunc(value_type givenData) { // TODO: hardcode as string?
        int addResult = 0;
        for (unsigned long int i = 0; i < givenData.length(); i++ ) { // TODO: refactor to use iterator?
            addResult += (int)givenData[i];
        }
        return  addResult % 150;
    }

};

template <typename value_type>
std::ostream& operator << (std::ostream& out, HTable<value_type>& hashTable) {
    std::string HTstring = hashTable.toString();
    out << HTstring;
    return out;
}

#endif //HTABLE_H
