
// DEVELOPED BY ZENIL RAYMA 

// PROGRAM FOR SORTING DATA

/* THIS PROGRAM WILL SORT DATA USING SORTING ALGORITHM SUCH AS

   MERGE SORT
   QUICK SORT
   HEAP SORT
*/    

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Algorithm_selection();
void Heap_sort();
void Quik_sort();
void Merge_sort();
void All();

// Merge Sort function
void merge(void *arr, int l, int m, int r, int order, int dataType) {

    int i, j, k;

    if (dataType == 0) {  // logic for ineger input

        int *intArr = (int *)arr;
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[n1], R[n2];

        for (i = 0; i < n1; i++)
            L[i] = intArr[l + i];

        for (j = 0; j < n2; j++)
            R[j] = intArr[m + 1 + j];

        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2) {

            if (order == 1) {

                if (L[i] <= R[j])
                    intArr[k] = L[i++];
                else
                    intArr[k] = R[j++];

            } else if (order == 2) {

                if (L[i] >= R[j])
                    intArr[k] = L[i++];
                else
                    intArr[k] = R[j++];
            }

            k++;
        }
        while (i < n1)
            intArr[k++] = L[i++];
        while (j < n2)
            intArr[k++] = R[j++]; 

    } else if (dataType == 1) {  // logic for character input

        char *charArr = (char *)arr;
        int n1 = m - l + 1;
        int n2 = r - m;
        char L[n1], R[n2];

        for (i = 0; i < n1; i++)
            L[i] = charArr[l + i];

        for (j = 0; j < n2; j++)
            R[j] = charArr[m + 1 + j];

        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2) {

            if (order == 1) {
                if (L[i] <= R[j])
                    charArr[k] = L[i++];
                else
                    charArr[k] = R[j++];
            } else if (order == 2) {

                if (L[i] >= R[j])
                    charArr[k] = L[i++];
                else
                    charArr[k] = R[j++];
            }

            k++;
        }
        while (i < n1)
            charArr[k++] = L[i++];
        while (j < n2)
            charArr[k++] = R[j++];

    } else if (dataType == 2) {  // logic for string input 

        char (*strArr)[100] = (char (*)[100])arr;
        int n1 = m - l + 1;
        int n2 = r - m;
        char L[n1][100], R[n2][100];
        for (i = 0; i < n1; i++)
            strcpy(L[i], strArr[l + i]);
        for (j = 0; j < n2; j++)
            strcpy(R[j], strArr[m + 1 + j]);
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2) {
            if (order == 1) {
                if (strcmp(L[i], R[j]) <= 0)
                    strcpy(strArr[k], L[i++]);
                else
                    strcpy(strArr[k], R[j++]);
            } else if (order == 2) {
                if (strcmp(L[i], R[j]) >= 0)
                    strcpy(strArr[k], L[i++]);
                else
                    strcpy(strArr[k], R[j++]);
            }
            k++;
        }
        while (i < n1)
            strcpy(strArr[k++], L[i++]);
        while (j < n2)
            strcpy(strArr[k++], R[j++]);
    }
}

void mergeSort(void *arr, int l, int r, int order, int dataType) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge(arr, l, m, r, order, dataType);
        mergeSort(arr, l, m, order, dataType);
        mergeSort(arr, m + 1, r, order, dataType);
        merge(arr, l, m, r, order, dataType);
    }
}

int partition(void *arr, int low, int high, int order, int dataType) {
    if (dataType == 0) { // 

        int *intArr = (int *)arr;
        int pivot = intArr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (order == 1) {
                if (intArr[j] < pivot) {
                    i++;
                    int temp = intArr[i];
                    intArr[i] = intArr[j];
                    intArr[j] = temp;
                }
            } else if (order == 2) {
                if (intArr[j] > pivot) {
                    i++;
                    int temp = intArr[i];
                    intArr[i] = intArr[j];
                    intArr[j] = temp;
                }
            }
        }
        int temp = intArr[i + 1];
        intArr[i + 1] = intArr[high];
        intArr[high] = temp;
        return (i + 1);
    } else if (dataType == 1) {
        char *charArr = (char *)arr;
        char pivot = charArr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (order == 1) {
                if (charArr[j] < pivot) {
                    i++;
                    char temp = charArr[i];
                    charArr[i] = charArr[j];
                    charArr[j] = temp;
                }
            } else if (order == 2) {
                if (charArr[j] > pivot) {
                    i++;
                    char temp = charArr[i];
                    charArr[i] = charArr[j];
                    charArr[j] = temp;
                }
            }
        }
        char temp = charArr[i + 1];
        charArr[i + 1] = charArr[high];
        charArr[high] = temp;
        return (i + 1);
    } else if (dataType == 2) {
        char (*strArr)[100] = (char (*)[100])arr;
        char pivot[100];
        strcpy(pivot, strArr[high]);
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (order == 1) {
                if (strcmp(strArr[j], pivot) < 0) {
                    i++;
                    char temp[100];
                    strcpy(temp, strArr[i]);
                    strcpy(strArr[i], strArr[j]);
                    strcpy(strArr[j], temp);
                }
            } else if (order == 2) {
                if (strcmp(strArr[j], pivot) > 0) {
                    i++;
                    char temp[100];
                    strcpy(temp, strArr[i]);
                    strcpy(strArr[i], strArr[j]);
                    strcpy(strArr[j], temp);
                }
            }
        }
        char temp[100];
        strcpy(temp, strArr[i + 1]);
        strcpy(strArr[i + 1], strArr[high]);
        strcpy(strArr[high], temp);
        return (i + 1);
    }
}

