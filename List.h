#ifndef LIST_H
#define LIST_H

class List {
int array_size;
double *the_array;
    public:
List();
List(int array_size);
List(int array_size, double *the_array);
List(const List & temp_list);
//void operator = (const List & temp_list);
~List();
int getSize()   const;
double* getPointer()    const;
void checkIfEmpty()   const;
void addNewElement(double n_el);
void deleteElement(int el);
double accessTheElement(int el) const;
void displayNumberOfElements()   const;
void printTheList()   const;
};
#endif
