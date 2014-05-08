#include "Worker.h"

Worker::Worker(int m, int n) :
  member(m),
  power(n),
  result(0) {
}

Worker::Worker(const Worker& worker) {
	member = worker.member;
	power = worker.power;
}

Worker::~Worker() {}

void Worker::operator()() {
	result = member;
	for(int i = 1; i < power; i++) {
		result *= member;
		boost::this_thread::yield();
	}

	if(power == 0)
		result = 1;
}