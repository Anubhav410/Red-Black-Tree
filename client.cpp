#include "code.h"
int main()
{
	Tree<int> tree;
 
//to demonstrate rotation

	tree.addNode(30);		
	tree.addNode(8);
	tree.addNode(37);
	tree.addNode(38);
	tree.addNode(39);
	tree.addNode(45);
	tree.addNode(15);

#if 0			//to show left rotation
tree.addNode(13);
tree.addNode(8);
tree.addNode(17);
tree.addNode(2);
tree.addNode(1);		

#endif


	tree.display();
	Tree<int>::Iterator begin = tree.begin();
	Tree<int>::Iterator end = tree.end();
	int i = 0;
#if 0
	while(begin != end)
	{
		cout<<(*begin)<<"\t";
		++begin;
	}
#endif

	return 0;
}