void quickSort(void *arr, int low, int high, int order, int dataType) {
    if (low < high) {
        int pi = partition(arr, low, high, order, dataType);
        quickSort(arr, low, pi - 1, order, dataType);
        quickSort(arr, pi + 1, high, order, dataType);
    }
}

void Swap(void *arr, int a, int b, int dataType) {
    if (dataType == 0) {
        int *intArr = (int *)arr;
        int temp = intArr[a];
        intArr[a] = intArr[b];
        intArr[b] = temp;
    } else if (dataType == 1) {
        char *charArr = (char *)arr;
        char temp = charArr[a];
        charArr[a] = charArr[b];
        charArr[b] = temp;
    } else if (dataType == 2) {
        char (*strArr)[100] = (char (*)[100])arr;
        char temp[100];
        strcpy(temp, strArr[a]);
        strcpy(strArr[a], strArr[b]);
        strcpy(strArr[b], temp);
    }
}

void Heapify(void *arr, int n, int i, int order, int dataType) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (dataType == 0) {
        int *intArr = (int *)arr;
        if (order == 1) {
            if (left < n && intArr[left] > intArr[largest])
                largest = left;
            if (right < n && intArr[right] > intArr[largest])
                largest = right;
        } else if (order == 2) {
            if (left < n && intArr[left] < intArr[largest])
                largest = left;
            if (right < n && intArr[right] < intArr[largest])
                largest = right;
        }
    } else if (dataType == 1) {
        char *charArr = (char *)arr;
        if (order == 1) {
            if (left < n && charArr[left] > charArr[largest])
                largest = left;
            if (right < n && charArr[right] > charArr[largest])
                largest = right;
        } else if (order == 2) {
            if (left < n && charArr[left] < charArr[largest])
                largest = left;
            if (right < n && charArr[right] < charArr[largest])
                largest = right;
        }
    } else if (dataType == 2) {
        char (*strArr)[100] = (char (*)[100])arr;
        if (order == 1) {
            if (left < n && strcmp(strArr[left], strArr[largest]) > 0)
                largest = left;
            if (right < n && strcmp(strArr[right], strArr[largest]) > 0)
                largest = right;
        } else if (order == 2) {
            if (left < n && strcmp(strArr[left], strArr[largest]) < 0)
                largest = left;
            if (right < n && strcmp(strArr[right], strArr[largest]) < 0)
                largest = right;
        }
    }

    if (largest != i) {
        Swap(arr, i, largest, dataType);
        Heapify(arr, n, largest, order, dataType);
    }
}

void HeapSort(void *arr, int n, int order, int dataType) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i, order, dataType);
    for (int i = n - 1; i > 0; i--) {
        Swap(arr, 0, i, dataType);
        Heapify(arr, i, 0, order, dataType);
    }
}

int main()
{
    printf("\n\nWELCOME TO THE SORTING ALGORITHMS PROJECT!\n\n");
    printf("Sorting is a fundamental concept in computer science.\n");
    printf("It involves arranging a list of elements in a specific order.\n");
    printf("This project explores three popular sorting algorithms: Merge Sort, Quick Sort, and Heap Sort.\n");

    printf("\nABOUT THIS PROGRAM:\n\n");
    printf("You can input data of three types: integer, character, or string.\n");
    printf("Choose the sorting order (ascending or descending) and an algorithm to sort your data.\n");
    printf("You can also compare the performance of all three algorithms on the same data.\n\n");

    Algorithm_selection();

    return 0;
}

