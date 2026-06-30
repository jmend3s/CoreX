
#include "application/Application.h"
#include "hardware/BoardConfiguration.h"


int main()
{
    BoardConfiguration const board;
    Application app(board.board());
    System system(app.components(), app.storage(), app.count(), app.time());

    system.run();
}
