#pragma once



class MineItem
{
private:
	bool _isOpen;
	bool _isMine;
	bool _isMark;
	int _Neighbour;

public:
	MineItem();
	~MineItem(void);

	bool IsOpen() const { return _isOpen; }
	void IsOpen(bool val) { _isOpen = val; }

	bool IsMine() const { return _isMine; }
	void IsMine(bool val) { _isMine = val; }

	int Neighbour() const { return _Neighbour; }
	void Neighbour(int val) { _Neighbour = val; }

	bool IsMark() const { return _isMark; }
	void IsMark(bool val) { _isMark = val; }

};
