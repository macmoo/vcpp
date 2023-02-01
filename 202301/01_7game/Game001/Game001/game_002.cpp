// ************************************************************
// * ����
//   https://beltoforion.de/en/game_of_life/
// ************************************************************
// [1] ���
#include <stdio.h>	// ǥ�� �����
#include <stdlib.h> // ǥ�� ���̺귯�� system("cls")
#include <string.h> // ���ڿ� ���� memcpy
#include <conio.h>	// �ܼ� �Է� _getch()
#include <time.h>	// �ð� ���� clock()
// ************************************************************
// [2] ���� ����
#define FIELD_WIDTH		(160)
#define FIELD_HEIGHT	(160)
#define FPS				(10)		// 1�ʴ� ����Ƚ��
#define INTERVAL		(1000/FPS)	// ���� ����(�̸���)
// ************************************************************
// [3] ���� ����
// [3-1] �ʵ� ����
bool field[FIELD_HEIGHT][FIELD_WIDTH] =
{
	//{0,1,0},
	//{0,0,1},
	//{1,1,1},
};
// ************************************************************
// [4] �Լ� ����
// ------------------------------
// [4-1] �ʵ� �׸��� �Լ�
void drawField()
{
	system("cls");
	// [4-1-2] �ʵ��� ��
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		// [4-1-3] �ʵ��� ��
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			// [4-1-4] ��� ������ ��, �׾����� ��
			printf("%s", field[y][x] ? "��" : "��");
		}
		printf("\n"); // [4-1-5] �� �� �׷����� ����
	}
}
// ------------------------------
// [4-2] ��� ���� ������ ����ִ� ���� ���� ���� �Լ�
int getLivingCellsCount(int _x, int _y)
{
	// [4-2-1]
	int count = 0;
	// [4-2-2] ��� ���� ���� 1ĭ�� �ݺ�
	for (int y = _y - 1; y <= _y + 1; y++)
	{
		//// [4-2-3] ���� ���� ���� ���� ���, ���� ���� ������ ����
		//if ((y < 0) || (y >= FIELD_HEIGHT))
		//{
		//	continue; // [4-2-4] 
		//}

		// [4-2-5] ���� ������ y ��ǥ�� ����
		int roopedY = (FIELD_HEIGHT + y) % FIELD_HEIGHT;

		// [4-2-6] ����� ���� �¿� 1ĭ�� �ݺ�
		for (int x = _x - 1; x <= _x + 1; x++)
		{
			//// [4-2-7] �¿� ���� ���� ���� ���, ���� ���� ������ ����
			//if ((x < 0) || (x >= FIELD_WIDTH))
			//{
			//	continue; // [4-2-8]
			//}

			// [4-2-8] �¿� ������ x ��ǥ�� ����
			int roopedX = (FIELD_WIDTH + x) % FIELD_WIDTH;

			// [4-2-10] ����� ��ǥ�� �߽ɼ����� ����
			if ((roopedX == _x) && (roopedX == _y))
			{
				continue; // [4-2-11]
			}

			// [4-2-12] ��� ���� ��� ������ 1, �׾� ������ 0�� ����
			count += field[roopedY][roopedX];
		}
	}
	// [4-2-13]
	return count;
}
// ------------------------------
// [4-3] 1���ܺ��� �ùķ��̼��� �����ϴ� �Լ�
void stepSimulation()
{
	// [4-3-1] 
	bool nextField[FIELD_HEIGHT][FIELD_WIDTH] = {};

	// [4-3-2] ��� �� �ݺ�
	for (int y = 0; y < FIELD_WIDTH; y++)
	{
		// [4-3-3] ��� �� �ݺ�
		for (int x = 0; x < FIELD_HEIGHT; x++)
		{
			// [4-3-4] ��� ���� ������ ����ִ� ���� ���� ����
			int livingCellCount = getLivingCellsCount(x, y);
			// [4-3-5] ������ ����ִ� ���� ���� �б�
			// - 1�� : ����(Φ��)�� ���
			// - 2�� : ��������
			// - 3�� : ���� �Ǵ� ź��(����)
			// - 4�� �̻� : ����(Φ��)�� ���
			// [4-3-5]
			if (livingCellCount <= 1)
			{
				// [4-3-6] ��� ���� ���
				nextField[y][x] = false;
			}
			// [4-3-7]
			else if (livingCellCount == 2)
			{
				// [4-3-8] ��������
				nextField[y][x] = field[y][x];
			}
			// [4-3-9]
			else if (livingCellCount == 3)
			{
				// [4-3-10] ��� ���� ź��/����
				nextField[y][x] = true;
			}
			// [4-3-11] 4�� �̻�
			else
			{
				nextField[y][x] = false;
			}
		}
	}

	// [4-3-13] ���� ���� �ʵ带 ���� �ʵ忡 ����
	memcpy(field, nextField, sizeof field);

}
// ------------------------------
// [4-4] ������ �ʵ忡 �����ϴ� �Լ�
void patternTransfer(int _destX, int _destY, int _srcWidth, int _srcHeight, bool* _nPattern)
{
	// [4-4-1] ���ϳ��� ��� �� �ݺ�
	for (int y = 0; y < _srcHeight; y++)
	{
		// [4-4-2] ���ϳ��� ��� �� �ݺ�
		for (int x = 0; x < _srcWidth; x++)
		{
			// [4-4-3] ������ �ʵ忡 ������
			field[_destY + y][_destX + x] = _nPattern[y*_srcWidth+x];
		}
	}
	// [4-4-]
	// [4-4-]
}

// ------------------------------
int main()
{
	// [4-5-1] ������ ��
	const int patternWidth	= 10;
	// [4-5-2] ������ ����
	const int patternHeight	= 8;
	// [4-5-3] ���ϼ���
	bool pattern[patternHeight][patternWidth] = 
	{
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,1,0,1,1,0},
		{0,0,0,0,0,1,0,1,0,0},
		{0,0,0,0,0,1,0,0,0,0},
		{0,0,0,1,0,0,0,0,0,0},
		{0,1,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0}
	};
	// [4-5-4] ������ �ʵ��� �߽����� ����
	patternTransfer(
		FIELD_WIDTH  / 2 - patternWidth  / 2,
		FIELD_HEIGHT / 2 - patternHeight / 2,
		patternWidth,
		patternHeight,
		(bool*)pattern);

	// [4-5-5] ������ ��� �ð��� ����
	clock_t lastClock = clock();
	
	// [4-5-6] main loop
	while (1)
	{
		// [4-5-7] ������ ��� �ð��� ����
		clock_t newClock = clock();
		// [4-5-8] ������ ����ð�����, ��� �ð��� ��� ���� �ʾҴٸ�
		if (newClock < lastClock + INTERVAL)
		{
			// [4-5-9] ��� ���·� ��
			continue;
		}
		// [4-5-10] ���� ����ð��� ������ ����ð����� ����
		lastClock = newClock;
		// [4-5-11] �ʵ� �׸�
		drawField();
		// [4-5-12] �Է� ���
		// _getch();
		// [4-5-13] �ùķ��̼� ����
		stepSimulation();
	}
}
// ------------------------------


// ************************************************************
