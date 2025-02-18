#include "../include/all_includes.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

std::vector<std::string> ImageNames = {
  "001_explosion.jpg",
  "002_explosionp.jpg",
  "003_murdefeu.jpg",
  "004_terrebrulee.jpg",
  "005_feudeforet.jpg",
  "006_divinecomedie.jpg",
  "007_tangoardent.jpg",
  "008_gardedelta.jpg",
  "009_kamikaze.jpg",
  "010_kamikazep.jpg",
  "011_detonation.jpg",
  "012_detonationp.jpg",
  "013_queue.jpg",
  "014_chant.jpg",
  "015_baisermortel.jpg",
  "016_baisermortelp.jpg",
  "017_charme.jpg",
  "018_charmep.jpg",
  "019_salvedefeu.jpg",
  "020_barriereardente.jpg",
  "021_espritmortel.jpg",
  "022_espritmortelp.jpg",
  "023_feuderenaissance.jpg",
  "024_feuderenaissancep.jpg",
  "025_carapace.jpg",
  "026_carapacep.jpg",
  "027_carapacemiracle.jpg",

  "027_carapacemiracle.jpg",

  "029_somnifere.jpg",
  "030_gardetotale.jpg",
  "031_tournepine.jpg",
  "032_piege.jpg",
  "033_dardempoisonne.jpg",

  "033_dardempoisonne.jpg",

  "035_1000epines.jpg",
  "036_1000epinesp.jpg",
  "037_charge.jpg",
  "038_ruadedeguerison.jpg",
  "039_source.jpg",
  "040_sourcep.jpg",
  "041_rafale.jpg",
  "042_rafalep.jpg",
  "043_coleredegaia.jpg",
  "044_rocher.jpg",
  "045_poingterrestre.jpg",
  "046_poingterrestrep.jpg",
  "047_faille.jpg",
  "048_faillep.jpg",
  "049_murmuredeglace.jpg",
  "050_extincteur.jpg",
  "051_extincteurp.jpg",
  "052_voiledeneige.jpg",
  "053_transcendantale.jpg",
  "054_celeste.jpg",
  "055_coupdefouet.jpg",
  "056_tempete.jpg",
  "057_geyser.jpg",
  "058_geyserp.jpg",
  "059_tsunami.jpg",
  "060_tsunamip.jpg",
  "061_soufflebrumeux.jpg",
  "062_brumeondulante.jpg",
  "063_aquasouffle.jpg",
  "064_aquasoufflep.jpg",
  "065_sceaudeglace.jpg",
  "066_sceaudeglacep.jpg",
  "067_aquarius.jpg",
  "068_engloutir.jpg",
  "069_engloutirp.jpg",
  "070_breche.jpg",
  "071_brechep.jpg",
  "072_maelstrom.jpg",
  "073_etoilebrillante.jpg",
  "074_martellement.jpg",
  "075_rubislumineux.jpg",
  "076_rubislumineuxp.jpg",
  "077_gardesainte.jpg",
  "078_chanbeni.jpg",
  "079_foudre.jpg",
  "080_orage.jpg",
  "081_champsem.jpg",
  "082_champsemp.jpg",
  "083_jugement.jpg",
  "084_jugementp.jpg",
  "085_megaphone.jpg",
  "086_trompette.jpg",
  "087_trompettep.jpg",
  "088_chat-verse.jpg",
  "089_acclamation.jpg",
  "090_acclamationp.jpg",
  "091_poing.jpg",
  "092_plaquage.jpg",
  "093_rayon.jpg",
  "094_rayonp.jpg",
  "095_coupascendant.jpg",
  "096_coupascendantp.jpg",
  "097_zantetsuken.jpg",
  "098_zantetsukenp.jpg",
  "099_gungnir.jpg",
  "100_gungnirp.jpg",
  "101_sleipnir.jpg",
  "102_lamesombre.jpg",
  "103_frappeaerienne.jpg",
  "104_megaatomnium.jpg",
  "105_megaatomniump.jpg",
  "106_rayonterra.jpg",
  "107_rayonterrap.jpg",
  "108_pulsar.jpg",
  "109_nuageempoisonne.jpg",
  "110_liensombre.jpg",
  "111_couteau.jpg",
  "112_rancune.jpg",
  "113_rancunep.jpg",
  "114_claque.jpg",
  "115_claquep.jpg",
  "116_rage.jpg",
  "117_cri.jpg",
  "118_meteore.jpg",
  "119_bouledefeu.jpg",
  "120_miammiam.jpg",
  "121_reniflement.jpg",
  "122_ecrasement.jpg"
};


