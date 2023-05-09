#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100 
#define MAX_NAME 50   

struct file {
    char name[MAX_NAME];
    int size;
};


struct directory {
    char name[MAX_NAME];
    struct file files[MAX_FILES];
    int num_files;
};

struct file new_file(char* name, int size) {
    struct file f;
    strncpy(f.name, name, MAX_NAME);
    f.size = size;
    return f;
}

int main() {
    
    struct directory cse;
    strncpy(cse.name, "CSE", MAX_NAME);
    cse.num_files = 0;
    
    
    cse.files[cse.num_files++] = new_file("A", 100);
    cse.files[cse.num_files++] = new_file("B", 200);
    cse.files[cse.num_files++] = new_file("C", 300);

    
    printf("Directory: %s\n", cse.name);
    printf("Number of files: %d\n", cse.num_files);
    for (int i = 0; i < cse.num_files; i++) {
        printf("File %d: %s, size = %d\n", i+1, cse.files[i].name, cse.files[i].size);
    }
    
    return 0;
}
