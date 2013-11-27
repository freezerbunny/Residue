#include "RCol.h"

RCol::RCol() {
  //ctor
}

bool RCol::init() {
  // Try to open RGB.txt
  std::ifstream rgb;
  std::string path = "resources/rgb.txt";
  rgb.open(path.c_str(), std::ios::in);

  if(!rgb.is_open()) {
    printf( "Could not open rgb.txt: %s\n", path.c_str() );
    return false;
  }

  // Create mappings.
  char line[256];
  char num[3];
  int r, g, b;
  std::string name;
  while ( !rgb.eof() ) {
    rgb.getline(line, 256, '\n');

    name = "";
    r = 0, g = 0, b = 0;
    for (int i = 0; i < 256; i++) {
      if (i < 3)
        num[i] = line[i];
      else if (!r) {
        r = atoi(num);
      }
      else if (i > 4 && i < 8) {
        num[i - 5] = line[i];
      }
      else if (!g) {
        g = atoi(num);
      }
      else if (i > 8 && i < 12) {
        num[i - 9] = line[i];
      }
      else if (!b) {
        b = atoi(num);
      }
      else if (i > 11) {
        name += line[i];
      }
    }
    printf( "%s is: R = %d, G = %d, B = %d\n", name.c_str(), r, g, b );
  }

  return true;
}

RCol::~RCol() {
  //dtor
}
