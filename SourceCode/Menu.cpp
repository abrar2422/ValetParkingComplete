#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"

namespace sdds {
	/*****MenuItem Class*****/
	MenuItem::MenuItem(const char* str) {
		if (str != nullptr && str[0] != 0) {
			m_item = new char[strlen(str) + 1];
			strcpy(m_item, str);
		}
		else {
			m_item = nullptr;
		}
	}
	std::ostream& MenuItem::display(std::ostream& os)const {
		if (m_item != nullptr) {
			os << m_item << std::endl;
		}
		return os;
	}
	MenuItem::~MenuItem(){
		delete[] m_item;
	}

	/*****Menu class*****/

	//constructors and deconstructors
	Menu::Menu(const char* str, int num) {
		if (str != nullptr && str[0] != 0) {
			m_title = new char[strlen(str) + 1];
			strcpy(m_title, str);
		}
		else {
			m_title = nullptr;
		}
		m_indentation = num;
	}
	Menu::Menu(const Menu& src) {
		*this = src;
	}
	Menu::~Menu() {}
	//Member functions
	bool Menu::isEmpty()const {
		return m_title == nullptr || m_numOfMenuItems <= 0;
	}
	std::ostream& Menu::display(std::ostream& os)const {
		if (isEmpty()) {
			os << "Invalid Menu" << std::endl;
		}
		else if (m_numOfMenuItems == 0) {
			os << "No Items to display!" << std::endl;
		}
		return os;
	}
	//overloads
	Menu& Menu::operator=(const Menu& src) {
		if (this != &src) {
			m_numOfMenuItems = src.m_numOfMenuItems;
			m_indentation = src.m_indentation;

			delete[] m_title;
			if (m_title != nullptr) {
				m_title = new char[strlen(m_title) + 1];
				strcpy(m_title, src.m_title);
			}
			else {
				m_title = nullptr;
			}

			for (int i = 0; i < m_numOfMenuItems; i++ ) {
				delete[] menu_items[i];
			}
			for (int i = 0; i < src.m_numOfMenuItems; i++) {
				menu_items[i] = new MenuItem(src.menu_items[i]->m_item);
			}
		}
		else {
			m_title = nullptr;
		}
		return *this;
	}
	Menu::operator bool()const { 
		return m_title != nullptr && m_numOfMenuItems > 0; 
	}

}