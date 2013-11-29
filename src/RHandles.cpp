#include "RHandles.h"

RHandles::RHandles() {
  // TODO: Document what each generally represents.
  // INITIALISE TILE HANDLES
  int cur = 0;
  // Row 1.
  tile_handles_["null"] = cur; cur++;
  tile_handles_["☺"] = cur; cur++;
  tile_handles_["☻"] = cur; cur++;
  tile_handles_["♥"] = cur; cur++;
  tile_handles_["♦"] = cur; cur++;
  tile_handles_["♣"] = cur; cur++;
  tile_handles_["♠"] = cur; cur++;
  tile_handles_["•"] = cur; cur++;
  tile_handles_["◘"] = cur; cur++;
  tile_handles_["○"] = cur; cur++;
  tile_handles_["◙"] = cur; cur++;
  tile_handles_["♂"] = cur; cur++;
  tile_handles_["♀"] = cur; cur++;
  tile_handles_["♪"] = cur; cur++;
  tile_handles_["♫"] = cur; cur++;
  tile_handles_["☼"] = cur; cur++;

  // Row 2.
  tile_handles_["►"] = cur; cur++;
  tile_handles_["◄"] = cur; cur++;
  tile_handles_["↕"] = cur; cur++;
  tile_handles_["‼"] = cur; cur++;
  tile_handles_["¶"] = cur; cur++;
  tile_handles_["§"] = cur; cur++;
  tile_handles_["▬"] = cur; cur++;
  tile_handles_["↨"] = cur; cur++;
  tile_handles_["↑"] = cur; cur++;
  tile_handles_["↓"] = cur; cur++;
  tile_handles_["→"] = cur; cur++;
  tile_handles_["←"] = cur; cur++;
  tile_handles_["∟"] = cur; cur++;
  tile_handles_["↔"] = cur; cur++;
  tile_handles_["▲"] = cur; cur++;
  tile_handles_["▼"] = cur; cur++;

  // Row 3.
  tile_handles_[" "] = cur; cur++;
  tile_handles_["!"] = cur; cur++;
  tile_handles_["\""] = cur; cur++;
  tile_handles_["#"] = cur; cur++;
  tile_handles_["$"] = cur; cur++;
  tile_handles_["%"] = cur; cur++;
  tile_handles_["&"] = cur; cur++;
  tile_handles_["'"] = cur; cur++;
  tile_handles_["("] = cur; cur++;
  tile_handles_[")"] = cur; cur++;
  tile_handles_["*"] = cur; cur++;
  tile_handles_["+"] = cur; cur++;
  tile_handles_[","] = cur; cur++;
  tile_handles_["-"] = cur; cur++;
  tile_handles_["."] = cur; cur++;
  tile_handles_["/"] = cur; cur++;

  // Row 4.
  tile_handles_["0"] = cur; cur++;
  tile_handles_["1"] = cur; cur++;
  tile_handles_["2"] = cur; cur++;
  tile_handles_["3"] = cur; cur++;
  tile_handles_["4"] = cur; cur++;
  tile_handles_["5"] = cur; cur++;
  tile_handles_["6"] = cur; cur++;
  tile_handles_["7"] = cur; cur++;
  tile_handles_["8"] = cur; cur++;
  tile_handles_["9"] = cur; cur++;
  tile_handles_[":"] = cur; cur++;
  tile_handles_[";"] = cur; cur++;
  tile_handles_["<"] = cur; cur++;
  tile_handles_["="] = cur; cur++;
  tile_handles_[">"] = cur; cur++;
  tile_handles_["?"] = cur; cur++;

  // Row 5.
  tile_handles_["@"] = cur; cur++;
  tile_handles_["A"] = cur; cur++;
  tile_handles_["B"] = cur; cur++;
  tile_handles_["C"] = cur; cur++;
  tile_handles_["D"] = cur; cur++;
  tile_handles_["E"] = cur; cur++;
  tile_handles_["F"] = cur; cur++;
  tile_handles_["G"] = cur; cur++;
  tile_handles_["H"] = cur; cur++;
  tile_handles_["I"] = cur; cur++;
  tile_handles_["J"] = cur; cur++;
  tile_handles_["K"] = cur; cur++;
  tile_handles_["L"] = cur; cur++;
  tile_handles_["M"] = cur; cur++;
  tile_handles_["N"] = cur; cur++;
  tile_handles_["O"] = cur; cur++;

  // Row 6.
  tile_handles_["P"] = cur; cur++;
  tile_handles_["Q"] = cur; cur++;
  tile_handles_["R"] = cur; cur++;
  tile_handles_["S"] = cur; cur++;
  tile_handles_["T"] = cur; cur++;
  tile_handles_["U"] = cur; cur++;
  tile_handles_["V"] = cur; cur++;
  tile_handles_["W"] = cur; cur++;
  tile_handles_["X"] = cur; cur++;
  tile_handles_["Y"] = cur; cur++;
  tile_handles_["Z"] = cur; cur++;
  tile_handles_["["] = cur; cur++;
  tile_handles_["\\"] = cur; cur++;
  tile_handles_["]"] = cur; cur++;
  tile_handles_["^"] = cur; cur++;
  tile_handles_["_"] = cur; cur++;

  // Row 7.
  tile_handles_["`"] = cur; cur++;
  tile_handles_["a"] = cur; cur++;
  tile_handles_["b"] = cur; cur++;
  tile_handles_["c"] = cur; cur++;
  tile_handles_["d"] = cur; cur++;
  tile_handles_["e"] = cur; cur++;
  tile_handles_["f"] = cur; cur++;
  tile_handles_["g"] = cur; cur++;
  tile_handles_["h"] = cur; cur++;
  tile_handles_["i"] = cur; cur++;
  tile_handles_["j"] = cur; cur++;
  tile_handles_["k"] = cur; cur++;
  tile_handles_["l"] = cur; cur++;
  tile_handles_["m"] = cur; cur++;
  tile_handles_["n"] = cur; cur++;
  tile_handles_["o"] = cur; cur++;

  // Row 8.
  tile_handles_["p"] = cur; cur++;
  tile_handles_["q"] = cur; cur++;
  tile_handles_["r"] = cur; cur++;
  tile_handles_["s"] = cur; cur++;
  tile_handles_["t"] = cur; cur++;
  tile_handles_["u"] = cur; cur++;
  tile_handles_["v"] = cur; cur++;
  tile_handles_["w"] = cur; cur++;
  tile_handles_["x"] = cur; cur++;
  tile_handles_["y"] = cur; cur++;
  tile_handles_["z"] = cur; cur++;
  tile_handles_["{"] = cur; cur++;
  tile_handles_["|"] = cur; cur++;
  tile_handles_["}"] = cur; cur++;
  tile_handles_["~"] = cur; cur++;
  tile_handles_["⌂"] = cur; cur++;

  // Row 9.
  tile_handles_["Ç"] = cur; cur++;
  tile_handles_["ü"] = cur; cur++;
  tile_handles_["é"] = cur; cur++;
  tile_handles_["â"] = cur; cur++;
  tile_handles_["ä"] = cur; cur++;
  tile_handles_["à"] = cur; cur++;
  tile_handles_["å"] = cur; cur++;
  tile_handles_["ç"] = cur; cur++;
  tile_handles_["ê"] = cur; cur++;
  tile_handles_["ë"] = cur; cur++;
  tile_handles_["è"] = cur; cur++;
  tile_handles_["ï"] = cur; cur++;
  tile_handles_["î"] = cur; cur++;
  tile_handles_["ì"] = cur; cur++;
  tile_handles_["Ä"] = cur; cur++;
  tile_handles_["Å"] = cur; cur++;

  // Row 10.
  tile_handles_["É"] = cur; cur++;
  tile_handles_["æ"] = cur; cur++;
  tile_handles_["Æ"] = cur; cur++;
  tile_handles_["ô"] = cur; cur++;
  tile_handles_["ö"] = cur; cur++;
  tile_handles_["ò"] = cur; cur++;
  tile_handles_["û"] = cur; cur++;
  tile_handles_["ù"] = cur; cur++;
  tile_handles_["ÿ"] = cur; cur++;
  tile_handles_["Ö"] = cur; cur++;
  tile_handles_["Ü"] = cur; cur++;
  tile_handles_["¢"] = cur; cur++;
  tile_handles_["£"] = cur; cur++;
  tile_handles_["¥"] = cur; cur++;
  tile_handles_["₧"] = cur; cur++;
  tile_handles_["ƒ"] = cur; cur++;

  // Row 11.
  tile_handles_["á"] = cur; cur++;
  tile_handles_["í"] = cur; cur++;
  tile_handles_["ó"] = cur; cur++;
  tile_handles_["ú"] = cur; cur++;
  tile_handles_["ñ"] = cur; cur++;
  tile_handles_["Ñ"] = cur; cur++;
  tile_handles_["ª"] = cur; cur++;
  tile_handles_["º"] = cur; cur++;
  tile_handles_["¿"] = cur; cur++;
  tile_handles_["⌐"] = cur; cur++;
  tile_handles_["¬"] = cur; cur++;
  tile_handles_["½"] = cur; cur++;
  tile_handles_["¼"] = cur; cur++;
  tile_handles_["¡"] = cur; cur++;
  tile_handles_["«"] = cur; cur++;
  tile_handles_["»"] = cur; cur++;


  // Row 12.
  tile_handles_["░"] = cur; cur++;
  tile_handles_["▒"] = cur; cur++;
  tile_handles_["▓"] = cur; cur++;
  tile_handles_["│"] = cur; cur++;
  tile_handles_["┤"] = cur; cur++;
  tile_handles_["╡"] = cur; cur++;
  tile_handles_["╢"] = cur; cur++;
  tile_handles_["╖"] = cur; cur++;
  tile_handles_["╕"] = cur; cur++;
  tile_handles_["╣"] = cur; cur++;
  tile_handles_["║"] = cur; cur++;
  tile_handles_["╗"] = cur; cur++;
  tile_handles_["╝"] = cur; cur++;
  tile_handles_["╜"] = cur; cur++;
  tile_handles_["╛"] = cur; cur++;
  tile_handles_["┐"] = cur; cur++;

  // Row 13.
  tile_handles_["└"] = cur; cur++;
  tile_handles_["┴"] = cur; cur++;
  tile_handles_["┬"] = cur; cur++;
  tile_handles_["├"] = cur; cur++;
  tile_handles_["─"] = cur; cur++;
  tile_handles_["┼"] = cur; cur++;
  tile_handles_["╞"] = cur; cur++;
  tile_handles_["╟"] = cur; cur++;
  tile_handles_["╚"] = cur; cur++;
  tile_handles_["╔"] = cur; cur++;
  tile_handles_["╩"] = cur; cur++;
  tile_handles_["╦"] = cur; cur++;
  tile_handles_["╠"] = cur; cur++;
  tile_handles_["═"] = cur; cur++;
  tile_handles_["╬"] = cur; cur++;
  tile_handles_["╧"] = cur; cur++;

  // Row 14.
  tile_handles_["╨"] = cur; cur++;
  tile_handles_["╤"] = cur; cur++;
  tile_handles_["╥"] = cur; cur++;
  tile_handles_["╙"] = cur; cur++;
  tile_handles_["╘"] = cur; cur++;
  tile_handles_["╒"] = cur; cur++;
  tile_handles_["╓"] = cur; cur++;
  tile_handles_["╫"] = cur; cur++;
  tile_handles_["╪"] = cur; cur++;
  tile_handles_["┘"] = cur; cur++;
  tile_handles_["┌"] = cur; cur++;
  tile_handles_["█"] = cur; cur++;
  tile_handles_["▄"] = cur; cur++;
  tile_handles_["▌"] = cur; cur++;
  tile_handles_["▐"] = cur; cur++;
  tile_handles_["▀"] = cur; cur++;
  // Row 15
  tile_handles_["α"] = cur; cur++;
  tile_handles_["ß"] = cur; cur++;
  tile_handles_["Γ"] = cur; cur++;
  tile_handles_["π"] = cur; cur++;
  tile_handles_["Σ"] = cur; cur++;
  tile_handles_["σ"] = cur; cur++;
  tile_handles_["µ"] = cur; cur++;
  tile_handles_["τ"] = cur; cur++;
  tile_handles_["Φ"] = cur; cur++;
  tile_handles_["Θ"] = cur; cur++;
  tile_handles_["Ω"] = cur; cur++;
  tile_handles_["δ"] = cur; cur++;
  tile_handles_["∞"] = cur; cur++;
  tile_handles_["φ"] = cur; cur++;
  tile_handles_["ε"] = cur; cur++;
  tile_handles_["∩"] = cur; cur++;

  // Row 16.
  tile_handles_["≡"] = cur; cur++;
  tile_handles_["±"] = cur; cur++;
  tile_handles_["≥"] = cur; cur++;
  tile_handles_["≤"] = cur; cur++;
  tile_handles_["⌠"] = cur; cur++;
  tile_handles_["⌡"] = cur; cur++;
  tile_handles_["÷"] = cur; cur++;
  tile_handles_["≈"] = cur; cur++;
  tile_handles_["°"] = cur; cur++;
  tile_handles_["∙"] = cur; cur++;
  tile_handles_["·"] = cur; cur++;
  tile_handles_["√"] = cur; cur++;
  tile_handles_["ⁿ"] = cur; cur++;
  tile_handles_["²"] = cur; cur++;
  tile_handles_["■"] = cur; cur++;
//  tile_handles_[""] = cur; cur++;
}

std::map<std::string, int> RHandles::tile_handles() {
  return tile_handles_;
}

RHandles::~RHandles() {
}
