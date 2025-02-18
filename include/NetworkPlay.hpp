#ifndef network_play__hpp
#define network_play__hpp

#include <SFML/Network.hpp>
#include "../include/all_includes.hpp"
#include <thread>

void sendIds(sf::TcpSocket &socket, std::vector<int>& ids, int size);
void receiveIds(sf::TcpSocket &socket, std::vector<int>& ids, int size);

void sendId(sf::TcpSocket &socket, int& id);
void receiveId(sf::TcpSocket &socket, int& id);

#endif
