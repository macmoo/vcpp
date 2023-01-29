// [1] 헤더 include
#include <conio.h>// [1-5] 콘솔 입출력

// [2] 정수 정의

// [3] 열거정수 정의
// [3-1] 몬스터의 종류
enum
{
	MONSTER_PLAYER,	// [3-1-1] 플레이어
	MONSTER_MAX		// [3-1-4] 몬스터 종류의 수
};

// [4] 구조체 선언
// [4-1] 캐릭터 구조체
typedef struct
{
	int  hp;
	int  maxHp;
	int  mp;
	int  maxMp;
	char name[4*2+1];
}CHARACTER;

// 
// [5] 변수를 선언

// [6] 함수를 선언
// [6-4] 전투신 함수 선언
void battle()
{
	// [6-4-6] 키입력 대기
	_getch();

}
// [6-6] 실행시작점
int main()
{
	// [6-6-3] 전투신 함수 호출
	battle();

}
// [] 
