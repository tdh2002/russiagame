#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>

#define SMALL_BLOCK_SIZE    25

/*
  OO
  OO
*/


int block0[3][4][4] =
{
	{
		{1,1,0,0},
		{1,1,0,0},
		{0,0,0,0},
		{0,0,0,0}
	},

	{
		{1,0,0,0},
		{1,0,0,0},
		{1,0,0,0},
		{1,0,0,0}
	},

	{
		{1,1,1,1},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	}

};



//static int *block[1] = {&block0[0][0]};

int Color ;
int bkColor ;
int fillColor ;

void drawblock (int x, int y, int number)
{
//	int i, j;
//	for (i = 0; i < 4; i++)
//		for (j = 0; j < 4; j++)
//		{
		//	if (block0[number][j][i] == 1)
		//		bar3d(x + i * SMALL_BLOCK_SIZE, y + j * SMALL_BLOCK_SIZE , x + (i + 1) * SMALL_BLOCK_SIZE - 3, y + (j+1) * SMALL_BLOCK_SIZE -3, 3 , 1);
		switch (number)
		{
		case 1:  /* 方块****  */
			bar3d(x, y, x + 1 * SMALL_BLOCK_SIZE - 3, y + 1 * SMALL_BLOCK_SIZE -3, 3 , 1);
			bar3d(x + 1 * SMALL_BLOCK_SIZE , y, x + 2 * SMALL_BLOCK_SIZE - 3, y + 1 * SMALL_BLOCK_SIZE -3, 3 , 1);
			bar3d(x + 2 * SMALL_BLOCK_SIZE , y, x + 3 * SMALL_BLOCK_SIZE - 3, y + 1 * SMALL_BLOCK_SIZE -3, 3 , 1);
			bar3d(x + 3* SMALL_BLOCK_SIZE , y, x + 4 * SMALL_BLOCK_SIZE - 3, y + 1 * SMALL_BLOCK_SIZE -3, 3 , 1);
			break;
			default:break;
		}
//		}
}




void DrawSmallBlock(int x , int y , bool fDispFlag)
{
    if(fDispFlag)
    {
        setfillstyle(fillColor);
        setcolor(Color);
    }
    else
    {
//        setfillstyle(RGB(0,0,0));
//        setcolor(RGB(0,0,0));
        setfillstyle(BLACK);
        setcolor(BLACK);
    }
	drawblock (x,y,1);
//     bar3d(x , y , x + SMALL_BLOCK_SIZE - 4 , y + SMALL_BLOCK_SIZE - 4 , 3 , 1);
//     y += SMALL_BLOCK_SIZE ;
//     bar3d(x , y , x + SMALL_BLOCK_SIZE - 4 , y + SMALL_BLOCK_SIZE - 4 , 3 , 1);
//     y += SMALL_BLOCK_SIZE ;
//     bar3d(x , y , x + SMALL_BLOCK_SIZE - 4 , y + SMALL_BLOCK_SIZE - 4 , 3 , 1);
//     x += SMALL_BLOCK_SIZE ;
//     bar3d(x , y , x + SMALL_BLOCK_SIZE - 4 , y + SMALL_BLOCK_SIZE - 4 , 3 , 1);
}

void main(void)
{
    time_t t;
    int Key ;
    int x , y ;
    clock_t start, end;


    start = clock();
    end = start ;


    srand((unsigned) time(&t));

    initgraph(480 , 640);

    fillColor = RGB(rand() % 256 , rand() % 256 , rand() % 256);
    Color = YELLOW ;

    setcolor(Color);
    setfillstyle(fillColor);

    x = 200 ;
    y = 50 ;
	rectangle(0,0, 320, 480);

    while(1)
    {
        DrawSmallBlock(x , y , 1);
        end = clock();
        if(end - start > 100)
        {
            start = end ;
            //时间超过600ms
            DrawSmallBlock(x , y , 0);
			if (y < 480)  /* 方块是否固定  */
			{
				y += SMALL_BLOCK_SIZE;
				/* 消行 */
			}
			else/* 出新方块 */
				;
        }

        if(kbhit())
        {
            Key = getch();
            if(Key == 224)
            {
                Key = getch();
                switch(Key)
                {
                    case 80:
                        DrawSmallBlock(x , y , 0);
                        y += SMALL_BLOCK_SIZE ;
                        break;
                    case 72:
						/*  */
                        //DrawSmallBlock(x , y , 0);
                        //y -= SMALL_BLOCK_SIZE ;
                        break;
                    case 77:        //向右
                        DrawSmallBlock(x , y , 0);
                        x += SMALL_BLOCK_SIZE ;
                        break;
                    case 75:
                        DrawSmallBlock(x , y , 0);
                        x -= SMALL_BLOCK_SIZE ;
                        break;
                    default:
                        break;
                }
            }
        }
    }

    closegraph();
}


