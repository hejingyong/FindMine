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

	//��Ǻ��Ѿ��򿪵�����
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

// ��������Ķ�����ʤ��
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

	//�Ѿ��򿪵�����
	if(mineItem->IsOpen())return;

	// �Ѿ����ȡ�����,û�б�ǵĽ��б�ǣ�����дif else ��
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

	if(item->IsMine()) return;//�������׵�����

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
	mineItem->IsOpen(true);// ���Լ�

	if(mineItem->Neighbour()==0)//��Χû���״���Χ�ķ���
	{
		for (int ii=-1;ii<=1;ii++)
		{
			for (int jj=-1;jj<=1;jj++)
			{
				int x = ii+i;
				int y = jj+j;

				if (x>=0&&x<_height&&y>=0&&y<_width&&!Get(x,y)->IsOpen())
					OpenMine(x,y);//Ƕ�״�
			}
		}
	}
}

void MineGrid::InitialMine()
{
	// ��������
	int mC = 0;
	while (mC<MineCont)
	{
		int num =( clock()+rand())%(_height*_width);
		int x = num /_width; // ����
		int y = num%_width; // ����

		if (!Get(x,y)->IsMine())
		{
			// ԭ�������׵����ó���
			Get(x,y)->IsMine(true);
			mC++;
		}	
	}
}

void MineGrid::InitialGrid()
{
	// ��ԭ
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
	// �����ڽ������׵�����
	for (int i=0;i<_height;i++)
		for (int j=0;j<_width;j++)
			SetNeghbour(i,j);
}
