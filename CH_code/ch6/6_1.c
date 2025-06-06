#include <stdio.h>
#include <stdlib.h>

// 앞의 코드 여기에 추가
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
    element array[MAX_LIST_SIZE];
    int size;
} ArrayListType;

// {오류 처리 함수 생략}

//리스트 초기화 함수
void init(ArrayListType *L) {
    L->size = 0;
}

//리스트 비어있으면 1반환. else 0반환
int is_empty(ArrayListType *L) {
    return L->size ==0;
}
int is_full(ArrayListType *L) {
    return L ->size == MAX_LIST_SIZE;
}

//element get_entry...

void print_list (ArrayListType *L) {
    int i;
    for (i=0;i<L->size;i++)
       printf("%d->", L->array[i]);
    printf("\n");
}

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void insert_last(ArrayListType *L, element item)
{
if( L->size >= MAX_LIST_SIZE ) {
error("'리스트 오버플로우");

}

L->array[L->size++] = item;
}

void insert(ArrayListType *L, int pos, element item) {

if(!is_full(L) && (pos>=0) &&(pos <= L->size)) {
for (int i = (L->size -1); i >= pos; i -- )
L->array[i +1]=L->array[i];
L->array[pos] = item;
L->size++;
   }
}

element delete(ArrayListType *L, int pos) {
element item;
if (pos < 0 || pos >= L->size)
error("위치 오류");
item = L->array[pos];
for (int i = pos; i<(L->size - 1); i++)
L->array[i]=L->array[i+1];
L->size --;
return item;
}
// ....

int main(void) {
    //ArrayListType를 정적으로 생성, ArrayListType를
    //가리키는 포인터를 함수의 매개변수로 전달.
    ArrayListType list;

    init(&list);
    insert(&list, 0, 10);   print_list(&list);
    insert(&list, 0, 20);   print_list(&list);
    insert(&list, 0, 30);   print_list(&list);
    insert_last(&list, 40); print_list(&list);
    delete(&list, 0);       print_list(&list);
    return 0;
}