//
// Created by Yosiah on 24/10/2020.
//

#include <iostream>
#include <string>

#ifndef SENG1120_A3_HTABLE_H
#define SENG1120_A3_HTABLE_H

template <typename value_type>
class HTable {
public:
    HTable() {

    }

    HTable(value_type data) {
        add(data);
    }

    ~HTable() {

    }

    void add(value_type givenData) {
        data[hashFunc(givenData)] = givenData;
    }

    void remove(value_type data) {
        int index;
        index = hashFunc(data);
        data[index] = NULL;
    }

    std::string toString() { // TODO: Maybe make private?
        std::string hashTableString;
        for (int i = 0; i < SIZE; i++) {
            if (data[i] != "") {
                hashTableString += data[i] + " ";
            }
        }
        return hashTableString;
    }

    void operator += (HTable& HTable2) {
        std::string HTable2String;
        HTable2String = HTable2.toString();
        int pos = -1;
        for (unsigned long int i = 0; i <= HTable2String.length(); i++) {
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
        for (int i = 0; i < givenData.length(); i++ ) {
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

#endif //SENG1120_A3_HTABLE_H
