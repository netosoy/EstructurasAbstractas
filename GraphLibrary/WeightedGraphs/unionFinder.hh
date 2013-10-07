#ifndef CLASEUF
#define CLASEUF
#include <iostream>

using namespace std;

/*!
 * \brief The union finder class
 *
 *This class maintains an array of integers id[] such that the find() method returns the same integer for every site in each connected component. The union() method must maintain this invariant.

 *
 */
class UnionFinder{
	
	int* id; /*!< access to component id */
	int count, size; /*!< number of components*/
	
public:
	 /*!
     * \brief Constructor, initialize N sites with integer names (0 to N-1)
     * \param N Number of elements
     */
	UnionFinder(int N); 
	 /*!
     * \brief Destructor
     */
	~UnionFinder();
	 /*!
     * \briefAdd connection between p and q
     */
	void Union(int p, int q); 
	 /*!
     * \briefAdd Component identifier for p(0 to N-1)
     */
	int find(int p); 	
	 /*!
     * \briefAdd Return true if p and are in the same component
     */
 	bool connected(int p, int q);
	 /*!
     * \briefAdd Return the number of components
     */
	int Count(void); 
};

#endif
