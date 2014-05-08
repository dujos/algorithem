#include <vector>
#include <string>

class Composer {

public:
	std::string get_composer(std::vector<std::string>* pvec, int i);

	std::string* get_composer(std::vector<std::string>* pvec, int i, int j);
};