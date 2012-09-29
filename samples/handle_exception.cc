#include <iostream>
#include "../src/exception.h"

using namespace std;
using namespace raven;

int main() {
  try {
    try {
      throw Exception("A inner exception has occured");
    } catch (Exception& e) {
      throw Exception("An exception has oaccured", e);
    }
  }
  catch (Exception& e) {
    cout << e.message() << ": " << e.inner_exception()->message() << endl;
  }
  return 0;
}