sf::TcpSocket socket;
sf::TcpListener listener;
sf::SocketSelector selector;
bool isHost = false;
bool connected = false;
const unsigned short PORT = 44000;


void runGame(sf::RenderWindow& window, const std::array<Card*, 122>& AllCards, const std::vector<sf::Sprite>& sprites, sf::TcpSocket &socket, Player* p1, Player* p2, std::vector<int>& ids1, std::vector<int>& ids2){

  DeckCreationMenu dcm(sprites, p1);
  dcm.run(window, AllCards);

  for (Card* c : p1->getDeck()){
    std::cout << "Carte : " << c->getId() << std::endl;
    ids1.push_back(c->getId());
  }

  sendIds(socket, ids1, 15);
  receiveIds(socket, ids2, 15);

  for (int id : ids2){
    p2->addCard(id, AllCards);
  }
  for (Card* c : p2->getDeck()){
    std::cout << "Carte adversaire : " << c->getId() << std::endl;
  }

  InGameInterface igi(sprites, p1, p2);
  igi.run(window, AllCards, socket);

}


int main(int, char**) {

  sf::IpAddress localIP = sf::IpAddress::getLocalAddress();

  std::cout << "Trying to connect to an existing host at " << localIP << "...\n";
  if (socket.connect(localIP, PORT, sf::seconds(2)) == sf::Socket::Done) {
    isHost = false;
    std::cout << "Connected to host at " << localIP << "!\n";
  } else {
    isHost = true;
    std::cout << "No host found. Starting as host...\n";

    if (listener.listen(PORT) != sf::Socket::Done) {
      std::cerr << "Error: Could not start listening on port " << PORT << "\n";
      return -1;
    }

    std::cout << "Waiting for opponent to connect...\n";
    while (listener.accept(socket) != sf::Socket::Done) {
      std::cout << "Still waiting for a connection...\n";
      sf::sleep(sf::seconds(1)); // Petite pause pour éviter d'utiliser 100% du CPU
    }
    std::cout << "Opponent connected!\n";

  }

  connected = true;

  std::vector<int> ids1;
  std::vector<int> ids2;


  // Create textures and sprites
  std::vector<sf::Texture> textures(122);
  std::vector<sf::Sprite> sprites(122);

  // Get the Images 
  for (int i = 0; i < 122; ++i) {
    std::string filename = "assets/Pop-Up_Duel_Cards/" + ImageNames[i];
    if (!textures[i].loadFromFile(filename)) {
    }
    sprites[i].setTexture(textures[i]);
  }

  // Create the Cards
  std::array<Card*, 122> AllCards = Cards_Creation();

  // Get Screen Dimension
  sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
  unsigned int screenHeight = desktopMode.height;

  // Create Window
  sf::RenderWindow window(sf::VideoMode(screenHeight * 0.9 * 1.5, screenHeight * 0.9), "Pop-Up Duel");

  // Create the Players
  Player* p1 = new Player("PlayerOne");
  Player* p2 = new Player("PlayerTwo");

  // Card selection
  // p1 p2 ids1 ids2
  if(isHost){

    runGame(window, AllCards, sprites, socket, p1, p2, ids1, ids2);

  } 
  else {

    runGame(window, AllCards, sprites, socket, p2, p1, ids2, ids1);

  }

  return 0;
}
