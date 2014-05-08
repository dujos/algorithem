#include "Account.h"

Account::Account(int amount) {
	if((balance - amount) > 0) {
		//other threads can run
		boost::this_thread::sleep(boost::posix_time::seconds(1));
		balance -= amount;
	}
}

void Account::withdrawn_synchronized(int amount) {
	//aquire lock on mutex. Automatically unlocked when locked is destroyed at end.
	boost::unique_lock<boost::mutex> lock(mutex);
	if((balance-amount) >= 0) {
		boost::this_thread::sleep(boost::posix_time::seconds(4));
		balance -= amount;
	} else {}
}