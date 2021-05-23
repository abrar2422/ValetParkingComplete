#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds {
	const int MAX_NO_OF_ITEMS = 10;
	class Menu;
	class MenuItem {
		char* m_item;
		friend class Menu;
		MenuItem(const char* str);
		std::ostream& display(std::ostream& os = std::cout)const;
		MenuItem(const MenuItem& item) = delete;
		~MenuItem();
	};
	class Menu {
		char* m_title;
		int m_numOfMenuItems;
		int m_identation;
		MenuItem* menu[MAX_NO_OF_ITEMS];
	public:

	};
}
#endif // !SDDS_MENU_H
