#include "List.h"

#include <iostream>

List::List() {
    array_size = 0;
    the_array = new double[array_size];
}
List::List(int array_size) {
    this->array_size = array_size;
    the_array = new double[array_size];
    for (int i=0; i<array_size; i++) {
        the_array[i] = 1.0;
}
List::List(int array_size, double *the_array) {
    this->array_size = array_size;
    this->the_array = new double[array_size];
    for (int i=0; i<array_size; i++)
        this->the_array[i] = the_array[i];
}
List::List(const List & list) {
    array_size = list.getSize();
    the_array = new double[array_size];
    for (int i = 0; i < array_size; i++)
        the_array[i] = list.getPointer()[i];
}
/*void List::operator = (const List & list) {
    array_size = list.getSize();
    the_array = new double[array_size];
    for (int i=0; i < array_size; i++)
        the_array[i] = list.getPointer()[i];
}*/
List::~List() {
    delete[] the_array;
}
int List::getSize() const{
    return array_size;
}
double* List::getPointer() const{
    return the_array;
}
void List::checkIfEmpty() const {
    if (array_size == 0)
        std::cout<<"This list is empty.\n";
    else std::cout<<"This list is not empty.\n";
}
void List::addNewElement(double n_el) {
    array_size++;
    double *temp = new double[array_size];
    for (int i = 0; i < array_size; i++) {
        temp[i] = the_array[i];
    }
    temp[array_size-1] = n_el;
    delete[] the_array;
    the_array = temp;
}
void List::deleteElement(int el) {
    if (el < 0 or el > getSize() - 1) return;
    array_size--;
    double *temp = new double[getSize()];
    for (int i = 0; i < getSize(); i++) {
        if (i < el) temp[i] = the_array[i];
            else temp[i] = the_array[i+1];
    }
        delete[] the_array;
        the_array = temp;
}
void List::insertElement(double el, int pos) {
    if (pos < 0 or pos > getSize() - 1) return;
    array_size++;
    double *temp = new double[getSize()];
    for (int i = 0; i < getSize(); i++) {
        if (i < pos) temp[i] = the_array[i];
        if (i == pos) temp[i] = el;
        if (i > pos) temp[i] = the_array[i-1];
    }
    delete[] the_array;
    the_array = temp;
}
double List::accessTheElement(int el) const{
   return the_array[el];
}
void List::printTheList() const{

    for (int i = 0; i < getSize(); i++)
        std::cout<<accessTheElement(i)<<std::endl;
}
void List::displayNumberOfElements() const{
std::cout<<"\nNumber of elements: "<<getSize();
}


