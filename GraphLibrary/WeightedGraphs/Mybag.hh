#ifndef CLASEBAG
#define CLASEBAG
#include <string>
#include <iostream>
#include"edge.hh"


using namespace std;
    /*!
     * \brief Linked list struct
     * \param edge Edge object and cell data
     * \param *next pointer to the next cell
     */
typedef struct S_cell{
	Edge edge;
	S_cell *next;
} T_cell;
/*! \brief Bag implementtion with linked lists to store Edge objects

A bag is a collection where removing items is not supported—its purpose is to provide clients with the ability to collect items and then to iterate through the collected items (the client can also test if a bag is empty and find its number of items). The order of iteration is unspecified and should be immaterial to the client.
*/

class MyBag{
private: 
	T_cell* first_element; /*!< First node in list.*/
	T_cell * iterator;	/*!< Current node in list.*/
	int N;	/*!< Number of bag elemnts*/
	int position; /*!< Holds the position of iterator */
public: 
    /*!
     * \brief The constructor
   
     * Sets the first element to NULL, and N to 0.
     */
	MyBag(void); 
	    /*!
     * \brief The destructor
     */
	~MyBag(void);
		  /*!
     * \brief Check if the bag has no elements
     */
	bool is_empty();
		  /*!
     * \brief Add an Edge element in the bag
          * \param Edge& Edge object to be added
     */
	void add(const Edge&);
	   /*!
     * \brief prints all edges objects in the bag
     */
	void print_EdgeBag(void);
	   /*!
     * \brief get the number of elements in the bag
     */
	int size_of(void);
	   /*!
     * \brief sets the iterator pointer to the first_element
     */
	void beginIterate();
	   /*!
     * \brief Return the Edge of the current cell, and sets the itertor to the next cell
     */
	Edge getEdge();
	   /*!
     * \brief Checks if the current element is the last
     */
	bool isEnd();
	
};

#endif
