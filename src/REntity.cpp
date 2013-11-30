#include "REntity.h"

REntity::REntity( std::string id, std::map<std::string, unsigned int> mappings,
                  std::vector<int> vars, std::vector<std::string> strings, std::vector<std::string> flags ) {
  this->id = id;
  this->mappings = mappings;
  this->vars = vars;
  this->strings = strings;
  this->flags = flags;
}

REntity::~REntity() {
  //dtor
}
