#include "../include/linkedlist.h"
#include <iostream>
using namespace std;
int main() {

  LinkedList l1;

  l1.add(18);
  l1.add(44);
  l1.add(29);
  l1.add(30);

    l1.find(20);
  cout << "================================================\n";
  l1.display();
  cout << "\n";

  l1.InsertAfter(25, 44);
  l1.display();
  cout << "\n";

  l1.InsertBefore(15, 44);
  l1.display();
    
  LinkedList l2;

  l2.display();
  cout<<endl;
  l2.InsertAfter(25, 20);



  cout << "\n";

  cout << "Count: " << l1.GetCount() << endl;

  cout << "Index 2: " << l1.GetDataByIndex(2) << endl;

  return 0;
}