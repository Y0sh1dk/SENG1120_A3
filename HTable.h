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
    // Pre-Condition:
    //
    // Post Condition:
    HTable() {
        // TODO: initalize array maybe?
    }

    // Pre-Condition:
    //
    // Post Condition:
    HTable(value_type data) {
        add(data);  // Add given data to HTable
    }

    // Pre-Condition:
    //
    // Post Condition:
    ~HTable() {
        // Nothing to do here?
    }

    // Pre-Condition:
    //
    // Post Condition:
    void add(value_type givenData) {
        data[hashFunc(givenData)] = givenData;      // Assign data to array at index given by hashFunc()
    }

    // Pre-Condition:
    //
    // Post Condition:
    void remove(value_type givendata) {
//        int index;
//        index = hashFunc(givendata);
//        data[hashFunc(givendata)] = (char)NULL;
        data[hashFunc(givendata)] = "";
    }

    // Pre-Condition:
    //
    // Post Condition:
    std::string toString() {
        std::string hashTableString;
        for (int i = 0; i < SIZE; i++) {            // For each element in the array
            if (data[i] != "") {                    // If contains data, append to string
                hashTableString += data[i] + " ";
            }
        }
        return hashTableString;
    }

    // Pre-Condition:
    //
    // Post Condition:
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

    int hashFunc(value_type givenData) { // TODO: hardcode as string?
        int addResult = 0;
        for (unsigned long int i = 0; i < givenData.length(); i++ ) { // TODO: refactor to use iterator?
            addResult += (int)givenData[i];
        }
        return  addResult % 150;
    }

};

template <typename value_type>
std::ostream& operator << (std::ostream& out, HTable<value_type> hashTable) {
    std::string HTstring = hashTable.toString();
    out << HTstring;
    return out;
}

#endif //HTABLE_H
