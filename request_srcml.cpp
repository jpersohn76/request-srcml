/*
  @file request_srcml.cpp

  Implementation of request_srcml()
*/

#include "request_srcml.hpp"
#include "get_language_from_filename.hpp"
#include <iostream>

// extracts the filename to use from the request
std::string request_filename(const srcml_request& request) {

	std::string filename;
	
	if (request.option_filename != "")  // TEST 2
	{
		filename = request.option_filename;
		return filename;
	}
	
	if (request.entry_filename == "data")	// TEST 3 
	{	
		if (request.local_filename == "-")	// TEST 6
		{
			filename = "";
			return filename;
		}
		
		filename = request.local_filename;
		return filename;
	}
	else if (request.local_filename != "" && request.entry_filename != "") // TEST 1
	{
		filename = request.entry_filename;
		return filename;
	}
	else filename = "";	// TEST 0
	
	
    return filename;
}

// extracts the language to use from the request, and the filename
std::string request_language(const srcml_request& request, const std::string& filename) {

    std::string language;
	
	if (request.option_language == "")
		language = get_language_from_filename(filename);
	else 
		language = request.option_language;
	
	if (language == "")
		//generate_srcml(request);
	
    return language;
}

// generates srcML based on the request
void generate_srcml(const srcml_request& request) {

	std::string filename = request_filename(request);
	
	if (filename == "-")
		std::cout << "Using stdin requires a declared language" << "\n";
	
	std::string language = request_language(request, filename);
	
	if (language == "")
		std::cout << "Extension not supported" << "\n";

	// srcML generation code that is not available yet
}
