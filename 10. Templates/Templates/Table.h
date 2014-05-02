#ifndef TABLE_H
#define TABLE_H

template <typename T>
class Table
{
public:
	Table();
	Table(int rows, int columns);
	Table(int rows, int columns, const T& value);
	Table(const Table<T>& otherTable);
	~Table();

	Table<T>& operator=(const Table<T>& otherTable);
	T& operator()(int row, int column);

	int GetRows() const;
	int GetColumns() const;
	void Resize(int rows, int columns);
	void Resize(int rows, int columns, const T& value);

private:
	void Destroy();

private:
	int rows;
	int columns;
	T** matrix;
};

template <typename T>
Table<T>::Table() : Table<T>(0, 0, T())
{
}

template <typename T>
Table<T>::Table(int rows, int columns) : Table<T>(rows, columns, T())
{
}

template <typename T>
Table<T>::Table(int rows, int columns, const T& value)
{
	this->rows = 0;
	this->columns = 0;
	this->matrix = 0;

	this->Resize(rows, columns, value);
}

template <typename T>
Table<T>::Table(const Table<T>& otherTable)
{
	this->rows = 0;
	this->columns = 0;
	this->matrix = 0;

	*this = otherTable;
}

template <typename T>
Table<T>::~Table()
{
	this->Destroy();
}

template <typename T>
Table<T>& Table<T>::operator=(const Table<T>& otherTable)
{
	if (this != &otherTable)
	{
		this->Resize(otherTable.GetRows(), otherTable.GetColumns());

		for (int row = 0; row < this->GetRows(); row++)
		{
			for (int col = 0; col < this->GetColumns(); col++)
			{
				this->matrix[row][col] = otherTable->matrix[row][col];
			}
		}
	}

	return *this;
}

template <typename T>
T& Table<T>::operator()(int row, int column)
{
	return this->matrix[row][column];
}

template <typename T>
int Table<T>::GetRows() const
{
	return this->rows;
}

template <typename T>
int Table<T>::GetColumns() const
{
	return this->columns;
}

template <typename T>
void Table<T>::Resize(int rows, int columns)
{
	this->Resize(rows, columns, T());
}

template <typename T>
void Table<T>::Resize(int rows, int columns, const T& value)
{
	this->Destroy();

	this->rows = rows;
	this->columns = columns;

	this->matrix = new T*[rows];
	for (int row = 0; row < rows; row++)
	{
		this->matrix[row] = new T[columns];

		for (int col = 0; col < columns; col++)
		{
			this->matrix[row][col] = value;
		}
	}
}

template <typename T>
void Table<T>::Destroy()
{
	if (this->matrix)
	{
		for (int row = 0; row < this->rows; row++)
		{
			if (this->matrix[row])
			{
				delete[] this->matrix[row];
				this->matrix[row] = 0;
			}
		}

		delete[] this->matrix;
		this->matrix = 0;
	}

	this->rows = 0;
	this->columns = 0;
}

#endif // TABLE_H
