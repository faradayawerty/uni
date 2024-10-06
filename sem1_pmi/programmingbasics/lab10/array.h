// 1 - чтение элементов массива с клавиатуры
int *inputArr(int);

// 2 - запалнение массива с помощью случайных чисел
int *randArr(int, int, int);

// 3 - вывод элементов массива на экран
void printArr(int *, int);

// 4 - найти индекс элемента
int findIndex(int *, int, int);

// 5 - индекс минимального/максимального элемента
int findMin(int *, int);
int findMax(int *, int);

// 6 - индекс минимального/максимального элемента, удовлетворяющего условию
int findMinCond(int *, int, bool (*)(int));
int findMaxCond(int *, int, bool (*)(int));