void Algorithm_selection()
{
    int choice;

list:
    printf("\n*** LIST OF ALGORITHMS ***\n\n\n");
    printf("1. Merge sort\n");
    printf("2. Quick sort\n");
    printf("3. Heap sort\n");
    printf("4. All together\n");
    printf("5. Exit");
    printf("\n\nEnter your choice : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            Merge_sort();
            break;
        case 2:
            Quik_sort();
            break;
        case 3:
            Heap_sort();
            break;
        case 4:
            All();
            break;
        case 5:
            printf("\n\nExiting the program ......\nDONE.\n\n");
            break;
        default:
            printf("\nInvalid choice,  try again... \n choose from 1 to 5\n");
            goto list;
            break;
    }
}

void Merge_sort()
{
    int choice2;
    int order; // Variable to store the sorting order (1 for ascending, 2 for descending)
    int dataType;

options:
    printf("\n\n ** SELECT TYPE OF INPUT DATA **\n\n");
    printf("\n0. integer\n");
    printf("1. character\n");
    printf("2. string\n");
    printf("3. Exit\n");

    printf("\nYour choice : ");
    scanf("%d", &choice2);

     if (choice2 == 3) { // CHOICE OF EXIT
        printf("\n\nExiting the program ......\nDONE.\n\n");
        exit(0);
     }
    printing:
    printf("\n* Select sorting order *\n\n");
    printf("1. Ascending\n");
    printf("2. Descending\n\n");
    printf("Your choice: ");
    scanf("%d", &order);

    if(order != 1 && order != 2 ){ // FOR INVALID CHOICE

        printf("\nInvalid choice of order , try again ....\n");
        goto printing;
    }

    if (choice2 == 0) { // FOR CHOICE OF INTEGER 
        int I_data[100];
        int size;

        printf("\nEnter number of elements : ");
        scanf("%d", &size);
        printf("\n");

        printf("Enter %d values to sort :\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &I_data[i]);
            printf("You have entered '%d'\n", I_data[i]);
            printf("\n");
        }

        dataType = 0;

        // Call the Merge Sort function with the specified order
        mergeSort(I_data, 0, size - 1, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", I_data[i]);
        }
        printf("\n");
    } else if (choice2 == 1) { // FOR CHOICE OF CHARACTER
        char C_data[100];
        int size;

        printf("\nEnter number of elements : ");
        scanf("%d", &size);
        printf("\n");

        printf("Enter %d characters to sort :\n", size);
        for (int i = 0; i < size; i++) {
            scanf(" %c", &C_data[i]);
            printf("You have entered '%c'\n", C_data[i]);
            printf("\n");
        }

        dataType = 1;

        // Call the Merge Sort function with the specified order
        mergeSort(C_data, 0, size - 1, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%c ", C_data[i]);
        }
        printf("\n");
    } else if (choice2 == 2) { // CHOICE OF STRING
        char S_data[100][100];
        int size;

        printf("\nEnter number of elements : ");
        scanf("%d", &size);
        printf("\n");

        printf("Enter %d strings to sort :\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%s", S_data[i]);
            printf("You have entered '%s'\n", S_data[i]);
            printf("\n");
        }

        dataType = 2;

        // Call the Merge Sort function with the specified order
        mergeSort(S_data, 0, size - 1, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%s ", S_data[i]);
        }
        printf("\n");
    } // else if (choice2 == 3) { // CHOICE OF EXIT
     //   printf("\n\nExiting the program ......\nDONE.\n\n");
       // exit(0); }
     else { // FOR INVALID CHOICE
        printf("Invalid choice of data type , try again...\n");
        goto options;
    }

    Algorithm_selection();
}

