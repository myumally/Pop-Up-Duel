#include "../include/all_includes.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "../include/DeckCreationMenu.hpp"

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


int main(int, char**) {

  /*
  // Get Screen Dimension
  sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
  unsigned int screenHeight = desktopMode.height;

  // Create Window
  sf::RenderWindow window(sf::VideoMode(screenHeight * 0.9 * 1.5, screenHeight * 0.9), "Deck Creation");

  */

  // Create textures and sprites
  std::vector<sf::Texture> textures(122);
  std::vector<sf::Sprite> sprites(122);

  // Get the Images 
  for (int i = 0; i < 122; ++i) {
    std::string filename = "assets/Pop-Up_Duel_Cards/" + ImageNames[i];
    if (!textures[i].loadFromFile(filename)) {
    }
    sprites[i].setTexture(textures[i]);
    sprites[i].setScale(2.0f, 2.0f);
  }

  // Scroll Management
  float scrollOffset = 0.f;
  float scrollSpeed = 20.f;
/*
  // Main Loop

  // mouse's position and state
  int x = 0;
  int y = 0;
  int mouse_state = 0;

  // id of the card pointed by the mouse
  int id_mouse_card = 0;

  sf::Event event;

  while (window.isOpen()) {

    mouse_state = 0;

    while (window.pollEvent(event))
    {
      // check the type of the event...
      switch (event.type)
      {
        // window closed
        case sf::Event::Closed:
          window.close();
          break;

        
        case sf::Event::MouseWheelScrolled:
          if (event.mouseWheelScroll.delta > 0) {
            scrollOffset += scrollSpeed;
          } else {
            scrollOffset -= scrollSpeed;
          }
          break;

        case sf::Event::MouseButtonPressed:
          x = event.mouseButton.x;
          y = event.mouseButton.y;
          mouse_state = 1;          
          break;

        case sf::Event::MouseMoved:
          x = event.mouseMove.x;
          y = event.mouseMove.y;          
          break;

        default:
          break;
      }
    }

    // update

    if (mouse_state == 1){
      for (int i = 0; i < 122; ++i){
        if (sprites[i].getGlobalBounds().contains(x, y)){
          id_mouse_card = i + 1;
          std::cout << "La souris est sur l'image " << id_mouse_card << std::endl;

        }
      }
    }

    // render

    window.clear();

    for (int i = 0; i < 122; ++i){
      sprites[i].setPosition(600.f + (i%3) * 300.f, ((i/3) * 400.f) + scrollOffset);
      window.draw(sprites[i]); 
    }

    window.display();
  }
  */

  DeckCreationMenu dcm(sprites);
  dcm.run();

  return 0;
}
