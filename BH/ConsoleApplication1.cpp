
#include <iostream>
#include "SaveSysteam.h"
#include "DataSysteam.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SaveSysteam save;
	Inventory inventory(save);
	Item item(save,2);
	item.SetName("Laser");
	inventory.AddItem(item);
	system("pause");
	return 0;
}

