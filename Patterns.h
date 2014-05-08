#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <time.h>
#include <sys\types.h>
#include <sys\timeb.h>

/*
 * Singleton pattern limits the instantiation of a class to one object;
 */
class Singleton {

public:
	static Singleton* get_singleton();

private:
	Singleton();
	~Singleton();
	Singleton(const Singleton&);
	const Singleton& operator=(const Singleton&);

private:
	static Singleton* instance;
};

/*
 * The strategy pattern is intended to provide a means to define a family of algorithms, 
 * encapsulate each one as an object, and make them interchangeable;
 */

class Sort {
public:
	virtual void sort() const = 0;
};

class Merge : public Sort {
public:
	virtual void sort() const {
		std::cout << "Merge sort" << std::endl;
	}
};

class Quick : public Sort {
	virtual void sort() const {
		std::cout << "Quick sort" << std::endl;
	}
};

class Search {
public:
	virtual void search() const = 0;
};

class BinaryTree : public Search {
	virtual void search() const {
		std::cout << "binary tree search" << std::endl;
	}
};

class HashMap : public Search {
	virtual void search() const {
		std::cout << "hash map search" << std::endl;
	}
};

class Strategy {

private:
	Sort* msort;
	Search* msearch;

public:
	Strategy() {};

	void set_sort(Sort* sort) { this->msort = sort; }
	void set_search(Search* search) { this->msearch = search; }

	void sorting() const { msort->sort(); }
	void searching() const { msearch->search(); }
};

/*
 * Observer Pattern is to define a one-to-many dependency between objects 
 * so that when one object changes state, all its dependents are notified and 
 * updated automatically.
 */
class Subject;

class Observer {
public:
	Observer() {};
	~Observer() {};

	virtual void update(Subject* subject) = 0;
};

class Subject {
public:
	Subject();
	virtual ~Subject();
	
	virtual void attach(Observer* );
	virtual void dettach(Observer* );
	virtual void notify();

private:
	std::vector<Observer*> observers;
};

class ClockTime : public Subject {

public:
	ClockTime();
	int get_hours();
	int get_minutes();
	int get_seconds();

	void tick();

private:
	char temp[128];
};

class AnalogClock : public Observer {

public:
	AnalogClock(ClockTime* analog_clock);
	~AnalogClock();

	void update(Subject* );
	void draw();

private:
	ClockTime* analog_clock;
};

class DigitalClock : public Observer {

public:
	DigitalClock(ClockTime* );
	~DigitalClock();

	void update(Subject* );
	void draw();

private:
	ClockTime* digital_clock;
};

/*
 * In Factory Method client doesn't know the concrete class. 
 * Client wants to create an object from abstract class. 
 * But the subclass decides which class to instantiate. 
 * This allows us to defer the instantiation to the subclass. 
 * The client doesn't know which subclass or concrete class is used to create the object.
 */

class Button {
public:
	virtual void draw() = 0;
private:
	char button_name[128];
};

class AndroidButton : public Button {
public:
	void draw() { std::cout << "android button" << std::endl; }
};

class AppleButton : public Button {
public:
	void draw() { std::cout << "apple button" << std::endl; }
};

class WindowsButton : public Button {
public:
	void draw() { std::cout << "windows button" << std::endl; }
};

class GUIFactory {

public:
	virtual Button* create_button(char* button_type) = 0;
};

class Factory : public GUIFactory {

public:
	Button* create_button(char* type) {
		if(std::strcmp(type, "windows") == 0)
			return new WindowsButton;
		if(std::strcmp(type, "android") == 0)
			return new AndroidButton;
		if(std::strcmp(type, "apple") == 0)
			return new AppleButton;
		return NULL;
	}
};

class Shape {
public:
	~Shape() {}
	virtual void draw() const = 0;
	virtual void add(Shape* ) {};
};

class Rectangle : public Shape {
public:
	void draw() const { std::cout << "rectangle" << std::endl; }
};

class Circle : public Shape {
public:
	void draw() const { std::cout << "circle" << std::endl; }
};

class Square : public Shape {
public:
	void draw() const { std::cout << "square" << std::endl; }
};

class Solid : public Shape {
public:
	void draw() const { std::for_each(shapes.begin(), shapes.end(), std::mem_fun(&Shape::draw)); }
	void add(Shape* shape) { shapes.push_back(shape); }

private:
	std::vector<Shape* > shapes;
};


