/** Tester
 *  
 */

#include "load_npy.h"

#include <exception>
#include <fstream>
#include <iostream>
using std::cout;
using std::endl;

// Make this a bit more portable
#include <cstdint>

template <typename T>
void do_test(std::string filename, const char *format)
{
	cout << "Trying filename: " << filename << endl;
	try {
		struct point { T x,y; };
		auto buffer = load_numpy_structured_rows<point>(filename, 2, format);
		for (auto row : buffer) {
			cout << row.x << ", " << row.y << endl;
		}
	}
	catch ( const std::exception& e )
	{
		cout << "Exception: " << e.what() << endl;
	}
}

int main()
{
	do_test<int32_t>("int32.npy", "i4");
	do_test<int64_t>("int64.npy", "i8");
	do_test<float>("float32.npy", "f4");
	do_test<double>("double64.npy", "f8");
}
