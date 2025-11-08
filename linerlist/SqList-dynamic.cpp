#include "iostream"
#include "cstdlib"  // for malloc, realloc, free

using namespace std;

typedef int ElemType;
typedef struct {
    ElemType* data;
    int length;
    int maxSize;
} SqList;

void InitList(SqList &L) {
    L.data = (ElemType*)malloc(10 * sizeof(ElemType));  // 初始分配10个元素
    if (L.data == NULL) {
        throw runtime_error("Memory allocation failed");
    }
    L.length = 0;
    L.maxSize = 10;
}

bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    if (L.length >= L.maxSize) {
        // 扩容
        int newMaxSize = L.maxSize * 2;
        ElemType* newData = (ElemType*)realloc(L.data, newMaxSize * sizeof(ElemType));
        if (newData == NULL) {
            return false;
        }
        L.data = newData;
        L.maxSize = newMaxSize;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) {
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}

ElemType GetElem(SqList L, int i) {
    if (i < 1 || i > L.length) {
        throw out_of_range("Index out of range");
    }
    return L.data[i - 1];
}

ElemType LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (e == L.data[i]) {
            return i + 1;
        }
    }
    return -1;
}

void DestroyList(SqList &L) {
    free(L.data);
    L.data = NULL;
    L.length = 0;
    L.maxSize = 0;
}

int length(SqList L) {
    return L.length;
}

void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

bool Empty(SqList L) {
    return L.length == 0;
}

int main() {
    SqList L;
    InitList(L);
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    PrintList(L);

    ElemType e;
    ListDelete(L, 2, e);
    cout << "Deleted element: " << e << endl;
    PrintList(L);

    cout << "Element at position 2: " << GetElem(L, 2) << endl;
    cout << "Position of element 10: " << LocateElem(L, 10) << endl;

    cout << "Length of list: " << length(L) << endl;
    cout << "Is list empty? " << (Empty(L) ? "Yes" : "No") << endl;

    DestroyList(L);
    cout << "List destroyed. Is list empty? " << (Empty(L) ? "Yes" : "No") << endl;

    return 0;
}