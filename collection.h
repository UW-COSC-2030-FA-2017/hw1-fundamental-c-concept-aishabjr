//Aisha Balogun Mohammed
//COSC 2030
//Homework 1 Part 3
//Help received from Damir Pulatov



#ifndef _COLLECTION_H
#define _COLLECTION_H
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

template<class T>class Collection {

 private:
    int size;
	int index;
    T *coll;
 public:

	Collection(int x = 7);

	~Collection();

	bool isEmpty() const; // post: true has been returned just if this Array is empty

	void makeEmpty(); 

	void insert(int x);

	bool remove(int x);

	void removeRandom();

	bool notContained(int x);

	// post: the doubles in this List have been written to
	//         outfile.
	void print();

};

//Constructor method. Size keeps track of array memory created and index is current size of the array
template <class T>
Collection<T>::Collection(int x)
{
	size = x;
	coll = new T [size];
	index = 0;
}

//Checks if an element is not contained in the array
template <class T>
bool Collection<T>::notContained(int x)
{
    for (int i=0;  i < size; i++)
    {
        if(coll[i] == x)
        {
            return false;
        }
    }
	return  true;
}

//Print method to test the Collection Class
template <class T>
void Collection<T>::print() 
{
	cout << "There are " << index << " elements in the array." << endl;
	cout << "The elememts are: ";
	for (int i = 0; i < index; i++)
	{
		cout << coll[i] << ", ";
	}
	cout << endl;
}

//Destructor 
template <class T>
Collection<T>::~Collection()
{
	delete[] coll;
}

//Checks if the array is empty and returns true if it is, and false otherwise.
template <class T>
bool Collection<T>::isEmpty() const
{
	if(index == 0)
	{
		cout<< "The array is empty." << endl;
	    return true;
	}
	else
    {
		cout<< "The array is not empty." << endl;
        return false;
    }
}

//Deletes all the elements in the array and resets the index variable to 0
//Also creates an empty array so there is no error when the destructor method is called
template <class T>
void Collection<T>::makeEmpty()
{
	delete[] coll;
	index = 0;
	cout << "All the objects in the array have been deleted." << endl;
	coll = new T [size];
}

//Inserts an object x into the array. 
//If the array already contains the maximum number of objects, 
//Double the size of the array and then copy the object.
template <class T>
void Collection<T>::insert(int x)
{
	if(index < size)
	{
		coll[index] = x;
		cout<< x << " has been inserted." << endl;
		index++;
	}
	else
	{
		size *= 2;
		T *copy = new T[size];
		for(int i = 0;i < index; i++)
		{
			copy[i] = coll[i];
		}
		delete[] coll;
		coll = copy;
		
		coll[index] = x;
		cout<< x << " has been inserted." << endl;
		index++;
	}
	
}

//Removes an object x from the array if it exists, and return false if it does not exist
template <class T>
bool Collection<T>::remove(int x)
{
    for(int i=0; i < size; i++)
    {
         if (coll[i] == x)
         {
             for(int j=i; j< size; j++)
			 {
				 coll[j] = coll[j+1];
			 }
			 cout<< x << " has been removed." << endl;
			 index--;
			 return true;
         }
    }
	cout<< x << " The object is not contained in the array." << endl;
    return false;
}

//Removes a random object from the array
template <class T>
void Collection<T>::removeRandom()
{
	srand(time(0));
	
    int random = rand() % index;
    remove(coll[random]);
}

#endif
