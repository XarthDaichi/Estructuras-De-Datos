#include "File_Manager.h"

File_Manager::File_Manager() {}
File_Manager::~File_Manager() {}

std::queue<Song> File_Manager::load_txt(const std::string& file_name) {
	std::string name, artist;

	Song temp_song;
	std::queue<Song> que;

	std::ifstream in(file_name, std::ios::in);

	if (!in.is_open())
		throw std::invalid_argument("Could not open file [" + file_name + "]");

	while (in.good()) {
		getline(in, name, '-');
		getline(in, artist, '\n');

		temp_song.set_name(name);
		temp_song.set_author(artist);

		if (!name.empty())
			que.push(temp_song);
	}

	return que;
}

void File_Manager::save_txt(const std::string& file_name, std::queue<Song>& que) {
	std::ofstream out(file_name, std::ios::out | std::ios::trunc);

	if (!out.is_open())
		throw std::invalid_argument("Could not open file [" + file_name + "]");

	while (!que.empty()) {
		out << que.front() << '\n';
		que.pop();
	}
}

std::queue<Song> File_Manager::shuffle_queue(const std::string& file_name)
{	
	std::string name, artist;

	Song temp_song;
	std::vector<Song> shuffling_vec;
	std::queue<Song> que;

	std::ifstream in(file_name, std::ios::in);

	if (!in.is_open())
		throw std::invalid_argument("Could not open file [" + file_name + "]");

	while (in.good()) {
		getline(in, name, '-');
		getline(in, artist, '\n');

		temp_song.set_name(name);
		temp_song.set_author(artist);
		if (!name.empty())
			shuffling_vec.push_back(temp_song);
	}

	std::random_shuffle(shuffling_vec.begin(), shuffling_vec.end());

	for (auto i : shuffling_vec)
		que.push(i);

	return que;
}
