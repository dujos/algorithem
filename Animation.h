#include <boost\thread.hpp>

class Animation {

private:
	boost::thread* thread;
	int frame;

	bool stop;
	boost::mutex stop_mutex;

public:
	Animation();
	Animation(const Animation& anim);
	~Animation();
	
	void operator()();

	void start_animation();
	void stop_animation();
	void display();
};