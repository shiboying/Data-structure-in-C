#include "linkedlist.h"

int main(int argc, const char * argv[]){
    linkedlist list;
    Initial_linkedlist(&list);
    int i;
    for(i=1; i<=5; i++)
        Insert_linkedlist(list, i, i);
    print_list(list);
    Clear_linkedlist(&list);
    print_list(list);
    for(i=1; i<=10;i++)
        Insert_linkedlist(list, i, i);
    print_list(list);
}
