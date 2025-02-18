#include "../include/NetworkPlay.hpp"

void sendIds(sf::TcpSocket &socket, std::vector<int>& ids, int size) {
  sf::Packet packet;

  for (int i = 0; i < size; i++) {
    packet << ids[i];
  }

  if (socket.send(packet) != sf::Socket::Done) {
    std::cerr << "Erreur lors de l'envoi du tableau\n";
  } else {
    std::cout << "Tableau envoyé !\n";
  }
}

void receiveIds(sf::TcpSocket &socket, std::vector<int>& ids, int size) {
  sf::Packet packet;

  ids.clear();
  ids.resize(size);

  if (socket.receive(packet) != sf::Socket::Done) {
    std::cerr << "Erreur lors de la réception du tableau\n";
    return;
  }

  for (int i = 0; i < size; i++) {
    packet >> ids[i];
  }

  std::cout << "Tableau reçu !\n";
}

void sendId(sf::TcpSocket &socket, int& id) {
  sf::Packet packet;

  packet << id;

  if (socket.send(packet) != sf::Socket::Done) {
    std::cerr << "Erreur lors de l'envoi du tableau\n";
  } else {
    std::cout << "id envoyé !\n";
  }
}

void receiveId(sf::TcpSocket &socket, int& id) {
  sf::Packet packet;

  if (socket.receive(packet) != sf::Socket::Done) {
    std::cerr << "Erreur lors de la réception du tableau\n";
    return;
  }

  packet >> id;

  std::cout << "id reçu !\n";
}
