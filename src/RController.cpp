#include "RController.h"

RController::RController( RTiler *rtiler ) {
  this->rtiler = rtiler;
  printf("RController: Creating controller.\n");

  // Create model, observer, and interface.
  dictionary = new RDictionary( "resources/dat/entities.rdat" );
  model = new RModel( dictionary );
  observer = new RObserver;
  interface = new RInterface;
}

RController::~RController() {
  printf("RController: Destroying controller.\n");
  // Save the game.
  // Delete interface, observer, and model.
  delete interface;
  delete observer;
  delete model;
  delete dictionary;
}
