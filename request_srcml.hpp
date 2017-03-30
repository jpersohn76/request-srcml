/*
  @file request_srcml.hpp

  Header for request_srcml()
*/

#ifndef INCLUDE_REQUEST_SRCML_HPP
#define INCLUDE_REQUEST_SRCML_HPP

#include <string>

struct srcml_request {
	std::string option_filename;
	std::string local_filename;
	std::string entry_filename;
	std::string option_language;
};

// extracts the filename to use from the request
std::string request_filename(const srcml_request& request);

// extracts the language to use from the request, and the filename
std::string request_language(const srcml_request& request, const std::string& filename);

//

#endif
