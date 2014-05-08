#include "Composer.h"

std::string Composer::get_composer(std::vector<std::string>* pvec, int i) {
	return (*pvec)[i];
}

std::string* Composer::get_composer(std::vector<std::string>* pvec, int i, int j) {
	return &((*pvec)[i]);
}