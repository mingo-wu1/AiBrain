#include <stdlib.h>
#include <stdio.h>

#define HASHSIZE 100
#define NULLKEY -10000

/* hash 函数 */
int hashAlgorithm(int key) {
    return key % HASHSIZE;
}

/* 哈希冲突函数，开放定址法，线性探测 */
int hashLinearProbing(int key) {
    return (key % HASHSIZE + 1) % HASHSIZE;
}

/* 哈希表 */
typedef struct HashTable {
    int *element;    
} HashTable;

/* 初始化哈希表 */
void hashInit(HashTable *hashTable) {
    int i;
    hashTable->element = (int *)malloc(sizeof(int) * HASHSIZE);
    for (i = 0; i < HASHSIZE; i++) {
        hashTable->element[i] = NULLKEY;
    }
}

/* 插入元素 */
void hashInsert(HashTable *hashTable, int key) {
 
    int addr = hashAlgorithm(key);
    while(hashTable->element[addr] != NULLKEY) {
        addr = hashLinearProbing(addr);
    }
    hashTable->element[addr] = key; /* 插入元素key */
}

/* 查找元素 */
int hashSearch(HashTable *hashTable, int key) {
    int addr = hashAlgorithm(key);
    int origin = addr;
    while(hashTable->element[addr] != NULLKEY) {
        if (hashTable->element[addr] == key) {
            return 1;
        }
        else
            addr = hashLinearProbing(addr);
        
        if(origin == hashAlgorithm(addr)) {
            return -1;
        }
    }
    return -1;
}

/* 删除元素 */
void hashDelete(HashTable *hashTable, int key) {
    int addr = hashAlgorithm(key);
    while(hashTable->element[addr] != NULLKEY) {
        if (hashTable->element[addr] == key) {
            hashTable->element[addr] = NULLKEY;
            return;
        }
        else
            addr = hashLinearProbing(addr);
    }
}

/* 销毁哈希表 */
void hashDestroy(HashTable *hashTable) {
    free(hashTable->element);
}

/* 测试 */
int main(int argc, char**argv){
    HashTable hashTable;
    hashInit(&hashTable);
    hashInsert(&hashTable, 1);
    hashInsert(&hashTable, 2);
    hashInsert(&hashTable, 3);
    hashInsert(&hashTable, 4);
    hashInsert(&hashTable, 5);
    hashInsert(&hashTable, 6);
    hashInsert(&hashTable, 7);
    hashInsert(&hashTable, 8);
    hashInsert(&hashTable, 9);
    hashInsert(&hashTable, 10);
    hashInsert(&hashTable, 11);
    hashInsert(&hashTable, 12);
    hashInsert(&hashTable, 13);
    hashInsert(&hashTable, 14);
    hashInsert(&hashTable, 15);
    hashInsert(&hashTable, 16);
    hashInsert(&hashTable, 17);
    hashInsert(&hashTable, 18);
    hashInsert(&hashTable, 19);
    hashInsert(&hashTable, 20);
    hashInsert(&hashTable, 21);
    hashInsert(&hashTable, 22);
    hashInsert(&hashTable, 23);
    hashInsert(&hashTable, 24);
    hashInsert(&hashTable, 25);
    hashInsert(&hashTable, 26);
    hashInsert(&hashTable, 27);
    hashInsert(&hashTable, 28);
    hashInsert(&hashTable, 29);
    hashInsert(&hashTable, 30);
    hashInsert(&hashTable, 31);
    hashInsert(&hashTable, 32);
    hashInsert(&hashTable, 33);
    hashInsert(&hashTable, 34);
    hashInsert(&hashTable, 35);
    hashInsert(&hashTable, 36);
    hashInsert(&hashTable, 37);
    hashInsert(&hashTable, 38);
    hashInsert(&hashTable, 39);
    hashInsert(&hashTable, 40);
    hashInsert(&hashTable, 41);
    hashInsert(&hashTable, 42);
    hashInsert(&hashTable, 43);
    hashInsert(&hashTable, 44);
    hashInsert(&hashTable, 45);
    hashInsert(&hashTable, 46);
    hashInsert(&hashTable, 47);
    hashInsert(&hashTable, 48);
    printf("%d \n", hashSearch(&hashTable, 1));
    hashDestroy(&hashTable);
}