#include "manager.h"

void manager::maingame_start()
{
    dialog.setModal(true);
    dialog.exec();
}
