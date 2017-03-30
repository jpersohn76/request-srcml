/*
  @file request_srcml.cpp

  Implementation of request_srcml()
*/

#include "request_srcml.hpp"
#include "get_language_from_filename.hpp"

// extracts the filename to use from the request
std::string request_filename(const srcml_request& request) {

	std::string filename;
	
	if (request.option_filename != "") 
	{
		filename = request.option_filename;
		return filename;
	}
	
	if (request.entry_filename == "data")	// TEST 3 
	{	
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
	
    return language;
}

// generates srcML based on the request
void generate_srcml(const srcml_request& request) {

	std::string filename = request_filename(request);

	std::string language = request_language(request, filename);

	// srcML generation code that is not available yet
}
