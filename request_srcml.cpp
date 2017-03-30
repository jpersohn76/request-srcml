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
	}
	else 
	{
		if (request.entry_filename == "data")
				filename = request.local_filename;
			else 
				filename = "";
	}
	
	
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
