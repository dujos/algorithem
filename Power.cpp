#include "Power.h"
#include <boost\thread.hpp>

Power::Power(int m, int n) :
  m(m),
  n(n) {
	result = 0.0f;
}

Power::Power(const Power& power) {}

void Power::operator()() {
	result = m;
	for(int i = 1; i < n; i++) {
		result *= m;
		boost::this_thread::yield();
		if(n==0)
			result = 1;
	}
}