void Quik_sort()
{
    int choice3;
    int order; // Variable to store the sorting order (1 for ascending, 2 for descending)
    int dataType;

options:
    printf("\n\n ** SELECT TYPE OF INPUT DATA **\n\n");
    printf("\n0. integer\n");
    printf("1. character\n");
    printf("2. string\n");
    printf("3. Exit\n");

    printf("\nYour choice : ");
    scanf("%d", &choice3);

     if (choice3 == 3) { // FOR EXIT CHOICE
        printf("\n\nExiting the program ......\nDONE.\n\n");
        exit(0);
     }

    printing:
    printf("\n* Select sorting order *\n\n");
    printf("1. Ascending\n");
    printf("2. Descending\n\n");
    printf("Your choice: ");
    scanf("%d", &order);

    if(order != 1 && order != 2 ){ // FOR INVALID CHOICE

        printf("\nInvalid choice of order , try again ....\n");
        goto printing;
    }

    if (choice3 == 0) { // FOR INTEGER 
        int I_data[100];
        int size;

        printf("\nEnter number of elements : ");
        scanf("%d", &size);
        printf("\n");

        printf("Enter %d values to sort :\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &I_data[i]);
            printf("You have entered '%d'\n", I_data[i]);
            printf("\n");
        }

        dataType = 0;

        // Call the Quick Sort function with the specified order
        quickSort(I_data, 0, size - 1, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", I_data[i]);
        }
        printf("\n");
    } else if (choice3 == 1) { // FOR CHARACTER
        char C_data[100];
        int size;

        printf("\nEnter number of elements : ");
        scanf("%d", &size);
        printf("\n");

        printf("Enter %d characters to sort :\n", size);
        for (int i = 0; i < size; i++) {
            scanf(" %c", &C_data[i]);
            printf("You have entered '%c'\n", C_data[i]);
            printf("\n");
        }

        dataType = 1;

        // Call the Quick Sort function with the specified order
        quickSort(C_data, 0, size - 1, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%c ", C_data[i]);
        }
        printf("\n");
    } else if (choice3 == 2) { // FOR STRING 
        char S_data[100][100];
        int size;

        printf("\nEnter number of elements : ");
        scanf("%d", &size);
        printf("\n");

        printf("Enter %d strings to sort :\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%s", S_data[i]);
            printf("You have entered '%s'\n", S_data[i]);
            printf("\n");
        }

        dataType = 2;

        // Call the Quick Sort function with the specified order
        quickSort(S_data, 0, size - 1, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%s ", S_data[i]);
        }
        printf("\n");
    } //else if (choice3 == 3) {
       // printf("\n\nExiting the program ......\nDONE.\n\n");
        //exit(0);
    else { // FOR INVALID CHOICE
        printf("Invalid choice of data type , try again.\n");
        goto options;
    }

    Algorithm_selection();
}

void Heap_sort()
{
    int choice4;
    int order; // Variable to store the sorting order (1 for ascending, 2 for descending)
    int dataType;

options:
    printf("\n\n ** SELECT TYPE OF INPUT DATA **\n\n");
    printf("\n0. integer\n");
    printf("1. character\n");
    printf("2. string\n");
    printf("3. Exit\n");

    printf("\nYour choice : ");
    scanf("%d", &choice4);

     if (choice4 == 3) {
        printf("\n\nExiting the program ......\nDONE.\n\n");
        exit(0); }
    
    printing:
    printf("\n* Select sorting order *\n\n");
    printf("1. Ascending\n");
    printf("2. Descending\n\n");
    printf("Your choice: ");
    scanf("%d", &order);

    if(order != 1 && order != 2 ){ // FOR INVALID CHOICE

        printf("\nInvalid choice of order , try again ....\n");
        goto printing;
    }

    if (choice4 == 0) { // FOR CHOICE OF INTEGER
        int I_data[100];
        int size;

        printf("\nEnter number of elements : ");
        scanf("%d", &size);
        printf("\n");

        printf("Enter %d values to sort :\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &I_data[i]);
            printf("You have entered '%d'\n", I_data[i]);
            printf("\n");
        }

        dataType = 0;

        // Call the Heap Sort function with the specified order
        HeapSort(I_data, size, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", I_data[i]);
        }
        printf("\n");
    } else if (choice4 == 1) {  // FOR CHOICE OF CHARACTER
        char C_data[100];
        int size;

        printf("\nEnter number of elements : ");
        scanf("%d", &size);
        printf("\n");

        printf("Enter %d characters to sort :\n", size);
        for (int i = 0; i < size; i++) {
            scanf(" %c", &C_data[i]);
            printf("You have entered '%c'\n", C_data[i]);
            printf("\n");
        }

        dataType = 1;

        // Call the Heap Sort function with the specified order
        HeapSort(C_data, size, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%c ", C_data[i]);
        }
        printf("\n");
    } else if (choice4 == 2) { // FOR CHOICE OF STRING 
        char S_data[100][100];
        int size;

        printf("\nEnter number of elements : ");
        scanf("%d", &size);
        printf("\n");

        printf("Enter %d strings to sort :\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%s", S_data[i]);
            printf("You have entered '%s'\n", S_data[i]);
            printf("\n");
        }

        dataType = 2;

        // Call the Heap Sort function with the specified order
        HeapSort(S_data, size, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%s ", S_data[i]);
        }
        printf("\n");
    }// else if (choice4 == 3) {
       // printf("\n\nExiting the program ......\nDONE.\n\n");
        //exit(0);
      else {   // FOR INVALID CHOICE
        printf("Invalid choice of data type , try again...\n");
        goto options;
    }

    Algorithm_selection();
}

