// ************************************************************
// [1] 헤더
#include <stdio.h>  // [1-1]
#include <stdlib.h> // [1-2] 화면클리어하기 위한 라이브러리
#include <conio.h>  // [1-3] 콘솔입력 헤더
// ************************************************************
// [2] 정수
#define BOARD_WIDTH		(8)
#define BOARD_HEIGHT	(8)
// ************************************************************
// [3] 열거형
// [3-1] 턴의 종류
enum
{
	TURN_BLACK, // 흑
	TURN_WHITE, // 백
	TURN_NONE,  // 돌없음
	TURN_MAX    // 턴의 수
};
// ------------------------------
// [3-2] 방향 종류를 정의
enum
{
	DIRECTION_UP,           // [3-2-1] 上
	DIRECTION_UP_LEFT,      // [3-2-2] 左上
	DIRECTION_LEFT,         // [3-2-3] 左
	DIRECTION_DOWN_LEFT,    // [3-2-4] 左下
	DIRECTION_DOWN,         // [3-2-5] 下
	DIRECTION_DOWN_RIGHT,   // [3-2-6] 右下
	DIRECTION_RIGHT,        // [3-2-7] 右
	DIRECTION_UP_RIGHT,     // [3-2-8] 右上
	DIRECTION_MAX           // [3-2-9] 方向の数
};
// ************************************************************
// [4] 구조체
// [4-1] 벡터 구조체
typedef struct {
	int x, y; // [4-1-1] 좌표
} VEC2;
// ************************************************************
// [5] 변수
// ------------------------------
// [5-1] 石のアスキーアー
const char* diskAA[TURN_MAX] =
{
	"●",    // [5-1-1] TURN_BLACK    黒い石が置かれている
	"○",    // [5-1-2] TURN_WHITE    白い石が置かれている
	"×"     // [5-1-3] TURN_NONE     石が置かれていない
};
// ------------------------------
// [5-2] 턴의 이름 배열
const char* turnNames[] =
{
	"검정색", // TURN_BLACK
	"하얀색"  // TURN_WHITE
};
// ------------------------------
// [5-4] 방향을 선언
VEC2 directions[DIRECTION_MAX] = 
{
	{ 0,-1},    // [5-4-1] DIRECTION_UP          上
	{-1,-1},    // [5-4-2] DIRECTION_UP_LEFT     左上
	{-1, 0},    // [5-4-3] DIRECTION_LEFT        左
	{-1, 1},    // [5-4-4] DIRECTION_DOWN_LEFT   左下
	{ 0, 1},    // [5-4-5] DIRECTION_DOWN        下
	{ 1, 1},    // [5-4-6] DIRECTION_DOWN_RIGHT  右下
	{ 1, 0},    // [5-4-7] DIRECTION_RIGHT       右
	{ 1,-1}     // [5-4-8] DIRECTION_UP_RIGHT    右上
};

// ------------------------------
// [5-5] 각 칸의 상태를 선언
int board[BOARD_HEIGHT][BOARD_WIDTH];
// ------------------------------
// [5-6] 커서의 좌표 선언
VEC2 cursorPosition;
// ------------------------------
// [5-7] 현재 턴
int turn;
// ************************************************************
// [6] 함수
// ------------------------------
// [6-1] 벡터를 더하는 함수
VEC2 vecAdd(VEC2 _v0, VEC2 _v1)
{
	// [6-1-2] 더한 벡터를 반환
	return 
	{
		_v0.x + _v1.x,
		_v0.y + _v1.y
	};
}

// ------------------------------
// [6-2] 돌을 둘 수 있나 확인하는 함수
bool checkCanPlace(int _color		// 돌의 색
				   , VEC2 _pos)		// 좌표
{
	// [6-2-1] 판단 플래그
	bool canPlace = false;
	// [6-2-2] 대상 좌표에 돌이 놓여 있나 확인
	if (board[_pos.y][_pos.x] != TURN_NONE)
	{
		// [6-2-3] 돌이 있으면 둘 수 없다.
		return false;
	}
	// [6-2-4] 상대의 돌의 색을 선언
	int opponent = _color ^ 1;
	
	// [6-2-5] 모든 방향 반복
	for(int i=0 ; i<DIRECTION_MAX ; i++)
	{
		// [6-2-6] 현재 체크중의 좌료
		VEC2 curPos = _pos;
		// [6-2-7] 옆 칸으로 이동
		curPos = vecAdd(curPos, directions[i]);
		// [6-2-8] 상대의 돌인지 판정
		if (board[curPos.y][curPos.x] != opponent)
		{
			// [6-2-9] 상대의 돌이 아니라면, 그 방향의 체크를 중지
			continue;

		}
	}
	// [6-2-] 
	// [6-2-] 
	// [6-2-] 
	// [6-2-] 
	// [6-2-] 

	// [6-2-24] 반환
	return canPlace;
}

