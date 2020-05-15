#pragma once

namespace davicsList
{

	template<typename Tvalue>
	class LinkedList
	{

	private:
#pragma region PrivateMembers
		struct Nodes
		{
			typename Tvalue data{ nullptr };
			Nodes* nextNode{ nullptr };
		};

		Nodes* headNode{ nullptr };
		Nodes* pointerPos{ nullptr };
		typename Tvalue endPointer{ nullptr };

#pragma endregion



	public:
#pragma region PublicMembers

		typename Tvalue startPointer{ nullptr };

		void Add(typename Tvalue v);

		void deleteNode(typename Tvalue);

		void updatePointer();

		void InitPointer();

		bool empty();

		Tvalue getNextPointer();


		~LinkedList()
		{
			headNode = nullptr;
		}


#pragma endregion

	};

#pragma region myLinkedlist functionDefinitions

	template<typename Tvalue>
	void LinkedList<Tvalue>::updatePointer()
	{
		this->startPointer = this->endPointer;
	}

	template<typename Tvalue>
	void LinkedList<Tvalue>::InitPointer()
	{
		this->startPointer = this->headNode->data;
	}


	template<typename Tvalue>
	Tvalue LinkedList<Tvalue>::getNextPointer()
	{
		Nodes* temp = pointerPos;

		if (pointerPos != nullptr)
		{
			if (pointerPos->data == this->startPointer)
			{
				pointerPos = pointerPos->nextNode;

				if (pointerPos != nullptr)
				{
					endPointer = pointerPos->data;
				}

				return temp->data;
			}
		}

		else
		{
			this->pointerPos = headNode;
			return nullptr;
		}
	}


	template<typename Tvalue>
	void LinkedList<Tvalue>::Add(typename Tvalue v)
	{
		Nodes* newNode = new Nodes;
		newNode->nextNode = nullptr;
		newNode->data = v;

		Nodes* traverseNode = nullptr;

		if (this->headNode == nullptr)
		{
			headNode = newNode;
			this->startPointer = headNode->data;
			this->pointerPos = headNode;
		}

		else
		{
			traverseNode = headNode;

			while (traverseNode->nextNode != nullptr) traverseNode = traverseNode->nextNode;

			traverseNode->nextNode = newNode;
			this->pointerPos = headNode;
		}
	}///


	template<typename Tvalue>
	void LinkedList<Tvalue>::deleteNode(typename Tvalue value)
	{
		try
		{
			if (headNode == nullptr) throw std::runtime_error("Collection Empty!");

			Nodes* traverseNode = nullptr;
			Nodes* PreviousNode = nullptr;

			if (headNode->data == value)
			{
				traverseNode = headNode->nextNode;
				delete headNode;
				headNode = traverseNode;
				this->startPointer = headNode->data;
				this->pointerPos = headNode;
			}

			else
			{
				traverseNode = headNode;

				while (traverseNode != nullptr && traverseNode->data != value)
				{
					PreviousNode = traverseNode;
					traverseNode = traverseNode->nextNode;
				}


				if (traverseNode)
				{
					PreviousNode->nextNode = traverseNode->nextNode;
					delete traverseNode;
				}

				this->pointerPos = headNode;
			}
		}

		catch (std::runtime_error e) {
			throw e;
		}

	}

	template<typename Tvalue>
	bool LinkedList<Tvalue>::empty()
	{
		if (headNode == nullptr)
			return true;
		else return false;
	}

#pragma endregion


}