void All()
{
    int choice5;
    int order; // Variable to store the sorting order (1 for ascending, 2 for descending)
    int dataType;

options:
    printf("\n\n ** SELECT TYPE OF INPUT DATA **\n\n");
    printf("\n0. integer\n");
    printf("1. character\n");
    printf("2. string\n");
    printf("3. Exit\n");

    printf("\nYour choice : ");
    scanf("%d", &choice5);

    if (choice5 == 3) { // CHOICE OF EXIT

        printf("\n\nExiting the program ......\nDONE.\n\n");
        exit(0);
    }

    printing:
    printf("\n* Select sorting order*\n\n");
    printf("1. Ascending\n");
    printf("2. Descending\n\n");
    printf("Your choice: ");
    scanf("%d", &order);

    if(order != 1 && order != 2 ){ // FOR INVALID CHOICE

        printf("\nInvalid choice of order , try again ....\n");
        goto printing;
    }

    if (choice5 == 0) { //  FOR CHOICE OF INTEGER 
        int I_data[100];
        int size;

        printf("\nEnter number of elements : ");
        scanf("%d", &size);
        printf("\n");

        printf("Enter %d values to sort :\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &I_data[i]);
            printf("You have entered '%d'\n", I_data[i]);
            printf("\n");
        }

        dataType = 0;

        // Call the Merge Sort function with the specified order

        printf("\nSorting using Merge Sort:\n");
        mergeSort(I_data, 0, size - 1, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", I_data[i]);
        }
        printf("\n");

        // Call the Quick Sort function with the specified order

        printf("\nSorting using Quick Sort:\n");
        quickSort(I_data, 0, size - 1, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", I_data[i]);
        }
        printf("\n");

        // Call the Heap Sort function with the specified order

        printf("\nSorting using Heap Sort:\n");
        HeapSort(I_data, size, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", I_data[i]);
        }
        printf("\n");
    } else if (choice5 == 1) { // FOR CHOICE OF CHARACTER
        char C_data[100];
        int size;

        printf("\nEnter number of elements : ");
        scanf("%d", &size);
        printf("\n");

        printf("Enter %d characters to sort :\n", size);
        for (int i = 0; i < size; i++) {
            scanf(" %c", &C_data[i]);
            printf("You have entered '%c'\n", C_data[i]);
            printf("\n");
        }

        dataType = 1;

        // Call the Merge Sort function with the specified order

        printf("\nSorting using Merge Sort:\n");
        mergeSort(C_data, 0, size - 1, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%c ", C_data[i]);
        }
        printf("\n");

        // Call the Quick Sort function with the specified order

        printf("\nSorting using Quick Sort:\n");
        quickSort(C_data, 0, size - 1, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%c ", C_data[i]);
        }
        printf("\n");

        // Call the Heap Sort function with the specified order

        printf("\nSorting using Heap Sort:\n");
        HeapSort(C_data, size, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%c ", C_data[i]);
        }
        printf("\n");
    } else if (choice5 == 2) {  // FOR CHOICE OF STRING
        char S_data[100][100];
        int size;

        printf("\nEnter number of elements : ");
        scanf("%d", &size);
        printf("\n");

        printf("Enter %d strings to sort :\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%s", S_data[i]);
            printf("You have entered '%s'\n", S_data[i]);
            printf("\n");
        }

        dataType = 2;

        // Call the Merge Sort function with the specified order

        printf("\nSorting using Merge Sort:\n");
        mergeSort(S_data, 0, size - 1, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%s ", S_data[i]);
        }
        printf("\n");

        // Call the Quick Sort function with the specified order

        printf("\nSorting using Quick Sort:\n");
        quickSort(S_data, 0, size - 1, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%s ", S_data[i]);
        }
        printf("\n");

        // Call the Heap Sort function with the specified order

        printf("\nSorting using Heap Sort:\n");
        HeapSort(S_data, size, order, dataType);

        // Display the sorted array based on the order
        printf("\nSorted data: ");
        for (int i = 0; i < size; i++) {
            printf("%s ", S_data[i]);
        }
        printf("\n");
    } //else if (choice5 == 3) { // CHOICE OF EXIT

      //   printf("\n\nExiting the program ......\nDONE.\n\n");
     // exit(0);
    // }
      else { // FOR INVALID CHOICE

        printf("Invalid choice of data type , try again.\n");
        goto options;
    }

    Algorithm_selection();
}
