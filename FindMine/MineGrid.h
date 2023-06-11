#pragma once
#include "MineItem.h"

class CFindMineView;

typedef void (CFindMineView::*Win)();
typedef void (CFindMineView::*Lost)();

class MineGrid
{
private:
    int _width;
	int _height;

    MineItem **_grid;

	Win  _winFunc;
	Lost  _lostFunc;
	CFindMineView *_view;

public:
	static const int MineCont = 10;

private:
	bool IsWin() ;
	void OpenMine(int i,int j);
	void SetNeghbour(int i,int j );

	void InitialGrid();
	void InitialMine();
	void InitialNeighbour();

public:
	MineGrid(int w,int h,Win winFunc,Lost lostFunc,CFindMineView *view);
	~MineGrid(void);

	int Width() const { return _width; }
	int Height() const { return _height; }

	MineItem *Get(int i,int j);
	void Initialization();

	void Mark(int i,int j);
	void Open(int i,int j);
    void OpenAll();
};
