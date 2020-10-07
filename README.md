# snakegame

Simple Snake game using Qt and a QGraphicsScene. 
A Snake is spawned with a head and 2 tail pieces by default. The snake is controlled by the WASD keys. A Food item is spawned randomly.
In the works is a 2-player multiplayer version.

# Snake
The snake is represented as a QGraphicsItemGroup with some custom slots for growing the snake and retrieving the head for collision detection 
by the scene against food.
