#include "RHandles.h"

RHandles::RHandles() {
  // TODO: Document what each generally represents.
  // INITIALISE TILE HANDLES
  // Row 1.
  tile_handles_["null"] = 0;
  tile_handles_["☺"] = 1;
  tile_handles_["☻"] = 2;
  tile_handles_["♥"] = 3;
  tile_handles_["♦"] = 4;
  tile_handles_["♣"] = 5;
  tile_handles_["♠"] = 6;
  tile_handles_["•"] = 7;
  tile_handles_["◘"] = 8;
  tile_handles_["○"] = 9;
  tile_handles_["◙"] = 10;
  tile_handles_["♂"] = 11;
  tile_handles_["♀"] = 12;
  tile_handles_["♪"] = 13;
  tile_handles_["♫"] = 14;
  tile_handles_["☼"] = 15;

  // Row 2.
  tile_handles_["►"] = 16;
  tile_handles_["◄"] = 17;
  tile_handles_["↕"] = 18;
  tile_handles_["‼"] = 19;
  tile_handles_["¶"] = 20;
  tile_handles_["§"] = 21;
  tile_handles_["▬"] = 22;
  tile_handles_["↨"] = 23;
  tile_handles_["↑"] = 24;
  tile_handles_["↓"] = 25;
  tile_handles_["→"] = 26;
  tile_handles_["←"] = 27;
  tile_handles_["∟"] = 28;
  tile_handles_["↔"] = 29;
  tile_handles_["▲"] = 30;
  tile_handles_["▼"] = 31;

  // Row 3.
  tile_handles_[" "] = 32;
  tile_handles_["!"] = 33;
  tile_handles_["\""] = 34;
  tile_handles_["#"] = 35;
  tile_handles_["$"] = 36;
  tile_handles_["%"] = 37;
  tile_handles_["&"] = 38;
  tile_handles_["'"] = 39;
  tile_handles_["("] = 40;
  tile_handles_[")"] = 41;
  tile_handles_["*"] = 42;
  tile_handles_["+"] = 43;
  tile_handles_[","] = 44;
  tile_handles_["-"] = 45;
  tile_handles_["."] = 46;
  tile_handles_["/"] = 47;

  // Row 4.
  tile_handles_["0"] = 48;
  tile_handles_["1"] = 49;
  tile_handles_["2"] = 50;
  tile_handles_["3"] = 51;
  tile_handles_["4"] = 52;
  tile_handles_["5"] = 53;
  tile_handles_["6"] = 54;
  tile_handles_["7"] = 55;
  tile_handles_["8"] = 56;
  tile_handles_["9"] = 57;
  tile_handles_[":"] = 58;
  tile_handles_[";"] = 59;
  tile_handles_["<"] = 60;
  tile_handles_["="] = 61;
  tile_handles_[">"] = 62;
  tile_handles_["?"] = 63;

  // Row 5.
  tile_handles_["@"] = 64;
  tile_handles_["A"] = 65;
  tile_handles_["B"] = 66;
  tile_handles_["C"] = 67;
  tile_handles_["D"] = 68;
  tile_handles_["E"] = 69;
  tile_handles_["F"] = 70;
  tile_handles_["G"] = 71;
  tile_handles_["H"] = 72;
  tile_handles_["I"] = 73;
  tile_handles_["J"] = 74;
  tile_handles_["K"] = 75;
  tile_handles_["L"] = 76;
  tile_handles_["M"] = 77;
  tile_handles_["N"] = 78;
  tile_handles_["O"] = 79;

  // Row 6.
  tile_handles_["P"] = 80;
  tile_handles_["Q"] = 81;
  tile_handles_["R"] = 82;
  tile_handles_["S"] = 83;
  tile_handles_["T"] = 84;
  tile_handles_["U"] = 85;
  tile_handles_["V"] = 86;
  tile_handles_["W"] = 87;
  tile_handles_["X"] = 88;
  tile_handles_["Y"] = 89;
  tile_handles_["Z"] = 90;
  tile_handles_["["] = 91;
  tile_handles_["\\"] = 92;
  tile_handles_["]"] = 93;
  tile_handles_["^"] = 94;
  tile_handles_["_"] = 95;

  // Row 7.
  tile_handles_["`"] = 96;
  tile_handles_["a"] = 97;
  tile_handles_["b"] = 98;
  tile_handles_["c"] = 99;
  tile_handles_["d"] = 100;
  tile_handles_["e"] = 101;
  tile_handles_["f"] = 102;
  tile_handles_["g"] = 103;
  tile_handles_["h"] = 104;
  tile_handles_["i"] = 105;
  tile_handles_["j"] = 106;
  tile_handles_["k"] = 107;
  tile_handles_["l"] = 108;
  tile_handles_["m"] = 109;
  tile_handles_["n"] = 110;
  tile_handles_["o"] = 111;

  // Row 8.
  tile_handles_["p"] = 112;
  tile_handles_["q"] = 113;
  tile_handles_["r"] = 114;
  tile_handles_["s"] = 115;
  tile_handles_["t"] = 116;
  tile_handles_["u"] = 117;
  tile_handles_["v"] = 118;
  tile_handles_["w"] = 119;
  tile_handles_["x"] = 120;
  tile_handles_["y"] = 121;
  tile_handles_["z"] = 122;
  tile_handles_["{"] = 123;
  tile_handles_["|"] = 124;
  tile_handles_["~"] = 125;
  tile_handles_["⌂"] = 126;

  // Row 9.
  tile_handles_["Ç"] = 127;
  tile_handles_["ü"] = 128;
  tile_handles_["é"] = 129;
  tile_handles_["â"] = 130;
  tile_handles_["ä"] = 131;
  tile_handles_["à"] = 132;
  tile_handles_["å"] = 133;
  tile_handles_["ç"] = 134;
  tile_handles_["ê"] = 135;
  tile_handles_["ë"] = 136;
  tile_handles_["è"] = 137;
  tile_handles_["ï"] = 138;
  tile_handles_["î"] = 139;
  tile_handles_["ì"] = 140;
  tile_handles_["Ä"] = 141;
  tile_handles_["Å"] = 142;

  // Row 10.
  tile_handles_["É"] = 143;
  tile_handles_["æ"] = 144;
  tile_handles_["Æ"] = 145;
  tile_handles_["ô"] = 146;
  tile_handles_["ö"] = 147;
  tile_handles_["ò"] = 148;
  tile_handles_["û"] = 149;
  tile_handles_["ù"] = 150;
  tile_handles_["ÿ"] = 151;
  tile_handles_["Ö"] = 152;
  tile_handles_["Ü"] = 153;
  tile_handles_["¢"] = 154;
  tile_handles_["£"] = 155;
  tile_handles_["¥"] = 156;
  tile_handles_["₧"] = 157;
  tile_handles_["ƒ"] = 158;

  // Row 11.
  tile_handles_["á"] = 159;
  tile_handles_["í"] = 160;
  tile_handles_["ó"] = 161;
  tile_handles_["ú"] = 162;
  tile_handles_["ñ"] = 163;
  tile_handles_["Ñ"] = 164;
  tile_handles_["ª"] = 165;
  tile_handles_["º"] = 166;
  tile_handles_["¿"] = 167;
  tile_handles_["⌐"] = 168;
  tile_handles_["¬"] = 169;
  tile_handles_["½"] = 170;
  tile_handles_["¼"] = 171;
  tile_handles_["¡"] = 172;
  tile_handles_["«"] = 173;
  tile_handles_["»"] = 174;


  // Row 12.
  tile_handles_["░"] = 175;
  tile_handles_["▒"] = 176;
  tile_handles_["▓"] = 177;
  tile_handles_["│"] = 178;
  tile_handles_["┤"] = 179;
  tile_handles_["╡"] = 180;
  tile_handles_["╢"] = 181;
  tile_handles_["╖"] = 182;
  tile_handles_["╕"] = 183;
  tile_handles_["╣"] = 184;
  tile_handles_["║"] = 185;
  tile_handles_["╗"] = 186;
  tile_handles_["╝"] = 187;
  tile_handles_["╜"] = 188;
  tile_handles_["╛"] = 189;
  tile_handles_["┐"] = 190;

  // Row 13.
  tile_handles_["└"] = 191;
  tile_handles_["┴"] = 192;
  tile_handles_["┬"] = 193;
  tile_handles_["├"] = 194;
  tile_handles_["─"] = 195;
  tile_handles_["┼"] = 196;
  tile_handles_["╞"] = 197;
  tile_handles_["╟"] = 198;
  tile_handles_["╚"] = 199;
  tile_handles_["╔"] = 200;
  tile_handles_["╩"] = 201;
  tile_handles_["╦"] = 202;
  tile_handles_["╠"] = 203;
  tile_handles_["═"] = 204;
  tile_handles_["╬"] = 205;
  tile_handles_["╧"] = 206;

  // Row 14.
  tile_handles_["╨"] = 207;
  tile_handles_["╤"] = 208;
  tile_handles_["╥"] = 209;
  tile_handles_["╙"] = 210;
  tile_handles_["╘"] = 211;
  tile_handles_["╒"] = 212;
  tile_handles_["╓"] = 213;
  tile_handles_["╫"] = 214;
  tile_handles_["╪"] = 215;
  tile_handles_["┘"] = 216;
  tile_handles_["┌"] = 217;
  tile_handles_["█"] = 218;
  tile_handles_["▄"] = 219;
  tile_handles_["▌"] = 220;
  tile_handles_["▐"] = 221;
  tile_handles_["▀"] = 222;
  // Row 15
  tile_handles_["α"] = 223;
  tile_handles_["ß"] = 224;
  tile_handles_["Γ"] = 225;
  tile_handles_["π"] = 226;
  tile_handles_["Σ"] = 227;
  tile_handles_["σ"] = 228;
  tile_handles_["µ"] = 229;
  tile_handles_["τ"] = 230;
  tile_handles_["Φ"] = 231;
  tile_handles_["Θ"] = 232;
  tile_handles_["Ω"] = 233;
  tile_handles_["δ"] = 234;
  tile_handles_["∞"] = 235;
  tile_handles_["φ"] = 236;
  tile_handles_["ε"] = 237;
  tile_handles_["∩"] = 238;

  // Row 16.
  tile_handles_["≡"] = 239;
  tile_handles_["±"] = 240;
  tile_handles_["≥"] = 241;
  tile_handles_["≤"] = 242;
  tile_handles_["⌠"] = 243;
  tile_handles_["⌡"] = 244;
  tile_handles_["÷"] = 245;
  tile_handles_["≈"] = 246;
  tile_handles_["°"] = 247;
  tile_handles_["∙"] = 248;
  tile_handles_["·"] = 249;
  tile_handles_["√"] = 250;
  tile_handles_["ⁿ"] = 251;
  tile_handles_["²"] = 252;
  tile_handles_["■"] = 253;
//  tile_handles_[""] = 254;
}

std::map<std::string, int> RHandles::tile_handles() {
  return tile_handles_;
}

RHandles::~RHandles() {
}
