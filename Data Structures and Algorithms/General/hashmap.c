// hashmap in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

typedef struct {
    char* key;
    int value;
} hashmap_entry;

hashmap_entry* hashmap[SIZE];

unsigned int hash(char* key) {
    unsigned int value = 0;
    for (int i = 0; i < strlen(key); i++) {
        value = value * 37 + key[i];
    }
    return value % SIZE;
}

void hashmap_put(char* key, int value) {
    unsigned int index = hash(key);
    hashmap_entry* entry = (hashmap_entry*) malloc(sizeof(hashmap_entry));
    entry->key = key;
    entry->value = value;
    hashmap[index] = entry;
}

int hashmap_get(char* key) {
    unsigned int index = hash(key);
    return hashmap[index]->value;
}

int main() 
{
    hashmap_put("key1", 7);
    hashmap_put("key2", 14);
    hashmap_put("key3", 21);

    printf("key1 value = %d\n", hashmap_get("key1"));
    printf("key2 value = %d\n", hashmap_get("key2"));
    printf("key3 value = %d\n", hashmap_get("key3"));

    return 0;
}