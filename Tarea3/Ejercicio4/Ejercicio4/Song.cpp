#include "Song.h"

Song::Song(std::string name, std::string author) : name(name), author(author) {}

Song::~Song() {}

std::string Song::get_name() { return name; }

std::string Song::get_author() { return author; }

void Song::set_name(std::string name) { this->name = name; }

void Song::set_author(std::string author) { this->author = author; }

std::ostream& operator<<(std::ostream& os, const Song& song) {
	os << song.name << " - " << song.author;
	return os;
}

std::string Song::toString() {
	std::stringstream s;
	s << " Name: " << get_name() << " Artist: " << get_author();
	return s.str();
}
