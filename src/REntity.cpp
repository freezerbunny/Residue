#include "REntity.h"

REntity::REntity( std::string id, std::map<std::string, unsigned int> mappings,
                  std::vector<int> vars, std::vector<std::string> strings, std::vector<std::string> flags ) {
  this->id = id;
  this->mappings = mappings;
  this->vars = vars;
  this->strings = strings;
  this->flags = flags;

  // Create graphlet.
  graphlet.character = strings[mappings["character"]];
  graphlet.color = strings[mappings["color"]];
}

REntity::~REntity() {
}
