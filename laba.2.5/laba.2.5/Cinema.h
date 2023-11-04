#pragma once
#include<iostream>
#include<string>
#include<deque>
#include"Movie.h"
using namespace std;

class Cinema {
private:
	deque<Movie> Database;

public:
	Cinema();

	void Replase();

	void ModifyTheContainer();

	void PrintIterator();

	void Change_the_first_container_and_add_elements_of_the_second_container(Cinema cinema2);

	void Print();
};

