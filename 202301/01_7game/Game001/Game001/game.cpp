// [1] ��� include
#include <conio.h>// [1-5] �ܼ� �����

// [2] ���� ����

// [3] �������� ����
// [3-1] ������ ����
enum
{
	MONSTER_PLAYER,	// [3-1-1] �÷��̾�
	MONSTER_MAX		// [3-1-4] ���� ������ ��
};

// [4] ����ü ����
// [4-1] ĳ���� ����ü
typedef struct
{
	int  hp;
	int  maxHp;
	int  mp;
	int  maxMp;
	char name[4*2+1];
}CHARACTER;

// 
// [5] ������ ����

// [6] �Լ��� ����
// [6-4] ������ �Լ� ����
void battle()
{
	// [6-4-6] Ű�Է� ���
	_getch();

}
// [6-6] ���������
int main()
{
	// [6-6-3] ������ �Լ� ȣ��
	battle();

}
// [] 
