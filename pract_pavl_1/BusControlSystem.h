#pragma once

namespace control
{
	struct Bus
	{
		int id;
		int route;
		char driver_name[30];
		bool on_the_way;
		void PrintBusInfo();
		Bus(int id, int route, char const* driver_name, bool on_the_way);		
	};
	struct BusList
	{
	private:
		struct Node
		{
			Bus* info;
			Node* prev = nullptr;
			Node* next = nullptr;
			Node(Bus* info);
		};
		Node* head = nullptr;
		Node* tail = nullptr;
	public:
		void Add(Bus* info);
		void AddFirst(Bus* info); //system command, not for the user
		void AddAfter(Bus* info, int id); ////system command, not for the user
		bool CheckID(int id);
		void BusDeparture(int id);
		void BusReturn(int id);
		void PrintEn_Route();
		void PrintAtHome();
		void PrintAll();
	};
}