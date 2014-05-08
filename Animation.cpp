#include "Animation.h"

Animation::Animation() :
  	thread(NULL),
	frame(0),
	stop(false) {
}

Animation::Animation(const Animation& anim) {
	thread = anim.thread;
	frame = anim.frame;
	stop = anim.stop;
}

Animation::~Animation() {
	if(thread != NULL)
		delete thread;
}

void Animation::operator()() {
	bool stopping = false;
	do {
		display();
		boost::this_thread::sleep(boost::posix_time::millisec(1000));
		stop_mutex.lock();
		stopping = stop;
		stop_mutex.unlock();
	} while(stopping == false);
}

void Animation::start_animation() {
	thread = new boost::thread(boost::ref(*this));
}

void Animation::stop_animation() {
	stop_mutex.lock();
	stop = true;
	stop_mutex.unlock();

	if(thread != NULL)
		thread->join();
}

void Animation::display() {
	std::cout << " frame: " << frame++ << std::endl;
}