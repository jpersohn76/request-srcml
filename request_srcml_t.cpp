/*
  @file request_srcml_t.cpp

  Test program for request_srcml()
*/

#include "request_srcml.hpp"
#include <cassert>
#include <iostream>

int main() {

	// TEST 0
	// all filenames and languages empty
    {
    	srcml_request request = { "", "", "", ""};
    	assert(request_filename(request) == "");
    	assert(request_language(request, "") == "");
    }
	
	// The local_filename is the name of the file on the disk.
	// For a source-code archive (e.g., file.tar.gz, file.zip, etc.) the entry_filename is used instead.
	// TEST 1
	{
    	srcml_request request = { "", "code.tar.gz", "test.cpp", ""};
    	assert(request_filename(request) == "test.cpp");
    	assert(request_language(request, "") == "");
    }
	
	// For a plain old file, e.g., file.cpp, the entry_filename is
	// the literal string “data”, and you should use the local_filename
	// TEST 2
	{
    	srcml_request request = { "", "test.cpp", "data", ""};
    	assert(request_filename(request) == "test.cpp");
    	assert(request_language(request, "") == "");
    }
	
	// The filename can be explicitly given as an option (option_filename)
	// and this supersedes all other filenames
	// TEST 3
	{
    	srcml_request request = { "test.cpp", "test2.zip", "main.cpp", ""};
    	assert(request_filename(request) == "test.cpp");
    	assert(request_language(request, "") == "");
    }
	
	// The language is based on the file extension, 
	// e.g., .cpp and .hpp are C++ files. The function get_language_from_filename() is used for this.
	// TEST 4
	{
    	srcml_request request = { "", "test.cpp", "data", ""};
    	assert(request_filename(request) == "test.cpp");
    	assert(request_language(request, "test.cpp") == "C++");
    }
	
	// The language can be explicitly given as an option (option_language)
	// and this supersedes all other language settings
	// TEST 5
	{
    	srcml_request request = { "", "test.cpp", "data", "C++"};
    	assert(request_filename(request) == "test.cpp");
    	assert(request_language(request, "test.cpp") == "C++");
    }
	
	//	The local_filename is a single dash “-” when the input is from stdin (i.e., standard input, e.g., std::cin). In this case, the option_filename and entry_filename must be used. Note that the entry_filename is not valid (i.e, “data”) for a non source code archive, and the option_filename must be used. If the option_filename is blank (i.e., “”), then the resulting filename is blank, and the language is based on the option_language.
	//	TEST 6
	{
    	srcml_request request = { "", "-", "data", ""};
    	assert(request_filename(request) == "");
    	assert(request_language(request, "") == "");
    }

    return 0;
}
