#include "DxLib.h" /* DX�饤�֥��Ȥ��������ʙC�ܤ�ʹ������ */
int main() {

	int x = 640/2-32/2, y = 480/2-32/2; /* ���������� */
	int keyInput;

	int bg = 0;
	int myShip = 0;

	int speed = 5;//speed setter

	myShip = LoadGraph("MyShip32.bmp");
	bg = LoadGraph("bg.jpg");

	SetDrawScreen(DX_SCREEN_BACK);  /* �軭�Ȥ��Y������O������ */

	while (1) { /* �o�ޤ��R�귵��(�o�ޥ�`��) */

		ClsDrawScreen(); /* �軭�Ȼ���򤭤줤����ȥ���� */

		keyInput = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (keyInput == PAD_INPUT_RIGHT) {
			if ((x + speed) >= (639 - 31))x = (639 - 31);
			else x += speed;
		}
		if (keyInput == PAD_INPUT_LEFT) {
			if ((x - speed) <= 0)x = 0;
			else x -= speed;
		}
		if (keyInput == PAD_INPUT_DOWN) {
			if ((y + speed) >= (479 - 31))y = (479 - 31);
			else y += speed;
		}
		if (keyInput == PAD_INPUT_UP) {
			if ((y - speed) <= 0)y = 0;
			else y -= speed;
		}

		DrawGraph(0, 0, bg, TRUE);

		DrawGraph(x, y, myShip, TRUE);

		ScreenFlip(); /* �Y������軭������Τ�����ܞд���� */


		if (CheckHitKey(KEY_INPUT_ESCAPE)) break; /* �������`�ץ��`��Ѻ���줿���R�귵���I������� */
	} /* while( )���]�������� */

	return 0;
}
