#ifndef MYARRAY_H
#define MYARRAY_H

namespace davics {

	template<class T>
	class myarray
	{

	private:
		int arr_siz{ 0 };
		T* ptr{ nullptr };

	public:
		T* ArrayPtr{};
		int Position{};

		myarray(int);

		T& operator[] (int);
		T* begin() const;
		T* end() const;

		void Add(T);
		bool empty() const;
		void Remove(T);

		~myarray();

	};

	///...............................

	template<class T>
	void myarray<T>::Remove(T func)
	{
		try {

			if (this == nullptr) throw std::runtime_error("Initialisation Error!");

			if (this->arr_siz > 0)
			{

				int temp = 0;
				bool found = false;

				for (int index = 0; index != this->Position; ++index)
				{
					if (this->ptr[index] == func)
					{
						temp = index;
						found = true;
						break;
					}
				}

				if (found) {

					for (int j = temp + 1; j != Position; ++j, ++temp)
					{
						this->ptr[temp] = this->ptr[j];
						this->ptr[j] = nullptr;
					}

					this->Position -= 1;
				}
			}

			else throw std::out_of_range("Collection Empty!");
		}

		catch (std::out_of_range e)
		{
			throw e;
		}

		catch (std::runtime_error e)
		{
			throw e;
		}

	}
	template<class T>
	void myarray<T>::Add(T func)
	{

		try {

			if (this == nullptr) throw std::runtime_error("Initialisation Error!");

			if (this->Position != this->arr_siz)
			{
				this->ptr[this->Position++] = func;
			}

			else throw std::out_of_range("Collection out of Capacity");
		}

		catch (std::out_of_range e)
		{
			throw e;
		}

		catch (std::runtime_error e)
		{
			throw e;
		}
	}


	template<class T>
	bool myarray<T>::empty() const
	{
		try {

			if (this == nullptr) throw std::runtime_error("Initialisation Error!");

			if (this->Position == 0)
				return true;

			else
				return false;
		}

		catch (std::runtime_error e)
		{
			throw e;
		}


	}

	template<class T>
	myarray<T>::myarray(int size)
	{
		try
		{
			if (size > 0)
			{
				this->arr_siz = size;
				ptr = new T[size];

			}
			else throw std::runtime_error("array size must be greater than zero!");
		}

		catch (std::runtime_error e)
		{
			throw e;
		}
	}

	template<class T>
	T& myarray<T>::operator[](int index)
	{

		try
		{
			if (this == nullptr) throw std::runtime_error("Initialisation Error!");

			if (index >= this->arr_siz || index < 0) throw std::out_of_range("out of Range!");

		}

		catch (std::out_of_range e)
		{
			throw e;
		}

		return this->ptr[index];
	}


	template<class T>
	T* myarray<T>::begin() const
	{
		try
		{
			if (this == nullptr) throw std::runtime_error("Initialisation Error!");

			if (this->arr_siz == 0) throw std::runtime_error("no elements");

		}

		catch (std::runtime_error e)
		{
			throw e;
		}
		return &this->ptr[0];
	}

	template<class T>
	T* myarray<T>::end() const
	{
		try
		{
			if (this == nullptr) throw std::runtime_error("Initialisation Error!");

			if (this->arr_siz == 0) throw std::runtime_error("no elements");

		} ///end of try

		catch (std::runtime_error e)
		{
			throw e;
		}

		return &this->ptr[this->Position];
	}

	template<class T>
	myarray<T>::~myarray()
	{
		if (this->arr_siz > 0) { delete[] ptr; }
	}

}


#endif // MYARRAY_H_INCLUDED
