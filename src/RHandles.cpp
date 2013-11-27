#include "RHandles.h"

RHandles::RHandles() {
  // TODO: Document what each generally represents.
  // Row 1.

  // Row 2.

  // Row 3.
  tile_handles[" "] = ' ';
  tile_handles["!"] = '!';
  tile_handles["\""] = '"';
  tile_handles["#"] = '#';
  tile_handles["$"] = '$';
  tile_handles["%"] = '%';
  tile_handles["&"] = '&';
  tile_handles["'"] = '\'';
  tile_handles["("] = '(';
  tile_handles[")"] = ')';
  tile_handles["*"] = '*';
  tile_handles["+"] = '+';
  tile_handles[","] = ',';
  tile_handles["-"] = '-';
  tile_handles["."] = '.';
  tile_handles["/"] = '/';

  // Row 4.
  tile_handles["0"] = '0';
  tile_handles["1"] = '1';
  tile_handles["2"] = '2';
  tile_handles["3"] = '3';
  tile_handles["4"] = '4';
  tile_handles["5"] = '5';
  tile_handles["6"] = '6';
  tile_handles["7"] = '7';
  tile_handles["8"] = '8';
  tile_handles["9"] = '9';
  tile_handles[":"] = ':';
  tile_handles[";"] = ';';
  tile_handles["<"] = '<';
  tile_handles["="] = '=';
  tile_handles[">"] = '>';
  tile_handles["?"] = '?';

  // Row 5.
  tile_handles["@"] = '@';
  tile_handles["A"] = 'A';
  tile_handles["B"] = 'B';
  tile_handles["C"] = 'C';
  tile_handles["D"] = 'D';
  tile_handles["E"] = 'E';
  tile_handles["F"] = 'F';
  tile_handles["G"] = 'G';
  tile_handles["H"] = 'H';
  tile_handles["I"] = 'I';
  tile_handles["J"] = 'J';
  tile_handles["K"] = 'K';
  tile_handles["L"] = 'L';
  tile_handles["M"] = 'M';
  tile_handles["N"] = 'N';
  tile_handles["O"] = 'O';

  // Row 6.
  tile_handles["P"] = 'P';
  tile_handles["Q"] = 'Q';
  tile_handles["R"] = 'R';
  tile_handles["S"] = 'S';
  tile_handles["T"] = 'T';
  tile_handles["U"] = 'U';
  tile_handles["V"] = 'V';
  tile_handles["W"] = 'W';
  tile_handles["X"] = 'X';
  tile_handles["Y"] = 'Y';
  tile_handles["Z"] = 'Z';
  tile_handles["["] = '[';
  tile_handles["\\"] = '\\';
  tile_handles["]"] = ']';
  tile_handles["^"] = '^';
  tile_handles["_"] = '_';

  // Row 7.
  tile_handles["`"] = '`';
  tile_handles["a"] = 'a';
  tile_handles["b"] = 'b';
  tile_handles["c"] = 'c';
  tile_handles["d"] = 'd';
  tile_handles["e"] = 'e';
  tile_handles["f"] = 'f';
  tile_handles["g"] = 'g';
  tile_handles["h"] = 'h';
  tile_handles["i"] = 'i';
  tile_handles["j"] = 'j';
  tile_handles["k"] = 'k';
  tile_handles["l"] = 'l';
  tile_handles["m"] = 'm';
  tile_handles["n"] = 'n';
  tile_handles["o"] = 'o';

  // Row 8.
  tile_handles["p"] = 'p';
  tile_handles["q"] = 'q';
  tile_handles["r"] = 'r';
  tile_handles["s"] = 's';
  tile_handles["t"] = 't';
  tile_handles["u"] = 'u';
  tile_handles["v"] = 'v';
  tile_handles["w"] = 'w';
  tile_handles["x"] = 'x';
  tile_handles["y"] = 'y';
  tile_handles["z"] = 'z';
  tile_handles["{"] = '{';
  tile_handles["|"] = '|';
  tile_handles["~"] = '~';
//  tile_handles[""] = '';

  // Row 9.

  // Row 10.

  // Row 11.

  // Row 12.

  // Row 13.

  // Row 14.

  // Row 15.

  // Row 16.

  // Initialise operators.

}

std::map<std::string, char> *RHandles::get_tile_handles() {
  return &tile_handles;
}

RHandles::~RHandles() {
}
