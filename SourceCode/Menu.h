#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds {
	const int MAX_NO_OF_ITEMS = 10;
	class Menu;
	class MenuItem {
	//member variable
		char* m_item = nullptr;
		friend class Menu;
	//constructors & deconstructors
		MenuItem(const char* str);
		MenuItem(const MenuItem&) = delete;
		virtual ~MenuItem();
	//member functions
		std::ostream& display(std::ostream& os = std::cout)const;
	//overloads
		MenuItem& operator=(const MenuItem&) = delete;

	};
	class Menu {
	//member variable
		char* m_title;
		int m_numOfMenuItems;
		int m_indentation;
		MenuItem* menu_items[MAX_NO_OF_ITEMS];
	public:
	//constructor & deconstructor
		Menu(const char*, int m = 0);
		Menu(const Menu&);
		virtual ~Menu();
	//member functions
		bool isEmpty()const;
		std::ostream& display(std::ostream& os = std::cout)const;
	//overloads
		Menu& operator=(const Menu&);
		operator bool() const;
	};
}
#endif // !SDDS_MENU_H
