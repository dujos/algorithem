#include "Withdrawl.h"
#include <boost\thread.hpp>

Withdrawl::Withdrawl(int amount) {
	if((balance - amount) > 0) {
		//other threads can run
		boost::this_thread::sleep(boost::posix_time::seconds(1));
		balance -= amount;
	}
}

void Withdrawl::withdrawl_synchronized(int amount) {
	//lock on mutex, if already locked wait till unlocked.
}