// [6-5] 화면 그리는 함수
void drawScreen()
{
	// [6-5-1] 화면 클리어
	system("cls");
	// [6-5-2]
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		// [6-5-3]
		for (int x = 0; x < BOARD_WIDTH; x++)
			printf("%s", diskAA[board[y][x]] ); // [6-5-4]
		// [6-5-6] 대상의 행이 커서와 같은 행인지 판정
		if (y == cursorPosition.y)
		{
			printf("←"); // [6-5-7]
		}
		printf("\n"); // [6-5-8] 개행
	}
	// [6-5-10] 판의 열 반복
	for (int x = 0; x < BOARD_WIDTH; x++)
	{
		// [6-5-11] 커서가 같은 열인지 판정
		if (x == cursorPosition.x)
		{
			printf("↑"); // [6-5-12]
		}
		else {
			printf("  "); // [6-5-13]
		}
	}
	// [6-5-14] 개행
	printf("\n");
	
	// [6-5-16] 현재 턴 메시지
	printf("%s의 턴이다.\n", turnNames[turn]);
}
// ------------------------------
// [6-7] 초기화 함수
void init()
{
	// [6-7-1] 초기화
	for (int y = 0; y < BOARD_HEIGHT; y++)
	{
		// [6-7-2]
		for (int x = 0; x < BOARD_WIDTH; x++)
		{
			board[y][x] = TURN_NONE; // [6-7-3]
		}
	}
	// [6-7-4] 판 중앙의 우상, 좌하에 흑돌을 둔다
	board[4][3] = board[3][4] = TURN_BLACK;
	// [6-7-5] 흰돌
	board[4][4] = board[3][3] = TURN_WHITE;

	// [6-7-6] 흑의 턴으로 초기화
	turn = TURN_BLACK;

	// [6-7-7] 커서 좌표 초기화
	cursorPosition = {3,3};

	// [6-7-8] 화면 그림
	drawScreen();
}
// ------------------------------
// [6-8] 돌을 둘 곳을 선택하는 함수
VEC2 inputPosition() {
	// [6-8-1] 돌을 둘수 있는 곳이 선택될때 까지 무한루프
	while (1)
	{
		drawScreen(); // [6-8-2]
		// [6-8-3] 입력한 키에 따라 분기
		// [6-8-4] ~ // [6-8-11]
		switch (_getch())
		{
		case 'w':
			cursorPosition.y--;
			break;
		case 's':
			cursorPosition.y++;
			break;
		case 'a':
			cursorPosition.x--;
			break;
		case 'd':
			cursorPosition.x++;
			break;
		default: // [6-8-12] 상기 이외의 키가 눌리면,
			// [6-8-13] 커서에 돌을 둘수 있나 확인.
			if (checkCanPlace(turn, cursorPosition))
			{
				return cursorPosition; // [6-8-14] 좌표반환
			}
			else // [6-8-15] 둘수 없다
			{
				// [6-8-16] 메시지 표시
				printf("거기에는 둘 수 없다!!!");
				// [6-8-17] 키보드 입력 대기
				_getch();
			}
			break;
		}
		// [6-8-18] 커서를 좌우로 루프
		cursorPosition.x = (BOARD_WIDTH + cursorPosition.x) % BOARD_WIDTH;
		// [6-8-19] 커스를 상하로 루프
		cursorPosition.y = (BOARD_HEIGHT + cursorPosition.y) % BOARD_HEIGHT;
	}
}
// ------------------------------
// [6-9] 프로그램 시작
int main()
{
	// [6-9-5] 초기화
	init();
	// [6-9-6] 메인루프
	while (1)
	{
		// [6-9-16] 돌을 둘 곳은 선언
		VEC2 placePosition;
		// [6-9-18] 돌을 둘 곳을 선택하는 함수호출
		placePosition = inputPosition();


		// [6-9-30] 현재 턴의 돌을 둔다.
		board[placePosition.y][placePosition.x] = turn;
		// [6-9-31] 턴을 전환
		turn ^= 1;
	}
}
// ------------------------------
// ------------------------------
// ------------------------------
// ------------------------------
// ------------------------------
// ------------------------------
// ************************************************************
