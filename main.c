#include <stdio.h>
#include "bst.h"

int main(){
int temp = 0, count = 0;
int dataArray[100] = {0};
FILE *file;
char filename[100];


printf("Enter the filename: ");
    scanf("%s", filename);
file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file.\n");
        return 1;
    } else {
        printf("File opened successfully.\n");
    }


int i = 0;
while(i < 100 && fscanf(file, "%d", &temp) == 1 && temp != -1){
    dataArray[i] = temp;
    count++;
    i++;
}
fclose(file);
for(int i = 0; i < count; i++){
    printf("%d: %d, \n ", i, dataArray[i]);
}




bst t1 = createBST();
for(int i = 0; i < count; i++){
    insertItem(t1 ,dataArray[i]);
}
printf("Size of Array %d", size(t1));

    return 0;
}
