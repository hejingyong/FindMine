#include "StdAfx.h"
#include "MineGrid.h"


MineGrid::MineGrid( int w,int h,Win winFunc,Lost lostFunc,CFindMineView *view )
{
	_width =w;
	_height = h;

	_view = view;
	_winFunc = winFunc;
	_lostFunc = lostFunc;

	_grid = new MineItem *[w*h];
	for (int i=0;i<_height;i++)
		for (int j=0;j<_width;j++)
			_grid[i*_width+j] =  new MineItem();
}

MineGrid::~MineGrid(void)
{
	for (int i=0;i<_height;i++)
		for (int j=0;j<_width;j++)
			delete Get(i,j);

	delete _grid;
}

MineItem *MineGrid::Get( int i,int j )
{
	return _grid[i*_width+j];
}

void MineGrid::Initialization()
{
	InitialGrid();
	InitialMine();
	InitialNeighbour();
}

void MineGrid::Open( int i,int j )
{
	MineItem *mineItem =  Get(i,j);

	//标记和已经打开的跳过
	if(mineItem->IsOpen()||mineItem->IsMark()) return;

	if (mineItem->IsMine())
	{
		(_view->*_lostFunc)();
	}
	else
	{
		OpenMine(i,j);
		if(IsWin()) (_view->*_winFunc)();
	}
}

// 除雷以外的都打开算胜利
bool MineGrid::IsWin() 
{
	bool isWin = true;
	for (int i=0;i<_height;i++)
	{
		for (int j=0;j<_width;j++)
		{
			MineItem* item = Get(i,j);

			if (item->IsOpen())
				isWin =isWin&& true;
			else
				if (item->IsMine())
					isWin =isWin && true;
				else
					isWin = isWin && false;

			if(!isWin) break;
		}//end for j
		if(!isWin) break;
	}//end for i
	return isWin;
}

void MineGrid::Mark( int i,int j )
{
	MineItem *mineItem =  Get(i,j);

	//已经打开的跳过
	if(mineItem->IsOpen())return;

	// 已经标记取消标记,没有标记的进行标记，懒得写if else 了
	mineItem->IsMark(!mineItem->IsMark());
}

void MineGrid::OpenAll()
{
	for (int i=0;i<_height;i++)
		for (int j=0;j<_width;j++)
			Get(i,j)->IsOpen(true);
}


void MineGrid::SetNeghbour( int i,int j )
{
	MineItem *item =  Get(i,j);

	if(item->IsMine()) return;//自身是雷的跳过

	int mc = 0;
	for (int ii=-1;ii<=1;ii++)
	{
		for (int jj=-1;jj<=1;jj++)
		{
			int x = ii+i;
			int y = jj+j;

			if (x>=0&&x<_height&&y>=0&&y<_width&&Get(x,y)->IsMine())
				mc++;
		}
	}

	item->Neighbour(mc);
}

void MineGrid::OpenMine( int i,int j )
{
	MineItem *mineItem =  Get(i,j);
	mineItem->IsOpen(true);// 打开自己

	if(mineItem->Neighbour()==0)//周围没有雷打开周围的方格
	{
		for (int ii=-1;ii<=1;ii++)
		{
			for (int jj=-1;jj<=1;jj++)
			{
				int x = ii+i;
				int y = jj+j;

				if (x>=0&&x<_height&&y>=0&&y<_width&&!Get(x,y)->IsOpen())
					OpenMine(x,y);//嵌套打开
			}
		}
	}
}

void MineGrid::InitialMine()
{
	// 产生地雷
	int mC = 0;
	while (mC<MineCont)
	{
		int num =( clock()+rand())%(_height*_width);
		int x = num /_width; // 行数
		int y = num%_width; // 列数

		if (!Get(x,y)->IsMine())
		{
			// 原来不是雷的设置成雷
			Get(x,y)->IsMine(true);
			mC++;
		}	
	}
}

void MineGrid::InitialGrid()
{
	// 复原
	for (int i=0;i<_height;i++)
	{
		for (int j=0;j<_width;j++)
		{
			MineItem* item = Get(i,j);
			item->IsMine(false);
			item->IsOpen(false);
			item->IsMark(false);
			item->Neighbour(0);
		}
	}
}

void MineGrid::InitialNeighbour()
{
	// 设置邻接区域雷的数量
	for (int i=0;i<_height;i++)
		for (int j=0;j<_width;j++)
			SetNeghbour(i,j);
}
