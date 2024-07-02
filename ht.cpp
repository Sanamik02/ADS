#include <iostream>
#include <vector>
#include <list>

using namespace std;


class HashTable {
private:
    vector<list<int>> table;  
    int size;  

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size); 
    }

    void insert(int key) {
        int index = hashFunction(key);  

        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                cout << "Element " << key << " already exists in the hash table." << endl;
                return;
            }
        }

        table[index].push_back(key);
        cout << "Element " << key << " inserted into the hash table." << endl;
    }

    void remove(int key) {
        int index = hashFunction(key); 
     
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                table[index].erase(it); 
                cout << "Element " << key << " removed from the hash table." << endl;
                return;
            }
        }

        cout << "Element " << key << " not found in the hash table." << endl;
    }

    bool search(int key) {
        int index = hashFunction(key);  
     
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == key) {
                cout << "Element " << key << " found in the hash table." << endl;
                return true;
            }
        }

        cout << "Element " << key << " not found in the hash table." << endl;
        return false;
    }
};

int main() {
  
    HashTable ht(10);

    ht.insert(5);
    ht.insert(15);
    ht.insert(25);

    ht.search(15);
    ht.search(35);

    ht.remove(15);
    ht.remove(35);

    return 0;
}