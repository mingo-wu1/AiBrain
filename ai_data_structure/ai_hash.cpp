#include <iostream>
using namespace std;

/* hash table */
/* use open addressing double hashing */
/* use linear probing for collision resolution */
class HashTable {
    public:
        HashTable(int size){
            this->size = size;
            this->table = new int[size];
            for(int i = 0; i < size; i++){
                table[i] = -1;
            } 
        }

        ~HashTable(){
            delete[] table;
        }
        
        int Hash(int key){
            return key % size;
        }

        void Insert(int key){
            int hash_value = Hash(key);
            while(table[hash_value] != -1){
                hash_value = (hash_value % size + 1) % size;
            }
            table[hash_value] = key;
        }

        bool Find(int key){
            int hash_value = Hash(key);
            while(table[hash_value] != -1){
                if(table[hash_value] == key){
                    return true;
                }
                hash_value = (hash_value + 1) % size;
            }
            return false;
        }

        void Remove(int key){
            int hash_value = Hash(key);
            while(table[hash_value] != -1){
                if(table[hash_value] == key){
                    table[hash_value] = -1;
                    return;
                }
                hash_value = (hash_value + 1) % size;
            }
        }

        void Print(){
            for(int i = 0; i < size; i++){
                cout << table[i] << " ";
            }
            cout << endl;
        }

    private:        
        int size;
        int* table;
};

int main(int argc, char const *argv[])
{
    HashTable* hash_table = new HashTable(10);
    hash_table->Insert(1);
    hash_table->Insert(2);
    hash_table->Insert(3);
    hash_table->Insert(4);
    hash_table->Insert(5);
    hash_table->Insert(6);
    hash_table->Insert(7);
    hash_table->Insert(8);
    hash_table->Insert(9);
    hash_table->Insert(10);
    hash_table->Print();
    hash_table->Remove(1);
    hash_table->Print();
    hash_table->Remove(2);
    hash_table->Print();
    hash_table->Insert(31);
    hash_table->Print();
    cout<<hash_table->Find(31)<<endl;
    return 0;
}
