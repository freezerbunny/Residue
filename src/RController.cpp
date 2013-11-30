#include "RController.h"

RController::RController( RTiler *rtiler ) {
  this->rtiler = rtiler;
  printf("RController: Created new controller.\n");

  // Create model, observer, and interface.
  dictionary = new RDictionary( "resources/dat/entities.rdat" );
  model = new RModel;
  observer = new RObserver;
  interface = new RInterface;
}

RController::~RController() {
  // Save the game.
  // Delete interface, observer, and model.
  delete interface;
  delete observer;
  delete model;
  delete dictionary;
}