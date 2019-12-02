
#include <iostream>
#include "SaveSysteam.h"
#include "DataSysteam.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	SaveSysteam* save = new SaveSysteam();
	Inventory inventory;

	Item item(1);
	item.SetName("Laser");
	inventory.AddItem(item);

	Item item2(2);
	item2.SetName("bajs");
	inventory.AddItem(item2);

	inventory.Save();
	delete save;
	system("pause");
	return 0;
}

