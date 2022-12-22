#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
#include <sstream>

class Song {
private:
	std::string name;
	std::string author;

public:
	Song(std::string name = "", std::string author = "");
	
	~Song();

	std::string get_name();
	std::string get_author();
	void set_name(std::string name);
	void set_author(std::string author);

	friend std::ostream& operator<<(std::ostream& os, const Song& song);

	std::string toString();
};


#endif //SONG_H