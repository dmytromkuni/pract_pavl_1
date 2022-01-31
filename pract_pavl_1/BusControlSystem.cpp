#include "BusControlSystem.h"
#include <iostream>
#include <string>

control::Bus::Bus(int id, int route, char const* driver_name, bool on_the_way)
{
	this->id = id;
	this->route = route;
	strcpy_s(this->driver_name, driver_name);
	this->on_the_way = on_the_way;
}

control::BusList::Node::Node(Bus* info)
{
	this->info = info;
}

void control::Bus::PrintBusInfo()
{
	std::cout << "Id: " << this->id
		<< "\nRoute: " << this->route
		<< "\nDriver name: " << this->driver_name
		<< "\nIs on the way? ";
	if (this->on_the_way) std::cout << "Yes.\n\n";
	else std::cout << "No.\n\n";
}

void control::BusList::Add(Bus* info)
{
	Node* node = new Node(info);
	if (head == nullptr)
	{
		head = node;
		tail = node;
		std::cout << "The new bus with ID (" << info->id << ") is succesfully added to the system!\n\n";
	}
	else
	{		
		if (!this->CheckID(info->id))
		{
			tail->next = node;
			node->prev = tail;
			tail = node;
			std::cout << "The new bus with ID (" << info->id << ") is succesfully added to the system!\n\n";
		}
		else std::cout << "Unfortunately, bus with such ID (" << info->id << ") already exists.\n\n";	
	}
}

void control::BusList::AddFirst(Bus* info)
{
	Node* node = new Node(info);
	if (head == nullptr)
	{
		head = node;
		tail = node;
		std::cout << "The new bus with ID (" << info->id << ") is succesfully added to the system!\n\n";
	}
	else
	{
		if (!this->CheckID(info->id))
		{
			head->prev = node;
			node->next = head;
			head = node;
			std::cout << "The new bus with ID (" << info->id << ") is succesfully added to the system!\n\n";
		}
		else std::cout << "Unfortunately, bus with such ID (" << info->id << ") already exists.\n\n";
	}
}

void control::BusList::AddAfter(Bus* info, int id)
{
	Node* node = new Node(info);
	Node* iter = head;
	while (iter)
	{
		if (iter->info->id == id)
		{
			Node* temp = iter->next;
			node->next = temp;
			node->prev = iter;
			if(temp) temp->prev = node; //if the func doesn't add a bus as the last element, prev. for the next element must be changed
			iter->next = node;
			std::cout << "The new bus with ID (" << id << ") is succesfully added to the system!\n\n";
			break;
		}
		iter = iter->next;
	}
	if (!iter) std::cout << "Unfortunately, bus with such ID (" << id << ") doesn't exist.\n\n";
}

bool control::BusList::CheckID(int id)
{
	Node* iter = head;
	bool result = false;
	while (iter)
	{
		if (iter->info->id == id)
		{
			result = true;
		}
		iter = iter->next;
	}
	return result;
}

void control::BusList::BusDeparture(int id)
{
	Node* iter = head;
	while (iter)
	{
		if (iter->info->id == id)
		{
			if (!iter->info->on_the_way)
			{
				iter->info->on_the_way = true;
				std::cout << "The bus with ID (" << id << ") succesfully departed!\n\n";
			}
			else std::cout << "The bus with such ID (" << id << ") is already departed.\n\n";
			break;
		}
		iter = iter->next;
	}
	if (!iter) std::cout << "Unfortunately, bus with such ID (" << id << ") doesn't exist.\n\n";
}

void control::BusList::BusReturn(int id)
{
	Node* iter = head;
	while (iter)
	{
		if (iter->info->id == id)
		{
			if (iter->info->on_the_way)
			{
				iter->info->on_the_way = false;
				std::cout << "The bus with ID (" << id << ") succesfully returned!\n\n";
			}
			else std::cout << "The bus with such ID (" << id << ") is already in the bus depot.\n\n";
			break;
		}
		iter = iter->next;
	}
	if (!iter) std::cout << "Unfortunately, bus with such ID (" << id << ") doesn't exist.\n\n";
}

void control::BusList::PrintEn_Route()
{
	bool no_buses_on_the_way = true;
	Node* iter = head;
	if (!head)
	{
		std::cout<<"There are no buses in the system.\n\n";
		return;
	}
	while (iter)
	{
		if (iter->info->on_the_way == true)
		{
			iter->info->PrintBusInfo();
			no_buses_on_the_way = false;
		}
		iter = iter->next;
	}
	if(no_buses_on_the_way) std::cout << "There are no buses on the way.\n\n";
}

void control::BusList::PrintAtHome()
{
	bool no_buses_at_home = true;
	Node* iter = head;
	if (!head)
	{
		std::cout << "Unfortunately, there are no buses in the system.\n\n";
		return;
	}
	while (iter)
	{
		if (iter->info->on_the_way == false)
		{
			iter->info->PrintBusInfo();
			no_buses_at_home = false;
		}
		iter = iter->next;
	}
	if (no_buses_at_home) std::cout << "There are no buses in the bus depot.\n\n";
}

void control::BusList::PrintAll()
{
	Node* iter = head;
	while (iter)
	{
		iter->info->PrintBusInfo();
		iter = iter->next;
	}
	if (!head) std::cout << "List is empty at the moment.\n\n";
}


