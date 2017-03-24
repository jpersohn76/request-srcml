/*
  @file request_srcml_t.cpp

  Test program for request_srcml()
*/

#include "request_srcml.hpp"
#include <cassert>
#include <iostream>

int main() {
    //std::cout << "hi" << "\n"; 
	// all filenames and languages empty
    {
    	srcml_request request = { "", "test.cpp", "", ""};
    	assert(request_filename(request) == "test.cpp");
    	assert(request_language(request, "") == "");
    }

    return 0;
}
