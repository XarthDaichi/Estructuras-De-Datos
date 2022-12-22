/*
4) Cree un pequeno programa que simule una cola de reproduccion de musica.Cada elemento de la cola contiene el titulo de la cancion y el artista.Muestre en pantalla una pequena simulacion de la cola de reproduccion.Utilica la libreria queque de la STL

PUNTOS EXTRA : Cree un archivo con la informacion de las canciones(titulo, autor) y genere la cola de reproduccion de manera aleatoria.Se tomara en cuenta la eficiencia de su algoritmo para realizar eso
*/

#include <iostream>
#include <queue>
#include "Song.h"
#include "File_Manager.h"

std::string music_queue(std::queue<Song> que) {
	std::stringstream s;
	s << "NOW PLAYING" << '\n';
	s << que.front() << '\n' << '\n';
	s << "UP NEXT" << '\n';
	que.pop();
	while (!que.empty()) {
		s << que.front() << '\n';
		que.pop();
	}
	return s.str();
}

int main() {
	std::cout << "--------------------------NORMAL QUEUE--------------------------------" << '\n';
	std::queue<Song> playlist;

	Song song1("What's Up Danger", "Blackway and Black Caviar");
	Song song2("Bohemian Rhapsody", "Queen");
	Song song3("Toss a Coin to Your Witcher", "Sonya Belousova, Giona Ostinelli, Joey Batey");
	Song song4("Enemy (with JID)", "Imagine Dragons and JID");

	playlist.push(song1);
	playlist.push(song2);
	playlist.push(song3);
	playlist.push(song4);

	std::cout << music_queue(playlist);

	std::cout << "--------------------------SAVING QUEUE--------------------------------" << '\n';

	File_Manager::save_txt("music.txt", playlist);

	std::cout << "--------------------------PARSING QUEUE--------------------------------" << '\n';

	std::queue<Song> playlist2 = File_Manager::load_txt("music.txt");

	std::cout << music_queue(playlist2);

	std::cout << "--------------------------SHUFFLING QUEUE--------------------------------" << '\n';

	std::queue<Song> playlist3 = File_Manager::shuffle_queue("music.txt");

	std::cout << music_queue(playlist3);

	return 0;
}