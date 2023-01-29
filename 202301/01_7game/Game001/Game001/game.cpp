// ************************************************************
// [1] 헤더 include
#include <stdio.h>							// [1-1] 표준 입출력
#include <stdlib.h>							// [1-2] 표준 라이브러리
#include <string.h>							// [1-3] 문자열 조작
#include <time.h>							// [1-4] 시간 관리
#include <conio.h>							// [1-5] 콘솔 입출력
#include <windows.h>						// vs console 인코딩변경
#pragma execution_character_set( "utf-8" )	// vs console 인코딩변경
// ************************************************************
// [2] 정수 정의
// [2-1] 주문의 소비 mp
#define SPELL_COST (3)
// ************************************************************
// [3] 열거정수 정의
// ------------------------------
// [3-1] 몬스터의 종류
enum
{
	MONSTER_PLAYER,	// [3-1-1] 플레이어
	MONSTER_SLIME,	// [3-1-2] 슬라임
	MONSTER_BOSS,	// [3-1-3] BOSS
	MONSTER_MAX		// [3-1-4] 몬스터 종류의 수
};
// ------------------------------
// [3-2] 캐릭터의 종류
enum
{
	CHARACTER_PLAYER,	// [3-2-1] 플레이어
	CHARACTER_MONSTER,	// [3-2-2] 몬스터
	CHARACTER_MAX,		// [3-2-3] 캐릭터 종류의 수
};
// ------------------------------
// [3-3] 커맨드 종류를 정의
enum
{
	COMMAND_FIGHT,		// [3-3-1] 싸우다
	COMMAND_SPELL,		// [3-3-2] 주문
	COMMAND_RUN,		// [3-3-3] 도망
	COMMAND_MAX			// [3-3-4] 커맨드 종류의 수
};
// ************************************************************
// [4] 구조체 선언
// [4-1] 캐릭터 구조체
typedef struct
{
	int		hp;
	int		maxHp;
	int		mp;
	int		maxMp;
	int		attack;				// 공격력
	char	name[6 * 2 + 1];
	char	aa[256];			// 아스키 아트
	int		command;			// 커맨드
	int		target;				// 공격대상
}CHARACTER;
// ************************************************************
// [5] 변수를 선언
// ------------------------------
// [5-1] 몬스터의 상태 배열을 선언
CHARACTER monsters[MONSTER_MAX] =
{
	// [5-1-1] MONSTER PLAYER
	{
		100,			// hp
		100,			// max hp
		15,				// mp
		15,				// max mp
		60,				// attack
		"勇者"			// 이름
	},
	// [5-1-8] MONSTER SLIME
	{
		3,				// hp
		3,				// max hp
		0,				// mp
		0,				// max mp
		2,				// attack
		"スライム",		// 이름
		"／・Д・＼\n"
		"～～～～～"	// 아스키 아트
	},
	// [5-1-16] MONSTER BOSS
	{
		255,			// hp
		255,			// max hp
		0,				// mp
		0,				// max mp
		50,				// attack
		"魔王",			// 이름
		"　　Ａ＠Ａ\n"
		"ψ（▼皿▼）ψ"// 아스키 아트
	},
};
// ------------------------------
// [5-2] 캐릭터의 배열을 선언
CHARACTER characters[CHARACTER_MAX];
// ------------------------------
// [5-3] 커맨드명을 선언
char comandNames[COMMAND_MAX][6 * 2 + 1] = {
	"たたかう", // [5-3-1]COMMAND_FIGHT 戦う
	"じゅもん", // [5-3-2]COMMAND_SPELL 呪文
	"にげる"    // [5-3-3]COMMAND_RUN   逃げる
};
// ************************************************************
// [6] 함수를 선언
// ------------------------------
// [6-1] 게임 초기화 함수
void init()
{
	// vs console 인코딩변경
	SetConsoleOutputCP(65001); // UTF-8

	// [6-1-1] 플레이어 상태를 초기화
	characters[CHARACTER_PLAYER] = monsters[MONSTER_PLAYER];
}
// ------------------------------
// [6-2] 전투신 그리는 함수
void drawBattleScreen()
{
	// [6-2-1] 화면 클리어
	system("cls");
	printf("-----------------------------------\n");
	printf("name   :%s\n", characters[CHARACTER_PLAYER].name);
	printf("command:%d\n", characters[CHARACTER_PLAYER].command);
	printf("-----------------------------------\n");
	// [6-2-2] 플레이어 이름 표시
	printf("%s\n", characters[CHARACTER_PLAYER].name);
	// [6-2-3] 플레이어 상태 표시
	printf("HP:%d/%d  MP:%d/%d\n"
		, characters[CHARACTER_PLAYER].hp
		, characters[CHARACTER_PLAYER].maxHp
		, characters[CHARACTER_PLAYER].mp
		, characters[CHARACTER_PLAYER].maxMp);
	printf("\n");
	// [6-2-4] 몬스터의 아스키 아트 출력
	printf("%s", characters[CHARACTER_MONSTER].aa);
	// [6-2-6] 몬스터의 HP 출력
	printf("(HP:%d/%d)\n"
		, characters[CHARACTER_MONSTER].hp
		, characters[CHARACTER_MONSTER].maxHp);
	printf("\n");
}
// ------------------------------
// [6-3] 커맨드 선택 함수 선언
void selectCommand()
{
	// [6-3-1] 플레이어의 커맨드를 초기화
	characters[CHARACTER_PLAYER].command = COMMAND_FIGHT;
	// [6-3-2] 커맨드가 결정될 때 까지 루프
	while (1)
	{
		// [6-3-3] 전투 화면 표시 함수 호출
		drawBattleScreen();
		// [6-3-4] 커맨드 일람 표시
		for (int i = 0; i < COMMAND_MAX; i++)
		{
			// [6-3-6] 선택중의 커맨드일 경우
			if (i == characters[CHARACTER_PLAYER].command)
			{
				printf("> ");
			}
			else
			{
				printf("  ");
			}
			// [6-3-9] 커맨드명 표시
			printf("%s\n", comandNames[i]);
		}
		// [6-3-10] 입력된 키에 따라 분기
		switch (_getch())
		{
			// [6-3-11] w키가 입력됨
		case 'w':
			// [6-3-12] 위의 커맨드로 이동
			characters[CHARACTER_PLAYER].command--;
			break;
			// [6-3-13] s키가 입력됨
		case 's':
			// [6-3-14] 아래의 커맨드로 이동
			characters[CHARACTER_PLAYER].command++;
			break;
			// [6-3-15] 상기이외의 키가 눌렸을 경우
		default:
			// [6-3-16] 함수를 빠져나옴
			return;
		}
		// [6-3-17] 커서를 상하 루프 시킴
		characters[CHARACTER_PLAYER].command = (COMMAND_MAX + characters[CHARACTER_PLAYER].command) % COMMAND_MAX;
	}
}
// ------------------------------
// [6-4] 전투신 함수 선언
void battle(int _monster)
{
	// [6-4-1] 몬스터의 상태를 초기화
	characters[CHARACTER_MONSTER] = monsters[_monster];
	// [6-4-2] 플레이어의 공격대상
	characters[CHARACTER_PLAYER].target = CHARACTER_MONSTER;
	// [6-4-3] 몬스터의 공격대상
	characters[CHARACTER_MONSTER].target = CHARACTER_PLAYER;
	// [6-4-4] 전투신 그리는 함수 호출
	drawBattleScreen();
	// [6-4-5] 전투신 최초의 메시지 출력
	printf("%sが　現れた！！\n", characters[CHARACTER_MONSTER].name);
	// [6-4-6] 키입력 대기
	_getch();
	// [6-4-7] 배틀이 종료될 때 까지 무한루프
	while (1)
	{
		// [6-4-8] 커맨드 선택 함수 호출
		selectCommand();
		// [6-4-9] 각 캐릭터 반복
		for (int i = 0; i < CHARACTER_MAX; i++)
		{
			// [6-4-10] 전투신 그리는 함수 호출
			drawBattleScreen();
			switch (characters[i].command)
			{
			// [6-4-12] FIGHT
			case COMMAND_FIGHT:
			{
				// [6-4-13] 공격 메세지를 표시
				printf("%sの　攻撃！\n", characters[i].name);
				// [6-4-14] 키보드 입력 대기
				_getch();
				// [6-4-15] 적에게의 데미지를 계산
				int damage = 1 + rand() % characters[i].attack;
				// [6-4-16] 적에게 데미지
				characters[characters[i].target].hp -= damage;
				// [6-4-17] 적의 hp가 음수판정
				if (characters[characters[i].target].hp <= 0)
				{
					// [6-4-18] 적의 hp를 0으로 함
					characters[characters[i].target].hp = 0;
				}
				// [6-4-19] 전투신 화면 다시 그림
				drawBattleScreen();
				// [6-4-20] 적에게 데미지를 전했을 때의 메시지 출력
				printf("%sに　%dのダメージ！\n", characters[characters[i].target].name, damage);
				// [6-4-21] 키 입력
				_getch();
				break;
			}
			// [6-4-22] SPELL
			case COMMAND_SPELL:
				// [6-4-23] MP 체크
				if (characters[i].mp < SPELL_COST) {
					// [6-4-24] MP 부족 메시지 출력
					printf("MPが　足りない！！");
					// [6-4-25] 키 입력 대기
					_getch();
					// [6-4-26] 주문 처리 종료
					break;
				}
				// [6-4-27] MP 소비
				characters[i].mp -= SPELL_COST;
				// [6-4-28] 화면 다시 그림
				drawBattleScreen();
				// [6-4-29] 주문 메시지 출력
				printf("%sは　ヒールを唱えました！", characters[i].name);
				// [6-4-30] 키 입력 대기
				_getch();
				// [6-4-31] HP 회복
				characters[i].hp = characters[i].maxHp;
				// [6-4-32] 화면 다시 그림
				drawBattleScreen();
				// [6-4-33] HP 회복 메시지 출력
				printf("%sの傷が　回復した。\n", characters[i].name);
				// [6-4-34] 키 입력 대기
				_getch();
				break;
			// [6-4-35] RUN
			case COMMAND_RUN:
				// [6-4-36] 도망 메시지 출력
				printf("%sは　逃げました！", characters[i].name);
				// [6-4-37] 키 입력 대기
				_getch();
				// [6-4-38] 처리 종료
				// break;
				return;
			}
			// [6-4-39] 공격대상을 쓰러트렸는지 판정
			if (characters[characters[i].target].hp <= 0)
			{
				// [6-4-40] 공격대상에 따라 처리 분기
				switch (characters[i].target)
				{
					// [6-4-41] 플레이어일 경우
				case CHARACTER_PLAYER:
					// [6-4-42] 플레이어 사망
					printf("%s　死亡！！！", characters[characters[i].target].name);
					break;
					// [6-4-43] 몬스터일 경우
				case CHARACTER_MONSTER:
					// [6-4-44] 몬스터의 아스키 아트를 덮어씀
					strcpy_s(characters[characters[i].target].aa, "／TTДTT＼\n");
					// [6-4-45] 전투신을 다시 그림
					drawBattleScreen();
					// [6-4-46] 몬스터를 무찔렀을 경우
					printf("%sを　倒した！！！！！\n", characters[characters[i].target].name);
					break;
				}
				// [6-4-47] 키 입력 대기
				_getch();
				// [6-4-48] 전투신 함수 탈출
				return;
			}
		}
	}
}
// ------------------------------
// [6-6] 실행시작점
int main()
{
	// [6-6-1] 난수를 섞음
	srand((unsigned int)time(NULL));

	// [6-6-2] 게임 초기화 함수 호출
	init();
	// [6-6-3] 전투신 함수 호출
	// battle(MONSTER_SLIME);
	battle(MONSTER_BOSS);

}
// ************************************************************
