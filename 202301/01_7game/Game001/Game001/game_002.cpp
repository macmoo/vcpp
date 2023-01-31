// ************************************************************
// [1] 헤더
#include <stdio.h>	// 표준 입출력
#include <stdlib.h> // 표준 라이브러리 system("cls")
#include <string.h> // 문자열 조작 memcpy
#include <conio.h>	// 콘솔 입력 _getch()
#include <time.h>	// 시간 관리 clock()
// ************************************************************
// [2] 정수 정의
#define FIELD_WIDTH		(12)
#define FIELD_HEIGHT	(12)
#define FPS				(10)		// 1초당 개신횟수
#define INTERVAL		(1000/FPS)	// 갱신 간격(미리초)
// ************************************************************
// [3] 변수 선언
// [3-1] 필드 선언
bool field[FIELD_HEIGHT][FIELD_WIDTH] =
{
	{0,1,0},
	{0,0,1},
	{1,1,1},
};
// ************************************************************
// [4] 함수 선언
// ------------------------------
// [4-1] 필드 그리는 함수
void drawField()
{
	system("cls");
	// [4-1-2] 필드의 행
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		// [4-1-3] 필드의 열
		for (int x = 0; x < FIELD_WIDTH; x++)
		{
			// [4-1-4] 살아 있으면 ■, 죽었으면 　
			printf("%s", field[y][x] ? "■" : "　");
		}
		printf("\n"); // [4-1-5] 한 행 그렸으면 개행
	}
}
// ------------------------------
// [4-2] 대상 셀과 인접한 살아있는 셀의 수를 세는 함수
int getLivingCellsCount(int _x, int _y)
{
	// [4-2-1]
	int count = 0;
	// [4-2-2] 대상 셀의 상하 1칸을 반복
	for (int y = _y - 1; y <= _y + 1; y++)
	{
		//// [4-2-3] 상하 루프 하지 않을 경우, 행이 범위 밖인지 판정
		//if ((y < 0) || (y >= FIELD_HEIGHT))
		//{
		//	continue; // [4-2-4] 
		//}

		// [4-2-5] 상하 루프한 y 좌표를 선언
		int roopedY = (FIELD_HEIGHT + y) % FIELD_HEIGHT;

		// [4-2-6] 대상의 셀의 좌우 1칸을 반복
		for (int x = _x - 1; x <= _x + 1; x++)
		{
			//// [4-2-7] 좌우 루프 하지 않을 경우, 열이 범위 밖인지 판정
			//if ((x < 0) || (x >= FIELD_WIDTH))
			//{
			//	continue; // [4-2-8]
			//}

			// [4-2-8] 좌우 루프한 x 좌표를 선언
			int roopedX = (FIELD_WIDTH + x) % FIELD_WIDTH;

			// [4-2-10] 대상의 좌표가 중심셀인지 판정
			if ((roopedX == _x) && (roopedX == _y))
			{
				continue; // [4-2-11]
			}

			// [4-2-12] 대상 셀이 살아 있으면 1, 죽어 있으면 0을 가산
			count += field[roopedY][roopedX];
		}
	}
	// [4-2-13]
	return count;
}
// ------------------------------
// [4-3] 1스텝분의 시뮬레이션을 실행하는 함수
void stepSimulation()
{
	// [4-3-1] 
	bool nextField[FIELD_HEIGHT][FIELD_WIDTH] = {};

	// [4-3-2] 모든 행 반복
	for (int y = 0; y < FIELD_WIDTH; y++)
	{
		// [4-3-3] 모든 열 반복
		for (int x = 0; x < FIELD_HEIGHT; x++)
		{
			// [4-3-4] 대상 셀과 인접한 살아있는 셀의 수를 선언
			int livingCellCount = getLivingCellsCount(x, y);
			// [4-3-5] 인전한 살아있는 셀의 수로 분기
			// - 1개 : 과소(過疎)로 사멸
			// - 2개 : 현상유지
			// - 3개 : 생존 또는 탄생(誕生)
			// - 4개 이상 : 과밀(過密)로 사멸
			// [4-3-5]
			if (livingCellCount <= 1)
			{
				// [4-3-6] 대상 셀을 사멸
				nextField[y][x] = false;
			}
			// [4-3-7]
			else if (livingCellCount == 2)
			{
				// [4-3-8] 현상유지
				nextField[y][x] = field[y][x];
			}
			// [4-3-9]
			else if (livingCellCount == 3)
			{
				// [4-3-10] 대상 셀을 탄생/생존
				nextField[y][x] = true;
			}
			// [4-3-11] 4개 이상
			else
			{
				nextField[y][x] = false;
			}
		}
	}

	// [4-3-13] 다음 스텝 필드를 현재 필드에 복사
	memcpy(field, nextField, sizeof field);

}
// ------------------------------
int main()
{
	// [4-5-5] 이전의 경과 시간을 선언
	clock_t lastClock = clock();
	
	// [4-5-6] main loop
	while (1)
	{
		// [4-5-7] 현재의 경과 시간을 선언
		clock_t newClock = clock();
		// [4-5-8] 이전의 경과시간에서, 대기 시간이 경과 하지 않았다면
		if (newClock < lastClock + INTERVAL)
		{
			// [4-5-9] 대기 상태로 함
			continue;
		}
		// [4-5-10] 이전 경과시간을 현재의 경과시간으로 갱신
		lastClock = newClock;
		// [4-5-11] 필드 그림
		drawField();
		// [4-5-12] 입력 대기
		// _getch();
		// [4-5-13] 시뮬레이션 개시
		stepSimulation();
	}
}
// ------------------------------


// ************************************************************
