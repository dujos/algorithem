#include <boost\thread.hpp>

class Account {

public:
	Account(int amount);
	void withdrawn_synchronized(int amount);

private:
	boost::mutex mutex;
	int balance;
};