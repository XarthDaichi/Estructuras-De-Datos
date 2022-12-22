#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include "Song.h"

class File_Manager {
public:
	File_Manager();
	~File_Manager();

	static std::queue<Song> load_txt(const std::string& file_name);

	static void save_txt(const std::string& file_name, std::queue<Song> &que);

	static std::queue<Song> shuffle_queue(const std::string& file_name);
};

#endif // FILE_MANAGER_H
