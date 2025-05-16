#include <SDL.h>
#include <string>
#include "../Player/Player.h"
#include "../Ball/Ball.h"

class BoostBox {
public:
  std::string name;

  virtual void handlePlayerColision(Player * player) = 0;
  virtual void handleBallColision(Ball * ball) = 0;
};

class SpeedBoostBox : public BoostBox {
public:
  void handlePlayerColision(Player * player);
  void handleBallColision(Ball * ball);
};