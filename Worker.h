#include <iostream>
#include <sstream>
#include <boost\thread.hpp>

class Worker {
public:
	Worker(int member, int power);
	Worker(const Worker& worker);
	~Worker();
	
	Worker& operator=(const Worker& source);
	void operator()();
private:
	int member;
	int power;
	int result;
};